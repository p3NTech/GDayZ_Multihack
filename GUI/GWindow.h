#ifndef _WINDOW_
#define _WINDOW_

#include "GInput.h"
#include "GButton.h"
#include "GLabel.h"
#include "GSliderControl.h"
#include "GCheckbox.h"
#include "GFont.h"
#include "GGroupControl.h"
#include "GProgressbar.h"
#include "GEditbox.h"

struct GGWindow
{
	int index; 

	int x;
	int y;
	int width;
	int height;

	bool active;
	int order;

	bool minimized;
	bool maximized;

	bool hasTitlebar;
	bool hasMinimized;
	bool hasMaximized;
	bool hasExit;

	bool canResize;
	bool canMove;

	bool topmost;
	bool moving;
	bool resizing;

	bool hasStatusbar;
	char statusbartext[256];

	bool m_bClickCheck;
	bool m_bPressingCheck;

	char title[64];
	GInput* input;

	GFont* font;

	std::vector<GButton*> stdButton;
	std::vector<GButton*>::iterator itButton;

	std::vector<GLabel*> stdLabel;
	std::vector<GLabel*>::iterator itLabel;

	std::vector<GSliderControl*> stdSlider;
	std::vector<GSliderControl*>::iterator itSlider;

	std::vector<GCheckbox*> stdCheckbox;
	std::vector<GCheckbox*>::iterator itCheckbox;

	std::vector<GGroupControl*> stdGroup;
	std::vector<GGroupControl*>::iterator itGroup;

	std::vector<GProgressbar*> stdProgressbar;
	std::vector<GProgressbar*>::iterator itProgressbar;

	std::vector<GEditbox*> stdEditbox;
	std::vector<GEditbox*>::iterator itEditbox;
};


#define WINDOW_TITLEBAR			0x1
#define WINDOW_EXIT				0x2
#define WINDOW_MINIMIZE			0x4
#define WINDOW_MAXIMIZE			0x8
#define WINDOW_STATUSBAR		0x10
#define WINDOW_MOVE				0x20

enum {
	GBUTTON,
	GLABEL,
	GSLIDER,
	GCHECKBOX,
	GGROUP,
	GPROGRESSBAR,
	GEDITBOX
};



class GWindow
{
public:
	GWindow();
	~GWindow();
	GGWindow* GCreateWindow(int x, int y, int width, int height, char* title, char* font, DWORD style);
	void GDraw(GGWindow* window);
	void setStatusText(GGWindow* window, char* text);
	char* getStatusText(GGWindow* window);
	void setTitlebarText(GGWindow* window, char* text);
	char* getTitlebarText(GGWindow* window);
	int GAssignElement(void* element, GGWindow* window, int type, void* function = NULL);
	GGWindow* GFindWindow(char* title, int index = NULL);
	bool OnMouseOver(GGWindow* window);
	bool OnClick(GGWindow* window);
	bool OnSelect(GGWindow* window);
private:
	int index;
	int k;
};



#endif