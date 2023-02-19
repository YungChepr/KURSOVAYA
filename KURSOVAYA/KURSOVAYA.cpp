// KURSOVAYA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Ecran.h"
#include "Igrok.h"
#include "Odnopalybnik.h"
#include "Mnogopalybnik.h"
#include "Igra.h"
#include <conio.h>
#include <windows.h>

using namespace std;

string s1 = "Ivan";
string s2 = "Maksim";

pole doska1, doska2; //Доски игроков 1 - игрок, 2 - противник
Odnopalybnik* korabli1[M];
Odnopalybnik* korabli2[M];


Ecran ecranchik; 
Igrok igrok1(s1), igrok2(s2);
Igra Morskoyboy;
int X, Y,f,c,i;

int main()
{
    setlocale(LC_ALL,"RUS");
    string nachsnaach;
    //Инициализация гинератора случайных чисел
    srand(time(NULL));

    do {
        //Блок начала игры
        system("cls");
        cout << "Приветсвуем в игре Морской бой!" << endl;
        cout << "Игрок 1: " << s1 << endl;
        cout << "Игрок 2: " << s2 << endl;
        Igra::igrokperviy = s1;
        Igra::igrokvtoroy = s2;
       
        doska1.imyapolya = igrok1.getimya();
        doska2.imyapolya = igrok2.getimya();

        //Блок создания кораблей
        for (i = 0; i < kolodno; i++)
        {
            korabli1[i] = new Odnopalybnik();
            korabli2[i] = new Odnopalybnik();
        }
        for (i = 0; i < koldvy; i++)
        {
            korabli1[i + kolodno] = new Mnogopalybnik(2);
            korabli2[i + kolodno] = new Mnogopalybnik(2);
        } 
        for (i = 0; i < koltre; i++)
        {
            korabli1[i + kolodno + koldvy] = new Mnogopalybnik(3);
            korabli2[i + kolodno + koldvy] = new Mnogopalybnik(3);
        }
        for (i = 0; i < kolchetire; i++)
        {
            korabli1[i + kolodno + koldvy + koltre] = new Mnogopalybnik(4);
            korabli2[i + kolodno + koldvy + koltre] = new Mnogopalybnik(4);
        }


        Morskoyboy.rasstanovka(korabli1, &doska1);
        Morskoyboy.rasstanovka(korabli2, &doska2);

        ecranchik.prorisovkapolya(&doska1);
        ecranchik.prorisovkapolya(&doska2);
        
        //Решить кто первый ходит
        cout << endl << endl << endl << endl;
        cout << "Первым ходит игрок " << s1 << endl;
        cout << "Нажмите любую клавишу... ";
        c=_getch();
        

        //Блок хода игры
        do {
            system("cls");
            if ((Morskoyboy.scetchikXodov % 2) == 0)
            {
                igrok1.vystrel(&X, &Y, &doska2);
                Morskoyboy.hod(korabli2, &doska2, X, Y);

                ecranchik.prorisovkashapki(&doska1);
                ecranchik.prorisovkapolya(&doska1);
                ecranchik.prorisovkapolya(&doska2);
                cout << "          " << "Этот ход сделал игрок: " << Igra::igrokperviy << endl;
                ecranchik.prorisovkapodvala(&doska2);

                f = Morskoyboy.konecigry(korabli2);//1 - если игры продолжается, 0 - если закончилась
                if (f == 0)
                {
                    Morskoyboy.setimyapobeditelya(s1);
                }
            }

            else
            {
                igrok2.vystrel(&X, &Y, &doska1);
                Morskoyboy.hod(korabli1, &doska1, X, Y);

                ecranchik.prorisovkashapki(&doska1);
                ecranchik.prorisovkapolya(&doska1);
                ecranchik.prorisovkapolya(&doska2);
                cout << "          " << "Этот ход сделал игрок: " << Igra::igrokvtoroy << endl;
                ecranchik.prorisovkapodvala(&doska1);

                f = Morskoyboy.konecigry(korabli1);//1 - если игры продолжается, 0 - если закончилась
                if (f == 0)
                {
                    Morskoyboy.setimyapobeditelya(s2);
                }
            }
            Morskoyboy.scetchikXodov = Morskoyboy.scetchikXodov + 1;

            cout << "Следующий ход... "; //Задержка после каждого хода
            //Sleep(ZAD); //Задержка перед следующим ходом
             c = _getch();

        } while (f);
        
        

        //Блок конца игры
        system("cls");
        ecranchik.prorisovkapolya(&doska1);
        ecranchik.prorisovkapolya(&doska2);
       
        cout << "Победил игрок: " << Morskoyboy.getimyapobeditelya() << endl << endl;

        
          
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
