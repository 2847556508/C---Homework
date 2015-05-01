#pragma once
#include "shape.h"
class CLine :
	public CShape
{
public:
	// 无参数构造
	CLine(void);
	// 有参数构造
	CLine(char*, float, float, float, float);
	// 析构函数
	~CLine(void);
	// 拷贝构造
	CLine(const CLine&);
	// 重载运算符
	CLine operator+(float);
	// 显示
	virtual void Draw();
	// 保存至文件
	virtual void saveToFile(ofstream&);
	// 从文件读取
	virtual CLine& loadFromFile(ifstream&);
	// 判断该形状是否存在
	int exist();

private:
	float x1;
	float y1;
	float x2;
	float y2;
};

