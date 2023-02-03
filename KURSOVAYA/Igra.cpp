#include "Igra.h"


void Igra::rasstanovka(Odnopalybnik* korabli[M], pole* doska)
{

	korabli[0]->setkoordinata(0, 0);
	korabli[0]->setpalyba(NEPODBIT);
	doska->pol[0][0].setklet(KOR);
};