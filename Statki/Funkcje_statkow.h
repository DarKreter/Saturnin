#ifndef Funkcje_statkow.h
#define Funkcje_statkow.h

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                    FUNCKJE STATKI
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

bool zatopiony(string statki[7][6], string pole[10][10]);
/**
    Sprawdza czy jakis NOWY NIE statek ZOSTAL ZATOPIONY
    Zwraca TRUE dla zatopionego
    Zwraca FALSE dla braku zatopienia
*/

void PPONS(int x, int y, string pole[10][10]);
/**
    POPRAWIENIE PLANSZY I NOWY STATEK
    Korzystamy tego jak ustawiamy nowy statek
*/

void menu_statkow(int, int, int, bool);
/**
    Rysuje na ekranie menu wyboru statku do ustawienia
*/

void rysowanie_planszy(int x , int y, string pole[10][10], bool=0, bool czy_koniec=0);
/**
    Rysujemy plansze statkow razem z tym co w tablicach
*/

void czyszczenie(int x, int y);
/**
    Czyscimy dwie linijki w konsoli na ekranie
*/

bool przegralem(string statki[7][6]);
/**
    Sprawdza czy GRACZ NIE PRZEGRAL
*/


#endif // Funkcje_statkow
