// Card.h: interface for the CCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RCARDS_H__996169E4_5EEB_11D3_B413_A87510C10000__INCLUDED_)
#define AFX_RCARDS_H__996169E4_5EEB_11D3_B413_A87510C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifdef RCARDS_DLL
#ifdef RCARDS_EXPORTS
// #define EXTERNAL_RCARDS   __declspec(dllexport)
	#define RCARDS_API __declspec(dllexport)
#else
//	#define EXTERNAL_RCARDS   __declspec(dllimport)
	#define RCARDS_API __declspec(dllimport)
#endif  
#else
	#define RCARDS_API
#endif





#ifdef __cplusplus
extern "C" 
{
#endif
RCARDS_API BOOL RCards_InitCards(HINSTANCE a_hInstance);
RCARDS_API void RCards_DoneCards();

RCARDS_API BOOL Cards_GetSize(short* a_pDx, short* a_pDy);
RCARDS_API BOOL Cards_GetSize(short* a_pDx, short* a_pDy);
RCARDS_API BOOL Cards_DrawCard(HDC a_hDC, int a_iCard,
	int a_xDst,	int a_yDst,	int a_dxDst,
	int a_dyDst, int a_dx,
	int a_dy, BOOL a_bHilited);
RCARDS_API BOOL Cards_DrawCover(HDC a_hDC, HBITMAP a_hBmpCover, int a_xDst,
	int a_yDst,	int a_dxDst, int a_dyDst, int a_dx,	int a_dy);
RCARDS_API HBITMAP	Cards_GetBitmap(UINT a_idBmp);
#ifdef __cplusplus
}
#endif

#endif
