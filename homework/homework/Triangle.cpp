#include "Triangle.h"


CTriangle::CTriangle(void)
{
	shape = SHAPE_TRIANGLE;
	name = "三角形";
	edges = 3;
	float x[] = {0, 0, 1};
	float y[] = {0, 1, 0};
	px = new float[edges];
	py = new float[edges];
	for(int i = 0; i < edges; i++) {
		this->px[i] = x[i];
		this->py[i] = y[i];
	}
}

CTriangle::CTriangle(char *name, float *px, float *py)
{
	shape = SHAPE_TRIANGLE;
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->edges = 3;
	this->px = new float[3];
	this->py = new float[3];
	for(int i = 0; i < 3; i++) {
		this->px[i] = px[i];
		this->py[i] = py[i];
	}
}

CTriangle::CTriangle(const CTriangle& src)
{
	shape = SHAPE_TRIANGLE;
	name = new char[strlen(src.name)];
	strcpy(name, src.name);
	this->edges = 3;
	this->px = new float[3];
	this->py = new float[3];
	for(int i = 0; i < 3; i++) {
		this->px[i] = src.px[i];
		this->py[i] = src.py[i];
	}
}

CTriangle::~CTriangle(void)
{
	delete[] name;
}

CTriangle CTriangle::operator+(float f)
{
	px[0] += f;
	px[1] += f;
	px[2] += f;
	return *this;
}

void CTriangle::Draw()
{
	cout << "三角形 " << name << ", "
		 << "三个顶点坐标分别为：(" << px[0] << ", " << py[0] << "), ("
		 << px[1] << ", " << py[1] << "), ("
		 << px[2] << ", " << py[2] << ")" << endl;
}

void CTriangle::Calc()
{
	float *length = new float[3];
	// 计算各边长
	length[0] = sqrt(pow((px[2] - px[1]), 2) + pow((py[2] - py[1]), 2));
	length[1] = sqrt(pow((px[1] - px[0]), 2) + pow((py[1] - py[0]), 2));
	length[2] = sqrt(pow((px[0] - px[2]), 2) + pow((py[0] - py[2]), 2));
	cout << "三角形 " << name << ", 周长为：" << length[0] + length[1] + length[2] << endl;
}

void CTriangle::saveToFile(ofstream& ofs)
{
	int len = strlen(name);
	ofs << shape << ' ' << px[0] << ' ' << py[0] << ' ' << px[1] << ' ' 
		<< py[1] << ' ' << px[2] << ' ' << py[2] << ' ' << len << endl;
	ofs << name << endl;
}

CTriangle& CTriangle::loadFromFile(ifstream& ifs)
{
	int len = 0;
	ifs >> px[0] >> py[0] >> px[1] >> py[1] >> px[2] >> py[2] >> len;
	len++;
	name = new char[len];
	while(ifs.get() != '\n'); // 跳过一行
	ifs.getline(name, len);
	return *this;
}