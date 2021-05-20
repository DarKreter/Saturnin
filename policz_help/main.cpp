#include "../_Headers/funkcje.h"

int main(){
    fstream plik;
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
    fstream help; string linia;
    string kupa[3][82];
    help.open("../Pliki/help_policz",ios::in);
    saturnin_mowi(kolor_saturnina);
    short licznik =1;
    plik.open("../Pliki/help_dla_help_do_policz",ios::in);
    int first, second;
    plik >> first >> second;
    plik.close();
    while(getline(help,linia))
    {
        if(licznik < first) kupa[0][licznik] = linia;
        else if(licznik > first-1 && licznik < second) kupa[1][licznik-first] = linia;
        else kupa[2][licznik-second] = linia;
        licznik ++;
    }
    help.close();
    licznik = 0;
    for(int i=0;i<82;i++)
    {
        cout << kupa[licznik][i] <<endl;
    }
    ustaw_wskaznik(1,1);
    ///Zeby sie nie wwylaczal
    for(;;)
    {
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
                saturnin_mowi(kolor_saturnina);
                for(int i=0;i<82;i++)
                {
                    cout << kupa[licznik][i] <<endl;
                }
                ustaw_wskaznik(1,1);
        }
        if(kbhit() == true)
        {
            short x = getch();
            if(x == 100 && licznik != 2)
            {
                licznik ++;
                system("cls");
                for(int i=0;i<82;i++)
                {
                    cout << kupa[licznik][i] <<endl;
                }
                ustaw_wskaznik(1,1);
            }
            else if(x == 97 && licznik != 0)
            {
                licznik --;
                system("cls");
                for(int i=0;i<82;i++)
                {
                    cout << kupa[licznik][i] <<endl;
                }
                ustaw_wskaznik(1,1);
            }
        }
    }
    return 0;
}
