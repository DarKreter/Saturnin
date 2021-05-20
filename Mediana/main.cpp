#include "../_Headers/funkcje.h"

int main(int argc, char*argv[])
{
    srand(time(NULL));
     string odpowiedz_losowa[] = {"Otoz mediana brzmi ","Udalo mi sie, mediana to ","Bez problemu doszedlem ze mediana rowna sie ",
                            "Odpowiedz ktorej oczekujesz jest nastepujaca ","Wynikiem jest ","Zakladam ze mediana to ","To bylo proste mediana wynosi ",
                            "Mediana to "};
    string odp = "";
    fstream plik;
    long double wynik;
    int nasz_kolor, kolor_saturnina,czas;

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
    plik>> kolor_saturnina >> nasz_kolor;
    plik.close();


    string linia="";
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
    czy_wszystko_ok=true;
    odp="";
    while(usp(odp) == "")
    {
        saturnin_mowi(kolor_saturnina);
        cout << "Podaj liczby: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        saturnin_mowi(kolor_saturnina);
    }
    if(usp(modp(odp)) == "/wyjdz"){
        zegnaj(kolor_saturnina,odp);
        getch();
        return EXIT_SUCCESS;
    }
    dalej:
    saturnin_mowi(kolor_saturnina);
    czas = rand()%8;
    wynik = mediana (odp);
    cout <<odpowiedz_losowa[czas]<<wynik<<endl;
    }
}
