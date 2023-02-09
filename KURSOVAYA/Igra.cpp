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
		doska->resposlxoda = "Мимо";
	}
	if ((per == PUSTPOD) || (per == KORPOD))
	{
		doska->resposlxoda = "Тоже мимо";
	}
	if (per == KOR)
	{
		doska->pol[x][y].setklet(KORPOD);
		//Сдесь мы должны пройти по массиву кораблей, но т.к. у нас один корабль то этого не сделали
		if ( ( x== korabli[0]->getkoordinataX() ) && (y == korabli[0]->getkoordinataY() ) )
		{
			korabli[0]->setpalyba(PODBIT);
			korabli[0]->setkorabl(PODBIT);
			doska->resposlxoda = "Убит";
		}

	}
	
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

int Igra::scetchikXodov = 0; //Выделяем место в памяти для static переменной и инициализируем её