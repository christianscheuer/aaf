#ifndef __AAFResult_h_
#define __AAFResult_h_

/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/


/* SESSION/FILE Error Codes */
#define AAFRESULT_BAD_SESSION				 0x80000010L
#define AAFRESULT_BADSESSIONOPEN			 0x80000011L
#define AAFRESULT_BADSESSIONMETA			 0x80000012L
#define AAFRESULT_BADSESSIONCLOSE			 0x80000013L
#define AAFRESULT_BADCONTAINER				 0x80000014L
#define AAFRESULT_FILEREV_NOT_SUPP			 0x80000015L
#define AAFRESULT_FILEREV_DIFF				 0x80000016L
#define AAFRESULT_BADOPEN					 0x80000017L
#define AAFRESULT_BADCLOSE					 0x80000018L
#define AAFRESULT_BAD_FHDL					 0x80000019L
#define AAFRESULT_BADHEAD					 0x8000001AL
#define AAFRESULT_NOBYTEORDER				 0x8000001BL
#define AAFRESULT_INVALID_BYTEORDER			 0x8000001CL
#define AAFRESULT_NOTAAFFILE				 0x8000001DL
#define AAFRESULT_WRONG_FILETYPE			 0x8000001EL
#define AAFRESULT_WRONG_OPENMODE			 0x8000001FL
#define AAFRESULT_CONTAINERWRITE			 0x80000020L
#define AAFRESULT_FILE_NOT_FOUND			 0x80000021L
#define AAFRESULT_CANNOT_SAVE_CLSD			 0x80000022L
#define AAFRESULT_CANNOT_LOAD_CLSD			 0x80000023L
#define AAFRESULT_FILE_REV_200				 0x80000024L
#define AAFRESULT_NEED_PRODUCT_IDENT		 0x80000025L
#define AAFRESULT_NOT_WRITEABLE				 0x80000026L
#define AAFRESULT_NOT_READABLE				 0x80000027L
#define AAFRESULT_FILE_EXISTS				 0x80000028L

/* MEDIA Error Codes */
#define AAFRESULT_DESCSAMPRATE				0x80000064L
#define AAFRESULT_SOURCEMOBLIST				0x80000065L
#define AAFRESULT_DESCLENGTH				0x80000066L
#define AAFRESULT_INTERNAL_MDO				0x80000067L
#define AAFRESULT_3COMPONENT				0x80000068L
#define AAFRESULT_INTERNAL_CORRUPTVINFO 	0x80000069L
#define AAFRESULT_BADSAMPLEOFFSET			0x8000006AL
#define AAFRESULT_ONESAMPLEREAD				0x8000006BL
#define AAFRESULT_ONESAMPLEWRITE			0x8000006CL
#define AAFRESULT_DECOMPRESS				0x8000006DL
#define AAFRESULT_NODATA					0x8000006EL
#define AAFRESULT_SMALLBUF					0x8000006FL
#define AAFRESULT_BADCOMPR					0x80000070L
#define AAFRESULT_BADPIXFORM				0x80000071L
#define AAFRESULT_BADLAYOUT					0x80000072L
#define AAFRESULT_COMPRLINESWR				0x80000073L
#define AAFRESULT_COMPRLINESRD				0x80000074L
#define AAFRESULT_BADMEDIATYPE 				0x80000075L
#define AAFRESULT_BADDATAADDRESS			0x80000076L
#define AAFRESULT_BAD_MDHDL					0x80000077L
#define AAFRESULT_MEDIA_NOT_FOUND			0x80000078L
#define AAFRESULT_ILLEGAL_MEMFMT			0x80000079L
#define AAFRESULT_ILLEGAL_FILEFMT			0x8000007AL
#define AAFRESULT_SWABBUFSIZE				0x8000007BL
#define AAFRESULT_MISSING_SWAP_PROC			0x8000007CL
#define AAFRESULT_NULL_STREAMPROC			0x8000007DL
#define AAFRESULT_NULLBUF					0x8000007EL
#define AAFRESULT_SWAP_SETUP				0x8000007FL
#define AAFRESULT_INVALID_FILE_MOB			0x80000080L
#define AAFRESULT_SINGLE_CHANNEL_OP			0x80000081L
#define AAFRESULT_INVALID_CACHE_SIZE		0x80000082L
#define AAFRESULT_NOT_FILEMOB				0x80000083L
#define AAFRESULT_TRANSLATE_SAMPLE_SIZE		0x80000084L
#define AAFRESULT_TRANSLATE_NON_INTEGRAL_RATE 0x80000085L
#define AAFRESULT_MISSING_MEDIA_REP			0x80000086L
#define AAFRESULT_NOT_LONGWORD				0x80000087L
#define AAFRESULT_XFER_DUPCH				0x80000088L
#define AAFRESULT_MEDIA_NOT_INIT			0x80000089L
#define AAFRESULT_BLOCKING_SIZE				0x8000008AL
#define AAFRESULT_WRONG_MEDIATYPE 			0x8000008BL
#define AAFRESULT_MULTI_WRITELEN			0x8000008CL
#define AAFRESULT_STREAM_REOPEN				0x8000008DL
#define AAFRESULT_TOO_MANY_FMT_OPS 			0x8000008EL
#define AAFRESULT_MEDIASTREAM_NOTALLOWED	0x8000008FL
#define AAFRESULT_STILLFRAME_BADLENGTH		0x80000090L
#define AAFRESULT_DATA_NONCONTIG			0x80000091L
#define AAFRESULT_OPLIST_OVERFLOW			0x80000092L
#define AAFRESULT_STREAM_CLOSED 			0x80000093L
#define AAF_RESULT_USE_MULTI_CREATE			0x80000094L
#define AAFRESULT_MEDIA_OPENMODE			0x80000095L
#define AAFRESULT_MEDIA_CANNOT_CLOSE 		0x80000096L
#define AAFRESULT_CODEC_INVALID 			0x80000097L
#define AAFRESULT_INVALID_OP_CODEC 			0x80000098L
#define AAFRESULT_BAD_CODEC_REV  			0x80000099L
#define AAFRESULT_CODEC_CHANNELS 			0x8000009AL
#define AAFRESULT_INTERN_TOO_SMALL  		0x8000009BL
#define AAFRESULT_INTERNAL_UNKNOWN_LOC 		0x8000009CL
#define AAFRESULT_TRANSLATE 				0x8000009DL
#define AAFRESULT_EOF 						0x8000009EL
#define AAFRESULT_TIFFVERSION 				0x8000009FL
#define AAFRESULT_BADTIFFCOUNT 				0x800000A0L
#define AAFRESULT_24BITVIDEO 				0x800000A1L
#define AAFRESULT_JPEGBASELINE 				0x800000A2L
#define AAFRESULT_BADJPEGINFO 				0x800000A3L
#define AAFRESULT_BADQTABLE  				0x800000A4L
#define AAFRESULT_BADACTABLE 				0x800000A5L
#define AAFRESULT_BADDCTABLE 				0x800000A6L
#define AAFRESULT_NOFRAMEINDEX  			0x800000A7L
#define AAFRESULT_BADFRAMEOFFSET 			0x800000A8L
#define AAFRESULT_JPEGPCM 					0x800000A9L
#define AAFRESULT_JPEGDISABLED 				0x800000AAL
#define AAFRESULT_JPEGPROBLEM 				0x800000ABL
#define AAFRESULT_BADEXPORTPIXFORM 			0x800000ACL
#define AAFRESULT_BADEXPORTLAYOUT 			0x800000ADL
#define AAFRESULT_BADRWLINES 				0x800000AEL
#define AAFRESULT_BADAIFCDATA 				0x800000AFL
#define AAFRESULT_BADWAVEDATA  				0x800000B0L
#define AAFRESULT_NOAUDIOCONV 				0x800000B1L
#define AAFRESULT_XFER_NOT_BYTES 			0x800000B2L
#define AAFRESULT_CODEC_NAME_SIZE 			0x800000B3L
#define AAFRESULT_ZERO_SAMPLESIZE 			0x800000B4L
#define AAFRESULT_ZERO_PIXELSIZE 			0x800000B5L
#define AAFRESULT_BAD_VARIETY 				0x800000B6L
	
/* OBJECT Error Codes */
#define AAFRESULT_NULLOBJECT				0x800000C8L
#define AAFRESULT_BADINDEX					0x800000C9L
#define AAFRESULT_INVALID_LINKAGE			0x800000CAL
#define AAFRESULT_BAD_PROP					0x800000CBL
#define AAFRESULT_BAD_TYPE					0x800000CCL
#define AAFRESULT_SWAB						0x800000CDL
#define AAFRESULT_END_OF_DATA 				0x800000CEL
#define AAFRESULT_PROP_NOT_PRESENT			0x800000CFL
#define AAFRESULT_INVALID_DATAKIND			0x800000D0L
#define AAFRESULT_DATAKIND_EXIST			0x800000D1L
#define AAFRESULT_TOO_MANY_TYPES			0x800000D2L
	
/* MOB Error Codes */
#define AAFRESULT_NOT_SOURCE_CLIP			0x800000FAL
#define AAFRESULT_FILL_FOUND				0x800000FBL
#define AAFRESULT_BAD_LENGTH 				0x800000FCL
#define AAFRESULT_BADRATE					0x800000FDL
#define AAFRESULT_INVALID_ROUNDING			0x800000FEL
#define AAFRESULT_TIMECODE_NOT_FOUND		0x800000FFL
#define AAFRESULT_NO_TIMECODE				0x80000100L
#define AAFRESULT_INVALID_TIMECODE 			0x80000101L
#define AAFRESULT_TRACK_NOT_FOUND			0x80000102L
#define AAFRESULT_BAD_SLOTLENGTH			0x80000103L
#define AAFRESULT_MISSING_TRACKID 			0x80000104L
#define AAFRESULT_TRACK_EXISTS 				0x80000105L
#define AAFRESULT_MOB_NOT_FOUND 			0x80000106L
#define AAFRESULT_NO_MORE_MOBS 				0x80000107L
#define AAFRESULT_DUPLICATE_MOBID 			0x80000108L
#define AAFRESULT_MISSING_MOBID 			0x80000109L
#define AAFRESULT_EFFECTDEF_EXIST  			0x8000010AL
#define AAFRESULT_INVALID_EFFECTDEF 		0x8000010BL
#define AAFRESULT_INVALID_EFFECT 			0x8000010CL
#define AAFRESULT_INVALID_EFFECTARG  		0x8000010DL
#define AAFRESULT_INVALID_CVAL 				0x8000010EL
#define AAFRESULT_RENDER_NOT_FOUND 			0x8000010FL
#define AAFRESULT_BAD_ITHDL 				0x80000110L
#define AAFRESULT_NO_MORE_OBJECTS 			0x80000111L
#define AAFRESULT_ITER_WRONG_TYPE 			0x80000112L
#define AAFRESULT_INVALID_SEARCH_CRIT 		0x80000113L	
#define AAFRESULT_INTERNAL_ITERATOR 		0x80000114L
#define AAFRESULT_NULL_MATCHFUNC 			0x80000115L
#define AAFRESULT_NULL_CALLBACKFUNC 		0x80000116L
#define AAFRESULT_TRAVERSAL_NOT_POSS 		0x80000117L
#define AAFRESULT_INVALID_TRAN_EFFECT		0x80000118L
#define AAFRESULT_ADJACENT_TRAN  			0x80000119L
#define AAFRESULT_LEADING_TRAN  			0x8000011AL
#define AAFRESULT_INSUFF_TRAN_MATERIAL  	0x8000011BL
#define AAFRESULT_PULLDOWN_DIRECTION  		0x8000011CL
#define AAFRESULT_PULLDOWN_FUNC  			0x8000011DL
#define AAFRESULT_PULLDOWN_KIND  			0x8000011EL
#define AAFRESULT_BAD_SRCH_ITER  			0x8000011FL
#define AAFRESULT_NOT_COMPOSITION  			0x80000120L
#define AAFRESULT_NOT_A_TRACK  				0x80000121L
#define AAFRESULT_PARSE_EFFECT_AMBIGUOUS  	0x80000122L

/* SIMPLE COMPOSITION Error Codes */
#define AAFRESULT_BAD_STRACKHDL				0x8000012CL
#define AAFRESULT_STRACK_APPEND_ILLEGAL		0x8000012DL

/* GENERIC Error Codes ***/
#define AAFRESULT_NOMEMORY					0x8000015EL
#define AAFRESULT_OFFSET_SIZE				0x8000015FL
#define AAFRESULT_INTERNAL_NEG64			0x80000160L
#define AAFRESULT_OVERFLOW64				0x80000161L
#define AAFRESULT_NOT_IN_15					0x80000162L
#define AAFRESULT_NOT_IN_20 				0x80000163L
#define AAFRESULT_NULL_PARAM				0x80000164L
#define AAFRESULT_ZERO_DIVIDE				0x80000165L

/* SEMANTIC CHECKING Error Codes */
#define AAFRESULT_REQUIRED_POSITIVE			0x80000190L
#define AAFRESULT_INVALID_TRACKKIND			0x80000191L
#define AAFRESULT_INVALID_EDGETYPE			0x80000192L
#define AAFRESULT_INVALID_FILMTYPE			0x80000193L
#define AAFRESULT_INVALID_MOBTYPE 			0x80000194L
#define AAFRESULT_INVALID_TAPECASETYPE		0x80000195L
#define AAFRESULT_INVALID_VIDEOSIGNALTYPE 	0x80000196L
#define AAFRESULT_INVALID_TAPEFORMATTYPE	0x80000197L
#define AAFRESULT_INVALID_EDITHINT 			0x80000198L
#define AAFRESULT_INVALID_INTERPKIND		0x80000199L
#define AAFRESULT_INVALID_TRACK_REF			0x8000019AL
#define AAFRESULT_INVALID_OBJ				0x8000019BL
#define AAFRESULT_BAD_VIRTUAL_CREATE 		0x8000019CL
#define AAFRESULT_INVALID_CLASS_ID			0x8000019DL
#define AAFRESULT_OBJECT_SEMANTIC			0x8000019EL
#define AAFRESULT_DATA_IN_SEMANTIC			0x8000019FL
#define AAFRESULT_DATA_OUT_SEMANTIC			0x800001A0L
#define AAFRESULT_TYPE_SEMANTIC 			0x800001A1L
#define AAFRESULT_INVALID_ATTRIBUTEKIND		0x800001A2L
#define AAFRESULT_DATA_MDES_DISAGREE		0x800001A3L
#define AAFRESULT_CODEC_SEMANTIC_WARN		0x800001A4L
#define AAFRESULT_INVALID_BOOLTYPE			0x800001A5L

/* INTERNAL Error Codes */
#define AAFRESULT_TABLE_DUP_KEY				0x800001C2L
#define AAFRESULT_TABLE_MISSING_COMPARE		0x800001C3L
#define AAFRESULT_TABLE_BAD_HDL				0x800001C4L
#define AAFRESULT_TABLE_BAD_ITER			0x800001C5L
#define AAFRESULT_BENTO_PROBLEM				0x800001C6L
#define AAFRESULT_BENTO_HANDLER				0x800001C7L
#define AAFRESULT_PROPID_MATCH				0x800001C8L
#define AAFRESULT_INTERNAL_DIVIDE			0x800001C9L

/* Testing Error Codes */
#define AAFRESULT_TEST_FAILED				0x800001F4L

#define AAFRESULT_MAXCODE					0x800001F5L


#endif // ! __AAFResult_h_
