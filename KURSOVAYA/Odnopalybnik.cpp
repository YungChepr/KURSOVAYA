#include "Odnopalybnik.h"
Odnopalybnik::Odnopalybnik() 
{
	palyba = NEUKAZANO;
};

sost Odnopalybnik::getpalyba()
{
	return palyba;
};

void Odnopalybnik::setpalyba(sost p)
{
	palyba = p;
};

sost Odnopalybnik::getkorabl()
{
	return korabl;
};

void Odnopalybnik::setkorabl(sost k)
{
	korabl = k;
};
