#include "kletka.h"

kletka::kletka() //Конструктор
{
	klet = PUST;
};

void kletka::setklet(sostoyanie k) //устанавливает состояние клетки
{
	klet = k;
};

sostoyanie kletka::getklet() //считать состояние клетки
{
	return klet;
};