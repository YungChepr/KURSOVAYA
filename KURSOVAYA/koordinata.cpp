#include "koordinata.h"

using namespace std;

koordinata::koordinata() //�����������
{
	koordinataX = -1;
	koordinataY = -1;
};

void koordinata::getkoordinata(int* x, int* y) //��������� ���� ����������
{
	*(x) = koordinataX;
	*(y) = koordinataY;
};

void koordinata::setkoordinata(int x, int y) //��������� ���� ����������
{
	// �������� �� ����������� ���������� �������� ���������. ��� ������ ���� �� 0 �� N.
	try
	{
		if ((x < 0) || (x > (N-1)) || (y < 0) || (y > (N - 1)))
		{
			throw "������, ���������� �������";
		}
	}
	catch(const char* oshibka)
	{
		cout << oshibka << endl;
		cout <<  "X = " << x << " " << "Y = " << y << endl;
		
	}
	koordinataX = x;
	koordinataY = y;
};

int koordinata::getkoordinataX() //��������� ���� ����������
{
	return koordinataX;
};

int koordinata::getkoordinataY() //��������� ���� ����������
{
	return koordinataY;
};