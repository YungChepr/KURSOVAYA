#include "Ecran.h"

const string Ecran::symvoli[4] = { "  ","� ","+ ","x " }; //������� �������������� ���������� ������ ����

const string Ecran::bykvi[10] = { "a ","b ","c ","d ","e ","f ","g ","h ","j ","k " }; //������� �������������� ����������� �� Y

const string OTST = "          "; //������ ��� ������ ����� ������� 5 ��������

void Ecran::prorisovkashapki(pole* doska)
{
	cout << endl << endl << endl;
}

void Ecran::prorisovkapolya(pole* doska)
{

	int i,j; //�������

	//����� �����
	cout << endl << endl;

	cout << OTST << "�����: " << doska->imyapolya << endl;
	cout << endl;

	//����� ��������� ����
	cout << OTST << "  " << "1 2 3 4 5 6 7 8 9 10" << endl;
	for (i = 0; i < N; i++) 
	{
		cout << OTST << Ecran::bykvi[i];
		for (j = 0; j < N; j++)
		{
			cout << Ecran::symvoli[doska->pol[i][j].getklet()];
			
		}
		cout << Ecran::bykvi[i];
		cout << endl;
	}
	cout << OTST << "  " << "1 2 3 4 5 6 7 8 9 10" << endl;
	cout << endl << endl << endl << endl;

};

void Ecran::prorisovkapodvala(pole* doska)
{
	//����� �������
	cout << OTST << "���: " << doska->koorposlxoda << "   " << endl;
	cout << OTST << "���������:   " << doska->resposlxoda << "           " << endl; //������ ������ ���������� ����� ������� �����
	cout << OTST << "��������� ��� ������: " << doska->imyapolya << "                           " << endl;
	cout << endl;
}

void Ecran::prorisovkastroki(pole* doska, int x, int y, int nomerdoski)
{
	Ecran::set_cursor(0, 0);
	int delta;
	if (nomerdoski == 1)
	{
		delta = 0;
		Ecran::set_cursor((10 + 2 + 2 * y), (3 + 5 + x));
		cout << Ecran::symvoli[doska->pol[x][y].getklet()];

	}
	else
	{ //���� ����� ������ ��������� �� ����� �����
		delta = 20;
		Ecran::set_cursor((10 + 2 + 2 * y), (delta + 3 + 5 + x));
		cout << Ecran::symvoli[doska->pol[x][y].getklet()];
	}
	Ecran::set_cursor(0, (2*N + 23));
}

//�������� �� ���������
//��� ������� ����� �������� � ����� ����������� ����������
void Ecran::set_cursor(int x, int y) //������� ������������ �������
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}
