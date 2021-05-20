#include "../_Headers/funkcje.h"
#include "Funkcje_ranking.h"

vector <string> nazwy,wykonawcy,linki,oceny,liczby_ocen;

int main(){
    fstream plik;
    string linia;
    int nasz_kolor, kolor_saturnina;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

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

    ///WCZYTANIE UZYTKOWNIKA JAKIM JESTESMY
    nazwa = lokacja + "ranking";
    plik.open(nazwa.c_str(),ios::in);
    getline(plik,linia);
    string uzytkownik = linia;
    if(uzytkownik == "") uzytkownik = "Gosc";
    plik.close();
    plik.open(nazwa.c_str(),ios::out);
    plik.close();
    ///---------------------------------------------------------------------------------
    //uzytkownik = "Daniel";
    ///---------------------------------------------------------------------------------
    /// WYCZTANIE DO VECTOROW
    string nazwa_pliku;
    nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
    plik.open(nazwa_pliku.c_str(),ios::in);
    int licznik = 0, liczmy = 0;
    while(getline(plik,linia))  ///Wpisanie pliku  pod vectory
    {
        if(licznik % 5 == 0)
        {
            nazwy.push_back(linia);
        }
        else if(licznik % 5 == 1)
        {
            wykonawcy.push_back(linia);
        }
        else if(licznik % 5 == 2)
        {
            linki.push_back(linia);
        }
        else if(licznik % 5 == 3)
        {
            oceny.push_back(linia);
        }
        else if(licznik % 5 == 4)
        {
            liczby_ocen.push_back(linia);
            liczmy ++ ;
        }
        licznik ++;
    }
    plik.close();

    ///FUNKCJA SORTUJACA PLIK
    sortowanie_pliku(uzytkownik);

    saturnin_mowi(kolor_saturnina);
    cout << "Oto ranking dla uzytkownika " << uzytkownik << endl;
    for(int i = 0; i < nazwy.size(); i++)
    {
        cout << oceny[i]
             << (oceny[i] == "10" ? "": " ")
             << " - "
             << nazwy[i]
             << " wyk. "
             <<wykonawcy[i]
             <<endl;
    }
    while(true)
    {
        Sleep(1000);
    }
    return 0;
}


