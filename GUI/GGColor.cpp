#include "sdk.h"


GColor::GColor(int r, int g, int b, int a) :
	m_iR(r), m_iG(g), m_iB(b), m_iA(a)
{
	Set();
}

GColor &GColor::operator =(GColor& color)
{
	m_iR = color.m_iR;
	m_iG = color.m_iG;
	m_iB = color.m_iB;
	m_iA = color.m_iA;

	Set();

	return *this;
}

void GColor::Set()
{
	m_dwColor = 0;
	m_dwColor |= ((BYTE)m_iA << 24);
	m_dwColor |= ((BYTE)m_iR << 16);
	m_dwColor |= ((BYTE)m_iG << 8);
	m_dwColor |= ((BYTE)m_iB << 0);
}

DWORD GColor::Get()
{
	return m_dwColor;
}