#pragma once
#include "Header.h"
#include "pole.h"

class Igrok
{
private:
	string imya;
	sostoyanie masproverky[N][N]; //������ ��������� �������� ������
	varianti fdobit; //������ ��� ������� �������
	int napr; //����������� ��������� �� ��������� �������
	int xnach, ynach, xpre, ypre, naprmimo[4], ch; //���������� ��� ��������� ������� �������
public:
	Igrok(string imya);
	void vystrel(int* x, int* y, pole* doska);
	string getimya();
	
};