#include "stdafx.h"
#include "Basic.h"


Basic::Basic()
{
	State = -1;
	kind = 0;
}
Basic::Basic(int lx, int rx, int uy, int dy)
{
	Lx = lx;
	Rx = rx;
	Uy = uy;
	Dy = dy;
	State = -1;
	kind = 0;
}
Basic::~Basic()
{
}
void Basic::DeleteStart()
{
	;
}
void Basic::DeleteEnd()
{
	;
}
void Basic::setStart(Basic*TuYuan)
{
	;
}
void Basic::setEnd(Basic*TuYuan)
{
	;
}
Basic* Basic::getStart()
{
	Basic*temp = new Basic();
	return temp;
}
Basic* Basic::getEnd()
{
	Basic*temp = new Basic();
	return temp;
}
int Basic::getBasic1()
{
	return 0;
}
int Basic::getBasic2()
{
	return 0;
}
void Basic::setLx(int x)
{
	Lx = x;
}
void Basic::setRx(int x)
{
	Rx = x;
}
void Basic::setUy(int y)
{
	Uy = y;
}
void Basic::setDy(int y)
{
	Dy = y;
}
void Basic::setState(int s)
{
	State = s;
}
void Basic::setKind(int k)
{
	kind = k;
}
int Basic::getLx()
{
	return Lx;
}
int Basic::getRx()
{
	return Rx;
}
int Basic::getUy()
{
	return Uy;
}
int Basic::getDy()
{
	return Dy;
}
int Basic::getState()
{
	return State;
}
int Basic::getKind()
{
	return kind;
}


void Basic::Offset(int cx, int cy)
{
	Lx += cx;		Rx += cx;
	Uy += cy;		Dy += cy;
}

void Basic::onSize(int cx, int cy)
{
	Lx -= cx / 2;	Rx += cx / 2;
	Uy -= cy / 2;	Dy += cy / 2;
}

void Basic::onPress(int x, int y)
{
	int t_height = 30;
	int f_width = 25;
	if (Rx - Lx <= 50)
	{
		f_width = (Rx - Lx) / 2;
	}
	if (Dy - Uy <= 60)
	{
		t_height = (Dy - Uy) / 2;
	}
	//if (Lx <= x && x <= Rx &&
	//	Uy <= y && y < Uy + t_height)
	//	State = 0;		//	选中标题
	if (Lx <= x && x < Lx + f_width && Uy + t_height <= y&&y <= Dy)	State = 1;	//	选中左边
	if (Uy <= y&&y <= Uy + t_height && Lx <= x &&x <= Rx)	State = 2;   // 上边
	if (Rx - f_width < x&&x <= Rx && Uy + t_height <= y&&y <= Dy)	State = 3;   //右边
	if (Dy - t_height < y&&y <= Dy && Lx + f_width <= x&&x <= Rx - f_width)	State = 4;	//	选中下边
	if (Lx + f_width <= x &&x <= Rx - f_width && Uy + t_height < y&&y <= Dy - t_height) State = 5; //选中对象
}
void Basic::onPress2(int x, int y)
{
	int t_height = 30;
	int f_width = 25;
	if (Rx - Lx <= 50)
	{
		f_width = (Rx - Lx) / 2;
	}
	if (Dy - Uy <= 60)
	{
		t_height = (Dy - Uy) / 2;
	}
	//if (Lx <= x && x <= Rx &&
	//	Uy <= y && y < Uy + t_height)
	//	State = 0;		//	选中标题
	if (Lx <= x && x < Lx + f_width && Uy + t_height <= y&&y <= Dy)	State = 1;	//	选中左边
	if (Uy <= y&&y <= Uy + t_height && Lx <= x &&x <= Rx)	State = 2;   // 上边
	if (Rx - f_width < x&&x <= Rx && Uy + t_height <= y&&y <= Dy)	State = 3;   //右边
	if (Dy - t_height < y&&y <= Dy && Lx + f_width <= x&&x <= Rx - f_width)	State = 4;	//	选中下边
	if (Lx + f_width <= x &&x <= Rx - f_width && Uy + t_height < y&&y <= Dy - t_height) State = 5; //选中对象
}
void Basic::onRelease(int x, int y)
{
	State = -1;
}

void Basic::onMove(int cx, int cy)
{
	if (State == 0) {
		Offset(cx, cy);		//  位移量cx,cy
	}
	else if (State == 1) {
		onSize(-cx, 0);		Offset(cx / 2, 0);
	}
	else if (State == 2) {
		onSize(0, -cy);		Offset(0, cy / 2);
	}
	else if (State == 3) {
		onSize(cx, 0);		Offset(cx / 2, 0);
	}
	else if (State == 4) {
		onSize(0, cy);		Offset(0, cy / 2);
	}		//	先改变大小，再移动半幅
	else if (State == 5)
	{
		Offset(cx, cy);
	}
	int temp;
	if (Lx > Rx)
	{
		temp = Rx;
		Rx = Lx;
		Lx = temp;
	}
	if (Uy > Dy)
	{
		temp = Dy;
		Dy = Uy;
		Uy = temp;
	}
}

void Basic::onDraw(CDC *pDC)
{
	pDC->Rectangle(Lx, Uy, Rx, Dy);
}

void Basic::onDelete()
{
	;
}
void Basic::editDia()
{
	;
}

CString Basic::onSave()
{
	CString cstr = _T("");
	return cstr;
}