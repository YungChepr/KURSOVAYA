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
	else
	{
		if ((doska->resposlxoda == "Попал") && (fdobit == var2)) //Второе попадание
		{
			fdobit = var3;
		}
		else
		{
			if ((doska->resposlxoda == "Попал") && (fdobit == var3)) //
			{
				fdobit = var3;
			}
			else
			{
				if ((doska->resposlxoda == "Попал") && (fdobit == var3A)) //
				{
					fdobit = var3;
				}
				else
				{
					if (((doska->resposlxoda == "Мимо") || (doska->resposlxoda == "Тоже мимо")) && (fdobit == var2)) //Промах после первого попадания
					{
						fdobit = var3A;
					}
					else
					{
						if (((doska->resposlxoda == "Мимо") || (doska->resposlxoda == "Тоже мимо")) && (fdobit == var3)) //Промах после серии попаданий
						{
							fdobit = var4;
						}
						else
						{
							if (doska->resposlxoda == "Убит") //Если убили корабль
							{
								fdobit = var5;
							}
						}
					}
				}
			}
		}
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
			*(x) = round(((double) rand() / 32767) * ((N - 1) - 0) + 0);
			*(y) = round(((double) rand() / 32767) * ((N - 1) - 0) + 0);
		} while (masproverky[*(x)][*(y)] == PUSTPOD);
		masproverky[*(x)][*(y)] = PUSTPOD;

		//Хранят результата последнего хода
		xnach = *(x);
		ynach = *(y); 
		xpre = xnach;
		ypre = ynach;

		return;
	}

	if (fdobit == var3A)
	{
		//Выбираем направление
		do {
			napr = round(((double) rand() / 32767) * (4-1) + 1); //Выбераем одно из 4-х направлений

			if ((napr == naprmimo[0]) || (napr == naprmimo[1]) || (napr == naprmimo[2]))
			{
				continue;
			}
			else
			{
				if ((napr == 1) && (!((xnach + 1) < N)))
				{
					continue;
				}
				if ((napr == 2) && (!((xnach - 1) >= 0)))
				{
					continue;
				}
				if ((napr == 3) && (!((ynach + 1) < N)))
				{
					continue;
				}
				if ((napr == 4) && (!((ynach - 1) >= 0)))
				{
					continue;
				}

				ch = ch + 1;
				naprmimo[ch] = napr;
				break;
			}
		}
		while (1);

		if (napr == 1)
		{
			xpre = xnach + 1;
			ypre = ynach;
		}
		else
		{
			if (napr == 2)
			{
				xpre = xnach - 1;
				ypre = ynach;
			}
			else
			{
				if (napr == 3)
				{
					ypre = ynach + 1;
					xpre = xnach;
				}
				else
				{
					if (napr == 4)
					{
						ypre = ynach - 1;
						xpre = xnach;
					}
				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	if (fdobit == var3)
	{
		if ((napr == 1) && ((xpre + 1) < N))
		{
			xpre = xpre + 1;
		}
		else
		{
			if ((napr == 2) && ((xpre - 1) >= 0))
			{
				xpre = xpre - 1;
			}
			else {
				if ((napr == 3) && ((ypre + 1) < N))
				{
					ypre = ypre + 1;
				}
				else {
					if ((napr == 4) && ((ypre - 1) >= 0))
					{
						ypre = ypre - 1;
					}
					else
					{
						//Сдесь вариант 4
						if (napr == 1)
						{
							napr = 2;
							xpre = xnach - 1;
						}
						else
						{
							if (napr == 2)
							{
								napr = 1;
								xpre = xnach + 1;
							}
							else
							{
								if (napr == 3)
								{
									napr = 4;
									ypre = ynach - 1;
								}
								else
								{
									if (napr == 4)
									{
										napr = 3;
										ypre = ynach + 1;
									}
								}
							}
						}
					}
				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	//Меняем направление на противоположенное
	if (fdobit == var4)
	{
		if (napr == 1)
		{
			napr = 2;
			xpre = xnach - 1;
		}
		else
		{
			if (napr == 2)
			{
				napr = 1;
				xpre = xnach + 1;
			}
			else
			{
				if (napr == 3)
				{
					napr = 4;
					ypre = ynach - 1;
				}
				else
				{
					if (napr == 4)
					{
						napr = 3;
						ypre = ynach + 1;
					}


				}
			}
		}
		*(x) = xpre;
		*(y) = ypre;
		masproverky[*(x)][*(y)] = PUSTPOD;
		fdobit = var3;
		return;
	}

	if (fdobit == var2) 
	{
		//Выбираем направление
		do {
			napr = round(((double) rand() / 32767) * (4 - 1) + 1); //Выбераем одно из 4-х направлений
			if ((napr == 1) && ((xnach + 1) < N))
			{
				break;
			}
			if ((napr == 2) && ((xnach - 1) >= 0))
			{
				break;
			}
			if ((napr == 3) && ((ynach + 1) < N))
			{
				break;
			}
			if ((napr == 4) && ((ynach - 1) >= 0))
			{
				break;
			}
		} while (1);

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
		masproverky[*(x)][*(y)] = PUSTPOD;
		return;
	}

	if (fdobit == var1)
	{
		do 
		{
			*(x) = round(((double) rand() / 32767) * ((N - 1) - 0) + 0);
			*(y) = round(((double) rand() / 32767) * ((N - 1) - 0) + 0);
		} 
		while (masproverky[*(x)][*(y)] == PUSTPOD);
		masproverky[*(x)][*(y)] = PUSTPOD;

		//Хранят результата последнего хода
		xnach = *(x);
		ynach = *(y);
		xpre = xnach;
		ypre = ynach;
		return;
	}
};

string Igrok::getimya()
{
	return imya;
};