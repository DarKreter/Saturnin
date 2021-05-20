#include "..\_Headers\funkcje.h"

int main()
{
    fstream plik; int kolor_saturnina, nasz_kolor;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    plik.open(nazwa.c_str(),ios::out|ios::app);
    plik.close();
    plik.open(nazwa.c_str(),ios::in);
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();
    saturnin_mowi(kolor_saturnina);
    cout << "Zostales Wyzwany w kolko i krzyzyk!" ;
    getch();
}
