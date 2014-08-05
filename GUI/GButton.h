#ifndef _BUTTON_
#define _BUTTON_

class GInput;
class GTooltip;
struct GGWindow;

#include "GConstruct.h"
#include "GWindow.h"

class GButton : public GConstruct
{
	public:
		GButton(char* title, int x, int y, int w, int h, char* tooltip = NULL);
		void DoModal();
	private:
	protected:
};

#endif
