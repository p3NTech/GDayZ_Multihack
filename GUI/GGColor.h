#ifndef _COLOR_
#define _COLOR_

class GColor
{
	public:
		GColor(int r = 0, int g = 0, int b = 0, int a = 255);
		GColor &operator =(GColor& color);
		DWORD Get();
		int m_iR, m_iG, m_iB, m_iA;
	private:
		DWORD m_dwColor;
	protected:
		void Set();
};

#endif