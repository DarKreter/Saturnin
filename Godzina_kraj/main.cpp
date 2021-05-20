#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
    int nasz_kolor, kolor_saturnina;
    fstream plik; string odp;

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

    string linia = "";
    argv++;
	for(int i = 1; i<argc; i++)
	{
		linia += *argv;
		argv++;
		if(i!=argc-1)linia+= " ";
	}
    if(linia != ""){
        odp = usp(modp(linia));
        goto dalej;
    }

    for(;;)
    {
        saturnin_mowi(kolor_saturnina);
        cout << "Podaj kraj w jakim chcesz sprawdzic godzine: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        if(usp(odp) == "")
        {
            continue;
        }
        else if(usp(modp(odp)) == "/wyjdz")
        {
            saturnin_mowi(kolor_saturnina);
            zegnaj(kolor_saturnina,odp);
            getch();
            return EXIT_SUCCESS;
        }
        dalej:
        saturnin_mowi(kolor_saturnina);
        odp = usp(modp(odp));
        saturnin_mowi(kolor_saturnina);
        sprawdzanie_godziny_w_innym_kraju(odp,nasz_kolor,kolor_saturnina);
    }
    }

