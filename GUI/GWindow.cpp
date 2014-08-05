#include "sdk.h"

GWindow::GWindow()
{
	index = 1;
	int k = 0;
}

GWindow::~GWindow()
{

}

GGWindow* GWindow::GCreateWindow(int x, int y, int width, int height, char* title, char* font, DWORD style)
{
	GGWindow* pWindow = new GGWindow();
	memset(pWindow, 0, sizeof(GGWindow));

	pWindow->x = x;
	pWindow->y = y;
	pWindow->width = width;
	pWindow->height = height;
	strcpy(pWindow->title, title);


	if(style & WINDOW_TITLEBAR)  pWindow->hasTitlebar = true;
	if(style & WINDOW_EXIT)		 pWindow->hasExit = true;
	if(style & WINDOW_MINIMIZE) pWindow->hasMinimized = true;
	if(style & WINDOW_MAXIMIZE) pWindow->hasMaximized = true;
	if(style & WINDOW_STATUSBAR) pWindow->hasStatusbar = true;
	if(style & WINDOW_MOVE)		 pWindow->canMove = true;

	pWindow->font = new GFont(font, 13, FW_NORMAL);
	pWindow->font->Create();
	
	pWindow->index = index++;
	pWindow->order = index;
	pWindow->input = new GInput();
	stdInput.push_back(pWindow->input);

	stdWindow.push_back(pWindow);

	return pWindow;
}

int GWindow::GAssignElement(void* element, GGWindow* window, int type, void* function)
{
	GConstruct* construct = (GConstruct*)element;
	construct->m_function = function;
	construct->window = window;
	
	switch(type) {
		case GBUTTON: 
			window->stdButton.push_back((GButton*)element);
			break;

		case GLABEL:
			window->stdLabel.push_back((GLabel*)element);
			break;

		case GSLIDER:
			window->stdSlider.push_back((GSliderControl*)element);
			break;

		case GCHECKBOX:
			window->stdCheckbox.push_back((GCheckbox*)element);
			break;

		case GGROUP:
			window->stdGroup.push_back((GGroupControl*)element);
			break;

		case GPROGRESSBAR:
			window->stdProgressbar.push_back((GProgressbar*)element);
			break;

		case GEDITBOX:
			window->stdEditbox.push_back((GEditbox*)element);
			break;

		default: 
			return -1; 
			break;
	}

	return globalindex++;
}


GGWindow* GWindow::GFindWindow(char* title, int index)
{
	for(itWindow = stdWindow.begin(); itWindow != stdWindow.end(); itWindow++) {
		if((*itWindow)->index != 0 && ((*itWindow)->index == index || (title && !strcmp((*itWindow)->title, title))))
			return *itWindow;
	}

	return NULL;
}

void GWindow::setStatusText(GGWindow* window, char* text)
{
	strcpy(window->statusbartext, text);
}

char* GWindow::getStatusText(GGWindow* window)
{
	return window->statusbartext;
}

void GWindow::setTitlebarText(GGWindow* window, char* text)
{
	strcpy(window->title, text);
}

char* GWindow::getTitlebarText(GGWindow* window)
{
	return window->title;
}

void GWindow::GDraw(GGWindow* window)
{

	pDraw->DrawFilledQuad(window->x, window->y, window->width, window->height, GColor(210, 210, 210));

	//left
	pDraw->DrawQuad(window->x+1, window->y+1, 1, window->height-3, white, 1);

	//up
	pDraw->DrawQuad(window->x+1, window->y+1, window->width-2, 1, white, 1);

	//right
	pDraw->DrawQuad(window->x+window->width-1, window->y+1, 1, window->height-2, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(window->x+window->width, window->y, 1, window->height, GColor(64, 64, 64), 1);

	//down
	pDraw->DrawQuad(window->x+1, window->y+window->height-2, window->width-2, 1, GColor(128, 128, 128), 1);
	pDraw->DrawQuad(window->x, window->y+window->height-1, window->width, 1, GColor(64, 64, 64), 1);

	int x_exit = window->x+window->width-22;
	int y_exit = window->y+6;

	if(window->hasTitlebar) {
		if(window->active) {
			pDraw->DrawFilledQuadGradient(window->x+4, window->y+4, window->width-7, 18, GColor(10, 36, 104), GColor(10, 36, 104, 50));
		}
		else {
			pDraw->DrawFilledQuadGradient(window->x+4, window->y+4, window->width-7, 18, GColor(125, 125, 125), GColor(125, 125, 125, 200));
		}

		int add_height = window->font->GetTextHeight(window->title) / 2;
		pMainFont->DrawText(window->x+7, window->y+4+8-add_height, white, DT_LEFT, window->title);

		if(window->hasExit) {
			//16x14
			pDraw->DrawFilledQuad(x_exit, y_exit, 16, 14, GColor(210, 210, 210));

				//left
				pDraw->DrawQuad(x_exit, y_exit, 1, 14, white, 1);

				//up
				pDraw->DrawQuad(x_exit, y_exit, 15, 1, white, 1);

				//right
				pDraw->DrawQuad(x_exit+14, y_exit+1, 1, 12, GColor(128, 128, 128), 1);
				pDraw->DrawQuad(x_exit+15, y_exit, 1, 14, GColor(64, 64, 64), 1);

				//down
				pDraw->DrawQuad(x_exit+1, y_exit+12, 13, 1, GColor(128, 128, 128), 1);
				pDraw->DrawQuad(x_exit, y_exit+13, 16, 1, GColor(64, 64, 64), 1);

				int char_width = pMainFont->GetTextWidth("x") /2;
				int char_height = pMainFont->GetTextHeight("x") /2;
				pMainFont->DrawText(x_exit+9-char_width, y_exit+5-char_height, black, DT_CENTER, "x");
		}
		if(window->hasMaximized) {
			//16x14
			x_exit -= 16;
			pDraw->DrawFilledQuad(x_exit, y_exit, 16, 14, GColor(210, 210, 210));

			//left
			pDraw->DrawQuad(x_exit, y_exit, 1, 14, white, 1);

			//up
			pDraw->DrawQuad(x_exit, y_exit, 15, 1, white, 1);

			//right
			pDraw->DrawQuad(x_exit + 14, y_exit + 1, 1, 12, GColor(128, 128, 128), 1);
			pDraw->DrawQuad(x_exit + 15, y_exit, 1, 14, GColor(64, 64, 64), 1);

			//down
			pDraw->DrawQuad(x_exit + 1, y_exit + 12, 13, 1, GColor(128, 128, 128), 1);
			pDraw->DrawQuad(x_exit, y_exit + 13, 16, 1, GColor(64, 64, 64), 1);

			int char_width = pMainFont->GetTextWidth("o") / 2;
			int char_height = pMainFont->GetTextHeight("o") / 2;
			pMainFont->DrawText(x_exit + 9 - char_width, y_exit + 5 - char_height, black, DT_CENTER, "o");
		}
		if(window->hasMinimized) {
			//16x14
			x_exit -= 16;
			pDraw->DrawFilledQuad(x_exit, y_exit, 16, 14, GColor(210, 210, 210));

			//left
			pDraw->DrawQuad(x_exit, y_exit, 1, 14, white, 1);

			//up
			pDraw->DrawQuad(x_exit, y_exit, 15, 1, white, 1);

			//right
			pDraw->DrawQuad(x_exit + 14, y_exit + 1, 1, 12, GColor(128, 128, 128), 1);
			pDraw->DrawQuad(x_exit + 15, y_exit, 1, 14, GColor(64, 64, 64), 1);

			//down
			pDraw->DrawQuad(x_exit + 1, y_exit + 12, 13, 1, GColor(128, 128, 128), 1);
			pDraw->DrawQuad(x_exit, y_exit + 13, 16, 1, GColor(64, 64, 64), 1);

			int char_width = pMainFont->GetTextWidth("_") / 2;
			int char_height = pMainFont->GetTextHeight("_") / 2;
			pMainFont->DrawText(x_exit + 9 - char_width, y_exit + 9 - char_height, black, DT_CENTER, "_");
		}
	}
	
	if(window->hasStatusbar) {
		pDraw->DrawQuad(window->x+4, window->y+window->height-25, window->width-9, 20, GColor(128,128,128), 1);
		
		//down
		pDraw->DrawQuad(window->x+4, window->y+window->height-6, window->width-9, 1, white, 1);

		//right
		pDraw->DrawQuad(window->x+window->width-6, window->y+window->height-25, 1, 20, white, 1);

		int add_height = window->font->GetTextHeight(window->statusbartext) / 2;
		window->font->DrawText(window->x+11, window->y+window->height-15-add_height, black, DT_LEFT, window->statusbartext);
	}


	for(window->itLabel = window->stdLabel.begin(); window->itLabel < window->stdLabel.end(); window->itLabel++) {
		(*window->itLabel)->DoModal();
	}

	for(window->itEditbox = window->stdEditbox.begin(); window->itEditbox < window->stdEditbox.end(); window->itEditbox++) {
		(*window->itEditbox)->DoModal();
	}

	for(window->itSlider = window->stdSlider.begin(); window->itSlider < window->stdSlider.end(); window->itSlider++) {
		(*window->itSlider)->DoModal();
	}

	for(window->itCheckbox = window->stdCheckbox.begin(); window->itCheckbox < window->stdCheckbox.end(); window->itCheckbox++) {
		(*window->itCheckbox)->DoModal();
	}

	for(window->itGroup = window->stdGroup.begin(); window->itGroup < window->stdGroup.end(); window->itGroup++) {
		(*window->itGroup)->DoModal();
	}

	for(window->itProgressbar = window->stdProgressbar.begin(); window->itProgressbar < window->stdProgressbar.end(); window->itProgressbar++) {
		(*window->itProgressbar)->DoModal();
	}


	for(window->itButton = window->stdButton.begin(); window->itButton < window->stdButton.end(); window->itButton++) {
		(*window->itButton)->DoModal();
	}



	bool bCanMove = true;

	for(itWindow2 = stdWindow.begin(); itWindow2 != stdWindow.end(); itWindow2++) {
		if((*itWindow2) != window && (*itWindow2)->moving == true) {
			bCanMove = false;
			break;
		}
	}

	/*char kk[100] = ""; sprintf(kk, "Order: %d", window->order);
	this->setTitlebarText(window, kk);*/

	if(window->canMove && bCanMove) {
		static int posx = 0, posy = 0;

		if(window->moving == false && window->input->OnMouseInArea(window->x+2, window->y+2, x_exit-window->x-5, 18) && this->OnSelect(window)/*window->input->OnMousePressing()*/) {
			posx = window->input->m_pPoint->x-window->x;
			posy = window->input->m_pPoint->y-window->y;
			window->moving = true;
		}

		if(window->moving) {
			window->x = window->input->m_pPoint->x - posx;
			window->y = window->input->m_pPoint->y - posy;
			if(!window->input->OnMousePressing()) {
				window->moving = false;
			}
		}
		
	}

	if(window->input->OnMouseInArea(window->x, window->y, window->width, window->height) && window->input->OnMousePressing() == true) {
		for(itWindow2 = stdWindow.begin(); itWindow2 != stdWindow.end(); itWindow2++) {
				(*itWindow2)->active = false;
		}
		window->active = true;
	}	
}

bool GWindow::OnMouseOver(GGWindow* window)
{
	if(window->input->OnMouseInArea(window->x, window->y, window->width, window->height))
		return true;

	return false;
}

bool GWindow::OnClick(GGWindow* window)
{
	if(this->OnMouseOver(window))
	{
		if(window->input->OnMousePressed() && !window->m_bClickCheck)
			return true;

		if(!window->input->OnMousePressing())
			window->m_bClickCheck = false;
	}
	else
		window->m_bClickCheck = true;

	return false;
}

bool GWindow::OnSelect(GGWindow* window)
{
	if(this->OnMouseOver(window))
	{
		if(window->input->OnMousePressing() && !window->m_bPressingCheck)
			return true;

		if(!window->input->OnMousePressing())
			window->m_bPressingCheck = false;
	}
	else
		window->m_bPressingCheck = window->input->OnMousePressing();

	return false;
}