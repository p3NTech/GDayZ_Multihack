#ifndef _CHECKBOX_
#define _CHECKBOX_

#include "sdk.h"
#include "GConstruct.h"


class GCheckbox : public GConstruct
{
	public:
		GCheckbox(char* text, int x, int y, char* tooltip = 0);
		void DoModal();
	private:

	protected:

};

#endif