#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class CShape
{
public:
	const static int SHAPE_CIRCLE = 1;
	const static int SHAPE_POINT = 2;
	const static int SHAPE_LINE = 3;
	const static int SHAPE_POLYGON = 4;
	const static int SHAPE_RECTANGLE = 5;
	const static int SHAPE_TRIANGLE = 6;
	// �޲�������
	CShape(void);
	// �в�������
	CShape(char*);
	// ��������
	~CShape(void);
	// ��������
	CShape(const CShape&);
	// ��ȡ����
	char *getName();
	// ��ʾ���Ƶ���Ϣ��ʹ���麯��
	virtual void Draw(void);
	// ���㲢��ʾ�ܳ���ʹ���麯��
	virtual void Calc(void);
	// �������ļ�
	virtual void saveToFile(ofstream&);
	// ���ļ���ȡ
	virtual CShape& loadFromFile(ifstream&);
	// �ж���״�Ƿ����
	virtual int exist();

protected:
	// ͼ�ε�����
	char* name;
	int shape;
};