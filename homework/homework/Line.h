#pragma once
#include "shape.h"
class CLine :
	public CShape
{
public:
	// �޲�������
	CLine(void);
	// �в�������
	CLine(char*, float, float, float, float);
	// ��������
	~CLine(void);
	// ��������
	CLine(const CLine&);
	// ���������
	CLine operator+(float);
	// ��ʾ
	virtual void Draw();
	// �������ļ�
	virtual void saveToFile(ofstream&);
	// ���ļ���ȡ
	virtual CLine& loadFromFile(ifstream&);
	// �жϸ���״�Ƿ����
	int exist();

private:
	float x1;
	float y1;
	float x2;
	float y2;
};

