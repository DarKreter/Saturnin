#include "../_Headers/funkcje.h"
#include "Funkcje_ttt.h"

///DEFINICJE FUNKCJI DLA KOLKA I KRZYZYK

void czyszczenie_ttt(){
    ustaw_wskaznik(1,31);
    for(int i = 0;i < 10;i++)
    {
        for(int j = 0;j < 80 ; j++)
        {
            cout << " ";
        }
    cout << endl;
    }
}

void rysowanie_wygranej(int linia, bool czy_ja_wygralem){
    string wygrana;
    if(czy_ja_wygralem == true)
    {
        wygrana = "WYGRALES, GRATULACJE!";
    }
    else
    {
        wygrana = "PRZEGRALES, KAZDEMU MOZE SIE ZDAZYC!";
    }

    switch(linia)
    {
    case 1:
        for(int i = 21; i < 50; i++)
        {
            ustaw_wskaznik(i,5);
            cout << "x";
        }
        ustaw_wskaznik(1,31);
        czyszczenie_ttt();
        ustaw_wskaznik(30,31);
        cout << wygrana;
        getch();
        exit(0);
        break;
    case 2:
        for(int i = 21; i < 50; i++)
        {
            ustaw_wskaznik(i,15);
            cout << "x";
        }
        ustaw_wskaznik(1,31);
        czyszczenie_ttt();
        ustaw_wskaznik(30,31);
        cout << wygrana;
        getch();
        exit(0);
        break;
    case 3:
        for(int i = 21; i < 50; i++)
        {
            ustaw_wskaznik(i,25);
            cout << "x";
        }
        ustaw_wskaznik(1,31);
        czyszczenie_ttt();
        ustaw_wskaznik(30,31);
        cout << wygrana;
        getch();
        exit(0);
        break;
    case 4:
        for(int i = 1; i < 30; i++)
        {
            ustaw_wskaznik(25,i);
            cout << "x";
        }
        ustaw_wskaznik(1,31);
        czyszczenie_ttt();
        ustaw_wskaznik(30,31);
        cout << wygrana;
        getch();
        exit(0);
        break;
    case 5:
        for(int i = 1; i < 30; i++)
        {
            ustaw_wskaznik(35,i);
            cout << "x";
        }
        ustaw_wskaznik(1,31);
        czyszczenie_ttt();
        ustaw_wskaznik(30,31);
        cout << wygrana;
        getch();
        exit(0);
        break;
    case 6:
        for(int i = 1; i < 30; i++)
        {
            ustaw_wskaznik(45,i);
            cout << "x";
        }
        ustaw_wskaznik(1,31);
        czyszczenie_ttt();
        ustaw_wskaznik(30,31);
        cout << wygrana;
        getch();
        exit(0);
        break;
    case 7:
        for(int i = 1; i < 30;i++)
        {
        ustaw_wskaznik(20 + i, i);
        cout << "x";
        }
        ustaw_wskaznik(1,31);
        czyszczenie_ttt();
        ustaw_wskaznik(30,31);
        cout << wygrana;
        getch();
        exit(0);
        break;
    case 8:
        for(int i = 1; i < 30;i++)
        {
        ustaw_wskaznik(50 - i,i);
        cout << "x";
        }
        ustaw_wskaznik(1,31);
        czyszczenie_ttt();
        ustaw_wskaznik(30,31);
        cout << wygrana;
        getch();
        exit(0);
        break;
    }
}

int sprawdzanie_wygranej(string *pola){

    string tab[10];
    pola ++ ;
    for(int i = 1; i<10; i++)
    {
        tab[i] = *pola;
        pola++;
    }
    if(tab[1] == tab[2] && tab[1] == tab[3] && tab[1] != "")
    {
        return 1;
    }
    else if(tab[4] == tab[5] && tab[4] == tab[6] && tab[4] != "")
    {
        return 2;
    }
    else if(tab[7] == tab[8] && tab[7] == tab[9] && tab[7] != "")
    {
        return 3;
    }
    else if(tab[1] == tab[4] && tab[1] == tab[7] && tab[1] != "")
    {
        return 4;
    }
    else if(tab[2] == tab[5] && tab[2] == tab[8] && tab[2] != "")
    {
        return 5;
    }
    else if(tab[3] == tab[6] && tab[3] == tab[9] && tab[3] != "")
    {
        return 6;
    }
    else if(tab[1] == tab[5] && tab[1] == tab[9] && tab[1] != "")
    {
        return 7;
    }
    else if(tab[3] == tab[5] && tab[3] == tab[7] && tab[3] != "")
    {
        return 8;
    }
    else return 0;
}

void rysuj_ksztalt(int ktore,string znak ,string *pola){
    if(znak == "krzyz"){
        int wysokosc = 0, szerokosc = 0;

    switch(ktore)  ///Ustawiam wysokosc i szerokosc
    {
    case 1:
        szerokosc = 21;
        wysokosc  = 1;
        break;
    case 2:
        szerokosc = 31;
        wysokosc  = 1;
        break;
    case 3:
        szerokosc = 41;
        wysokosc  = 1;
        break;
    case 4:
        szerokosc = 21;
        wysokosc  = 11;
        break;
    case 5:
        szerokosc = 31;
        wysokosc  = 11;
        break;
    case 6:
        szerokosc = 41;
        wysokosc  = 11;
        break;
    case 7:
        szerokosc = 21;
        wysokosc  = 21;
        break;
    case 8:
        szerokosc = 31;
        wysokosc  = 21;
        break;
    case 9:
        szerokosc = 41;
        wysokosc  = 21;
        break;
    }

    int maxszer = 0;

    for(int i = 0; i<=8; i++)
    {
        ustaw_wskaznik(szerokosc + i,wysokosc+i);
        cout << "x";
        maxszer = szerokosc + i;

    }
    for(int i = 0; i <= 8; i++)
    {
        ustaw_wskaznik(maxszer - i,wysokosc + i);
        cout << "x";
    }
    for(int i = 0; i < ktore; i++)
    {
        pola++;
    }
    *pola = "krzyz";
    ustaw_wskaznik(1,33);
    }

    else if(znak == "kolko"){
       int wysokosc = 0, szerokosc = 0;

    switch(ktore)  ///Ustawiam wysokosc i szerokosc
    {
    case 1:
        szerokosc = 21;
        wysokosc  = 1;
        break;
    case 2:
        szerokosc = 31;
        wysokosc  = 1;
        break;
    case 3:
        szerokosc = 41;
        wysokosc  = 1;
        break;
    case 4:
        szerokosc = 21;
        wysokosc  = 11;
        break;
    case 5:
        szerokosc = 31;
        wysokosc  = 11;
        break;
    case 6:
        szerokosc = 41;
        wysokosc  = 11;
        break;
    case 7:
        szerokosc = 21;
        wysokosc  = 21;
        break;
    case 8:
        szerokosc = 31;
        wysokosc  = 21;
        break;
    case 9:
        szerokosc = 41;
        wysokosc  = 21;
        break;
    }

    ustaw_wskaznik(szerokosc + 4, wysokosc + 4);
    cout << " ";

    for(int i = 2; i < 7; i++)
    {
        ustaw_wskaznik(szerokosc + i, wysokosc);
        cout << "o";
        ustaw_wskaznik(szerokosc + i, wysokosc + 8);
        cout << "o";
        ustaw_wskaznik(szerokosc, wysokosc + i);
        cout << "o";
        ustaw_wskaznik(szerokosc +8, wysokosc + i);
        cout << "o";
    }

    ustaw_wskaznik(szerokosc + 1, wysokosc + 1);
    cout << "o";
    ustaw_wskaznik(szerokosc + 7, wysokosc + 1);
    cout << "o";
    ustaw_wskaznik(szerokosc + 7, wysokosc + 7);
    cout << "o";
    ustaw_wskaznik(szerokosc + 1, wysokosc + 7);
    cout << "o";

    for(int i = 0; i < ktore; i++)
    {
        pola++;
    }
    *pola = "kolko";
    }
}

void rysowanie_tablicy(string *pola){

    for(int i = 21; i<50; i++)
    {
        ustaw_wskaznik(i,10);
        cout << "-";
        ustaw_wskaznik(i,20);
        cout << "-";
    }
    for(int x = 1; x < 30; x++)
    {
        ustaw_wskaznik(30,x);
        cout << "|";
        ustaw_wskaznik(40,x);
        cout << "|";
    }
    pola ++ ;
    int szerokosc = 0, wysokosc = 0;
    for(int i = 1; i < 10; i++)
    {
        if(*pola == "")
        {
            switch(i)  ///Ustawiam wysokosc i szerokosc
            {
            case 1:
                szerokosc = 21;
                wysokosc  = 1;
                break;
            case 2:
                szerokosc = 31;
                wysokosc  = 1;
                break;
            case 3:
                szerokosc = 41;
                wysokosc  = 1;
                break;
            case 4:
                szerokosc = 21;
                wysokosc  = 11;
                break;
            case 5:
                szerokosc = 31;
                wysokosc  = 11;
                break;
            case 6:
                szerokosc = 41;
                wysokosc  = 11;
                break;
            case 7:
                szerokosc = 21;
                wysokosc  = 21;
                break;
            case 8:
                szerokosc = 31;
                wysokosc  = 21;
                break;
            case 9:
                szerokosc = 41;
                wysokosc  = 21;
                break;
            }

            ustaw_wskaznik(szerokosc + 4,wysokosc + 4);
            saturnin_mowi(kolor_saturnina);
            cout << i;
        }
        else if(*pola == "krzyz")
        {
            saturnin_mowi(nasz_kolor);
            rysuj_ksztalt(i,"krzyz",pola - i);
        }
        else if(*pola == "kolko")
        {
            saturnin_mowi(nasz_kolor);
            rysuj_ksztalt(i,"kolko",pola - i);
        }
        pola ++;
    }

}
