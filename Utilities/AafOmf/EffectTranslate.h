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

/************************************************************************
 *
 * Omf2Aaf.h Describes structures and prototypes for the OMF to AAF 
 *          conversion utility.
 *
 ************************************************************************/

HRESULT GetEffectIDs(IAAFOperationGroup *effect,
									   OMF2::omfUniqueNamePtr_t effectID,
									   OMF2::omfUniqueNamePtr_t MCEffectID);

HRESULT GetAAFEffectID(	OMF2::omfUniqueNamePtr_t OMFEffectIDPtr,
						OMF2::omfUniqueNamePtr_t MCEffectIDPtr,
						aafUID_t	*aafUID);

IAAFInterpolationDef *CreateInterpolationDefinition(IAAFDictionary *dict, aafUID_t interpolationDefID);

typedef struct OMFIPvtKFInfo OMFIPvtKFInfo_t;

void ExportSeparateKeyframeData(aafUID_t &effectUID,
								aafInt32 numKF,
								OMFIPvtKFInfo_t **keyframes,
								aafRational_t *times,
								IAAFDictionary		*pDict,
								IAAFOperationGroup* pOutputEffect);

IAAFVaryingValue *AAFAddEmptyVaryingVal(IAAFDictionary *dict, IAAFOperationGroup *pOutputEffect);
IAAFParameter *AAFAddConstantVal(IAAFDictionary *dict, long buflen, void *buf, IAAFOperationGroup *pGroup);
void AAFAddOnePoint(IAAFDictionary *dict, aafRational_t percentTime, long buflen, void *buf, IAAFTypeDef *typeDef, IAAFVaryingValue *pVVal);
IAAFParameterDef *CreateParameterDefinition(IAAFDictionary *dict, aafUID_t parmDefID);
IAAFTypeDef *CreateTypeDefinition(IAAFDictionary *dict, aafUID_t typeDefID);
bool EffectCapabilityPresent(aafUID_t &effectUID, aafUInt32 capabilityMask);
aafInt32 GetMCKeyframeSlotID(aafUID_t& uid);
aafInt32 GetMCGlobalSlotID(aafUID_t& uid);
bool isMCPrivateEffect(aafUID_t& uid);

// Media composer effect IDs
const aafUID_t kEffBlendPIPUUID =		{0xD94E75C2,0x6ADF,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffBlendSuperUUID =	{0xD94E75C4,0x6ADF,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffBlendFadeUpUUID =	{0xD94E75C7,0x6ADF,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffBlendDipUUID =		{0xD94E75C8,0x6ADF,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffXRotate = {0x783B4810,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffYRotate = {0x783B4811,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffZRotate = {0x783B4812,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeZoom = {0x783B4813,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeHorz = {0x783B4814,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeVert = {0x783B4815,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeBottomCenter = {0x783B4816,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeRightCenter = {0x783B4817,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeTopCenter = {0x783B4818,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeLeftCenter = {0x783B4818,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeTop = {0x783B481A,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeBottom = {0x783B481B,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeLeft = {0x783B481C,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeRight = {0x783B481D,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeBottomLeft = {0x783B481E,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeTopRight = {0x783B481F,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeBottomRight = {0x783B4820,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSqueezeTopLeft = {0x783B4821,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffAudioPanvol = {0xF1DB0F22,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffAudioEQ = {0xF1DB0F23,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffAudioSuite = {0xF1DB0F24,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffTimeWarp = {0xF1DB0F25,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffMotionStrobe = {0xF1DB0F26,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffAudioWarp = {0xF1DB0F27,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffMask166 = {0xF1DB0F29,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffMask185 = {0xF1DB0F2A,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffMask235 = {0xF1DB0F2B,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffMask177 = {0xF1DB0F2C,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffVDissolveLin = {0xF1DB0F2D,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffVDissolveLog = {0xF1DB0F2E,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffBlowUp = {0xF1DB0F2F,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffBlendMask = {0xF1DB0F30,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffColorCorrect = {0xF1DB0F31,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffRGBColorCorrect = {0xF1DB0F61,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffFlipVert = {0xF1DB0F32,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffFlipBoth = {0xF1DB0F33,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffFlipHoriz = {0xF1DB0F34,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffMaskImage = {0xF1DB0F35,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPaint = {0xF1DB0F36,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPaintMosaic = {0xF1DB0F37,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPaintSpotColor = {0xF1DB0F38,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPaintMPEGOutline = {0xF1DB0F39,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPaintScratch = {0xF1DB0F3A,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPaintResize = {0xF1DB0F3B,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPanScan = {0xF1DB0F3C,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSubmaster = {0xF1DB0F3d,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffAnimatte = {0xF1DB0F3E,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffLumaKey = {0xF1DB0F3F,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffMatteKey = {0xF1DB0F40,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffYUVChromaKey = {0xF1DB0F41,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSimpleLumaKey = {0xF1DB0F42,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSimpleChromaKey = {0xF1DB0F43,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffChromaKey = {0xF1DB0F44,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffToucanChromaKey = {0xF1DB0F45,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff2DMatteKey = {0xF1DB0F46,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffConceal = {0xF1DB0F47,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffLConceal = {0xF1DB0F48,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPeel = {0xF1DB0F49,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffPush = {0xF1DB0F4A,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffSBlend = {0xF1DB0F4B,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DPIP = {0xF1DB0F4C,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DPageCurl = {0xF1DB0F4D,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DQuadCurl = {0xF1DB0F4E,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DShapeArrow = {0xF1DB0F4F,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DShapeSlats = {0xF1DB0F50,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DShapeMultiWave = {0xF1DB0F51,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DShapeCenterBurst = {0xF1DB0F52,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DShapeSineWave = {0xF1DB0F53,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DShapeBall = {0xF1DB0F54,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DShapePageFold = {0xF1DB0F55,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DShapeBumps = {0xF1DB0F56,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DTitle = {0xF1DB0F57,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEff3DMatteKey = {0xF1DB0F58,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffRollingTitle = {0xF1DB0F59,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffRolling2dMatte = {0xF1DB0F5A,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffCrawlingTitle = {0xF1DB0F5B,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffCrawling2DMatte = {0xF1DB0F5C,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffTestOneTrack = {0xF1DB0F5D,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffTestTwoTrack = {0xF1DB0F5E,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffTestThreeTrack = {0xF1DB0F5F,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};

// Direction codes for Conceal, LConceal, Peel, and Push
const aafUID_t kEffDirBottomLeft = {0xF1DB0F62,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffDirBottomRight = {0xF1DB0F63,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffDirTopRight = {0xF1DB0F64,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffDirTopLeft = {0xF1DB0F65,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffDirTop = {0xF1DB0F66,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffDirBottom = {0xF1DB0F67,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffDirLeft = {0xF1DB0F68,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kEffDirRight = {0xF1DB0F69,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};

// Media composer parameter IDs
const aafUID_t kAAFParamID_AvidBorderWidth =	{0x8BC42735,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidBorderSoft =	{0x8BC42736,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidXPos =	{0x8BC42737,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidYPos =	{0x8BC42738,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidCrop =	{0x8BC42739,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidScale =	{0x8BC4273A,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidSpillSupress =	{0x8BC4273B,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidBounds =	{0x8BC4273C,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidColor =	{0x8BC4273D,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidUserParam =	{0x8BC4273E,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidEffectName = {0x783B480F,0x7CF6,0x11d3,{0x80,0xD5,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidDirection = {0xF1DB0F6A,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFParamID_AvidGlobalKF = { 0x9997779, 0x960e, 0x11d3, { 0xa0, 0x4e, 0x0, 0x60, 0x94, 0xeb, 0x75, 0xcb } };

// Media Composer type ID's
const aafUID_t kAAFTypeID_AvidPosition =	{0x8BC4272E,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFTypeID_AvidCrop =	{0x8BC4272F,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFTypeID_AvidScale =	{0x8BC42730,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFTypeID_AvidSpillSupress =	{0x8BC42731,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFTypeID_AvidBounds =	{0x8BC42732,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFTypeID_AvidEffColor =	{0x8BC42733,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFTypeID_AvidEffUserParam =	{0x8BC42734,0x6BAB,0x11d3,{0x80,0xCF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFTypeID_AvidDirection = {0xF1DB0F6B,0x8D64,0x11d3,{0x80,0xDF,0x00,0x60,0x08,0x14,0x3E,0x6F}};
const aafUID_t kAAFTypeID_AvidGlobalKF = { 0x9997778, 0x960e, 0x11d3, { 0xa0, 0x4e, 0x0, 0x60, 0x94, 0xeb, 0x75, 0xcb } };

// Avid MC Private effect blob
#define MAX_EFFECT_COLORS		16

typedef	unsigned long	AvFixed30;
typedef	unsigned long	AvFixed16;

typedef struct
	{
	unsigned char 		hue;
	unsigned char 		sat;
	unsigned char 		lum;
	unsigned char		dep;
	} hsl8Color_t, **hsl8ColorHdl;

typedef	struct
	{
	AvFixed16	top;
	AvFixed16	left;
	AvFixed16	bottom;
	AvFixed16	right;
	unsigned char		Lvl2Xscale;
	unsigned char		Lvl2Yscale;
	unsigned char		Lvl2Xpos;
	unsigned char		Lvl2Ypos;
	} OMFIPvtFixedRect;

#pragma pack(1)
struct OMFIPvtKFInfo
	{
	long		cookie;
	long		revision;
	long	    selected;			// Boolean would have struct alignment problems x-platform
	AvFixed30	percentTime;
	AvFixed30	level;
	AvFixed16	posX;
	AvFixed16	XFloor;
	AvFixed16	XCeiling;
	AvFixed16	posY;
	AvFixed16	YFloor;
	AvFixed16	YCeiling;
	AvFixed16	Xscale;
	AvFixed16	Yscale;

	AvFixed16	cropLeft;
	AvFixed16	cropRight;
	AvFixed16	cropTop;
	AvFixed16	cropBottom;
	
	OMFIPvtFixedRect	Box;
	long				borderWidth;
	long				borderSoft;
	long				nColors;
	
	short				secondGain;
	short				spillGain;
	
	short				secondSoft;
	short				spillSoft;

	char				enableKeyFlags;
	char				pad1;

	hsl8Color_t 		colors[MAX_EFFECT_COLORS];

// userParamSize must ALWAYS be the last field of this structure.  It doesn't have to
// be the last one written to the domain, but it must be the last one here.  userParamSize
// must always remain a long because people are using it to determine the position of the
// userParams which is glommed on the end.  POC.

	long				userParamSize;
// the userParams are just glommed onto the end of this structure at this position.  POC.

	};

typedef struct
	{
	long				cookie;
	long				rev;
	long				kfCurrent;
	long				kfSmooth;
	short				colorItem;
	short				quality;
	unsigned char		isReversed;
	unsigned char		ScalesDetached;
	} OMFIPvtGlobalInfo_t;
#pragma pack()

typedef struct
{
	aafRational_t	pos;
	aafRational_t	floor;
	aafRational_t	ceiling;
} AAFPvtPosExport;

typedef struct
{
	aafRational_t	top;
	aafRational_t	left;
	aafRational_t	bottom;
	aafRational_t	right;
} AAFPvtCropExport;

typedef struct
{
	aafRational_t	xScale;
	aafRational_t	yScale;
} AAFPvtScaleExport;

typedef struct
{
	aafInt16	secondGain;
	aafInt16	spillGain;	
	aafInt16	secondSoft;
	aafInt16	spillSoft;
} AAFPvtSpillExport;

typedef struct
{
	aafRational_t	top;
	aafRational_t	left;
	aafRational_t	bottom;
	aafRational_t	right;
	aafBool			Lvl2Xscale;
	aafBool			Lvl2Yscale;
	aafBool			Lvl2Xpos;
	aafBool			Lvl2Ypos;		
} AAFPvtBoundExport;

typedef struct
{
	aafInt32		nColors;
	hsl8Color_t 	colors[MAX_EFFECT_COLORS];	// JeffB: Not an AAF Type
} AAFPvtColorExport;

typedef struct
	{
	long				cookie;
	long				rev;
	long				kfCurrent;
	long				kfSmooth;
	short				colorItem;
	short				quality;
	unsigned char		isReversed;
	unsigned char		ScalesDetached;
	} AAFPvtGlobalInfo_t;

#define OMF2_EFFE_ALLOTHERS_GLOBAL_SLOT 1
#define OMF2_EFFE_ALLOTHERS_KEYFRAME_SLOT 2
#define OMF2_EFFE_ALLOTHERS_LEVEL_SLOT 3
#define OMF2_EFFE_PUBLIC_WITH_AVID_PRIVATE_DATA_GLOBAL_SLOT		128
#define OMF2_EFFE_PUBLIC_WITH_AVID_PRIVATE_DATA_KEYFRAME_SLOT	129
#define OMF2_EFFE_PUBLIC_WITH_AVID_PRIVATE_DATA_LEVEL_SLOT		130

#define OMFI_KF_COOKIE		0x526F626E
#define OMFI_KF_REVISION	1
#define OMFI_GLB_COOKIE		0x476C6F62
#define OMFI_GLB_REVISION	1

#define AAF_GLB_COOKIE		0x476C6F62
#define AAF_GLB_REVISION	1

#define ONE_FIXED16			0x00010000
#define ONE_FIXED30			0x40000000
