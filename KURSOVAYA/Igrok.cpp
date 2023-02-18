#include "Igrok.h"


Igrok::Igrok(string imya)
{
	fdobit = var1; //Нет корабля который нужно добивать
	napr = 0;  //Нет направления по которому стреляем
	ch = 0;
	xnach = -1; 
	ynach = -1;
	xpre = -1;
	ypre = -1;
	naprmimo[0] = 0;
	naprmimo[1] = 0;
	naprmimo[2] = 0;
	naprmimo[3] = 0;
	this->imya = imya;
	int i,j;
	for (i = 0; i < N; i++) //Инициализация массива сделанных выстрелов
	{
		for (j = 0; j < N; j++)
		{
			masproverky[i][j] = PUST;
		}
	}
};

void Igrok::vystrel(int* x, int* y, pole* doska) //Генерация поля в которое игрок стреляет
{   
	
	if ((doska->resposlxoda == "Попал") && (fdobit == var1)) //Первое попадание
	{
		fdobit = var2;
	}

	if ((doska->resposlxoda == "Попал") && (fdobit == var2)) //Второе попадание
	{
		fdobit = var3;
	}

	if ((doska->resposlxoda == "Попал") && (fdobit == var3)) //
	{
		fdobit = var3;
	}

	if ((doska->resposlxoda == "Попал") && ( fdobit == var3A)) //
	{
		fdobit = var3;
	}

	if (((doska->resposlxoda == "Мимо") || (doska->resposlxoda == "Тоже мимо")) && (fdobit == var2)) //Промах после первого попадания
	{
		fdobit = var3A;
	}

	if (((doska->resposlxoda == "Мимо") || (doska->resposlxoda == "Тоже мимо")) && (fdobit == var3)) //Промах после серии попаданий
	{
		fdobit = var4;
	}

	if (doska->resposlxoda == "Убит") //Если убили корабль
	{
		fdobit = var5;
	}
	
	if (fdobit == var5)
	{
		//Заново инициализируем переменные
		fdobit = var1; //Нет корабля который нужно добивать
		napr = 0;  //Нет направления по которому стреляем
		ch = 0;
		xnach = -1;
		ynach = -1;
		xpre = -1;
		ypre = -1;
		naprmimo[0] = 0;
		naprmimo[1] = 0;
		naprmimo[2] = 0;
		naprmimo[3] = 0;

		//Повторяем действия варианта 1
		do
		{
			*(x) = (int)((rand() / 32767.0) * (N));
			*(y) = (int)((rand() / 32767.0) * (N));
		} while (masproverky[*(x)][*(y)] == PUSTPOD);

		masproverky[*(x)][*(y)] = PUSTPOD;
		//Хранят результата последнего хода
		xnach = *(x);
		ynach = *(y);
	}

	if (fdobit == var4)
	{
		if (napr == 1)
		{
			napr = 2;
			xpre = xnach + 1;
		}
		if (napr == 2)
		{
			napr = 1;
			xpre = xnach - 1;
		}
		if (napr == 3)
		{
			napr = 4;
			ypre = ynach + 1;
		}
		if (napr == 4)
		{
			napr = 3;
			ypre = ynach - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
	}

	if (fdobit == var3A)
	{
		//Выбираем направление
		do {
			napr = (int)((rand() / 32767.0) * (3)) + 1; //Выбераем одно из 4-х направлений

			if ((napr == naprmimo[0]) || (napr == naprmimo[1]) || (napr == naprmimo[2]))
			{
				continue;
			}
			else
			{
				ch = ch + 1;
				naprmimo[ch] = napr;
				break;
			}
		}
		while (1);

		if (napr == 1)
		{
			xpre = xnach + 1;
		}
		if (napr == 2)
		{
			xpre = xnach - 1;
		}
		if (napr == 3)
		{
			ypre = ynach + 1;
		}
		if (napr == 4)
		{
			ypre = ynach - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
	}

	if (fdobit == var3)
	{
		if (napr == 1)
		{
			xpre = xpre + 1;
		}
		if (napr == 2)
		{
			xpre = xpre - 1;
		}
		if (napr == 3)
		{
			ypre = ypre + 1;
		}
		if (napr == 4)
		{
			ypre = ypre - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
	}

	if (fdobit == var2) 
	{
		//Выбираем направление
		napr = (int)((rand() / 32767.0) * (3)) + 1; //Выбераем одно из 4-х направлений
		naprmimo[ch] = napr;

		if (napr == 1)
		{
			xpre = xnach + 1;
		}
		if (napr == 2)
		{
			xpre = xnach - 1;
		}
		if (napr == 3)
		{
			ypre = ynach + 1;
		}
		if (napr == 4)
		{
			ypre = ynach - 1;
		}

		*(x) = xpre;
		*(y) = ypre;
	}

	
	if (fdobit == var1)
	{
		do 
		{
			*(x) = (int)((rand() / 32767.0) * (N));
			*(y) = (int)((rand() / 32767.0) * (N));
		} 
		while (masproverky[*(x)][*(y)] == PUSTPOD);

		masproverky[*(x)][*(y)] = PUSTPOD;
		//Хранят результата последнего хода
		xnach = *(x);
		ynach = *(y);

	}
};

string Igrok::getimya()
{
	return imya;
};