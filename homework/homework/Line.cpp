#include "Line.h"

CLine::CLine(void)
{
	shape = SHAPE_LINE;
	name = "直线";
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

CLine::CLine(char *name, float x1, float y1, float x2, float y2)
{
	shape = SHAPE_LINE;
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

CLine::CLine(const CLine& src)
{
	shape = SHAPE_LINE;
	name = new char[strlen(src.name)];
	strcpy(name, src.name);
	x1 = src.x1;
	y1 = src.y1;
	x2 = src.x2;
	y2 = src.y2;
}

CLine::~CLine(void)
{
	delete[] name;
}

CLine CLine::operator+(float f)
{
	x1 += f;
	x2 += f;
	return *this;
}

void CLine::Draw()
{
	cout << "直线 " << name << ", "
		 << "经过点：(" << x1 << ", " << y1 << ")" << ",  "
		 << "(" << x2 << ", " << y2 << ")" << endl;
}

void CLine::saveToFile(ofstream& ofs)
{
	int len = strlen(name);
	ofs << shape << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << len << endl;
	ofs << name << endl;
}

CLine& CLine::loadFromFile(ifstream& ifs)
{
	int len = 0;
	ifs >> x1 >> y1 >> x2 >> y2 >> len;
	len++;
	name = new char[len];
	while(ifs.get() != '\n'); // 跳过一行
	ifs.getline(name, len);
	return *this;
}

int CLine::exist()
{
	if((x1 == x2) && (y1 == y2))
		return 0;
	else
		return 1;
}