#pragma once
#include "Header.h"

class koordinata
{
private:
	int koordinataX; //���������� �� �����������
	int koordinataY; //���������� �� ���������

public:
	koordinata();
	//������� � ����������� ��� � ����� ��������
	void getkoordinata(int *x, int *y); //��������� ���� ����������
	void setkoordinata(int x, int y); //��������� ���� ����������

	int getkoordinataX(); //��������� X	
	int getkoordinataY(); //��������� Y ��� ������ �� �����
	
};