#pragma once
#include "Header.h"

class Igrok
{
private:
	string imya;
	sostoyanie masproverky[N][N]; //������ ��������� �������� ������
public:
	Igrok(string imya);
	void vystrel(int* x, int* y, pole* doska);
	string getimya();
	
};