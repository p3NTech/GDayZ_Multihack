#ifndef _EDITBOX_
#define _EDITBOX_

#include "sdk.h"
#include "GConstruct.h"
#include "GSliderControl.h"

class GEditbox : public GConstruct
{
	public:
		GEditbox(int x, int y, int w, int h,  bool singleline = true, char* tooltip = 0);
		~GEditbox();
		void DoModal();	
		bool OnActive();
		bool OnLock();
		void SetText(char* text);
		void GetText(char* text);
	private:
		char m_pszTitle[10000];
		bool m_bLock;
		int buf;
		int len;
		int s_x, s_y;
		bool m_bSingleline;
		GSliderControl* m_pSlider;
	protected:
};

#endif