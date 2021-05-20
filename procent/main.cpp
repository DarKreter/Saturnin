#include "../_Headers/funkcje.h"

int main()
{
int kolor_saturnina,nasz_kolor; fstream plik; string odp,linia;
  short int losowanko, tryb; long double wynik;
  string mozliwosci[5]={"Wynik wynosi ","Wynik jest nastepujacy ","Jest to ","Wynik to ","Procent wynosi "};

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
    plik >> kolor_saturnina>> nasz_kolor;
    plik.close();

    bool pierwszy_raz=true; ///patrzy czy przed chwila nie wpisales blednej liczby w zmianie trybu
    poooooooczatek:

    saturnin_mowi(kolor_saturnina); cout<<"1. Licze procent liczb X z Y\n"
                                          "2. Licze procent z liczby\n"
                                          "3. Licze 100% liczby na podstawie procentu i liczby\n";
                                    cout<< (pierwszy_raz==true ? "Prosze wybrac tryb dzialania:" : "Prosze wybrac poprawny tryb dzialania:");
    saturnin_mowi(nasz_kolor); getline(cin,odp);

    if(odp==""){
        system("cls");
        goto poooooooczatek;
    }
    else if(odp=="1"||odp=="01") {tryb=1; system("cls");}
    else if(odp=="2"||odp=="02") {tryb=2; system("cls");}
    else if(odp=="3"||odp=="03") {tryb=3; system("cls");}
    else if(odp=="/wyjdz") {
            zegnaj(kolor_saturnina, odp);
            getch();
            return EXIT_SUCCESS;
    }
    else {
        system("cls");
        pierwszy_raz=false;
        goto poooooooczatek;
    }
    pierwszy_raz=true; ///zerujemy pierwszy raz
    saturnin_mowi(kolor_saturnina);
    cout << "Wybrano tryb ";
    switch(tryb){
         case 1:
            cout<<"liczenia procent pierwszej liczby z drugiej"<<ENDL;
        break;
         case 2:
            cout<<"liczenia procent z liczby"<<ENDL;
        break;
         case 3:
            cout<<"liczenia liczby na podstawie procentu i liczby z tego procentu"<<ENDL;
        break;
    }
    cout<<"By zmienic tryb wpisz: /zmien tryb"<<endl;
    for(;;){
        poczatek:

            czy_wszystko_ok=true;
            saturnin_mowi(kolor_saturnina);  cout<< "Prosze podac 2 liczby:";
            saturnin_mowi(nasz_kolor);       getline(cin,odp);

        if(odp==""){
            goto poczatek;
        }
        else if(zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/wyjdz"){
            zegnaj(kolor_saturnina, odp);
            getch();
            return EXIT_SUCCESS;
        }
        else if(zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/tryb1"){ tryb=1;saturnin_mowi(kolor_saturnina); cout<<"Zmieniono tryb"<<endl;continue;}
        else if(zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/tryb2"){ tryb=2;saturnin_mowi(kolor_saturnina); cout<<"Zmieniono tryb"<<endl;continue;}
        else if(zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/tryb3") {tryb=3;saturnin_mowi(kolor_saturnina); cout<<"Zmieniono tryb"<<endl;continue;}
        else if(zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/zmientryb1") {tryb=1;saturnin_mowi(kolor_saturnina); cout<<"Zmieniono tryb"<<endl;continue;}
        else if(zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/zmientryb2") {tryb=2;saturnin_mowi(kolor_saturnina); cout<<"Zmieniono tryb"<<endl;continue;}
        else if(zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/zmientryb3") {tryb=3;saturnin_mowi(kolor_saturnina); cout<<"Zmieniono tryb"<<endl;continue;}
        else if(zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/tryb"||zamiana_polskich_znakow(zmiana_wielkosci_liter(usp(odp)))=="/zmientryb"){
            system("cls");
            goto poooooooczatek;
        }
        dalej:
            losowanko=rand()% ( tryb==1 ? 5 : 4 );

            wynik=procent(odp,tryb);
            saturnin_mowi(kolor_saturnina);
            if(czy_wszystko_ok==false){
                sprawdzacz_bledow(wynik);
                continue;
            }


            cout<< mozliwosci[losowanko];
            cout<<setprecision(6);
            saturnin_mowi(nasz_kolor);
            cout<< wynik;
            if(tryb==1) cout<<"%";
            cout<< ENDL;
        continue;


    }
    return 0;
}
