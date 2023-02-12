#include "Mnogopalybnik.h"

Mnogopalybnik::Mnogopalybnik() //По умолчанию создаем двухпалубный корабль
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
		cout << endl << "Не верное значение параметра k, создан двухпалбуный корабль!!!" << endl;
	}
};
//Перекрываю методы однопалубника
sost Mnogopalybnik::getpalyba()
{
	return Odnopalybnik::getpalyba();
};

void Mnogopalybnik::setpalyba(sost p)
{
	Odnopalybnik::setpalyba(p);
};

sost Mnogopalybnik::getkorabl()
{
	return Odnopalybnik::getkorabl();
};

void Mnogopalybnik::setkorabl(sost k)
{
	Odnopalybnik::setkorabl(k);
};