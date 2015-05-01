#include "Rectangle.h"


CRectangle::CRectangle(void)
{
	shape = SHAPE_RECTANGLE;
	name = "矩形";
	x1 = 0;
	y1 = 0;
	x2 = 2;
	y2 = 1;
}

CRectangle::CRectangle(char *name, float x1, float y1, float x2, float y2)
{
	shape = SHAPE_RECTANGLE;
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

CRectangle::CRectangle(const CRectangle& src)
{
	shape = SHAPE_RECTANGLE;
	name = new char[strlen(src.name)];
	strcpy(name, src.name);
	x1 = src.x1;
	y1 = src.y1;
	x2 = src.x2;
	y2 = src.y2;
}

CRectangle::~CRectangle(void)
{
	delete[] name;
}

CRectangle CRectangle::operator+(float f)
{
	x1 += f;
	x2 += f;
	return *this;
}

void CRectangle::Draw()
{
	cout << "矩形 " << name << ", 两对角顶点为：(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")" << endl;
}

void CRectangle::Calc()
{
	cout << "矩形 " << name << ", 周长为：" << 2 * (abs(x1 - x2) + abs(y1 - y2));
}

void CRectangle::saveToFile(ofstream& ofs)
{
	int len = strlen(name);
	ofs << shape << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << len << endl;
	ofs << name << endl;
}

CRectangle& CRectangle::loadFromFile(ifstream& ifs)
{
	int len = 0;
	ifs >> x1 >> y1 >> x2 >> y2 >> len;
	len++;
	name = new char[len];
	while(ifs.get() != '\n'); // 跳过一行
	ifs.getline(name, len);
	return *this;
}

int CRectangle::exist()
{
	if((x1 == x2) || (y1 == y2))
		return 0;
	else
		return 1;
}