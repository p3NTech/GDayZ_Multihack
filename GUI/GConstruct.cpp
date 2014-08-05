#include "sdk.h"


GConstruct::GConstruct(char* title, int x, int y, int w, int h, char* tooltip) :
m_iX(x), m_iY(y), m_iW(w), m_iH(h), m_bEnabled(true), m_bChecked(false), m_iK(w), m_bActive(false)
{
	m_pTooltip = NULL;
	strcpy(m_pszTitle, title);
	m_function = 0;
	window = 0;

	if(tooltip) m_pTooltip = new GTooltip(tooltip, x, y, w, h);
	m_pInput = new GInput();
	stdInput.push_back(m_pInput);

	m_x = x;
	m_y = y;
}

GConstruct::~GConstruct()
{
	if(m_pTooltip)
		delete m_pTooltip;

	delete m_pInput;
}

void GConstruct::Enable(bool status)
{
	m_bEnabled = status;
}

char* GConstruct::GetText()
{
	//strcpy(text, m_pszTitle);
	return m_pszTitle;
}

void GConstruct::SetText(char* text)
{
	strcpy(m_pszTitle, text);
}

bool GConstruct::GetCheck()
{
	return m_bChecked;
}

void GConstruct::SetCheck(bool status)
{
	m_bChecked = status;
}

bool GConstruct::OnActive()
{
	return m_bActive;
}
void GConstruct::SetActive(bool status)
{
	m_bActive = status;
}

bool GConstruct::OnMouseOver()
{
	if(m_bEnabled == false) return false;

	if(m_pInput->OnMouseInArea(m_iX, m_iY, m_iK, m_iH))
	{
		//pDraw->DrawFilledQuad(m_iX, m_iY, m_iK, m_iH, white);
		return true;
	}
	return false;
}

bool GConstruct::OnSelect()
{
	if(m_bEnabled == false) return false;

	if(this->OnMouseOver())
	{
		if(m_pInput->OnMousePressing() && !m_bPressingCheck)
			return true;

		if(!m_pInput->OnMousePressing())
			m_bPressingCheck = false;
	}
	else
		m_bPressingCheck = m_pInput->OnMousePressing();

	return false;
}

bool GConstruct::OnSelectW()
{
	if(m_bEnabled == false) return false;

	if(this->OnMouseOver())
	{
		if(m_pInput->OnMousePressing() && !m_bPressingCheck)
			return true;

		if(!m_pInput->OnMousePressing())
			m_bPressingCheck = false;
	}

	return false;
}

bool GConstruct::OnClick()
{
	if(m_bEnabled == false) return false;

	if(this->OnMouseOver())
	{
		if(m_pInput->OnMousePressed() && !m_bClickCheck)
			return true;

		if(!m_pInput->OnMousePressing())
			m_bClickCheck = false;
	}
	else
		m_bClickCheck = true;

	return false;
}