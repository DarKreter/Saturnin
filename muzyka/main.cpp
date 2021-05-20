#include "../_Headers/funkcje.h"

int main(int argc, char*argv[])
{
    fstream plik;
    string linia;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    int nasz_kolor, kolor_saturnina;
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
    string uzytkownik;
    if(argc == 2)
    {
        argv++;
        //cout << *argv << endl;
         uzytkownik = *argv;
    }
    else  uzytkownik = "Gosc";


    string odp; int wybor; bool bledna_proba = false;
    for(;;)
    {
        czy_wszystko_ok = true;
        saturnin_mowi(kolor_saturnina);
        ustaw_wskaznik(4,1);
        cout << (uzytkownik == "Gosc" ? "Niezarejestrowany uzytkownik, blad...":"Baza danych dla uzytkownika: " )
             << (uzytkownik == "Gosc" ? "" : uzytkownik)
             << endl
             << (uzytkownik == "Gosc"?"1. KOMENDA ZABLOKOWANA DLA PUBLICZNEJ PLAYLISTY  \n":"1. Startuj playliste  \n")
             << (uzytkownik == "Gosc"?"2. KOMENDA ZABLOKOWANA DLA PUBLICZNEJ PLAYLISTY  \n":"2. Dodaj lub modyfikuj piosenki z playlisty  \n")
             << (uzytkownik == "Gosc"?"3. KOMENDA ZABLOKOWANA DLA PUBLICZNEJ PLAYLISTY  \n":"3. Wyswietl ranking piosenek  \n")
             << (bledna_proba == true ?"Podaj poprawny numer dzialania ktore chcesz wykonac: ":"Podaj numer dzialania ktore chcesz wykonac: ");
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        if(modp(odp,1,1,0) == "/wyjdz")
        {
            zegnaj(kolor_saturnina,odp);
            getch();
            return EXIT_SUCCESS;
        }
        wybor = string_na_int(odp);
        saturnin_mowi(kolor_saturnina);
        switch(wybor)
        {
        case 1:
            if(uzytkownik == "Gosc")
            {
                cout << "NIEAUTORYZOWANE \275ADANIE, PRZEKIEROWANIE DO MENU";
                kropki(700);
            }
            else{
            bledna_proba = false;
            cout << "Wprowadzono prosbe uruchomienia Saturnin.mp3";
            for(int i = 3; i>0;i--)
                        {
                            cout << " ";
                            Sleep(500);
                            cout << "\16";
                            Sleep(500);
                        }
            nazwa = lokacja + "playlist";
            plik.open(nazwa.c_str(),ios::out);
            plik << uzytkownik;
            plik.close();
            system("start ../playlist/playlist.exe");
            }
            break;
        case 2:
            if(uzytkownik == "Gosc")
            {
                cout << "NIEAUTORYZOWANE \275ADANIE, PRZEKIEROWANIE DO MENU";
                kropki(700);
            }
            else{
            bledna_proba = false;
            cout << "Otwieram centrum modyfikacji piosenek";
            for(int i = 3; i>0;i--)
                        {
                            cout << " ";
                            Sleep(500);
                            cout << "\16";
                            Sleep(500);
                        }
            nazwa = lokacja + "edit_music";
            plik.open(nazwa.c_str(),ios::out);
            plik << uzytkownik;
            plik.close();
            system("start ../edit_music/edit_music.exe");
            }

            break;
        case 3:
            if(uzytkownik == "Gosc")
            {
                cout << "NIEAUTORYZOWANE \275ADANIE, PRZEKIEROWANIE DO MENU";
                kropki(700);
            }
            else{
            bledna_proba = false;
            cout << "Wyswietlam ranking";
            for(int i = 3; i>0;i--)
                        {
                            cout << " ";
                            Sleep(500);
                            cout << "\16";
                            Sleep(500);
                        }
            nazwa = lokacja + "ranking";
            plik.open(nazwa.c_str(),ios::out);
            plik << uzytkownik;
            plik.close();
            system("start ../ranking/ranking.exe");}
            break;
        default:
            bledna_proba = true;
        }
        system("cls");
    }
    getch();
    return 0;
}
