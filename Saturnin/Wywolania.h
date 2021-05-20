#ifndef WYWOLANIA.H
#define WYWOLANIA.H


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                FUNCKJE WYWOLAN
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void ustawianie_tablicy_wskaznikow(void (*tab[])(string**), int *ilosc_komend);
/**
    FUNKCJA MATKA TABLICY WSKAZNIKOW
    Funkcja ustawia po kolei wskazniki z tablicy wskaznikow na odpowiednie funkcje!
    Wystarczy jeszcze podac pod *ILOSC_KOMEND dlugosc pliku tekstowego LISTA_KOMEND

*/

void WywolanieModulo(string** argv);
void WywolanieSrednia(string** argv);
void WywolanieZegnaj(string** argv);
void WywolaniePrzywitanie(string** argv);
void WywolanieDzielenieZReszta(string** argv);
void WywolanieMediana(string** argv);
void WywolanieZapis(string** argv);
void WywolanieDopisz(string** argv);
void WywolanieOdczyt(string** argv);
void WywolanieWyczyscPlik(string** argv);
void WywolanieBazaKolorow(string** argv);
void WywolanieSegregowanie(string** argv);
void WywolanieZmienTwojKolor(string** argv);
void WywolanieZmienMojKolor(string** argv);
void WywolanieLiczbaPierwsza(string** argv);
void WywolanieListaKomend(string** argv);
void WywolaniePolicz(string** argv);
void WywolanieSprDzTyg(string** argv);
void WywolanieWzor(string** argv);
void WywolaniePalindrom(string** argv);
void WywolanieDzielniki(string** argv);
void WywolanieGWIK(string** argv);
void WywolanieGWIM(string** argv);
void WywolanieSilnia(string** argv);
void WywolanieLosuj(string** argv);
void WywolanieSysLicz(string** argv);
void WywolanieWybierz(string** argv);
void WywolanieProcent(string** argv);
void WywolaniePi(string** argv);
void WywolanieMuzyka(string** argv);
void WywolanieZaloguj(string** argv);
void WywolanieZarejestruj(string** argv);
void WywolanieWyloguj(string** argv);
void WywolanieUsunKonto(string** argv);
void WywolanieKomunikator(string** argv);
void WywolanieStatki(string** argv);
void WywolanieSzachy(string** argv);
void WywolanieTtt(string** argv);
void mem(string** argv);
void WywolanieDefault(string** argv);

/**
    Funkcje sa UZYWANE w MAINIE gdy ktos poda komende i zgadza ona sie z odpowiednim slowem kluczem wywolywana jest odpowiednia FUNKCJA.
    Funkcje NIE SA wywolywane BEZPOSREDNIO poniewaz ich adresy sa zapisane w TABLICY WSKAZNIKOW NA FUNKCJE
    Czasami w srodku sa COUTY, ZABEZPIECZENIA, WYWOLANIA INNYCH PROGRAMOW
*/

#endif // WYWOLANIA
