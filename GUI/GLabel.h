#ifndef _LABEL_
#define _LABEL_

#include "sdk.h"
#include "GConstruct.h"

class GLabel : public GConstruct
{
	public:
		GLabel(char* text, int x, int y, int w, int h, bool sunken = false, char* tooltip = 0);
		void DoModal();
	private:
		char m_pszTitle[100];
		bool m_bSunken;
	protected:
};

#endif