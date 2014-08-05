#include "sdk.h"
#include "../GDraw.h"

GFont::GFont(char* name, int height, int weight) :
	m_iHeight(height), m_iWeight(weight)
{
	strcpy(m_pszName, name);
}

GFont::~GFont()
{
//	if(!IsBadReadPtr((void*)m_pFont, 4))
	//	m_pFont->Release();

	//m_pFont = NULL;
}

bool GFont::Create()
{
	/*HRESULT hr = D3DXCreateFont(pDevice, m_iHeight, 0, m_iWeight, 0, 0, DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH  | FF_DONTCARE, TEXT(m_pszName),
		&m_pFont);
		*/
	//return SUCCEEDED(hr);
	return true;
}

void GFont::DrawText(int x, int y, GColor color, DWORD format, char* text, ...)
{
//	if(!m_pFont || IsBadReadPtr((void*)m_pFont, 4))
	//	return;
	
	char logbuf[100] = "";

	va_list va_alist;
	va_start (va_alist, text);
	_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
	va_end (va_alist);

	RECT rct;
	rct.left=x;
	if(format == DT_CENTER)
		rct.right = x;
	else
		rct.right=1000-10;
	rct.top=y-2;
	rct.bottom=rct.top+m_iHeight;

	g_pDraw->DrawTextFlags(x, y, color, format, logbuf);
	//m_pFont->DrawTextA(0, logbuf, (int)strlen(logbuf), &rct, format|DT_NOCLIP, color.Get());
}

int GFont::GetFontHeight()
{
	return g_pDraw->GetFontHeight();
}

int GFont::GetCharacterWidth(char character)
{
	/*HDC hdc = m_pFont->GetDC();
	SIZE size;
	GetTextExtentPoint32(hdc, "W", 1, &size);
	*/
	//return size.cx;
	textsize size;
	char keke[] = { character };
	g_pDraw->GetTextLength(keke, &size);
	return size.w;
}

int GFont::GetTextWidth(char* text)
{
	/*HDC hdc = m_pFont->GetDC();
	SIZE size;
	GetTextExtentPoint32(hdc, text, (int)strlen(text), &size);

	return size.cx;*/
	textsize size;
	g_pDraw->GetTextLength(text, &size);
	return size.w;
}

int GFont::GetTextHeight(char* text)
{
	/*HDC hdc = m_pFont->GetDC();
	SIZE size;
	GetTextExtentPoint32(hdc, text, (int)strlen(text), &size);

	return size.cx;*/
	textsize size;
	g_pDraw->GetTextLength(text, &size);
	return size.h;
}

