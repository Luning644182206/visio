#include "stdafx.h"
#include "Rectangle.h"

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(int x1, int x2, int y1, int y2) :Basic()
{
	Lx = x1;
	Rx = x2;
	Uy = y1;
	Dy = y2;
	kind = 3;
	height = (y2 - y1) / 3;
	width = (x2 - x1) / 3;
}
Rectangle::~Rectangle()
{
}

void Rectangle::Offset(int cx, int cy)
{
	Lx += cx;       Rx += cx;
	Uy += cy;       Dy += cy;
}

void Rectangle::onSize(int cx, int cy)
{
	Lx -= cx / 2;   Rx += cx / 2;
	Uy -= cy / 2;   Dy += cy / 2;
}

void Rectangle::onPress(int x, int y)
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
	if (Lx <= x && x < Lx + f_width && Uy + t_height <= y&&y <= Dy) State = 1;  //  选中左边
	if (Uy <= y&&y <= Uy + t_height && Lx <= x &&x <= Rx)   State = 2;   // 上边
	if (Rx - f_width < x&&x <= Rx && Uy + t_height <= y&&y <= Dy)   State = 3;   //右边
	if (Dy - t_height < y&&y <= Dy && Lx + f_width <= x&&x <= Rx - f_width) State = 4;  //  选中下边
	if (Lx + f_width <= x &&x <= Rx - f_width && Uy + t_height < y&&y <= Dy - t_height) State = 0; //选中对象
	if (Lx <= x&&x <= Lx + width&&y >= Uy + height - 10 && y <= Uy + height + 10)State = 6;//小格子下边
	if (Lx + width - 10 <= x&&x <= Lx + width + 10 && y >= Uy && y <= Uy + height)State = 7;//小格子右边
}
void Rectangle::onPress2(int x, int y)
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
	if (Lx <= x && x < Lx + f_width && Uy + t_height <= y&&y <= Dy) State = 1;  //  选中左边
	if (Uy <= y&&y <= Uy + t_height && Lx <= x &&x <= Rx)   State = 2;   // 上边
	if (Rx - f_width < x&&x <= Rx && Uy + t_height <= y&&y <= Dy)   State = 3;   //右边
	if (Dy - t_height < y&&y <= Dy && Lx + f_width <= x&&x <= Rx - f_width) State = 4;  //  选中下边
	if (Lx + f_width <= x &&x <= Rx - f_width && Uy + t_height < y&&y <= Dy - t_height) State = 0; //选中对象
	if (Lx <= x&&x <= Lx + width&&y >= Uy + height - 10 && y <= Uy + height + 10)State = 6;//小格子下边
	if (Lx + width - 10 <= x&&x <= Lx + width + 10 && y >= Uy && y <= Uy + height)State = 7;//小格子右边
}

void Rectangle::onRelease(int x, int y)
{
	State = -1;
}

void Rectangle::onMove(int cx, int cy)
{
	if (getState() == 0) {
		Offset(cx, cy);     //  位移量cx,cy
	}
	else if (getState() == 1) {
		if (cx > 0 && cx > width)
			cx = width - 20;
		onSize(-cx, 0);
		Offset(cx / 2, 0);
		width -= cx;
	}
	else if (getState() == 2) {
		if (cy > height)
			cy = height - 20;
		onSize(0, -cy);     Offset(0, cy / 2);
		height -= cy;
	}
	else if (getState() == 3) {
		if (cx<0 && -cx>Rx - Lx - width)
			cx = -Rx + Lx + width + 20;
		onSize(cx, 0);      Offset(cx / 2, 0);
	}
	else if (getState() == 4) {
		if (cy<0 && -cy>Dy - Uy - height)
			cy = Uy + height - Dy + 20;
		onSize(0, cy);      Offset(0, cy / 2);
	}       //  先改变大小，再移动半幅
	else if (getState() == 5)
	{
		Offset(cx, cy);
	}
	else if (getState() == 6)   //小格子下边
	{
		if (cy > 0 && cy + Uy + height >= Dy)
			cy = Dy - Uy - height - 30;
		if (cy < 0 && -cy >= height)
			cy = -height + 20;
		height += cy;
	}
	else if (getState() == 7)   //小格子右边
	{
		if (cx>0 && Lx + width + cx > Rx)
			cx = Rx - Lx - width - 20;
		if (cx<0 && -cx>width)
			cx = -width + 20;
		width += cx;
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

void Rectangle::onDraw(CDC *pDC)
{
	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));//建立画笔对象，构造时设置画笔属性
	pDC->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	pDC->SelectObject(&brush);
	pDC->Rectangle(Lx, Uy, Lx + width, Uy + height);
	pDC->Rectangle(Lx, Uy + height, Rx, Dy);
	pDC->TextOutW(Lx + 10, Uy + 10, Name);
	/*CPoint p1 = (50, 50);
	CPoint p2 = (20, 60);
	pDC->MoveTo(p1);
	pDC->LineTo(p2);*/
}

void Rectangle::onDelete()
{
	;
}
void Rectangle::editDia()
{
	/*PackDia dlg;
	dlg.Name = Name;
	if (IDOK == dlg.DoModal())
	{
		Name = dlg.Name;
	}*/
}
CString Rectangle::onSave()
{
	CString cstr = _T("");
	return cstr;
}
