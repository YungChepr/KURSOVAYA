#include "Odnopalybnik.h"
Odnopalybnik::Odnopalybnik() 
{
	palyba = NEUKAZANO;
	//korabl = NEUKAZANO;
};

sost Odnopalybnik::getpalyba()
{
	return palyba;
};

void Odnopalybnik::setpalyba(sost p)
{
	palyba = p;
};

sost Odnopalybnik::getkorabl()
{
	return palyba;
};

void Odnopalybnik::setkorabl(sost k)
{
	palyba = k;
};

 void Odnopalybnik::ustanovkakorablya(pole* doska)
 {
	 int x, y;

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
		 if ((x + 1) < N)
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

	 setkoordinata(x, y); //�����������
	 setpalyba(NEPODBIT);
	 setkorabl(NEPODBIT);
	 doska->pol[x][y].setklet(KOR);
 };

 sost Odnopalybnik::proverkakorablya(int x, int y)
 {
	 if ((x == getkoordinataX()) && (y == getkoordinataY()))
	 { 
		 setpalyba(PODBIT);
		 //setkorabl(PODBIT);
		 return UBIT;

	 }
	 else
	 {
		 return NEPODBIT;
	 }
	
 };
