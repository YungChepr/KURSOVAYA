#pragma once
#include "pole.h"

class Ecran
{
public:
	static const string symvoli[4]; //������� �������������� ���������� ������ ����
	static const string bykvi[10]; //������� �������������� ����������� �� Y

	void prorisovkashapki(pole* doska);
	void prorisovkapolya(pole* doska);
	void prorisovkapodvala(pole* doska);
};

