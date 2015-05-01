#pragma once
#include "Shape.h"
#include <vector>
#include <string>

class CShapeArray
{
public:
	CShapeArray(void);
	~CShapeArray(void);
	// ���
	void add(CShape*);
	// ����
	void insert(int, CShape);
	// ɾ��
	void del(int);
	// ���ȫ��
	void clear(void);
	// ��ѯ
	CShape* get(int);
	// ����
	void copy(int, int);
	// ��ʾ����Ԫ��
	void drawAll(void);
	// ��ȡԪ����Ŀ
	int getSize(void);
	// �������Ʋ�ѯ
	int findByName(char*);

private:
	vector<CShape*> vec;
};