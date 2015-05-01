#pragma once

/***********************����ͷ�ļ�***********************/
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

/**********************ȫ�ֱ�������**********************/
// ���浽���ļ���
const static char *fname = "D:\\dat.txt";
// CShapeArray����
CShapeArray arr;
// ��¼Ҫ���Ƶ���״����λ��
int copyPos = -1;
/************************��������************************/
// �������ֽ���ѡ��
int input(char *, int);
// ����
void clr();
// ��ͣ
void pause();
// ѡ�����
void inputOp();
// ѡ����״
void inputShape();
// ��ѯ
void inputQuery();
// ����λ�ò�ѯ
void inputPos();
// �������Ʋ�ѯ
void inputName();
// ����
void inputCopy();
// ճ��
void inputPaste();
// ɾ��
void inputDel();
// �������ļ�
void saveToFile();
// ���ļ���ȡ
void loadFromFile();
// �������
CRectangle* inputRectangle();
// ����Բ��
CCircle* inputCircle();
// ��������
CPolygon* inputPolygon();
// ����������
CTriangle* inputTriangle();
// �����
CCPoint* inputPoint();
// ����ֱ��
CLine* inputLine();