#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
    int kolor_saturnina,nasz_kolor; fstream plik; string odp,linia="";

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

    argv++;
	for(int i = 1; i<argc; i++)
	{
		linia += *argv;
		argv++;
		if(i!=argc-1)linia+= " ";
	}
    if(linia!=""){
        odp = linia;
        goto dalej;

    }

    for(;;){
        poczatek:
        czy_wszystko_ok=true;
        saturnin_mowi(kolor_saturnina);
        cout<< "Prosze podac liczby do policzenia sredniej:";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        if(odp==""){
            goto poczatek;
        }
        else if(modp(usp(odp))=="/wyjdz"){
            zegnaj(kolor_saturnina, odp);
            return EXIT_SUCCESS;
        }
        dalej:
            saturnin_mowi(kolor_saturnina);
         string odpowiedz_losowa[] = {"Otoz wynik brzmi ","Udalo mi sie, srednia to ","Bez problemu doszedlem ze srednia rowna sie ",
                            "Odpowiedz ktorej oczekujesz jest nastepujaca ","Wynikiem jest ","Zakladam ze srednia to ","To bylo proste srednia wynosi ",
                            "Srednia to "};

        long double wynik = srednia(odp, 0);
        int los = rand() %8;
        if(czy_wszystko_ok == true)     cout<<odpowiedz_losowa[los];

        sprawdzacz_bledow(wynik);
        continue;


    }
    return 0;
}
