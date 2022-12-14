// TagLine.cpp: implementation of the CTagLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "3dfstbrk.h"
#include "TagLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTagLine::CTagLine()
{
	nPointHead=-1;
	nPointTail=-1;
}

CTagLine::~CTagLine()
{

}

void CTagLine::operator =(CTagLine &other)
{
	CLine::operator = (other);
	nPointHead=other.nPointHead ;
	nPointTail=other.nPointTail ;
}

bool CTagLine::Linking(long i)
{
	return (nPointHead==i||nPointTail==i);
}

long CTagLine::CommonPoint(CTagLine &other)
{
	if(nPointHead==other.nPointHead )return nPointHead ;
	if(nPointTail==other.nPointHead )return nPointHead ;
	if(nPointHead==other.nPointTail)return nPointHead ;
	if(nPointTail==other.nPointTail)return nPointTail ;
	return -1;
}

CMyPrcPoint CTagLine::MidPoint()
{
	return CMyPrcPoint(x1+(x2-x1)/2,y1+(y2-y1)/2,m_dPrecision);
}
