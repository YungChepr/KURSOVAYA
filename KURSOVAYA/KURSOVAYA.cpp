// KURSOVAYA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Ecran.h"
#include "Igrok.h"
#include "Odnopalybnik.h"
#include "Igra.h"

using namespace std;

string s1 = "Ivan";
string s2 = "Maksim";
pole doska1, doska2; //Доски игроков 1 - игрок, 2 - противник
Odnopalybnik* korabli1[M];
Odnopalybnik* korabli2[M];


Ecran ecranchik; 
Igrok igrok1(s1), igrok2(s2);
Igra Morskoyboy;

int main()
{
    setlocale(LC_ALL,"RUS");
    string nachsnaach;
    do {
        system("cls");
        cout << "Приветсвуем в игре Морской бой!" << endl;
        cout << "Игрок 1: " << s1 << endl;
        cout << "Игрок 2: " << s2 << endl;

        //Блок начала игры
        doska1.imyapolya = igrok1.getimya();

        doska2.imyapolya = igrok2.getimya();
        korabli1[0] = new Odnopalybnik();
        korabli2[0] = new Odnopalybnik();
        Morskoyboy.rasstanovka(korabli1, &doska1);
        Morskoyboy.rasstanovka(korabli2, &doska2);

        ecranchik.prorisovka(&doska1);
        ecranchik.prorisovka(&doska2);
        //Решить кто первый ходит
         
        //Блок хода игры
        do {
            //Проверить кто ходит из игроков
            //Сгенерировать координату выстрела
            //Передать координату в функию выстрел
            //В выстреле меняем состояние
            //Цикл проверки состояния кораблей
            //Если нет ни одного живого корабля то выход


            //korabli1[0].getpalyba();
        } while (1);

        //Блок конца игры
        cout << "Если вы хотите закончить игру введите 1" << endl;
        cout << "Если вы хотите начать игру заново введите любой символ" << endl;
        cout << "> " ;
        cin >> nachsnaach;
    } while (nachsnaach != "1");
    cout << "Вы закончили игру";
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
