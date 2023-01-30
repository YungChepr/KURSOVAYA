#pragma once
#include <iostream>
#include "string"
using namespace std;


const int N = 10; //Размерность поля при отчете с 1

enum sostoyanie //Состояние поля
{
	PUST,		//Пустое
	PUSTPOD,	//Пустое но сюда уже стреляли
	KOR,		//На этом поле стоит корабль
	KORPOD		//На этом поле стоит корабль по которому стреляли
};

enum sost //Состояние палубы
{
	PODBIT,     //Палуба подбита
	NEPODBIT,   //Палуба НЕ подбита
	NEUKAZANO   //Состояние не указано
};