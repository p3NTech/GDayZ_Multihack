#include "sdk.h"

char pszAscii_ALTGR[256] = {0};
char pszAscii_SHIFT[256] = {0};
char pszAscii[256] = {0};

GInput::GInput()
{
	pszAscii_ALTGR['0'] = '}';
	pszAscii_ALTGR['2'] = '²';
	pszAscii_ALTGR['3'] = '³';
	pszAscii_ALTGR['7'] = '{';
	pszAscii_ALTGR['8'] = '[';
	pszAscii_ALTGR['9'] = ']';

	pszAscii_ALTGR[187] = '~';
	pszAscii_ALTGR[219] = '\\';
	pszAscii_ALTGR[226] = '|';
	pszAscii_ALTGR['M'] = 'µ';
	pszAscii_ALTGR['Q'] = '@';
	pszAscii_ALTGR['E'] = '€';

	pszAscii_SHIFT['0'] = '=';
	pszAscii_SHIFT['1'] = '!';
	pszAscii_SHIFT['2'] = '\"';
	pszAscii_SHIFT['3'] = '§';
	pszAscii_SHIFT['4'] = '$';
	pszAscii_SHIFT['5'] = '%';
	pszAscii_SHIFT['6'] = '&';
	pszAscii_SHIFT['7'] = '/';
	pszAscii_SHIFT['8'] = '(';
	pszAscii_SHIFT['9'] = ')';

	pszAscii_SHIFT[' '] = ' ';
	pszAscii_SHIFT['\n'] = '\n';
	pszAscii_SHIFT['A'] = 'A';
	pszAscii_SHIFT['B'] = 'B';
	pszAscii_SHIFT['C'] = 'C';
	pszAscii_SHIFT['D'] = 'D';
	pszAscii_SHIFT['E'] = 'E';
	pszAscii_SHIFT['F'] = 'F';
	pszAscii_SHIFT['G'] = 'G';
	pszAscii_SHIFT['H'] = 'H';
	pszAscii_SHIFT['I'] = 'I';
	pszAscii_SHIFT['J'] = 'J';
	pszAscii_SHIFT['K'] = 'K';
	pszAscii_SHIFT['L'] = 'L';
	pszAscii_SHIFT['M'] = 'M';
	pszAscii_SHIFT['N'] = 'N';
	pszAscii_SHIFT['O'] = 'O';
	pszAscii_SHIFT['P'] = 'P';
	pszAscii_SHIFT['Q'] = 'Q';
	pszAscii_SHIFT['R'] = 'R';
	pszAscii_SHIFT['S'] = 'S';
	pszAscii_SHIFT['T'] = 'T';
	pszAscii_SHIFT['U'] = 'U';
	pszAscii_SHIFT['V'] = 'V';
	pszAscii_SHIFT['W'] = 'W';
	pszAscii_SHIFT['X'] = 'X';
	pszAscii_SHIFT['Y'] = 'Y';
	pszAscii_SHIFT['Z'] = 'Z';

	pszAscii_SHIFT[186] = 'Ü';
	pszAscii_SHIFT[187] = '*';
	pszAscii_SHIFT[188] = ';';
	pszAscii_SHIFT[189] = '_';
	pszAscii_SHIFT[190] = ':';
	pszAscii_SHIFT[191] = '\'';
	pszAscii_SHIFT[192] = 'Ö';
	pszAscii_SHIFT[219] = '?';
	pszAscii_SHIFT[220] = '°';
	pszAscii_SHIFT[221] = '`';
	pszAscii_SHIFT[222] = 'Ä';
	pszAscii_SHIFT[226] = '>';

	pszAscii['0'] = '0';
	pszAscii['1'] = '1';
	pszAscii['2'] = '2';
	pszAscii['3'] = '3';
	pszAscii['4'] = '4';
	pszAscii['5'] = '5';
	pszAscii['6'] = '6';
	pszAscii['7'] = '7';
	pszAscii['8'] = '8';
	pszAscii['9'] = '9';

	pszAscii[' '] = ' ';
	pszAscii[VK_TAB] = '\t';
	pszAscii[VK_RETURN] = '\n';
	pszAscii['A'] = 'a';
	pszAscii['B'] = 'b';
	pszAscii['C'] = 'c';
	pszAscii['D'] = 'd';
	pszAscii['E'] = 'e';
	pszAscii['F'] = 'f';
	pszAscii['G'] = 'g';
	pszAscii['H'] = 'h';
	pszAscii['I'] = 'i';
	pszAscii['J'] = 'j';
	pszAscii['K'] = 'k';
	pszAscii['L'] = 'l';
	pszAscii['M'] = 'm';
	pszAscii['N'] = 'n';
	pszAscii['O'] = 'o';
	pszAscii['P'] = 'p';
	pszAscii['Q'] = 'q';
	pszAscii['R'] = 'r';
	pszAscii['S'] = 's';
	pszAscii['T'] = 't';
	pszAscii['U'] = 'u';
	pszAscii['V'] = 'v';
	pszAscii['W'] = 'w';
	pszAscii['X'] = 'x';
	pszAscii['Y'] = 'y';
	pszAscii['Z'] = 'z';

	pszAscii[ 96] = '0';
	pszAscii[ 97] = '1';
	pszAscii[ 98] = '2';
	pszAscii[ 99] = '3';
	pszAscii[100] = '4';
	pszAscii[101] = '5';
	pszAscii[102] = '6';
	pszAscii[103] = '7';
	pszAscii[104] = '8';
	pszAscii[105] = '9';

	pszAscii[106] = '*';
	pszAscii[107] = '+';
	pszAscii[109] = '-';
	pszAscii[110] = ',';
	pszAscii[111] = '/';
	pszAscii[186] = 'ü';
	pszAscii[187] = '+';
	pszAscii[188] = ',';
	pszAscii[189] = '-';
	pszAscii[190] = '.';
	pszAscii[191] = '#';
	pszAscii[192] = 'ö';
	pszAscii[219] = 'ß';
	pszAscii[220] = '^';
	pszAscii[221] = '´';
	pszAscii[222] = 'ä';
	pszAscii[226] = '<';

	m_pPoint = NULL;
	m_bShift = false;
	m_bAltGR = false;
	m_bLock = false;
	m_bActive = false;
	ResetUserInput();
}

void GInput::SetMouse(POINT* point)
{
	if(m_bLock) return;

	m_pPoint = point;
}

void GInput::OnKeyDown(int key)
{
	if(key == VK_SHIFT) m_bShift = true;
	if(key == 18) m_bAltGR = true;

	unsigned char character = m_bShift?pszAscii_SHIFT[key]:pszAscii[key];
	if(m_bAltGR) character = pszAscii_ALTGR[key];

	if(key == '\b' || key == VK_DELETE)
		m_pszUserInput[strlen(m_pszUserInput)-1] = 0;

	else if(!this->GetLock())
	{
		char szBackup[10000] = {0};
		strcpy(szBackup, m_pszUserInput);
		if(character != '%')
			sprintf(m_pszUserInput, "%s%c", szBackup, character);
		else
			sprintf(m_pszUserInput, "%s%%", szBackup);
	}
}

void GInput::OnKeyUp(int key)
{
	if(key == VK_SHIFT) m_bShift = false;
	if(key == 18) m_bAltGR = false;
}

void GInput::SetLock(bool status)
{
	m_bLock = status;
}

bool GInput::GetLock()
{
	return m_bLock;
}

void GInput::SetActive(bool status)
{
	m_bActive = status;
}

bool GInput::OnActive()
{
	return m_bActive;
}

char* GInput::GetUserInput()
{
	return m_pszUserInput;
}

void GInput::ResetUserInput()
{
	memset(&m_pszUserInput, 0, sizeof(m_pszUserInput));
	m_bReset = false;
}

bool GInput::OnMousePressing()
{
	if(m_bLock) return false;

	bool hr = m_bMouse1;
	if(hr) return true;

	return false;
}


bool GInput::OnMousePressed()
{
	if(m_bLock) return false;

	bool hr = m_bMouse1;
	if(hr)  m_bReset = true;

	if(hr == 0 && m_bReset)
	{
		m_bReset = false;
		return true;
	}
	
	return false;
}

bool GInput::OnMouseInArea(int x, int y, int w, int h)
{
	if(m_bLock) return false;

	int xw = x + w;
	int yh = y + h; 

	if(!m_pPoint) return false;

	if(m_pPoint->x <= xw && m_pPoint->x >= x &&
	   m_pPoint->y <= yh && m_pPoint->y >= y) 	 
		return true; 

	return false;
}