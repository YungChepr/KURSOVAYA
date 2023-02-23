#pragma once
#include <iostream>
#include "string"
#include <windows.h>
using namespace std;


const int N = 10; //Размерность поля при отчете с 1
const int ZAD = 500;//Задержка - 500 милисекунд


const int kolodno = 4; //Количество однопалубников
const int koldvy = 3; //Количество двупалубников
const int koltre = 2; //Количество трехпалубников
const int kolchetire = 1; //Количество четырехпалубников
const int M = kolodno + koldvy + koltre + kolchetire; //Количество кораблей у игрока
const int KOLPOPITOK = 1000;

enum sostoyanie //Состояние поля
{
	PUST,		//Пустое
	PUSTPOD,	//Пустое но сюда уже стреляли
	KOR,		//На этом поле стоит корабль
	KORPOD		//На этом поле стоит корабль по которому стреляли
};

enum sost //Состояние палубы и корабля
{
	PODBIT,     //Палуба подбита, попал в корабль
	NEPODBIT,   //Палуба НЕ подбита, мимо корабля
	UBIT,	  //Корабль убит
	NEUKAZANO   //Состояние не указано
};

enum varianti //Варианты выстрела
{
	var1, // Произвольный выстрел
	var2, // Первое попадание в корабль
	var3, // Следующие попадание в корабль
	var3A,// Промах после первого попадния
	var4, // Промах после серии
	var5
};

