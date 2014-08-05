#ifndef _GROUPCONTROL_
#define _GROUPCONTROL_

#include "GConstruct.h"

class GGroupControl : public GConstruct
{
	public:
		GGroupControl(char* text, int x, int y, int w, int h);
		void DoModal();

	private:

	protected:
};

#endif