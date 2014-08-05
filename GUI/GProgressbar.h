#ifndef _PROGRESSBAR_
#define _PROGRESSBAR_

#include "sdk.h"
#include "GConstruct.h"

class GProgressbar : public GConstruct
{
	public:
		GProgressbar(int x, int y, int w, int h, int percentage = 100, char* tooltip = 0);
		void DoModal();
		void Update(int percentage);
		void Reset();
	private:
		int m_iPercentage;
		int m_iCurrentPercentage;
	protected:
};

#endif