#include "../_Headers/funkcje.h"
#include "Wywolania.h"

/**
    FUNKCJA MATKA TABLICY WSKAZNIKOW
    To tutaj w tablicy wskaznikow przysylanej jako argument wskazniki sa ustawiane na odpowiednie funkcje zgodnie z numerami w tablicy (tak jak w pliku slowa_klucz)
    Przysylamy tez ILOSC_KOMEND by NIE ZMIENIAC RECZNIE DEFAULT
    Wartosc ilosc_komend to DLUGOSC PLIKU TEKSTOWEGO SLOWA_KLUCZ
    przez to dodajac NOWE komendy nie trzeba sie martwic o NIE WPROWADZONO TAKIEJ KOMENDY
*/

void ustawianie_tablicy_wskaznikow(void (*tab[])(string**), int *ilosc_komend){
    for(int i=0;i<*ilosc_komend;i++)
        tab[i] = 0; ///Ustawiamy wszystkie na zero zeby nie bylo tragedi jesli sie przypadkiem jakies pominelo


    tab[0] = 0;
    for(int i=19;i<23;i++) tab[i] = 0;  ///Mozna by pominac ale ustaiamy je na zero zeby wiedziec ze akurat te sa celowo ustawione
/* MODULO  */
    tab[1] = &WywolanieModulo; tab[3] = &WywolanieModulo; tab[5] = &WywolanieModulo; tab[40] = &WywolanieModulo; tab[64] = &WywolanieModulo;
/* SREDNIA */
    tab[8] = &WywolanieSrednia;
/* ZEGNAJ */
    tab[28] = &WywolanieZegnaj; tab[29] = tab[28]; tab[30] = tab[28]; tab[31] = tab[28]; tab[33] = tab[28];
    tab[65] = tab[28]; tab[66] = tab[28]; tab[67] = tab[28];
/* PRZYWITANIE */
    tab[32] = &WywolaniePrzywitanie; tab[11] = tab[32]; tab[107] = tab[32];
    for(int i=68;i<96;i++)   tab[i]=tab[32];
/* DZIELENIE */
    tab[2] = &WywolanieDzielenieZReszta; tab[18] = tab[2];
/* DZIELENIE */
    tab[6] = &WywolanieMediana; tab[42] = tab[6];
/* ZAPIS */
    tab[9] = &WywolanieZapis;
/* DOPIS */
    tab[43] = &WywolanieDopisz;
/* ODCZYT */
    tab[10] = &WywolanieOdczyt; tab[34] = tab[10];
/* WYCZYSC PLIK */
    tab[23] = &WywolanieWyczyscPlik;
/* BAZA KOLOROW */
    tab[13] = &WywolanieBazaKolorow; tab[41] = tab[13];
/* SEGREGOWANIE */
    for(int i=14;i<18;i++)  tab[i] = &WywolanieSegregowanie;
/* ZMIEN MOJ KOLOR */
    tab[4] = &WywolanieZmienTwojKolor; tab[24] = tab[4]; tab[97] = tab[4]; tab[98] = tab[4];
/* ZMIEN TWOJ KOLOR */
    tab[44] = &WywolanieZmienMojKolor; tab[99] = tab[44];
/* LICZBA PIERWSZA */
    tab[25] = &WywolanieLiczbaPierwsza; tab[26] = tab[25];
/* LISTA KOMEND */
    tab[27] = &WywolanieListaKomend; for(int i=177;i<=119;i++) tab[i] = tab[27];
/* POLICZ */
    tab[12] = &WywolaniePolicz; tab[38] = tab[12]; tab[120] = tab[12]; tab[121] = tab[12];
/* SPRAWDZ DZIEN TYGODNIA */
    tab[35] = &WywolanieSprDzTyg;
/* WZOR */
    tab[39] = &WywolanieWzor;
/* PALINDROM */
    tab[45] = &WywolaniePalindrom; tab[46] = tab[45];
/* DZIELNIKI */
    tab[50] = &WywolanieDzielniki; tab[51] = tab[50]; tab[52] = tab[50];
/* GODZINA WW INNYM MIESCIE */
    tab[61] = &WywolanieGWIM; tab[62] = tab[61]; tab[104] = tab[61];
/* GODZINA W INNYM KRAJU */
    tab[59] = &WywolanieGWIK; tab[60] = tab[59]; tab[103] = tab[59];
/* SILNIA */
    tab[7] = &WywolanieSilnia; tab[63] = tab[7];
/* LOSUJ */
    tab[100] = &WywolanieLosuj; tab[101] = tab[100]; tab[102] = tab[100];
/* SYSTEMY LICZENIOWE */
    tab[105] = &WywolanieSysLicz; tab[106] = tab[105];
/* WYBIERZ */
    tab[96] = &WywolanieWybierz;
/* PROCENT */
    tab[36] = &WywolanieProcent; tab[37] = tab[36];
/* PI */
    for(int i=122;i<127;i++)    tab[i] = &WywolaniePi;
/* MUZYKA */
    for(int i=111;i<117;i++)    tab[i] = &WywolanieMuzyka;
/* STATKI */
    tab[127] = &WywolanieStatki;
/* SZACHY */
    tab[128] = &WywolanieSzachy;
/* TTT */
    for(int i=108;i<111;i++)    tab[i] = &WywolanieTtt;
/* WYLOGUJ */
    tab[56] = &WywolanieWyloguj;
/* ZALOGUJ */
    tab[54] = &WywolanieZaloguj;
/* USUN KONTO */
    tab[58] = &WywolanieUsunKonto;
/* ZAREJESTRUJ */
    tab[55] = &WywolanieZarejestruj; tab[57] = tab[55];
/* KOMUNIKATOR */
    tab[47] = &WywolanieKomunikator; tab[48] = tab[47]; tab[49] = tab[47]; tab[53] = tab[47];
    tab[129] = &mem;
/* DEFAULT */
    tab[*ilosc_komend-1] = &WywolanieDefault; ///Jesli nie podano komendy mamy do czynienia z wartoscia rowna dlugosci pliku
                                             ///Dlatego jesli ktos wywola ostatnie miejsce tablicy (numerowane od 0) oznacza to ostanie mioejsce w pliku (numerowane od 1)


}

/**
    Funkcje sa UZYWANE w MAINIE gdy ktos poda komende i zgadza ona sie z odpowiednim slowem kluczem wywolywana jest odpowiednia FUNKCJA.
    Funkcje NIE SA wywolywane BEZPOSREDNIO poniewaz ich adresy sa zapisane w TABLICY WSKAZNIKOW NA FUNKCJE
    Jako argument przysylamy TABLICE WSKAZNIKOW NA STRINGI
    Tablica jest odbierana jako WSKAZNIK dlatego mamy PODWOJNE GWIAZDKI
    Mozna by rownie dobrze zapisac !!!----> string* argv[] <----!!!
    Wysylamy tablice poniewaz nie mialoby sensu wysylac do kazdej funkcji wielu zmiennych gdy kazda z osobna uzywa tylko poszczegolnych jej elemtntow!
*/

/**
    argv[0] => przechowuje lokalizacje na dysku C folderu Saturnin
    argv[1] => Przechowuje odpowiedz a wlasciwie to co z niej zostalo
    argv[2] => Zmieniona odpowiedz na potrzeby pozegnania
    argv[3] => To co ma sie wysiwetlic na ekranie po wyczyszczeniu
    argv[4] => Przechowuje uzytkownika
*/

void WywolanieModulo(string** argv){
    cout<<"Uruchamiam funkcje modulo";
    kropki(700);
    string przesyl = "start ../Modulo/Modulo.exe "+*argv[1];
    system(przesyl.c_str());
}

void WywolanieSrednia(string** argv){
    cout<<"Uruchamiam srednia";
    kropki(700);
    string przesyl = "start ../Srednia/Srednia.exe "+*argv[1];
    system(przesyl.c_str());
}

void WywolanieZegnaj(string** argv){
    zegnaj(kolor_saturnina,*argv[2]);
    getch();
    exit(0);
}

void mem(string** argv){
    cout<<"Przybyles poznac prawde";
    kropki(1500);
    cout << endl << "Ukryta jest ona";
    kropki(1500);
    cout << endl << "W folderze nr";
    kropki(1500);
    cout << endl << "HAHA numeru nawet ja nie znam";
    kropki(1500);
    cout << endl << "Za to na kanale kurs programistyczny";
    kropki(1500);
    cout << endl << "W kanale tekstowym narada-mistrzow";
    kropki(1500);
    cout << endl << "W jego opisie jest odpowiedz";
    kropki(1500);
    cout << endl << "Zegnaj";
    kropki(1500);
    system("cls");
}

void WywolaniePrzywitanie(string** argv){
    przywitanie();
    getch();
}

void WywolanieDzielenieZReszta(string** argv){
    cout<<"Uruchamiam program Dzielenie";
    kropki(700);
    string przesyl = "start ../Dzielenie/Dzielenie.exe "+*argv[1];
    system(przesyl.c_str());
}

void WywolanieMediana(string** argv){
    cout<<"Uruchamiam Mediane";
	kropki(700);
	string przesyl = "start ../Mediana/Mediana.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieZapis(string** argv){
    string k;
    zapis(*argv[1],kolor_saturnina,nasz_kolor,*argv[3]);
}

void WywolanieDopisz(string** argv){
    (*argv[1]).erase(0,1);
    dopis(*argv[1],kolor_saturnina,nasz_kolor,*argv[3]);
}

void WywolanieOdczyt(string** argv){
    cout << "Otwieram schowek";
    kropki(700);
    system("start ../odczytaj/odczytaj.exe");
}

void WywolanieWyczyscPlik(string** argv){
    wyczysc(kolor_saturnina,*argv[3]);
}

void WywolanieBazaKolorow(string** argv){
    cout << "Pokazuje dostepne kolory";
    kropki(700);
    system("start ../baza_kolorow/baza_kolorow.exe");
}

void WywolanieSegregowanie(string** argv){
    cout<<"Uruchamiam program do segregowania";
	kropki(700);
	string przesyl = "start ../Uporzadkuj/Uporzadkuj.exe "+*argv[1];
	system(przesyl.c_str());

}

void WywolanieZmienTwojKolor(string** argv){
    kolor_saturnina=zmien_twoj_kolor(kolor_saturnina,nasz_kolor,*argv[1], *argv[3]);
    if(kolor_saturnina == 6 || kolor_saturnina == 7) kolor_saturnina = 4;
    else if(kolor_saturnina == 27 || kolor_saturnina == 28 || kolor_saturnina == 30 || kolor_saturnina == 31 || kolor_saturnina == 33) kolor_saturnina = 8;
    else if(kolor_saturnina == 13) kolor_saturnina = 11;
    else if(kolor_saturnina == 14 || kolor_saturnina == 17 || kolor_saturnina == 19 || kolor_saturnina == 20 || kolor_saturnina == 21 || kolor_saturnina == 32) kolor_saturnina = 12;
    else if(kolor_saturnina == 18) kolor_saturnina = 16;
    else if(kolor_saturnina == 23 || kolor_saturnina == 24) kolor_saturnina = 22;
    else if(kolor_saturnina == 26 || kolor_saturnina == 29) kolor_saturnina = 25;
    else if(kolor_saturnina == 35 || kolor_saturnina == 36 || kolor_saturnina == 37) kolor_saturnina = 34;
}

void WywolanieZmienMojKolor(string** argv){
    nasz_kolor=zmien_moj_kolor(kolor_saturnina,nasz_kolor,*argv[1], *argv[3]);
    if(nasz_kolor == 6 || nasz_kolor == 7) nasz_kolor = 4;
    else if(nasz_kolor == 27 || nasz_kolor == 28 || nasz_kolor == 30 || nasz_kolor == 31 || nasz_kolor == 33) nasz_kolor = 8;
    else if(nasz_kolor == 13) nasz_kolor = 11;
    else if(nasz_kolor == 14 || nasz_kolor == 17 || nasz_kolor == 19 || nasz_kolor == 20 || nasz_kolor == 21 || nasz_kolor == 32) nasz_kolor = 12;
    else if(nasz_kolor == 18) nasz_kolor = 16;
    else if(nasz_kolor == 23 || nasz_kolor == 24) nasz_kolor = 22;
    else if(nasz_kolor == 26 || nasz_kolor == 29) nasz_kolor = 25;
    else if(nasz_kolor == 35 || nasz_kolor == 36 || nasz_kolor == 37) nasz_kolor = 34;

}

void WywolanieLiczbaPierwsza(string** argv){
    cout<<"Uruchamiam Sprawdzacza liczb pierwszych";
	kropki(700);
//	cout<<"\n*argv[1] == "<<*argv[1]<<endl;
	string przesyl = "start ../Liczba_Pierwsza/Liczba_Pierwsza.exe "+*argv[1];
//	cout << przesyl.c_str() << endl;
//		getch();
	system(przesyl.c_str());
}

void WywolanieListaKomend(string** argv){
    cout << "Uruchamiam liste komend";
    kropki(700);
    system("start ../lista_komend/lista_komend.exe");
}

void WywolaniePolicz(string** argv){
    cout<<"Uruchamiam policz";
	kropki(700);
	string przesyl = "start ../Policz/Policz.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieSprDzTyg(string** argv){
    cout<<"Uruchamiam sprawdzanie dnia tygodnia";
	kropki(700);
	string przesyl = "start ../sprawdz_dzien_tygodnia/sprawdz_dzien_tygodnia.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieWzor(string** argv){
    cout<<"Pracujemy nad tym";
    kropki(700);
}

void WywolaniePalindrom(string** argv){
    cout<<"Uruchamiam program sprawdzajacy palindromy";
	kropki(700);
	string przesyl = "start ../palindrom/palindrom.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieDzielniki(string** argv){
    cout<<"Uruchamiam program wyznaczajacy dzielniki";
	kropki(700);
	string przesyl = "start ../dzielniki/dzielniki.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieGWIK(string** argv){
    cout<<"Uruchamiam Sprawdzanie godziny w innym kraju";
	kropki(700);
	string przesyl = "start ../Godzina_kraj/Godzina_kraj.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieGWIM(string** argv){
    cout<<"Uruchamiam Sprawdzanie godziny w innym miescie";
	kropki(700);
	string przesyl = "start ../godzina_miasto/godzina_miasto.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieSilnia(string** argv){
    cout<<"Uruchamiam program liczacy silnie";
	kropki(700);
	string przesyl = "start ../silnia/silnia.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieLosuj(string** argv){
    cout<<"Uruchamiam program losujacy";
	kropki(700);
	string przesyl = "start ../losowanie/losowanie.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieSysLicz(string** argv){
    cout<<"Uruchamiam program do obliczen na systemach liczeniowych";
    kropki(700);
    system("start ../systemy_liczeniowe/systemy_liczeniowe.exe");
}

void WywolanieWybierz(string** argv){
    cout<<"Uruchamiam program wybierajacy";
	kropki(700);
	string przesyl = "start ../wybierz/wybierz.exe "+*argv[1];
	system(przesyl.c_str());
}

void WywolanieProcent(string** argv){
    cout<<"Uruchamiam program liczacy procent";
    kropki(700);
    system("start ../procent/procent.exe");
}

void WywolaniePi(string** argv){
    fstream plik;
    if(nasz_kolor == kolor_saturnina)
    {
        cout << "Tutaj twoj kolor nie moze nachodzic sie z moim!\n";
        getch();
        return;
    }
      string przesyl = "start ../liczba_pi/liczba_pi.exe "+*argv[1];

    cout << "Zapraszamy do kacika niezmierzonych legionow cyfr Ludolfiny";
    cout << "\n"; Sleep(200); cout << "3"; Sleep(200); cout << "."; Sleep(200); cout << "1"; Sleep(200); cout << "4"; Sleep(200);
    cout << "1"; Sleep(200); cout << "5"; Sleep(200); cout << "9"; Sleep(200); cout << "2"; Sleep(200);
    system(przesyl.c_str());
}

void WywolanieMuzyka(string** argv){
	string przesyl = "start ../muzyka/muzyka.exe "+*argv[4];
    cout << "Uruchamiam zakatek muzyczny";
    //kropki(700);
    for(int i = 3; i>0;i--)
    {
        cout << " ";
        Sleep(500);
        cout << "\16";
        Sleep(500);
    }
    system(przesyl.c_str());
}

void WywolanieStatki(string** argv){
    fstream plik;
    if(*argv[4] == "Gosc")
    {
        *argv[3] = "Gosc nie ma uprawnien do gry w statki";
    }
    else
    {
        string przesyl = "start ../Statki/Statki.exe "+ *argv[4];
        cout<< "Uruchamiam statki";
        kropki(700);
        system(przesyl.c_str());
    }
}

void WywolanieSzachy(string** argv){
    system("start ../Szachy-Online/Szachy-Online.exe");
}

void WywolanieTtt(string** argv){
    fstream plik;
    if(*argv[4] == "Gosc")
    {
        *argv[3] = "Gosc nie ma uprawnien do gry w kolko i krzyzyk";
    }
    else
    {
        string przesyl = "start ../kolko_i_krzyzyk/kolko_i_krzyzyk.exe "+ *argv[4];
        cout<< "Uruchamiam kolko i krzyzyk";
        kropki(700);
        system(przesyl.c_str());
    }
}

void WywolanieDefault(string** argv){
    static int podpowiedz = 100;
    cout << "Nie wprowadzono do bazy danych tej komendy";
    if(rand()%podpowiedz == 0 || rand()%podpowiedz == 1)  ///Jesli modulo to 0 lub jeden bo jesli podzielimy 1 przez 2 to bedzie zero a modulo zero to zly pomysl
    {
        cout<<endl<<"Polecam uzyc komendy \"Lista komend\"";
        podpowiedz = 100; ///Sprawdzil sie warunek ustawiamy spowrotem warunek na male prawdopoobienstwo
        Sleep(5000);
    }
    else
    {
        podpowiedz /= 3; ///Zmniejszamy prawdopodobienstwo dzielac przez 3
        kropki(700);
        return;
    }
}

void WywolanieWyloguj(string** argv){
    if(*argv[4] == "Gosc")
    {
        *argv[3] = "Nie jestes zalogowany!";
    }
    else {
        *argv[4] = "Gosc";
        *argv[3] = "Wylogowano!";
    }
}

void WywolanieZaloguj(string** argv){
    static bool login = false;
    fstream logowanie;
    string nazwa, haslo;   ///Pomocne stringi
    int licznik=0;
    if(*argv[4] != "Gosc")
    {
        *argv[3] = "Juz jestes zalogowany na konto - "+*argv[4]+"!";
        goto zalogowano;
    }
    if(usp(*argv[1]) == "")
    {
        cout<<"Podaj nazwe uzytkownika: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,*argv[1]);
        saturnin_mowi(kolor_saturnina);
    }
    if(usp(*argv[1]) == "Gosc")
    {
         *argv[3] = "Nazwa zajeta!";
        goto zalogowano;
    }
    logowanie.open("../Pliki/logowanie",ios::in);   ///Sprawdzanie czy ktos nie jest zalogowany
    while(getline(logowanie,nazwa))
    {
        if(login == true)
        {
            login = false; ///Zeby mozna bylo sie zalogowac jak haslo bedzie zle
            saturnin_mowi(kolor_saturnina);
            if(haslo == nazwa)
            {
                *argv[3] = "Witaj "+*argv[4]+"!";    ///Witamy uzytkownika
                goto zalogowano;
            }
            else
            {
                *argv[3] = "Bledne haslo, sprobuj jeszcze raz";    ///Jesli sie nie udalo podmieniamy uzytkownika na goscia
                *argv[4] = "Gosc";
                goto zalogowano;
            }
        }
        if(licznik%2 == 0)  ///Co dwa sa nazwy
        {
            if(nazwa == usp(*argv[1],0,0,1,1))
            {
                ///jest taki uzytkownik prosimy o haslo
                *argv[4] = nazwa;
                saturnin_mowi(kolor_saturnina);
                cout<<"Podaj haslo: ";
                saturnin_mowi(nasz_kolor);
                echo(false);  ///Nie wyswietla sie haslo
                getline(cin,haslo);
                login = true;  ///Ustawia login na true zeby na nastepnym przejsciu petli sprawdzil haslo

            }
        }
        licznik++;
    }
    *argv[3] = "Nie ma takiego uzytkownika w bazie danych, polecam uzyc komendy \"Zarejestruj\"";
zalogowano:
    logowanie.close();
}

void WywolanieUsunKonto(string** argv){
    vector <string> kopia_zapasowa;
    fstream logowanie;
    string napis, linia;
    if(*argv[4] == "Gosc")
    {
        *argv[3] = "Musisz sie najpierw zalogowac!";    ///jesli ktos nie jest zalogowany
        return;
    }
    cout << "Czy chcesz usunac swoje konto ? (W celu usuniecia nalezy podac \"tak\")" <<endl;
    saturnin_mowi(nasz_kolor);
    getline(cin,napis);
    saturnin_mowi(kolor_saturnina);
    if(usp(modp(napis)) == "tak")   ///Potwierdzenie usuniecia
    {
        logowanie.open("../Pliki/logowanie",ios::in);
        while(getline(logowanie,linia))         ///Tworzymy kopie zapasowa
        {
            if(linia == *argv[4])
            {
                getline(logowanie,linia);    ///Pomijamy dwie linijki z aktualnym kontem
                continue;
            }
            else
            {
                kopia_zapasowa.push_back(linia);   ///Wczytujemy do vectora plik
            }
        }
        logowanie.close();
        logowanie.open("../Pliki/logowanie", ios::out);  ///Plik sie czysci
        for(unsigned int i=0; i <kopia_zapasowa.size(); i++)
        {
            logowanie << kopia_zapasowa[i] << endl; ///Uaktualniamy plik z kopi zapasowej

        }
        *argv[3] = "Konto usuniete pomyslnie!";
        *argv[4] = "Gosc"; ///No bo nie moze byc na usunietyum uzytkowniku
    }
    else if(usp(modp(napis)) == "nie")
    {
        *argv[3] = "W takim razie przerywam operacje...";
    }
    else
    {
        *argv[3] = "Nie zrozumiala odpowiedz, przerywam operacje...";
    }
}

void WywolanieZarejestruj(string** argv){
    fstream logowanie;
    string nazwa_uzytkownika, password, passwort,linia;
    int licznik = 0;
    nazwa_uzytkownika = *argv[1];
    if(usp(nazwa_uzytkownika) == "")
    {
        cout << "Podaj nazwe uzytkownika: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,nazwa_uzytkownika);   ///Wczytujemy nazwe
        saturnin_mowi(kolor_saturnina);
    }
    logowanie.open("../Pliki/logowanie",ios::in);
    while(getline(logowanie,linia))  ///Sprawdanie czy taka nazwa juz jest
    {
        //cout << "Z pliku: "<<linia << " a podane: " <<nazwa_uzytkownika<<endl;
        if(licznik %2 == 0&&modp(linia) == modp(nazwa_uzytkownika))
        {
            *argv[3] = "Taka nazwa juz istnieje!";
            return;
        }
        licznik++;
    }
    //cout << "Tu skonczylem petle\n";
    logowanie.close();
    cout << "Podaj haslo: ";
    saturnin_mowi(nasz_kolor);
    cin >> password;
    saturnin_mowi(kolor_saturnina);
    cout << "Potwierdz haslo: ";
    saturnin_mowi(nasz_kolor);
    cin >> passwort;   ///Sprawdzanie czy hasla sa takie same
    saturnin_mowi(kolor_saturnina);
    if(password != passwort)
    {
        *argv[3] = "Podane hasla nie zgadzaja sie!";
        return;
    }
    logowanie.open("../Pliki/logowanie",ios::out|ios::app);
    logowanie << nazwa_uzytkownika<<endl << password <<endl; ///Wpisanie konta do pliku
    logowanie.close();
    *argv[3] = "Konto zostalo stworzone pomyslnie!";
}

void WywolanieKomunikator(string** argv){
    string operacje_na_plikach, linia, nazwa ;
    fstream logowanie, plik;
    operacje_na_plikach = "../komunikator/" + *argv[4] ;

    logowanie.open(operacje_na_plikach.c_str(),ios::in);
    string X;
    int licznik = 0;
    while(getline(logowanie,linia))
    {
        X = linia;
    }
    if(X != *argv[4] + " opuscil czat..." && licznik > 0)
    {
        *argv[3] =  "Uzytkownik o tej nazwie juz korzysta z czatu!\nStworz swoje konto uzywajac komendy \"Zarejestruj\" aby dolaczyc do czatu!\n";
        return;
    }
    logowanie.close();
    string przesyl = "start ../Komunikator/komunikator.exe " + *argv[4];
    cout << "Uruchamiam komunikator";
    kropki(500);
    system(przesyl.c_str());
}
