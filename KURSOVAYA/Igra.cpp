#include "Igra.h"
#include "Ecran.h"


void Igra::rasstanovka(Odnopalybnik* korabli[M], pole* doska)
{
	int i,x,y;
	for (i = 0; i < M; i++)
	{
		do
		{
			x = (int)((rand() / 32767.0) * (N));
			y = (int)((rand() / 32767.0) * (N));

			
			//��������� ���� ����� � ��� �� ���� ������� �������
			if (doska->pol[x][y].getklet() == KOR)
			{
				continue;
			}

			//�������� ������ ��� ��������������!!!
			//��������� �������� ���� �� ������� � ��� �������, �� �� ����� ����� ��� �� �������� �� ����� �������
			if((x + 1) < N)
			{
				if (doska->pol[x + 1][y].getklet() == KOR)
				{
					continue;
				}
			}
			
			if (((x + 1) < N) && ((y + 1) < N))
			{
				if (doska->pol[x + 1][y + 1].getklet() == KOR)
				{
					continue;
				}
			}

			if ((y + 1) <= N)
			{
				if (doska->pol[x][y + 1].getklet() == KOR)
				{
					continue;
				}
			}

			if (((x - 1) >= 0) && ((y + 1) < N))
			{
				if (doska->pol[x - 1][y + 1].getklet() == KOR)
				{
					continue;
				}
			}

			if (((x - 1) >= 0))
			{
				if (doska->pol[x - 1][y].getklet() == KOR)
				{
					continue;
				}
			}

			if (((x - 1) >= 0) && ((y - 1) >= 0))
			{
				if (doska->pol[x - 1][y - 1].getklet() == KOR)
				{
					continue;
				}
			}

			if (((y - 1) >= 0))
			{
				if (doska->pol[x][y - 1].getklet() == KOR)
				{
					continue;
				}
			}

			if (((x + 1) < N) && ((y - 1) >= 0))
			{
				if (doska->pol[x + 1][y - 1].getklet() == KOR)
				{
					continue;
				}
			}

			//���� �������� ��� �������� ����� � ����� �� ����� ����� ������ ������� ����� ���������
			break;
		} while (1);

		korabli[i]->setkoordinata(x, y);
		korabli[i]->setpalyba(NEPODBIT);
		korabli[i]->setkorabl(NEPODBIT);
		doska->pol[x][y].setklet(KOR);
	}
	imyapobeditelya = "�� ��������";
};

void Igra::hod(Odnopalybnik* korabli[M], pole* doska, int x, int y)
{
	int i;
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
		for (i = 0; i < M; i++)
		{
			if ((x == korabli[i]->getkoordinataX()) && (y == korabli[i]->getkoordinataY()))
			{
				//�������� ������ ��� ������������� �������
				korabli[i]->setpalyba(PODBIT);
				korabli[i]->setkorabl(PODBIT);
				doska->resposlxoda = "����";
			}
		}

	}
	
};

int Igra::konecigry(Odnopalybnik* korabli[M])
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