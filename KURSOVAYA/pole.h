#pragma once
#include "kletka.h"
class pole 
{
private:
	kletka pol[N][N]; //Хранит информацию о клетках
public:
	pole();
	void chistka(); //Чистит поля
};

