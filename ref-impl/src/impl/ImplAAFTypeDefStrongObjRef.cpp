/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
*                                          *
\******************************************/


#ifndef __ImplAAFPropValData_h__
#include "ImplAAFPropValData.h"
#endif

#ifndef __ImplAAFClassDef_h__
#include "ImplAAFClassDef.h"
#endif

#ifndef __ImplAAFTypeDefStrongObjRef_h__
#include "ImplAAFTypeDefStrongObjRef.h"
#endif

#ifndef __ImplAAFHeader_h_
#include "ImplAAFHeader.h"
#endif

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"

#include <assert.h>
#include <string.h>


ImplAAFTypeDefStrongObjRef::ImplAAFTypeDefStrongObjRef ()
  : _referencedType (PID_TypeDefinitionStrongObjectReference_ReferencedType, "ReferencedType")
{
  _persistentProperties.put(_referencedType.address());
}


ImplAAFTypeDefStrongObjRef::~ImplAAFTypeDefStrongObjRef ()
{}

// Override from AAFTypeDefObjectRef
AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefStrongObjRef::pvtInitialize (
      const aafUID_t *  pID,
      const aafUID_t * pRefdObjID,
      wchar_t *  pTypeName)
{
  if (! pID)       return AAFRESULT_NULL_PARAM;
  if (! pRefdObjID)  return AAFRESULT_NULL_PARAM;
  if (! pTypeName) return AAFRESULT_NULL_PARAM;

  AAFRESULT hr;

  hr = SetName (pTypeName);
  if (! AAFRESULT_SUCCEEDED (hr)) return hr;

  _referencedType = *pRefdObjID;

  hr = SetAUID (pID);
  if (! AAFRESULT_SUCCEEDED (hr)) return hr;

  return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefStrongObjRef::SetObject (ImplAAFPropertyValue * pPropVal,
										   ImplAAFObject * pObject)
{
  if (! pPropVal) return AAFRESULT_NULL_PARAM;
  if (! pObject) return AAFRESULT_NULL_PARAM;

  OMStorable ** ppStorable = NULL;
  aafUInt32 bitsSize = 0;
  AAFRESULT hr;
  ImplAAFPropValDataSP pvd;
  pvd = dynamic_cast<ImplAAFPropValData*>(pPropVal);
  assert (pvd);

  hr = pvd->AllocateBits (sizeof (OMStorable*), (aafMemPtr_t*) &ppStorable);
  if (AAFRESULT_FAILED(hr)) return hr;
  assert (ppStorable);
  if (*ppStorable)
	{
	  // An object was already here.  Release it before we trash the
	  // reference to it.
	  ImplAAFObject * tmp = dynamic_cast<ImplAAFObject*>(*ppStorable);
	  assert (tmp);
	  tmp->ReleaseReference ();
	  tmp = 0;
	  *ppStorable = 0;
	}

  assert (! *ppStorable);
  *ppStorable = pObject;
  pObject->AcquireReference ();

  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
ImplAAFTypeDefStrongObjRef::GetObject (ImplAAFPropertyValue * pPropVal,
									   ImplAAFObject ** ppObject)
{
  if (! pPropVal) return AAFRESULT_NULL_PARAM;
  if (! ppObject) return AAFRESULT_NULL_PARAM;

  OMStorable ** ppStorable = NULL;
  aafUInt32 bitsSize = 0;
  AAFRESULT hr;
  ImplAAFPropValDataSP pvd;
  pvd = dynamic_cast<ImplAAFPropValData*>(pPropVal);
  assert (pvd);

  hr = pvd->GetBitsSize (&bitsSize);
  if (AAFRESULT_FAILED(hr)) return hr;
  assert (bitsSize >= sizeof (ImplAAFObject*));
  hr = pvd->GetBits ((aafMemPtr_t*) &ppStorable);
  if (AAFRESULT_FAILED(hr)) return hr;
  assert (*ppStorable);
  assert (ppObject);
  ImplAAFObject * pObj;
  pObj = dynamic_cast<ImplAAFObject*>(*ppStorable);
  assert (pObj);
  *ppObject = pObj;
  (*ppObject)->AcquireReference ();

  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefStrongObjRef::GetObjectType (ImplAAFClassDef ** ppObjType) const
{
  if (! ppObjType) return AAFRESULT_NULL_PARAM;

  if (! _cachedObjType)
	{
	  ImplAAFHeaderSP pHead;
	  ImplAAFDictionarySP pDict;

	  AAFRESULT hr;
	  hr = MyHeadObject(&pHead);
	  if (AAFRESULT_FAILED(hr))
		return hr;
	  assert (pHead);
	  hr = (pHead->GetDictionary(&pDict));
	  if (AAFRESULT_FAILED(hr))
		return hr;
	  assert (pDict);

	  ImplAAFTypeDefStrongObjRef * pNonConstThis =
		  (ImplAAFTypeDefStrongObjRef*) this;
	  aafUID_t id = _referencedType;
	  hr = pDict->LookupClass (&id, &pNonConstThis->_cachedObjType);
	  if (AAFRESULT_FAILED(hr))
		return hr;
	  assert (_cachedObjType);
	}
  assert (ppObjType);
  *ppObjType = _cachedObjType;
  assert (*ppObjType);
  (*ppObjType)->AcquireReference ();
  return AAFRESULT_SUCCESS;
}

// Override from AAFTypeDefObjectRef
AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefStrongObjRef::CreateValue (/*[in]*/ ImplAAFObject * /*pObj*/,
      /*[out]*/ ImplAAFPropertyValue ** /*ppPropVal*/)
{
  return AAFRESULT_NOT_IMPLEMENTED;
}



AAFRESULT STDMETHODCALLTYPE
    ImplAAFTypeDefStrongObjRef::GetTypeCategory (eAAFTypeCategory_t *  pTid)
{
  if (!pTid) return AAFRESULT_NULL_PARAM;
  *pTid = kAAFTypeCatStrongObjRef;
  return AAFRESULT_SUCCESS;
}



aafBool ImplAAFTypeDefStrongObjRef::IsFixedSize (void) const
{
  return AAFTrue;
}


size_t ImplAAFTypeDefStrongObjRef::PropValSize (void) const
{
  return sizeof (ImplAAFObject*);
}


aafBool ImplAAFTypeDefStrongObjRef::IsRegistered (void) const
{
  return AAFTrue;
}


size_t ImplAAFTypeDefStrongObjRef::NativeSize (void) const
{
  return sizeof (ImplAAFObject*);
}


OMProperty * ImplAAFTypeDefStrongObjRef::pvtCreateOMPropertyMBS
  (OMPropertyId pid,
   const char * name) const
{
  assert (name);
  OMProperty * result =
	new OMStrongReferenceProperty<ImplAAFObject> (pid, name);
  assert (result);
  return result;
}


OMDEFINE_STORABLE(ImplAAFTypeDefStrongObjRef, AUID_AAFTypeDefStrongObjRef);
