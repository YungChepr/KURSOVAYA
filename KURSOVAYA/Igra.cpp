#include "Igra.h"
#include "Ecran.h"


void Igra::rasstanovka(Odnopalybnik* korabli[MMAX], pole* doska)
{
	int i;
	for (i = (M-1); i >=0; i--)
	{
		korabli[i]->ustanovkakorablya(doska);
	}
	imyapobeditelya = "�� ��������";
};

void Igra::hod(Odnopalybnik* korabli[MMAX], pole* doska, int x, int y)
{
	int i;
	sostoyanie per;//�������������� ����������
	sost vspper;//�������������� ����������

	doska->koorposlxoda = Ecran::bykvi[x] + Ecran::tsifri[y];

	per = doska->pol[x][y].getklet();
	if (per == PUST)
	{
		doska->pol[x][y].setklet(PUSTPOD);
		doska->resposlxoda = "����";
	}
	if ((per == PUSTPOD) || (per == KORPOD))
	{
		doska->resposlxoda = "���� ����";
	}
	if (per == KOR)
	{
		doska->pol[x][y].setklet(KORPOD);
		for (i = 0; i < M; i++) //�������� �� ������� �������� ����� ����� ��� � ������� �� ������
		{
			vspper = korabli[i]->proverkakorablya(x, y);
			if (vspper == UBIT)
			{
				doska->resposlxoda = "����";
				return;
			}
			if (vspper == PODBIT)
			{
				doska->resposlxoda = "�����";
				return;
			}
			if (vspper == NEPODBIT)
			{
				//������ �� ������, �� ���� ��������� ��������� �������
			}
		}
		cout << endl << "�������� ������� �� ������" << endl;
	}
	
};

int Igra::konecigry(Odnopalybnik* korabli[MMAX])
{
	int i;

	for (i = 0; i < M; i++)
	{
		if (korabli[i]->getkorabl() == NEPODBIT)
		{
			//���������� ����
			return 1;
		}
	}
	//��������� ����
	return 0;
	
}

string Igra::getimyapobeditelya()
{
	return imyapobeditelya;
};

void Igra::setimyapobeditelya(string imyapobeditelya)
{
	this->imyapobeditelya = imyapobeditelya;
};

int Igra::scetchikXodov = 0; //�������� ����� � ������ ��� static ���������� � �������������� �
string Igra::igrokperviy;
string Igra::igrokvtoroy;