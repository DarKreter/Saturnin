#include "../_Headers/funkcje.h"

int main(int argc, char*argv[])
{
    string odpowiedz_losowa[]  = {"Stwierdzam ze to palindrom","Napis jest palindromem","Otoz napis jest palindromem","Napis to palindrom","Otoz tym razem to byl palindrom","Zaiste palindromem to jest"};
    string odpowiedz_losowa1[] = {"Obawiam sie ze to nie jest palindrom","Napis nie jest palindromem","Otoz napis nie jest palindromem","Otoz tym razem to nie byl palindrom","Zaiste palindromem to nie jest", "Stwierdzam ze to nie jest palindrom"
                                 };
    fstream plik; string odp;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    int nasz_kolor, kolor_saturnina,czas;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik>> kolor_saturnina >> nasz_kolor;
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
    cout << "Podaj palindrom: ";
    saturnin_mowi(nasz_kolor);
    getline(cin,odp);
    if(usp(modp(odp)) == "/wyjdz")
    {
        saturnin_mowi(kolor_saturnina);
        zegnaj(kolor_saturnina,odp);
        getch();
        return EXIT_SUCCESS;
    }
    saturnin_mowi(kolor_saturnina);
    dalej:
    saturnin_mowi(kolor_saturnina);
    if(palindrom(odp)==true)
    {
        int los = rand()%6;
        cout<<odpowiedz_losowa[los]<< endl;
    }
    else
    {
        int los1 = rand()%6;
        cout<<odpowiedz_losowa1[los1]<<endl;
    }
    }
}
