#ifndef __AAFResult_h__
#define __AAFResult_h__

#if defined(_MAC) || defined(macintosh)
// Make sure SEVERITY_ERROR and FACILITY_ITF are defined.
#include <scode.h>
#endif

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
 *  prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
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

#define AAFRESULT_FAILED(Status) ((AAFRESULT)(Status)<0)
#define AAFRESULT_SUCCEEDED(Status) (!(AAFRESULT_FAILED(Status)))

// #define _FACILITY_AAF    FACILITY_ITF
#define _FACILITY_AAF 0x12
#define MAKE_AAFHRESULT( code ) MAKE_HRESULT( SEVERITY_ERROR, _FACILITY_AAF, code )

/* SESSION/FILE Error Codes */
#define AAFRESULT_BAD_SESSION                MAKE_AAFHRESULT(0x0010)
#define AAFRESULT_BADSESSIONOPEN             MAKE_AAFHRESULT(0x0011)
#define AAFRESULT_BADSESSIONMETA             MAKE_AAFHRESULT(0x0012)
#define AAFRESULT_BADSESSIONCLOSE            MAKE_AAFHRESULT(0x0013)
#define AAFRESULT_BADCONTAINER               MAKE_AAFHRESULT(0x0014)
#define AAFRESULT_FILEREV_NOT_SUPP           MAKE_AAFHRESULT(0x0015)
#define AAFRESULT_FILEREV_DIFF               MAKE_AAFHRESULT(0x0016)
#define AAFRESULT_BADOPEN                    MAKE_AAFHRESULT(0x0017)
#define AAFRESULT_BADCLOSE                   MAKE_AAFHRESULT(0x0018)
#define AAFRESULT_BAD_FHDL                   MAKE_AAFHRESULT(0x0019)
#define AAFRESULT_BADHEAD                    MAKE_AAFHRESULT(0x001A)
#define AAFRESULT_NOBYTEORDER                MAKE_AAFHRESULT(0x001B)
#define AAFRESULT_INVALID_BYTEORDER          MAKE_AAFHRESULT(0x001C)
#define AAFRESULT_NOT_AAF_FILE               MAKE_AAFHRESULT(0x001D)
#define AAFRESULT_WRONG_FILETYPE             MAKE_AAFHRESULT(0x001E)
#define AAFRESULT_WRONG_OPENMODE             MAKE_AAFHRESULT(0x001F)
#define AAFRESULT_CONTAINERWRITE             MAKE_AAFHRESULT(0x0020)
#define AAFRESULT_FILE_NOT_FOUND             MAKE_AAFHRESULT(0x0021)
#define AAFRESULT_CANNOT_SAVE_CLSD           MAKE_AAFHRESULT(0x0022)
#define AAFRESULT_CANNOT_LOAD_CLSD           MAKE_AAFHRESULT(0x0023)
#define AAFRESULT_FILE_REV_200               MAKE_AAFHRESULT(0x0024)
#define AAFRESULT_NEED_PRODUCT_IDENT         MAKE_AAFHRESULT(0x0025)
#define AAFRESULT_NOT_WRITEABLE              MAKE_AAFHRESULT(0x0026)
#define AAFRESULT_NOT_READABLE               MAKE_AAFHRESULT(0x0027)
#define AAFRESULT_FILE_EXISTS                MAKE_AAFHRESULT(0x0028)
#define AAFRESULT_NOT_OPEN                   MAKE_AAFHRESULT(0x0029)
#define AAFRESULT_ALREADY_OPEN               MAKE_AAFHRESULT(0x002A)
#define AAFRESULT_BAD_FLAGS                  MAKE_AAFHRESULT(0x002B)
#define AAFRESULT_BAD_FLAG_COMBINATION       MAKE_AAFHRESULT(0x002C)
#define AAFRESULT_UNSAVED_CHANGES            MAKE_AAFHRESULT(0x002D)
#define AAFRESULT_NOT_REVERTABLE             MAKE_AAFHRESULT(0x002E)
#define AAFRESULT_MEDIA_NOT_REVERTABLE       MAKE_AAFHRESULT(0x002F)

/* MEDIA Error Codes */
#define AAFRESULT_DESCSAMPRATE              MAKE_AAFHRESULT(0x0064)
#define AAFRESULT_SOURCEMOBLIST             MAKE_AAFHRESULT(0x0065)
#define AAFRESULT_DESCLENGTH                MAKE_AAFHRESULT(0x0066)
#define AAFRESULT_INTERNAL_MDO              MAKE_AAFHRESULT(0x0067)
#define AAFRESULT_3COMPONENT                MAKE_AAFHRESULT(0x0068)
#define AAFRESULT_INVALID_PARM_SIZE         MAKE_AAFHRESULT(0x0069)
#define AAFRESULT_BADSAMPLEOFFSET           MAKE_AAFHRESULT(0x006A)
#define AAFRESULT_ONESAMPLEREAD             MAKE_AAFHRESULT(0x006B)
#define AAFRESULT_ONESAMPLEWRITE            MAKE_AAFHRESULT(0x006C)
#define AAFRESULT_DECOMPRESS                MAKE_AAFHRESULT(0x006D)
#define AAFRESULT_NODATA                    MAKE_AAFHRESULT(0x006E)
#define AAFRESULT_SMALLBUF                  MAKE_AAFHRESULT(0x006F)
#define AAFRESULT_BADCOMPR                  MAKE_AAFHRESULT(0x0070)
#define AAFRESULT_BADPIXFORM                MAKE_AAFHRESULT(0x0071)
#define AAFRESULT_BADLAYOUT                 MAKE_AAFHRESULT(0x0072)
#define AAFRESULT_COMPRLINESWR              MAKE_AAFHRESULT(0x0073)
#define AAFRESULT_COMPRLINESRD              MAKE_AAFHRESULT(0x0074)
#define AAFRESULT_BADMEDIATYPE              MAKE_AAFHRESULT(0x0075)
#define AAFRESULT_BADDATAADDRESS            MAKE_AAFHRESULT(0x0076)
#define AAFRESULT_BAD_MDHDL                 MAKE_AAFHRESULT(0x0077)
#define AAFRESULT_MEDIA_NOT_FOUND           MAKE_AAFHRESULT(0x0078)
#define AAFRESULT_ILLEGAL_MEMFMT            MAKE_AAFHRESULT(0x0079)
#define AAFRESULT_ILLEGAL_FILEFMT           MAKE_AAFHRESULT(0x007A)
#define AAFRESULT_SWABBUFSIZE               MAKE_AAFHRESULT(0x007B)
#define AAFRESULT_MISSING_SWAP_PROC         MAKE_AAFHRESULT(0x007C)
#define AAFRESULT_NULL_STREAMPROC           MAKE_AAFHRESULT(0x007D)
#define AAFRESULT_NULLBUF                   MAKE_AAFHRESULT(0x007E)
#define AAFRESULT_SWAP_SETUP                MAKE_AAFHRESULT(0x007F)
#define AAFRESULT_INVALID_FILE_MOB          MAKE_AAFHRESULT(0x0080)
#define AAFRESULT_SINGLE_CHANNEL_OP         MAKE_AAFHRESULT(0x0081)
#define AAFRESULT_INVALID_CACHE_SIZE        MAKE_AAFHRESULT(0x0082)
#define AAFRESULT_NOT_FILEMOB               MAKE_AAFHRESULT(0x0083)
#define AAFRESULT_TRANSLATE_SAMPLE_SIZE     MAKE_AAFHRESULT(0x0084)
#define AAFRESULT_TRANSLATE_NON_INTEGRAL_RATE MAKE_AAFHRESULT(0x0085)
#define AAFRESULT_MISSING_MEDIA_REP         MAKE_AAFHRESULT(0x0086)
#define AAFRESULT_NOT_LONGWORD              MAKE_AAFHRESULT(0x0087)
#define AAFRESULT_XFER_DUPCH                MAKE_AAFHRESULT(0x0088)
#define AAFRESULT_MEDIA_NOT_INIT            MAKE_AAFHRESULT(0x0089)
#define AAFRESULT_BLOCKING_SIZE             MAKE_AAFHRESULT(0x008A)
#define AAFRESULT_WRONG_MEDIATYPE           MAKE_AAFHRESULT(0x008B)
#define AAFRESULT_MULTI_WRITELEN            MAKE_AAFHRESULT(0x008C)
#define AAFRESULT_STREAM_REOPEN             MAKE_AAFHRESULT(0x008D)
#define AAFRESULT_TOO_MANY_FMT_OPS          MAKE_AAFHRESULT(0x008E)
#define AAFRESULT_MEDIASTREAM_NOTALLOWED    MAKE_AAFHRESULT(0x008F)
#define AAFRESULT_STILLFRAME_BADLENGTH      MAKE_AAFHRESULT(0x0090)
#define AAFRESULT_DATA_NONCONTIG            MAKE_AAFHRESULT(0x0091)
#define AAFRESULT_OPLIST_OVERFLOW           MAKE_AAFHRESULT(0x0092)
#define AAFRESULT_STREAM_CLOSED             MAKE_AAFHRESULT(0x0093)
#define AAF_RESULT_USE_MULTI_CREATE         MAKE_AAFHRESULT(0x0094)
#define AAFRESULT_MEDIA_OPENMODE            MAKE_AAFHRESULT(0x0095)
#define AAFRESULT_MEDIA_CANNOT_CLOSE        MAKE_AAFHRESULT(0x0096)
#define AAFRESULT_CODEC_INVALID             MAKE_AAFHRESULT(0x0097)
#define AAFRESULT_INVALID_OP_CODEC          MAKE_AAFHRESULT(0x0098)
#define AAFRESULT_BAD_CODEC_REV             MAKE_AAFHRESULT(0x0099)
#define AAFRESULT_CODEC_CHANNELS            MAKE_AAFHRESULT(0x009A)
#define AAFRESULT_INTERN_TOO_SMALL          MAKE_AAFHRESULT(0x009B)
#define AAFRESULT_INTERNAL_UNKNOWN_LOC      MAKE_AAFHRESULT(0x009C)
#define AAFRESULT_TRANSLATE                 MAKE_AAFHRESULT(0x009D)
#define AAFRESULT_EOF                       MAKE_AAFHRESULT(0x009E)
#define AAFRESULT_TIFFVERSION               MAKE_AAFHRESULT(0x009F)
#define AAFRESULT_BADTIFFCOUNT              MAKE_AAFHRESULT(0x00A0)
#define AAFRESULT_24BITVIDEO                MAKE_AAFHRESULT(0x00A1)
#define AAFRESULT_JPEGBASELINE              MAKE_AAFHRESULT(0x00A2)
#define AAFRESULT_BADJPEGINFO               MAKE_AAFHRESULT(0x00A3)
#define AAFRESULT_BADQTABLE                 MAKE_AAFHRESULT(0x00A4)
#define AAFRESULT_BADACTABLE                MAKE_AAFHRESULT(0x00A5)
#define AAFRESULT_BADDCTABLE                MAKE_AAFHRESULT(0x00A6)
#define AAFRESULT_NOFRAMEINDEX              MAKE_AAFHRESULT(0x00A7)
#define AAFRESULT_BADFRAMEOFFSET            MAKE_AAFHRESULT(0x00A8)
#define AAFRESULT_JPEGPCM                   MAKE_AAFHRESULT(0x00A9)
#define AAFRESULT_JPEGDISABLED              MAKE_AAFHRESULT(0x00AA)
#define AAFRESULT_JPEGPROBLEM               MAKE_AAFHRESULT(0x00AB)
#define AAFRESULT_BADEXPORTPIXFORM          MAKE_AAFHRESULT(0x00AC)
#define AAFRESULT_BADEXPORTLAYOUT           MAKE_AAFHRESULT(0x00AD)
#define AAFRESULT_BADRWLINES                MAKE_AAFHRESULT(0x00AE)
#define AAFRESULT_BADAIFCDATA               MAKE_AAFHRESULT(0x00AF)
#define AAFRESULT_BADWAVEDATA               MAKE_AAFHRESULT(0x00B0)
#define AAFRESULT_NOAUDIOCONV               MAKE_AAFHRESULT(0x00B1)
#define AAFRESULT_XFER_NOT_BYTES            MAKE_AAFHRESULT(0x00B2)
#define AAFRESULT_CODEC_NAME_SIZE           MAKE_AAFHRESULT(0x00B3)
#define AAFRESULT_ZERO_SAMPLESIZE           MAKE_AAFHRESULT(0x00B4)
#define AAFRESULT_ZERO_PIXELSIZE            MAKE_AAFHRESULT(0x00B5)
#define AAFRESULT_BAD_VARIETY               MAKE_AAFHRESULT(0x00B6)
#define AAFRESULT_FORMAT_BOUNDS             MAKE_AAFHRESULT(0x00B7)     
#define AAFRESULT_FORMAT_NOT_FOUND          MAKE_AAFHRESULT(0x00B8)
#define AAFRESULT_UNKNOWN_CONTAINER         MAKE_AAFHRESULT(0x00B9)

/* OBJECT Error Codes */
#define AAFRESULT_NULLOBJECT                MAKE_AAFHRESULT(0x00C8)
#define AAFRESULT_BADINDEX                  MAKE_AAFHRESULT(0x00C9)
#define AAFRESULT_INVALID_LINKAGE           MAKE_AAFHRESULT(0x00CA)
#define AAFRESULT_BAD_PROP                  MAKE_AAFHRESULT(0x00CB)
#define AAFRESULT_BAD_TYPE                  MAKE_AAFHRESULT(0x00CC)
#define AAFRESULT_SWAB                      MAKE_AAFHRESULT(0x00CD)
#define AAFRESULT_END_OF_DATA               MAKE_AAFHRESULT(0x00CE)
#define AAFRESULT_PROP_NOT_PRESENT          MAKE_AAFHRESULT(0x00CF)
#define AAFRESULT_INVALID_DATADEF           MAKE_AAFHRESULT(0x00D0)
#define AAFRESULT_DATADEF_EXIST             MAKE_AAFHRESULT(0x00D1)
#define AAFRESULT_TOO_MANY_TYPES            MAKE_AAFHRESULT(0x00D2)
#define AAFRESULT_BAD_TYPE_CATEGORY         MAKE_AAFHRESULT(0x00D5)
#define AAFRESULT_OBJECT_NOT_FOUND          MAKE_AAFHRESULT(0x00D6)
#define AAFRESULT_IS_ROOT_CLASS             MAKE_AAFHRESULT(0x00D7)
#define AAFRESULT_TYPE_NOT_FOUND            MAKE_AAFHRESULT(0x00D8)
#define AAFRESULT_PROPERTY_NOT_FOUND        MAKE_AAFHRESULT(0x00D9)
#define AAFRESULT_CLASS_NOT_FOUND           MAKE_AAFHRESULT(0x00DA)
#define AAFRESULT_PROPERTY_DUPLICATE        MAKE_AAFHRESULT(0x00DB)
#define AAFRESULT_ELEMENT_NOT_PRESENT       MAKE_AAFHRESULT(0x00DC)
#define AAFRESULT_ELEMENT_NOT_OBJECT        MAKE_AAFHRESULT(0x00DD)
#define AAFRESULT_PROP_ALREADY_PRESENT      MAKE_AAFHRESULT(0x00DE)

/* MOB Error Codes */
#define AAFRESULT_NOT_SOURCE_CLIP           MAKE_AAFHRESULT(0x00FA)
#define AAFRESULT_FILL_FOUND                MAKE_AAFHRESULT(0x00FB)
#define AAFRESULT_BAD_LENGTH                MAKE_AAFHRESULT(0x00FC)
#define AAFRESULT_BADRATE                   MAKE_AAFHRESULT(0x00FD)
#define AAFRESULT_INVALID_ROUNDING          MAKE_AAFHRESULT(0x00FE)
#define AAFRESULT_TIMECODE_NOT_FOUND        MAKE_AAFHRESULT(0x00FF)
#define AAFRESULT_NO_TIMECODE               MAKE_AAFHRESULT(0x0100)
#define AAFRESULT_INVALID_TIMECODE          MAKE_AAFHRESULT(0x0101)
#define AAFRESULT_SLOT_NOT_FOUND            MAKE_AAFHRESULT(0x0102)
#define AAFRESULT_BAD_SLOTLENGTH            MAKE_AAFHRESULT(0x0103)
#define AAFRESULT_MISSING_TRACKID           MAKE_AAFHRESULT(0x0104)
#define AAFRESULT_SLOT_EXISTS               MAKE_AAFHRESULT(0x0105)
#define AAFRESULT_MOB_NOT_FOUND             MAKE_AAFHRESULT(0x0106)
#define AAFRESULT_NO_MORE_MOBS              MAKE_AAFHRESULT(0x0107)
#define AAFRESULT_DUPLICATE_MOBID           MAKE_AAFHRESULT(0x0108)
#define AAFRESULT_MISSING_MOBID             MAKE_AAFHRESULT(0x0109)
#define AAFRESULT_EFFECTDEF_EXIST           MAKE_AAFHRESULT(0x010A)
#define AAFRESULT_INVALID_EFFECTDEF         MAKE_AAFHRESULT(0x010B)
#define AAFRESULT_INVALID_EFFECT            MAKE_AAFHRESULT(0x010C)
#define AAFRESULT_INVALID_EFFECTARG         MAKE_AAFHRESULT(0x010D)
#define AAFRESULT_INVALID_CVAL              MAKE_AAFHRESULT(0x010E)
#define AAFRESULT_RENDER_NOT_FOUND          MAKE_AAFHRESULT(0x010F)
#define AAFRESULT_BAD_ITHDL                 MAKE_AAFHRESULT(0x0110)
#define AAFRESULT_NO_MORE_OBJECTS           MAKE_AAFHRESULT(0x0111)
#define AAFRESULT_ITER_WRONG_TYPE           MAKE_AAFHRESULT(0x0112)
#define AAFRESULT_INVALID_SEARCH_CRIT       MAKE_AAFHRESULT(0x0113L 
#define AAFRESULT_INTERNAL_ITERATOR         MAKE_AAFHRESULT(0x0114)
#define AAFRESULT_NULL_MATCHFUNC            MAKE_AAFHRESULT(0x0115)
#define AAFRESULT_NULL_CALLBACKFUNC         MAKE_AAFHRESULT(0x0116)
#define AAFRESULT_TRAVERSAL_NOT_POSS        MAKE_AAFHRESULT(0x0117)
#define AAFRESULT_INVALID_TRAN_EFFECT       MAKE_AAFHRESULT(0x0118)
#define AAFRESULT_ADJACENT_TRAN             MAKE_AAFHRESULT(0x0119)
#define AAFRESULT_LEADING_TRAN              MAKE_AAFHRESULT(0x011A)
#define AAFRESULT_INSUFF_TRAN_MATERIAL      MAKE_AAFHRESULT(0x011B)
#define AAFRESULT_PULLDOWN_DIRECTION        MAKE_AAFHRESULT(0x011C)
#define AAFRESULT_PULLDOWN_FUNC             MAKE_AAFHRESULT(0x011D)
#define AAFRESULT_PULLDOWN_KIND             MAKE_AAFHRESULT(0x011E)
#define AAFRESULT_BAD_SRCH_ITER             MAKE_AAFHRESULT(0x011F)
#define AAFRESULT_NOT_COMPOSITION           MAKE_AAFHRESULT(0x0120)
#define AAFRESULT_NOT_A_TRACK               MAKE_AAFHRESULT(0x0121)
#define AAFRESULT_PARSE_EFFECT_AMBIGUOUS    MAKE_AAFHRESULT(0x0122)
#define AAFRESULT_NO_ESSENCE_DESC           MAKE_AAFHRESULT(0x0123)
#define AAFRESULT_TAPE_DESC_ONLY            MAKE_AAFHRESULT(0x0124)
#define AAFRESULT_FILM_DESC_ONLY            MAKE_AAFHRESULT(0x0125)
#define AAFRESULT_UNKNOWN_PARAMETER_CLASS   MAKE_AAFHRESULT(0x0126)
#define AAFRESULT_PARAMETER_NOT_FOUND       MAKE_AAFHRESULT(0x0127) 
#define AAFRESULT_SEGMENT_NOT_FOUND         MAKE_AAFHRESULT(0x0128) 
#define AAFRESULT_ESSENCE_NOT_FOUND         MAKE_AAFHRESULT(0x0129) 


/* SIMPLE COMPOSITION Error Codes */
#define AAFRESULT_BAD_STRACKHDL             MAKE_AAFHRESULT(0x012C)
#define AAFRESULT_STRACK_APPEND_ILLEGAL     MAKE_AAFHRESULT(0x012D)

/* Object Management Related Error Codes */
#define AAFRESULT_OBJECT_ALREADY_IN_FILE    MAKE_AAFHRESULT(0x0130)
#define AAFRESULT_OBJECT_NOT_IN_FILE        MAKE_AAFHRESULT(0x0131)
#define AAFRESULT_OBJECT_ALREADY_ATTACHED   MAKE_AAFHRESULT(0x0132)
#define AAFRESULT_OBJECT_NOT_ATTACHED       MAKE_AAFHRESULT(0x0133)
#define AAFRESULT_OBJECT_ALREADY_PERSISTENT MAKE_AAFHRESULT(0x0134)
#define AAFRESULT_OBJECT_NOT_PERSISTENT     MAKE_AAFHRESULT(0x0135)

/* GENERIC Error Codes ***/
#define AAFRESULT_NOMEMORY                  MAKE_AAFHRESULT(0x015E)
#define AAFRESULT_OFFSET_SIZE               MAKE_AAFHRESULT(0x015F)
#define AAFRESULT_INTERNAL_NEG64            MAKE_AAFHRESULT(0x0160)
#define AAFRESULT_OVERFLOW64                MAKE_AAFHRESULT(0x0161)
#define AAFRESULT_NOT_IN_CURRENT_VERSION    MAKE_AAFHRESULT(0x0162)
#define AAFRESULT_NULL_PARAM                MAKE_AAFHRESULT(0x0164)
#define AAFRESULT_ZERO_DIVIDE               MAKE_AAFHRESULT(0x0165)
#define AAFRESULT_ALREADY_INITIALIZED       MAKE_AAFHRESULT(0x0166)
#define AAFRESULT_NOT_INITIALIZED           MAKE_AAFHRESULT(0x0167)
#define AAFRESULT_INTERNAL_ERROR            MAKE_AAFHRESULT(0x0168)
#define AAFRESULT_DATA_SIZE                 MAKE_AAFHRESULT(0x0169)
#define AAFRESULT_ILLEGAL_VALUE             MAKE_AAFHRESULT(0x016A)
#define AAFRESULT_INVALID_TRANSPARENCY      MAKE_AAFHRESULT(0x016B)
#define AAFRESULT_INVALID_PARAM             MAKE_AAFHRESULT(0x016C)
#define AAFRESULT_INVALID_ENUM_VALUE        MAKE_AAFHRESULT(0x016D)

/* SEMANTIC CHECKING Error Codes */
#define AAFRESULT_REQUIRED_POSITIVE         MAKE_AAFHRESULT(0x0190)
#define AAFRESULT_INVALID_TRACKKIND         MAKE_AAFHRESULT(0x0191)
#define AAFRESULT_INVALID_EDGETYPE          MAKE_AAFHRESULT(0x0192)
#define AAFRESULT_INVALID_FILMTYPE          MAKE_AAFHRESULT(0x0193)
#define AAFRESULT_INVALID_MOBTYPE           MAKE_AAFHRESULT(0x0194)
#define AAFRESULT_INVALID_TAPECASETYPE      MAKE_AAFHRESULT(0x0195)
#define AAFRESULT_INVALID_VIDEOSIGNALTYPE   MAKE_AAFHRESULT(0x0196)
#define AAFRESULT_INVALID_TAPEFORMATTYPE    MAKE_AAFHRESULT(0x0197)
#define AAFRESULT_INVALID_EDITHINT          MAKE_AAFHRESULT(0x0198)
#define AAFRESULT_INVALID_INTERPKIND        MAKE_AAFHRESULT(0x0199)
#define AAFRESULT_INVALID_TRACK_REF         MAKE_AAFHRESULT(0x019A)
#define AAFRESULT_INVALID_OBJ               MAKE_AAFHRESULT(0x019B)
#define AAFRESULT_BAD_VIRTUAL_CREATE        MAKE_AAFHRESULT(0x019C)
#define AAFRESULT_INVALID_CLASS_ID          MAKE_AAFHRESULT(0x019D)
#define AAFRESULT_OBJECT_SEMANTIC           MAKE_AAFHRESULT(0x019E)
#define AAFRESULT_DATA_IN_SEMANTIC          MAKE_AAFHRESULT(0x019F)
#define AAFRESULT_DATA_OUT_SEMANTIC         MAKE_AAFHRESULT(0x01A0)
#define AAFRESULT_TYPE_SEMANTIC             MAKE_AAFHRESULT(0x01A1)
#define AAFRESULT_INVALID_ATTRIBUTEKIND     MAKE_AAFHRESULT(0x01A2)
#define AAFRESULT_DATA_MDES_DISAGREE        MAKE_AAFHRESULT(0x01A3)
#define AAFRESULT_CODEC_SEMANTIC_WARN       MAKE_AAFHRESULT(0x01A4)
#define AAFRESULT_INVALID_BOOLTYPE          MAKE_AAFHRESULT(0x01A5)

/* INTERNAL Error Codes */
#define AAFRESULT_TABLE_DUP_KEY             MAKE_AAFHRESULT(0x01C2)
#define AAFRESULT_TABLE_MISSING_COMPARE     MAKE_AAFHRESULT(0x01C3)
#define AAFRESULT_TABLE_BAD_HDL             MAKE_AAFHRESULT(0x01C4)
#define AAFRESULT_TABLE_BAD_ITER            MAKE_AAFHRESULT(0x01C5)
#define AAFRESULT_PROPID_MATCH              MAKE_AAFHRESULT(0x01C8)
#define AAFRESULT_INTERNAL_DIVIDE           MAKE_AAFHRESULT(0x01C9)
#define AAFRESULT_ABSTRACT_CLASS            MAKE_AAFHRESULT(0x01CA)
#define AAFRESULT_WRONG_SIZE                MAKE_AAFHRESULT(0x01CB)
#define AAFRESULT_INCONSISTANCY             MAKE_AAFHRESULT(0x01CC)

/* Reference implementation assertion violation (programming error) */
#define AAFRESULT_ASSERTION_VIOLATION       MAKE_AAFHRESULT(0x01D0)

/* Reference implementation unexpected C++ exception (programming error) */
#define AAFRESULT_UNEXPECTED_EXCEPTION      MAKE_AAFHRESULT(0x01D1)

/* Testing Error Codes */
#define AAFRESULT_TEST_FAILED               MAKE_AAFHRESULT(0x01F4)
#define AAFRESULT_TEST_PARTIAL_SUCCESS      MAKE_AAFHRESULT(0x01F5)
#define AAFRESULT_NOT_IMPLEMENTED                           0x80004001L
#define AAFRESULT_SUCCESS                                   0
#define HRESULT_NOT_IMPLEMENTED                             0x80004001L
#define HRESULT_SUCCESS                                     0

/* Property access error codes */
#define AAFRESULT_BAD_SIZE                       MAKE_AAFHRESULT(0x0200)
#define AAFRESULT_NOT_REGISTERED                 MAKE_AAFHRESULT(0x0201)
#define AAFRESULT_NOT_EXTENDABLE                 MAKE_AAFHRESULT(0x0202)
#define AAFRESULT_ALREADY_UNIQUELY_IDENTIFIED    MAKE_AAFHRESULT(0x0203)
#define AAFRESULT_DEFAULT_ALREADY_USED           MAKE_AAFHRESULT(0x0204)

/* Object extension error codes */
#define AAFRESULT_EXTENSION_NOT_FOUND            MAKE_AAFHRESULT(0x0300)
#define AAFRESULT_EXTENSION_ALREADY_INITIALIZED  MAKE_AAFHRESULT(0x0301)
#define AAFRESULT_PLUGIN_NOT_REGISTERED          MAKE_AAFHRESULT(0x0302)
#define AAFRESULT_PLUGIN_ALREADY_REGISTERED      MAKE_AAFHRESULT(0x0303)
#define AAFRESULT_PLUGIN_CIRCULAR_REFERENCE      MAKE_AAFHRESULT(0x0304)
#define AAFRESULT_PLUGIN_INVALID_REFERENCE_COUNT MAKE_AAFHRESULT(0x0305)



#define AAFRESULT_MAXCODE                   MAKE_AAFHRESULT(0x0305)


#endif // ! __AAFResult_h__
