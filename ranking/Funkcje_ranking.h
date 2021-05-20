#ifndef Funkcje_rankingu.h
#define Funkcje_rankingu.h

extern vector <string> nazwy,wykonawcy,linki,oceny,liczby_ocen;

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                    FUNKCJE DLA RANKINGU MUZYKI
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

void sortowanie_vectorow(float *tablica,int lewy,int prawy);
/**
    QUICK SORT ale zastosowany do VECTOROW ktore sa GLOBALNE
    NA WYLACZNY UZYTEK RANKINGU
*/

void sortowanie_pliku(string uzytkownik);
/**
    Wpisywanie POSORTOWANYCH vectorow do PLIKU
    NA WYLACZNY UZYTEK RANKINGU
*/

#endif // Funkcje_rankingu
