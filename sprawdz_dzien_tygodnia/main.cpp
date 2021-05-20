#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
    srand(time(NULL));
    string odp_losowa[] = {"Byl wtedy ","Wtedy byl ","Dniem tym byl ","Ten dzien to ","Dzien tygodnia o ktory ci chodzi to "};
    string odp_losowa1[] = {"Byla wtedy ","Wtedy byla ","Dniem tym byla ","Ten dzien to ","Dzien tygodnia o ktory ci chodzi to "};
    string odp_losowa2[] = {"Wtedy bedzie ", "Bedzie wtedy ","Dniem tym bedzie ", "Ten dzien to bedzie ", "Dzien tygodnia o ktory ci chodzi to "};
    string odp;
    fstream plik;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    int nasz_kolor, kolor_saturnina, kiedy_czas = 17;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();

    bool specjalna_data = false ;
    saturnin_mowi(kolor_saturnina);

    string linia = "";
    argv++;
	for(int i = 1; i<argc; i++)
	{
		linia += *argv;
		argv++;
		if(i!=argc-1)linia+= " ";
	}

    if(linia != "")
    {
        odp = modp(linia);
        goto dalej;
    }

    for(;;)
    {
    cout<<"Wprowadz date (rok miesiac dzien): ";
    saturnin_mowi(nasz_kolor);
    getline(cin,odp);
    saturnin_mowi(kolor_saturnina);
    if(usp(odp) == "")  continue;
    if(usp(modp(odp)) == "/wyjdz")
    {
        zegnaj(kolor_saturnina,odp);
        getch();
        return EXIT_SUCCESS;
    }
    dalej:
    czy_wszystko_ok = true;
    specjalna_data = false ;
    //cout << "Przed uzyciem funckji\n";
    odp = sprawdzanie_dnia_tygodnia(odp,specjalna_data, kiedy_czas);
    //cout << "Po uzyciu funkcji\n";
    if(czy_wszystko_ok == false)
    {
        czy_wszystko_ok = true ;///podoba mi sie - Alex
        long double x;
        x = string_na_int(odp);///Potrzebne poniewaz int na string ma takiego zlego ifa
        czy_wszystko_ok = false;
        sprawdzacz_bledow(x);
    }
    else if(specjalna_data == true)
    {
        cout << odp << endl;
    }
    else if(kiedy_czas == 1) ///Przeszlosc
    {
        int los = rand() % 5;
        if(odp == "Sroda"||odp == "Sobota"||odp == "Niedziela")
        cout << odp_losowa1[los];
        else cout << odp_losowa[los];
        cout << odp << endl;
    }
    else if(kiedy_czas == 10) ///Przyszlosc
    {
        int los = rand() % 5;
        cout << odp_losowa2[los]<< odp << endl;
    }
    else ///Teraz
    {
        cout << "Dzis jest " << odp << endl;
    }
    }
}

///Daty przeszle
