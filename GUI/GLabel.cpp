#include "sdk.h"


GLabel::GLabel(char* text, int x, int y, int w, int h, bool sunken, char* tooltip) : GConstruct(text, x, y, w, h, tooltip),
m_bSunken(sunken)
{
	strcpy(m_pszTitle, text);
}

void GLabel::DoModal()
{
	if(window) {
		m_iX = window->x + m_x;
		m_iY = window->y + m_y;
	}

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

	if(m_bSunken) {
		pDraw->DrawFilledQuad(m_iX-5, m_iY, m_iW, m_iH, GColor(210, 210, 210));
		pDraw->DrawQuad(m_iX-5, m_iY, m_iW, m_iH, white, 1);

		//left
		pDraw->DrawQuad(m_iX-5, m_iY, 1, m_iH-1, GColor(128, 128, 128), 1);

		//up
		pDraw->DrawQuad(m_iX-5, m_iY, m_iW, 1, GColor(128, 128, 128), 1);
	}				

	if(iTextIndex == 1) {
		int add_height = window->font->GetTextHeight(m_pszTitle) / 2;
		window->font->DrawText(m_iX, m_iY+m_iH/2-add_height, black,0, m_pszTitle);
	}
	else //multiline tooltip
	{
		int index = 0;
		int add_height = window->font->GetTextHeight(m_pszTitle) / 2;
		for(int i = iTextIndex-1; i >= 0; i--) {
			window->font->DrawText(m_iX, m_iY + m_iH / 2 - add_height + (index++*(add_height*2)), black, 0, szText[i]);
		}
	}

	if(m_pTooltip && this->m_bEnabled) {
	if(window) {
		m_pTooltip->window = window;
		if(window->active) m_pTooltip->DoModal();
	}
	else
		m_pTooltip->DoModal();
	}
}