#pragma once

class koordinata
{
private:
	int koordinataX; //���������� �� �����������
	int koordinataY; //���������� �� ���������

public:
	//������� � ����������� ��� � ����� ��������
	void getkoordinata(int *x, int *y); //��������� ���� ����������
	void setkoordinata(int x, int y); //��������� ���� ����������

	int getkoordinataX(); //��������� X	
	int getkoordinataY(); //��������� Y ��� ������ �� �����
	
};