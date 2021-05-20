#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
    srand(time(NULL));
   string losowa_odpowiedz[] = {"Silnia wynosi ","Silnia rowna sie ","Silnia to ","To bylo proste silnia wynosi ","Otoz wynik brzmi ",
                            "Udalo mi sie, silnia to ","Bez problemu doszedlem ze wynik rowna sie ",
                            "Odpowiedz ktorej oczekujesz jest nastepujaca ","Zakladam ze silnia to ","Silnia przyjmuje wartosc "};
    string odp;
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


    string linia = "";
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
    czy_wszystko_ok = true;
        saturnin_mowi(kolor_saturnina);
         cout << "Podaj liczbe dla jakiej chcesz policzyc silnie: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        usp(odp,0,0,1,1);
        saturnin_mowi(kolor_saturnina);
    if(usp(modp(odp)) == "/wyjdz"){
        zegnaj(kolor_saturnina,odp);
        getch();
        return EXIT_SUCCESS;
    }
    dalej:
    saturnin_mowi(kolor_saturnina);
    long double x;
    x = silnia(odp);
    cout << setprecision(10000);   ///No coz duzy limit
    int los = rand() % 10 ;
    if(czy_wszystko_ok == false)
    {
        sprawdzacz_bledow(x);
    }
    else
    cout<<losowa_odpowiedz[los]<<x<<endl;
    }
}
