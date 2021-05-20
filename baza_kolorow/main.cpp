#include "..\_Headers\funkcje.h"

using namespace std;

int main()
{
    fstream plik;
    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/kolory";


    for(;;)
    {
        int kolor_saturnina, nasz_kolor;
        plik.open(lokacja.c_str(),ios::out|ios::app); ///TU
        plik.close();
        plik.open(lokacja.c_str(),ios::in); ///TU
        if(plik.good()==false)
        {
            czy_wszystko_ok= false;
            sprawdzacz_bledow(0);
        }
        plik >> kolor_saturnina >> nasz_kolor;
        plik.close();
        saturnin_mowi(kolor_saturnina);

        int nr_linii = 1,kolumny = 1, wiersze = 1;
        string linia;
        plik.open("../Pliki/dostepne_kolory",ios::in);    ///plik sie zamyka za gorze wiec mozna go otworzyc tutaj
        if(plik.good()==false)
        {
            czy_wszystko_ok=false;
            sprawdzacz_bledow(10);
            return 0;
        }
        linia="lolxd";
        while(getline(plik,linia))
        {
            if(linia == "WITAJ") break;
            if(nr_linii == 1)
            {
                ustaw_wskaznik(1,kolumny);
            }
            else if(nr_linii == 2)
            {
                ustaw_wskaznik(25,kolumny);
            }
            else if(nr_linii == 3)
            {
                ustaw_wskaznik(50,kolumny);
            }
            cout<<linia;
            if(nr_linii == 3)
            {
                //cout << nr_linii << " " << licznik <<endl;
                nr_linii = 0;
                //cout << "hej\n";
                kolumny++; ///Dodaje endl co 4 slowa
            }
            nr_linii++;
        }
        cout<<endl;
        plik.close();
        Sleep(5000);
        system("cls");
    }
    return 0;
}
