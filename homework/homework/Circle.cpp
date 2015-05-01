#include "Circle.h"

CCircle::CCircle(void)
{
	shape = SHAPE_CIRCLE;
	name = "Բ��";
	x = 0;
	y = 0;
	r = 1;
}

CCircle::CCircle(char* name, float x, float y, float r)
{
	shape = SHAPE_CIRCLE;
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->x = x;
	this->y = y;
	this->r = r;
}

CCircle::~CCircle(void)
{
	delete[] name;
}

CCircle::CCircle(const CCircle& src)
{
	shape = SHAPE_CIRCLE;
	name = new char[strlen(src.name)];
	strcpy(name, src.name);
	x = src.x;
	y = src.y;
	r = src.r;
}

CCircle CCircle::operator+(const float f)
{
	x += f;
	return *this;
}

void CCircle::Draw(void)
{
	cout << "Բ�� " << name << ", "
		 << "Բ�ģ� (" << x << ", " << y << "),  "
		 << "�뾶�� " << r << endl;
}

void CCircle::Calc(void)
{
	cout << "Բ�� " << name << ", "
		 << "�ܳ�Ϊ�� " << 2*3.14*r << endl;
}

void CCircle::saveToFile(ofstream& ofs)
{
	int len = strlen(name);
	ofs << shape << ' ' << x << ' ' << y << ' ' << r << ' ' << len << endl;
	ofs << name << endl;
}

CCircle& CCircle::loadFromFile(ifstream& ifs)
{
	int len = 0;
	ifs >> x >> y >> r >> len;
	len++;
	name = new char[len];
	while(ifs.get() != '\n'); // ����һ��
	ifs.getline(name, len);
	return *this;
}