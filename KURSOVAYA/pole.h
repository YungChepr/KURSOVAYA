#pragma once
#include "kletka.h"
class pole 
{
public:
	string imyapolya; // ������ ����� ����� ������
	string koorposlxoda; // ������ ����� ���������� ���������� ����
	string resposlxoda; // ������ �����  ���������� ���������� ����
	kletka pol[N][N]; //������ ���������� � �������
	pole();
	void chistka(); //������ ����
};

