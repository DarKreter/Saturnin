#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
    int kolor_saturnina,nasz_kolor; fstream plik; string odp,linia = "";

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
        cout<< "Prosze podac liczby do posegregowania:";
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
         string odpowiedz_losowa[] = {"Posegregowalem to z latwoscia:", "Oto posegregowane liczby:","Po segregacji wyglada to tak:","Po chwili ulozylem liczby w tej oto kolejnosci:","Wedlug mnie po segregacji bedzie to wygladac tak:","Jestem pewien ze wygladac to bedzie tak:1 2 3\nSorry cwicze modul z sztucznym poczuciem humoru, oto poprawna kolejnosc:"
                            };

        segregowanie(odp);

        int los = rand() %6;
        if(czy_wszystko_ok == true)     cout<<odpowiedz_losowa[los];

        for(list<long double> ::iterator i = lista_globalna.begin(); i != lista_globalna.end(); ++i)
                            {
                                cout<<*i<<" ";
                            }
                            cout<< endl;
        continue;


    }
    return 0;
}
