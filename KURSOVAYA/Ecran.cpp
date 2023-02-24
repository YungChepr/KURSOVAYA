#include "Ecran.h"

const string Ecran::symvoli[4] = { "  ","· ","+ ","x " }; //Символы соответсвующие состояниям клеток поля

const string Ecran::tsifri[NMAX] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20" }; //Символы соответсвующие координатам по X
const string Ecran::bykvi[NMAX] = { "a ","b ","c ","d ","e ","f ","g ","h ","j ","k ", "l ", "m ", "n " , "o " , "p " , "q " , "r " , "s " , "t " , "u " }; //Символы соответсвующие координатам по Y

const string OTST = "          "; //Отступ при печати новой строчки 5 пробелов

void Ecran::prorisovkashapki(pole* doska)
{
	cout << endl << endl << endl;
}

void Ecran::prorisovkapolya(pole* doska)
{

	int i,j; //Счетчик

	//Вывод шапки
	cout << endl;

	cout << OTST << "Игрок: " << doska->imyapolya << endl;
	cout << endl;

	//Вывод основного поля
	cout << OTST << "  ";
	for (i = 0; i < N; i++)
	{
		if(i<10)
		{
			cout << Ecran::tsifri[i] << " ";
		}
		else
		{
			cout << Ecran::tsifri[i];
		}
	}
	cout << endl;

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

	cout << OTST << "  ";
	for (i = 0; i < N; i++)
	{
		if (i < 10)
		{
			cout << Ecran::tsifri[i] << " ";
		}
		else
		{
			cout << Ecran::tsifri[i];
		}
	}
	cout << endl;
	cout << endl;
};

void Ecran::prorisovkapodvala(pole* doska)
{
	//Вывод подвала
	cout << OTST << "Ход: " << doska->koorposlxoda << "   " << endl;
	cout << OTST << "Результат:   " << doska->resposlxoda << "           " << endl; //Второй пробел перезатрет более длинное слово
	cout << OTST << "Следующий ход игрока: " << doska->imyapolya << "                           ";
}

void Ecran::prorisovkastroki(pole* doska, int x, int y, int nomerdoski)
{
	Ecran::set_cursor(0, 0);
	int delta;
	if (nomerdoski == 1)
	{
		delta = 3 + 4;
		Ecran::set_cursor((10 + 2 + 2 * y), (delta + x));
		cout << Ecran::symvoli[doska->pol[x][y].getklet()];

	}
	else
	{ //Надо будет курсор поставить на конец доски
		delta = 8 + 1 + N + 4;
		Ecran::set_cursor((10 + 2 + 2 * y), (delta + x));
		cout << Ecran::symvoli[doska->pol[x][y].getklet()];
	}
	Ecran::set_cursor(0, (2*N + 15));
}

//Параметр по умолчанию
//Эту функцию можно вызывать с любым количеством параметров
void Ecran::set_cursor(int x, int y) //Функция передвижения курсора
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}
