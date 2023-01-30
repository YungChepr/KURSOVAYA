#pragma once
#include "kletka.h"
class pole 
{
private:
	string imyapolya; // Хранит имя игрока
public:
	kletka pol[N][N]; //Хранит информацию о клетках
	pole();
	void chistka(); //Чистит поля
	void ystanovkaimeni(); //Устанавливает имя игрока
};

