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

			
			//Проверяем поле чтобы в нем не было другого корабля
			if (doska->pol[x][y].getklet() == KOR)
			{
				continue;
			}

			//Работает только для однопалубников!!!
			//Проверяем соседние поля на наличие в них корабля, но до этого чтобы они не выходили за рамки массива
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

			//Если пройдены все этарации цикла и дошли до этого места значит корабль можно поставить
			break;
		} while (1);

		korabli[i]->setkoordinata(x, y);
		korabli[i]->setpalyba(NEPODBIT);
		korabli[i]->setkorabl(NEPODBIT);
		doska->pol[x][y].setklet(KOR);
	}
	imyapobeditelya = "Не известно";
};

void Igra::hod(Odnopalybnik* korabli[M], pole* doska, int x, int y)
{
	int i;
	sostoyanie per;//Дополнительная переменная

	doska->koorposlxoda = Ecran::bykvi[x] + to_string(y + 1);

	per = doska->pol[x][y].getklet();
	if (per == PUST)
	{
		doska->pol[x][y].setklet(PUSTPOD);
		doska->resposlxoda = "Мимо";
	}
	if ((per == PUSTPOD) || (per == KORPOD))
	{
		doska->resposlxoda = "Тоже мимо";
	}
	if (per == KOR)
	{
		doska->pol[x][y].setklet(KORPOD);
		for (i = 0; i < M; i++)
		{
			if ((x == korabli[i]->getkoordinataX()) && (y == korabli[i]->getkoordinataY()))
			{
				//Работает только для однопалубного корабля
				korabli[i]->setpalyba(PODBIT);
				korabli[i]->setkorabl(PODBIT);
				doska->resposlxoda = "Убит";
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
			//Продолжаем игру
			return 1;
		}
	}
	//Закончить игру
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

int Igra::scetchikXodov = 0; //Выделяем место в памяти для static переменной и инициализируем её
string Igra::igrokperviy;
string Igra::igrokvtoroy;