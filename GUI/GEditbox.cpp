#include "sdk.h"


GEditbox::GEditbox(int x, int y, int w, int h, bool singleline, char* tooltip) : GConstruct("", x, y, w, h, tooltip),
	m_bLock(false), s_x(0), s_y(0), m_bSingleline(singleline)
{
	buf = 0;
	len = 0;
	m_x = x;
	m_y = y;

	m_pSlider = new GSliderControl(x+w, y, 1, h-2, 0, 1, true, false);
}

GEditbox::~GEditbox()
{
	delete m_pSlider;
}


void GEditbox::DoModal()
{
	if(window) {
		m_iX = window->x + m_x;
		m_iY = window->y + m_y;
	}

	pDraw->DrawFilledQuad(m_iX, m_iY, m_iW, m_iH, white);

	//up
	pDraw->DrawQuad(m_iX, m_iY, m_iW-1, 1, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(m_iX+1, m_iY+1, m_iW-3, 1, GColor(64, 64, 64), 1);

	//left
	pDraw->DrawQuad(m_iX, m_iY, 1, m_iH-1, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(m_iX+1, m_iY+1, 1, m_iH-3, GColor(64, 64, 64), 1);

	//down
	pDraw->DrawQuad(m_iX, m_iY+m_iH-1, m_iW-1, 1, white, 1);
	pDraw->DrawQuad(m_iX+1, m_iY+m_iH-2, m_iW-3, 1, GColor(210, 210, 210), 1);

	//right
	pDraw->DrawQuad(m_iX+m_iW-1, m_iY, 1, m_iH-1, white, 1);
	pDraw->DrawQuad(m_iX+m_iW-2, m_iY+1, 1, m_iH-2, GColor(210, 210, 210), 1);

	window->input->SetActive(m_bActive);
	int textsize = window->font->GetTextWidth(window->input->GetUserInput());

	char* text = window->input->GetUserInput();

	char buf[400] = "";
	if(textsize >= (m_iW-7)) {
		for(int i = 0; i < strlen(text); i++) {
			textsize = window->font->GetTextWidth(&text[i]);
			if(textsize < (m_iW-7)) {
				strcpy(buf, &text[i]);
				break;
			}
		}
	}
	else {
		strcpy(buf, text);
	}
	int add_height = window->font->GetTextHeight(buf) / 2;
	window->font->DrawText(m_iX + 5, m_iY + m_iW / 2 - add_height, black, DT_LEFT, buf);

	if(m_bActive) {
		pDraw->DrawFilledQuad(m_iX+textsize+5, m_iY+4, 1, window->font->GetFontHeight()-1, black);
	}

	//GColor boxColor = m_bEnabled?green:lightgrey;
	//GColor textColor = m_bEnabled?white:lightgrey;

	//m_pSlider->mainColor = boxColor;
	//
	//pDraw->DrawQuad(m_iX, m_iY, m_iW, m_iH, boxColor, 1);

	//m_pInput->SetLock(!m_bActive);

	//if(m_pSlider->IsSliding()) this->m_bActive = true;

	//char szBuf[10000] = {0};
	//char szText[100][100] = {0};
	//int iTextIndex = 0;

	//strcpy(szBuf, m_pInput->GetUserInput());

	//for(int i = (int)strlen(szBuf)-1; i >= 0; i--)
	//{
	//	if(szBuf[i] == '\n' || i == 0)
	//	{
	//		strcpy(szText[iTextIndex++], &szBuf[i?(i+1):i]);
	//		szBuf[i] = 0;
	//	}
	//}

	////umdrehen
	//char szText2[100][100] = {0};
	//memcpy(&szText2, &szText, sizeof(szText));
	//memset(&szText, 0, sizeof(szText));

	//for(int i = 0; i < iTextIndex; i++)
	//{
	//	strcpy(szText[i], szText2[iTextIndex-i-1]);
	//}


	//m_pInput->SetActive(m_bActive);

	//int bla = ((m_iH) / window->font->GetFontHeight());

	//int index = 0;
	//for(int i = (int)m_pSlider->GetState(); i < iTextIndex; i++)
	//{
	//	
	//	m_pSlider->SetEnd((float)(iTextIndex-bla));
	//	int iTextWidth = window->font->GetTextWidth(szText[i]);

	//	if(iTextWidth >= (m_iW-10)) {
	//		char save = m_pInput->m_pszUserInput[strlen(m_pInput->m_pszUserInput)-1]; 
	//		m_pInput->m_pszUserInput[strlen(m_pInput->m_pszUserInput)-1]= '\n';
	//		if(save != 0x20) m_pInput->m_pszUserInput[strlen(m_pInput->m_pszUserInput)] = save;
	//	}//m_pInput->SetLock(true);

	//	if(window->font->GetFontHeight()*index >= (m_iH-window->font->GetFontHeight()));//m_pInput->SetLock(true);
	//	else
	//	{
	//		window->font->DrawText(m_iX+3, m_iY+4+(index++*window->font->GetFontHeight()), textColor,0,szText[i]);
	//	}
	//}

	//if(buf != (iTextIndex-bla))
	//{
	//	buf = iTextIndex-bla;
	//	if(buf >= 0)
	//	m_pSlider->SetState((float)buf);
	//}

	//if(m_bActive)
	//{
	//	m_pSlider->mainColor = white;
	//	pDraw->DrawQuad(m_iX, m_iY, m_iW, m_iH, white, 1);
	//}

	//if(iTextIndex-(bla) > 0)
	//{
	//	m_pSlider->DoModal();

	//	if(len != strlen(szText[iTextIndex-1]))
	//	{
	//		len = (int)strlen(szText[iTextIndex-1]);
	//		m_pSlider->SetState((float)buf);
	//	}
	//}

	if(this->OnClick() && m_bEnabled)
		m_bActive = true;
	else if(!this->OnMouseOver() && m_pInput->OnMousePressed())
		m_bActive = false;

	if(m_pTooltip && this->m_bEnabled) {
	if(window) {
		m_pTooltip->window = window;
		if(window->active) m_pTooltip->DoModal();
	}
	else
		m_pTooltip->DoModal();
	}
}

bool GEditbox::OnLock()
{
	return m_bLock;
}

void GEditbox::SetText(char* text)
{
	strcpy(m_pInput->GetUserInput(), text);
}
void GEditbox::GetText(char* text)
{
	strcpy(text, m_pInput->GetUserInput());
}
