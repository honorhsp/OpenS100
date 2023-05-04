#include "stdafx.h"
#include "RIAS.h"

int RIAS::GetSize()
{
	return 8;
}

bool RIAS::IsForward()
{
	return m_ornt == 1;
}

bool RIAS::IsReverse()
{
	return m_ornt == 2;
}

bool RIAS::IsExterior()
{
	return m_usag == 1;
}

bool RIAS::IsInterior()
{
	return m_usag == 2;
}

bool RIAS::IsCurve()
{
	return m_name.RCNM == 120;
}

bool RIAS::IsCompositeCurve()
{
	return m_name.RCNM == 125;
}