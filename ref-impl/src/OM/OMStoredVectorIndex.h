/***********************************************************************
*
*              Copyright (c) 1998-1999 Avid Technology, Inc.
*
* Permission to use, copy and modify this software and accompanying
* documentation, and to distribute and sublicense application software
* incorporating this software for any purpose is hereby granted,
* provided that (i) the above copyright notice and this permission
* notice appear in all copies of the software and related documentation,
* and (ii) the name Avid Technology, Inc. may not be used in any
* advertising or publicity relating to the software without the specific,
* prior written permission of Avid Technology, Inc.
*
* THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
* EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
* WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
* SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
* OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
* ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
* RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
* ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
* LIABILITY.
*
************************************************************************/

// @doc OMINTERNAL
#ifndef OMSTOREDVECTORINDEX_H
#define OMSTOREDVECTORINDEX_H

#include "OMPortability.h"
#include "OMDataTypes.h"

#include <stddef.h>

  // @class The in-memory representation of the on-disk index for a
  //        stored object vector.
class OMStoredVectorIndex {
public:
  // @access Public members.

    // @cmember Constructor.
  OMStoredVectorIndex(size_t capacity);

    // @cmember Destructor.
  ~OMStoredVectorIndex(void);

    // @cmember The high water mark in the set of names assigned to
    //          this <c OMStoredVectorIndex>.
  OMUInt32 highWaterMark(void) const;

    // @cmember Insert a new element in this <c OMStoredVectorIndex>
    //          at position <p position> with name <p name>.
    //          The name of an element is an integer. Names are assigned
    //          such that the names of existing elements do not have to
    //          change when other elements are added to or removed from
    //          the associated <c OMStrongReferenceVector>. The name is
    //          independent of the element's logical or physical position
    //          within the associated <c OMStrongReferenceVector>.
  void insert(size_t position, OMUInt32 name);

    // @cmember The number of elements in this <c OMStoredVectorIndex>.
  size_t entries(void) const;

    // @cmember Iterate over the elements in this <c OMStoredVectorIndex>.
  void iterate(size_t& context, OMUInt32& name) const;

    // @cmember Is this <c OMStoredVectorIndex> valid ?
  bool isValid(void) const;

private:

  OMUInt32 _highWaterMark;
  size_t _capacity;
  size_t _entries;
  OMUInt32* _names;
};

#endif
