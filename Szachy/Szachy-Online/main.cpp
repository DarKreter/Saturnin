#include <iostream>
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
//#include "..\..\Pliki\funkcje.h"
#include "..\Szachy-Funkcje.h"
#include <conio.h>

using namespace std;


int main()
{
    srand(time(NULL));

    fstream plik;
    ///cout<<"Ala"<<endl;
    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";

    string nazwa = lokacja + "szachy_who";
    string uzytkownik="gowno";
    plik.open(nazwa.c_str(),ios::in);
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(10); getch(); return 0;}
    plik >> uzytkownik;
    plik.close();

    nazwa = lokacja + "kolory";
    int nasz_kolor, kolor_saturnina;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(10);}
    plik>> kolor_saturnina >> nasz_kolor;
    plik.close();

    /// MENU WYBORU

    int wybor=0;
    poczatek:
    for(;;){
        system("cls");

        saturnin_mowi(kolor_saturnina); cout << "GRA W SZACHY"<< endl;

        saturnin_mowi(nasz_kolor);
        if(wybor==0) cout << "-"; else cout<< " "; cout << "Graj online"<< endl;

        if(wybor==1) cout << "-"; else cout<< " "; cout << "Graj lokalnie"<< endl;

        if(wybor==2) cout << "-"; else cout<< " "; cout << "Tablica Wynikow"<< endl;

        if(wybor==3) cout << "-"; else cout<< " "; cout << "Instrukcja"<< endl;

        if(wybor==4) cout << "-"; else cout<< " "; cout << "Wyjdz"<< endl;

        unsigned char strzalka=getch();
        if(strzalka==224){
            switch(getch()){
                case 72: strzalka=119; /// strzalka w gore zamieniona na W
                    break;
                case 80: strzalka=115; /// strzalka w dol  zamieniona na S
                    break;
            }
        }


        switch(strzalka){
            case 119: /// gora
                if(wybor!=0) wybor--;
                break;
            case 115: /// dol
                if(wybor!=4) wybor++;
                break;
            case 13: /// enter
                switch(wybor){

                    case 0:{ /// gra online

                        if(uzytkownik=="Gosc"){
                            system("cls");
                            saturnin_mowi(kolor_saturnina); cout<< "Ta funkcja nie jest dostepna na koncie Goscia"<<endl;
                            getch();
                            goto poczatek;
                        }
                        int wybor=0;
                        while(1){
                            system("cls");
                            fstream plik; string nazwa,wyzwany_przeciwnik; unsigned char strzalka;
                            int licznik=0;

                            plik.open("../Pliki/logowanie",ios::in);
                            if(plik.good() == false){ sprawdzacz_bledow(20);}

                            for(int i=0;getline(plik,nazwa);i++){
                                if(wybor == i){
                                    cout<<"-";
                                    wyzwany_przeciwnik=nazwa;
                                } else cout<<" ";
                                cout<<nazwa<<endl;
                                getline(plik, nazwa);
                                licznik++;
                            }

                            strzalka=getch();

                            if(strzalka==224){
                                switch(getch()){
                                    case 72: strzalka=119; /// strzalka w gore zamieniona na W
                                        break;
                                    case 80: strzalka=115; /// strzalka w dol  zamieniona na S
                                        break;
                                }
                            }

                            switch(strzalka){
                                case 119:
                                    if(wybor!=0) wybor--;
                                    break;
                                case 115:
                                    if(wybor!=licznik-1) wybor++;
                                    break;
                                case 13:{  /// WYSYLANIE ZAPROSZENIA
                                    system("cls");
                                    saturnin_mowi(kolor_saturnina);
                                    cout<<"Wysylanie Zaproszenia..."<<endl;
                                    fstream plik;
                                    plik.open(("../Szachy/Szachy-Online/Zaproszenia/"+wyzwany_przeciwnik+".txt").c_str(),ios::out);
                                    plik << uzytkownik;
                                    plik.close();
                                    Sleep(3000);

                                    system("cls");
                                    cout<<"Oczekiwanie na odpowiedz";
//                                    plik.open(("Zaproszenia/"+wyzwany_przeciwnik+".txt").c_str(),ios::in); if(plik.good()==false) cout<<"hm cos tu jest powaznie nie tak"<<endl; plik.close();

                                    //cout<< wyzwany_przeciwnik<<" no nie "<<endl;
                                    while(1){
                                        string odpowiedz;
                                        plik.open(("../Szachy/Szachy-Online/Zaproszenia/"+wyzwany_przeciwnik+".txt").c_str(),ios::in); /// Sciezka wzgledna prowadzona jest od saturnin.exe !
                                        if(plik.good()==false) cout<<"hm cos tu jest powaznie nie tak"<<endl;
                                        plik >> odpowiedz;
                                        int kolor_przeciwnika;
                                        plik >> kolor_przeciwnika;
                                        plik.close();

                                        if(odpowiedz == "TAK"){
//                                          cout<< "tu tu ruu"<<endl;
                                            gramy_host(uzytkownik,wyzwany_przeciwnik,nasz_kolor,kolor_przeciwnika);
                                        }
                                        if(odpowiedz == "NIE"){
                                            system("cls");
                                            cout<<wyzwany_przeciwnik<<" odrzucil wyzwanie"<<endl;
                                            getch();
                                            goto poczatek;
                                        }

                                    }
                                return 0;
                                }
                            }
                        }
                    }
                        break;
                    case 1:{ /// gra lokalna
                        string nazwa1,nazwa2;
                        int wybor=0;

                        system("cls");
                        saturnin_mowi(kolor_saturnina); cout <<"Podaj nazwe pierwszego Gracza:";
                        saturnin_mowi(nasz_kolor); getline(cin,nazwa1);

                        system("cls");
                        saturnin_mowi(kolor_saturnina); cout <<"Podaj nazwe drugiego Gracza:";
                        saturnin_mowi(nasz_kolor); getline(cin,nazwa2);

                        for(;;){
                            system("cls");
                            saturnin_mowi(kolor_saturnina); cout <<"Ktory Gracz ma pierwszy zaczynac?"<<endl;
                            saturnin_mowi(nasz_kolor);
                            if(wybor==0) cout<< "-"; else cout<< " "; cout<< nazwa1;
                            cout<<"   ";
                            if(wybor==1) cout<< "-"; else cout<< " "; cout<< nazwa2<<endl;

                            unsigned char strzalka=getch();
                            if(strzalka==224){
                                switch(getch()){
                                    case 75: strzalka=97; /// strzalka w gore zamieniona na W
                                        break;
                                    case 77: strzalka=100; /// strzalka w dol  zamieniona na S
                                        break;
                                }
                            }
                            switch(strzalka){
                                case 100: /// prawo
                                    if(wybor!=1) wybor=1;
                                    break;
                                case 97: /// lewo
                                    if(wybor!=0) wybor=0;
                                    break;
                                case 13:{ /// enter
                                    if(wybor==1){ /// musimy zamienic graczy miejscami
                                        string nazwa_zapasowa=nazwa1;
                                        nazwa1=nazwa2;
                                        nazwa2=nazwa_zapasowa;
                                    }
                                    ///  -----------------------------------------------------------------------ODPALANIE GRY LOKALNEJ
                                    nazwa = lokacja + "szachy-nazwy";
                                    plik.open(nazwa.c_str(),ios::out); ///TU
                                    plik << nazwa1 <<endl<< nazwa2 ;
                                    plik.close();

                                    system("start ../Szachy/Szachy.exe");
                                    return 0;
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 2:{ /// Tablica wynikow

                        break;
                    }
                    case 3:{ /// instrukcja

                        break;
                    }
                    case 4:{ /// Wyjscie
                        return 0;
                        break;
                    }
                }

        }

    }


}
