#include "../_Headers/funkcje.h"
#include "Funkcje_Komunikator.h"


void rozdzielenie(string napis, string &pierwsza_czesc, string &druga_czesc){
    pierwsza_czesc = napis;
    druga_czesc = "";
    for(int i = 0;i < napis.length();i++)
    {
        if(napis.substr(i,1) == ":")
        {
                pierwsza_czesc.clear();
                pierwsza_czesc.insert(0,napis.substr(0,i+1));
                druga_czesc.insert(0,napis.substr(i+1,napis.length()));
                break;

        }
    }

}

void rozdzielenie_historia(string napis, string &pierwsza_czesc, string &druga_czesc){
    int x = 0;
    pierwsza_czesc = napis;
    druga_czesc = "";
    for(int i = 0;i < napis.length();i++)
    {
        if(napis.substr(i,1) == ":")
        {
            if(x == 1){
                pierwsza_czesc.clear();
                pierwsza_czesc.insert(0,napis.substr(0,i+1));
                druga_czesc.insert(0,napis.substr(i+1,napis.length()));
                break;
            }
            else x++;

        }
    }

}

Komunikator::Komunikator(string u){  ///Konstruktor
    uzytkownik = u; ///Musimy miec uzytkownika
}

Komunikator::~Komunikator(){ ///Destruktor   WPISUJEMY DO PLIKU ZE OPUSCILISMY CZAT ORAZ DO HISTORII

    fstream plik; string operacje_na_plikach;
    operacje_na_plikach ="../komunikator/" + uzytkownik ;
    plik.open(operacje_na_plikach.c_str(),ios::out|ios::app);   ///Czyscimy plik po wyjsciu z komunikatora
    plik <<endl<< uzytkownik << " opuscil czat...";
    plik.close();
    plik.open("../komunikator/historia",ios::out|ios::app);
    string x = sprawdzanie_czasu(0), y = sprawdzanie_daty(), kupa;
    x.erase(5,x.length());
    y = y.substr(5,5); ///Data, godzina
    kupa = y.substr(0,2);
    y.replace(0,2,y.substr(3,2));
    y.replace(3,2,kupa);
    plik <<y<<" "<<x <<" "<< uzytkownik << " opuscil czat..."<<endl; ///Wpisujemy do historii ze sobie poszlismy
    plik.close();
}
