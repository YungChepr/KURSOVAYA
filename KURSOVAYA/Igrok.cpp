#include "Igrok.h"
Igrok::Igrok(string imya)
{
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

void Igrok::vystrel(int*x, int*y) //Генерация поля в которое игрок стреляет
{
	do 
	{
		*(x) = (int)((rand() / 32767.0) * (N - 1));
		*(y) = (int)((rand() / 32767.0) * (N - 1));
	} 
	while (masproverky[*(x)][*(y)] == PUSTPOD);

	masproverky[*(x)][*(y)] = PUSTPOD;
};

string Igrok::getimya()
{
	return imya;
};