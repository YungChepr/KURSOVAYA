#pragma once
#include "kletka.h"
#include "pole.h"


class Odnopalybnik: public kletka
{
private:
	sost palyba;//������ ���������� � ��������� ������ �������
	//sost korabl; //������ ���������� � ��������� �������
public:
	Odnopalybnik();
	virtual void ustanovkakorablya(pole* doska); //��������� �� ���� �������������
	virtual sost getpalyba(); //getpalyba �� ����� ��������������
	virtual void setpalyba(sost p);//setpalyiba �� ����� ��������������
	virtual sost proverkakorablya(int x, int y); //���������� ������� ������ �� � ����
	virtual sost getkorabl();
	virtual void setkorabl(sost k);
};