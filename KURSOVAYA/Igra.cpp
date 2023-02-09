#include "Igra.h"
#include "Ecran.h"


void Igra::rasstanovka(Odnopalybnik* korabli[M], pole* doska)
{

	korabli[0]->setkoordinata(0, 0);
	korabli[0]->setpalyba(NEPODBIT);
	korabli[0]->setkorabl(NEPODBIT);
	doska->pol[0][0].setklet(KOR);
	imyapobeditelya = "�� ��������";
};

void Igra::hod(Odnopalybnik* korabli[M], pole* doska, int x, int y)
{
	sostoyanie per;//�������������� ����������

	doska->koorposlxoda = Ecran::bykvi[x] + to_string(y + 1);

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
		//����� �� ������ ������ �� ������� ��������, �� �.�. � ��� ���� ������� �� ����� �� �������
		if ( ( x== korabli[0]->getkoordinataX() ) && (y == korabli[0]->getkoordinataY() ) )
		{
			korabli[0]->setpalyba(PODBIT);
			korabli[0]->setkorabl(PODBIT);
			doska->resposlxoda = "����";
		}

	}
	
};

int Igra::konecigry(Odnopalybnik* korabli[M])
{
	//��� ��� ���� ������� � ������� ����� for ���� ����
	if (korabli[0]->getkorabl() == NEPODBIT)
	{
		//���������� ����
		return 1;
	}
	else 
	{
		//��������� ����
		return 0;
	}
	
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