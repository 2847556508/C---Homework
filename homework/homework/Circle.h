#pragma once
#include "shape.h"
class CCircle :
	public CShape
{
public:
	// 无参数构造
	CCircle(void);
	// 有参数构造(圆心坐标，半径)
	CCircle(char *, float x, float y, float r);
	// 析构函数
	~CCircle(void);
	// 拷贝构造
	CCircle(const CCircle&);
	// 重载“+”操作符
	CCircle operator+(const float);
	// 显示名称等信息
	virtual void Draw(void);
	// 计算并显示周长
	virtual void Calc(void);
	// 保存至文件
	virtual void saveToFile(ofstream&);
	// 从文件读取
	virtual CCircle& loadFromFile(ifstream&);

private:
	float x;
	float y;
	float r;
};