// ��������ͷ�ļ���ȫ�ֱ��������������������Լ�һЩ�궨��
#include "homework.h"

int main(void)
{
	arr = CShapeArray();
	// ѡ�������ѭ��
	inputOp();
	return 0;
}

// �������ֽ���ѡ��
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
			// ����cin״̬Ϊios_base::goodbit, 
			// ������뻺�����еĴ�������, 
			// ����������ĸ��ɵ���ѭ��
			cin.clear();
			cin.sync();
			cout << "����������������룡" << endl;
		}
	}
}

// ����
void clr()
{
	system("CLS");
}

// ��ͣ
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
                          ѡ�������\n\
        1.������״  2.��ѯ������  3.����        4.ճ��\n\
        5.ɾ��      6.�������ļ�  7.���ļ�����  8.�˳�\n\
-----------------------------------------------------------------", 8);
		switch(r) {
		case 1: // ������״
			inputShape();
			break;
		case 2: // ��ѯ������
			if(!arr.getSize()) {
				cout << "û�����ݣ�" << endl;
			} else {
				inputQuery();
			}
			break;
		case 3:	// ����
			inputCopy();
			break;
		case 4:	// ճ��
			inputPaste();
			break;
		case 5:	// ɾ��
			inputDel();
			break;
		case 6:	// �������ļ�
			saveToFile();
			break;
		case 7:	// ���ļ�����
			loadFromFile();
			break;
		case 8:	// �˳�
			exit(0);
		}
	}
}

void inputShape()
{
	clr();
	CShape *p;
	switch(input("ѡ����״��\n1.����  2.Բ��  3.�����  4.������  5.��  6.ֱ��", 6)) {
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
                         ��������ǣ�" << endl;
	p->Draw();
	cout <<
"-----------------------------------------------------------------\n" << endl;
	if(!p->exist()) {
		cout << "����״�����ڣ���ӷ�������" << endl;
	} else {
		arr.add(p);
	}
	pause();
}

void inputQuery()
{
	clr();
	switch(input("ѡ���ѯ��ʽ��  1.��λ�ò�ѯ  2.�����Ʋ�ѯ  3.��ʾȫ��", 3)) {
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
	cout << "����" << arr.getSize() << "���¼" << endl;
	arr.get(input("����λ�ò�ѯ��\n", arr.getSize()) - 1 )->Draw();
	pause();
}

void inputName()
{
	char *name = new char;
	clr();
	cout << "\n" << "�������Ʋ�ѯ��\n" << endl;
	getchar();
	gets(name);
	int r = arr.findByName(name);
	if(r == -1) {
		cout << "��������Ҳ������ݣ�" << endl;
	} else {
		arr.get(r)->Draw();
	}
	pause();
}

// ����
void inputCopy()
{
	clr();
	cout << "����" << arr.getSize() << "���¼" << endl;
	arr.drawAll();
	copyPos = input("����Ҫ���Ƶ���״����λ�ã�\n", arr.getSize()) - 1;
}

// ճ��
void inputPaste()
{
	clr();
	if(copyPos == -1) {
		cout << "�޷�ճ����" << endl;
	} else if(copyPos > arr.getSize()) {
		cout << "�Ҳ������" << endl;
	} else {
		cout << "����" << arr.getSize() << "���¼" << endl;
		int copyDst = input("����Ҫճ������λ�ã�\n", arr.getSize() + 1);
		arr.copy(copyPos , copyDst - 1);
		copyPos = -1;
		cout << "���Ƴɹ����ѽ���״��λ��" << copyPos << "���Ƶ�λ��" << copyDst << endl;
	}
	pause();
}

// ɾ��
void inputDel()
{
	clr();
	cout << "����" << arr.getSize() << "���¼" << endl;
	arr.drawAll();
	int delPos = input("����Ҫɾ������״����λ�ã�\n", arr.getSize());
	arr.del(delPos - 1);
	cout << "ɾ���ɹ����ѽ���״��λ��" << delPos << "ɾ����" << endl;
	pause();
}

// �������
CRectangle* inputRectangle()
{
	char *name = new char;
	clr();
	cout << "��������:" << endl;
	getchar();
	gets(name);
	float x1, x2, y1, y2;
	cout << "�������ԽǶ�������(x1, y1), (x2, y2)(�ÿո��س�����)��" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	return new CRectangle(name, x1, y1, x2, y2);
}

// ����Բ��
CCircle* inputCircle()
{
	float x, y, r;
	char *name = new char;
	clr();
	cout << "��������:" << endl;
	getchar();
	gets(name);
	cout << "����Բ������(x, y)���뾶r(�ÿո��س�����)��" << endl;
	cin >> x >> y >> r;
	return new CCircle(name, x, y, r);
}

// ��������
CPolygon* inputPolygon()
{
	char *name = new char;
	clr();
	cout << "��������:" << endl;
	getchar();
	gets(name);
	int edges;
	cout << "���������" << endl;
	cin >> edges;
	float *px = new float[edges];
	float *py = new float[edges];
	for(int i = 0; i < edges; i++) {
		cout << "�����" << i + 1 << "����������(x"<< i + 1 << ", y" << i + 1 << ")(�ÿո��س�����)��" << endl;
		cin >> px[i] >> py[i];
	}
	return new CPolygon(name, edges, px, py);
}

// ����������
CTriangle* inputTriangle()
{
	char *name = new char;
	clr();
	cout << "��������:" << endl;
	getchar();
	gets(name);
	int edges = 3;
	float *px = new float[edges];
	float *py = new float[edges];
	for(int i = 0; i < edges; i++) {
		cout << "�����" << i + 1 << "����������(x"<< i + 1 << ", y" << i + 1 << ")(�ÿո��س�����)��" << endl;
		cin >> px[i] >> py[i];
	}
	return new CTriangle(name, px, py);
}

// �����
CCPoint* inputPoint()
{
	char *name = new char;
	clr();
	cout << "��������:" << endl;
	getchar();
	gets(name);
	float x, y;
	cout << "��������(x, y)(�ÿո��س�����)��" << endl;
	cin >> x >> y;
	return new CCPoint(name, x, y);
}

// ����ֱ��
CLine* inputLine()
{
	char *name = new char;
	clr();
	cout << "��������:" << endl;
	getchar();
	gets(name);
	float x1, y1, x2, y2;
	cout << "����ֱ�߾�������������(x1, y1), (x2, y2)(�ÿո��س�����)��" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	return new CLine(name, x1, y1, x2, y2);
}

// �������ļ�
void saveToFile()
{
	ofstream fs(fname);
	int num = arr.getSize();
	fs << num << endl;
	for(int i = 0; i != num; i++) {
		arr.get(i)->saveToFile(fs);
	}
	fs.close();
	cout << "�ѱ�����" << fname << endl;
	pause();
}

// ���ļ�����
void loadFromFile()
{
	arr.clear();
	ifstream fs("D:\\dat.txt", ios::in);
	if(!fs.good()) {
		// ���������˳�
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
			// ���������˳�
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
			// ���������˳�
			cout << "Error!" << endl;
			pause();
			return;
		}
		s->loadFromFile(fs);
		arr.add(s);
	}
	fs.close();
	cout << "�Ѵ�" << fname << "��ȡ���" << endl;
	pause();
}