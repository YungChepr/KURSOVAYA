#pragma once
#include "kletka.h"
class pole 
{
public:
	string imyapolya; // Хранит копию имени игрока
	kletka pol[N][N]; //Хранит информацию о клетках
	pole();
	void chistka(); //Чистит поля
};

