#include "Polygon.h"


CPolygon::CPolygon(void)
{
	shape = SHAPE_POLYGON;
	name = "多边形";
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

CPolygon::CPolygon(char *name, int edges, float *px, float *py)
{
	shape = SHAPE_POLYGON;
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->edges = edges;
	this->px = new float[edges];
	this->py = new float[edges];
	for(int i = 0; i < edges; i++) {
		this->px[i] = px[i];
		this->py[i] = py[i];
	}
}

CPolygon::CPolygon(const CPolygon& src)
{
	shape = SHAPE_POLYGON;
	name = new char[strlen(src.name)];
	strcpy(name, src.name);
	edges = src.edges;
	this->px = new float[edges];
	this->py = new float[edges];
	for(int i = 0; i < edges; i++) {
		this->px[i] = src.px[i];
		this->py[i] = src.py[i];
	}
}

CPolygon::~CPolygon(void)
{
	delete[] name;
}

CPolygon CPolygon::operator+(float f)
{
	for(int i = 0; i < edges; i++)
		px[i] += f;
	return *this;
}

void CPolygon::Draw()
{
	cout << edges << "边形 " << name << ", 顶点分别为:" << endl;
	for(int i = 0; i < edges; i++)
		cout << "\t(" << px[i] << ", " << py[i] << ")" << endl;
}

void CPolygon::Calc()
{
	float *length = new float[edges];
	float lengthAll = 0;
	// 计算各边长
	for(int i = 0; i < edges; i++) {
		if(i == 0) {
			length[i] = sqrt( pow((px[edges] - px[0]),2) + pow((py[edges] - py[0]),2) );
		} else {
			length[i] = sqrt( pow((px[i + 1] - px[i]),2) + pow((py[i + 1] - py[i]),2) );
		}
		lengthAll += length[i];
	}
	cout << "多边形 " << name << ", 周长为：" << lengthAll << endl;
}

void CPolygon::saveToFile(ofstream& ofs)
{
	int len = strlen(name);
	ofs << shape << ' ' << edges << ' ';
	for(int i = 0; i < edges; i++)
		ofs << px[i] << ' ' << py[i] << ' ';
	ofs << len << endl;
	ofs << name << endl;
}

CPolygon& CPolygon::loadFromFile(ifstream& ifs)
{
	ifs >> edges;
	cout << edges << endl;
	px = new float[edges];
	py = new float[edges];
	for(int i = 0; i < edges; i++) {
		ifs >> px[i];
		ifs >> py[i];
	}
	int len = 0;
	ifs >> len;
	len++;
	name = new char[len];
	while(ifs.get() != '\n'); // 跳过一行
	ifs.getline(name, len);
	return *this;
}

int CPolygon::exist()
{
	// 此函数没有考虑输入的点重合时的情况
	float *length = new float[edges];
	float lengthAll = 0;
	// 计算各边长
	for(int i = 0; i < edges; i++) {
		if(i == 0) {
			length[i] = sqrt(pow((px[edges - 1] - px[0]), 2) + pow((py[edges - 1] - py[0]), 2));
		} else {
			length[i] = sqrt(pow((px[i - 1] - px[i]), 2) + pow((py[i - 1] - py[i]), 2));
		}
		lengthAll += length[i];
	}
	float lengthHalf = lengthAll / 2.0f;
	// 如果一边之长大于等于其他所有边之和，即该边长大于等于全长的一半，多边形不存在
	for(int i = 0; i < edges; i++) {
		if(length[i] >= lengthHalf)
			return 0;
	}
	return 1;
}