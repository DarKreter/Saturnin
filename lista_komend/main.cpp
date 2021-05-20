#include <windows.h>
#include "..\_Headers\funkcje.h"

int main()
{
    fstream komendy,plik;
    string linia;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    int nasz_kolor, kolor_saturnina,czas, kolor_saturnina1;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false)
    {
        czy_wszystko_ok= false;
        sprawdzacz_bledow(0);
    }
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();
    komendy.open("../Pliki/lista_komend",ios::in);
    saturnin_mowi(kolor_saturnina);
    while(getline(komendy,linia))
    {
        cout << linia <<endl ;
    }
    komendy.close();
    ///Zeby sie nie wwylaczal
    for(;;)
    {
        int nasz_kolor, kolor_saturnina,czas;
        plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
        plik.close();
        plik.open(nazwa.c_str(),ios::in); ///TU
        if(plik.good()==false)
        {
            czy_wszystko_ok= false;
            sprawdzacz_bledow(0);
        }
        plik >> kolor_saturnina1 >> nasz_kolor;
        plik.close();
        if(kolor_saturnina1 != kolor_saturnina)
        {
            system("cls");
            kolor_saturnina = kolor_saturnina1;
            komendy.open("../Pliki/lista_komend",ios::in);
            saturnin_mowi(kolor_saturnina);
            while(getline(komendy,linia))
            {
                cout << linia <<endl ;
            }
            komendy.close();
        }
    }
    return 0;
}
