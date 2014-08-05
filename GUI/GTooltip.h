#ifndef _TOOLTIP_
#define _TOOLTIP_


class GTooltip : public GConstruct
{
	public:
		GTooltip(char* name, int x, int y, int w, int h, int delay = 0);
		void DoModal();
	private:
		char m_pszTitle[100];
		DWORD m_dwTime;
		int m_iDelay;
		int m_iTargetX;
		int m_iTargetY;
		int m_iTargetW;
		int m_iTargetH;
		int iX, iY;
	protected:
};

#endif