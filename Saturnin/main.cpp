#include "..\_Headers\funkcje.h"
#include "Wywolania.h"


int main(int argc, char*argv[]){
    /*TWORZENIE FOLDEROW I PLIKOW*/
    tworzymy_pliki();
    fstream plik;
    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja += "Saturnin/";

    /*DEFINIOWANIA ZMIENNYCH*/
    srand(time(NULL));
    string uzytkownik="Gosc"; bool login = false;
    long double wynik,wynik2; string wynik_string;
    string odp,odp2,nwm, liczba_pierwsza, dzielenie1, dzielenie2, reszta1, zapisz, dopisz;
    string twoj_kolor, moj_kolorek ;
    int licznik, czas,  nr_linii = 0;
    string dzialanie , jeden, dwa;
    string linia; fstream slowa_klucz;
    string czyszczenie = "";

    /*TABLICA WSKAZNIKOW NA FUNKCJE*/
    linia = "../Pliki/slowa_klucz";
    plik.open(linia.c_str(),ios::in);                       ///otwieramy plik slowa_klucz
    int *wsk = new int;     *wsk = 1;                       ///Alokujemy miejsce dla nwoego wskaznika i nadajemy mu wartosc poczatkowa 1
    while(getline(plik,linia))  *wsk+=1;                    ///Sprawdzamy dlugosc pliku tesktowego z komendami
    plik.close();
    void (*TABLICA_WSKAZNIKOW[*wsk])(string**);             ///TWORZYMY TABLICE WSKAZNIKOW NA FUNKCJE O WIELKOSCI TAKA JAKA MA DLUGOSC PLIK Z KOMENDAMI CZYLI ICH ILOSC
    ustawianie_tablicy_wskaznikow(TABLICA_WSKAZNIKOW, wsk); ///Ustawiamy wskazniki na odpowiednie funkcje
    delete wsk; wsk = null;                                 ///Usuwamy juz niepotrzebny wskaznik


    /*OTWIERANIE PLIKÓW*/

        ///problem z zmien twoj kolor
    czyszczenie = lokacja + "kolory";
    plik.open(czyszczenie.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(czyszczenie.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();
    czyszczenie = "";


//    POINT P;
//    cout << GetCursorPos()<<endl;
//    P.x;
//    P.y;
//    cout<<P.x<<endl<<P.y;
    ///Moze sie kiedys przydac znajdujemy pozycje kursora myszy

    czyszczenie_ekranu:
    int x = 3; ///x rowne 3 bo 2 3 linii bedziemy pisac nastepne rzeczy
    ustaw_wskaznik(1,2); ///Na drugiej linii sie to wypisuje
    saturnin_mowi(kolor_saturnina);
    cout <<"Saturnin ver 0.48 klania sie do uslug"<< endl;
    ///ZA PIERWSZYM RAZEM MUSIMY TO TU WYPISAC
    ustaw_wskaznik(1,1); ///Ustawiamy kursor na najwyzsza linie
    string help = sprawdzanie_daty();
    cout << help;
    help = sprawdzanie_czasu(0); ///Strefa czasowa
    help = help.substr(0,5);
    cout << "     " << help << endl;
    ustaw_wskaznik(1,x);
    clock_t start, stop;
    double mierzenie_czau;
    start = clock();

    for(int i=1;;i++){

    {               /*SPRAWDZANIE CZY KTOS NAS NIE WYZWAL W KOLKO I KRZYZYK*/
        string nazwa_pliku = "../ttt/" + uzytkownik, linia;
        fstream pliczek;
        pliczek.open(nazwa_pliku.c_str(),ios::in);
        getline(pliczek,linia);
        pliczek.close();
        if(linia == "Wyzywam")
        {
            pliczek.open(nazwa_pliku.c_str(),ios::out);
            pliczek.close();
            nazwa_pliku = lokacja + "tttwyzwanie";
            pliczek.open(nazwa_pliku.c_str(), ios::out);
            pliczek << "cokolwiek";
            pliczek.close();
            system("start ../Wyzwanie/Wyzwanie.exe");
        }
    }

    {           /*SPRAWDZENIE CZY KTOS NIE WYZWAL W STATKI*/
        string name = "../Statki/files/Wyzwania/"+uzytkownik;
        fstream file;
        file.open(name.c_str(),ios::out | ios::app);
        file.close();
        file.open(name.c_str(),ios::in);
        getline(file,linia);
        file.close();
        if(linia != "")
        {
            ///Wyslanie kto nas wyzwal
            string UMIERAM = lokacja + "statki_wyzwanie";
            file.open(name.c_str(),ios::out);
            file.close();
            file.open(UMIERAM.c_str(), ios::out);
            file << linia;
            file.close();
            ///Wyslanie kim jestesmy
            UMIERAM = lokacja + "statki_who_wyzwanie";
            file.open(name.c_str(),ios::out);
            file.close();
            file.open(UMIERAM.c_str(), ios::out);
            file << uzytkownik;
            file.close();

            system("start ../statki_wyzwanie/statki_wyzwanie.exe");

        }
    }

    {               ///WYPISANIE DATY I GODZINE NA GORZE EKRANU
    stop = clock();
    mierzenie_czau = (double) (stop - start) / CLOCKS_PER_SEC ;
    if(mierzenie_czau > 1)  ///co 5 sekund uaktualniamy
    {
        ustaw_wskaznik(1,1); ///Ustawiamy kursor na najwyzsza linie
        string help = sprawdzanie_daty();
        cout << help;
        help = sprawdzanie_czasu(0); ///Strefa czasowa
        help = "     " + help.substr(0,5);
        cout <<  help << endl;
        ustaw_wskaznik(1,x);
        start = clock();
    }
    }

    {               /*SPRAWDZANIE CZY NIE POTRZEBA CZEGOS WYPISAC*/
    if(czyszczenie != "")
    {
        cout << czyszczenie << endl;
        czyszczenie = "";
        x++;
    }
    }
    if(kbhit()==true){                      ///JESLI KTOS COS KLIKNAL CZYLI WCZYTUJEMY KOMENDE
            ///ZABEZPIECZENIA
        wynik = 0;
        czy_wszystko_ok = true;
        nr_linii = 0;
        lista_globalna.clear();
            /// WCZYTYWANIE ODPOWIEDZI
       saturnin_mowi(nasz_kolor); /// Alex jesiedebilem tu starcza jedna funkcja pacz ;-;
        getline(cin, odp);
        saturnin_mowi(kolor_saturnina);
            /// MODYFIKACJA ODPOWIEDZI
        odp = modp(usp(odp,1,0,0,0,"","","","",1));
        //cout << odp<<endl;
        slowa_klucz.open("../Pliki/slowa_klucz",ios::out|ios::app);
        slowa_klucz.close();
        slowa_klucz.open("../Pliki/slowa_klucz",ios::in);
        if( slowa_klucz.good()==false){
            czy_wszystko_ok=false;
            sprawdzacz_bledow(10);
    }
    if(odp.length() == 0) goto podana_pustka; ///GDY KTOS NIE PODA NIC -> ZOSTAWI SPACJE, bo nie chcemy wtedy "nie ma takiej komendy"
                                            ///Wczytywanie komendy
        while(getline(slowa_klucz,linia)){
            nr_linii++;
            if(odp.substr(0,linia.length())==linia){
                odp2 = odp.substr(0,linia.length());    ///odp2 do zegnaj
                //cout<<odp<<endl;
                odp.erase(0,linia.length());            ///Usuwa poczatek
                //cout<< odp<<endl;
                //cout<<nr_linii;

                break;
            }
        }
        slowa_klucz.close();
                        /**WYWOLYWANIE KOMEND*/
                podana_pustka:
                cout<<setprecision(1000);

                string *h[5]; ///Tworzymy tablice wskaznikow
                h[0] = &lokacja;
                h[1] = &odp;
                h[2] = &odp2;
                h[3] = &czyszczenie;
                h[4] = &uzytkownik;
                /**
                    h[0] => przechowuje lokalizacje na dysku C folderu Saturnin
                    h[1] => Przechowuje odpowiedz a wlasciwie to co z niej zostalo
                    h[2] => Zmieniona odpowiedz na potrzeby pozegnania
                    h[3] => To co ma sie wysiwetlic na ekranie po wyczyszczeniu
                    h[4] => Przechowuje uzytkownika
                */
                if(TABLICA_WSKAZNIKOW[nr_linii])  (*TABLICA_WSKAZNIKOW[nr_linii])(h) ;
                ///Jesli wskaznik na cos wskazuje wywolujemy ta funkcje
                system("cls");
                goto czyszczenie_ekranu;

    }

    }
    }

    /// W TRAKCIE...
/// SZACHY

    ///NASZE POMYSLY DO ZREALIZOWANIA
///HANDLE CIEKAWE CO TO ZA SHIT
///POMARANCZOWY NIE ISTNIEJE (JAK ORANZOWY MANDARYNKOWY I BRAZOWY)
///PIERWIASTKOWANIE
///LOGARYTMOWANIE
///SYSTEMY LICZENIOWE W POLICZ
///SZACHY ONLINE
///MIERZENIE CZASU
///POWIADOMIENIE ZE KTOS COS NAPISAL -> JAK BEDZIE OBIEKTOWY KOMUNIKATOR
///TECZOWY KOLOR WLASNA FUNCKJA COUT
///ADMINISTRATORZY W UZYTKOWNIKACH
///KOMUNIKATOR OBIEKTOWO
///OBIEKTOWA KONSOLA

///ZMIESZAJ KOLORY
///ILE CZASU ZOSTALO DO  TEZ BY SIE PRZYDALO
///ILE CZASU MINELO OD   TO TEZ
///KLASA PRZETRZYMUJACA WIELKIE LICZBY MOC ALEXA ;-;


    ///POPIERDOLONE POMYSLY PRZYSZ£OSCI:
/// POLICZ NIECH MOWI GDZIE JEST BLAD >:) >:) / chyba nie takie trudne /
/// GENERATOR ZDAÑ, OPOWIADAÑ
/// RÓWNANIA
/// LITERÓWKI
/// T£UMACZ S£OW NA ANG
/// RYSOWANIE W UKLADZIE WSPOLRZEDNYCH
/// ODMIANA SLOW PRZEZ PRZYPADKI I BLEDY ORTOGRAFICZNE (DEKLINACJA)

    ///Swoja droga idzcie do szarko i zrobcie prezentacje na temat Liczb fibonacciego i liczb Lucasa [*]

    ///Impreza urodzinowa dla satunina
