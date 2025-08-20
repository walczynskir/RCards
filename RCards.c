// RCards.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <rcommon/rstddef.h>
#include "RCards.h"
#include <tchar.h>

static HBITMAP s_arrBitmap[53];
static HINSTANCE s_hInstance = NULL;
static const int c_iMaskCard = 52;
static BOOL s_bInitialized = FALSE;

static BOOL DrawAnyCard(HDC a_hDC, HBITMAP a_hBmp,
	int a_xDst,	int a_yDst,	int a_dxDst,
	int a_dyDst, int a_dx,
	int a_dy, BOOL a_bHilited);

static const cc_iMaskBmp = 69;




// ---------------------------------------------------------
// Entry point, only for dynamic library. Only for remembering instance handle which will be used later. 
//
BOOL
APIENTRY DllMain(
	HANDLE a_hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		s_hInstance = (HINSTANCE)a_hModule;
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}



// ---------------------------------------------------------
// Inicjacja modu³u kart
//
BOOL
RCards_InitCards(HINSTANCE a_hInstance)
{

	// check if properly called. Should be called with NULL if dynamic library
#ifdef RCARDS_DLL
	ASSERT(s_hInstance != NULL);
	ASSERT(a_hInstance == NULL);
#else
	ASSERT(a_hInstance != NULL);
	s_hInstance = a_hInstance;
#endif
	
	// decoding of cards in resources
	// TODO: check, why decoding is needed
	short l_arrDecode[] =  
	{ 
	  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13,  1,  
	 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 14, 
	 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 40, 
	 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 27 
	} ;
	int l_iPos ;

	if (s_bInitialized)
	{
		return TRUE;
	}
	memset(s_arrBitmap, 0, sizeof(s_arrBitmap));
	for (l_iPos = 1; l_iPos <= 52; l_iPos++)
	{
		s_arrBitmap[l_iPos - 1] = LoadBitmap(s_hInstance, MAKEINTRESOURCE(l_arrDecode[l_iPos - 1]));
		if (s_arrBitmap[l_iPos - 1] == NULL)
		{
			return FALSE;
		}
	}

	s_arrBitmap[c_iMaskCard] = LoadBitmap(s_hInstance, MAKEINTRESOURCE(cc_iMaskBmp));
	if (s_arrBitmap[c_iMaskCard] == NULL)
	{
		return FALSE;
	}
	s_bInitialized = TRUE;
	return TRUE;
}


// ---------------------------------------------------------
// Pobranie rozmiarów kart
//
BOOL
Cards_GetSize(
	short* a_pDx, 
	short* a_pDy
	)
{
	BITMAP l_bitmap;
	if (s_arrBitmap[0] == NULL)
	{
		return FALSE;
	}

	if (!GetObject(s_arrBitmap[0], sizeof(BITMAP), &l_bitmap))
	{
		return FALSE;
	}

	*a_pDx = (short)l_bitmap.bmWidth;	
	*a_pDy = (short)l_bitmap.bmHeight;	
	return TRUE;
}


// ---------------------------------------------------------
// Wyczyszczenie modu³u kart
//
void
RCards_DoneCards()
{
	int l_iAt;
	if (!s_bInitialized)
	{
		return;
	}
	for (l_iAt = 0; l_iAt < sizeof(s_arrBitmap) / sizeof(s_arrBitmap[0]); l_iAt++)
	{
		HBITMAP l_hBitmap = s_arrBitmap[l_iAt];
		if (l_hBitmap != NULL)
		{
			DeleteObject(l_hBitmap);
		}
	}
	s_bInitialized = FALSE;
}


// ---------------------------------------------------------
// Narysowanie karty wraz z rozszerzeniem lub jej 
// skurczeniem na podany rozmiar.
//
BOOL	//WY TRUE - powiod³o siê
Cards_DrawCard(
	HDC a_hDC,			//WE device kontekst
	int a_iCard,		//WE numer karty
	int a_xDst,			//WE po³o¿enie docelowe
	int a_yDst,			//WE	---"-----
	int a_dxDst,		//WE po³o¿enie x od którego zacz¹æ rysowaæ bitmapê
	int a_dyDst,		//WE po³o¿enie y od którego zacz¹æ rysowaæ bitmapê
	int a_dx,			//WE szerokoœæ Ÿród³a oczekiwana (ca³ego)
	int a_dy,			//WE wysokoœæ Ÿród³a oczekiwana (ca³ego)
	BOOL a_bHilited		//WE czy w trybie podœwietlonym
	)
{
	return DrawAnyCard(a_hDC,	s_arrBitmap[a_iCard],
		a_xDst,	a_yDst,	a_dxDst, a_dyDst,
		a_dx, a_dy,	a_bHilited);
}


// ---------------------------------------------------------
// Narysowanie karty wraz z rozszerzeniem lub jej 
// skurczeniem na podany rozmiar.
//
BOOL	//WY TRUE - powiod³o siê
Cards_DrawCover(
	HDC a_hDC,			//WE device kontekst
	HBITMAP a_hBmp,     //WE cover bitmap
	int a_xDst,			//WE po³o¿enie docelowe
	int a_yDst,			//WE	---"-----
	int a_dxDst,		//WE szerokoœæ docelowa
	int a_dyDst,		//WE wysokoœæ docelowa
	int a_dx,			//WE szerokoœæ Ÿród³a oczekiwana (ca³ego)
	int a_dy			//WE wysokoœæ Ÿród³a oczekiwana (ca³ego)
	)
{
	BITMAP l_bitmap;
	BITMAP l_bitmapMask;
	HBITMAP l_hBmpMask;
	HDC l_hdcCompat;
	if (!s_bInitialized)
	{
		return FALSE;
	}

	if (GetObject(a_hBmp, sizeof(BITMAP), &l_bitmap) == 0)
	{
		return FALSE;
	}

	l_hBmpMask = s_arrBitmap[c_iMaskCard];
	if (GetObject(l_hBmpMask, sizeof(BITMAP), &l_bitmapMask) == 0)
	{
		return FALSE;
	}

	l_hdcCompat = CreateCompatibleDC(a_hDC);

	SelectObject(l_hdcCompat, l_hBmpMask);
	if (!StretchBlt(
		a_hDC,
		a_xDst, 
		a_yDst, 
		a_dxDst, 
		a_dyDst, 
		l_hdcCompat, 
		0, 
		0, 
		(a_dxDst * l_bitmapMask.bmWidth) / a_dx, 
		(a_dyDst * l_bitmapMask.bmHeight) / a_dy, 
		MERGEPAINT))
	{
		DeleteDC(l_hdcCompat);
		return FALSE;
	}

	SelectObject(l_hdcCompat, a_hBmp);
	if (!StretchBlt(
		a_hDC,
		a_xDst, 
		a_yDst, 
		a_dxDst, 
		a_dyDst, 
		l_hdcCompat, 
		0, 
		0, 
		(a_dxDst * l_bitmap.bmWidth) / a_dx, 
		(a_dyDst * l_bitmap.bmHeight) / a_dy, 
		SRCAND))
	{
		DeleteDC(l_hdcCompat);
		return FALSE;
	}
	DeleteDC(l_hdcCompat);
	return TRUE;
}


// ---------------------------------------------------------
// Narysowanie karty wraz z rozszerzeniem lub jej 
// skurczeniem na podany rozmiar.
//
BOOL	//WY TRUE - powiod³o siê
DrawAnyCard(
	HDC a_hDC,			//WE device kontekst
	HBITMAP a_hBmp,		//WE bitmapa karty rysowana
	int a_xDst,			//WE po³o¿enie docelowe
	int a_yDst,			//WE	---"-----
	int a_dxDst,		//WE po³o¿enie x od którego zacz¹æ rysowaæ bitmapê
	int a_dyDst,		//WE po³o¿enie y od którego zacz¹æ rysowaæ bitmapê
	int a_dx,			//WE szerokoœæ Ÿród³a oczekiwana (ca³ego)
	int a_dy,			//WE wysokoœæ Ÿród³a oczekiwana (ca³ego)
	BOOL a_bHilited		//WE czy w trybie podœwietlonym
	)
{
	DWORD l_dwRopMask;
	DWORD l_dwRopCard;
	BITMAP l_bitmap;
	HBITMAP l_hBmpMask;
	HDC l_hdcCompat;
	if (!s_bInitialized)
	{
		return FALSE;
	}

	if (a_bHilited)
	{
		l_dwRopMask = SRCAND;
		l_dwRopCard = MERGEPAINT;
	}
	else
	{
		l_dwRopMask = MERGEPAINT;
		l_dwRopCard = SRCAND;
	}

	if (GetObject(a_hBmp, sizeof(BITMAP), &l_bitmap) == 0)
	{
		return FALSE;
	}

	l_hBmpMask = s_arrBitmap[c_iMaskCard];

	l_hdcCompat = CreateCompatibleDC(a_hDC);

	SelectObject(l_hdcCompat, l_hBmpMask);
	if (!StretchBlt(
		a_hDC,
		a_xDst, 
		a_yDst, 
		a_dxDst, 
		a_dyDst, 
		l_hdcCompat, 
		0, 
		0, 
		(a_dxDst * l_bitmap.bmWidth) / a_dx, 
		(a_dyDst * l_bitmap.bmHeight) / a_dy, 
		l_dwRopMask))
	{
		DeleteDC(l_hdcCompat);
		return FALSE;
	}

	SelectObject(l_hdcCompat, a_hBmp);
	if (!StretchBlt(
		a_hDC,
		a_xDst, 
		a_yDst, 
		a_dxDst, 
		a_dyDst, 
		l_hdcCompat, 
		0, 
		0, 
		(a_dxDst * l_bitmap.bmWidth) / a_dx, 
		(a_dyDst * l_bitmap.bmHeight) / a_dy, 
		l_dwRopCard))
	{
		DeleteDC(l_hdcCompat);
		return FALSE;
	}
	DeleteDC(l_hdcCompat);
	return TRUE;
}


// ---------------------------------------------------------
// Za³adowanie bitmapy o podanym identyfikatorze
//
HBITMAP		//WY uchwyt bitmapy
Cards_GetBitmap(
	UINT a_idBmp	//WE id bitmapy
	)
{
	return LoadBitmap(s_hInstance, MAKEINTRESOURCE(a_idBmp));
}


