#pragma once
#include "polygon.h"

class CTriangle :
	public CPolygon
{
public:
	// �޲�������
	CTriangle(void);
	// �в�������
	CTriangle(char*, float*, float*);
	// ��������
	~CTriangle(void);
	// ��������
	CTriangle(const CTriangle&);
	// ���������
	CTriangle operator+(float);
	// ��ʾ
	virtual void Draw();
	// �����ܳ�
	virtual void Calc();
	// �������ļ�
	virtual void saveToFile(ofstream&);
	// ���ļ���ȡ
	virtual CTriangle& loadFromFile(ifstream&);
	// �жϸ���״�Ƿ����(�����ε��жϺ����̳������μ��ɣ������ظ�����)
	//int exist();

private:
};