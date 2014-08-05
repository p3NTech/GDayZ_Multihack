#include "sdk.h"



GTooltip::GTooltip(char* name, int x, int y, int w, int h, int delay) : GConstruct("", x, y, w, h, 0),
	m_iTargetX(x), m_iTargetY(y), m_iTargetW(w), m_iTargetH(h)
{
	if(name) strcpy(m_pszTitle, name);
	m_iDelay = 1500;
	m_dwTime = 0;
	iX = 0, iY = 0;
}

void GTooltip::DoModal()
{
	if(window) {
		m_iTargetX = window->x + m_x;
		m_iTargetY = window->y + m_y;
	}
	
	if(pInput->OnMouseInArea(m_iTargetX, m_iTargetY, m_iTargetW, m_iTargetH))
	{
		if(iX == 0 || iY == 0)
		{
			iX = pInput->m_pPoint->x;
			iY = pInput->m_pPoint->y;
		}
		
		if(m_dwTime == 0)
			m_dwTime = GetTickCount();

		if(iX != pInput->m_pPoint->x || iY != pInput->m_pPoint->y || pInput->OnMousePressing())
		{
			m_dwTime = GetTickCount(); 
			iX = 0; iY = 0;
			return;
		}

		if((m_dwTime+m_iDelay) < GetTickCount())
		{
			char szBuf[100] = {0};
			char szText[100][100] = {0};
			int iTextIndex = 0;
			int iBuf = 0;
			int iBiggerIndex = 0;

			strcpy(szBuf, m_pszTitle);

			for(int i = (int)strlen(szBuf); i >= 0; i--)
			{
				if(szBuf[i] == '\n' || i == 0)
				{
					strcpy(szText[iTextIndex], &szBuf[i?(i+1):i]);
					if((int)strlen(szText[iTextIndex]) > iBuf)
					{
						iBuf = (int)strlen(szText[iTextIndex]);
						iBiggerIndex = iTextIndex;
					}
					++iTextIndex;
					szBuf[i] = 0;
				}
			}

			if(iTextIndex == 1)
			{
				int iCharWidth = window->font->GetTextWidth(m_pszTitle) + 10;
				pDraw->DrawFilledQuad(pInput->m_pPoint->x-3, pInput->m_pPoint->y+20, iCharWidth, 16, GColor(255,255,230));
				pDraw->DrawQuad(pInput->m_pPoint->x-3, pInput->m_pPoint->y+20, iCharWidth, 16, black, 1);
				window->font->DrawText(pInput->m_pPoint->x+2, pInput->m_pPoint->y+24, black, 0, m_pszTitle);
			}
			else //multiline tooltip
			{
				int index = 0;
				int iBiggestWidth = window->font->GetTextWidth(szText[iBiggerIndex]);
				int iFontHeight = window->font->GetFontHeight();
				pDraw->DrawFilledQuad(pInput->m_pPoint->x-3, pInput->m_pPoint->y+20, iBiggestWidth+8, iFontHeight*iTextIndex+2, GColor(255,255,230));
				pDraw->DrawQuad(pInput->m_pPoint->x-3, pInput->m_pPoint->y+20, iBiggestWidth+8, iFontHeight*iTextIndex+2, black, 1);
				for(int i = iTextIndex-1; i >= 0; i--)
				{
					window->font->DrawText(pInput->m_pPoint->x+2, pInput->m_pPoint->y+24+(index++*iFontHeight), black,0,szText[i]);
				}
			}
		}
	}
	else
	{
		m_dwTime = 0;
		iX = 0;
		iY = 0;
	}
}