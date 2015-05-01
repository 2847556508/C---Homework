#include "Circle.h"

CCircle::CCircle(void)
{
	shape = SHAPE_CIRCLE;
	name = "圆形";
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
	cout << "圆形 " << name << ", "
		 << "圆心： (" << x << ", " << y << "),  "
		 << "半径： " << r << endl;
}

void CCircle::Calc(void)
{
	cout << "圆形 " << name << ", "
		 << "周长为： " << 2*3.14*r << endl;
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
	while(ifs.get() != '\n'); // 跳过一行
	ifs.getline(name, len);
	return *this;
}