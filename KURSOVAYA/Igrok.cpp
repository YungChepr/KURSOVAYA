#include "Igrok.h"
Igrok::Igrok(string imya)
{
	this->imya = imya;
};

void Igrok::vystrel(int*x, int*y) //Генерация поля в которое игрок стреляет
{
	*(x) = 0;
	*(y) = 0;
	//Не завершено!!!
	//Заменить на генерацию случайных координат
};

string Igrok::getimya()
{
	return imya;
};