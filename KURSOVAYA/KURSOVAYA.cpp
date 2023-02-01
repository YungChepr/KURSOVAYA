// KURSOVAYA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Ecran.h"
#include "Igrok.h"
#include "Odnopalybnik.h"
#include "Igra.h"

using namespace std;

pole doska1, doska2; //Доски игроков 1 - игрок, 2 - противник
Odnopalybnik* korabli1[M];
Odnopalybnik* korabli2[M];


Ecran ecranchik; 
Igrok igrok1("Ivan"), igrok2("Maksim");
Igra Morskoyboy;

int main()
{
    setlocale(LC_ALL,"RUS");
    
    //Блок начала игры
    doska1.imyapolya = igrok1.getimya();
    doska2.imyapolya = igrok2.getimya();
    korabli1[0] = new Odnopalybnik();
    korabli2[0] = new Odnopalybnik();
    Morskoyboy.rasstanovka(korabli1, doska1);
    Morskoyboy.rasstanovka(korabli2, doska2);
    ecranchik.prorisovka(&doska1);
    ecranchik.prorisovka(&doska2);

    //Блок хода игры
    //do {

   // } while ();

    //Блок конца игры
    
}

 

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
