#pragma once
#include "kletka.h"

class Odnopalybnik: public kletka
{
private:
	sost palyba; //������ ���������� � ��������� ������ �������
	sost korabl; //������ ���������� � ��������� �������
public:
	Odnopalybnik();
	virtual sost getpalyba();
	virtual void setpalyba(sost p);
	virtual sost getkorabl();
	virtual void setkorabl(sost k);
};