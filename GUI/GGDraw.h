#ifndef _DRAW_
#define _DRAW_

#include "sdk.h"

class GGDraw
{
	public:
		GGDraw();
		void DrawFilledQuad(int x, int y, int w, int h, GColor color);
		void DrawFilledQuadGradient(int x, int y, int w, int h, GColor color1, GColor color2);
		void DrawQuad(int x, int y, int w, int h, GColor color, int thickness);
		void DrawCircle(int x, int y, int radius, GColor color);
	private:
	protected:
};


#endif