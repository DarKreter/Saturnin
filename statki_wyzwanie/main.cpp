#include "..\_Headers\funkcje.h"

int main(int argc, char*argv[])
{
    int kolor_saturnina, nasz_kolor;
    fstream plik,file;
    string lokacja,linia,uzytkownik;
    plik.open("../Pliki/lokalizacja",ios::in);
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    ///WCZYTUJEMY KOLORY
    string x;
    x = lokacja + "kolory";
    plik.open(x.c_str(),ios::in);
    plik >> kolor_saturnina >>  nasz_kolor;
    plik.close();
    saturnin_mowi(kolor_saturnina);

    string UMIERAM = lokacja + "statki_wyzwanie";
    file.open(UMIERAM.c_str(), ios::in);
    file >> linia;
    file.close();

    string help = lokacja + "statki_who_wyzwanie";
    plik.open(help.c_str(),ios::in);
    plik >> uzytkownik;
    plik.close();

    bool przyjal = false, wskaznik = 0;
    while(true)
    {
        system("cls");
        saturnin_mowi(kolor_saturnina);
        cout<< "Zostales wyzwany w statki przez uzytkownika " << linia<<"!\n"
        << "Przyjmuejsze wyzwanie ?\n";
        if(wskaznik == 0)
        {
            saturnin_mowi(nasz_kolor);
            cout << "-TAK\t";
            saturnin_mowi(kolor_saturnina);
            cout << " NIE\t";
        }
        if(wskaznik == 1)
        {
            saturnin_mowi(kolor_saturnina);
            cout << " TAK\t";
            saturnin_mowi(nasz_kolor);
            cout << "-NIE\t";
        }
        char czar = getch();
        if(czar == 224 || czar == 0) czar = getch();
        switch(czar)
        {
        case 97: case 65: case 75:
            if(wskaznik) wskaznik=0;
            break;
        case 100: case 68: case 77:
            if(!wskaznik) wskaznik =1;
            break;
        case 13:
            przyjal = wskaznik == 0 ? true : false;
            goto koniec;
            break;
        }
    }

    ///WCZYTAC LINIE I PRZECIWNIKA

    koniec:
    if(przyjal)
    {

        string UMIERAM = lokacja + "statki_wyzwanie";
        file.open(UMIERAM.c_str(), ios::out);
        file.close();

        string help = lokacja + "statki_who_wyzwanie";
        plik.open(help.c_str(),ios::out);
        plik.close();

        UMIERAM = lokacja + "statki_przeciwnik";
        file.open(UMIERAM.c_str(), ios::out);
        file << linia;
        file.close();

        UMIERAM = lokacja + "statki_who";
        plik.open(UMIERAM.c_str(),ios::out);
        plik << uzytkownik;
        plik.close();

        system("start ../Statki/Statki.exe");
        return 0;
    }
    else
    {
        string UMIERAM = lokacja + "statki_wyzwanie";
        file.open(UMIERAM.c_str(), ios::out);
        file.close();

        string help = lokacja + "statki_who_wyzwanie";
        plik.open(help.c_str(),ios::out);
        plik.close();

        string folderyANDpliki = "../Statki/files/Przyjecia/" + uzytkownik;
        plik.open(folderyANDpliki.c_str(),ios::out);
        plik << "NIE";
        plik.close();
        return 0;
    }
}
