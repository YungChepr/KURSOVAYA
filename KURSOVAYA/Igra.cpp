#include "Igra.h"
#include "Ecran.h"


void Igra::rasstanovka(Odnopalybnik* korabli[MMAX], pole* doska)
{
	int i;
	for (i = (M-1); i >=0; i--)
	{
		korabli[i]->ustanovkakorablya(doska);
	}
	imyapobeditelya = "Не известно";
};

void Igra::hod(Odnopalybnik* korabli[MMAX], pole* doska, int x, int y)
{
	int i;
	sostoyanie per;//Дополнительная переменная
	sost vspper;//Дополнительная переменная

	doska->koorposlxoda = Ecran::bykvi[x] + Ecran::tsifri[y];

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
		for (i = 0; i < M; i++) //Проходит по массиву кораблей чтобы найти тот в который мы попали
		{
			vspper = korabli[i]->proverkakorablya(x, y);
			if (vspper == UBIT)
			{
				doska->resposlxoda = "Убит";
				return;
			}
			if (vspper == PODBIT)
			{
				doska->resposlxoda = "Попал";
				return;
			}
			if (vspper == NEPODBIT)
			{
				//Ничего не делает, то есть проверяем следующий корабль
			}
		}
		cout << endl << "ПОДБИТЫЙ КОРАБЛЬ НЕ НАЙДЕН" << endl;
	}
	
};

int Igra::konecigry(Odnopalybnik* korabli[MMAX])
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