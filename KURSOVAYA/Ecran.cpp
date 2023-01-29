#include "Ecran.h"
#include "kletka.h"


 
const string Ecran::symvoli[4] = { "  ","• ","+ ","x " }; //Символы соответсвующие состояниям клеток поля

const string Ecran::bykvi[10] = { "a ","b ","c ","d ","e ","f ","g ","h ","j ","k " }; //Символы соответсвующие координатам по Y

const string OTST = "     "; //Отступ при печати новой строчки 5 пробелов


void prorisovka(pole doska)
{

	int i,j; //Счетчик

	//Вывод шапки
	cout << endl << endl << endl;
	cout << OTST << OTST << " ИГРОК 1 " << endl;
	cout << endl;
	cout << OTST << "  " << "1 2 3 4 5 6 7 8 9 10" << endl;

	//Вывод основного поля
	for (i = 0; i < N; i++) 
	{
		cout << OTST << Ecran::bykvi[i];
		for (j = 0; j < N; j++)
		{
			cout << Ecran::symvoli[doska.pol[i][j].getklet()] << endl;
		}
	}

	//Вывод подвала
	cout << endl;
	cout << OTST << OTST << "Текущий ход: " << "a 1  " << endl;
	cout << OTST << OTST << "Результат:   " << "Попал" << endl;
	cout << endl;
};