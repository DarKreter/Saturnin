#include "..\_Headers\funkcje.h"

int main(){
    srand(time(NULL));
    fstream plik;
    string odp, dwojkowy_sd = "", dwojkowy_sz = ""; int z_czego = 0, na_co = 0;  /// Systemy
    string odp_losowa[] =
    {
      "Po przeliczeniu wyszla mi nastepujaca liczba: ", "Oto liczba ktora cie zadowoli: ", "W tym systemie liczba wynosi: ", "Wyszla mi nastepujaca liczba: ", "W tym systemie ta liczbe przedstawiamy jako: "
    };

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    ///KOLORY
    int kolor_saturnina, nasz_kolor;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();


    plik.open("../Pliki/system_pamiec",ios::in); ///Wczytujemy ostatnie wybory systemow
    if(plik.good() == false)
    {
        ///Jesli nie znalazl pliku robi z 10 na 16
        z_czego = 10;
        na_co = 16;
    }
    else
    {
        getline(plik,odp);
        z_czego = string_na_int(odp);
        getline(plik,odp);
        na_co = string_na_int(odp);
        getline(plik,odp);
        dwojkowy_sz = odp;
        getline(plik,odp);
        dwojkowy_sd = odp;
    }
    plik.close();
    //cout << z_czego << endl << na_co;
    wyczyszczenie:
    ///ZAWSZE TRZEBA TO NA GORZE PROGRAMU WYSWIETLAC ZEBY KAZDY WIEDZIAL
    saturnin_mowi(kolor_saturnina);
    cout << "Zmieniam teraz z systemu "
         << z_czego
         << (dwojkowy_sz != "" ? " " : "")
         << (dwojkowy_sz != "" ? dwojkowy_sz : "")
         << " na system "
         << na_co
         << " "
         << (dwojkowy_sd != "" ? dwojkowy_sd : "")
         <<  endl;
    cout << "Jesli chcesz zmienic system zrodlowy uzyj komendy \"sz\"\nJesli chcesz zmienic system docelowy uzyj komendy \"sd\"\n";
    long double wynik = 0;

    for(;;)
    {
        czy_wszystko_ok = true;
        saturnin_mowi(kolor_saturnina);
        cout << "Podaj liczbe do przeliczenia: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        if(usp(odp) == "")
            continue;
        saturnin_mowi(kolor_saturnina);
        ///Idziemy sobie
        if(usp(zmiana_wielkosci_liter(zamiana_polskich_znakow(odp))) == "/wyjdz")
        {
            zegnaj(kolor_saturnina,odp);
            getch();
            return EXIT_SUCCESS;
        }
        ///Zmieniamy system zrodlowy
        else if(usp(zmiana_wielkosci_liter(zamiana_polskich_znakow(odp.substr(0,2)))) == "sz")
        {
            odp.erase(0,2);
            int x = z_czego;
            zmiana_systemu(0,x,odp, nasz_kolor, kolor_saturnina, dwojkowy_sz);
            if(czy_wszystko_ok == false) ///Jakby funkcja zwrocila blad
            {
                int err = x;
                sprawdzacz_bledow(err);
                continue;
            }
            ///Jesli nie to mozemy nadpisac zmienna oraz plik
            z_czego = x;
            plik.open("../Pliki/system_pamiec",ios::out);
            plik  << z_czego << endl << na_co << endl << dwojkowy_sz <<endl<< dwojkowy_sd;
            plik.close();
            system("cls");
            goto wyczyszczenie;
        }
        ///Zmieniamy system docelowy
        else if(usp(zmiana_wielkosci_liter(zamiana_polskich_znakow(odp.substr(0,2)))) == "sd")
        {
            odp.erase(0,2);
            int x = na_co;
            zmiana_systemu(1,x,odp, nasz_kolor, kolor_saturnina, dwojkowy_sd);
            if(czy_wszystko_ok == false) ///Jakby funkcja zwrocila blad np nie ma takiego systemu
            {
                int err = x;
                sprawdzacz_bledow(err);
                continue;
            }
            ///Jesli wszystko ok to podmieniamy zmienna oraz plik
            na_co = x;
            plik.open("../Pliki/system_pamiec",ios::out);
            plik  << z_czego << endl << na_co << endl << dwojkowy_sz <<endl<< dwojkowy_sd;
            plik.close();
            system("cls");
            goto wyczyszczenie;
        }
        ///uzywamy swietej funkcji
        odp = system_liczeniowy(odp,z_czego,na_co, dwojkowy_sd, dwojkowy_sz);
        if(czy_wszystko_ok == false) ///Bledzik
        {
            czy_wszystko_ok = true;
            int err = string_na_int(odp);
            czy_wszystko_ok = false;
            sprawdzacz_bledow(err);
        }
        else ///No i odpowiedz losowa =)
        {
            int los = rand() % 5;
            cout << odp_losowa[los] << odp << endl;
        }
    }
    return 0;
}
