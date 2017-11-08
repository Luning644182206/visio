#pragma once
#include "Basic.h"
class Rectangle:
	public Basic
{
protected:
	int height;
	int width;
public:
	Rectangle(int x1, int x2, int y1, int y2);
	~Rectangle();

	void Offset(int cx, int cy);    //位移
	void onSize(int cx, int cy);    //改变大小 
	void onPress(int x, int y);   //鼠标按下
	void onPress2(int x, int y);   //鼠标按下
	void onRelease(int x, int y); //鼠标释放
	void onMove(int cx, int cy);    //鼠标移动
	void onDraw(CDC *pDC);    //绘制
	CString onSave(); //保存
	void onDelete();  //删除
	void editDia();    //文字编辑
};

