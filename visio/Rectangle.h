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

	void Offset(int cx, int cy);    //λ��
	void onSize(int cx, int cy);    //�ı��С 
	void onPress(int x, int y);   //��갴��
	void onPress2(int x, int y);   //��갴��
	void onRelease(int x, int y); //����ͷ�
	void onMove(int cx, int cy);    //����ƶ�
	void onDraw(CDC *pDC);    //����
	CString onSave(); //����
	void onDelete();  //ɾ��
	void editDia();    //���ֱ༭
};

