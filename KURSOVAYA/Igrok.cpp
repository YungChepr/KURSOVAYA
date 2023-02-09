#include "Igrok.h"
Igrok::Igrok(string imya)
{
	this->imya = imya;
};

void Igrok::vystrel(int*x, int*y, int stenchik) //√енераци€ пол€ в которое игрок стрел€ет
{
	if (stenchik == 0) 
	{
		*(x) = 2;
		*(y) = 2;
	}
	if (stenchik == 1)
	{
		*(x) = 1;
		*(y) = 1;
	}
	if (stenchik == 2)
	{
		*(x) = 0;
		*(y) = 0;
	}
	stenchik = stenchik + 1;
	//Ќе завершено!!!
	//«аменить на генерацию случайных координат
	//—десь надо провер€ть не попал ли € в поле, в которое уже стрел€л
};

string Igrok::getimya()
{
	return imya;
};