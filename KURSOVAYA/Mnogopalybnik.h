#pragma once
#include "Odnopalybnik.h"

class Mnogopalybnik : public Odnopalybnik
{
private: 
	Odnopalybnik* bolkorabl[4]; //������������� ��� ������ ��������������
	int kolpalyb;	//������ ���������� �����
public:
	Mnogopalybnik(); //�� ��������� ��������� ������������ �������
	Mnogopalybnik(int k); //����������� � ���������� ���������� �����
	//sost getpalyba(); //�������� ������ �������������
	//void setpalyba(sost p);
	sost getkorabl();
	//void setkorabl(sost k);
	void ustanovkakorablya(pole* doska); //��������� �� ���� ��������������
	sost proverkakorablya(int x, int y); //���������� ������� ������ �� � ����
};

