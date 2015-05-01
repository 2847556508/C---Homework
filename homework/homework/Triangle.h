#pragma once
#include "polygon.h"

class CTriangle :
	public CPolygon
{
public:
	// 无参数构造
	CTriangle(void);
	// 有参数构造
	CTriangle(char*, float*, float*);
	// 析构函数
	~CTriangle(void);
	// 拷贝构造
	CTriangle(const CTriangle&);
	// 重载运算符
	CTriangle operator+(float);
	// 显示
	virtual void Draw();
	// 计算周长
	virtual void Calc();
	// 保存至文件
	virtual void saveToFile(ofstream&);
	// 从文件读取
	virtual CTriangle& loadFromFile(ifstream&);
	// 判断该形状是否存在(三角形的判断函数继承与多边形即可，无需重复定义)
	//int exist();

private:
};