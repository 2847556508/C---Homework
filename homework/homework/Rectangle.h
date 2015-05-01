#pragma once
#include "shape.h"
class CRectangle :
	public CShape
{
public:
	// 无参数构造
	CRectangle(void);
	// 有参数构造
	CRectangle(char*, float, float, float, float);
	// 析构函数
	~CRectangle(void);
	// 拷贝构造
	CRectangle(const CRectangle&);
	// 重载运算符
	CRectangle operator+(float);
	// 显示
	virtual void Draw();
	// 计算周长
	virtual void Calc();
	// 保存至文件
	virtual void saveToFile(ofstream&);
	// 从文件读取
	virtual CRectangle& loadFromFile(ifstream&);
	// 判断该形状是否存在
	int exist();

private:
	float x1;
	float y1;
	float x2;
	float y2;
};