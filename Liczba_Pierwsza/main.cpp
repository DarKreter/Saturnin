#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
   srand(time(NULL));
      string odpowiedz_losowa[] = { " jest liczba pierwsza!"," oczywiscie jest liczba pierwsza!"," zaiste jest liczba pierwsza"," to napewno liczba pierwsza"};
        string odpowiedz_losowa1[] = { " nie jest liczba pierwsza!"," oczywiscie nie jest liczba pierwsza!"," zaiste to nie liczba pierwsza"," to z pewnosci nie liczba pierwsza liczba pierwsza"};
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
    plik.open(nazwa.c_str(),ios::out|ios::app);
    plik.close();
    plik.open(nazwa.c_str(),ios::in);
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
//    cout << "\"" <<linia<< "\"\n";
    if(linia!=""){
        odp = linia;
        goto dalej;

    }
    for(;;){
    czy_wszystko_ok = true;
    odp="";
    while(usp(odp) == "")
    {
        saturnin_mowi(kolor_saturnina);
        cout << "Podaj liczbe do sprawdzenia: ";
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
                    wynik=l_pierwsza(odp);
                    if(czy_wszystko_ok==false) {
                        sprawdzacz_bledow(wynik);
                        continue;
                    }
                    else if(wynik==1){
                        int los = rand()%4;
                        cout<<odp <<odpowiedz_losowa[los]<<endl;
                    }
                    else{
                        int los1 = rand()%4;
                        cout<<odp<<odpowiedz_losowa1[los1]<<endl;
                        }
    }
}
