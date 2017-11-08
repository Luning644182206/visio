#pragma once
#include <vector>
using namespace std;
class Basic
{
protected:
	int Lx;
	int Rx;
	int Uy;
	int Dy;
	int State;
	int kind;
	CString Name;
	vector<CString> property;
	vector<CString> method;
	CString startpoint;
	CString finalpoint;
public:
	Basic();
	Basic(int lx, int rx, int uy, int dy);
	~Basic();

	void setLx(int x);
	void setRx(int x);
	void setUy(int y);
	void setDy(int y);
	void setKind(int k);
	void setState(int s);
	virtual int getLx();
	virtual int getRx();
	virtual int getUy();
	virtual int getDy();
	int getState();
	int getKind();

	virtual void setStart(Basic*TuYuan);
	virtual void setEnd(Basic*TuYuan);
	virtual void DeleteStart();
	virtual void DeleteEnd();
	virtual Basic* getStart();
	virtual Basic* getEnd();
	virtual int getBasic1();
	virtual int getBasic2();
	virtual void Offset(int cx, int cy);    //位移
	virtual void onSize(int cx, int cy);    //改变大小 
	virtual void onPress(int x, int y);   //鼠标按下
	virtual void onPress2(int x, int y);   //鼠标按下双击
	virtual void onRelease(int x, int y); //鼠标释放
	virtual void onMove(int cx, int cy);    //鼠标移动
	virtual void onDraw(CDC *pDC);    //绘制
	virtual CString onSave(); //保存
	virtual void onDelete();  //删除
	virtual void editDia();    //文字编辑

};

