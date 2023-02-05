#include "Igra.h"
#include "Ecran.h"


void Igra::rasstanovka(Odnopalybnik* korabli[M], pole* doska)
{

	korabli[0]->setkoordinata(0, 0);
	korabli[0]->setpalyba(NEPODBIT);
	korabli[0]->setkorabl(NEPODBIT);
	doska->pol[0][0].setklet(KOR);
	imyapobeditelya = "Не известно";
};

void Igra::hod(Odnopalybnik* korabli[M], pole* doska, int x, int y)
{
	sostoyanie per;//Дополнительная переменная

	doska->koorposlxoda = Ecran::bykvi[x] + to_string(y + 1);

	per = doska->pol[x][y].getklet();
	if (per == PUST)
	{
		doska->pol[x][y].setklet(PUSTPOD);
	}
	if ((per == PUSTPOD) || (per == KORPOD))
	{

	}
	if (per == KOR)
	{
		doska->pol[x][y].setklet(KORPOD);
		//Сдесь мы должны пройти по массиву кораблей, но т.к. у нас один корабль то этого не сделали
		if ( ( x== korabli[0]->getkoordinataX() ) && (y == korabli[0]->getkoordinataY() ) )
		{
			korabli[0]->setpalyba(PODBIT);
			korabli[0]->setkorabl(PODBIT);
		}

	}
	doska->resposlxoda = "Убит";
	//Реализовать проверку результата хода и присвоить resposlxoda 
	//Сделать массив в экране в результатами "Не попал" "Попал" и "Убил"
};

int Igra::konecigry(Odnopalybnik* korabli[M])
{
	//Так как один элемент в массиве цикла for пока нету
	if (korabli[0]->getkorabl() == NEPODBIT)
	{
		//Продолжаем игру
		return 1;
	}
	else 
	{
		//Закончить игру
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