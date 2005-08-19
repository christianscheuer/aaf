//=---------------------------------------------------------------------=
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
// The Original Code of this file is Copyright 1998-2003, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// @doc OMINTERNAL
// @author Tim Bingham | tjb | Avid Technology, Inc. | OMMXFStorage

#include "OMMXFStorage.h"

#include "OMRawStorage.h"
#include "OMAssertions.h"
#include "OMExceptions.h"
#include "OMUtilities.h"
#include "OMSet.h"
#include "OMIdentitySet.h"
#include "OMIdentitySetIter.h"
#include "OMType.h"
#include "OMUniqueObjectIdentType.h"

  // @mfunc Constructor.
OMMXFStorage::OMMXFStorage(OMRawStorage* store)
: OMWrappedRawStorage(store),
  _operationalPattern(nullOMKLVKey),
  _essenceContainerLabels(),
  _generation(nullOMUniqueObjectIdentification),
  _instanceIdToObject(0),
  _objectToInstanceId(0)
{
  TRACE("OMMXFStorage::OMMXFStorage");
}

  // @mfunc Destructor.
OMMXFStorage::~OMMXFStorage(void)
{
  TRACE("OMMXFStorage::~OMMXFStorage");

  if (_instanceIdToObject != 0) {
    _instanceIdToObject->clear();
    delete _instanceIdToObject;
    _instanceIdToObject = 0;
  }

  if (_objectToInstanceId != 0) {
    _objectToInstanceId->clear();
    delete _objectToInstanceId;
    _objectToInstanceId = 0;
  }
}

  // @mfunc Set the operational pattern to <p pattern>.
  //   @parm The operational pattern.
void OMMXFStorage::setOperationalPattern(const OMKLVKey& pattern)
{
  TRACE("OMMXFStorage::setOperationalPattern");
  _operationalPattern = pattern;
}

  // @mfunc Get the operational pattern.
  //   @rdesc The operational pattern.
OMKLVKey OMMXFStorage::operationalPattern(void) const
{
  TRACE("OMMXFStorage::operationalPattern");
  return _operationalPattern;
}

  // @mfunc Add <p label> to the set of essence container labels.
  //   @parm The essence container label.
void OMMXFStorage::addEssenceContainerLabel(const OMKLVKey& label)
{
  TRACE("OMMXFStorage::addEssenceContainerLabel");
  PRECONDITION("Label not present", !containsEssenceContainerLabel(label));

  _essenceContainerLabels.insert(label);
}

  // @mfunc Is <p label> present in the set of essence container labels.
  //   @parm The essence container label.
  //   @rdesc <e bool.true> if <p label> is present,
  //          <e bool.false> otherwise.
bool OMMXFStorage::containsEssenceContainerLabel(const OMKLVKey& label) const
{
  TRACE("OMMXFStorage::containsEssenceContainerLabel");

  bool result;
  if (_essenceContainerLabels.contains(label)) {
    result = true;
  } else {
    result = false;
  }
  return result;
}

  // @mfunc Create an iterator over the set of essence container labels.
  //  @rdesc The newly created iterator.
OMMXFStorage::LabelSetIterator*
OMMXFStorage::essenceContainerLabels(void) const
{
  TRACE("OMMXFStorage::essenceContainerLabels");

  LabelSetIterator* result = new LabelSetIterator(_essenceContainerLabels,
                                                  OMBefore);
  ASSERT("Valid heap pointer", result != 0);
  return result;
}

  // @mfunc Set the file generation.
  //   @parem The file generation.
void
OMMXFStorage::setGeneration(const OMUniqueObjectIdentification& generation)
{
  TRACE("OMMXFStorage::setGeneration");
  _generation = generation;
}

void OMMXFStorage::writeHeaderPartition(void)
{
  TRACE("OMMXFStorage::writeHeaderPartition");
  bool reorderBytes;
  if (hostByteOrder() == bigEndian) {
    reorderBytes = false;
  } else {
    reorderBytes = true;
  }
  writePartition(ClosedHeaderPartitionPackKey, KAGSize, reorderBytes);
  OMUInt64 currentPosition = position();
  fillAlignK(currentPosition, KAGSize);
}

void OMMXFStorage::writeBodyPartition(void)
{
  TRACE("OMMXFStorage::writeBodyPartition");
  bool reorderBytes;
  if (hostByteOrder() == bigEndian) {
    reorderBytes = false;
  } else {
    reorderBytes = true;
  }
  OMUInt32 KAGSize = 0x200; // Different than the default
  writePartition(ClosedBodyPartitionPackKey, KAGSize, reorderBytes);
  OMUInt64 currentPosition = position();
  fillAlignV(currentPosition, KAGSize);
}

void OMMXFStorage::writeFooterPartition(void)
{
  TRACE("OMMXFStorage::writeFooterPartition");
  bool reorderBytes;
  if (hostByteOrder() == bigEndian) {
    reorderBytes = false;
  } else {
    reorderBytes = true;
  }
  writePartition(ClosedFooterPartitionPackKey, KAGSize, reorderBytes);
}

void OMMXFStorage::writePartition(const OMKLVKey& key,
                                  OMUInt32 KAGSize,
                                  bool reorderBytes)
{
  TRACE("OMMXFStorage::writePartition");

  OMUInt32 elementSize = sizeof(OMKLVKey);
  LabelSetIterator* iter = essenceContainerLabels();
  OMUInt32 elementCount = iter->count();

  writeKLVKey(key);
  OMUInt64 sizeOfFixedPortion = 88;
  OMUInt64 length = sizeOfFixedPortion + (elementCount * elementSize);
#if defined(BER9)
  writeKLVLength(length);
#else
  writeBerLength(3, length);
#endif
  OMUInt16 majorVersion = currentMajorVersion;
  write(majorVersion, reorderBytes);
  OMUInt16 minorVersion = currentMinorVersion;
  write(minorVersion, reorderBytes);
  write(KAGSize, reorderBytes);
  OMUInt64 thisPartition = 0;
  write(thisPartition, reorderBytes);
  OMUInt64 previousPartition = 0;
  write(previousPartition, reorderBytes);
  OMUInt64 footerPartition = 0;
  write(footerPartition, reorderBytes);
  OMUInt64 headerByteCount = 0;
  write(headerByteCount, reorderBytes);
  OMUInt64 indexByteCount = 0;
  write(indexByteCount, reorderBytes);
  OMUInt32 indexSID = 1;
  write(indexSID, reorderBytes);
  OMUInt64 bodyOffset = 0;
  write(bodyOffset, reorderBytes);
  OMUInt32 bodySID = 2;
  write(bodySID, reorderBytes);
  writeKLVKey(_operationalPattern);
  write(elementCount, reorderBytes);
  write(elementSize, reorderBytes);
  while (++(*iter)) {
    OMKLVKey label = iter->value();
    writeKLVKey(label);
  }
  delete iter;
}

  // @mfunc Write a fill key, a BER encoded length and
  //        <p length> bytes of fill.
  //   @parm The number of bytes of fill to write.
void OMMXFStorage::writeKLVFill(const OMUInt64& length)
{
  TRACE("OMMXFStorage::writeKLVFill");

  writeKLVKey(fillKey);
#if defined(BER9)
  writeKLVLength(length);
#else
  writeBerLength(3, length);
#endif
  for (OMUInt64 i = 0; i < length; i++) {
#if defined(OM_DEBUG)
    const OMByte fillPattern[] = "FFFF.FFFC ";
    write(fillPattern[i % (sizeof(fillPattern) - 1)]);
#else
    const OMByte fillPattern = 0;
    write(fillPattern);
#endif
  }
}

  // @cmember Write fill so that the next key is page aligned.
  //   @parm The current position.
  //   @parm The page/KAG size.
void OMMXFStorage::fillAlignK(const OMUInt64& currentPosition,
                              const OMUInt32& KAGSize)
{
  TRACE("OMMXFStorage::fillAlignK");

#if defined(BER9)
  OMUInt64 minimumFill = sizeof(OMKLVKey) + sizeof(OMUInt64) + 1;
#else
  OMUInt64 minimumFill = sizeof(OMKLVKey) + 3 + 1;
#endif
  OMUInt64 nextPage = (currentPosition / KAGSize) + 1;
  OMUInt64 remainder = (nextPage * KAGSize) - currentPosition;
  if (remainder < minimumFill) {
    remainder = remainder + KAGSize;
  }
  remainder = remainder - minimumFill; // Subtract key and length of fill
  writeKLVFill(remainder);
}

  // @mfunc Write fill so that the next value is page aligned.
  //   @parm The current position.
  //   @parm The page/KAG size.
void OMMXFStorage::fillAlignV(const OMUInt64& currentPosition,
                              const OMUInt32& KAGSize)
{
  TRACE("OMMXFStorage::fillAlignV");

#if defined(BER9)
  OMUInt64 minimumFill = sizeof(OMKLVKey) + sizeof(OMUInt64) + 1;
#else
  OMUInt64 minimumFill = sizeof(OMKLVKey) + 3 + 1;
#endif
  OMUInt64 nextPage = (currentPosition / KAGSize) + 1;
  OMUInt64 remainder = (nextPage * KAGSize) - currentPosition;
  // Subtract key and length of triplet following this fill
  remainder = remainder - (sizeof(OMKLVKey) + sizeof(OMUInt64) + 1);
  if (remainder < minimumFill) {
    remainder = remainder + KAGSize;
  }
  remainder = remainder - minimumFill; // Subtract key and length of fill
  writeKLVFill(remainder);
}

void OMMXFStorage::write(const OMByte* bytes,
                         OMUInt32 byteCount,
                         OMUInt32& bytesWritten)
{
  TRACE("OMMXFStorage::write");
  OMWrappedRawStorage::write(bytes, byteCount, bytesWritten);
}

void OMMXFStorage::write(const OMUInt8& i)
{
  TRACE("OMMXFStorage::write");

  OMUInt32 x;
  write(&i, sizeof(OMUInt8), x);

  POSTCONDITION("All bytes written", x == sizeof(OMUInt8));
}

void OMMXFStorage::write(const OMUInt16& i, bool reorderBytes)
{
  TRACE("OMMXFStorage::write");

  OMUInt16 si = i;
  OMByte* src = reinterpret_cast<OMByte*>(&si);
  if (reorderBytes) {
    OMType::reorderInteger(src, sizeof(OMUInt16));
  }
  OMUInt32 x;
  write(src, sizeof(OMUInt16), x);

  POSTCONDITION("All bytes written", x == sizeof(OMUInt16));
}

void OMMXFStorage::write(const OMUInt32& i, bool reorderBytes)
{
  TRACE("OMMXFStorage::write");

  OMUInt32 si = i;
  OMByte* src = reinterpret_cast<OMByte*>(&si);
  if (reorderBytes) {
    OMType::reorderInteger(src, sizeof(OMUInt32));
  }
  OMUInt32 x;
  write(src, sizeof(OMUInt32), x);

  POSTCONDITION("All bytes written", x == sizeof(OMUInt32));
}

void OMMXFStorage::write(const OMUInt64& i, bool reorderBytes)
{
  TRACE("OMMXFStorage::write");

  OMUInt64 si = i;
  OMByte* src = reinterpret_cast<OMByte*>(&si);
  if (reorderBytes) {
    OMType::reorderInteger(src, sizeof(OMUInt64));
  }
  OMUInt32 x;
  write(src, sizeof(OMUInt64), x);

  POSTCONDITION("All bytes written", x == sizeof(OMUInt64));
}

void OMMXFStorage::write(const OMUniqueObjectIdentification& id,
                         bool reorderBytes)
{
  TRACE("OMMXFStorage::write");

  OMUniqueObjectIdentification sid = id;
  OMByte* src = reinterpret_cast<OMByte*>(&sid);
  if (reorderBytes) {
    OMUniqueObjectIdentificationType::instance()->reorder(
                                         src,
                                         sizeof(OMUniqueObjectIdentification));
  }
  OMUInt32 x;
  write(src, sizeof(OMUniqueObjectIdentification), x);

  POSTCONDITION("All bytes written",
                                    x == sizeof(OMUniqueObjectIdentification));
}

void OMMXFStorage::write(const OMByte* buffer, const OMUInt32& bufferSize)
{
  TRACE("OMMXFStorage::write");

  OMUInt32 x;
  write(buffer, bufferSize, x);

  POSTCONDITION("All bytes written", x == bufferSize);
}

void OMMXFStorage::writeKLVKey(const OMKLVKey& key)
{
  TRACE("OMMXFStorage::writeKLVKey");

  OMUInt32 x;
  const OMByte* src = reinterpret_cast<const OMByte*>(&key);
  write(src, sizeof(OMKLVKey), x);

  POSTCONDITION("All bytes written", x == sizeof(OMKLVKey));
}

void OMMXFStorage::writeKLVLength(const OMUInt8& length)
{
  TRACE("OMMXFStorage::writeKLVLength");

  writeBerLength(sizeof(OMUInt8), length);
}

void OMMXFStorage::writeKLVLength(const OMUInt16& length)
{
  TRACE("OMMXFStorage::writeKLVLength");

  writeBerLength(sizeof(OMUInt16), length);
}

void OMMXFStorage::writeKLVLength(const OMUInt32& length)
{
  TRACE("OMMXFStorage::writeKLVLength");

  writeBerLength(sizeof(OMUInt32), length);
}

void OMMXFStorage::writeKLVLength(const OMUInt64& length)
{
  TRACE("OMMXFStorage::writeKLVLength");

  writeBerLength(sizeof(OMUInt64), length);
}

void OMMXFStorage::writeBerLength(OMUInt32 lengthSize, const OMUInt64& length)
{
  TRACE("OMMXFStorage::writeBerLength");

  PRECONDITION("Valid size", lengthSize > 0);

  OMByte berLength[sizeof(OMUInt64) + 1]; // Max

  berEncode(berLength, sizeof(berLength), lengthSize, length);
  OMUInt32 x;
  write(berLength, lengthSize + 1, x);

  POSTCONDITION("All bytes written", x == (lengthSize + 1));
}

  // @mfunc The minimum size of <p i> when encoded using <f berEncode>.
  //        The returned size includes the BER length byte.
  //   @parm The value to encode.
  //   @rdesc The encoded size.
size_t OMMXFStorage::berEncodedSize(const OMUInt64 i)
{
  TRACE("OMMXFStorage::berEncodedSize");

  size_t result;
  if (i != 0) {
    result = sizeof(i);
    OMUInt64 v = i;
    while (((v & 0xff00000000000000) >> 56) == 0) {
      v = v << 8;
      result = result - 1;
    }
  } else {
    result = 1;
  }
  result = result + 1; // account for length byte
  return result;
}

  // @mfunc BER encode <p value> into <p berValueBuffer>.
  //   @parm OMByte* | berValueBuffer | The buffer in which to place the BER
  //         encoded value.
  //   @parm size_t | berValueBufferSize | The size of the buffer.
  //   @parm const OMUInt32& | berValueSize | The desired encoding size 1-8
  //         (does not include the BER length byte). e.g for a value that fits
  //         in an OMUInt32, 4 is sufficient.
  //   @parm const OMUInt64& | value | The value to encode.
void OMMXFStorage::berEncode(OMByte* berValueBuffer,
                                  size_t ANAME(berValueBufferSize),
                                  const OMUInt32& berValueSize,
                                  const OMUInt64& value)
{
  TRACE("OMMXFStorage::berEncode");
  PRECONDITION("Valid output buffer", berValueBuffer != 0);
  PRECONDITION("Valid output buffer size",
                              berValueBufferSize >= berEncodedSize(value));
  PRECONDITION("Valid size", berValueSize <= sizeof(OMUInt64));
  PRECONDITION("Valid size", berValueSize > 0);
  PRECONDITION("Valid size", berValueSize >= (berEncodedSize(value) - 1));

  OMByte* p = berValueBuffer;
  OMByte b = 0x80 | (OMByte)berValueSize;
  *p++ = b;
  size_t skip = sizeof(OMUInt64) - berValueSize;
  size_t i;
  OMUInt64 v = value;
  for (i = 0; i < skip; i++) {
    v = v << 8;
  }
  for (i = i; i < sizeof(OMUInt64); i++) {
    b = (OMByte)((v & 0xff00000000000000) >> 56);
    *p++ = b;
    v = v << 8;
  }
}

bool OMMXFStorage::readHeaderPartition(void)
{
  TRACE("OMMXFStorage::readHeaderPartition");

  bool reorderBytes;
  if (hostByteOrder() == bigEndian) {
    reorderBytes = false;
  } else {
    reorderBytes = true;
  }
  OMKLVKey k;
  bool result = true;
  readKLVKey(k);
  k.octet14 = 0x02;
  if (k == ClosedHeaderPartitionPackKey) {
    readKLVLength();
    OMUInt16 majorVersion;
    read(majorVersion, reorderBytes);
    if (majorVersion != currentMajorVersion) {
      result = false;
    }
    OMUInt16 minorVersion;
    read(minorVersion, reorderBytes);
    if (minorVersion != currentMinorVersion) {
      result = false;
    }
    OMUInt32 KAGSize;
    read(KAGSize, reorderBytes);
    OMUInt64 thisPartition;
    read(thisPartition, reorderBytes);
    OMUInt64 previousPartition;
    read(previousPartition, reorderBytes);
    OMUInt64 footerPartition;
    read(footerPartition, reorderBytes);
    OMUInt64 headerByteCount;
    read(headerByteCount, reorderBytes);
    OMUInt64 indexByteCount;
    read(indexByteCount, reorderBytes);
    OMUInt32 indexSID;
    read(indexSID, reorderBytes);
    OMUInt64 bodyOffset;
    read(bodyOffset, reorderBytes);
    OMUInt32 bodySID;
    read(bodySID, reorderBytes);
    OMKLVKey operationalPattern;
    readKLVKey(operationalPattern);
    OMUInt32 elementCount;
    read(elementCount, reorderBytes);
    OMUInt32 elementSize;
    read(elementSize, reorderBytes);
    OMKLVKey essenceContainer;
    for (OMUInt32 i = 0; i < elementCount; i++) {
      readKLVKey(essenceContainer);
    }
  } else {
    result = false;
  }
  return result;
}

bool OMMXFStorage::read(const OMRawStorage* store,
                        OMUInt16& i,
                        bool reorderBytes)
{
  TRACE("OMMXFStorage::read");
  bool result;
  OMUInt16 val;
  OMUInt32 bytesRead;
  OMByte* dest = reinterpret_cast<OMByte*>(&val);
  store->read(dest, sizeof(OMUInt16), bytesRead);
  if (bytesRead == sizeof(OMUInt16)) {
    if (reorderBytes) {
      OMType::reorderInteger(dest, sizeof(OMUInt16));
    }
    i = val;
    result = true;
  } else {
    result = false;
  }
  return result;
}

void OMMXFStorage::read(OMUInt8& i) const
{
  TRACE("OMMXFStorage::read");
  OMUInt8 result;
  OMUInt32 x;
  read(&result, sizeof(OMUInt8), x);
  ASSERT("All bytes read", x == sizeof(OMUInt8));
  i = result;
}

void OMMXFStorage::read(OMUInt16& i, bool reorderBytes) const
{
  TRACE("OMMXFStorage::read");
  OMUInt16 result;
  OMUInt32 x;
  OMByte* dest = reinterpret_cast<OMByte*>(&result);
  read(dest, sizeof(OMUInt16), x);
  ASSERT("All bytes read", x == sizeof(OMUInt16));
  if (reorderBytes) {
    OMType::reorderInteger(dest, sizeof(OMUInt16));
  }
  i = result;
}

void OMMXFStorage::read(OMUInt32& i, bool reorderBytes) const
{
  TRACE("OMMXFStorage::read");
  OMUInt32 result;
  OMUInt32 x;
  OMByte* dest = reinterpret_cast<OMByte*>(&result);
  read(dest, sizeof(OMUInt32), x);
  ASSERT("All bytes read", x == sizeof(OMUInt32));
  if (reorderBytes) {
    OMType::reorderInteger(dest, sizeof(OMUInt32));
  }
  i = result;
}

void OMMXFStorage::read(OMUInt64& i, bool reorderBytes) const
{
  TRACE("OMMXFStorage::read");
  OMUInt64 result;
  OMUInt32 x;
  OMByte* dest = reinterpret_cast<OMByte*>(&result);
  read(dest, sizeof(OMUInt64), x);
  ASSERT("All bytes read", x == sizeof(OMUInt64));
  if (reorderBytes) {
    OMType::reorderInteger(dest, sizeof(OMUInt64));
  }
  i = result;
}

void OMMXFStorage::read(OMUniqueObjectIdentification& id,
                        bool reorderBytes) const
{
  TRACE("OMMXFStorage::read");
  OMUniqueObjectIdentification result;
  OMUInt32 x;
  OMByte* dest = reinterpret_cast<OMByte*>(&result);
  read(dest, sizeof(OMUniqueObjectIdentification), x);
  ASSERT("All bytes read", x == sizeof(OMUniqueObjectIdentification));
  if (reorderBytes) {
    OMUniqueObjectIdentificationType::instance()->reorder(
                                         dest,
                                         sizeof(OMUniqueObjectIdentification));
  }
  id = result;
}

void OMMXFStorage::read(OMByte* buffer, const OMUInt32& bufferSize) const
{
  TRACE("OMMXFStorage::read");
  OMUInt32 x;
  read(buffer, bufferSize, x);
  ASSERT("All bytes read", x == bufferSize);
}

void OMMXFStorage::read(OMByte* bytes,
                        OMUInt32 byteCount,
                        OMUInt32& bytesRead) const
{
  TRACE("OMMXFStorage::read");
  OMWrappedRawStorage::read(bytes, byteCount, bytesRead);
}

void OMMXFStorage::readKLVKey(OMKLVKey& key) const
{
  TRACE("OMMXFStorage::readKLVKey");

  OMUInt32 x;
  OMByte* dest = reinterpret_cast<OMByte*>(&key);
  read(dest, sizeof(OMKLVKey), x);

  POSTCONDITION("All bytes read", x == sizeof(OMKLVKey));
}

OMUInt64 OMMXFStorage::readKLVLength(void) const
{
  TRACE("OMMXFStorage::readKLVLength");
  OMUInt64 result = readBerLength();
  return result;
}

void OMMXFStorage::readKLVFill(void) const
{
  TRACE("OMMXFStorage::readKLVFill");

  OMKLVKey k;
  readKLVKey(k);
  ASSERT("Fill key", k == fillKey);
  OMUInt64 length = readKLVLength();
  for (OMUInt64 i = 0; i < length; i++) {
    OMByte b;
    read(b);
  }
}

void OMMXFStorage::skipLV(void) const
{
  TRACE("OMMXFStorage::skipLV");

  OMUInt64 length = readKLVLength();
  OMUInt64 pos = position();
  OMUInt64 newPosition = pos + length;
  setPosition(newPosition);
}

OMUInt64 OMMXFStorage::readBerLength(void) const
{
  TRACE("OMMXFStorage::readBerLength");

  OMUInt64 result;
  OMUInt8 b;
  read(b);
  if (b == 0x80) {
    // unknown length
    result = 0;
  } else if ((b & 0x80) != 0x80) {
    // short form
    result = b;
  } else {
    // long form
    int length = b & 0x7f;
    result = 0;
    for (int k = 0; k < length; k++) {
      read(b);
      result = result << 8;
      result = result + b;
    }
  }
  return result;
}

OMMXFStorage::ObjectDirectory* OMMXFStorage::instanceIdToObject(void)
{
  TRACE("OMMXFStorage::instanceIdToObject");
  if (_instanceIdToObject == 0) {
    _instanceIdToObject = new ObjectDirectory();
    ASSERT("Valid heap pointer", _instanceIdToObject != 0);
  }
  return _instanceIdToObject;
}

OMMXFStorage::ObjectSet* OMMXFStorage::objectToInstanceId(void)
{
  TRACE("OMMXFStorage::objectToInstanceId");

  if (_objectToInstanceId == 0) {
    _objectToInstanceId = new ObjectSet();
    ASSERT("Valid heap pointer", _objectToInstanceId != 0);
  }
  return _objectToInstanceId;
}