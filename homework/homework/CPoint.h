#pragma once
#include "shape.h"

// ����CPointΪVS�еı����������ʴ˴���CCPoint���棬�����������
class CCPoint :
	public CShape
{
public:
	// �޲�������
	CCPoint(void);
	// �в�������
	CCPoint(char*, float, float);
	// ��������
	~CCPoint(void);
	// ��������
	CCPoint(const CCPoint&);
	// ���������
	CCPoint operator+(float);
	// ��ʾ
	virtual void Draw();
	// �������ļ�
	virtual void saveToFile(ofstream&);
	// ���ļ���ȡ
	virtual CCPoint& loadFromFile(ifstream&);

private:
	float x;
	float y;
};

