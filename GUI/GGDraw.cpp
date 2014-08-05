#include "sdk.h"
#include "../GDraw.h"

GGDraw::GGDraw()
{

}

//void GGDraw::DrawFilledQuad(int x, int y, int w, int h, GColor color)
//{
//	D3DRECT box = {	x, y, x+w, y+h	};
//	pDevice->Clear(1, &box, D3DCLEAR_TARGET, color.Get(), 0, 0);
//}

struct QuadVertex
{
	float x,y,z,rhw;
	DWORD dwColor;
};


void GGDraw::DrawFilledQuadGradient(int x, int y, int w, int h, GColor color1, GColor color2)
{
	/*const DWORD D3D_FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
	DWORD colore1 = color1.Get();
	DWORD colore2 = color2.Get();

	QuadVertex qV[4] =	
	{
		{ (float)x    , (float)(y+h), 0.0f, 0.0f, colore1},
		{ (float)x    , (float)y    , 0.0f, 0.0f, colore1},
		{ (float)(x+w), (float)(y+h), 0.0f, 0.0f, colore2},
		{ (float)(x+w), (float)y    , 0.0f, 0.0f, colore2}
	};
 
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	pDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );
 
	pDevice->SetFVF(D3D_FVF);
	pDevice->SetTexture(0, NULL);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,qV,sizeof(QuadVertex));*/
	g_pDraw->DrawFilledQuad(x, y, w, h, color1);

}

void GGDraw::DrawFilledQuad( int x, int y, int w, int h, GColor color)
{
	/*const DWORD D3D_FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
	DWORD colore = color.Get();
	QuadVertex qV[4] =	
	{
		{ (float)x    , (float)(y+h), 0.0f, 0.0f, colore},
		{ (float)x    , (float)y    , 0.0f, 0.0f, colore},
		{ (float)(x+w), (float)(y+h), 0.0f, 0.0f, colore},
		{ (float)(x+w), (float)y    , 0.0f, 0.0f, colore}
	};
	//allow for translucency
 
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	pDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );
 
	pDevice->SetFVF(D3D_FVF);
	pDevice->SetTexture(0, NULL);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,qV,sizeof(QuadVertex));*/
	g_pDraw->DrawFilledQuad(x, y, w, h, color);
}

void GGDraw::DrawQuad(int x, int y, int w, int h, GColor color, int thickness)
{
	/*D3DRECT oben =		{ x,	y,		x+w,		   y+thickness		};
	D3DRECT unten =		{ x,	y+h,	x+w,		   y+h+thickness	};
	D3DRECT links =		{ x,	y,		x+thickness,   y+h				};
	D3DRECT rechts =	{ x+w,	y,		x+w+thickness, y+h+thickness	};

	pDevice->Clear(1, &oben, D3DCLEAR_TARGET, color.Get(), 0, 0);
	pDevice->Clear(1, &links, D3DCLEAR_TARGET, color.Get(), 0, 0);
	pDevice->Clear(1, &rechts, D3DCLEAR_TARGET, color.Get(), 0, 0);
	pDevice->Clear(1, &unten, D3DCLEAR_TARGET, color.Get(), 0, 0);	*/
	g_pDraw->DrawQuad(x, y, w, h, thickness, color);
}

void GGDraw::DrawCircle(int x, int y, int radius, GColor color)
{
	g_pDraw->DrawCircle(x, y, radius, color);
}