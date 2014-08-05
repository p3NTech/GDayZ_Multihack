#ifndef _SLIDERCONTROL_
#define _SLIDERCONTROL_

#include "sdk.h"
#include "GConstruct.h"
#include "../GColor.h"

class GSliderControl : public GConstruct
{
	public:
		GSliderControl(int x, int y, int w, int h, float start, float end, bool vertical, bool showstatus = 1, bool round = 0, char* tooltip = 0);
		void DoModal();
		void SetStart(float start);
		void SetEnd(float end);
		float GetState();
		void SetState(float state);
		bool IsSliding();
GColor mainColor;
	private:
		float m_iStart;
		float m_iEnd;
		float m_iCurrentState;
		bool m_bSliding;
		bool m_bVertical;
		bool m_bRound;
		bool m_bShowStatus;
	protected:

};


#endif