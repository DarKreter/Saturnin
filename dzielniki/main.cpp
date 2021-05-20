#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
    string odpowiedz_losowa[] = {"Liczba ma ","Liczba posiada ","Liczba ma rowno "};
    string odpowiedz_losowa_2[] = {" dzielnikow, oto one:"," dzielnikow widzisz je ponizej:", " dzielnikow to one:"," dzielnikow, zobacz nizej:"," dzielnikow, wypisze ci je tutaj:"};
    string odp; fstream plik;
    long double wynik; int licznik;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    int kolor_saturnina, nasz_kolor;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();

    string linia = "";
    argv++;
	for(int i = 1; i<argc; i++)
	{
		linia += *argv;
		argv++;
		if(i!=argc-1)linia+= " ";
	}
    if(linia!="")
    {
        odp = linia;
        goto dalej;
    }

    for(;;)
    {
        saturnin_mowi(kolor_saturnina);
        cout << "Podaj liczbe do wyliczenia dzielnikow: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        if(usp(modp(odp)) == "/wyjdz")
        {
            saturnin_mowi(kolor_saturnina);
            zegnaj(kolor_saturnina,odp);
            getch();
            return EXIT_SUCCESS;
        }
        dalej:
        saturnin_mowi(kolor_saturnina);
        czy_wszystko_ok = true;
        wynik = dzielniki(odp);
        licznik = 0;
        if(czy_wszystko_ok==false)
        {
            sprawdzacz_bledow(wynik);
            continue;
        }
        else if(lista_globalna.empty() == true)
        {
            cout<<"Liczba nie ma dzielnikow"<<endl;
            continue;
        }
        int los = rand() % 3, los2 = rand()% 5; ///Losujemy odpowiedzi
        string dlugosc = int_na_string(lista_globalna.size());
        dlugosc = modp(dlugosc,0,0,0,1) ; ///Odwracamy zeby bylo latwiej i brac pierwsza nie ostatnia
        ///Powalony warunek bo jesli ostatnia cyfra to 2 3 4 i dlugosc to 1
        ///Ale odwrocilismy wiec pierwsza nie ostatnia
        if((dlugosc.substr(0,1) == "2"||dlugosc.substr(0,1) == "3"||dlugosc.substr(0,1) == "4")&&(dlugosc.length() == 1))
        {
            string x = odpowiedz_losowa_2[los2];
            x.replace(9,2,"i");         ///Zmieniamy "ow" na "i"     "Dzielnikow" -> "Dzielniki"
            odpowiedz_losowa_2[los2] = x;
        }
        else if(dlugosc.length() > 1)   ///Jesli dlugosc jest wieksza od 1 zeby moc zrobic substr z przedostatniej
        {
            ///Warunek bo jesli ostatnia cyfra to 2 3 4 a przed ostatnia jest rozna od 1 to mowimy dzielniki nie dzielnikow
            if((dlugosc.substr(0,1) == "2"||dlugosc.substr(0,1) == "3"||dlugosc.substr(0,1) == "4")&&(dlugosc.substr(1,1) != "1"))
            {
                string x = odpowiedz_losowa_2[los2];
                x.replace(9,2,"i");         ///Zmieniamy "ow" na "i"     "Dzielnikow" -> "Dzielniki"
                odpowiedz_losowa_2[los2] = x;
            }
        }
        cout<< odpowiedz_losowa[los]<< lista_globalna.size() << odpowiedz_losowa_2[los2] << endl; ///Wypisujemy odpowiedzi losowe

        string help = int_na_string(lista_globalna.back());
        int register x = help.length();

        for(list<long double> ::iterator i = lista_globalna.begin(); i != lista_globalna.end(); ++i)
        {
            licznik++;
            cout<<*i<<" ";
            string help = int_na_string(*i);
            for(int register j = 0;j < x - help.length();j++)
            {
                cout << " ";
            }
            if(licznik==10)
            {
                licznik=0;
                cout<<endl;
            }
        }
        cout<<endl;
    lista_globalna.clear();
    }
}
