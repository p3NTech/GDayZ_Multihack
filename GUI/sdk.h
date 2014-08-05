#ifndef _SDK_
#define _SDK_

#include <windows.h>
#include <iostream>
#include <vector>
#include <list>

#include <dxgi.h>
//#include <dxgi1_2.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10math.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

#include "GWindow.h"
#include "GSliderControl.h"
#include "GConstruct.h"
#include "GEditbox.h"
#include "GProgressbar.h"
#include "GRadioButton.h"
#include "GGroupControl.h"
#include "../GColor.h"
#include "GLabel.h"
#include "GTooltip.h"
#include "GInput.h"
#include "GFont.h"
#include "GGDraw.h"
#include "GCheckbox.h"
#include "GButton.h"

//extern IDirect3DDevice9* pDevice;
extern GInput* pInput;
extern GGDraw* pDraw;
extern GFont* pMainFont;

const GColor black(0, 0, 0, 255);
const GColor white(255, 255, 255, 255);
const GColor red(255, 0, 0, 255);
const GColor green(0, 255, 0, 255);
const GColor blue(0, 0, 255, 255);
const GColor yellow(255, 255, 0, 255);
const GColor lightgrey(192, 192, 192, 255);
const GColor darkgrey(162, 162, 162, 255);

extern bool bHoldingMouse1;

extern int globalindex;

extern std::list<GInput*> stdInput;
extern std::list<GInput*>::iterator itInput;

extern std::list<GGWindow*> stdWindow;
extern std::list<GGWindow*>::iterator itWindow, itWindow2;


extern int windowW, windowH;
//extern GSliderControl* slider4;


#endif