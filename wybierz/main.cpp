#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
  int kolor_saturnina,nasz_kolor; fstream plik; string odp,linia = "";
  int losowanko;
  string mozliwosci[5]={"Wybralem ","Jestem za ","Wybieram ","Moj wybor to ","moim wyborem jest "};

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
            saturnin_mowi(kolor_saturnina);  cout<< "Prosze podac wybory oddzielone spacjami:";
            saturnin_mowi(nasz_kolor);       getline(cin,odp);

        if(odp==""){
            goto poczatek;
        }
        else if(modp(usp(odp))=="/wyjdz"){
            saturnin_mowi(kolor_saturnina);
            zegnaj(kolor_saturnina, odp);
            getch();
            return EXIT_SUCCESS;
        }

        dalej:
            losowanko=rand()%5;

            saturnin_mowi(kolor_saturnina);
            cout<< mozliwosci[losowanko];


            saturnin_mowi(nasz_kolor);
            cout<< wybierz(odp)<<endl;


        continue;


    }
    return 0;
}
