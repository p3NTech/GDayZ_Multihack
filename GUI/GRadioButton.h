#ifndef _RADIOBUTTON_
#define _RADIOBUTTON_

#include "sdk.h"
#include "GConstruct.h"

class GRadioButton : public GConstruct
{
	public:
		GRadioButton(char* text, int x, int y, char* tooltip = 0);
		void DoModal();
	private:
		int m_iRadius;
	protected:
};

#endif