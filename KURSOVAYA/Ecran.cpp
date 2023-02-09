#include "Ecran.h"

const string Ecran::symvoli[4] = { "  ","· ","+ ","x " }; //Символы соответсвующие состояниям клеток поля

const string Ecran::bykvi[10] = { "a ","b ","c ","d ","e ","f ","g ","h ","j ","k " }; //Символы соответсвующие координатам по Y

const string OTST = "          "; //Отступ при печати новой строчки 5 пробелов

void Ecran::prorisovkashapki(pole* doska)
{
	cout << endl << endl << endl;
}

void Ecran::prorisovkapolya(pole* doska)
{

	int i,j; //Счетчик

	//Вывод шапки
	cout << endl << endl;

	cout << OTST << "Игрок: " << doska->imyapolya << endl;
	cout << endl;

	//Вывод основного поля
	cout << OTST << "  " << "1 2 3 4 5 6 7 8 9 10" << endl;
	for (i = 0; i < N; i++) 
	{
		cout << OTST << Ecran::bykvi[i];
		for (j = 0; j < N; j++)
		{
			cout << Ecran::symvoli[doska->pol[i][j].getklet()];
			
		}
		cout << Ecran::bykvi[i];
		cout << endl;
	}
	cout << OTST << "  " << "1 2 3 4 5 6 7 8 9 10" << endl;
};

void Ecran::prorisovkapodvala(pole* doska)
{
	//Вывод подвала
	cout << endl << endl << endl << endl;
	cout << OTST << "Текущий ход игрока: " << doska->imyapolya << endl;
	cout << OTST << "Текущий ход: " << doska->koorposlxoda << endl;
	cout << OTST << "Результат:   " << doska->resposlxoda << endl;
	cout << endl;
}