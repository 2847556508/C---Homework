#pragma once

/***********************包含头文件***********************/
#include <iostream>

using namespace std;

#include "Shape.h"
#include "ShapeArray.h"

#include "Circle.h"
#include "CPoint.h"
#include "Line.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Triangle.h"

/**********************全局变量声明**********************/
// 保存到的文件名
const static char *fname = "D:\\dat.txt";
// CShapeArray对象
CShapeArray arr;
// 记录要复制的形状所在位置
int copyPos = -1;
/************************函数声明************************/
// 输入数字进行选择
int input(char *, int);
// 清屏
void clr();
// 暂停
void pause();
// 选择操作
void inputOp();
// 选择形状
void inputShape();
// 查询
void inputQuery();
// 输入位置查询
void inputPos();
// 输入名称查询
void inputName();
// 复制
void inputCopy();
// 粘贴
void inputPaste();
// 删除
void inputDel();
// 保存至文件
void saveToFile();
// 从文件读取
void loadFromFile();
// 输入矩形
CRectangle* inputRectangle();
// 输入圆形
CCircle* inputCircle();
// 输入多边形
CPolygon* inputPolygon();
// 输入三角形
CTriangle* inputTriangle();
// 输入点
CCPoint* inputPoint();
// 输入直线
CLine* inputLine();