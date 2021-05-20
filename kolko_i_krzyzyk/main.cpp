#include "..\_Headers\funkcje.h"
#include "Funkcje_ttt.h"


int main(int argc, char*argv[]){
    string tactic = "../ttt/rozgrywka" ;
    CreateDirectory(TEXT(tactic.c_str()), NULL);
    srand(time(NULL));
    bool wyzywajacy;
    fstream plik; vector <string> inni_uzytkownicy;
    string przeciwnik ;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    int czas;
    ///KOLORY
    plik.open(nazwa.c_str() ,ios::out|ios::app);
    plik.close();
    plik.open(nazwa.c_str(),ios::in);
    if(plik.good()==false)
    {
        czy_wszystko_ok= false;
        sprawdzacz_bledow(0);
    }
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();

    string miejsca[10];
    saturnin_mowi(kolor_saturnina);
    string tak_o;
    string linia;
    ///WCZYTANIE UZYTKOWNIKA JAKIM JESTESMY
        string uzytkownik ="";
    if(argc > 1)
    {
        argv ++;
        uzytkownik = *argv;
    }

    if(uzytkownik == "") uzytkownik = "Gosc";
    ///WPISANIE NASZEGO KOLORU
    tak_o = "../ttt/kolor_"+uzytkownik;
    plik.open(tak_o.c_str(),ios::out);
    plik << nasz_kolor;
    plik.close();

    ///NAZWY UZYTKOWNIKOW DO VECTORA
    int k =0;
    plik.open("../Pliki/logowanie",ios::in);
    while(getline(plik, tak_o))  ///Bierzemy nazwy uzytkownikow i wsadzamy je do vectora
    {
        if(k%2 == 0&&tak_o != uzytkownik)    {inni_uzytkownicy.push_back(tak_o); } ///Co dwa sa nazwy
        k++;
    }
    plik.close();

    nazwa = lokacja + "tttwyzwanie";
    plik.open(nazwa.c_str(),ios::in);
    getline(plik,tak_o);
    plik.close();

    ///CZYSCIMY
    plik.open("../tt/rozgrywka/hej",ios::out);
    plik.close();
    plik.open("../tt/rozgrywka/gramy",ios::out);
    plik.close();
    string x = "../ttt/gram_"+uzytkownik;
    plik.open(x.c_str(),ios::out);
    plik.close();

    if(tak_o == ""){        ///WYZYWAMY GRACZA
        wyzywajacy = true;
        bool wyzwal = true; int x = 0;
        while(wyzwal) ///Powtarza sie dopoki nie poda prawidlowego uzytkownika
        {
            saturnin_mowi(kolor_saturnina);
            if(x > 0)
            {
                cout << "Nie ma uzytkownika o takiej nazwie!\n" ;
            }
            cout << "Podaj nazwe uzytkownika jakiego chcesz wyzwac: ";
            saturnin_mowi(nasz_kolor);
            getline(cin,tak_o);
            for(int i = 0;i < inni_uzytkownicy.size();i++)
            {
                if(inni_uzytkownicy[i] == tak_o)
                {
                    wyzwal = false;
                }
            }
            x++;
        }
        przeciwnik = tak_o;
        string nazwa_pliku = "../ttt/"+przeciwnik;
        plik.open(nazwa_pliku.c_str(), ios::out);
        plik << "Wyzywam";
        plik.close();
        saturnin_mowi(kolor_saturnina);
        cout << "Oczekiwanie na przeciwnika";
        while(true)
        {
            nazwa_pliku = "../ttt/przyjete_" + przeciwnik;
            plik.open(nazwa_pliku.c_str(), ios :: in);
            getline(plik,tak_o);
            plik.close();
            if(tak_o == "przyjalem")
            {
                system("cls");
                plik.open(nazwa_pliku.c_str(), ios :: out);
                plik.close();
                break;
            }
            kropki(700);
            Sleep(700);
            cout << "\b\b\b   \b\b\b";
        }
    }
    else{                   ///ZOSTALISMY WCZESNIEJ WYZWANI
        wyzywajacy = false;
        przeciwnik = tak_o;
        nazwa = lokacja + "tttwyzwanie";
        plik.open(nazwa.c_str(),ios::out);
        plik.close();
        saturnin_mowi(kolor_saturnina);
        string nazwa_pliku = "../ttt/przyjete_" + uzytkownik;
        plik.open(nazwa_pliku.c_str(),ios::out);
        plik << "przyjalem" ;
        plik.close();
        cout << "Prosze czekac!";
    }

    string znak;

    if(wyzywajacy == true){  ///USTALENIE KOLKA I KRZYZ I WYSLANIE DO PLIKU

        string nazwa = "../ttt/kolor_" + przeciwnik;
        plik.open(nazwa.c_str(),ios::in);
        plik >> kolor_przeciwnika;
        plik.close();

        int los;
        los = rand() % 2;
        ///Ustalanie czy jestes kolko czy krzyz
        if(los == 0)
        {
            znak = "kolko";
            string nazwa_pliku = "../ttt/gram_" + przeciwnik;
            plik.open(nazwa_pliku.c_str(), ios::out);
            plik << "krzyz" << endl << uzytkownik;
            plik.close();
        }
        else
        {
            znak = "krzyz";
            string nazwa_pliku = "../ttt/gram_" + przeciwnik;
            plik.open(nazwa_pliku.c_str(), ios::out);
            plik << "kolko" << endl << uzytkownik;
            plik.close();
        }
    }
    else{  ///ODCZYTANIE CZY JESTESMY KOLKIEM CZY KRZYZEM

        while(true)   ///Ustalenie czy jestes kolkiem czy krzyzem
        {
            string nazwa_pliku = "../ttt/gram_" + uzytkownik;
            plik.open(nazwa_pliku.c_str(), ios::in);
            getline(plik,tak_o);
            if(tak_o == "krzyz")
            {
                znak = "krzyz";
                getline(plik,tak_o);
                plik.close();
                nazwa_pliku = "../ttt/kolor_" + tak_o;
                plik.open(tak_o.c_str(),ios::in);
                plik >> kolor_przeciwnika;
                plik.close();
                break;
            }
            else if(tak_o == "kolko")
            {
                znak = "kolko";
                getline(plik,tak_o);
                plik.close();
                nazwa_pliku = "../ttt/kolor_" + tak_o;
                plik.open(nazwa_pliku.c_str(),ios::in);
                plik >> kolor_przeciwnika;
                plik.close();
                plik.close();
                break;
            }
            plik.close();
        }
        string nazwa_pliku = "../ttt/gram_" + uzytkownik;
        plik.open(nazwa_pliku.c_str(), ios::out);
        plik.close();
    }

    system("cls");
    //ustaw_wskaznik(1,40);saturnin_mowi(kolor_saturnina); cout << "Kolor przeciwnika to "; saturnin_mowi(kolor_przeciwnika); cout << kolor_przeciwnika;
    rysowanie_tablicy(miejsca);
    if(wyzywajacy == true){                                                  ///WYZYWAJACY
        int kolor_wroga;
        rysowanie_tablicy(miejsca);
        for(int i = 0;i < 9;i++)
        {
            if(i % 2 == 0){ ///Ty wpisujesz numerek

                ustaw_wskaznik(1,31);
                saturnin_mowi(kolor_saturnina);
                cout << "Podaj numer pola na ktorym chcesz postawic "<<znak<<":";
                wracaj:
                    czy_wszystko_ok = true;
                saturnin_mowi(nasz_kolor);
                getline(cin,linia);
                linia = usp(linia);
                int kupa = string_na_int(linia);
                if (linia.length() > 1 || kupa == 112 || czy_to_liczba(linia) == false|| linia == "0" || miejsca[kupa] == "kolko" || miejsca[kupa] == "krzyz")
                {
                    saturnin_mowi(kolor_saturnina);
                    cout << "Bledne pole!\nPodaj numer pola na ktorym chcesz postawic "<<znak<<":";
                    goto wracaj;
                }


                int num = string_na_int(linia);
                ustaw_wskaznik(1,40); cout << num ;
                string nazwa_pliku = "../ttt/rozgrywka/gramy";
                plik.open(nazwa_pliku.c_str(), ios::out);
                plik << num;
                plik.close();
                saturnin_mowi(nasz_kolor);
                rysuj_ksztalt(num, znak ,miejsca);
                int x = sprawdzanie_wygranej(miejsca);
                saturnin_mowi(15);
                rysowanie_wygranej(x,true);
            }
            else{  ///Czytasz
                ustaw_wskaznik(1,31);
                saturnin_mowi(kolor_saturnina);
                cout << "Oczekiwanie na ruch przeciwnika";
                while(true)
                {
                    kropki(400);
                    cout << "\b\b\b   \b\b\b";
                    plik.open("../ttt/rozgrywka/hej", ios::in);
                    string linia;
                    getline(plik,linia);
                    if(czy_to_liczba(linia) == true)
                    {
                        saturnin_mowi(nasz_kolor);
                        if(znak == "kolko")
                        {
                            saturnin_mowi(kolor_przeciwnika);
                            rysuj_ksztalt(string_na_int(linia),"krzyz",miejsca);
                            int x = sprawdzanie_wygranej(miejsca);
                            saturnin_mowi(15);
                            rysowanie_wygranej(x,false);
                            plik.close();
                            break;
                        }
                        else if(znak == "krzyz")
                        {
                            saturnin_mowi(kolor_przeciwnika);
                            rysuj_ksztalt(string_na_int(linia),"kolko",miejsca);
                            int x = sprawdzanie_wygranej(miejsca);
                            saturnin_mowi(15);
                            rysowanie_wygranej(x,false);
                            plik.close();
                            break;
                        }
                    }
                    plik.close();
                }
            }
        czyszczenie_ttt();
        plik.open("../ttt/rozgrywka/hej", ios::out);
        plik.close();
        }
    }
    else{                                                  ///PRZYJMUJACY

        rysowanie_tablicy(miejsca);
        for(int i = 0;i < 9;i++)
        {
            if(i % 2 == 0) ///Czytasz
            {
                ustaw_wskaznik(1,31);
                saturnin_mowi(kolor_saturnina);
                cout << "Oczekiwanie na ruch przeciwnika";
                while(true)
                {
                    kropki(400);
                    cout << "\b\b\b   \b\b\b";
                    plik.open("../ttt/rozgrywka/gramy", ios::in);
                    string linia;
                    getline(plik,linia);
                    if(czy_to_liczba(linia) == true)
                    {
                        if(znak == "kolko")
                        {
                            saturnin_mowi(kolor_przeciwnika);
                            rysuj_ksztalt(string_na_int(linia),"krzyz",miejsca);
                            int x = sprawdzanie_wygranej(miejsca);
                            saturnin_mowi(15);
                            rysowanie_wygranej(x,false);
                            plik.close();
                            break;
                        }
                        else if(znak == "krzyz")
                        {
                            saturnin_mowi(kolor_przeciwnika);
                            rysuj_ksztalt(string_na_int(linia),"kolko",miejsca);
                            int x = sprawdzanie_wygranej(miejsca);
                            saturnin_mowi(15);
                            rysowanie_wygranej(x,false);
                            plik.close();
                            break;
                        }
                    }
                    plik.close();

                }
                plik.open("../ttt/rozgrywka/gramy", ios::out);
                plik.close();
            }
            else  ///Ty wpisujesz numerek
            {
                ustaw_wskaznik(1,31);
                saturnin_mowi(kolor_saturnina);
                cout << "Podaj numer pola na ktorym chcesz postawic "<<znak<<":";
                powrot:
                    czy_wszystko_ok = true;
                saturnin_mowi(nasz_kolor);
                getline(cin,linia);
                linia = usp(linia);
                int kupa = string_na_int(linia);
                if (linia.length() > 1 || kupa == 112 || czy_to_liczba(linia) == false|| linia == "0" || miejsca[kupa] == "kolko" || miejsca[kupa] == "krzyz")
                {
                    saturnin_mowi(kolor_saturnina);
                    cout << "Bledne pole!\nPodaj numer pola na ktorym chcesz postawic "<<znak<<":";
                    goto powrot;
                }

                int num = string_na_int(linia);
                ustaw_wskaznik(1,40); cout << num ;
                fstream plikv2;
                plikv2.open("../ttt/rozgrywka/hej", ios::out);
                plikv2 << num;
                plikv2.close();
                saturnin_mowi(nasz_kolor);
                rysuj_ksztalt(num, znak ,miejsca);
                int x = sprawdzanie_wygranej(miejsca);
                saturnin_mowi(15);
                rysowanie_wygranej(x,true);
            }
        czyszczenie_ttt();
        }
    }

    ustaw_wskaznik(1,31);
    for(int i = 0;i < 40 ; i++)
    {
        cout << " ";
    }
    ustaw_wskaznik(30,31);
    saturnin_mowi(15);
    cout << "KONIEC RUCHOW!\n";
    system("pause");
    return 0;
}
