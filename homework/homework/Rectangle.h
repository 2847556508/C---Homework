#pragma once
#include "shape.h"
class CRectangle :
	public CShape
{
public:
	// �޲�������
	CRectangle(void);
	// �в�������
	CRectangle(char*, float, float, float, float);
	// ��������
	~CRectangle(void);
	// ��������
	CRectangle(const CRectangle&);
	// ���������
	CRectangle operator+(float);
	// ��ʾ
	virtual void Draw();
	// �����ܳ�
	virtual void Calc();
	// �������ļ�
	virtual void saveToFile(ofstream&);
	// ���ļ���ȡ
	virtual CRectangle& loadFromFile(ifstream&);
	// �жϸ���״�Ƿ����
	int exist();

private:
	float x1;
	float y1;
	float x2;
	float y2;
};