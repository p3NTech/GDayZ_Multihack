#include "sdk.h"


GButton::GButton(char* title, int x, int y, int w, int h, char* tooltip) : GConstruct(title, x, y, w, h, tooltip)
{
	m_function = 0;
}

void GButton::DoModal()
{
	if(window) {
		m_iX = window->x + m_x;
		m_iY = window->y + m_y;
	}
	
	char szDrawTitle[50] = "";
	strcpy(szDrawTitle, m_pszTitle);
	int iCharWidth = window->font->GetTextWidth(szDrawTitle);

	if(iCharWidth >= (m_iW)) 
	{
		int index = (int)strlen(szDrawTitle);
		for(; index > 0; index--)
		{
			if(window->font->GetTextWidth(&szDrawTitle[index]) > (m_iW))
				break;
		}

		strcpy(&szDrawTitle[index+7], "...");
	}


	pDraw->DrawFilledQuad(m_iX, m_iY, m_iW, m_iH, GColor(210, 210, 210));

	if(!this->OnSelect() || !window->active) {

	//left
	pDraw->DrawQuad(m_iX, m_iY+1, 1, m_iH-1, white, 1);

	//up
	pDraw->DrawQuad(m_iX, m_iY, m_iW, 1, white, 1);

	//right
	pDraw->DrawQuad(m_iX+m_iW-1, m_iY+1, 1, m_iH, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(m_iX+m_iW, m_iY, 1, m_iH+1, GColor(64, 64, 64), 1);

	//down
	pDraw->DrawQuad(m_iX+1, m_iY+m_iH-1, m_iW-1, 1, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(m_iX, m_iY+m_iH, m_iW, 1, GColor(64, 64, 64), 1);
	
	}

	if(this->m_bEnabled == false)
		return;

	if(window->active && this->OnSelect()) {

		//left
		pDraw->DrawQuad(m_iX+1, m_iY+1, 1, m_iH-1, GColor(128, 128, 128), 1);
		pDraw->DrawQuad(m_iX, m_iY, 1, m_iH, GColor(64, 64, 64), 1);

		//up
		pDraw->DrawQuad(m_iX+1, m_iY+1, m_iW-1, 1, GColor(128, 128, 128), 1);
		pDraw->DrawQuad(m_iX, m_iY, m_iW, 1, GColor(64, 64, 64), 1);

		//right
		pDraw->DrawQuad(m_iX+m_iW-1, m_iY+1, 1, m_iH-2, white, 1);

		//down
		pDraw->DrawQuad(m_iX+1, m_iY+m_iH-1, m_iW-1, 1, white, 1);
	}

	if(window->active && this->OnClick())
	{
		if(m_function) {
			typedef void (*function_t)(void* function);
			function_t function = (function_t)m_function;
			function(this);
		}
	}

	int add_height = window->font->GetTextHeight(szDrawTitle) / 2;
	window->font->DrawText(m_iX+(m_iW/2), m_iY+(m_iH/2) - add_height, black, DT_CENTER, szDrawTitle);
	//else if(this->OnMouseOver())
	//	boxColor = white;
	//else
	//	boxColor = green;

	//pDraw->DrawQuad(m_iX, m_iY, m_iW, m_iH, boxColor, 1);

	if(m_pTooltip) {
		if(window) {
			m_pTooltip->window = window;
			if(window->active) m_pTooltip->DoModal();
		}
		else
			m_pTooltip->DoModal();
	}
}