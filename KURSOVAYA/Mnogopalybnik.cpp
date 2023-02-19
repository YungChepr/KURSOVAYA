#include "Mnogopalybnik.h"

Mnogopalybnik::Mnogopalybnik() //ѕо умолчанию создаем двухпалубный корабль
{
	kolpalyb = 2;
	int i;
	for (i = 0; i < kolpalyb; i++)
	{
		bolkorabl[i] = new Odnopalybnik();
	}
};

Mnogopalybnik::Mnogopalybnik(int k)
{
	if (1 < k <= 4)
	{
		kolpalyb = k;
		int i;
		for (i = 0; i < kolpalyb; i++)
		{
			bolkorabl[i] = new Odnopalybnik();
		}
	}
	else
	{
		kolpalyb = 2;
		int i;
		for (i = 0; i < kolpalyb; i++)
		{
			bolkorabl[i] = new Odnopalybnik();
		}
		cout << endl << "Ќе верное значение параметра k, создан двухпалбуный корабль!!!" << endl;
	}
};

//ѕерекрываю методы однопалубника
/*sost Mnogopalybnik::getpalyba()
{
	return Odnopalybnik::getpalyba();
};

void Mnogopalybnik::setpalyba(sost p)
{
	Odnopalybnik::setpalyba(p);
};
*/
sost Mnogopalybnik::getkorabl()
{
	int i;
	for (i = 0; i < kolpalyb; i++)
	{
		if (bolkorabl[i]->getpalyba() == NEPODBIT)
		{
			return NEPODBIT;
		}
	}
 	return UBIT;
};

/*void Mnogopalybnik::setkorabl(sost k)
{
	Odnopalybnik::setkorabl(k);
}; */

void Mnogopalybnik::ustanovkakorablya(pole* doska)
{
	int x,y, xk[4], yk[4], napr, kolpopytok,i; //¬ массиве лежит максимум 4 координаты дл€ 4х-палубника
	
	kolpopytok = 0;
	do
	{
	//ѕроверка не более 1000 попыток расстановки корабл€
	kolpopytok = kolpopytok + 1;
	if (kolpopytok > 1000)
	{
		//≈сли сделано 1000 попыток корабль поставить нельз€
		cout << endl << "ƒостигнуто ограничение количества попыток расстановки корабл€.  орабль поставить не удалось!!!" << endl;
		break;
	}

	x = (int)((rand() / 32767.0) * (N));
	y = (int)((rand() / 32767.0) * (N));
	napr = (int)((rand() / 32767.0) * (3)) + 1; //¬ыбераем одно из 4-х направлений

	for (i = 0; i < kolpalyb; i++)
	{
		//ѕровер€ем поле чтобы в нем не было другого корабл€
		if (doska->pol[x][y].getklet() == KOR)
		{
			break;
		}

		//ѕровер€ем соседние пол€ на наличие в них корабл€, но до этого чтобы они не выходили за рамки массива
		if ((x + 1) < N)
		{
			if (doska->pol[x + 1][y].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			break;
		}

		if (((x + 1) < N) && ((y + 1) < N))
		{
			if (doska->pol[x + 1][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			break;
		}

		if ((y + 1) < N)
		{
			if (doska->pol[x][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			break;
		}

		if (((x - 1) >= 0) && ((y + 1) < N))
		{
			if (doska->pol[x - 1][y + 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			break;
		}

		if (((x - 1) >= 0))
		{
			if (doska->pol[x - 1][y].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			break;
		}

		if (((x - 1) >= 0) && ((y - 1) >= 0))
		{
			if (doska->pol[x - 1][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			break;
		}

		if (((y - 1) >= 0))
		{
			if (doska->pol[x][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			break;
		}

		if (((x + 1) < N) && ((y - 1) >= 0))
		{
			if (doska->pol[x + 1][y - 1].getklet() == KOR)
			{
				break;
			}
		}
		else
		{
			break;
		}
		//—охран€ем подход€щие координаты многопалубника в массив
		xk[i] = x; 
		yk[i] = y;

		if (napr == 1)
		{
			x = x + 1;
		}
		if (napr == 2)
		{
			x = x - 1;
		}
		if (napr == 3)
		{
			y = y + 1;
		}
		if (napr == 4)
		{
			y = y - 1;
		}
	}
	if (i == kolpalyb)
	{
		//≈сли дошел до kolpalyb итерации цикла то удалось поставить корабль
		break;
	}
	} while (1);

	for (i = 0; i < kolpalyb; i++)
	{
		bolkorabl[i]->setkoordinata(xk[i], yk[i]); 
		bolkorabl[i]->setpalyba(NEPODBIT);
		doska->pol[xk[i]][yk[i]].setklet(KOR);
	}
	//setkorabl(NEPODBIT);
};

sost Mnogopalybnik::proverkakorablya(int x, int y)//—прашивает корабль попали ли в него
{
	int i;
	sost res = NEPODBIT;
	for (i = 0; i < kolpalyb; i++)
	{
		if ((x == bolkorabl[i]->getkoordinataX()) && (y == bolkorabl[i]->getkoordinataY()))
		{
			bolkorabl[i]->setpalyba(PODBIT);
			res = PODBIT;
		}
	}

	if (getkorabl() == UBIT)
	{
		res = UBIT;
	}
	
	return res;
}; 