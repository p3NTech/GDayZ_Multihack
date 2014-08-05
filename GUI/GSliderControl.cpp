#include "sdk.h"

GSliderControl::GSliderControl(int x, int y, int w, int h, float start, float end, bool vertical,  bool showstatus, bool round, char* tooltip) : GConstruct("", x, y, w, h, tooltip),
	m_iStart(start), m_iEnd(end), m_iCurrentState(start), m_bVertical(vertical), m_bSliding(false), m_bShowStatus(showstatus), m_bRound(round)
{

	mainColor = GColor(0,255,0);
	m_iH = 4;
}

void GSliderControl::DoModal()
{
	if(window) {
		m_iX = window->x + m_x;
		m_iY = window->y + m_y;
	}

	GColor lineColor = m_bEnabled?mainColor:lightgrey;
	GColor textColor = m_bEnabled?white:lightgrey;

	if(!m_bVertical) {
		pDraw->DrawFilledQuad(m_iX, m_iY+1, m_iW, m_iH, GColor(210, 210, 210));
	
		//left
		pDraw->DrawQuad(m_iX, m_iY+1, 1, m_iH-2, GColor(128, 128, 128), 1);

		//up
		pDraw->DrawQuad(m_iX, m_iY+1, m_iW-2, 1, GColor(128, 128, 128), 1);
		pDraw->DrawQuad(m_iX+1, m_iY+2, m_iW-4, 1, GColor(64, 64, 64), 1);

		//right
		pDraw->DrawQuad(m_iX+m_iW-2, m_iY+1, 1, m_iH-1, white, 1);

		//down
		pDraw->DrawQuad(m_iX, m_iY+m_iH, m_iW-1, 1, white, 1);
	}
	else {
		pDraw->DrawFilledQuad(m_iX, m_iY+1, m_iH, m_iW, GColor(210, 210, 210));

		//left
		pDraw->DrawQuad(m_iX, m_iY+1, 1, m_iW-2, GColor(128, 128, 128), 1);
		pDraw->DrawQuad(m_iX+1, m_iY+2, 1, m_iW-4, GColor(64, 64, 64), 1);


		//up
		pDraw->DrawQuad(m_iX, m_iY+1, m_iH-2, 1, GColor(128, 128, 128), 1);

		//right
		pDraw->DrawQuad(m_iX+m_iH-1, m_iY+1, 1, m_iW-1, white, 1); 

		//down
		pDraw->DrawQuad(m_iX, m_iY+m_iW, m_iH-1, 1, white, 1);
	}

	float curx = float(m_bVertical?m_iY:m_iX);
	float curw = float(/*m_bVertical?m_iH:*/m_iW);


	float iRelativeState = curx+ ((curw * (m_iCurrentState-m_iStart)) / (m_iEnd-m_iStart)) ;

	int backx = m_iX;
	int backy = m_iY;
	int backw = m_iW;
	int backh = m_iH;


	if(m_bVertical)
	{
		m_iX -= 9;
		m_iY -= 5;
		m_iK = m_iH+17;
		m_iH = m_iW+10;
	}
	else
	{
		m_iX -= 5;
		m_iY -= 8;
		m_iH = 21;
		m_iK += 10;
	}

	if(window->active && this->OnSelect())
	{
		if(!m_bSliding)
			m_bSliding = true;
	}

	m_iX = backx;
	m_iY = backy;
	m_iK = backw;
	m_iH = backh;

	if(m_bSliding)
	{
		if(m_pInput->m_bMouse1)
		{
			iRelativeState = float(m_bVertical?m_pInput->m_pPoint->y:m_pInput->m_pPoint->x); 
			if(iRelativeState < curx) iRelativeState = curx;
			if(iRelativeState >= (curx+curw)) iRelativeState = curx + curw;
			m_iCurrentState =  ((iRelativeState-curx)*(m_iEnd-m_iStart))/curw + (m_iStart);
		}
		else
			m_bSliding = false;
	}

	int k = m_bVertical?(15):(m_iW/2);
	int l = m_bVertical?(m_iW/2):(15);

	if(m_bShowStatus) window->font->DrawText(m_iX+k,m_iY+l,black, m_bVertical?0:1, m_bRound?"%.0f":"%.2f", m_iCurrentState);

	//11x21

	if(m_bVertical) {
		pDraw->DrawFilledQuad(m_iX-9, (int)iRelativeState-5, 21, 11, GColor(210, 210, 210));

		//left
		pDraw->DrawQuad(m_iX-9, (int)iRelativeState-5, 1, 9, white, 1);

		//up
		pDraw->DrawQuad(m_iX-9, (int)iRelativeState-5, 19, 1, white, 1);

		//right
		pDraw->DrawQuad(m_iX+11, (int)iRelativeState-5, 1, 10, GColor(64, 64, 64), 1);
		pDraw->DrawQuad(m_iX+10, (int)iRelativeState-4, 1, 8, GColor(128, 128, 128), 1);

		//down
		pDraw->DrawQuad(m_iX-9, (int)iRelativeState+5, 20, 1, GColor(64, 64, 64), 1);
		pDraw->DrawQuad(m_iX-8, (int)iRelativeState+4, 18, 1, GColor(128, 128, 128), 1);
	}
	else {
		pDraw->DrawFilledQuad((int)iRelativeState-5, m_iY-8, 11, 21, GColor(210, 210, 210));
		
		//left
		pDraw->DrawQuad((int)iRelativeState-5, m_iY-8, 1, 20, white, 1);

		//up
		pDraw->DrawQuad((int)iRelativeState-5, m_iY-8, 10, 1, white, 1);

		//right
		pDraw->DrawQuad((int)iRelativeState-5+10, m_iY-8, 1, 20, GColor(64, 64, 64), 1);
		pDraw->DrawQuad((int)iRelativeState-5+9, m_iY-7, 1, 19, GColor(128, 128, 128), 1);

		//down
		pDraw->DrawQuad((int)iRelativeState-5, m_iY-8+20, 11, 1, GColor(64, 64, 64), 1);
		pDraw->DrawQuad((int)iRelativeState-4, m_iY-8+19, 9, 1, GColor(128, 128, 128), 1);
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

void GSliderControl::SetStart(float start)
{
	m_iStart = start;
}

void GSliderControl::SetEnd(float end)
{
	m_iEnd = end;
}

float GSliderControl::GetState()
{
	return m_iCurrentState;
}

void GSliderControl::SetState(float state)
{
	m_iCurrentState = state;
}

bool GSliderControl::IsSliding()
{
	return m_bSliding;
}