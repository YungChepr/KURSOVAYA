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
};

void Ecran::prorisovkapodvala(pole* doska)
{
	//����� �������
	cout << endl << endl << endl << endl;
	cout << OTST << "������� ��� ������: " << doska->imyapolya << endl;
	cout << OTST << "������� ���: " << doska->koorposlxoda << endl;
	cout << OTST << "���������:   " << doska->resposlxoda << endl;
	cout << endl;
}