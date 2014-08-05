#include "sdk.h"


GCheckbox::GCheckbox(char* text, int x, int y, char* tooltip) : GConstruct(text, x, y, 13, 13, tooltip)
{
	m_function = 0;
}

void GCheckbox::DoModal()
{
	if(window) {
		m_iX = window->x + m_x;
		m_iY = window->y + m_y;
	}

	m_iK = m_iW + window->font->GetTextWidth(m_pszTitle) + 5;
	GColor boxColor = m_bEnabled?green:lightgrey;

	pDraw->DrawFilledQuad(m_iX, m_iY, m_iW, m_iH, white);

	//left
	pDraw->DrawQuad(m_iX, m_iY, 1, m_iH-1, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(m_iX+1, m_iY+1, 1, m_iH-3, GColor(64, 64, 64), 1);

	//up
	pDraw->DrawQuad(m_iX, m_iY, m_iW-1, 1, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(m_iX+1, m_iY+1, m_iW-3, 1, GColor(64, 64, 64), 1);

	//right
	pDraw->DrawQuad(m_iX+m_iW-2, m_iY+1, 1, m_iH-2,GColor(210, 210, 210), 1);

	//down
	pDraw->DrawQuad(m_iX+1, m_iY+m_iH-2, m_iW-2, 1, GColor(210, 210, 210), 1);

	int add_height = window->font->GetTextHeight(m_pszTitle) / 2;
	window->font->DrawText(m_iX+m_iW+5, m_iY+m_iW/2-add_height, black, 0, m_pszTitle);

	if(m_bChecked) {

		pDraw->DrawFilledQuad(m_iX+3, m_iY+5, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+3, m_iY+6, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+3, m_iY+7, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+4, m_iY+6, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+4, m_iY+7, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+4, m_iY+8, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+5, m_iY+7, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+5, m_iY+8, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+5, m_iY+9, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+6, m_iY+8, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+6, m_iY+7, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+6, m_iY+6, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+7, m_iY+7, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+7, m_iY+6, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+7, m_iY+5, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+8, m_iY+6, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+8, m_iY+5, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+8, m_iY+4, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+9, m_iY+5, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+9, m_iY+4, 1, 1, black);
		pDraw->DrawFilledQuad(m_iX+9, m_iY+3, 1, 1, black);
		
	}

	if(window->active && this->OnClick()) {
		m_bChecked = !m_bChecked;

		if(m_function) {
			typedef void (*function_t)(void* function);
			function_t function = (function_t)m_function;
			function(this);
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
