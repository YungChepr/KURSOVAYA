#pragma once
#include "kletka.h"
class pole 
{
private:
	string imyapolya; // ������ ��� ������
public:
	kletka pol[N][N]; //������ ���������� � �������
	pole();
	void chistka(); //������ ����
	void ystanovkaimeni(); //������������� ��� ������
};

