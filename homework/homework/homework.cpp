// 包含其他头文件，全局变量声明，函数声明，以及一些宏定义
#include "homework.h"

int main(void)
{
	arr = CShapeArray();
	// 选择操作主循环
	inputOp();
	return 0;
}

// 输入数字进行选择
int input(char *promote, int choices)
{
	while(1) {
		cout << "\n" << promote << endl;
		int x;
		cin >> x;
		if(x > 0 && x <= choices) {
			return x;
		} else {
			clr();
			// 重置cin状态为ios_base::goodbit, 
			// 清空输入缓冲区中的错误数据, 
			// 避免输入字母造成的死循环
			cin.clear();
			cin.sync();
			cout << "输入错误，请重新输入！" << endl;
		}
	}
}

// 清屏
void clr()
{
	system("CLS");
}

// 暂停
void pause()
{
	system("PAUSE");
}

void inputOp()
{
	int r;
	while(1) {
		clr();
		r = input(
"-----------------------------------------------------------------\n\
                          选择操作：\n\
        1.输入形状  2.查询已输入  3.复制        4.粘贴\n\
        5.删除      6.保存至文件  7.从文件读入  8.退出\n\
-----------------------------------------------------------------", 8);
		switch(r) {
		case 1: // 输入形状
			inputShape();
			break;
		case 2: // 查询已输入
			if(!arr.getSize()) {
				cout << "没有数据！" << endl;
			} else {
				inputQuery();
			}
			break;
		case 3:	// 复制
			inputCopy();
			break;
		case 4:	// 粘贴
			inputPaste();
			break;
		case 5:	// 删除
			inputDel();
			break;
		case 6:	// 保存至文件
			saveToFile();
			break;
		case 7:	// 从文件读入
			loadFromFile();
			break;
		case 8:	// 退出
			exit(0);
		}
	}
}

void inputShape()
{
	clr();
	CShape *p;
	switch(input("选择形状：\n1.矩形  2.圆形  3.多边形  4.三角形  5.点  6.直线", 6)) {
	case 1:
		p = inputRectangle();
		break;
	case 2:
		p = inputCircle();
		break;
	case 3:
		p = inputPolygon();
		break;
	case 4:
		p = inputTriangle();
		break;
	case 5:
		p = inputPoint();
		break;
	case 6:
		p = inputLine();
		break;
	}
	cout << 
"-----------------------------------------------------------------\n\
                         您输入的是：" << endl;
	p->Draw();
	cout <<
"-----------------------------------------------------------------\n" << endl;
	if(!p->exist()) {
		cout << "该形状不存在！添加发生错误！" << endl;
	} else {
		arr.add(p);
	}
	pause();
}

void inputQuery()
{
	clr();
	switch(input("选择查询方式：  1.按位置查询  2.按名称查询  3.显示全部", 3)) {
	case 1:
		inputPos();
		break;
	case 2:
		inputName();
		break;
	case 3:
		arr.drawAll();
		pause();
		break;
	}
}

void inputPos()
{
	clr();
	cout << "共有" << arr.getSize() << "项纪录" << endl;
	arr.get(input("输入位置查询：\n", arr.getSize()) - 1 )->Draw();
	pause();
}

void inputName()
{
	char *name = new char;
	clr();
	cout << "\n" << "输入名称查询：\n" << endl;
	getchar();
	gets(name);
	int r = arr.findByName(name);
	if(r == -1) {
		cout << "输入错误，找不到数据！" << endl;
	} else {
		arr.get(r)->Draw();
	}
	pause();
}

// 复制
void inputCopy()
{
	clr();
	cout << "共有" << arr.getSize() << "项纪录" << endl;
	arr.drawAll();
	copyPos = input("输入要复制的形状所在位置：\n", arr.getSize()) - 1;
}

// 粘贴
void inputPaste()
{
	clr();
	if(copyPos == -1) {
		cout << "无法粘贴！" << endl;
	} else if(copyPos > arr.getSize()) {
		cout << "找不到该项！" << endl;
	} else {
		cout << "共有" << arr.getSize() << "项纪录" << endl;
		int copyDst = input("输入要粘贴到的位置：\n", arr.getSize() + 1);
		arr.copy(copyPos , copyDst - 1);
		copyPos = -1;
		cout << "复制成功！已将形状从位置" << copyPos << "复制到位置" << copyDst << endl;
	}
	pause();
}

// 删除
void inputDel()
{
	clr();
	cout << "共有" << arr.getSize() << "项纪录" << endl;
	arr.drawAll();
	int delPos = input("输入要删除的形状所在位置：\n", arr.getSize());
	arr.del(delPos - 1);
	cout << "删除成功！已将形状从位置" << delPos << "删除！" << endl;
	pause();
}

// 输入矩形
CRectangle* inputRectangle()
{
	char *name = new char;
	clr();
	cout << "输入名称:" << endl;
	getchar();
	gets(name);
	float x1, x2, y1, y2;
	cout << "输入两对角顶点坐标(x1, y1), (x2, y2)(用空格或回车隔开)：" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	return new CRectangle(name, x1, y1, x2, y2);
}

// 输入圆形
CCircle* inputCircle()
{
	float x, y, r;
	char *name = new char;
	clr();
	cout << "输入名称:" << endl;
	getchar();
	gets(name);
	cout << "输入圆心坐标(x, y)及半径r(用空格或回车隔开)：" << endl;
	cin >> x >> y >> r;
	return new CCircle(name, x, y, r);
}

// 输入多边形
CPolygon* inputPolygon()
{
	char *name = new char;
	clr();
	cout << "输入名称:" << endl;
	getchar();
	gets(name);
	int edges;
	cout << "输入边数：" << endl;
	cin >> edges;
	float *px = new float[edges];
	float *py = new float[edges];
	for(int i = 0; i < edges; i++) {
		cout << "输入第" << i + 1 << "个顶点坐标(x"<< i + 1 << ", y" << i + 1 << ")(用空格或回车隔开)：" << endl;
		cin >> px[i] >> py[i];
	}
	return new CPolygon(name, edges, px, py);
}

// 输入三角形
CTriangle* inputTriangle()
{
	char *name = new char;
	clr();
	cout << "输入名称:" << endl;
	getchar();
	gets(name);
	int edges = 3;
	float *px = new float[edges];
	float *py = new float[edges];
	for(int i = 0; i < edges; i++) {
		cout << "输入第" << i + 1 << "个顶点坐标(x"<< i + 1 << ", y" << i + 1 << ")(用空格或回车隔开)：" << endl;
		cin >> px[i] >> py[i];
	}
	return new CTriangle(name, px, py);
}

// 输入点
CCPoint* inputPoint()
{
	char *name = new char;
	clr();
	cout << "输入名称:" << endl;
	getchar();
	gets(name);
	float x, y;
	cout << "输入坐标(x, y)(用空格或回车隔开)：" << endl;
	cin >> x >> y;
	return new CCPoint(name, x, y);
}

// 输入直线
CLine* inputLine()
{
	char *name = new char;
	clr();
	cout << "输入名称:" << endl;
	getchar();
	gets(name);
	float x1, y1, x2, y2;
	cout << "输入直线经过的两点坐标(x1, y1), (x2, y2)(用空格或回车隔开)：" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	return new CLine(name, x1, y1, x2, y2);
}

// 保存至文件
void saveToFile()
{
	ofstream fs(fname);
	int num = arr.getSize();
	fs << num << endl;
	for(int i = 0; i != num; i++) {
		arr.get(i)->saveToFile(fs);
	}
	fs.close();
	cout << "已保存至" << fname << endl;
	pause();
}

// 从文件加载
void loadFromFile()
{
	arr.clear();
	ifstream fs("D:\\dat.txt", ios::in);
	if(!fs.good()) {
		// 发生错误，退出
		cout << "Error!" << endl;
		pause();
		return;
	}
	CShape *s;
	int shape;
	int num = 0;
	fs >> num;
	for(int i = 0; i < num; i++) {
		if(fs.eof()) {
			// 发生错误，退出
			cout << "Error!" << endl;
			pause();
			return;
		}
		shape = -1;
		fs >> shape;
		switch(shape) {
		case CShape::SHAPE_CIRCLE:
			s = new CCircle();
			break;
		case CShape::SHAPE_LINE:
			s = new CLine();
			break;
		case CShape::SHAPE_POINT:
			s = new CCPoint();
			break;
		case CShape::SHAPE_POLYGON:
			s = new CPolygon();
			break;
		case CShape::SHAPE_RECTANGLE:
			s = new CRectangle();
			break;
		case CShape::SHAPE_TRIANGLE:
			s = new CTriangle();
			break;
		default:
			// 发生错误，退出
			cout << "Error!" << endl;
			pause();
			return;
		}
		s->loadFromFile(fs);
		arr.add(s);
	}
	fs.close();
	cout << "已从" << fname << "读取完成" << endl;
	pause();
}