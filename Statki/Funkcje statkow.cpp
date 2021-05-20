#include "..\_Headers\funkcje.h"
#include "Funkcje_statkow.h"

bool zatopiony(string statki[7][6], string pole[10][10]){
//    fstream plik;
//    plik.open("sprawozdanie.txt", ios::out | ios::app);
//    plik<<"\nJestem w funkcji zatpiony!\n";
    for(int j=0;j<7;j++)
    {
//        plik << "Sprawdzam teraz " << j << " statek!\n";
        if(statki[j][5] == "false")
        {
//            plik << "statki[j][5] == \"false\"!\n";
            if(statki[j][4] == "prawo" || statki[j][4] == "dol")
            {
//                plik << "statki[j][4] == "<<statki[j][4]<<"\n";
                bool czy_zatopiony = true;
                for(int i=0; i<(int)string_na_int(statki[j][3]); i++)
                {
                    if(pole[(int)((int)string_na_int(statki[j][1]) / 10) + (statki[j][2] == "poziom" ? i : 0)]
                    [(int)((int)string_na_int(statki[j][1]) % 10)+ ((statki[j][2] == "pion") ? i : 0)] =="X")  continue;
                    else
                    {
                        czy_zatopiony = false;
                        break;
                    }
                }
//                plik << "czy_zatopiony = " << czy_zatopiony <<endl;
                if(czy_zatopiony)
                {
//                    plik.close();
                    statki[j][5] = "true";
                    return true;
                }
            }
            if(statki[j][4] == "lewo" || statki[j][4] == "gora")
            {
//                plik << "statki[j][4] == "<<statki[j][4]<<"\n";
                bool czy_zatopiony = true;
                for(int i=0; i<(int)string_na_int(statki[j][3]); i++)
                {
                    if(pole[(int)((int)string_na_int(statki[j][1]) / 10) - (statki[j][2] == "poziom" ? i : 0)]
                    [(int)((int)string_na_int(statki[j][1]) % 10)
                       - ((statki[j][2] == "pion") ? i : 0)] == "X")  continue;
                    else
                    {
                        czy_zatopiony = false;
                        break;
                    }
                }
//                plik << "czy_zatopiony = " << czy_zatopiony <<endl;
                if(czy_zatopiony)
                {
//                    plik.close();
                    statki[j][5] = "true";
                    return true;
                }
            }
        }
    }
//    plik.close();
    return false;
}

bool przegralem(string statki[7][6]){
    for(int i=0;i<7;i++)
        if(statki[i][5] == "false") return false;
    return true;
}

void PPONS(int x, int y, string pole[10][10]){  ///POPRAWIANIE PLANSZY O NOWY STATEK

    saturnin_mowi(nasz_kolor);
    for(int i = 0;i<21;i++)
    {
        for(int j = 0;j <21; j++)
        {
            ustaw_wskaznik((i == 20&&j==0?1:2)+j+x,2+i+y);
            if(i%2==0&&i!=0&&j%2==0&&j!=0)
            {
                if(pole[j/2 - 1][i/2 - 1] != "" && pole[j/2 - 1][i/2 - 1] != " ")
                {
                    cout << pole[j/2 - 1][i/2 - 1];
                }
            }
        }
    }
}

void rysowanie_planszy(int x , int y, string pole[10][10], bool my, bool czy_koniec){
    /*
        ARGUMENTY DOMNIEMANE:
        bool=0
        bool czy_koniec=0
    */
    saturnin_mowi(1);
    for(int i = 0;i<21;i++)
    {
        for(int j = 0;j <21; j++)
        {
            saturnin_mowi(1);
            ustaw_wskaznik((i == 20&&j==0?1:2)+j+x,2+i+y);
            if(i%2 == 1 && j%2 == 0)         cout <<"-";
            else if(i%2==1 && j%2==1)        cout <<"+";
            else if(j%2==1)                  cout <<"|";
            else if(i == 0&& j%2 == 0&&j!=0) cout << char(64 + j/2);
            else if(j == 0&&i%2 ==0&&i!=0)   cout << i/2;
            else if(i%2==0&&i!=0&&j%2==0&&j!=0&&pole[j/2 - 1][i/2 - 1]=="`") cout << " ";
            else if(i%2==0&&i!=0&&j%2==0&&j!=0&&pole[j/2 - 1][i/2 - 1]=="") cout << " ";
             else if(i%2==0&&i!=0&&j%2==0&&j!=0&&pole[j/2 - 1][i/2 - 1]=="?")
             {
                 saturnin_mowi(2);
                 cout << "?";
             }
            else if(i%2==0&&i!=0&&j%2==0&&j!=0&&pole[j/2 - 1][i/2 - 1]== "#")
            {
                if(my) saturnin_mowi(nasz_kolor);
                else if(czy_koniec)   saturnin_mowi(kolor_saturnina);
                else saturnin_mowi(1);
                cout << "#";
            }
            else if(i%2==0&&i!=0&&j%2==0&&j!=0&&pole[j/2 - 1][i/2 - 1]== "X" || pole[j/2 - 1][i/2 - 1]== "O")
            {
                saturnin_mowi(15);
                cout << pole[j/2 - 1][i/2 - 1];
            }
            else if(i%2==0&&i!=0&&j%2==0&&j!=0&&pole[j/2 - 1][i/2 - 1]!="") cout << pole[j/2 - 1][i/2 - 1];
        }
    }
}

void menu_statkow(int x, int y, int wskaznik, bool wszystkie_statki = false){


    y++;
    ustaw_wskaznik(x + 6,y + 23);
    saturnin_mowi(1);
    cout << ((wskaznik == 0) ? "Lotniskowiec  " : (wskaznik == 1) ? "Pancernik        " : (wskaznik == 2) ? "Krazawnik       " : (wskaznik == 3) ? "Lodz podwodna    " : (wskaznik == 4) ? "Okret desantowy        " :
        (wskaznik == 5) ? "Korweta         " : "Kuter          ");
    x += 5;
    if(wszystkie_statki)
    {
        saturnin_mowi(wskaznik == -1 ? nasz_kolor : 1);
        string koniec="KONIEC";
        for(int i = 0; i<6;i++)
        {
            ustaw_wskaznik(x-1,y+24+i);
            cout << koniec.substr(i,1);
        }
    }
    saturnin_mowi(wskaznik == 0 ? nasz_kolor : 1);
    for(int i = 0; i<5;i++)
    {
        ustaw_wskaznik(x+1,y+24+i);
        cout << "#";
    }
    saturnin_mowi(wskaznik == 1 ? nasz_kolor : 1);
    for(int i = 0; i<4;i++)
    {
        ustaw_wskaznik(x+3,y+24+i);
        cout << "#";
    }
    saturnin_mowi(wskaznik == 2 ? nasz_kolor : 1);
    for(int i = 0; i<3;i++)
    {
        ustaw_wskaznik(x+5,y+24+i);
        cout << "#";
    }
    saturnin_mowi(wskaznik == 3 ? nasz_kolor : 1);
    for(int i = 0; i<3;i++)
    {
        ustaw_wskaznik(x+7,y+24+i);
        cout << "#";
    }
    saturnin_mowi(wskaznik == 4 ? nasz_kolor : 1);
    for(int i = 0; i<2;i++)
    {
        ustaw_wskaznik(x+9,y+24+i);
        cout << "#";
    }
    saturnin_mowi(wskaznik == 5 ? nasz_kolor : 1);
    for(int i = 0; i<2;i++)
    {
        ustaw_wskaznik(x+11,y+24+i);
        cout << "#";
    }

    saturnin_mowi(wskaznik == 6 ? nasz_kolor : 1);
    ustaw_wskaznik(x+13,y+24);
    cout << "#";

}

void czyszczenie(int x, int y){
    ustaw_wskaznik(x,y);
    for(int i=0;i<90;i++)   cout << " ";
    ustaw_wskaznik(x,y+1);
    for(int i=0;i<90;i++)   cout << " ";
    ustaw_wskaznik(x,y);
}
