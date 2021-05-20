#ifndef Funkcje_ttt.h

#define Funkcje_ttt.h

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                       FUNCKJE KOLKA I KRZYZYK
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

void rysowanie_tablicy(string *pola);
/**
    RYSUJE PLANSZE DO KOLKA I KRZYZYK
    rysuje ksztalty ktore sa zapisane w tablicy POLA
*/

void rysuj_ksztalt(int ktore,string znak ,string *pola);
/**
    KOLKO I KRZYZYK
    Po czyims ruchu rysuje nowy ksztalt na planszy
*/

int sprawdzanie_wygranej(string *pola);
/**
    Sprawdza czy ktos nie wygral w KOLKU I KRZYZYK
    CZYLI czy sa 3 pod rzad
*/

void rysowanie_wygranej(int linia, bool czy_ja_wygralem);
/**
    Wywolywana po czyjejs wygranej w KOLKO I KRZYZYK
    Rysuje przekreslenie wygrywajacej TROJKI na czerwono
*/

void czyszczenie_ttt();
/**
    Czysci ekran w KOLKU I KRZYZYK
*/
#endif // Funkcje_ttt
