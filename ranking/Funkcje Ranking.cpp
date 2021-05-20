#include "../_Headers/funkcje.h"
#include "Funkcje_ranking.h"

void sortowanie_vectorow(float *tablica,int lewy,int prawy){
    //cout << "Leci funckja\n";
    float v=tablica[(lewy+prawy)/2];
    int i,j;
    float xxxx;
    string napis;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            napis = nazwy[i]; nazwy[i] = nazwy[j]; nazwy[j] = napis;
            napis = wykonawcy[i];  wykonawcy[i] =  wykonawcy[j];  wykonawcy[j] = napis;
            napis = linki[i]; linki[i] = linki[j]; linki[j] = napis;
            napis = oceny[i]; oceny[i] = oceny[j]; oceny[j] = napis;
            napis = liczby_ocen[i]; liczby_ocen[i] = liczby_ocen[j]; liczby_ocen[j] = napis;
            xxxx=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=xxxx;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy)  sortowanie_vectorow(tablica,lewy, j);
    if(i<prawy) sortowanie_vectorow(tablica, i, prawy);
}

void sortowanie_pliku(string uzytkownik){
    fstream plik;
    string nazwa = "../muzyka/" + uzytkownik + "_playlist";
    ///SORTOWANIE
    float *tablica;
    //cout << "zyjesz?\n";
    getch();
    tablica = new float [nazwy.size()];
    //cout << nazwy.size();
    getch();
    for(unsigned long long i = 0; i < nazwy.size() ; i++)
    {
        tablica[i] = string_na_int(oceny[i]);
    }
    //cout << "zyjesz?\n";
    sortowanie_vectorow(tablica,0,nazwy.size()-1);
    //cout << "tak\n";
    delete []tablica;
    reverse(nazwy.begin(),nazwy.end());
    reverse(wykonawcy.begin(),wykonawcy.end());
    reverse(linki.begin(),linki.end());
    reverse(oceny.begin(),oceny.end());
    reverse(liczby_ocen.begin(),liczby_ocen.end());
    ///NADPISANIE PLIKU
    plik.open(nazwa.c_str(),ios::out);
    for(unsigned long long i = 0; i < nazwy.size() ; i++)
    {
        //cout << i << endl;
        plik <<(i==0 ? "" : "\n");
        plik << nazwy[i] << endl
             << wykonawcy[i] << endl
             << linki[i]<<endl
             << oceny[i]<<endl
             << liczby_ocen[i];

    }
    plik << endl;
    plik.close();
    delete tablica;
}
