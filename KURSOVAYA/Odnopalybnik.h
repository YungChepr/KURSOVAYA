#pragma once
#include "kletka.h"

class Odnopalybnik: public kletka
{
private:
	sost palyba; //������ ���������� � ��������� ������ �������
public:
	Odnopalybnik();
	sost getpalyba();
	void setpalyba(sost s);
};