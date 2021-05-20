#include "../_Headers/funkcje.h"

int main()
{
    int nasz_kolor, kolor_saturnina,kolor_saturnina1;
    fstream plik;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();

    clock_t start, stop; ///Zmienne mogace pobierac liczbe cykli procesora
    double czas;

    start = clock();  ///Pobieramy liczbe cykli
    odczyt(kolor_saturnina,nasz_kolor);
    for(;;)
    {
        if(czas > 1) ///Jesli minela sekudna aktualizujemy
        {
            system("cls");
            odczyt(kolor_saturnina,nasz_kolor);
            start = clock();  ///Musimy nadpisac start zeby nie wchodzil tu caly czas tylko  co sekunde
        }
        stop = clock(); ///I znowu
        czas = (double)(stop - start) / CLOCKS_PER_SEC ; ///Teraz roznice podzielona przez stala z komputera daje wynik w sekundach

        plik.open(nazwa.c_str(),ios::in); ///TU
        if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
        plik >> kolor_saturnina1 >> nasz_kolor;
        plik.close();
        if(kolor_saturnina1 != kolor_saturnina)
        {
            kolor_saturnina = kolor_saturnina1;
        }

    }
    return 0;
}
