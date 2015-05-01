#pragma once
#include "shape.h"
class CPolygon :
	public CShape
{
public:
	// �޲�������
	CPolygon(void);
	// �в�������
	CPolygon(char*, int, float*, float*);
	// ��������
	~CPolygon(void);
	// ��������
	CPolygon(const CPolygon&);
	// ���������
	CPolygon operator+(float);
	// ��ʾ
	virtual void Draw();
	// �����ܳ�
	virtual void Calc();
	// �������ļ�
	virtual void saveToFile(ofstream&);
	// ���ļ���ȡ
	virtual CPolygon& loadFromFile(ifstream&);
	// �жϸ���״�Ƿ����
	int exist();

protected:
	int edges;
	float* px;
	float* py;
};

