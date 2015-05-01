#include "CPoint.h"


CCPoint::CCPoint(void)
{
	shape = SHAPE_POINT;
	name = "��";
	x = 0;
	y = 0;
}

CCPoint::CCPoint(char *name, float x, float y)
{
	shape = SHAPE_POINT;
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->x = x;
	this->y = y;
}

CCPoint::CCPoint(const CCPoint& src)
{
	shape = SHAPE_POINT;
	name = new char[strlen(src.name)];
	strcpy(name, src.name);
	x = src.x;
	y = src.y;
}

CCPoint::~CCPoint(void)
{
	delete[] name;
}

CCPoint CCPoint::operator+(float f)
{
	x += f;
	return *this;
}

void CCPoint::Draw()
{
	cout << "�� " << name << ", ���꣺(" << x << ", " << y << ")" << endl;
}

void CCPoint::saveToFile(ofstream& ofs)
{
	int len = strlen(name);
	ofs << shape << ' ' << x << ' ' << y << ' ' << len << endl;
	ofs << name << endl;
}

CCPoint& CCPoint::loadFromFile(ifstream& ifs)
{
	int len = 0;
	ifs >> x >> y >> len;
	len++;
	name = new char[len];
	while(ifs.get() != '\n'); // ����һ��
	ifs.getline(name, len);
	return *this;
}