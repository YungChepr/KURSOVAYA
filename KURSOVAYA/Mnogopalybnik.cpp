#include "Mnogopalybnik.h"

Mnogopalybnik::Mnogopalybnik() //�� ��������� ������� ������������ �������
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
		cout << endl << "�� ������ �������� ��������� k, ������ ������������ �������!!!" << endl;
	}
};
//���������� ������ �������������
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