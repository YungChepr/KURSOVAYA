#pragma once
#include "string"
using namespace std;


const int N = 10; //Размерность поля

enum sostoyanie //Состояние поля
{
	PUST,		//Пустое
	PUSTPOD,	//Пустое но сюда уже стреляли
	KOR,		//На этом поле стоит корабль
	KORPOD		//На этом поле стоит корабль по которому стреляли
};

