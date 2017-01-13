#include "pch.h"
#include "IJtag.h"


IJtag::IJtag(int i,int j)
{
	_i = i;
	_j = j;
}

int IJtag::GetI()
{
	return _i;
}

int IJtag::GetJ()
{
	return _j;
}