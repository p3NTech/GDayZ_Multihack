#ifndef _CONSTRUCT_
#define _CONSTRUCT_

class GInput;
class GTooltip;
struct GGWindow;

class GConstruct 
{
	public:
		GConstruct(char* title, int x, int y, int w, int h, char* tooltip = NULL);
		~GConstruct();
		bool OnMouseOver();
		bool OnSelect();
		bool OnSelectW();
		bool OnClick();
		void Enable(bool status);
		char* GetText();
		void SetText(char* text);
		bool GetCheck();
		void SetCheck(bool status);
		bool OnActive();
		void SetActive(bool status);
		GInput* m_pInput;
		int m_iX, m_iY, m_iW, m_iH, m_iK;
		int m_x, m_y;
		bool m_bClickCheck;
		bool m_bPressingCheck;
		bool m_bEnabled;
		bool m_bChecked;
		bool m_bActive;
		int index;
		void* m_function;
		GGWindow* window;
	private:

	protected:
		char m_pszTitle[100];
	
		GTooltip* m_pTooltip;
};

#endif