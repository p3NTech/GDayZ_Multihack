#include "sdk.h"


GProgressbar::GProgressbar(int x, int y, int w, int h, int percentage, char* tooltip) : GConstruct("", x, y, w, h, tooltip),
	m_iPercentage(percentage), m_iCurrentPercentage(percentage)
{
}


void GProgressbar::DoModal()
{
	if(window) {
		m_iX = window->x + m_x;
		m_iY = window->y + m_y;
	}
	
	GColor boxColor = m_bEnabled?green:lightgrey;

	int iPercentage = (m_iW * m_iCurrentPercentage) / 100;

	if(iPercentage > m_iW)
		return;

	pDraw->DrawFilledQuad(m_iX, m_iY, m_iW, m_iH, GColor(210, 210, 210));
	pDraw->DrawQuad(m_iX, m_iY, m_iW, m_iH, GColor(128, 128, 128), 1);

	//right
	pDraw->DrawQuad(m_iX+m_iW-1, m_iY, 1, m_iH, white, 1);

	//down
	pDraw->DrawQuad(m_iX, m_iY+m_iH-1, m_iW, 1, white, 1);


	GColor color = black;
	if(m_iCurrentPercentage >= 43) color = white;

	pDraw->DrawFilledQuad(m_iX+2, m_iY+2, iPercentage, m_iH-3, GColor(10, 36, 104));

	int add_width = window->font->GetTextWidth("100") / 2;
	int add_height = window->font->GetTextHeight("100") / 2;
	window->font->DrawText(m_iX + (m_iW / 2) - add_width, m_iY + (m_iH / 2) - add_height -1, color, 1, "%d%%", m_iCurrentPercentage);

	if(m_pTooltip && this->m_bEnabled) {
		if(window) {
			m_pTooltip->window = window;
			if(window->active) m_pTooltip->DoModal();
		}
		else
			m_pTooltip->DoModal();
	}
}

void GProgressbar::Update(int percentage)
{
	m_iCurrentPercentage = percentage;
}

void GProgressbar::Reset()
{
	m_iCurrentPercentage = m_iPercentage;
}