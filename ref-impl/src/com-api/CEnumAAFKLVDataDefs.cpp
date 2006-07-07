//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id$ $Name$
//
// The contents of this file are subject to the AAF SDK Public
// Source License Agreement (the "License"); You may not use this file
// except in compliance with the License.  The License is available in
// AAFSDKPSL.TXT, or you may obtain a copy of the License from the AAF
// Association or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.
//
// The Original Code of this file is Copyright 1998-2005, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=



#include "CEnumAAFKLVDataDefs.h"
#include "ImplEnumAAFKLVDataDefs.h"
#include "AAFResult.h"
#include "CAAFEnumValidation.h"

#include "OMAssertions.h"
#include "OMExceptions.h"

#include <assert.h>
#include <string.h>

#include "CAAFKLVDataDefinition.h"
#include "ImplAAFKLVDataDefinition.h"


// CLSID for EnumAAFKLVDataDefs 
// {ed7d95bc-8ce3-4d92-93f2-792e7efa224b}
EXTERN_C const CLSID CLSID_EnumAAFKLVDataDefs = { 0xed7d95bc, 0x8ce3, 0x4d92, { 0x93, 0xf2, 0x79, 0x2e, 0x7e, 0xfa, 0x22, 0x4b } };






CEnumAAFKLVDataDefs::CEnumAAFKLVDataDefs (IUnknown * pControllingUnknown, aafBool doInit)
  : CAAFRoot (pControllingUnknown, kAAFFalse)
{
  if (doInit)
    {
      ImplEnumAAFKLVDataDefs * newRep;
      newRep = new ImplEnumAAFKLVDataDefs;
      assert (newRep);
      InitRep (newRep);
    }
}


CEnumAAFKLVDataDefs::~CEnumAAFKLVDataDefs ()
{
}


HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVDataDefs::NextOne (IAAFKLVDataDefinition ** ppKLVDataDefs)
{
  HRESULT hr;

  ImplEnumAAFKLVDataDefs * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVDataDefs*> (pO);
  assert (ptr);

  //
  // set up for ppKLVDataDefs
  //
  ImplAAFKLVDataDefinition * internalppKLVDataDefs = NULL;
  ImplAAFKLVDataDefinition ** pinternalppKLVDataDefs = NULL;
  if (ppKLVDataDefs)
    {
      pinternalppKLVDataDefs = &internalppKLVDataDefs;
    }

  try
    {
      hr = ptr->NextOne
       (pinternalppKLVDataDefs);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  //
  // cleanup for ppKLVDataDefs
  //
  if (SUCCEEDED(hr))
    {
      IUnknown *pUnknown;
      HRESULT hStat;

      if (internalppKLVDataDefs)
        {
          pUnknown = static_cast<IUnknown *> (internalppKLVDataDefs->GetContainer());
          hStat = pUnknown->QueryInterface(IID_IAAFKLVDataDefinition, (void **)ppKLVDataDefs);
          assert (SUCCEEDED (hStat));
          //pUnknown->Release();
          internalppKLVDataDefs->ReleaseReference(); // We are through with this pointer.
        }
    }
  return hr;
}



HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVDataDefs::Next (aafUInt32  count,
        IAAFKLVDataDefinition ** ppKLVDataDefs,
        aafUInt32 *  pNumFetched)
{
  HRESULT hr;

  ImplEnumAAFKLVDataDefs * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVDataDefs*> (pO);
  assert (ptr);

  //
  // set up for ppKLVDataDefs
  //
  ImplAAFKLVDataDefinition ** internalppKLVDataDefs = NULL;
  assert (count >= 0);
  internalppKLVDataDefs = new ImplAAFKLVDataDefinition*[count];
  assert (internalppKLVDataDefs);

  ImplAAFKLVDataDefinition ** pinternalppKLVDataDefs = NULL;
  if (ppKLVDataDefs)
    {
      pinternalppKLVDataDefs = internalppKLVDataDefs;
    }

  try
    {
      hr = ptr->Next
       (count,
        pinternalppKLVDataDefs,
        pNumFetched);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  //
  // cleanup for ppKLVDataDefs
  //
  if (SUCCEEDED(hr)||hr==AAFRESULT_NO_MORE_OBJECTS)
    {
      IUnknown *pUnknown;
      HRESULT hStat;
      aafUInt32 localIdx;
	  assert (count >= 0);
	  for (localIdx = 0; localIdx < *pNumFetched; localIdx++)
		{
		  pUnknown = static_cast<IUnknown *> (internalppKLVDataDefs[localIdx]->GetContainer());
		  hStat = pUnknown->QueryInterface(IID_IAAFKLVDataDefinition, (void **)(ppKLVDataDefs+localIdx));
		  assert (SUCCEEDED (hStat));
		  //pUnknown->Release();
		  internalppKLVDataDefs[localIdx]->ReleaseReference(); // We are through with this pointer.
		}
    }
  delete[] internalppKLVDataDefs;
  internalppKLVDataDefs = 0;
  return hr;
}



HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVDataDefs::Skip (aafUInt32  count)
{
  HRESULT hr;

  ImplEnumAAFKLVDataDefs * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVDataDefs*> (pO);
  assert (ptr);


  try
    {
      hr = ptr->Skip
       (count);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  return hr;
}



HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVDataDefs::Reset ()
{
  ImplEnumAAFKLVDataDefs * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVDataDefs*> (pO);
  assert (ptr);
  HRESULT hr;

  try
    {
      hr = ptr->Reset();
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  return hr;
}



HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVDataDefs::Clone (IEnumAAFKLVDataDefs ** ppEnum)
{
  HRESULT hr;

  ImplEnumAAFKLVDataDefs * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVDataDefs*> (pO);
  assert (ptr);

  //
  // set up for ppEnum
  //
  ImplEnumAAFKLVDataDefs * internalppEnum = NULL;
  ImplEnumAAFKLVDataDefs ** pinternalppEnum = NULL;
  if (ppEnum)
    {
      pinternalppEnum = &internalppEnum;
    }

  try
    {
      hr = ptr->Clone
       (pinternalppEnum);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  //
  // cleanup for ppEnum
  //
  if (SUCCEEDED(hr))
    {
      IUnknown *pUnknown;
      HRESULT hStat;

      if (internalppEnum)
        {
          pUnknown = static_cast<IUnknown *> (internalppEnum->GetContainer());
          hStat = pUnknown->QueryInterface(IID_IEnumAAFKLVDataDefs, (void **)ppEnum);
          assert (SUCCEEDED (hStat));
          //pUnknown->Release();
          internalppEnum->ReleaseReference(); // We are through with this pointer.
        }
    }
  return hr;
}

//
// 
// 
inline int EQUAL_UID(const GUID & a, const GUID & b)
{
  return (0 == memcmp((&a), (&b), sizeof (aafUID_t)));
}
HRESULT CEnumAAFKLVDataDefs::InternalQueryInterface
(
    REFIID riid,
    void **ppvObj)
{
    if (NULL == ppvObj)
        return E_INVALIDARG;

    // We only support the IClassFactory interface 
    if (EQUAL_UID(riid,IID_IEnumAAFKLVDataDefs)) 
    { 
        *ppvObj = (IEnumAAFKLVDataDefs *)this; 
        ((IUnknown *)*ppvObj)->AddRef();
        return S_OK;
    }

    // Always delegate back to base implementation.
    return CAAFRoot::InternalQueryInterface(riid, ppvObj);
}

//
// Define the contrete object support implementation.
// 
AAF_DEFINE_FACTORY(EnumAAFKLVDataDefs)

