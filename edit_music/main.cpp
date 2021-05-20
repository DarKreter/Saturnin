#include "..\_Headers\funkcje.h"

int main()
{
    fstream plik;
    string linia, tytul, wykonawca, link, ocena;
    int nasz_kolor, kolor_saturnina;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    ///KOLORY
    plik.open(nazwa.c_str(),ios::out|ios::app);
    plik.close();
    plik.open(nazwa.c_str(),ios::in);
    if(plik.good()==false)
    {
        czy_wszystko_ok= false;
        sprawdzacz_bledow(0);
    }
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();

    ///WCZYTANIE UZYTKOWNIKA JAKIM JESTESMY
    nazwa= lokacja + "edit_music";
    plik.open(nazwa.c_str(),ios::in);
    getline(plik,linia);
    string uzytkownik = linia;
    if(uzytkownik == "")
    {
        saturnin_mowi(kolor_saturnina);
        cout << "WYSTAPIL KRYTYCZNY BLAD!";
        getch();
        exit(0);
    }
    plik.close();
    plik.open(nazwa.c_str(),ios::out);
    plik.close();

    ///---------------------------------------------------------------------------------------------------
    //uzytkownik = "Daniel";
    ///---------------------------------------------------------------------------------------------------
    string nazwa_pliku;
    bool czy_jest = false;
    for(;;)
    {
        czy_jest = false;
        system("cls");
        saturnin_mowi(kolor_saturnina);
        cout << "Tryb modyfikacji piosenek" << endl;
        cout << "Prosze podac tytul piosenki, bez wykonawcy(!): " ;
        saturnin_mowi(nasz_kolor);
        getline(cin,tytul);
        string tytul2 = modp(usp(tytul,1,0,0,0,"",""),1,1,0);
        if(tytul2 == "/wyjdz")
        {
            zegnaj(kolor_saturnina, tytul2);
            getch();
            return EXIT_SUCCESS;
        }
        saturnin_mowi(kolor_saturnina);
        cout << "Prosze podac wykonawce piosenki: " ;
        saturnin_mowi(nasz_kolor);
        getline(cin,wykonawca);
        string wykonawca2 = modp(usp(wykonawca,1,0,0,0,"",""),1,1,0);
        if(wykonawca2 == "/wyjdz")
        {
            zegnaj(kolor_saturnina, tytul);
            getch();
            return EXIT_SUCCESS;
        }
        nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
        plik.open(nazwa_pliku.c_str(),ios::in);
        int x = 0;
        int jest_juz = -1;
        while(getline(plik,linia))
        {
            if(x % 5 == 0)
            {
                //cout << "eloszka\n";
                jest_juz ++;
            }
            if(x % 5 == 0 && modp(usp(linia,1,0,0,0,"",""),1,1,0) == tytul2)
            {
                getline(plik,linia);
                if(modp(usp(linia,1,0,0,0,"",""),1,1,0) == wykonawca2)
                {
                    czy_jest = true;
                    break;
                }
            }
            x++;
        }
        plik.close();
        saturnin_mowi(kolor_saturnina);
        //cout << czy_jest << endl;
        if(czy_jest == true){   ///Aktualizacja piosenki
            vector <string> nazwy,wykonawcy,linki,oceny,liczby_ocen;
            nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
            plik.open(nazwa_pliku.c_str(),ios::in);
            int licznik = 0, liczmy = 0;
            while(getline(plik,linia)){ ///Wpisanie pliku  pod vectory
                    if(licznik % 5 == 0)
                    {
                        nazwy.push_back(linia);
                    }
                    else if(licznik % 5 == 1)
                    {
                        wykonawcy.push_back(linia);
                    }
                    else if(licznik % 5 == 2)
                    {
                        linki.push_back(linia);
                    }
                    else if(licznik % 5 == 3)
                    {
                        oceny.push_back(linia);
                    }
                    else if(licznik % 5 == 4)
                    {
                        liczby_ocen.push_back(linia);
                        liczmy ++ ;
                    }
                    licznik ++;
            }
            plik.close();
            bool oOo = false;

            cout << "Piosenka odnaleziona w bazie danych!\n"
                 << "Pracujesz na piosence: \nTytul: "
                 <<  nazwy[jest_juz] << endl
                 << "Wykonawca: " << wykonawcy[jest_juz] << endl
                 << "Link dostepu: " << linki[jest_juz] << endl
                 << "Ocena: " << oceny[jest_juz] << endl
                 << "Operacje dostepne na istniejacej piosence:\n"
                 << "1. Edytowanie tytulu\n"
                 << "2. Edytowanie wykonawcy\n"
                 << "3. Zmiana linku dostepu do piosenki\n"
                 << "4. Zaktualizowanie oceny\n"
                 << "5. Usuniecie piosenki z bazy danych\n"
                 << "6. Przerwanie akcji\n";
            powtorz:
            zmienmy_jeszcze_cos:
            saturnin_mowi(kolor_saturnina);
            cout << (oOo == true ?"Prosze podac poprawny wybor: " :"Wybierz jedna opcje z powyzej podanych: ") ;
                 //<<jest_juz<<endl<< nazwy[jest_juz]<<endl<<wykonawcy[jest_juz] <<endl<< linki[jest_juz] <<endl<< oceny[jest_juz]<<endl<<liczby_ocen[jest_juz];
            saturnin_mowi(nasz_kolor);
            getline(cin,linia);
            if(linia != "1" && linia != "2" &&linia != "3" &&linia != "4" &&linia != "5" &&linia != "6")
            {
                oOo = true;
                goto powtorz;
            }
            int pomoc = string_na_int(linia);
            saturnin_mowi(kolor_saturnina);
            float x,y,z;
            bool jakies_cos = false;
            string h;
            switch(pomoc)
            {
            case 1:
                cout << "Podaj tytul na jaki mam zmienic aktualny tytul: ";
                saturnin_mowi(nasz_kolor);
                getline(cin,tytul2);
                if(modp(usp(tytul2,1,0,0,0,"",""),1,1,0) == "/stop")     continue;
                nazwy[jest_juz] = tytul2;
                //cout << nazwy[jest_juz] << endl;
                nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
                plik.open(nazwa_pliku.c_str(),ios::out);
                //cout << nazwy.size();
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
                plik << "\n";
                plik.close();
                saturnin_mowi(kolor_saturnina);
                cout << "Zmiana tytulu przebiegla pomyslnie!\n";
                oOo = false;
                goto zmienmy_jeszcze_cos;
                break;
            case 2:
                cout << "Podaj wykonawce na jaki mam zmienic aktualnego: ";
                saturnin_mowi(nasz_kolor);
                getline(cin,tytul2);
                if(modp(usp(tytul2,1,0,0,0,"",""),1,1,0) == "/stop")     continue;
                wykonawcy[jest_juz] = tytul2;
                //cout << nazwy[jest_juz] << endl;
                nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
                plik.open(nazwa_pliku.c_str(),ios::out);
                //cout << nazwy.size();
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
                plik << "\n";
                plik.close();
                saturnin_mowi(kolor_saturnina);
                cout << "Zmiana wykonawcy przebiegla pomyslnie!\n";
                oOo = false;
                goto zmienmy_jeszcze_cos;
                break;
            case 3:
                cout << "Podaj nowy aktualny link: ";
                saturnin_mowi(nasz_kolor);
                getline(cin,tytul2);
                if(modp(usp(tytul2,1,0,0,0,"",""),1,1,0) == "/stop")     continue;
                linki[jest_juz] = tytul2;
                //cout << nazwy[jest_juz] << endl;
                nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
                plik.open(nazwa_pliku.c_str(),ios::out);
                //cout << nazwy.size();
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
                plik << "\n";
                plik.close();
                saturnin_mowi(kolor_saturnina);
                cout << "Zmiana linku przebiegla pomyslnie!\n";
                oOo = false;
                goto zmienmy_jeszcze_cos;
                break;
            case 4:
                powrocik:
                    saturnin_mowi(kolor_saturnina);
                cout << (jakies_cos == true ? "Prosze podac prawidlowa ocene: ":"Jak teraz oceniasz te piosenke: ");

                saturnin_mowi(nasz_kolor);
                getline(cin,tytul2);
                if(modp(usp(tytul2,1,0,0,0,"",""),1,1,0) == "/stop")     continue;
                if(czy_to_liczba(tytul2) == false || tytul2 == "0" )
                {
                    if(tytul2 == "10")
                    {
                        ;
                    }
                    else{ jakies_cos = true; goto powrocik;
                    }

                }
                x = string_na_int(tytul2); y = string_na_int(oceny[jest_juz]); z = string_na_int(liczby_ocen[jest_juz]);
                //cout << x <<endl << y <<endl << z<< endl ;
                liczby_ocen[jest_juz] = int_na_string(z + 1);
                oceny[jest_juz] = int_na_string((x + y) / (z + 1));
                h = oceny[jest_juz];
                if(h.length() > 4) h.erase(4,h.length() - 4);
                oceny[jest_juz] = h;
                //cout << nazwy[jest_juz] << endl;
                nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
                plik.open(nazwa_pliku.c_str(),ios::out);
                //cout << nazwy.size();
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
                plik << "\n";
                plik.close();
                saturnin_mowi(kolor_saturnina);
                cout << "Ocena zaktualizowana pomyslnie!\n";
                oOo = false;
                goto zmienmy_jeszcze_cos;
                break;

            case 5:

                cout << "Czy na pewno chcesz usuniac piosenke z bazy danych ? (zeby potwierdzic prosze wpisac \"tak\")\n";
                saturnin_mowi(nasz_kolor);
                getline(cin,tytul2);
                if(modp(usp(tytul2,1,0,0,0,"",""),1,1,0) == "/stop")     continue;
                if ( modp(usp(tytul2,1,0,0,0,"",""),1,1,0) != "tak")
                {
                    saturnin_mowi(kolor_saturnina);
                    cout << "Przerwanie operacji";
                    kropki(700);
                    continue;
                }
                //cout << nazwy[jest_juz] << endl;
                nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
                plik.open(nazwa_pliku.c_str(),ios::out);
                //cout << nazwy.size();
                for(unsigned long long i = 0; i < nazwy.size() ; i++)
                {
                    if(i == jest_juz) continue;
                    //cout << i << endl;
                    plik <<(i==0 ? "" : "\n");
                    plik << nazwy[i] << endl
                         << wykonawcy[i] << endl
                         << linki[i]<<endl
                         << oceny[i]<<endl
                         << liczby_ocen[i];

                }
                plik << "\n";
                plik.close();
                saturnin_mowi(kolor_saturnina);
                cout << "Piosenka usunieta pomyslnie!\n";
                break;
            case 6:
                cout << "Przerywanie akcji";
                kropki(700);
                continue;
                break;
            default:
                cout << "BLAD KRYTYCZNY!\n";
                getch();
                return EXIT_FAILURE;
            }
            getch();
        }
        else {       ///DODANIE PIOSENKI

            cout << "Nie mam piosenki w bazie danych!\n"
                 << "Rozpoczynam operacje wprowadzania piosenki do bazy danych\n"
                 << "W przypadku zmiany zdania wystarczy uzyc komendy \"/stop\" \n"
                 << "Prosze podac link lub sciezke do pliku: ";
            saturnin_mowi(nasz_kolor);
            getline(cin,linia); ///linku
            linia = usp(linia,1,0,0,0,"","");
            if(linia == "/stop") continue;
            link = linia;
            bool powtorz = false;
            powtorka:  ///Powtarzamy az gosc poda dobra ocene w skali
            saturnin_mowi(kolor_saturnina);
            cout << (powtorz == true? "Przypominam o obowiazujacej skali 1 - 10, prosze podac wlasciwa ocene: " :"Jak oceniasz ta piosenke, uzywana skala 1 - 10: ");
            saturnin_mowi(nasz_kolor);
            getline(cin,linia);
            usp(linia,1,0,0,0,"","");
            if(linia == "/stop") continue;
            if(czy_to_liczba(linia) == false || linia.length() > 1 || linia == "0") ///Bledna ocena
            {
                if(linia == "10")
                {
                    ;
                }
                else
                {
                    powtorz = true;
                    goto powtorka;
                }

            }
            ocena = linia;
            nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
            plik.open(nazwa_pliku.c_str(),ios::out|ios::app);
            plik << tytul << endl << wykonawca << endl << link << endl <<ocena << endl << 1 << endl;   ///Wpisanie wszystkiego na sam koniec, gdyby ktos sie rozmyslil i wylaczylsaturnina
            plik.close();
            saturnin_mowi(kolor_saturnina);
            cout << "Baza danych zaktualizowana, piosenka dostepna!\n";
            getch();
        }
    }
    getch();
    return 0;
}
