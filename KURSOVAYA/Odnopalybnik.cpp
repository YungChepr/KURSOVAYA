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


		 //ѕровер€ем поле чтобы в нем не было другого корабл€
		 if (doska->pol[x][y].getklet() == KOR)
		 {
			 continue;
		 }

		 //–аботает только дл€ однопалубников!!!
		 //ѕровер€ем соседние пол€ на наличие в них корабл€, но до этого чтобы они не выходили за рамки массива
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

		 //≈сли пройдены все этарации цикла и дошли до этого места значит корабль можно поставить
		 break;
	 } while (1);

	 setkoordinata(x, y); //ѕолиморфизм
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
