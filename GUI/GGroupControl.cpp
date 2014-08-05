#include "sdk.h"


GGroupControl::GGroupControl(char* text, int x, int y, int w, int h) : GConstruct(text, x, y, w, h, 0)
{
}

void GGroupControl::DoModal()
{
	if(window) {
		m_iX = window->x + m_x;
		m_iY = window->y + m_y;
	}

	GColor boxColor = m_bEnabled?green:lightgrey;
	GColor textColor = m_bEnabled?white:lightgrey;

	//pDraw->DrawQuad(m_iX, m_iY, m_iW, m_iH, black, 1);

	//left
	pDraw->DrawQuad(m_iX, m_iY, 1, m_iH, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(m_iX+1, m_iY+1, 1, m_iH-2, white, 1);

	//down
	pDraw->DrawQuad(m_iX, m_iY+m_iH, m_iW, 1, white, 1);
	pDraw->DrawQuad(m_iX+1, m_iY+m_iH-1, m_iW-1, 1, GColor(128, 128, 128), 1);

	//right
	pDraw->DrawQuad(m_iX+m_iW, m_iY, 1, m_iH+1, white, 1);
	pDraw->DrawQuad(m_iX+m_iW-1, m_iY, 1, m_iH-1, GColor(128, 128, 128), 1);


	int add_height = window->font->GetTextHeight(m_pszTitle) / 2;
	window->font->DrawText(m_iX + 20, m_iY - add_height, black, 0, m_pszTitle);

	int iTextWidth = window->font->GetTextWidth(m_pszTitle);
	pDraw->DrawFilledQuad(m_iX, m_iY, 15, 1, GColor(128, 128, 128));
	pDraw->DrawFilledQuad(m_iX+1, m_iY+1, 14, 1, white);
	//pDraw->DrawFilledQuad(m_iX, m_iY, m_iW, 1, yellow);
	pDraw->DrawFilledQuad(m_iX+iTextWidth+25, m_iY, m_iW-iTextWidth-25, 1, GColor(128, 128, 128));
	pDraw->DrawFilledQuad(m_iX+iTextWidth+25, m_iY+1, m_iW-iTextWidth-26, 1, white);
}