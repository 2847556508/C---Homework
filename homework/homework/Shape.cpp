#include "Shape.h"


CShape::CShape(void)
{
	name = "��״";
}

CShape::CShape(char *name)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}

CShape::~CShape(void)
{
	delete[] name;
}

CShape::CShape(const CShape& src)
{
	name = new char[strlen(src.name)];
	strcpy(name, src.name);
}

void CShape::Draw(void)
{
	// ��������������ô˷���
	cout << "δ������״" << endl;
}

void CShape::Calc(void)
{
	// ��������������ô˷���
	cout << "�޷������ܳ�" << endl;
}

char *CShape::getName(void)
{
	return name;
}

void CShape::saveToFile(ofstream&)
{
}

CShape& CShape::loadFromFile(ifstream&)
{
	return *new CShape();
}

int CShape::exist()
{
	return 1;
}