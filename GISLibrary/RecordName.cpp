#include "stdafx.h"
#include "RecordName.h"

RecordName::RecordName(void)
{

}

RecordName::RecordName(int RCNM, int RCID)
{
	this->RCNM = RCNM;
	this->RCID = RCID;
}

RecordName::RecordName(enum GISLibrary::RCNM RCNM, int RCID)
{
	this->RCNM = (int)RCNM;
	this->RCID = RCID;
}

RecordName::~RecordName(void)
{

}

__int64 RecordName::GetName()
{
	return ((__int64)RCNM) << 32 | RCID;
}

int RecordName::GetLength()
{
	return 5;
}

std::wstring RecordName::GetRCIDasWstring() 
{
	return std::to_wstring(RCID);
}