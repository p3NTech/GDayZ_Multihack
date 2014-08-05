#include "sdk.h"


GRadioButton::GRadioButton(char* text, int x, int y, char* tooltip) : GConstruct(text, x, y, 10, 10, tooltip),
	m_iRadius(5)
{

}

void GRadioButton::DoModal()
{
	m_iK = m_iW + window->font->GetTextWidth(m_pszTitle) + 4;

	GColor circleColor = m_bEnabled?green:lightgrey;
	GColor textColor = m_bEnabled?white:lightgrey;
	GColor checkColor = textColor;

	;//pDraw->DrawCircle(m_iX+m_iRadius, m_iY+m_iRadius, m_iRadius, circleColor);
	window->font->DrawText(m_iX+m_iRadius*2+5, m_iY, textColor, 0, m_pszTitle);

	if(m_bChecked)
		pDraw->DrawFilledQuad(m_iX+4, m_iY+4, 2, 2, checkColor);

	if(this->OnSelect())
		m_bChecked = true;
	else if(this->OnMouseOver() && m_bChecked == false)
		;//pDraw->DrawCircle(m_iX+m_iRadius, m_iY+m_iRadius, m_iRadius, textColor);

	if(m_pTooltip && m_bEnabled)
		m_pTooltip->DoModal();
}