#include <iostream>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <cmath>
#include <time.h>
#include <cctype>
#include <string>
#include <algorithm>
#include <list>
#include "..\Szachy-Funkcje.h"
#include <conio.h>
using namespace std;


int main()
{
    string lokacja,uzytkownik,przeciwnik;
    fstream file;

    file.open("../Pliki/lokalizacja",ios::in);
    getline(file,lokacja);
    file.close();
    lokacja += "Saturnin/";

    file.open((lokacja + "kolory").c_str(),ios::in); ///TU
    if(file.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(10);}
    file >> kolor_saturnina >> nasz_kolor;
    file.close();

    file.open((lokacja+"szachy_who").c_str(),ios::in);
    file >> uzytkownik;
    file.close();
    file.open((lokacja+"szachy_who").c_str(),ios::out); file.close();

    file.open((lokacja+"szachy-wyzwanie_who").c_str(),ios::in);
    file >> przeciwnik;
    file.close();
    file.open((lokacja+"szachy-wyzwanie_who").c_str(),ios::out); file.close();

    int wybor=0;
    while(1){
        system("cls");

        saturnin_mowi(kolor_saturnina);
        cout<<"Zostales wyzwany w Szachy przez uzytkownika "<<przeciwnik<<"!"<<endl;
        cout<<"Podejmujesz sie wyzwania?"<<endl;

        saturnin_mowi(nasz_kolor);
        if (wybor==0) cout<<"-"; else cout<<" ";
        cout<<"TAK"<<"    ";

        if (wybor==1) cout<<"-"; else cout<<" ";
        cout<<"NIE";

        switch(sprawdzacz_klawiszow()){
            case 97:
                if(wybor!=0) wybor=0;
            break;
            case 100:
                if(wybor!=1) wybor=1;
            break;
            case 13:
            string odp= (wybor==0) ? "TAK":"NIE";

            file.open(("../Szachy/Szachy-Online/Zaproszenia/"+uzytkownik+".txt").c_str(),ios::out);
            file << odp<<endl<<nasz_kolor;
            file.close();

            if(wybor==1) return 0;
//            cout<<"tu"<<endl;
            system("cls");
            saturnin_mowi(kolor_saturnina);
            cout<<"Konfigurowanie Rozgrywki..."<<endl;
            gramy_gosc(uzytkownik,przeciwnik);
            break;
        }



    }
}
