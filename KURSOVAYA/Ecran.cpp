#include "Ecran.h"

const string Ecran::symvoli[4] = { "  ","� ","+ ","x " }; //������� �������������� ���������� ������ ����

const string Ecran::bykvi[10] = { "a ","b ","c ","d ","e ","f ","g ","h ","j ","k " }; //������� �������������� ����������� �� Y

const string OTST = "          "; //������ ��� ������ ����� ������� 5 ��������


void Ecran::prorisovka(pole* doska)
{

	int i,j; //�������

	//����� �����
	cout << endl << endl << endl;
	cout << OTST <<  " ����� 1 " << endl;
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

	//����� �������
	cout << endl;
	cout << OTST  << "������� ���: " << "a 1  " << endl;
	cout << OTST  << "���������:   " << "�����" << endl;
	cout << endl;
};