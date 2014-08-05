#ifndef _INPUT_
#define _INPUT_

class GInput
{
	public:
		GInput();
		void SetMouse(POINT* point);
		bool OnMousePressing();
		bool OnMousePressed();
		bool OnMouseInArea(int x, int y, int w, int h);
		void OnKeyDown(int key);
		void OnKeyUp(int key);
		void ResetUserInput();
		char* GetUserInput();
		void SetLock(bool status);
		bool GetLock();
		bool OnActive();
		void SetActive(bool status);
		POINT* m_pPoint;
		bool m_bMouse1;
		char m_pszUserInput[10000];
	private:
		//POINT* m_pPoint;
		
		bool m_bReset;
		bool m_bShift;
		bool m_bAltGR;
		bool m_bLock;
		bool m_bActive;
	protected:
};

#endif