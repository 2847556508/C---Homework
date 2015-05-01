#pragma once
#include "shape.h"
class CPolygon :
	public CShape
{
public:
	// 无参数构造
	CPolygon(void);
	// 有参数构造
	CPolygon(char*, int, float*, float*);
	// 析构函数
	~CPolygon(void);
	// 拷贝构造
	CPolygon(const CPolygon&);
	// 重载运算符
	CPolygon operator+(float);
	// 显示
	virtual void Draw();
	// 计算周长
	virtual void Calc();
	// 保存至文件
	virtual void saveToFile(ofstream&);
	// 从文件读取
	virtual CPolygon& loadFromFile(ifstream&);
	// 判断该形状是否存在
	int exist();

protected:
	int edges;
	float* px;
	float* py;
};

