#ifndef _FONT_
#define _FONT_

#include "sdk.h"
class GColor;

class GFont
{
	public:
		GFont(char* name, int height, int weight);
		~GFont();
		bool Create();
		void DrawText(int x, int y, GColor color, DWORD format, char* text, ...);
		int GetCharacterWidth(char character = 'A');
		int GetTextWidth(char* text);
		int GetTextHeight(char* text);
		int GetFontHeight();
	private:
		char m_pszName[32];
		int m_iHeight;
		int m_iWeight;
//		ID3DXFont* m_pFont;
	protected:
};


#endif