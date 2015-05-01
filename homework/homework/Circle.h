#pragma once
#include "shape.h"
class CCircle :
	public CShape
{
public:
	// �޲�������
	CCircle(void);
	// �в�������(Բ�����꣬�뾶)
	CCircle(char *, float x, float y, float r);
	// ��������
	~CCircle(void);
	// ��������
	CCircle(const CCircle&);
	// ���ء�+��������
	CCircle operator+(const float);
	// ��ʾ���Ƶ���Ϣ
	virtual void Draw(void);
	// ���㲢��ʾ�ܳ�
	virtual void Calc(void);
	// �������ļ�
	virtual void saveToFile(ofstream&);
	// ���ļ���ȡ
	virtual CCircle& loadFromFile(ifstream&);

private:
	float x;
	float y;
	float r;
};