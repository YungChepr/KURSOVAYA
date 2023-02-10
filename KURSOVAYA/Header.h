#pragma once
#include <iostream>
#include "string"
using namespace std;


const int N = 10; //Размерность поля при отчете с 1
const int ZAD = 10;//Задержка - 500 милисекунд

const int kolodno = 4; //Количество однопалубников
const int koldvy = 3; //Количество двупалубников
const int kolnre = 2; //Количество трехпалубников
const int kolchetire = 1; //Количество четырехпалубников
const int M = kolodno + koldvy + kolnre + kolchetire; //Количество кораблей у игрока

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

