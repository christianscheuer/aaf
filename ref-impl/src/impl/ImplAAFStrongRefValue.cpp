//=---------------------------------------------------------------------=
//
// $Id$ $Name$
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#include "ImplAAFStrongRefValue.h"


#ifndef __ImplAAFRoot_h__
#include "ImplAAFRoot.h"
#endif

#ifndef __ImplAAFStorable_h__
#include "ImplAAFStorable.h"
#endif

#ifndef __ImplAAFObject_h__
#include "ImplAAFObject.h"
#endif

#ifndef __ImplAAFMetaDefinition_h__
#include "ImplAAFMetaDefinition.h"
#endif

// TBD: Note the following include for ImplAAFClassDef.h really belongs
// in ImplAAFTypeDefStrongObjRef.h!
#ifndef __ImplAAFClassDef_h__
#include "ImplAAFClassDef.h"
#endif

#ifndef __ImplAAFTypeDefStrongObjRef_h__
#include "ImplAAFTypeDefStrongObjRef.h"
#endif


#include "OMProperty.h"
#include "OMRefProperty.h" // Include header for base class for singleton references.

#include "OMAssertions.h"
#include <string.h>



ImplAAFStrongRefValue::ImplAAFStrongRefValue ()
{}


ImplAAFStrongRefValue::~ImplAAFStrongRefValue ()
{
}



AAFRESULT ImplAAFStrongRefValue::Initialize (
  const ImplAAFTypeDefStrongObjRef *referenceType)
{
  AAFRESULT result = AAFRESULT_SUCCESS;
  
  ASSERTU (!isInitialized());
  if (isInitialized())
    return AAFRESULT_ALREADY_INITIALIZED;
    
  result = ImplAAFRefValue::Initialize(referenceType);
  if (AAFRESULT_SUCCEEDED(result))
  {
    // This instance is now fully initialized.
    setInitialized();
  }
  return result;
}


AAFRESULT ImplAAFStrongRefValue::Initialize (
  const ImplAAFTypeDefStrongObjRef *referenceType,    
  OMProperty *property)
{
  AAFRESULT result = AAFRESULT_SUCCESS;
  
  ASSERTU (!isInitialized());
  if (isInitialized())
    return AAFRESULT_ALREADY_INITIALIZED;
    
  result = ImplAAFRefValue::Initialize(referenceType, property);
  if (AAFRESULT_SUCCEEDED(result))
  {
    // This instance is now fully initialized.
    setInitialized();
  }
  
  return result;
}


AAFRESULT STDMETHODCALLTYPE ImplAAFStrongRefValue::GetObject(ImplAAFStorable **ppObject) const
{
  AAFRESULT result = AAFRESULT_SUCCESS;
  ImplAAFStorable *pObject = NULL;
  
  if (NULL == ppObject)
    return AAFRESULT_NULL_PARAM;
  
  *ppObject = NULL;

  ASSERTU (isInitialized());
  if (!isInitialized())
    return AAFRESULT_NOT_INITIALIZED;

  OMReferenceProperty* pProperty =  referenceProperty();
  if (NULL != pProperty)
  {
    if (! pProperty->isOptional() || pProperty->isPresent ())
    {
      OMObject *object = pProperty->getObject();
      if (NULL == object)
        return AAFRESULT_NULLOBJECT;
      pObject = ConvertOMObjectToRoot(object); 
      ASSERTU (NULL != pObject);
      if (NULL == pObject)
        return AAFRESULT_INVALID_OBJ; // ???
    }
    else
    {
      return AAFRESULT_PROP_NOT_PRESENT;
    }
  }
  else
  {
    // Use an "indirect access" method of retrieving a strong object reference.
    //
    // If there was not associated reference property then there MUST
    // be a local object pointer assigned to this instance.
    pObject = GetLocalObject();
    ASSERTU (NULL != pObject);
  }
  
  *ppObject = pObject;
  (*ppObject)->AcquireReference();
  
  return result;
}

static AAFRESULT SetNewObjectReference(
  OMReferenceProperty* refProperty,
  ImplAAFStorable* pNewObject)
{   
  ASSERTU (NULL != pNewObject);
  if (NULL == pNewObject)
    return AAFRESULT_INVALID_OBJ; // ???
  OMObject *object = refProperty->setObject(pNewObject);

  // The new object reference is now owned by its containing object
  // so we need to increase the reference count.
  pNewObject->AcquireReference();

  // Release the old object reference if necessary...
  if (NULL != object)
  {    
    ImplAAFStorable *pOldObject = ImplAAFRefValue::ConvertOMObjectToRoot(object); 
    ASSERTU (NULL != pOldObject);
    if (NULL == pOldObject)
      return AAFRESULT_INVALID_OBJ; // ???
    
    pOldObject->ReleaseReference();
  }  
  
  return AAFRESULT_SUCCESS;
}


AAFRESULT STDMETHODCALLTYPE ImplAAFStrongRefValue::SetObject(ImplAAFStorable *pObject)
{
  AAFRESULT result = AAFRESULT_SUCCESS;
  
  if (NULL == pObject)
    return AAFRESULT_NULL_PARAM;

  ASSERTU (isInitialized());
  if (!isInitialized())
    return AAFRESULT_NOT_INITIALIZED;

  if (NULL != referenceProperty())
  {
    // Save the reference in the OMReferenceProperty
    result = SetNewObjectReference(referenceProperty(), pObject);
  }
  else
  {
    // Use an "indirect access" method of saving a strong object reference.
    //
    // If there was not associated reference property then we MUST
    // set the local object pointer for this instance.
    SetLocalObject(pObject);
  }
  
  
  return result;
}


//
// WriteTo
//
AAFRESULT STDMETHODCALLTYPE ImplAAFStrongRefValue::WriteTo(
  OMProperty* pOmProp)
{
  ASSERTU (isInitialized());
  if (!isInitialized())
    return AAFRESULT_NOT_INITIALIZED;

  AAFRESULT result = ImplAAFRefValue::WriteTo(pOmProp);
  if (AAFRESULT_SUCCEEDED(result))
  {
    // If there is a referenceProperty then the SetObject method has already
    // written the object reference to the property.
  
    if (NULL == referenceProperty())
    {
      OMReferenceProperty* refProperty = dynamic_cast<OMReferenceProperty *>(pOmProp);
      ASSERTU(refProperty);
      if (NULL == refProperty)
        return AAFRESULT_INVALID_OBJ; // ???

      // Use an "indirect access" method of saving a strong object reference.
      // The local object reference must exist! NOTE: GetLocalObject() does NOT increment
      // the reference count of the returned object!
      result = SetNewObjectReference(refProperty, GetLocalObject());
      if (AAFRESULT_SUCCEEDED(result))
      {
        // Install the property direct access and cleanup the local reference.
        SetProperty(pOmProp);
        SetLocalObject(NULL);
      }
    }
  }
  
  return result;
}
