#pragma once
#include "kletka.h"

class Odnopalybnik: public kletka
{
private:
	sost palyba; //������ ���������� � ��������� ������ �������
	sost korabl; //������ ���������� � ��������� �������
public:
	Odnopalybnik();
	sost getpalyba();
	void setpalyba(sost p);
	sost getkorabl();
	void setkorabl(sost k);
};