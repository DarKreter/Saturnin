#include "../_Headers/funkcje.h"

int main()
{
    fstream plik;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";
    int nasz_kolor, kolor_saturnina;
    ///KOLORY
    plik.open(nazwa.c_str(),ios::out|ios::app);
    plik.close();
    plik.open(nazwa.c_str(),ios::in);
    if(plik.good()==false)
    {
        czy_wszystko_ok= false;
        sprawdzacz_bledow(0);
    }
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();
    saturnin_mowi(kolor_saturnina);
    cout << "Losowo - Uruchamia tryb losowego puszczania piosenek\n"
         << "Powtarzaj - Uruchamia tryb powtarzania wszystkich piosenek po przejsciu playlisty\n"
         << "Powtarzaj jeden - Uruchamia tryb powtarzania jednej piosenki\n"
         << "Graj - Puszcza piosenke\n"
         << "Pomija jedna piosenke i puszcza nastepna\n"
         << "Wyjdz - Wylacza Saturnin.mp3\n";
    while(true)
    {
        Sleep(1000);
    }
    return 0;
}
