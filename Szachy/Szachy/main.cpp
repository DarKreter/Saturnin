/** POZOSTALE SPRAWY DO ZA£ATWIENIA
        SPRAWY ZWALONE NA DANIELA:
            -poprawienie roszady
        SPRAWY ALEXA:
            -online
            -instrukcja
**/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <string>
#include <conio.h>
#include <cmath>
#include "..\..\Pliki\funkcje.h"

using namespace std;

short int licznik_zaliczonych=0; ///ZMIENNA GLOBALNA PARARARA

short int lnn(string literka){
    if(literka=="a" || literka=="1") return 0;
    if(literka=="b" || literka=="2") return 1;
    if(literka=="c" || literka=="3") return 2;
    if(literka=="d" || literka=="4") return 3;
    if(literka=="e" || literka=="5") return 4;
    if(literka=="f" || literka=="6") return 5;
    if(literka=="g" || literka=="7") return 6;
    if(literka=="h" || literka=="8") return 7;


}

short int poprawienie_liczby(short int liczba){
    switch(liczba){
    case 0: return 0+1; ///Daniel spytasz czemu +1 ? to oczywiste, zle zapisalem za pierwszym razem i nie chcialo mi sie wszedzie zmieniac wiec dalem +1
    case 1: return 1+1; ///inkrementacjaaaaa
    case 2: return 2+1;
    case 3: return 3+1;
    case 4: return 4+1;
    case 5: return 5+1;
    case 6: return 6+1;
    case 7: return 7+1;
    }
}

char nnl(int liczba,bool uzytkownik=true){
    switch (uzytkownik){
     case false:
        switch (liczba){
        case 0: return 'A';
        case 1: return 'B';
        case 2: return 'C';
        case 3: return 'D';
        case 4: return 'E';
        case 5: return 'F';
        case 6: return 'G';
        case 7: return 'H';
        }
        case true:
        switch (liczba){
        case 0: return 'a';
        case 1: return 'b';
        case 2: return 'c';
        case 3: return 'd';
        case 4: return 'e';
        case 5: return 'f';
        case 6: return 'g';
        case 7: return 'h';
        }
    }
    return 'x';
}

void kolor(string kolor){
    if(kolor=="bialy" || kolor == "B"){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF); /// BIALY
    }
    else if(kolor=="czarny" || kolor == "C"){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xC); /// CZERWONY
    }
    else if(kolor=="plansza"){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x8); /// SZARY
    }
    else if(kolor=="special")
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE); /// ZOLTY
    }


return;
}

void rysuj(string pole[8][8], short int y=11, short int x=11){

    kolor("plansza");
    cout<<"#|";
    for(int i=0;i<=7;i++){
        cout<< nnl(i,0) << "|";
    }
    cout << endl;
    for(int i=7;i>=0;i--){
        kolor("plansza");
        cout<< i+1 <<"|";
        for(int j=0;j<=7;j++){
            kolor(pole[i][j].substr(1,1)=="B" ? "bialy" : pole[i][j].substr(1,1)=="C" ? "czarny" : "plansza");
            if(i == y && j == x) kolor("special");
            cout<<pole[i][j].substr(0,1);
            kolor("plansza");
            cout<<"|";
        }
        cout<<endl;
    }
return;
}

bool Sprawdzanie_czy_pole_jest_atakowane(short int y, short int x, string pole[8][8], string kolor_tury){  /// JESLI POLE JEST ATAKOWANE ZWRACANE JEST TRUE
    //cout<<"CZY TO WOGOLE TU WCHODZI"<<endl;
    string kolor_przeciwnika= kolor_tury=="B" ? "C" : "B" ;
    bool tablica[8]={true,true,true,true,true,true,true,true};
    //cout<<"kolor_tury w sprawdzanie czy pole jest atakowane-"<< kolor_tury<<endl;
    ///warunek na pionki
    if(kolor_tury=="B"){
        if(y+1<=7&&x+1<=7&&pole[y+1][x+1] == "PC"){ ///Atak na bialego krola przez czarnego pionka stojacego nad nim po prawej
            //cout<<"popierdolilo."<<endl;
            return true;
        }
        if(y+1<=7&&x-1>=0&&pole[y+1][x-1] == "PC" ){///Atak na bialego krola czarnym pionkiem od gory z lewej
            //cout<<"popierdolilo."<<endl;
            return true;
        }
    }
    else{
        if(y-1>=0&&x+1>=0&&pole[y-1][x+1] == "PB"){ ///Atak na czarnego krola z prawej z dolu bialym pionkiem
            //cout<<"masaka"<<endl;
            return true;
        }
        if(y-1>=0&&x-1>=0&&pole[y-1][x-1] == "PB"){ ///Atak na czarnego krola z lewej z dolu bialy pionek
            //cout<<"masaka 2.0"<<endl;
            return true;
        }
    }
    ///warunek na skoczka

    if(( y+2<=7 && x+1<=7 && pole[y+2][x+1]=="S"+kolor_przeciwnika) || (y+1<=7 && x+2<=7 && pole[y+1][x+2]=="S"+kolor_przeciwnika) || /// 0 1
        (y+2<=7 && x-1>=0 && pole[y+2][x-1]=="S"+kolor_przeciwnika) || (y-1>=0 && x+2<=7 && pole[y-1][x+2]=="S"+kolor_przeciwnika) || /// 2 3
        (y-2>=0 && x-1>=7 && pole[y-2][x-1]=="S"+kolor_przeciwnika) || (y-1>=0 && x-2>=0 && pole[y-1][x-2]=="S"+kolor_przeciwnika) || /// 4 5
        (y+1<=7 && x-2>=0 && pole[y+1][x-2]=="S"+kolor_przeciwnika) || (y+2<=7 && x-1>=0 && pole[y+2][x-1]=="S"+kolor_przeciwnika) ){ /// 6 7

        //cout<<"hej tu jestem"<<endl;
        return true;
    }

    ///warunek na wieze gonca i hetmana
    for(int i=1;;i++){

        if(y+i==8){ tablica[7]=false; tablica[0]=false; tablica[1]=false; }///tablica[0] oznacza czy dalej mozna sprawdzac w gore czy nie stoi tam wieza lub hetman
            if(y-i==-1){ tablica[5]=false; tablica[4]=false; tablica[3]=false; }/// jesli tablica[0] == false oznacza to ze na gorze doszlismy juz do gornej granicy i nie ma
            if(x+i==8){ tablica[1]=false; tablica[2]=false; tablica[3]=false; } /// co dalej sprawdzac, nastepne tablice ida jak w zegarku od 0 do 7
            if(x-i==-1){ tablica[7]=false; tablica[6]=false; tablica[5]=false; }

        if( tablica[0]==true && pole[y+i][x] != "__" ){ /// 0
            tablica[0]=false;
            if(pole[y+i][x] == "W"+kolor_przeciwnika || pole[y+i][x] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y+i <<"*"<<x<<" a stoi tu:"<<pole[y+i][x]<<endl;
                return true;
            }
        }
        if( tablica[1]==true && pole[y+i][x+i] != "__" ){ /// 1
            tablica[1]=false;
            if(pole[y+i][x+i] == "G"+kolor_przeciwnika || pole[y+i][x+i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y+i <<"*"<<x+i<<" a stoi tu:"<<pole[y+i][x+i]<<endl;
                return true;
            }
        }
        if( tablica[2]==true && pole[y][x+i] != "__" ){ /// 2
            tablica[2]=false;
            if(pole[y][x+i] == "W"+kolor_przeciwnika || pole[y][x+i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y <<"*"<<x+i<<" a stoi tu:"<<pole[y][x+i]<<endl;
                return true;
            }
        }
        if( tablica[3]==true && pole[y-i][x+i] != "__" ){ /// 3
            tablica[3]=false;
            if(pole[y-i][x+i] == "G"+kolor_przeciwnika || pole[y-i][x+i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y-i <<"*"<<x+i<<" a stoi tu:"<<pole[y-i][x+i]<<endl;
                return true;
            }
        }
        if( tablica[4]==true && pole[y-i][x] != "__" ){ /// 4
            tablica[4]=false;
            if(pole[y-i][x] == "W"+kolor_przeciwnika || pole[y-i][x] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y-i <<"*"<<x<<" a stoi tu:"<<pole[y-i][x]<<endl;
                return true;
            }
        }
        if( tablica[5]==true && pole[y-i][x-i] != "__" ){ /// 5
            tablica[5]=false;
            if(pole[y-i][x-i] == "G"+kolor_przeciwnika || pole[y-i][x-i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y-i <<"*"<<x-i<<" a stoi tu:"<<pole[y-i][x-i]<<endl;
                return true;
            }
        }
        if( tablica[6]==true && pole[y][x-i] != "__" ){ /// 6
            tablica[6]=false;
            if(pole[y][x-i] == "W"+kolor_przeciwnika || pole[y][x-i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y <<"*"<<x-i<<" a stoi tu:"<<pole[y][x-i]<<endl;
                return true;
            }
        }
        if( tablica[7]==true && pole[y+i][x-i] != "__" ){ /// 7
            tablica[7]=false;
           // cout<<"co ja robie tu-"<<pole[y+i][x-i]<<endl;
            if(pole[y+i][x-i] == "G"+kolor_przeciwnika || pole[y+i][x-i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y+i <<"*"<<x-i<<" a stoi tu:"<<pole[y+i][x-i]<<endl;
                return true;
            }
        }
        for(int j=0;j<8;j++){
            if(tablica[j]==true){
                break;
            }
            if(j==7){
                goto zycie_nie_ma_sensu;
            }
        }
    }
    zycie_nie_ma_sensu:
    //cout<<"to ja wychodze"<<endl;
    return false;
}

bool SPECJALNE_sprawdzanie_czy_pole_jest_atakowane(short int y, short int x, string pole[8][8], string kolor_tury, short int wynik[2] ){  ///Dodatkowo zwraca gdzie stoi figura atakujaca pole
    //cout<<"CZY TO WOGOLE TU WCHODZI"<<endl;
    string kolor_przeciwnika= kolor_tury=="B" ? "C" : "B" ;
    bool tablica[8]={true,true,true,true,true,true,true,true};
    bool czy_mamy_juz_jedna_szachujaca_figure=false;

    //cout<<"kolor_tury w sprawdzanie czy pole jest atakowane-"<< kolor_tury<<endl;
    ///warunek na pionki
    if(kolor_tury=="B"){
        if(y+1<=7&&x+1<=7&&pole[y+1][x+1] == "PC"){ ///Atak na bialego krola przez czarnego pionka stojacego nad nim po prawej
            //cout<<"popierdolilo."<<endl;
            if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                wynik[0]=10;
                return true;
            }
            else{
                wynik[0]=y+1; wynik[1]=x+1;
                czy_mamy_juz_jedna_szachujaca_figure=true;
            }
        }
        if(y+1<=7&&x-1>=0&&pole[y+1][x-1] == "PC" ){///Atak na bialego krola czarnym pionkiem od gory z lewej
            //cout<<"popierdolilo."<<endl;
            if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                wynik[0]=10;
                return true;
            }
            else{
                wynik[0]=y+1; wynik[1]=x-1;
                czy_mamy_juz_jedna_szachujaca_figure=true;
            }
        }
    }
    else{
        if(y-1>=0&&x+1>=0&&pole[y-1][x+1] == "PB"){ ///Atak na czarnego krola z prawej z dolu bialym pionkiem
            //cout<<"masaka"<<endl;
            if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                wynik[0]=10;
                return true;
            }
            else{
                wynik[0]=y-1; wynik[1]=x+1;
                czy_mamy_juz_jedna_szachujaca_figure=true;
            }
        }
        if(y-1>=0&&x-1>=0&&pole[y-1][x-1] == "PB"){ ///Atak na czarnego krola z lewej z dolu bialy pionek
            //cout<<"masaka 2.0"<<endl;
            if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                wynik[0]=10;
                return true;
            }
            else{
                wynik[0]=y-1; wynik[1]=x-1;
                czy_mamy_juz_jedna_szachujaca_figure=true;
            }
        }
    }
    ///warunek na skoczka (trick daniela) WOW.
    short int yy,xx;
    if( (yy=2,xx=1,(y+2<=7 && x+1<=7 && pole[y+2][x+1]=="S"+kolor_przeciwnika)) || (yy=1,xx=2,(y+1<=7 && x+2<=7 && pole[y+1][x+2]=="S"+kolor_przeciwnika)) || /// 0 1
        (yy=2,xx=-1,(y+2<=7 && x-1>=0 && pole[y+2][x-1]=="S"+kolor_przeciwnika)) ||(yy=-1,xx=2,(y-1>=0 && x+2<=7 && pole[y-1][x+2]=="S"+kolor_przeciwnika)) || /// 2 3
        (yy=-2,xx=-1,(y-2>=0 && x-1>=7 && pole[y-2][x-1]=="S"+kolor_przeciwnika)) || (yy=-1,xx=-2,(y-1>=0 && x-2>=0 && pole[y-1][x-2]=="S"+kolor_przeciwnika)) || /// 4 5
        (yy=1,xx=-2,(y+1<=7 && x-2>=0 && pole[y+1][x-2]=="S"+kolor_przeciwnika)) || (yy=2,xx=-1,(y+2<=7 && x-1>=0 && pole[y+2][x-1]=="S"+kolor_przeciwnika)) ){ /// 6 7

            //cout<<"hej tu jestem"<<endl;
            if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                wynik[0]=10;
                return true;
            }
            else{
                wynik[0]=y+yy; wynik[1]=x+xx;
                czy_mamy_juz_jedna_szachujaca_figure=true;
            }
    }

    ///warunek na wieze gonca i hetmana
    for(int i=1;;i++){

        if(y+i==8){ tablica[7]=false; tablica[0]=false; tablica[1]=false; }///tablica[0] oznacza czy dalej mozna sprawdzac w gore czy nie stoi tam wieza lub hetman
            if(y-i==-1){ tablica[5]=false; tablica[4]=false; tablica[3]=false; }/// jesli tablica[0] == false oznacza to ze na gorze doszlismy juz do gornej granicy i nie ma
            if(x+i==8){ tablica[1]=false; tablica[2]=false; tablica[3]=false; } /// co dalej sprawdzac, nastepne tablice ida jak w zegarku od 0 do 7
            if(x-i==-1){ tablica[7]=false; tablica[6]=false; tablica[5]=false; }

        if( tablica[0]==true && pole[y+i][x] != "__" ){ /// 0
            tablica[0]=false;
            if(pole[y+i][x] == "W"+kolor_przeciwnika || pole[y+i][x] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y+i <<"*"<<x<<" a stoi tu:"<<pole[y+i][x]<<endl;

                if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                    wynik[0]=10;
                    return true;
                }
                else{
                    wynik[0]=y+i; wynik[1]=x;
                    czy_mamy_juz_jedna_szachujaca_figure=true;
                }
            }
        }
        if( tablica[1]==true && pole[y+i][x+i] != "__" ){ /// 1
            tablica[1]=false;
            if(pole[y+i][x+i] == "G"+kolor_przeciwnika || pole[y+i][x+i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y+i <<"*"<<x+i<<" a stoi tu:"<<pole[y+i][x+i]<<endl;
                if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                    wynik[0]=10;
                    return true;
                }
                else{
                    wynik[0]=y+i; wynik[1]=x+i;
                    czy_mamy_juz_jedna_szachujaca_figure=true;
                }
            }
        }
        if( tablica[2]==true && pole[y][x+i] != "__" ){ /// 2
            tablica[2]=false;
            if(pole[y][x+i] == "W"+kolor_przeciwnika || pole[y][x+i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y <<"*"<<x+i<<" a stoi tu:"<<pole[y][x+i]<<endl;
                 if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                    wynik[0]=10;
                    return true;
                }
                else{
                    wynik[0]=y; wynik[1]=x+i;
                    czy_mamy_juz_jedna_szachujaca_figure=true;
                }
            }
        }
        if( tablica[3]==true && pole[y-i][x+i] != "__" ){ /// 3
            tablica[3]=false;
            if(pole[y-i][x+i] == "G"+kolor_przeciwnika || pole[y-i][x+i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y-i <<"*"<<x+i<<" a stoi tu:"<<pole[y-i][x+i]<<endl;
                 if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                    wynik[0]=10;
                    return true;
                }
                else{
                    wynik[0]=y-i; wynik[1]=x+i;
                    czy_mamy_juz_jedna_szachujaca_figure=true;
                }
            }
        }
        if( tablica[4]==true && pole[y-i][x] != "__" ){ /// 4
            tablica[4]=false;
            if(pole[y-i][x] == "W"+kolor_przeciwnika || pole[y-i][x] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y-i <<"*"<<x<<" a stoi tu:"<<pole[y-i][x]<<endl;
                 if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                    wynik[0]=10;
                    return true;
                }
                else{
                    wynik[0]=y-i; wynik[1]=x;
                    czy_mamy_juz_jedna_szachujaca_figure=true;
                }
            }
        }
        if( tablica[5]==true && pole[y-i][x-i] != "__" ){ /// 5
            tablica[5]=false;
            if(pole[y-i][x-i] == "G"+kolor_przeciwnika || pole[y-i][x-i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y-i <<"*"<<x-i<<" a stoi tu:"<<pole[y-i][x-i]<<endl;
                 if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                    wynik[0]=10;
                    return true;
                }
                else{
                    wynik[0]=y-i; wynik[1]=x-i;
                    czy_mamy_juz_jedna_szachujaca_figure=true;
                }
            }
        }
        if( tablica[6]==true && pole[y][x-i] != "__" ){ /// 6
            tablica[6]=false;
            if(pole[y][x-i] == "W"+kolor_przeciwnika || pole[y][x-i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y <<"*"<<x-i<<" a stoi tu:"<<pole[y][x-i]<<endl;
                 if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                    wynik[0]=10;
                    return true;
                }
                else{
                    wynik[0]=y; wynik[1]=x-i;
                    czy_mamy_juz_jedna_szachujaca_figure=true;
                }
            }
        }
        if( tablica[7]==true && pole[y+i][x-i] != "__" ){ /// 7
            tablica[7]=false;
           // cout<<"co ja robie tu-"<<pole[y+i][x-i]<<endl;
            if(pole[y+i][x-i] == "G"+kolor_przeciwnika || pole[y+i][x-i] == "H"+kolor_przeciwnika){
                //cout<< "NO TO TUTAJJ- "<<y+i <<"*"<<x-i<<" a stoi tu:"<<pole[y+i][x-i]<<endl;
                 if(czy_mamy_juz_jedna_szachujaca_figure==true){ /// to zastepuje RETURN TRUE
                    wynik[0]=10;
                    return true;
                }
                else{
                    wynik[0]=y+i; wynik[1]=x-i;
                    czy_mamy_juz_jedna_szachujaca_figure=true;
                }
            }
        }
        for(int j=0;j<8;j++){
            if(tablica[j]==true){
                break;
            }
            if(j==7){
                goto zycie_nie_ma_sensu;
            }
        }
    }
    zycie_nie_ma_sensu:
    //cout<<"to ja wychodze"<<endl;
    if(czy_mamy_juz_jedna_szachujaca_figure==false) return false;
    else return true;
}

bool Sprawdzanie_ruchu_goniec(short int pomoc[2], short int ruch[2], string pole[8][8], short int zaliczone[10][2]){
    //cout <<pomoc[0]<< "-||-"<<pomoc[1]<<"\n";
    if (abs(ruch[0]- pomoc[0]) == abs((ruch[1] - pomoc[1]))&& (ruch[1] - pomoc[1] != 0)) {
            //cout << "Czy to tu\n";
                    if(ruch[0] > pomoc[0]){
                        if(ruch[1] > pomoc[1]){
                            cout << "gora prawo\n";
                            for(int j=1;j<abs(ruch[0]-pomoc[0]);j++){
                                if(pole[pomoc[0]+j][pomoc[1]+j] != "__" )
                                    cout << "spadaj1\n";
                                    return false;
                            }
                            zaliczone[licznik_zaliczonych][0]= pomoc[0];
                            zaliczone[licznik_zaliczonych][1]= pomoc[1];


                            return true;
                        }
                        else{
                            cout << "gora lewo \n";
                            for(int j=1;j<abs(ruch[1]-pomoc[1]);j++){
                                if(pole[pomoc[0]+j][pomoc[1]-j] != "__" ){
                                        cout << "spadaj2\n";
                                    return false;
                                }
                            }
                            zaliczone[licznik_zaliczonych][0]= pomoc[0];
                            zaliczone[licznik_zaliczonych][1]= pomoc[1];


                            return true;
                        }
                    }
                    else{
                        if(ruch[1] > pomoc[1]){
                            cout << "dol prawo\n";
                            for(int j=1;j<abs(ruch[0]-pomoc[0]);j++){
                                if(pole[pomoc[0]-j][pomoc[1]+j] != "__" ){
                                    cout << "spadaj3\n";
                                    return false;
                                }
                            }
                            zaliczone[licznik_zaliczonych][0]= pomoc[0];
                            zaliczone[licznik_zaliczonych][1]= pomoc[1];
                            return true;
                        }
                        else{
                            cout << "dol lewo\n";
                            for(int j=1;j<abs(ruch[1]-pomoc[1]);j++){
                                if(pole[pomoc[0]-j][pomoc[1]-j] != "__" ){
                                    cout << "spadaj4\n";
                                    return false;
                                }
                            }
                            zaliczone[licznik_zaliczonych][0]= pomoc[0];
                            zaliczone[licznik_zaliczonych][1]= pomoc[1];


                            return true;
                        }
                    }
                }
    return 0;
}

bool Sprawdzanie_ruchu_Hetman(short int pomoc[2], short int ruch[2], string pole[8][8] , short int zaliczone[10][2] ){
    cout<<"pomoc0-"<<pomoc[0] <<" pomoc1-"<<pomoc[1] <<endl <<"ruch0-"<<ruch[0] <<" ruch1-"<<ruch[1]<<endl;


    if( ( ( ruch[0]  != pomoc[0] || ruch[1] != pomoc[1] ) && ( ruch[0] == pomoc[0] || ruch[1] == pomoc[1] ) ) || abs(ruch[0]-pomoc[0])==abs(ruch[1]-pomoc[1]) ){
        //cout<<"no nie"<<endl;
        if(ruch[0]>pomoc[0]){
            //cout<<"JAPIERDZIELE"<<endl;
            //cout<< ruch[1] << ">" << pomoc[1]<<endl;
            if(ruch[1]>pomoc[1]){ ///1

                for(int i=1;i+pomoc[0]<ruch[0];i++){
                    if(pole[pomoc[0]+i][pomoc[1]+i] != "__"){
                        //cout<<"hej"<<endl;
                        return false;
                    }
                }
                zaliczone[licznik_zaliczonych][0]=pomoc[0];
                zaliczone[licznik_zaliczonych][1]=pomoc[1];
                return true;
            }
            else if(ruch[1]<pomoc[1]){ ///7
                for(int i=1;i+pomoc[0]<ruch[0];i++){
                    if(pole[pomoc[0]+i][pomoc[1]-i] != "__"){
                       // cout<<"hej"<<endl;
                        return false;
                    }
                }
                zaliczone[licznik_zaliczonych][0]=pomoc[0];
                zaliczone[licznik_zaliczonych][1]=pomoc[1];

                //cout<<"LALALA"<<endl;
                return true;
            }
            else if(ruch[1]==pomoc[1]){ ///0
                for(int i=1;i+pomoc[0]<ruch[0];i++){
                    if(pole[pomoc[0]+i][pomoc[1]] != "__"){
                       // cout<<"hej"<<endl;
                        return false;
                    }
                }
                zaliczone[licznik_zaliczonych][0]=pomoc[0];
                zaliczone[licznik_zaliczonych][1]=pomoc[1];
                //cout<<"LALALA"<<endl;
                return true;
            }
        }
        else if(ruch[0]<pomoc[0]){
            if(ruch[1]>pomoc[1]){ ///3
                for(int i=1;pomoc[0]-i>ruch[0];i++){
                    if(pole[pomoc[0]-i][pomoc[1]+i] != "__"){
                        //cout<<"hej"<<endl;
                        return false;
                    }
                }
                zaliczone[licznik_zaliczonych][0]=pomoc[0];
                zaliczone[licznik_zaliczonych][1]=pomoc[1];
                //cout<<"LALALA"<<endl;
                return true;
            }
            else if(ruch[1]<pomoc[1]){ ///5
                for(int i=1;pomoc[0]-i>ruch[0];i++){
                    if(pole[pomoc[0]-i][pomoc[1]-i] != "__"){
                        //cout<<"hej"<<endl;
                        return false;
                    }
                }
                zaliczone[licznik_zaliczonych][0]=pomoc[0];
                zaliczone[licznik_zaliczonych][1]=pomoc[1];
                //cout<<"LALALA"<<endl;
                return true;
            }
            else if(ruch[1]==pomoc[1]){ ///4
                for(int i=1;pomoc[0]-i>ruch[0];i++){
                    if(pole[pomoc[0]-i][pomoc[1]] != "__"){
                        //cout<<"hej"<<endl;
                        return false;
                    }
                }
                zaliczone[licznik_zaliczonych][0]=pomoc[0];
                zaliczone[licznik_zaliczonych][1]=pomoc[1];
                //cout<<"LALALA"<<endl;
                return true;
            }
        }
        else if(ruch[0]==pomoc[0]){
            if(ruch[1]>pomoc[1]){ ///2
                for(int i=1;i+pomoc[1]<ruch[1];i++){
                    if(pole[pomoc[0]][pomoc[1]+i] != "__"){
                        //cout<<"hej"<<endl;
                        return false;
                    }
                }
                zaliczone[licznik_zaliczonych][0]=pomoc[0];
                zaliczone[licznik_zaliczonych][1]=pomoc[1];
                //cout<<"LALALA"<<endl;
                return true;
            }
            else if(ruch[1]<pomoc[1]){ ///6
                for(int i=1;pomoc[1]-i<ruch[1];i++){
                    if(pole[pomoc[0]][pomoc[1]-i] != "__"){
                        //cout<<"hej"<<endl;
                        return false;
                    }
                }
                zaliczone[licznik_zaliczonych][0]=pomoc[0];
                zaliczone[licznik_zaliczonych][1]=pomoc[1];

                //cout<<"LALALA"<<endl;
                return true;
            }

        }
    }
    return 0;
    cout<<"lol"<<endl;
}

bool Sprawdzanie_ruchu_Wieza(short int pomoc[2], short int ruch[2], string pole[8][8] , short int zaliczone[10][2]){

        //cout << pomoc[0] << "{}" << pomoc[1] <<endl;
        if( ( pomoc[0] != ruch[0] || pomoc[1] !=ruch[1] ) &&  ( pomoc[0] == ruch[0] || pomoc[1] ==ruch[1] ) ){
            if( pomoc[1]==ruch[1]){
                if(pomoc[0]<ruch[0]){
                    for(int j=1;j<ruch[0]-pomoc[0];j++){
                        if( pole[pomoc[0]+j][pomoc[1]] != "__"){
                            return 0;
                        }
                    }
                    zaliczone[licznik_zaliczonych][0]= pomoc[0];
                    zaliczone[licznik_zaliczonych][1]= pomoc[1];
                    getch();
                   // cout<<zaliczone[licznik_zaliczonych][0]<<" P " << zaliczone[licznik_zaliczonych][1]<<" P "<< licznik_zaliczonych<<endl;
                    return 1;
                }
                else{
                    for(int j=pomoc[0]-1 ; j>ruch[0] ; j-- ){
                        if(pole[j][pomoc[1]] != "__"){
                            return 0;
                        }
                    }
                    zaliczone[licznik_zaliczonych][0]= pomoc[0];
                    zaliczone[licznik_zaliczonych][1]= pomoc[1];
                    //cout<<zaliczone[licznik_zaliczonych][0]<<" P " << zaliczone[licznik_zaliczonych][1]<<" P "<< licznik_zaliczonych<<endl;
                    return 1;
                }
            }
            else{
                if(pomoc[1]<ruch[1]){
                    for(int j=pomoc[1]+1 ; j<ruch[1]; j++ ){
                        if(pole[pomoc[0]][j] != "__" ){
                            return 0;
                        }
                    }
                    zaliczone[licznik_zaliczonych][0]= pomoc[0];
                    zaliczone[licznik_zaliczonych][1]= pomoc[1];

                    //cout<<zaliczone[licznik_zaliczonych][0]<<" P " << zaliczone[licznik_zaliczonych][1]<<" P "<< licznik_zaliczonych<<endl;
                    return 1;
                }
                else{
                    for(int j=pomoc[1]-1 ; j>ruch[1] ; j-- ){
                        if(pole[pomoc[0]][j] != "__" ){
                            return 0;
                        }
                    }
                    zaliczone[licznik_zaliczonych][0]= pomoc[0];
                    zaliczone[licznik_zaliczonych][1]= pomoc[1];

                    //cout<<zaliczone[licznik_zaliczonych][0]<<" P " << zaliczone[licznik_zaliczonych][1]<<" P "<< licznik_zaliczonych<<endl;
                    return 1;
                }
            }
        }
    //cout<<"GOWNO"<<endl;
    return 0;
}

bool Sprawdzanie_ruchu_skoczek(short int pomoc[2], short int ruch[2],string pole[8][8], short int zaliczone[10][2]){
cout<<"k"<<endl;
    if( abs(ruch[0] - pomoc[0]) <= 2 && abs(ruch[1] - pomoc[1]) <= 2 && abs(ruch[0] - pomoc[0]) != abs(ruch[1] - pomoc[1]) && ruch[0] != pomoc[0] && ruch[1] != pomoc[1] ){
        cout<<"zzzz"<<endl;
        cout<<abs(ruch[0] - pomoc[0]) <<"!="<<abs(ruch[1] - pomoc[1])<<endl;
        zaliczone[licznik_zaliczonych][0]= pomoc[0];
        zaliczone[licznik_zaliczonych][1]= pomoc[1];
        return 1;
    }
    return 0;
}

bool Sprawdzanie_ruchu_pionek(short int pomoc[2],short int ruch[2], string pole[8][8], short int zaliczone[10][2], string kolor_tury, short int bicie_w_przelocie){
    cout<<"victorious"<<endl;
    if(kolor_tury=="B"){
            cout<<"Co tam"<<endl;
            if(ruch[0] == pomoc[0]+1){
                if(ruch[1] == pomoc[1] ){
                    if( pole[ruch[0]][ruch[1]] == "__") {
                        zaliczone[licznik_zaliczonych][0]= pomoc[0];
                        zaliczone[licznik_zaliczonych][1]= pomoc[1];
                        return 1;
                    }
                }
                else if(ruch[1] == pomoc[1]+1){
                    if( pole[ruch[0]][ruch[1]] != "__" || ( pole[ruch[0]][ruch[1]] == "__"  && bicie_w_przelocie==ruch[1] && ruch[0]==5  )){
                        zaliczone[licznik_zaliczonych][0]= pomoc[0];
                        zaliczone[licznik_zaliczonych][1]= pomoc[1];
                        return 1;
                    }

                }
                else if(ruch[1] == pomoc[1]-1){
                    if( pole[ruch[0]][ruch[1]] != "__" || ( pole[ruch[0]][ruch[1]] == "__"  && bicie_w_przelocie==ruch[1] && ruch[0]==5  ) ){
                        zaliczone[licznik_zaliczonych][0]= pomoc[0];
                        zaliczone[licznik_zaliczonych][1]= pomoc[1];
                        return 1;
                    }
                }
            }
            else if(ruch[0] == pomoc[0]+2 && ruch[1] == pomoc[1] && pole[pomoc[0]+2][pomoc[1]] == "__" && pomoc[0] == 1){
                zaliczone[licznik_zaliczonych][0]= pomoc[0];
                zaliczone[licznik_zaliczonych][1]= pomoc[1];
                return 1;
            }
        }

        else if(kolor_tury=="C"){
            if(ruch[0] == pomoc[0]-1){
                if(ruch[1] == pomoc[1] ){
                    if( pole[ruch[0]][ruch[1]] == "__") {
                        zaliczone[licznik_zaliczonych][0]= pomoc[0];
                        zaliczone[licznik_zaliczonych][1]= pomoc[1];
                        return 1;
                    }
                }
                else if(ruch[1] == pomoc[1]+1){
                    if( pole[ruch[0]][ruch[1]] != "__" || ( pole[ruch[0]][ruch[1]] == "__"  && bicie_w_przelocie==ruch[1] && ruch[0]==2  )){
                        zaliczone[licznik_zaliczonych][0]= pomoc[0];
                        zaliczone[licznik_zaliczonych][1]= pomoc[1];
                        return 1;
                    }
                }
                else if(ruch[1] == pomoc[1]-1){
                    if( pole[ruch[0]][ruch[1]] != "__" || ( pole[ruch[0]][ruch[1]] == "__"  && bicie_w_przelocie==ruch[1] && ruch[0]==2  )){
                        zaliczone[licznik_zaliczonych][0]= pomoc[0];
                        zaliczone[licznik_zaliczonych][1]= pomoc[1];
                        return 1;
                    }
                }
            }
            else if(ruch[0] == pomoc[0]-2 && ruch[1] == pomoc[1] && pole[pomoc[0]-2][pomoc[1]] == "__" && pomoc[0] == 6 ){
                zaliczone[licznik_zaliczonych][0]= pomoc[0];
                zaliczone[licznik_zaliczonych][1]= pomoc[1];
                return 1;
            }
        }
        return 0;
}

bool Sprawdzanie_ruchu_Krol(short int pomoc[2], short int ruch[2],string pole[8][8], short int zaliczone[10][2], string kolor_tury,bool roszada_mala, bool roszada_duza){
//cout<< "to ma byc mniejsze od 1->"<<abs(pomoc[0]-ruch[0])<<endl;//roszada
//cout << abs(pomoc[1]-ruch[1])<<endl;
    if(  abs(pomoc[0]-ruch[0]) <= 1 && abs(pomoc[1]-ruch[1]) <= 1  ){
        //cout<< "gowno"<<endl;
        string kolor_przeciwnika= ( kolor_tury=="B" ? "C" : "B" );
        bool tablica[8]={true,true,true,true,true,true,true,true};
        pole[pomoc[0]][pomoc[1]]="__"; ///usuwamy krola na poczatek bo potem sam sie zaslania przed figurami
        ///ZABAWA SIE ZACZYNA TUTAJ, SPRAWDZAMY CZY POLE JEST ATAKOWANE PRZEZ INNA FIGURE

        if(kolor_tury=="B"){
            //cout<<"l"<<endl;
            if(ruch[0]+1<=7&&ruch[1]+1<=7&&pole[ruch[0]+1][ruch[1]+1] == "PC"){ ///Atak na bialego krola przez czarnego pionka stojacego nad nim po prawej
                system("cls");
                pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                rysuj(pole,ruch[0]+1,ruch[1]+1); ///Rysujemy jeszcze raz zeby podswietlic na zolto figure atakujaca
                kolor("plansza");
              cout <<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]+1][ruch[1]+1].substr(0,1) <<nnl(ruch[0]+1,1)<<poprawienie_liczby(ruch[1]+1) <<"!\n";
                return false;
            }
            if(ruch[0]+1<=7&&ruch[1]-1>=0&&pole[ruch[0]+1][ruch[1]-1] == "PC" ){///Atak na bialego krola czarnym pionkiem od gory z lewej
                system("cls");
                pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                rysuj(pole,ruch[0]+1,ruch[1]-1); ///Rysujemy jeszcze raz zeby podswietlic na zolto figure atakujaca
                kolor("plansza");
                cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]+1][ruch[1]-1].substr(0,1) <<nnl(ruch[0]+1,1)<<poprawienie_liczby(ruch[1]-1) <<"!\n";
                return false;
            }
        }
        else{
            if(ruch[0]-1>=0&&ruch[1]+1>=7&&pole[ruch[0]-1][ruch[1]+1] == "PB"){ ///Atak na czarnego krola z prawej z dolu bialym pionkiem

                system("cls");
                pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                rysuj(pole,ruch[0]-1,ruch[1]+1);
                kolor("plansza");
                cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]-1][ruch[1]+1].substr(0,1) <<nnl(ruch[0]-1,1)<<poprawienie_liczby(ruch[1]+1) <<"!\n";
                return false;
            }
            if(ruch[0]-1>=0&&ruch[1]-1>=0&&pole[ruch[0]-1][ruch[1]-1] == "PB"){ ///Atak na czarnego krola z lewej z dolu bialy pionek
                system("cls");
                pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                rysuj(pole,ruch[0]-1,ruch[1]-1);
                kolor("plansza");
                cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]-1][ruch[1]-1].substr(0,1) <<nnl(ruch[0]-1,1)<<poprawienie_liczby(ruch[1]-1) <<"!\n";
                return false;
            }
        }
        ///Uwaga uwaga oto najlepszy z najlepszych waruneek na ruch skoczka! Prosze klekac SLODKI JEZU TO GENIALNE
       // cout<<"A"<<endl;
            int y = 0, x = 0;
            if(  (y =  2, x =  1, (ruch[0]+2<=7) && (ruch[1]+1<=7) && (pole[ruch[0]+2][ruch[1]+1] == "S"+kolor_przeciwnika)) || (y =  1, x =  2, (ruch[0]+1<=7) && (ruch[1]+2<=7) && (pole[ruch[0]+1][ruch[1]+2] == "S"+kolor_przeciwnika))
               ||(y =  2, x = -1, (ruch[0]+2<=7) && (ruch[1]-1>=0) && (pole[ruch[0]+2][ruch[1]-1] == "S"+kolor_przeciwnika)) || (y = -1, x =  2, (ruch[0]-1>=0) && (ruch[1]+2<=7) && (pole[ruch[0]-1][ruch[1]+2] == "S"+kolor_przeciwnika))
               ||(y = -2, x = -1, (ruch[0]-2>=0) && (ruch[1]-1>=0) && (pole[ruch[0]-2][ruch[1]-1] == "S"+kolor_przeciwnika)) || (y = -2, x =  1, (ruch[0]-2>=0) && (ruch[1]+1<=7) && (pole[ruch[0]-2][ruch[1]+1] == "S"+kolor_przeciwnika))
               ||(y =  1, x = -2, (ruch[0]+1<=7) && (ruch[1]-2>=0) && (pole[ruch[0]+1][ruch[1]-2] == "S"+kolor_przeciwnika)) || (y = -1, x = -2, (ruch[0]-1>=0) && (ruch[1]-2>=0) && (pole[ruch[0]-1][ruch[1]-2] == "S"+kolor_przeciwnika)))
            {
                ///GENIUSZ TO CO TU ZROBILEM (!) najs!
                system("cls");
                pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                rysuj(pole,ruch[0]+y, ruch[1]+x);
                kolor("plansza");
                //cout<<endl<<"Pole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure S"<<nnl(ruch[0]+y)<<poprawienie_liczby(ruch[1]+x)<<"!"<<endl;
                return false;

            }
            //cout<<"K"<<endl;
        ///Gonce Hetmany wie?e
        for(int i=1;;i++){
            ///lecimy jak w zegarku od 12
            //cout<<"ruch[0] +i=" <<ruch[0]+i<<endl; ///Hm o co tu chodzi
            if(ruch[0]+i==8){ tablica[7]=false; tablica[0]=false; tablica[1]=false; }///tablica[0] oznacza czy dalej mozna sprawdzac w gore czy nie stoi tam wieza lub hetman
            if(ruch[0]-i==-1){ tablica[5]=false; tablica[4]=false; tablica[3]=false; }/// jesli tablica[0] == false oznacza to ze na gorze doszlismy juz do gornej granicy i nie ma
            if(ruch[1]+i==8){ tablica[1]=false; tablica[2]=false; tablica[3]=false; } /// co dalej sprawdzac, nastepne tablice ida jak w zegarku od 0 do 7
            if(ruch[1]-i==-1){ tablica[7]=false; tablica[6]=false; tablica[5]=false; }
            //cout<<"llol"<< tablica[0]<<endl;    ///Musze sie ciebie zapytac o co tu dokladniej chodzi xD

            if(tablica[0]==true && pole[ruch[0]+i][ruch[1]] != "__" ){ ///Jesli mam sprawdzac i to pole nie jest wolne (wolnych nie bedzxiemy sprawdzac)
                tablica[0]=false; ///pewnie znaczy zeby juz nie sprawdzac xD
               // cout<<"Lol"<<endl;
                if( pole[ruch[0]+i][ruch[1]]=="W"+kolor_przeciwnika || pole[ruch[0]+i][ruch[1]]=="H"+kolor_przeciwnika || ( i==1 && pole[ruch[0]+i][ruch[1]]=="K"+kolor_przeciwnika ) ) {
                    ///Jesli Krol jest atakowny od gory po lini prostej przez Wieze badz hetmana LUB przez krola jesli to pierwsze przejscie (krol ma jeden zasiegu)
                    system("cls");
                    pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                    rysuj(pole,ruch[0]+i,ruch[1]);
                    kolor("plansza");
                    cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]+i][ruch[1]].substr(0,1) <<nnl(ruch[0]+1,1)<<poprawienie_liczby(ruch[1]) <<"!\n";
                    break;
                }
            }
            if(tablica[1]==true && pole[ruch[0]+i][ruch[1]+i] != "__"){ ///Jesli mam sprawdzac i to pole nie jest wolne (wolnych nie bedzxiemy sprawdzac)
                tablica[1]=false;

                if(pole[ruch[0]+i][ruch[1]+i]=="G"+kolor_przeciwnika || pole[ruch[0]+i][ruch[1]+i]=="H"+kolor_przeciwnika || ( i==1 && pole[ruch[0]+i][ruch[1]+i]=="K"+kolor_przeciwnika)){

                    ///Krol atakowany po skosie prawa gora goniec lub hetman LUB krol jesli jest o jedno pole
                    system("cls");
                    pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                    rysuj(pole,ruch[0]+i,ruch[1]+i);
                    kolor("plansza");
                    cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]+i][ruch[1]+i].substr(0,1) <<nnl(ruch[0]+1,1)<<poprawienie_liczby(ruch[1]+i) <<"!\n";
                    break;
                }
            }
            if(tablica[2]==true && pole[ruch[0]][ruch[1]+i] != "__" ){ ///Jesli mam sprawdzac i to pole nie jest wolne (wolnych nie bedzxiemy sprawdzac)
                tablica[2]=false;
                //cout<<"Lol"<<endl;
                if( pole[ruch[0]][ruch[1]+i]=="W"+kolor_przeciwnika || pole[ruch[0]][ruch[1]+i]=="H"+kolor_przeciwnika || ( i==1 && pole[ruch[0]][ruch[1]+i]=="K"+kolor_przeciwnika ) ) {
                    ///Krol jest atakowany przez wieze badz hetmana po linii prostej z prawej LUB Krola z prawej jesli jest o jeden
                    system("cls");
                    pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                    rysuj(pole,ruch[0],ruch[1]+i);
                    kolor("plansza");
                    cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]][ruch[1]+i].substr(0,1) <<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1]+i) <<"!\n";
                    break;
                }
            }
            if(tablica[3]==true && pole[ruch[0]-i][ruch[1]+i] != "__"){ ///Jesli mam sprawdzac i to pole nie jest wolne (wolnych nie bedzxiemy sprawdzac)
                tablica[3]=false;

                if(pole[ruch[0]-i][ruch[1]+i]=="G"+kolor_przeciwnika || pole[ruch[0]-i][ruch[1]+i]=="H"+kolor_przeciwnika || ( i==1 && pole[ruch[0]-i][ruch[1]+i]=="K"+kolor_przeciwnika)){
                    ///Krol atakowany przez gonca badz hetmana z prawego dolu po skosie LUB krol lewy dol jesli jest o jedno pole
                    system("cls");
                    pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                    rysuj(pole,ruch[0]-i,ruch[1]+i);
                    kolor("plansza");
                    cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]-i][ruch[1]+i].substr(0,1) <<nnl(ruch[0]-1,1)<<poprawienie_liczby(ruch[1]+i) <<"!\n";
                    break;
                }
            }
            if(tablica[4]==true && pole[ruch[0]-i][ruch[1]] != "__" ){ ///Jesli mam sprawdzac i to pole nie jest wolne (wolnych nie bedzxiemy sprawdzac)
                tablica[4]=false;
                //cout<<"Lol"<<endl;
                if( pole[ruch[0]-i][ruch[1]]=="W"+kolor_przeciwnika || pole[ruch[0]-i][ruch[1]]=="H"+kolor_przeciwnika || ( i==1 && pole[ruch[0]-i][ruch[1]]=="K"+kolor_przeciwnika ) ) {
                    ///Krol atakowany przez wieze badz hetmana w linii prostej od dolu LUB krola jesli jest o jedno pole
                    system("cls");
                    pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                    rysuj(pole,ruch[0]-i,ruch[1]);
                    kolor("plansza");
                    cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]-i][ruch[1]].substr(0,1) <<nnl(ruch[0]-i,1)<<poprawienie_liczby(ruch[1]) <<"!\n";
                    break;
                }
            }
            if(tablica[5]==true && pole[ruch[0]-i][ruch[1]-i] != "__"){ ///Jesli mam sprawdzac i to pole nie jest wolne (wolnych nie bedzxiemy sprawdzac)
                tablica[5]=false;

                if(pole[ruch[0]-i][ruch[1]-i]=="G"+kolor_przeciwnika || pole[ruch[0]-i][ruch[1]-i]=="H"+kolor_przeciwnika || ( i==1 && pole[ruch[0]-i][ruch[1]-i]=="K"+kolor_przeciwnika)){
                    ///Pole jest atakowane przez gonca badz hetmana z lewego dolu LUB krola lewy dol jesli jest o jedno pole
                    system("cls");
                    pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                    rysuj(pole,ruch[0]-i,ruch[1]-i);
                    kolor("plansza");
                    cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]-i][ruch[1]-i].substr(0,1) <<nnl(ruch[0]-i,1)<<poprawienie_liczby(ruch[1]-i) <<"!\n";
                    break;
                }
            }
            if(tablica[6]==true && pole[ruch[0]][ruch[1]-i] != "__" ){ ///Jesli mam sprawdzac i to pole nie jest wolne (wolnych nie bedzxiemy sprawdzac)
                tablica[6]=false;
                //cout<<"Lol"<<endl;
                if( pole[ruch[0]][ruch[1]-i]=="W"+kolor_przeciwnika || pole[ruch[0]][ruch[1]-i]=="H"+kolor_przeciwnika || ( i==1 && pole[ruch[0]][ruch[1]-i]=="K"+kolor_przeciwnika ) ) {
                    ///Pole atakowane przez krola lub wieze po linii prostej z lewej LUB krol tak tak wiemy
                    system("cls");
                    pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                    rysuj(pole,ruch[0],ruch[1]-i);
                    kolor("plansza");
                    cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]][ruch[1]-i].substr(0,1) <<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1]-i) <<"!\n";
                    break;
                }
            }
            if(tablica[7]==true && pole[ruch[0]+i][ruch[1]-i] != "__"){ ///Jesli mam sprawdzac i to pole nie jest wolne (wolnych nie bedzxiemy sprawdzac)
                tablica[7]=false;

                if(pole[ruch[0]+i][ruch[1]-i]=="G"+kolor_przeciwnika || pole[ruch[0]+i][ruch[1]-i]=="H"+kolor_przeciwnika || ( i==1 && pole[ruch[0]+i][ruch[1]-i]=="K"+kolor_przeciwnika)){
                    ///Pole atakowane przez hetmana badz gonca po skosie z gory lewej
                    system("cls");
                    pole[pomoc[0]][pomoc[1]] = "K"+kolor_tury;  ///Bo krol sie nam nie narysuje
                    rysuj(pole,ruch[0]+i,ruch[1]-i);
                    kolor("plansza");
                    cout<<"\nPole "<<nnl(ruch[0],1)<<poprawienie_liczby(ruch[1])<<" jest atakowane przez figure "<< pole[ruch[0]+i][ruch[1]-i].substr(0,1) <<nnl(ruch[0]+i,1)<<poprawienie_liczby(ruch[1]-i) <<"!\n";
                    break;
                }
            }

            ///i tutaj warunek konczacy
            for(int j=0;j<8;j++) if(tablica[j] == true) goto dalej;
            zaliczone[0][0]=pomoc[0];
            zaliczone[0][1]=pomoc[1];
            licznik_zaliczonych=1;
            return true;

            dalej:
            continue;
        }

    }


    if(roszada_mala == true){   ///Mozliwosc malej roszady
        cout<<"lalala"<<endl;
        if(kolor_tury=="B" && ruch[0] == 0){    /// dla bialego
            //cout<<"a"<<endl;
             if(ruch[1]==6  && pole[0][7]=="WB" && pole[0][6]=="__" && pole[0][5]=="__"){///Czy wieza jest tam gdzie powinna plus czy pomiedzy pola sa puste
                cout << "ciekawe\n";
                ///------------------------------------------------------------------------------------------------------------------------------------
                short int wynik[2]={11,11}; short calkiem_zbyteczna_zmienna_jak_ta_alexa = 0;
                if(SPECJALNE_sprawdzanie_czy_pole_jest_atakowane(0,4,pole,"B",wynik) == true)
                {
                        goto bialy_mala;
                }
                else    calkiem_zbyteczna_zmienna_jak_ta_alexa++;
                pole[0][4] = "__"; pole[0][7] = "__"; pole[0][5] = "WB"; pole[0][6] = "KB"; ///Symulacja pola
                if(Sprawdzanie_czy_pole_jest_atakowane(0,6,pole,"B") == true)
                {
                        goto bialy_mala;
                }
                else    calkiem_zbyteczna_zmienna_jak_ta_alexa++;
                if(Sprawdzanie_czy_pole_jest_atakowane(0,5,pole,"B") == true)    ///czy pola pomiedzy nie sa atakowane i czy krol nie zostanie zaszachowany
                {
                        goto bialy_mala;
                }
                else calkiem_zbyteczna_zmienna_jak_ta_alexa++;
                if(calkiem_zbyteczna_zmienna_jak_ta_alexa == 3)
                {
                    //cout<<"prr"<<endl;
                    pole[0][7]="__";
                    pole[0][5]="WB";
                    zaliczone[0][0]=pomoc[0];
                    zaliczone[0][1]=pomoc[1];
                    licznik_zaliczonych++;
                    pole[0][4] = "KB"; pole[0][6] = "__";
                    return true;
                }
                bialy_mala:
                pole[0][4] = "KB"; pole[0][7] = "WB"; pole[0][5] = "__"; pole[0][6] = "__";
                system("cls");
                rysuj(pole,wynik[0],wynik[1]);
                cout << endl << "Nie mozna wykonac roszady! ";
                if(calkiem_zbyteczna_zmienna_jak_ta_alexa == 0) cout << "Krol jest pod szachem!\n" ;
                else if(calkiem_zbyteczna_zmienna_jak_ta_alexa == 1)    cout << "Pole a7 jest atakowane"<<(wynik[0] == 10 ? " przez wiele figur!\n" :"!\n");
                else if(calkiem_zbyteczna_zmienna_jak_ta_alexa == 2)    cout << "Pole a6 jest atakowane"<<(wynik[0] == 10 ? " przez wiele figur!\n" :"!\n");
                ///------------------------------------------------------------------------------------------------------------------------------------
            }
        }
        else if(kolor_tury=="C" && ruch[0] == 7){   ///dla czarnego
            if(ruch[1]==6 && pole[7][7]=="WC" && pole[7][6]=="__" && pole[7][5]=="__" &&Sprawdzanie_czy_pole_jest_atakowane(7,4,pole,"C")==false){
                cout << "LOL\n";
                pole[7][4] = "__"; pole[7][7] = "__"; pole[7][5] = "WC"; pole[7][6] = "KC"; ///Symulacja pola
                if(Sprawdzanie_czy_pole_jest_atakowane(7,6,pole,"C") == false && Sprawdzanie_czy_pole_jest_atakowane(7,5,pole,"C") == false)    ///czy pola pomiedzy nie sa atakowane i czy krol nie zostanie zaszachowany
                {
                    pole[7][7]="__";
                    pole[7][5]="WC";
                    zaliczone[0][0]=pomoc[0];
                    zaliczone[0][1]=pomoc[1];
                    licznik_zaliczonych++;
                    pole[7][4] = "KC"; pole[7][6] = "__";
                    return true;
                }
                pole[7][4] = "KC"; pole[7][7] = "WC"; pole[7][5] = "__"; pole[7][6] = "__";
            }
        }
    }
    if(roszada_duza == true){
        //cout << "elo\n";
        if(kolor_tury == "B" && ruch[0] == 0)
        {
            //cout << "siema\n";
            if(ruch[1]==2 && pole[0][0]=="WB" && pole[0][1]=="__" && pole[0][2]=="__" && pole[0][3]=="__"&&Sprawdzanie_czy_pole_jest_atakowane(0,4,pole,"B")==false){
                pole[0][4] = "__"; pole[0][0] = "__"; pole[0][2] = "KB"; pole[0][3] = "WB"; ///Symulacja pola
                if(Sprawdzanie_czy_pole_jest_atakowane(0,2,pole,"B") == false && Sprawdzanie_czy_pole_jest_atakowane(0,3,pole,"B") == false)    ///czy pola pomiedzy nie sa atakowane i czy krol nie zostanie zaszachowany
                {
                    pole[0][0]="__";
                    pole[0][3]="WB";
                    zaliczone[0][0]=pomoc[0];
                    zaliczone[0][1]=pomoc[1];
                    licznik_zaliczonych++;
                    pole[0][4] = "KB"; pole[0][2] = "__";
                    return true;
                }
                 pole[0][4] = "KB"; pole[0][0] = "WB"; pole[0][2] = "__"; pole[0][3] = "__";
            }
        }
        else if(kolor_tury == "C" && ruch[0] == 7)
        {
                if(ruch[1]==2 && pole[7][0]=="WC" && pole[7][1]=="__" && pole[7][2]=="__" && pole[7][3]=="__"&&Sprawdzanie_czy_pole_jest_atakowane(7,4,pole,"C")==false){
                    pole[7][4] = "__"; pole[7][0] = "__"; pole[7][2] = "KC"; pole[7][3] = "WC";
                    if(Sprawdzanie_czy_pole_jest_atakowane(7,2,pole,"C")==false &&Sprawdzanie_czy_pole_jest_atakowane(7,3,pole,"C") == false)
                    {
                        pole[7][0]="__";
                        pole[7][3]="WC";
                        zaliczone[0][0]=pomoc[0];
                        zaliczone[0][1]=pomoc[1];
                        licznik_zaliczonych++;
                        pole[7][4] = "KC"; pole[7][2] = "__";
                        return true;
                    }
                pole[7][4] = "KC"; pole[7][0] = "WC"; pole[7][2] = "__"; pole[7][3] = "__";
            }
        }
    }
    //cout << "aha ?"<<endl;
    return 0;
}

bool Sprawdzanie_przeciwnej_strony_od_krola(short int zaliczone[2],string pole[8][8], short pozycja2,string kolor_przeciwnika,string Co_i_gdzie[7],short int wspolrzedne[2],short int podswietlanie_lol[8][2]){ ///returnuje false gdy krol bedzie atakowany po ruchu
    cout << "----przeciwna od krola - function\nPozycja2 = "<<pozycja2<<"  kolor wroga "<<kolor_przeciwnika<<endl;
    //cout << "Wspolrzednelol to "<<podswietlanie_lol[7][0]<<" "<<podswietlanie_lol[7][1]<<endl;
    if(pozycja2 == 8)   return false;
    if(pozycja2==0){
        if(Co_i_gdzie[0] == "W"+kolor_przeciwnika || Co_i_gdzie[7] == "H"+kolor_przeciwnika)
        {
            cout << "Cos atakuje Krola!\n";
            wspolrzedne[0] = podswietlanie_lol[0][0]; wspolrzedne[1] = podswietlanie_lol[0][1];
            return true;
        }
        else    return false;
    }
    if(pozycja2==1){
        cout << "numer 1\n";
        if(Co_i_gdzie[1] == "G"+kolor_przeciwnika || Co_i_gdzie[1] == "H"+kolor_przeciwnika)
        {
            cout << "Cos atakuje Krola!\n";
            //cout << podswietlanie_lol[1][0] << " " <<podswietlanie_lol[1][1]<<endl;
            wspolrzedne[0] = podswietlanie_lol[1][0]; wspolrzedne[1] = podswietlanie_lol[1][1];
            return true;
        }
        else    return false;

    }
    if(pozycja2==2){
        if(Co_i_gdzie[2] == "W"+kolor_przeciwnika || Co_i_gdzie[2] == "H"+kolor_przeciwnika)
        {
            cout << "Cos atakuje Krola!\n";
            wspolrzedne[0] = podswietlanie_lol[2][0]; wspolrzedne[1] = podswietlanie_lol[2][1];
            return true;
        }
        else    return false;
    }
    if(pozycja2 == 3)
    {
        if(Co_i_gdzie[3] == "G"+kolor_przeciwnika || Co_i_gdzie[3] == "H"+kolor_przeciwnika)
        {
            cout << "Cos atakuje Krola!\n";
            wspolrzedne[0] = podswietlanie_lol[3][0]; wspolrzedne[1] = podswietlanie_lol[3][1];
            return true;
        }
        else    return false;
    }
    if(pozycja2 == 4)
    {
        if(Co_i_gdzie[4] == "W"+kolor_przeciwnika || Co_i_gdzie[4] == "H"+kolor_przeciwnika)
        {
            cout << "Cos atakuje Krola!\n";
            wspolrzedne[0] = podswietlanie_lol[4][0]; wspolrzedne[1] = podswietlanie_lol[4][1];
            return true;
        }
        else    return false;
    }
    if(pozycja2 == 5)
    {
        if(Co_i_gdzie[5] == "G"+kolor_przeciwnika || Co_i_gdzie[5] == "H"+kolor_przeciwnika)
        {
            cout << "Cos atakuje Krola!\n";
            wspolrzedne[0] = podswietlanie_lol[5][0]; wspolrzedne[1] = podswietlanie_lol[5][1];
            return true;
        }
        else    return false;
    }
    if(pozycja2 == 6)
    {
        if(Co_i_gdzie[6] == "W"+kolor_przeciwnika || Co_i_gdzie[6] == "H"+kolor_przeciwnika)
        {
            cout << "Cos atakuje Krola!\n";
            wspolrzedne[0] = podswietlanie_lol[6][0]; wspolrzedne[1] = podswietlanie_lol[6][1];
            return true;
        }
        else    return false;
    }
    if(pozycja2 == 7)
    {
        if(Co_i_gdzie[7] == "G"+kolor_przeciwnika || Co_i_gdzie[7] == "H"+kolor_przeciwnika)
        {
            cout << "Cos atakuje Krola!\n";
            wspolrzedne[0] = podswietlanie_lol[7][0]; wspolrzedne[1] = podswietlanie_lol[7][1];
            //cout << "Wspolrzednelol to "<<podswietlanie_lol[7][0]<<" "<<podswietlanie_lol[7][1]<<endl;
            //cout << "Wspolrzedne to "<<wspolrzedne[0]<<" "<<wspolrzedne[1]<<endl;
            return true;
        }
        else    return false;
    }
    /// Mam dość ide na przerwe SKONCZYLEM TWE DZIELO chyba
}

bool Sprawdzanie_odkrywania_Krola_pod_szach(short int ruch[2],short int zaliczone[2],string pole[8][8], short int wspolrzedne[2]){
    cout << "---------funkcja odkrywanie krola pod szach\n";
    string Co_i_gdzie[8];   ///Tablica w ktora strone co stoi pierwsze
    Co_i_gdzie[0] = "__";Co_i_gdzie[1] = "__";Co_i_gdzie[2] = "__";Co_i_gdzie[3] = "__";Co_i_gdzie[4] = "__";Co_i_gdzie[5] = "__";Co_i_gdzie[6] = "__";Co_i_gdzie[7] = "__";
    short int podswietlanie_lol[8][2];
    short int pozycja=8; ///Pozycja krola wzgledem figury, od 0 do 7
    short int pozycja2=8; /// Pozycja na przeciwko krola od 0 do 7
    string kolor_tury=pole[zaliczone[0]][zaliczone[1]].substr(1,1); ///ustawiamy za kolor tury kolor figury ktorą sie ruszamy
    for(int i=0;i<=7;i++)    {Co_i_gdzie[i]="__";}
    string kolor_przeciwnika = ( kolor_tury=="B" ? "C" : "B" );
    //cout << "kolor przeciwnika1 "<<kolor_przeciwnika<<endl;
    //cout << "kolor przeciwnika2 "<<kolor_przeciwnika<<endl;
    if(ruch[0]<zaliczone[0]){ ///Zegarek 0-7
        //cout << "zaliczone[0] > ruch[0]\n";
        if(ruch[1]==zaliczone[1]){ /// 4
            //cout << "zaliczone[1]==ruch[1]\n";
            for(int i=1;i<=7;i++){
                /// W ifach dodatkowo sprawdzamy czy sprawdzane pola nie wychodza po za plansze
                if( Co_i_gdzie[1] == "__"&& zaliczone[0]+i<=7 && zaliczone[1]+i <=7 && pole[zaliczone[0]+i][zaliczone[1]+i] != "__" ){ /// jesli Krol jest w pozycji 1
                    Co_i_gdzie[1] = pole[zaliczone[0]+i][zaliczone[1]+i];
                    podswietlanie_lol[1][0] = zaliczone[0]+i; podswietlanie_lol[1][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]+i][zaliczone[1]+i].substr(0,1) == "K") pozycja = 1; ///Jesli to byl krol zapiszmy jednak ta pozycje
                    //cout << "Coigdzie[1] "<<Co_i_gdzie[1] << endl;
                    //break;
                }
                if( Co_i_gdzie[2] == "__"&&zaliczone[1]+i <=7 && pole[zaliczone[0]][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 2
                    Co_i_gdzie[2] = pole[zaliczone[0]][zaliczone[1]+i];
                    podswietlanie_lol[2][0] = zaliczone[0]; podswietlanie_lol[2][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]][zaliczone[1]+i].substr(0,1) == "K")   pozycja=2;
                    //cout << "Coigdzie[2] "<<Co_i_gdzie[2] << endl;
                    //break;
                }
                if( Co_i_gdzie[3] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]+i <=7 && pole[zaliczone[0]-i][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 3
                    Co_i_gdzie[3] = pole[zaliczone[0]-i][zaliczone[1]+i];
                    podswietlanie_lol[3][0] = zaliczone[0]-i; podswietlanie_lol[3][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]-i][zaliczone[1]+i].substr(0,1) == "K")   pozycja=3;
                    //cout << "Coigdzie[3] "<<Co_i_gdzie[3] << endl;
                    //break;
                }
                if( Co_i_gdzie[5] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]-i >=0 && pole[zaliczone[0]-i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 5
                    Co_i_gdzie[5] = pole[zaliczone[0]-i][zaliczone[1]-i];
                    podswietlanie_lol[5][0] = zaliczone[0]-i; podswietlanie_lol[5][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]-i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=5;
                    //cout << "Coigdzie[5] "<<Co_i_gdzie[5] << endl;
                    //break;
                }
                if( Co_i_gdzie[6] == "__"&&zaliczone[1]-i >=0 && pole[zaliczone[0]][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 6
                    Co_i_gdzie[6] = pole[zaliczone[0]][zaliczone[1]-i];
                    podswietlanie_lol[6][0] = zaliczone[0]; podswietlanie_lol[6][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]][zaliczone[1]-i].substr(0,1) == "K")   pozycja=6;
                    //cout << "Coigdzie[6] "<<Co_i_gdzie[6] << endl;
                    //break;
                }
                if( Co_i_gdzie[7] == "__"&&zaliczone[0]+i<=7 && zaliczone[1]-i >=0 && pole[zaliczone[0]+i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 7
                    Co_i_gdzie[7] = pole[zaliczone[0]+i][zaliczone[1]-i];
                    podswietlanie_lol[7][0] = zaliczone[0]+i; podswietlanie_lol[7][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]+i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=7;
                    //cout << "Wspolrzedne coigdzie to "<<podswietlanie_lol[7][0]<<" "<<podswietlanie_lol[7][1]<<endl;
                    //cout << "Coigdzie[7] "<<Co_i_gdzie[7] << endl;
                    //break;
                }
            }
            //cout << "kolor przeciwnika "<<kolor_przeciwnika<<endl;

        }
        if(ruch[1]>zaliczone[1]){ /// 3
            //cout << "zaliczone[1]<ruch[1]\n";
            for(int i=1;i<=7;i++){
                /// W ifach dodatkowo sprawdzamy czy sprawdzane pola nie wychodza po za plansze
                if(Co_i_gdzie[0] == "__"&&zaliczone[0]+i <=7&&pole[zaliczone[0]+i][zaliczone[1]]!="__"){    ///pozycja 0
                    Co_i_gdzie[0] = pole[zaliczone[0]+i][zaliczone[1]];
                    podswietlanie_lol[0][0] = zaliczone[0]+i; podswietlanie_lol[0][1] = zaliczone[1];
                    if(pole[zaliczone[0]+i][zaliczone[1]].substr(0,1) == "K")   pozycja=0;
                    //cout << "Coigdzie[0] "<<Co_i_gdzie[0] << endl;
                }
                if( Co_i_gdzie[1] == "__"&& zaliczone[0]+i<=7 && zaliczone[1]+i <=7 && pole[zaliczone[0]+i][zaliczone[1]+i] != "__" ){ /// jesli Krol jest w pozycji 1
                    Co_i_gdzie[1] = pole[zaliczone[0]+i][zaliczone[1]+i];
                    podswietlanie_lol[1][0] = zaliczone[0]+i; podswietlanie_lol[1][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]+i][zaliczone[1]+i].substr(0,1) == "K") pozycja = 1; ///Jesli to byl krol zapiszmy jednak ta pozycje
                   // cout << "Coigdzie[1] "<<Co_i_gdzie[1] << endl;
                    //break;
                }
                if( Co_i_gdzie[2] == "__"&&zaliczone[1]+i <=7 && pole[zaliczone[0]][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 2
                    Co_i_gdzie[2] = pole[zaliczone[0]][zaliczone[1]+i];
                    podswietlanie_lol[2][0] = zaliczone[0]; podswietlanie_lol[2][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]][zaliczone[1]+i].substr(0,1) == "K")   pozycja=2;
                    //cout << "Coigdzie[2] "<<Co_i_gdzie[2] << endl;
                    //break;
                }
                if(Co_i_gdzie[4] == "__"&&zaliczone[0]-i >=0&&pole[zaliczone[0]-i][zaliczone[1]]!="__"){    ///Pozycja 4
                    Co_i_gdzie[4] = pole[zaliczone[0]-i][zaliczone[1]];
                    podswietlanie_lol[4][0] = zaliczone[0]-i; podswietlanie_lol[4][1] = zaliczone[1];
                    if(pole[zaliczone[0]-i][zaliczone[1]].substr(0,1) == "K")   pozycja=4;
                    //cout << "Coigdzie[4] "<<Co_i_gdzie[4] << endl;
                }
                if( Co_i_gdzie[5] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]-i >=0 && pole[zaliczone[0]-i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 5
                    Co_i_gdzie[5] = pole[zaliczone[0]-i][zaliczone[1]-i];
                    podswietlanie_lol[5][0] = zaliczone[0]-i; podswietlanie_lol[5][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]-i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=5;
                    //cout << "Coigdzie[5] "<<Co_i_gdzie[5] << endl;
                    //break;
                }
                if( Co_i_gdzie[6] == "__"&&zaliczone[1]-i >=0 && pole[zaliczone[0]][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 6
                    Co_i_gdzie[6] = pole[zaliczone[0]][zaliczone[1]-i];
                    podswietlanie_lol[6][0] = zaliczone[0]; podswietlanie_lol[6][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]][zaliczone[1]-i].substr(0,1) == "K")   pozycja=6;
                    //cout << "Coigdzie[6] "<<Co_i_gdzie[6] << endl;
                    //break;
                }
            }
        }
        if(ruch[1]<zaliczone[1]){ /// 5
            cout << "zaliczone[1]>ruch[1]\n";
            for(int i=1;i<=7;i++){
             if(Co_i_gdzie[0] == "__"&&zaliczone[0]+i <=7&&pole[zaliczone[0]+i][zaliczone[1]]!="__"){    ///pozycja 0
                    Co_i_gdzie[0] = pole[zaliczone[0]+i][zaliczone[1]];
                    podswietlanie_lol[0][0] = zaliczone[0]+i; podswietlanie_lol[0][1] = zaliczone[1];
                    if(pole[zaliczone[0]+i][zaliczone[1]].substr(0,1) == "K")   pozycja=0;
                    cout << "Coigdzie[0] "<<Co_i_gdzie[0] << endl;
                }
                if( Co_i_gdzie[2] == "__"&&zaliczone[1]+i <=7 && pole[zaliczone[0]][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 2
                    Co_i_gdzie[2] = pole[zaliczone[0]][zaliczone[1]+i];
                    podswietlanie_lol[2][0] = zaliczone[0]; podswietlanie_lol[2][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]][zaliczone[1]+i].substr(0,1) == "K")   pozycja=2;
                    cout << "Coigdzie[2] "<<Co_i_gdzie[2] << endl;
                    //break;
                }
                if( Co_i_gdzie[3] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]+i <=7 && pole[zaliczone[0]-i][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 3
                    Co_i_gdzie[3] = pole[zaliczone[0]-i][zaliczone[1]+i];
                    podswietlanie_lol[3][0] = zaliczone[0]-i; podswietlanie_lol[3][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]-i][zaliczone[1]+i].substr(0,1) == "K")   pozycja=3;
                    cout << "Coigdzie[3] "<<Co_i_gdzie[3] << endl;
                    //break;
                }
                if(Co_i_gdzie[4] == "__"&&zaliczone[0]-i >=0&&pole[zaliczone[0]-i][zaliczone[1]]!="__"){    ///Pozycja 4
                    Co_i_gdzie[4] = pole[zaliczone[0]-i][zaliczone[1]];
                    podswietlanie_lol[4][0] = zaliczone[0]-i; podswietlanie_lol[4][1] = zaliczone[1];
                    if(pole[zaliczone[0]-i][zaliczone[1]].substr(0,1) == "K")   pozycja=4;
                    cout << "Coigdzie[4] "<<Co_i_gdzie[4] << endl;
                }
                if( Co_i_gdzie[6] == "__"&&zaliczone[1]-i >=0 && pole[zaliczone[0]][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 6
                    Co_i_gdzie[6] = pole[zaliczone[0]][zaliczone[1]-i];
                    podswietlanie_lol[6][0] = zaliczone[0]; podswietlanie_lol[6][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]][zaliczone[1]-i].substr(0,1) == "K")   pozycja=6;
                    cout << "Coigdzie[6] "<<Co_i_gdzie[6] << endl;
                    //break;
                }
                if( Co_i_gdzie[7] == "__"&&zaliczone[0]+i<=7 && zaliczone[1]-i >=0 && pole[zaliczone[0]+i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 7
                    Co_i_gdzie[7] = pole[zaliczone[0]+i][zaliczone[1]-i];
                    podswietlanie_lol[7][0] = zaliczone[0]+i; podswietlanie_lol[7][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]+i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=7;
                    cout << "Wspolrzedne coigdzie to "<<podswietlanie_lol[7][0]<<" "<<podswietlanie_lol[7][1]<<endl;
                    cout << "Coigdzie[7] "<<Co_i_gdzie[7] << endl;
                    //break;
                }
        }
    }
    }
    if(ruch[0]==zaliczone[0]){
        cout << "zaliczone[0]==ruch[0]\n";
        if(ruch[1]<zaliczone[1]){ ///6
            cout << "zaliczone[1]>ruch[1]\n";
            for(int i=1;i<=7;i++){
                /// W ifach dodatkowo sprawdzamy czy sprawdzane pola nie wychodza po za plansze
                if(Co_i_gdzie[0] == "__"&&zaliczone[0]+i <=7&&pole[zaliczone[0]+i][zaliczone[1]]!="__"){
                    Co_i_gdzie[0] = pole[zaliczone[0]+i][zaliczone[1]];
                    podswietlanie_lol[0][0] = zaliczone[0]+i; podswietlanie_lol[0][1] = zaliczone[1];
                    if(pole[zaliczone[0]+i][zaliczone[1]].substr(0,1) == "K")   pozycja=0;
                    cout << "Coigdzie[0] "<<Co_i_gdzie[0] << endl;
                }
                if( Co_i_gdzie[1] == "__"&& zaliczone[0]+i<=7 && zaliczone[1]+i <=7 && pole[zaliczone[0]+i][zaliczone[1]+i] != "__" ){ /// jesli Krol jest w pozycji 1
                    Co_i_gdzie[1] = pole[zaliczone[0]+i][zaliczone[1]+i];
                    podswietlanie_lol[1][0] = zaliczone[0]+i; podswietlanie_lol[1][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]+i][zaliczone[1]+i].substr(0,1) == "K") pozycja = 1; ///Jesli to byl krol zapiszmy jednak ta pozycje
                    cout << "Coigdzie[1] "<<Co_i_gdzie[1] << endl;
                    //break;
                }
                if( Co_i_gdzie[3] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]+i <=7 && pole[zaliczone[0]-i][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 3
                    Co_i_gdzie[3] = pole[zaliczone[0]-i][zaliczone[1]+i];
                    podswietlanie_lol[3][0] = zaliczone[0]-i; podswietlanie_lol[3][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]-i][zaliczone[1]+i].substr(0,1) == "K")   pozycja=3;
                    cout << "Coigdzie[3] "<<Co_i_gdzie[3] << endl;
                    //break;
                }
                if(Co_i_gdzie[4] == "__"&&zaliczone[0]-i >=0&&pole[zaliczone[0]-i][zaliczone[1]]!="__"){
                    Co_i_gdzie[4] = pole[zaliczone[0]-i][zaliczone[1]];
                    podswietlanie_lol[4][0] = zaliczone[0]-i; podswietlanie_lol[4][1] = zaliczone[1];
                    if(pole[zaliczone[0]-i][zaliczone[1]].substr(0,1) == "K")   pozycja=4;
                    cout << "Coigdzie[4] "<<Co_i_gdzie[4] << endl;
                }
                if( Co_i_gdzie[5] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]-i >=0 && pole[zaliczone[0]-i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 5
                    Co_i_gdzie[5] = pole[zaliczone[0]-i][zaliczone[1]-i];
                    podswietlanie_lol[5][0] = zaliczone[0]-i; podswietlanie_lol[5][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]-i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=5;
                    cout << "Coigdzie[5] "<<Co_i_gdzie[5] << endl;
                    //break;
                }
                if( Co_i_gdzie[7] == "__"&&zaliczone[0]+i<=7 && zaliczone[1]-i >=0 && pole[zaliczone[0]+i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 7
                    Co_i_gdzie[7] = pole[zaliczone[0]+i][zaliczone[1]-i];
                    podswietlanie_lol[7][0] = zaliczone[0]+i; podswietlanie_lol[7][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]+i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=7;
                    cout << "Coigdzie[7] "<<Co_i_gdzie[7] << endl;
                    //break;
                }
            }
        }
        if(ruch[1]>zaliczone[1]){ ///2
            cout << "zaliczone[1]<ruch[1]\n";
            for(int i=1;i<=7;i++){
                /// W ifach dodatkowo sprawdzamy czy sprawdzane pola nie wychodza po za plansze
                if(Co_i_gdzie[0] == "__"&&zaliczone[0]+i <=7&&pole[zaliczone[0]+i][zaliczone[1]]!="__"){    ///Pozycja 0
                    Co_i_gdzie[0] = pole[zaliczone[0]+i][zaliczone[1]];
                    podswietlanie_lol[0][0] = zaliczone[0]+i; podswietlanie_lol[0][1] = zaliczone[1];
                    if(pole[zaliczone[0]+i][zaliczone[1]].substr(0,1) == "K")   pozycja=0;
                    cout << "Coigdzie[0] "<<Co_i_gdzie[0] << endl;
                }
                if( Co_i_gdzie[1] == "__"&& zaliczone[0]+i<=7 && zaliczone[1]+i <=7 && pole[zaliczone[0]+i][zaliczone[1]+i] != "__" ){ /// jesli Krol jest w pozycji 1
                    Co_i_gdzie[1] = pole[zaliczone[0]+i][zaliczone[1]+i];
                    podswietlanie_lol[1][0] = zaliczone[0]+i; podswietlanie_lol[1][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]+i][zaliczone[1]+i].substr(0,1) == "K") pozycja = 1; ///Jesli to byl krol zapiszmy jednak ta pozycje
                    cout << "Coigdzie[1] "<<Co_i_gdzie[1] << endl;
                    //break;
                }
                if( Co_i_gdzie[3] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]+i <=7 && pole[zaliczone[0]-i][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 3
                    Co_i_gdzie[3] = pole[zaliczone[0]-i][zaliczone[1]+i];
                    podswietlanie_lol[3][0] = zaliczone[0]-i; podswietlanie_lol[3][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]-i][zaliczone[1]+i].substr(0,1) == "K")   pozycja=3;
                    cout << "Coigdzie[3] "<<Co_i_gdzie[3] << endl;
                    //break;
                }
                if(Co_i_gdzie[4] == "__"&&zaliczone[0]-i >=0&&pole[zaliczone[0]-i][zaliczone[1]]!="__"){    ///Pozycja 4
                    Co_i_gdzie[4] = pole[zaliczone[0]-i][zaliczone[1]];
                    podswietlanie_lol[4][0] = zaliczone[0]-i; podswietlanie_lol[4][1] = zaliczone[1];
                    if(pole[zaliczone[0]-i][zaliczone[1]].substr(0,1) == "K")   pozycja=4;
                    cout << "Coigdzie[4] "<<Co_i_gdzie[4] << endl;
                }
                if( Co_i_gdzie[5] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]-i >=0 && pole[zaliczone[0]-i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 5
                    Co_i_gdzie[5] = pole[zaliczone[0]-i][zaliczone[1]-i];
                    podswietlanie_lol[5][0] = zaliczone[0]-i; podswietlanie_lol[5][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]-i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=5;
                    cout << "Coigdzie[5] "<<Co_i_gdzie[5] << endl;
                    //break;
                }
                if( Co_i_gdzie[7] == "__"&&zaliczone[0]+i<=7 && zaliczone[1]-i >=0 && pole[zaliczone[0]+i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 7
                    Co_i_gdzie[7] = pole[zaliczone[0]+i][zaliczone[1]-i];
                    podswietlanie_lol[7][0] = zaliczone[0]+i; podswietlanie_lol[7][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]+i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=7;
                    cout << "Coigdzie[7] "<<Co_i_gdzie[7] << endl;
                    //break;
                }
            }
        }
    }
    if(ruch[0]>zaliczone[0]){
        cout << "zaliczone[0]<ruch[0]\n";
        if(ruch[1]==zaliczone[1]){ /// 0
            cout << "zaliczone[1]==ruch[1]\n";
            for(int i=1;i<=7;i++){
                /// W ifach dodatkowo sprawdzamy czy sprawdzane pola nie wychodza po za plansze
                if( Co_i_gdzie[1] == "__"&& zaliczone[0]+i<=7 && zaliczone[1]+i <=7 && pole[zaliczone[0]+i][zaliczone[1]+i] != "__" ){ /// jesli Krol jest w pozycji 1
                    Co_i_gdzie[1] = pole[zaliczone[0]+i][zaliczone[1]+i];
                    podswietlanie_lol[1][0] = zaliczone[0]+i; podswietlanie_lol[1][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]+i][zaliczone[1]+i].substr(0,1) == "K") pozycja = 1; ///Jesli to byl krol zapiszmy jednak ta pozycje
                    cout << "Coigdzie[1] "<<Co_i_gdzie[1] << endl;
                    //break;
                }
                if( Co_i_gdzie[2] == "__"&&zaliczone[1]+i <=7 && pole[zaliczone[0]][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 2
                    Co_i_gdzie[2] = pole[zaliczone[0]][zaliczone[1]+i];
                    podswietlanie_lol[2][0] = zaliczone[0]; podswietlanie_lol[2][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]][zaliczone[1]+i].substr(0,1) == "K")   pozycja=2;
                    cout << "Coigdzie[2] "<<Co_i_gdzie[2] << endl;
                    //break;
                }
                if( Co_i_gdzie[3] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]+i <=7 && pole[zaliczone[0]-i][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 3
                    Co_i_gdzie[3] = pole[zaliczone[0]-i][zaliczone[1]+i];
                    podswietlanie_lol[3][0] = zaliczone[0]-i; podswietlanie_lol[3][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]-i][zaliczone[1]+i].substr(0,1) == "K")   pozycja=3;
                    cout << "Coigdzie[3] "<<Co_i_gdzie[3] << endl;
                    //break;
                }
                if( Co_i_gdzie[5] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]-i >=0 && pole[zaliczone[0]-i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 5
                    Co_i_gdzie[5] = pole[zaliczone[0]-i][zaliczone[1]-i];
                    podswietlanie_lol[5][0] = zaliczone[0]-i; podswietlanie_lol[5][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]-i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=5;
                    cout << "Coigdzie[5] "<<Co_i_gdzie[5] << endl;
                    //break;
                }
                if( Co_i_gdzie[6] == "__"&&zaliczone[1]-i >=0 && pole[zaliczone[0]][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 6
                    Co_i_gdzie[6] = pole[zaliczone[0]][zaliczone[1]-i];
                    podswietlanie_lol[6][0] = zaliczone[0]; podswietlanie_lol[6][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]][zaliczone[1]-i].substr(0,1) == "K")   pozycja=6;
                    cout << "Coigdzie[6] "<<Co_i_gdzie[6] << endl;
                    //break;
                }
                if( Co_i_gdzie[7] == "__"&&zaliczone[0]+i<=7 && zaliczone[1]-i >=0 && pole[zaliczone[0]+i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 7
                    Co_i_gdzie[7] = pole[zaliczone[0]+i][zaliczone[1]-i];
                    podswietlanie_lol[7][0] = zaliczone[0]+i; podswietlanie_lol[7][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]+i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=7;
                    cout << "Coigdzie[7] "<<Co_i_gdzie[7] << endl;
                    //break;
                }
            }
        }
        if(ruch[1]<zaliczone[1]){ /// 7
            cout << "zaliczone[1]>ruch[1]\n";
            for(int i=1;i<=7;i++){
             if(Co_i_gdzie[0] == "__"&&zaliczone[0]+i <=7&&pole[zaliczone[0]+i][zaliczone[1]]!="__"){    ///pozycja 0
                    Co_i_gdzie[0] = pole[zaliczone[0]+i][zaliczone[1]];
                    podswietlanie_lol[0][0] = zaliczone[0]+i; podswietlanie_lol[0][1] = zaliczone[1];
                    if(pole[zaliczone[0]+i][zaliczone[1]].substr(0,1) == "K")   pozycja=0;
                    cout << "Coigdzie[0] "<<Co_i_gdzie[0] << endl;
                }
                if( Co_i_gdzie[1] == "__"&& zaliczone[0]+i<=7 && zaliczone[1]+i <=7 && pole[zaliczone[0]+i][zaliczone[1]+i] != "__" ){ /// jesli Krol jest w pozycji 1
                    Co_i_gdzie[1] = pole[zaliczone[0]+i][zaliczone[1]+i];
                    podswietlanie_lol[1][0] = zaliczone[0]+i; podswietlanie_lol[1][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]+i][zaliczone[1]+i].substr(0,1) == "K") pozycja = 1; ///Jesli to byl krol zapiszmy jednak ta pozycje
                    cout << "Coigdzie[1] "<<Co_i_gdzie[1] << endl;
                    //break;
                }
                if( Co_i_gdzie[2] == "__"&&zaliczone[1]+i <=7 && pole[zaliczone[0]][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 2
                    Co_i_gdzie[2] = pole[zaliczone[0]][zaliczone[1]+i];
                    podswietlanie_lol[2][0] = zaliczone[0]; podswietlanie_lol[2][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]][zaliczone[1]+i].substr(0,1) == "K")   pozycja=2;
                    cout << "Coigdzie[2] "<<Co_i_gdzie[2] << endl;
                    //break;
                }
                if(Co_i_gdzie[4] == "__"&&zaliczone[0]-i >=0&&pole[zaliczone[0]-i][zaliczone[1]]!="__"){    ///Pozycja 4
                    Co_i_gdzie[4] = pole[zaliczone[0]-i][zaliczone[1]];
                    podswietlanie_lol[4][0] = zaliczone[0]-i; podswietlanie_lol[4][1] = zaliczone[1];
                    if(pole[zaliczone[0]-i][zaliczone[1]].substr(0,1) == "K")   pozycja=4;
                    cout << "Coigdzie[4] "<<Co_i_gdzie[4] << endl;
                }
                if( Co_i_gdzie[5] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]-i >=0 && pole[zaliczone[0]-i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 5
                    Co_i_gdzie[5] = pole[zaliczone[0]-i][zaliczone[1]-i];
                    podswietlanie_lol[5][0] = zaliczone[0]-i; podswietlanie_lol[5][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]-i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=5;
                    cout << "Coigdzie[5] "<<Co_i_gdzie[5] << endl;
                    //break;
                }
                if( Co_i_gdzie[6] == "__"&&zaliczone[1]-i >=0 && pole[zaliczone[0]][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 6
                    Co_i_gdzie[6] = pole[zaliczone[0]][zaliczone[1]-i];
                    podswietlanie_lol[6][0] = zaliczone[0]; podswietlanie_lol[6][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]][zaliczone[1]-i].substr(0,1) == "K")   pozycja=6;
                    cout << "Coigdzie[6] "<<Co_i_gdzie[6] << endl;
                    //break;
                }
        }
        }
        if(ruch[1]>zaliczone[1]){ /// 1
            cout << "zaliczone[1]<ruch[1]\n";
            for(int i=1;i<=7;i++){
             if(Co_i_gdzie[0] == "__"&&zaliczone[0]+i <=7&&pole[zaliczone[0]+i][zaliczone[1]]!="__"){    ///pozycja 0
                    Co_i_gdzie[0] = pole[zaliczone[0]+i][zaliczone[1]];
                    podswietlanie_lol[0][0] = zaliczone[0]+i; podswietlanie_lol[0][1] = zaliczone[1];
                    if(pole[zaliczone[0]+i][zaliczone[1]].substr(0,1) == "K")   pozycja=0;
                    cout << "Coigdzie[0] "<<Co_i_gdzie[0] << endl;
                }
                if( Co_i_gdzie[2] == "__"&&zaliczone[1]+i <=7 && pole[zaliczone[0]][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 2
                    Co_i_gdzie[2] = pole[zaliczone[0]][zaliczone[1]+i];
                    podswietlanie_lol[2][0] = zaliczone[0]; podswietlanie_lol[2][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]][zaliczone[1]+i].substr(0,1) == "K")   pozycja=2;
                    cout << "Coigdzie[2] "<<Co_i_gdzie[2] << endl;
                    //break;
                }
                if( Co_i_gdzie[3] == "__"&&zaliczone[0]-i >=0 && zaliczone[1]+i <=7 && pole[zaliczone[0]-i][zaliczone[1]+i]!="__"){ /// jesli Krol jest w pozycji 3
                    Co_i_gdzie[3] = pole[zaliczone[0]-i][zaliczone[1]+i];
                    podswietlanie_lol[3][0] = zaliczone[0]-i; podswietlanie_lol[3][1] = zaliczone[1]+i;
                    if(pole[zaliczone[0]-i][zaliczone[1]+i].substr(0,1) == "K")   pozycja=3;
                    cout << "Coigdzie[3] "<<Co_i_gdzie[3] << endl;
                    //break;
                }
                if(Co_i_gdzie[4] == "__"&&zaliczone[0]-i >=0&&pole[zaliczone[0]-i][zaliczone[1]]!="__"){    ///Pozycja 4
                    Co_i_gdzie[4] = pole[zaliczone[0]-i][zaliczone[1]];
                    podswietlanie_lol[4][0] = zaliczone[0]-i; podswietlanie_lol[4][1] = zaliczone[1];
                    if(pole[zaliczone[0]-i][zaliczone[1]].substr(0,1) == "K")   pozycja=4;
                    cout << "Coigdzie[4] "<<Co_i_gdzie[4] << endl;
                }
                if( Co_i_gdzie[6] == "__"&&zaliczone[1]-i >=0 && pole[zaliczone[0]][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 6
                    Co_i_gdzie[6] = pole[zaliczone[0]][zaliczone[1]-i];
                    podswietlanie_lol[6][0] = zaliczone[0]; podswietlanie_lol[6][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]][zaliczone[1]-i].substr(0,1) == "K")   pozycja=6;
                    cout << "Coigdzie[6] "<<Co_i_gdzie[6] << endl;
                    //break;
                }
                if( Co_i_gdzie[7] == "__"&&zaliczone[0]+i<=7 && zaliczone[1]-i >=0 && pole[zaliczone[0]+i][zaliczone[1]-i]!="__"){ /// jesli Krol jest w pozycji 7
                    Co_i_gdzie[7] = pole[zaliczone[0]+i][zaliczone[1]-i];
                    podswietlanie_lol[7][0] = zaliczone[0]+i; podswietlanie_lol[7][1] = zaliczone[1]-i;
                    if(pole[zaliczone[0]+i][zaliczone[1]-i].substr(0,1) == "K")   pozycja=7;
                    cout << "Wspolrzedne coigdzie to "<<podswietlanie_lol[7][0]<<" "<<podswietlanie_lol[7][1]<<endl;
                    cout << "Coigdzie[7] "<<Co_i_gdzie[7] << endl;
                    //break;
                }
        }
    }
    }
    switch(pozycja){ ///Przypisujemy pozycje2 pod to co jest na przeciwko pozycji
            case 0:
                pozycja2 = 4;
                break;
            case 1:
                pozycja2 = 5;
                break;
            case 2:
                pozycja2 = 2;
                break;
            case 3:
                pozycja2 = 7;
                break;
            case 4:
                pozycja2 = 0;
                break;
            case 5:
                pozycja2 = 1;
                break;
            case 6:
                pozycja2 = 2;
                break;
            case 7:
                pozycja2 = 3;
            }

    cout << "Wazna pozycja to "<<pozycja<<endl;
    cout << "kolor przeciwnika "<<kolor_przeciwnika<<endl;
    ///Ostateczne rozwiazanie
    return Sprawdzanie_przeciwnej_strony_od_krola(zaliczone,pole,pozycja2,kolor_przeciwnika,Co_i_gdzie,wspolrzedne,podswietlanie_lol);
}

bool Sprawdzanie_odparcia_szachu(string figura , short int ruch[2] , short int zaliczone[2] , string pole[8][8],string kolor_tury){ ///jezeli szach jest na krolu zwracane jest false
    short int gdzie_krol[2]; /// a tu zapiszemy gdzie jest nasz krol

    /// WYPELNIAMY SYMULACJE POLA

    pole[zaliczone[0]][zaliczone[1]]="__";
    pole[ruch[0]][ruch[1]]=figura+kolor_tury;

    cout<<"a tu dojdzie?"<<endl;
    /// szukamy krola
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            if( pole[y][x] == "K"+kolor_tury){ /// zapisujemy gdzie jest krol zeby potem go nie szukac
                gdzie_krol[0]=y; gdzie_krol[1]=x;
                break;
            }
        }
    }

    /// SPRAWDZAMY CZY KROL JEST TERAZ ATAKOWANY
    cout<<"Y krola-"<<gdzie_krol[0]<<" X krola-"<<gdzie_krol[1]<<endl;
    cout<<"Y figury-"<<ruch[0]<<" X figury-"<<ruch[1]<<endl;

    if(Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0], gdzie_krol[1],pole,kolor_tury)==true){
        cout<<"RETURNED FALSE;"<<endl;

        pole[zaliczone[0]][zaliczone[1]]=figura+kolor_tury;
        pole[ruch[0]][ruch[1]]="__";
        return false;
    }
    cout<<"RETURNED TRUE;"<<endl;
    pole[zaliczone[0]][zaliczone[1]]=figura+kolor_tury;
    pole[ruch[0]][ruch[1]]="__";
    return true;
}

bool Ostateczny_sprawdzacz_mata(short int y,short int x,short int atakujacy[2],string pole[8][8],string kolor_tury){ /// Jezeli jest mat zwraca true
    string kolor_przeciwnika= kolor_tury=="B" ? "C" : "B";
    short int gdzie_krol[2]={11,11};

    /// SZUKAMY KROLA
    gdzie_krol[0]=y; gdzie_krol[1]=x;
    cout << "a";

    if(pole[atakujacy[0]][atakujacy[1]][0]=='S' || pole[atakujacy[0]][atakujacy[1]][0]=='P' ){
        if(Sprawdzanie_czy_pole_jest_atakowane(atakujacy[0],atakujacy[1],pole,kolor_przeciwnika)==true){ ///zwrot akcji takie tam masz tto opisane troszke nizej
            return false;
        }
    }
    cout << "a";
        /// ZEGAREK, ZACZYNAMY SPRAWDZAC OD STRONY KROLA ( WIEZA GONIEC HETMAN)
    if(gdzie_krol[0]<atakujacy[0] && gdzie_krol[1]==atakujacy[1]){ /// 0
        for(int i=1;;i++){
            cout<<"a niech mnie dunder scisnie"<<endl;
            if( Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0]+i,gdzie_krol[1],pole,kolor_przeciwnika)==true ){ /// BUM ZWROT AKCJI!!!! DAJEMY TAM KOLOR PRZECIWNIKA ZEBY SPRAWDZAL CZY MOZE ZASLONIC NASZA FIGURA
                cout<<"jeszcze jest nadzieja"<<endl;
                return false;
            }
            else if(gdzie_krol[0]+i==atakujacy[0]){
                cout<<"macik"<<endl;
                return true;

            }
        }
    }
    cout << "a";
    if(gdzie_krol[0]<atakujacy[0] && gdzie_krol[1]<atakujacy[1]){ /// 1
        for(int i=1;;i++){
            cout<<"a niech mnie dunder scisnie"<<endl;
            if( Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0]+i,gdzie_krol[1]+i,pole,kolor_przeciwnika)==true ){ /// BUM ZWROT AKCJI!!!! DAJEMY TAM KOLOR PRZECIWNIKA ZEBY SPRAWDZAL CZY MOZE ZASLONIC NASZA FIGURA
                cout<<"jeszcze jest nadzieja"<<endl;
                return false;
            }
            else if(gdzie_krol[0]+i==atakujacy[0] && gdzie_krol[1]+i==atakujacy[1]){
                cout<<"macik"<<endl;
                return true;

            }
        }
    }
    cout << "TU WCHODZI"<<endl;
    if(gdzie_krol[0]==atakujacy[0] && gdzie_krol[1]<atakujacy[1]){ /// 2
        for(int i=1;;i++){
            cout<<"a niech mnie dunder scisnie"<<endl;
            if( Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0],gdzie_krol[1]+i,pole,kolor_przeciwnika)==true ){ /// BUM ZWROT AKCJI!!!! DAJEMY TAM KOLOR PRZECIWNIKA ZEBY SPRAWDZAL CZY MOZE ZASLONIC NASZA FIGURA
                cout<<"jeszcze jest nadzieja"<<endl;
                return false;
            }
            else if(gdzie_krol[1]+i==atakujacy[1]){
                cout<<"macik"<<endl;
                return true;

            }
        }
    }
    cout << "a";
    if(gdzie_krol[0]>atakujacy[0] && gdzie_krol[1]<atakujacy[1]){ /// 3
        for(int i=1;;i++){
            cout<<"a niech mnie dunder scisnie"<<endl;
            if( Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0]-i,gdzie_krol[1]+i,pole,kolor_przeciwnika)==true ){ /// BUM ZWROT AKCJI!!!! DAJEMY TAM KOLOR PRZECIWNIKA ZEBY SPRAWDZAL CZY MOZE ZASLONIC NASZA FIGURA
                cout<<"jeszcze jest nadzieja"<<endl;
                return false;
            }
            else if(gdzie_krol[0]-i==atakujacy[0] && gdzie_krol[1]+i==atakujacy[1]){
                cout<<"macik"<<endl;
                return true;

            }
        }
    }
    cout << "a";
    if(gdzie_krol[0]>atakujacy[0] && gdzie_krol[1]==atakujacy[1]){ /// 4
        for(int i=1;;i++){
            cout<<"a niech mnie dunder scisnie"<<endl;
            if( Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0]-i,gdzie_krol[1],pole,kolor_przeciwnika)==true ){ /// BUM ZWROT AKCJI!!!! DAJEMY TAM KOLOR PRZECIWNIKA ZEBY SPRAWDZAL CZY MOZE ZASLONIC NASZA FIGURA
                cout<<"jeszcze jest nadzieja"<<endl;
                return false;
            }
            else if(gdzie_krol[0]-i==atakujacy[0]){
                cout<<"macik"<<endl;
                return true;

            }
        }
    }
    cout << "a";
    if(gdzie_krol[0]>atakujacy[0] && gdzie_krol[1]>atakujacy[1]){ /// 5
        for(int i=1;;i++){
            cout<<"a niech mnie dunder scisnie"<<endl;
            if( Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0]-i,gdzie_krol[1]-i,pole,kolor_przeciwnika)==true ){ /// BUM ZWROT AKCJI!!!! DAJEMY TAM KOLOR PRZECIWNIKA ZEBY SPRAWDZAL CZY MOZE ZASLONIC NASZA FIGURA
                cout<<"jeszcze jest nadzieja"<<endl;
                return false;
            }
            else if(gdzie_krol[0]-i==atakujacy[0] && gdzie_krol[1]-i==atakujacy[1]){
                cout<<"macik"<<endl;
                return true;

            }
        }
    }
    cout << "a";
    if(gdzie_krol[0]==atakujacy[0] && gdzie_krol[1]>atakujacy[1]){ /// 6
        for(int i=1;;i++){
            cout<<"a niech mnie dunder scisnie"<<endl;
            if( Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0],gdzie_krol[1]-i,pole,kolor_przeciwnika)==true ){ /// BUM ZWROT AKCJI!!!! DAJEMY TAM KOLOR PRZECIWNIKA ZEBY SPRAWDZAL CZY MOZE ZASLONIC NASZA FIGURA
                cout<<"jeszcze jest nadzieja"<<endl;
                return false;
            }
            else if(gdzie_krol[1]-i==atakujacy[1]){
                cout<<"macik"<<endl;
                return true;

            }
        }
    }
    cout << "a";
    if(gdzie_krol[0]<atakujacy[0] && gdzie_krol[1]>atakujacy[1]){ /// 7
        for(int i=1;;i++){
            cout<<"a niech mnie dunder scisnie"<<endl;
            if( Sprawdzanie_czy_pole_jest_atakowane(gdzie_krol[0]+i,gdzie_krol[1]-i,pole,kolor_przeciwnika)==true ){ /// BUM ZWROT AKCJI!!!! DAJEMY TAM KOLOR PRZECIWNIKA ZEBY SPRAWDZAL CZY MOZE ZASLONIC NASZA FIGURA
                cout<<"jeszcze jest nadzieja"<<endl;
                return false;
            }
            else if(gdzie_krol[0]+i==atakujacy[0] && gdzie_krol[1]-i==atakujacy[1]){
                cout<<"macik"<<endl;
                return true;

            }
        }
    }
    cout<<"?"<<endl;
    return true;
}

bool Sprawdzanie_mozliwosci_wykonania_ruchu(short int y, short int x, string figura, string pole[8][8], string kolor_tury){ /// true jesli moze wykonac ruch

    if(figura=="S"){
         if((y+2<=7 && x+1<=7 && pole[y+2][x+1].substr(1,1)!=kolor_tury) || (y+1<=7 && x+2<=7 && pole[y+1][x+2].substr(1,1)!=kolor_tury) || /// 0 1
            (y+2<=7 && x-1>=0 && pole[y+2][x-1].substr(1,1)!=kolor_tury) || (y-1>=0 && x+2<=7 && pole[y-1][x+2].substr(1,1)!=kolor_tury) || /// 2 3
            (y-2>=0 && x-1>=7 && pole[y-2][x-1].substr(1,1)!=kolor_tury) || (y-1>=0 && x-2>=0 && pole[y-1][x-2].substr(1,1)!=kolor_tury) || /// 4 5
            (y+1<=7 && x-2>=0 && pole[y+1][x-2].substr(1,1)!=kolor_tury) || (y+2<=7 && x-1>=0 && pole[y+2][x-1].substr(1,1)!=kolor_tury) ){ /// 6 7
            return true;
        }
    }
    else if(figura=="P"){
        string kolor_przeciwnika= kolor_tury=="B" ? "C" : "B" ;

        if(kolor_tury=="B"){
            if((y+1<=7 && x-1>=0 && pole[y+1][x-1].substr(1,1) == kolor_przeciwnika) || /// 7   moze sie ruszyc tylko gdy na ukos jest figura przeciwnika
               (y+1<=7 && pole[y+1][x].substr(1,1) == "_") ||                           /// 0   moze sie ruszyc tylko gdy przed nim jest _
               (y+1<=7 && x+1<=7 && pole[y+1][x+1].substr(1,1) == kolor_przeciwnika) ){ /// 1
                return true;
            }
        }
        else { /// kolor tury to C
            if((y-1>=0 && x-1>=0 && pole[y-1][x-1].substr(1,1) == kolor_przeciwnika) || /// 5   moze sie ruszyc tylko gdy na ukos jest figura przeciwnika
               (y-1>=0 && pole[y-1][x].substr(1,1) == "_") ||                           /// 4   moze sie ruszyc tylko gdy przed nim jest _
               (y-1>=0 && x+1<=7 && pole[y-1][x+1].substr(1,1) == kolor_przeciwnika) ){ /// 3
                return true;
            }
        }
    }
    else if(figura=="W" || figura=="H"){
        if(y+1<=7 && pole[y+1][x].substr(1,1) != kolor_tury){ /// (0) jesli znajduje sie na planszy te pole i nie ma na nim naszej figury
            return true;
        }
        if(x+1<=7 && pole[y][x+1].substr(1,1) != kolor_tury){ /// 2
            return true;
        }
        if(y-1>=0 && pole[y-1][x].substr(1,1) != kolor_tury){ /// 4
            return true;
        }
        if(x-1>=0 && pole[y][x-1].substr(1,1) != kolor_tury){ /// 6
            return true;
        }

    }
    ///Tu nie ma byc else if bo hetman skorzysta i z tego i z tego
    if(figura=="G" || figura=="H"){
        if(y+1<=7 && x+1<=7 && pole[y+1][x+1].substr(1,1) != kolor_tury){ /// 1
            return true;
        }
        if(y-1>=0 && x+1<=7 && pole[y-1][x+1].substr(1,1) != kolor_tury){ /// 3
            return true;
        }
        if(y-1>=0 && x-1>=0 && pole[y-1][x-1].substr(1,1) != kolor_tury){ /// 5
            return true;
        }
        if(y+1<=7 && x-1>=0 && pole[y+1][x-1].substr(1,1) != kolor_tury){ /// 7
            return true;
        }
    }
    return false;
}

int main(){
    /// Pobieranie Danych
    string gracz1="bialy",gracz2="czarny";

    fstream plik;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";


    int nasz_kolor, kolor_saturnina;

    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok=false; sprawdzacz_bledow(0);}
    plik>> kolor_saturnina >> nasz_kolor;
    plik.close();

    nazwa = lokacja + "szachy-nazwy";

    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    getline(plik,gracz1); getline(plik,gracz2);
    plik.close();

    /// TWORZENIE PLANSZY
    string pole[8][8];
    pole[0][0]="WB"; pole[0][7]="WB"; pole[7][0]="WC"; pole[7][7]="WC";
    pole[0][1]="SB"; pole[0][6]="SB"; pole[7][1]="SC"; pole[7][6]="SC";
    pole[0][2]="GB"; pole[0][5]="GB"; pole[7][2]="GC"; pole[7][5]="GC";
    pole[0][4]="KB"; pole[0][3]="HB"; pole[7][4]="KC"; pole[7][3]="HC";

    for(int i=1;i<=3;i++){
        for(int j=0;j<=7;j++){
            if(i==1){
                pole[i][j]="PB";
                pole[7-i][j]="PC";
            }
            else{
                pole[i][j]="__";
                pole[7-i][j]="__";
            }
        }
    }

    string ruch="", kolor_tury="B";
    ///Obie te tablice licza sie od 0 (jakby co uwaga bo czasami mamy +1 lol)
    short int pomocniczy[10][2], licznik_pomocy=0;      ///Wszystkie miejsca figur o tej samej nazwie
    short int zaliczone[10][2]; /// Wszystkie miejsca figur ktore spelniaja wszystkie warunki do tego ruchu
    bool mozliwosc_malej_roszady[2]={true,true}; /// 0- bialy 1- czarny
    bool mozliwosc_duzej_roszady[2]={true,true};
    bool szachowany_krol[2]={false,false}; /// 0- bialy 1- czarny
    short int bicie_w_przelocie=11 ; /// numer pionka ktory ruszyl sie ostatnio o 2 pola
    bool czy_wykonany_przelot=false; /// czy w ostatniej turze byl wykonany przelot

//    / /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///
//
//    for(int i=1;i<=3;i++){
//        for(int j=0;j<=7;j++){
//            if(i==1){
//                pole[i][j]="__";
//                pole[7-i][j]="__";
//            }
//            else{
//                pole[i][j]="__";
//                pole[7-i][j]="__";
//            }
//        }
//    }
//    pole[0][0]="WB"; pole[0][7]="WB"; pole[7][0]="KC"; pole[7][7]="__"; pole[7][3]="__";    pole[4][5] = "WC";
//    pole[0][1]="__"; pole[0][6]="__"; pole[7][1]="__"; pole[7][6]="__";
//    pole[0][2]="__"; pole[0][5]="__"; pole[7][2]="__"; pole[7][5]="__";
//                      pole[0][3]="__"; pole[7][4]="__"; pole[1][6]="__";
//
//    pole[0][4]="KB"; pole[3][4]="__";
//    pole[6][7]="WC"; pole[6][6]="WC"; pole[6][5]="WC";
//    / /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///

    for(long long tura=0;;tura++){

        licznik_pomocy=0; licznik_zaliczonych=0;
        szachowany_krol[0]==false; szachowany_krol[1]==false;

        system("cls");
        rysuj(pole);
        cout<<endl;
        if(tura%2==0){
            kolor("bialy");
            kolor_tury="B";
        }
        else{
            kolor("czarny");
            kolor_tury="C";
        }
        /// SPRAWDZANIA POL WOKOL KROLA ,SPRAWDZAMY CZY POLA WOKOL KROLA SĄ ATAKOWANE ALBO STOI NA NICH PRZYJAZNA FIGURA LUB NIE MA TAKIEGO POLA
        bool czy_atakowane_pola_wokol_krola=false;
        int ZUPELNIE_NIEPOTRZEBNA_TABLICA_2_ZMIENNYCH_BO_NIE_MOGE_INACZEJ_ZROBIC_BOZE_WSZYSTKICH_INFORMATYKOW_WYBACZ_MI[2];
        for(int y=0;y<8;y++){
            for(int x=0;x<8;x++){
                if(pole[y][x]=="K"+kolor_tury){
                    pole[y][x]="__";
                    ZUPELNIE_NIEPOTRZEBNA_TABLICA_2_ZMIENNYCH_BO_NIE_MOGE_INACZEJ_ZROBIC_BOZE_WSZYSTKICH_INFORMATYKOW_WYBACZ_MI[0]=y;
                    ZUPELNIE_NIEPOTRZEBNA_TABLICA_2_ZMIENNYCH_BO_NIE_MOGE_INACZEJ_ZROBIC_BOZE_WSZYSTKICH_INFORMATYKOW_WYBACZ_MI[1]=x;
                    do{
                        cout<<"nie wierze"<<endl;
                        if( (y+1<=7) && (pole[y+1][x].substr(1,1)!=kolor_tury   && Sprawdzanie_czy_pole_jest_atakowane(y+1,x    ,pole,kolor_tury)==false)) /// 0
                                { break;}cout<<"d";
                        if((y+1<=7 && x+1<=7) && (pole[y+1][x+1].substr(1,1)!=kolor_tury && Sprawdzanie_czy_pole_jest_atakowane(y+1,x+1  ,pole,kolor_tury)==false)) /// 1
                                { break;}cout<<"d";
                        if((x+1<=7) && (pole[y][x+1].substr(1,1)!=kolor_tury   && Sprawdzanie_czy_pole_jest_atakowane(y,x+1    ,pole,kolor_tury)==false)) /// 2
                                { break;}cout<<"d";
                        if((y-1>=0 && x+1<=7) && (pole[y-1][x+1].substr(1,1)!=kolor_tury && Sprawdzanie_czy_pole_jest_atakowane(y-1,x+1  ,pole,kolor_tury)==false)) /// 3
                                { break;}cout<<"d";
                        if((y-1>=0) && (pole[y-1][x].substr(1,1)!=kolor_tury   && Sprawdzanie_czy_pole_jest_atakowane(y-1,x    ,pole,kolor_tury)==false)) /// 4
                                { break;}cout<<"d";
                        if((y-1>=0 && x-1>=0) && (pole[y-1][x-1].substr(1,1)!=kolor_tury && Sprawdzanie_czy_pole_jest_atakowane(y-1,x-1  ,pole,kolor_tury)==false)) /// 5
                                { break;}cout<<"d";
                        if((x-1>=0) && (pole[y][x-1].substr(1,1)!=kolor_tury   && Sprawdzanie_czy_pole_jest_atakowane(y,x-1    ,pole,kolor_tury)==false)) /// 6
                                { break;}cout<<"d";
                        if((y+1<=7 && x-1>=0) && (pole[y+1][x-1].substr(1,1)!=kolor_tury && Sprawdzanie_czy_pole_jest_atakowane(y+1,x-1  ,pole,kolor_tury)==false)) /// 7
                                { break;}
                                cout<<"UWAGA WSZYSTKIE POLA WOKOL KROLA SA ATAKOWANE"<<endl;
                                czy_atakowane_pola_wokol_krola=true;
                    }while(0);
                    goto spadam;
                }
            }
        }
        spadam:
        pole[ZUPELNIE_NIEPOTRZEBNA_TABLICA_2_ZMIENNYCH_BO_NIE_MOGE_INACZEJ_ZROBIC_BOZE_WSZYSTKICH_INFORMATYKOW_WYBACZ_MI[0]][ZUPELNIE_NIEPOTRZEBNA_TABLICA_2_ZMIENNYCH_BO_NIE_MOGE_INACZEJ_ZROBIC_BOZE_WSZYSTKICH_INFORMATYKOW_WYBACZ_MI[1]]="K"+kolor_tury;
        /// SPRAWDZANIE CZY KROL JEST POD SZACHEM
        for(int y=0;y<8;y++){
            for(int x=0;x<8;x++){
                if(pole[y][x]=="K"+kolor_tury){
                    short int kto_atakuje[2]={11,11}; /// jezeli pole bedzie atakowane beda tu wspolzedne tej figury
                    /**
                    11- tablica nie zostala nadpisana
                    10- krola atakuje wiecej niz jedna figura
                    */

                    pole[y][x]="__"; /// usuwamy krola bo nam pozniej zaslania
                    //cout<<"kolor_tury-"<<kolor_tury<<endl;
                    if( SPECJALNE_sprawdzanie_czy_pole_jest_atakowane(y,x, pole,kolor_tury,kto_atakuje)==true){
                        do{
                                ///SPRAWDZAMY CZY POLA WOKOL KROLA SĄ ATAKOWANE ALBO STOI NA NICH PRZYJAZNA FIGURA LUB NIE MA TAKIEGO POLA
                            cout<<"uwaga wchodze-"<<kto_atakuje[0]<<endl;
                            if(czy_atakowane_pola_wokol_krola==false){ break;}
                            cout<<"doszedlem az tutaj!"<<endl;
                            if(kto_atakuje[0]==10){
                                cout<<"MAT"<<endl;
                                return 0;
                            }else{
                                pole[y][x]="K"+kolor_tury;
                                cout<< "turur"<<endl;
                                if(Ostateczny_sprawdzacz_mata(y,x,kto_atakuje,pole,kolor_tury)==false){
                                    break;
                                }
                                else{
                                    /// GDY JEST MAT
                                    cout<< "Mat"<<endl;
                                    return 0;
                                }
                            }

                        }while(0);
                        cout<<"Twoj krol jest atakowany!"<<endl;
                        szachowany_krol[ kolor_tury == "B" ? 0:1 ]= true;
                    }
                    pole[y][x]="K"+kolor_tury;
                    goto no_to_kamien;
                }
            }
        }
        no_to_kamien:
        //cout<<"?"<<endl;
        /// SPRAWDZANIE PATA
        if(czy_atakowane_pola_wokol_krola==true){
            //cout<<"AAA"<<endl;
            for(int y=0;y<8;y++){ /// lecimy po kazdym polu w szachownicy
                for(int x=0;x<8;x++){ /// i jesli znajdziemy nasza figure to sprawdzamy czy moze wykonac ruch
                    //cout<<"   to ja tu wejde"<<endl;
                    if(pole[y][x].substr(1,1)==kolor_tury){ /// jezeli moze wykonac to wywalamy petle bo nie ma pata
                        //cout<<"   to ja tu jestem"<<endl;
                        if(Sprawdzanie_mozliwosci_wykonania_ruchu(x,y,pole[y][x].substr(0,1),pole, kolor_tury)==true){
                            //cout<<"   to ja wychodze"<<endl;
                            goto nie_ma_pata;
                        }
                    }
                }
            }
            /// Jezeli tu dotarl to znaczy ze przeszedl cala plansze i zadna przyjazna figura nie mogla zrobic ruchu
            cout<<" PACIK KOCHANI"<<endl;
            return 0;

        }
        nie_ma_pata:
        /// WCZTUJEMY RUCH
        string pseudo_ruch;
        cout<< "ruch "<< (kolor_tury=="B"? gracz1 : gracz2) <<":";
        cin >> pseudo_ruch;
        ruch=pseudo_ruch.substr(0,1)+pseudo_ruch.substr(2,1)+pseudo_ruch.substr(1,1); /// jestem genialny
        short int tablica[2] = {lnn(ruch.substr(1,1)) , lnn(ruch.substr(2,1)) };

        /// MINI KOMENDY

        if(pseudo_ruch=="/poddaj"){
            kolor(kolor_tury == "C" ? "B":"C");
            cout<<"\n   PRZEGRALES!\n";
            getch();
            return 0;
        }

        /// OD RAZU SPRAWDZAMY PARE BLEDOW

        if(pole[lnn(ruch.substr(1,1))][lnn(ruch.substr(2,1))].substr(1,1)==kolor_tury){
            niepoprawny_ruch:
            cout<<"Niepoprawny ruch!";
            getch();
            tura--;
            system("cls");
            continue;
        }


        ///SZUKAMY WSZYSTKICH FIGOR MAJACYCH WYKONAC RUCH

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(pole[i][j].substr(0,1)==ruch.substr(0,1) && pole[i][j].substr(1,1)== kolor_tury){
                    pomocniczy[licznik_pomocy][0]=i; ///po znalezieniu figury, wpisuje jej kordynaty do pomocniczej zmiennej
                    pomocniczy[licznik_pomocy][1]=j;
                    licznik_pomocy++;
                }
            }
        }


        ///SPRAWDZAMY CZY MOZE TA FIGURA WYKONAC RUCH



        //cout << lnn(ruch.substr(1,1)) << " " << lnn(ruch.substr(2,1))<< endl;
        int zmienna = 13.6; /// lol ?
        for(int i=0;i<=licznik_pomocy-1;i++){
            //cout<<"PARARAR " <<licznik_zaliczonych<<endl;
            if(ruch.substr(0,1)=="W"){
                //cout << "Wieza ?\n";
                if(Sprawdzanie_ruchu_Wieza( pomocniczy[i] , tablica , pole , &zaliczone[licznik_zaliczonych]))      licznik_zaliczonych++;


            }
            else if(ruch.substr(0,1)=="G"){

                if(Sprawdzanie_ruchu_goniec(pomocniczy[i] , tablica , pole , &zaliczone[licznik_zaliczonych]))  licznik_zaliczonych++;
                //cout << "loll\n";

            }
            else if(ruch.substr(0,1)=="S"){
                if(Sprawdzanie_ruchu_skoczek(pomocniczy[i], tablica, pole, &zaliczone[licznik_zaliczonych]))    licznik_zaliczonych++;
                //cout << zaliczone[i][0]<<"---"<<zaliczone[i][1]<<endl;
                }
            else if(ruch.substr(0,1)=="P"){
                if(Sprawdzanie_ruchu_pionek(pomocniczy[i], tablica, pole, &zaliczone[licznik_zaliczonych],kolor_tury, bicie_w_przelocie))  licznik_zaliczonych++;
                //cout<< zaliczone[0][0]<<zaliczone[0][1]<<"]"<<licznik_zaliczonych<<endl;
                cout<<"BICIE W PRZELOCIE"<<bicie_w_przelocie<<endl;
            }
            else if(ruch.substr(0,1)=="H"){
                if(Sprawdzanie_ruchu_Hetman( pomocniczy[i] , tablica , pole , &zaliczone[licznik_zaliczonych] ))    licznik_zaliczonych++;
            }
            else if(ruch.substr(0,1)=="K"){
                if(Sprawdzanie_ruchu_Krol( pomocniczy[i] , tablica , pole , &zaliczone[licznik_zaliczonych], kolor_tury , mozliwosc_malej_roszady[kolor_tury == "B" ? 0:1], mozliwosc_duzej_roszady[kolor_tury == "B"?0:1] )==true){
                    mozliwosc_malej_roszady[kolor_tury=="B" ? 0:1]=false;
                    mozliwosc_duzej_roszady[kolor_tury == "B"?0:1]=false;
                }
                pole[pomocniczy[licznik_pomocy-1][0]][pomocniczy[licznik_pomocy-1][1]]="K"+kolor_tury;
                break;
            }

        }
        //cout<< "/"<<licznik_pomocy<<" "<<licznik_zaliczonych<<endl;

        /// GDY KROL BYL POD SZACHEM SPRAWDZAMY CZY DALEJ JEST

            if(szachowany_krol[ kolor_tury == "B" ? 0:1 ]== true){
                cout<<"ALERT KROL ATAKOWANY"<<endl;
                short int licznik_zaliczonych2=0;
                for(int i=0;i<licznik_zaliczonych;i++){
                    cout<<"no to hop"<<endl;
                    if(Sprawdzanie_odparcia_szachu(ruch.substr(0,1),tablica,zaliczone[i],pole,kolor_tury) == true){

                        /// nadpisanie tablicy i licznika zaliczonych figurami po ktorych ruchu krol juz nie jest szachowany
                        cout<<"ALERT KROL NIE ATAKOWANYYYYYYYYYYYYYYYYYYYYY"<<endl;
                        zaliczone[licznik_zaliczonych2][0]= zaliczone[i][0];
                        zaliczone[licznik_zaliczonych2][1]= zaliczone[i][1];
                        licznik_zaliczonych2++;
                    }
                }
                licznik_zaliczonych=licznik_zaliczonych2;
            }

        /// GDY JEST WIECEJ NIZ JEDNA FIGURA DO WYBORU RUCHU LUB NIE MA ZADNEJ

        short int wybor_pomocniczy[2];

        if(licznik_zaliczonych == 0 ){
            goto niepoprawny_ruch;
        }
        else if(licznik_zaliczonych > 1){
            short int gdzie_jest_znacznik = 0;
            short int zaliczonev2[licznik_zaliczonych][2]; /// kolejny filtr zaliczonych
            int j = 0; /// licznik zaliczonych v2
            short int atakujacy[2] ={0,0};
            for(int i=0;i<licznik_zaliczonych*2;i=i+2)  ///Sprawdzamy ile z tych figur ktorymi mozemy sie tam ruszyc nie odsloni jednoczesnie krola
            {
                short int kupa[2] = {lnn(ruch.substr(1,1)),lnn(ruch.substr(2,1))};
                cout<<"prrrr"<<endl;
                if(Sprawdzanie_odkrywania_Krola_pod_szach(kupa,zaliczone[i],pole,atakujacy) == false)
                {
                        zaliczonev2[j][0] = zaliczone[i][0];    zaliczonev2[j][1] = zaliczone[i][1];
                        j++;
                }
            }
            getch();

            if(j == 0)  ///Jesli kazda odsloni krola rzucamy blad
            {
                system("cls");
                rysuj(pole,atakujacy[0],atakujacy[1]);
                cout << "\nWszystkie figury po ruchu odslaniaja krola!\n";
                goto niepoprawny_ruch;
            }
            else if(j == 1)
            {

                wybor_pomocniczy[0]=zaliczonev2[0][0];
                wybor_pomocniczy[1]=zaliczonev2[0][1];
                goto mamy_wybor;
            }
            else if(j<licznik_zaliczonych)  ///Jesli jedna z figur odslania krola ale figur jest wiecej i nadal potrzebujemy wyboru
            {
                for(;;)
                {
                    system("cls");
                    rysuj(pole,zaliczonev2[gdzie_jest_znacznik][0],zaliczonev2[gdzie_jest_znacznik][1]);
                    kolor(kolor_tury);
                    cout << "Ktora z tych figur ma wykonac ruch? "<<endl;
                    //cout << gdzie_jest_znacznik << endl;
                    for(int i=0;i<j;i++){
                        //cout << zaliczone[i][0]+1<<"-!-"<<zaliczone[i][1]+1<<endl;
                        gdzie_jest_znacznik==i ? kolor("special") : kolor(kolor_tury);
                        cout << (gdzie_jest_znacznik==i ? "\26" : " ")<<ruch.substr(0,1)<<nnl(zaliczone[i][1])<<zaliczone[i][0]+1<<endl;
                    }
                    for(;;)
                    {
                        short int znak = getch();
                        if(znak == 115) ///S
                        {
                            gdzie_jest_znacznik == j-1 ?  : gdzie_jest_znacznik ++;
                            break;
                        }
                        else if(znak == 119) ///W
                        {
                            gdzie_jest_znacznik == 0 ?  : gdzie_jest_znacznik -- ;
                            break;
                        }
                        else if(znak == 13)
                        {
                            wybor_pomocniczy[0] = zaliczonev2[gdzie_jest_znacznik][0];
                            wybor_pomocniczy[1] = zaliczonev2[gdzie_jest_znacznik][1];
                            goto mamy_wybor;
                        }
                        }
                    }
            }
            else    ///Jesli kazda figura ktora mozna sie ruszyc nie odslania krola
            {
                for(;;)
                {
                    system("cls");
                    rysuj(pole,zaliczone[gdzie_jest_znacznik*2][0],zaliczone[gdzie_jest_znacznik*2][1]);
                    kolor(kolor_tury);
                    cout << "Ktora z tych figur ma wykonac ruch? "<<endl;
                    //cout << gdzie_jest_znacznik << endl;
                    for(int i=0;i<licznik_zaliczonych*2;i=i+2){     ///To razy dwa ktore sie tu dzieje to wina ze wlasciwe rzeczy sa co drugie w tablicy lol
                        //cout << zaliczone[i][0]+1<<"-!-"<<zaliczone[i][1]+1<<endl;
                        gdzie_jest_znacznik*2==i ? kolor("special") : kolor(kolor_tury);
                        cout << (gdzie_jest_znacznik*2==i ? "\26" : " ")<<ruch.substr(0,1)<<nnl(zaliczone[i][1])<<zaliczone[i][0]+1<<endl;
                    }
                    for(;;)
                    {
                        short int znak = getch();
                        if(znak == 115) ///S
                        {
                            gdzie_jest_znacznik == licznik_zaliczonych-1 ?  : gdzie_jest_znacznik ++;
                            break;
                        }
                        else if(znak == 119) ///W
                        {
                            gdzie_jest_znacznik == 0 ?  : gdzie_jest_znacznik -- ;
                            break;
                        }
                        else if(znak == 13)
                        {
                            wybor_pomocniczy[0] = zaliczone[gdzie_jest_znacznik*2][0];
                            wybor_pomocniczy[1] = zaliczone[gdzie_jest_znacznik*2][1];
                            goto mamy_wybor;
                        }
                        }
                    }
            }

            mamy_wybor:
            zaliczone[0][0]=wybor_pomocniczy[0];
            zaliczone[0][1]=wybor_pomocniczy[1];
        }

        /// WYKONUJEMY RUCH
        short int podswietlenie_ataku[2] = {0,0};
        short int kupa[2] = {lnn(ruch.substr(1,1)),lnn(ruch.substr(2,1))};
        if(ruch.substr(0,1) != "K" && Sprawdzanie_odkrywania_Krola_pod_szach(kupa,zaliczone[0],pole,podswietlenie_ataku) == true)
        {
            cout << "Wspolrzedne atakujacego to "<<podswietlenie_ataku[0]<<" "<<podswietlenie_ataku[1]<<endl;
            getch();
            system("cls");
            rysuj(pole,podswietlenie_ataku[0],podswietlenie_ataku[1]);
            cout << "\nOdslaniasz Krola!\n";
            goto niepoprawny_ruch;
        }
        //cout<< zaliczone[0][0]<<":"<<zaliczone[0][1]<<":"<<pole[zaliczone[0][0]][zaliczone[0][1]]<<endl;
        /** if(zaliczone[0][0] == 0 && zaliczone[0][1] == 1 && ruch.substr(0,1) == "W")
        {
            mozliwosc_duzej_roszady[kolor_tury == "B" ? 0:1] = false;
        }
        else if(zaliczone[0][0] == 6 && zaliczone[0][1] == 7 && ruch.substr(0,1) == "W")
        {
            mozliwosc_duzej_roszady[kolor_tury == "B" ? 0:1] = false;
        }*/
        pole[zaliczone[0][0]][zaliczone[0][1]]="__";
        pole[lnn(ruch.substr(1,1))][lnn(ruch.substr(2,1))]=ruch.substr(0,1)+ kolor_tury;
        //cout<<" 2. "<<zaliczone[0][0]<<":"<<zaliczone[0][1]<<":"<<pole[zaliczone[0][0]][zaliczone[0][1]]<<endl;
        /// SPRAWDZAMY CZY PIONEK NIE WYKONAL BICIA W PRZELOCIE
        if(kolor_tury=="B" && zaliczone[0][0]==4 && abs(zaliczone[0][1]-bicie_w_przelocie)==1){
            pole[lnn(ruch.substr(1,1))-1][lnn(ruch.substr(2,1))]="__";
        }
        else if(kolor_tury=="C" && zaliczone[0][0]==3 && abs(zaliczone[0][1]-bicie_w_przelocie)==1){
            pole[lnn(ruch.substr(1,1))+1][lnn(ruch.substr(2,1))]="__";
        }
        getch();
        system("cls");
        rysuj(pole);
        /// JEZELI PIONEK WYKONAL RUCH O 2 POLA
        if(ruch.substr(0,1)=="P"){
            cout<<"LLLLLLLLL"<<endl;
            if(kolor_tury=="B"){
                if( zaliczone[0][0] + 2 == lnn(ruch.substr(1,1)) ){
                    bicie_w_przelocie=zaliczone[0][1];
                }
                else{
                    bicie_w_przelocie=11;
                }
            }
            else{ /// kolor_tury== C
                if( zaliczone[0][0]-2 == lnn(ruch.substr(1,1)) ){
                    bicie_w_przelocie=zaliczone[0][1];
                }
                else{
                    bicie_w_przelocie=11;
                }
            }
        }
        else{
            bicie_w_przelocie=11;
        }
        cout<<bicie_w_przelocie<<endl;
        getch();
        ///SPRAWDZAMY CZY PIONEK JEST NA KONCU SWEJ DROGI KU NIESAMOWITOSCI
        for(int x=0;x<8;x++){
            if(pole[7][x]=="PB" || pole[0][x]=="PC"){
                string figura=""; int strzalka;
                short int nr_wyboru=0;
                kolor(kolor_tury=="B" ? "bialy":"czarny");
                for(int i=0;;i++){
                    system("cls");
                    rysuj(pole,kolor_tury=="B"? 7:0,x);
                    cout<<"Czym stac sie ma pionek?"<<endl;

                    kolor(kolor_tury=="B" ? "bialy":"czarny");

                    if(nr_wyboru==0){kolor("special"); cout<<"-"; figura="H";} else {cout << " "; kolor(kolor_tury=="B" ? "bialy":"czarny"); }
                    cout<<"H"<<endl;
                    if(nr_wyboru==1){kolor("special"); cout<<"-"; figura="W";} else {cout << " "; kolor(kolor_tury=="B" ? "bialy":"czarny"); }
                    cout<<"W"<<endl;
                    if(nr_wyboru==2){kolor("special"); cout<<"-"; figura="G";} else {cout << " "; kolor(kolor_tury=="B" ? "bialy":"czarny"); }
                    cout<<"G"<<endl;
                    if(nr_wyboru==3){kolor("special"); cout<<"-"; figura="S";} else {cout << " "; kolor(kolor_tury=="B" ? "bialy":"czarny"); }
                    cout<<"S"<<endl;

                    strzalka=getch();
                    if(strzalka==119 && nr_wyboru-1 >= 0){ /// W
                        nr_wyboru--;
                    }
                    else if(strzalka==115 && nr_wyboru+1 <= 4){ /// S
                        nr_wyboru++;
                    }
                    else if(strzalka==13 ){ /// enter
                        break;
                    }
                }
                pole[kolor_tury == "B"? 7:0][x]=figura+kolor_tury; ///TUTAJ
            }
        }
    }

    return 0;
}
