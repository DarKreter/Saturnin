#ifndef FUNKCJE.H
#define FUNKCJE.H
/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            INCLUDOWANIE BIBLIOTEK
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/
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
    #include <algorithm>
    #include <list>
    #include <conio.h>
    #include <string>
    #include <list>
    #include <vector>


/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            #DEFINE ORAZ MAKRODEFINICJE
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    #define ENDL endl
    #define Endl endl
    #define null 0
    #define Null 0
    #define FindNieZnalazl 4294967295


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                              NAMESPACY
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    using namespace std;

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                        EXTERN ROZNYCH ZMIENNYCH
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    extern bool czy_wszystko_ok;
    extern int kolor_saturnina, nasz_kolor, kolor_przeciwnika;
    extern list <long double> lista_globalna;
    extern nullptr_t Pusty_adres;


/*------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                          DEKLARACJE FUNKCJI
--------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                     FUNCKJE PLIKOWE I FOLDEROWE
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool czy_otwarty(fstream plik);
/**
    Sprawdzanie czy plik jest OTWARTY
    Jesli nie jest WYSWIETLA na ekranie KOMUNIKAT i zwraca FALSE
    Jesli plik sie otworzyl zwraca TRUE
*/

void tworzymy_pliki();
/**
    Synchronizacja i utworzenie niestniejacych FOLDEROW I PLIKOW
    INDYWIDUALNA FUNKCJA
    NIE UZYWAC
*/

int zapis(string napis,int kolor,int kolor2,string &czyszczenie);
/**
    Zapisuje podanego stringa do pliku tesktowego (SCHOWKA) na dysku C
    Do CZYSZCZENIA ktore jest przeslane za pomnoca REFERENCJI wpisuje czy odczyt byl UDANY czy NIE
    Jesli w pliku juz cos jest dopisze to na nowej linii
*/

int dopis(string napis,int kolor,int kolor2, string & czyszczenie);
/**
    Dopisuje podanego stringa do pliku tesktowego (SCHOWKA) na dysku C
    Do CZYSZCZENIA ktore jest przeslane za pomnoca REFERENCJI wpisuje czy odczyt byl UDANY czy NIE
    Dopisuje ZAWSZE PO SPACJI
*/

int odczyt(int kolor,int kolor2);
/**
    Odczytuje plik tesktowy (SCHOWEK) na dysku C
    Jesli odczyt nie byl udany wyswietli to na ekranie
    Wypisuje zawartosc na ekran
*/

int wyczysc(int kolor, string & czyszczenie);
/**
    CZYSCI plik tesktowy (SCHOWEK) na dysku C
    Jesli otworzenie pliku nie bylo udane wrzuci to do zmiennej CZYSZCZENIE przekazanej przez REFERENCJE
    Jesli bylo UDANE rowniez wpisze to do CZYSZCZENIE
*/

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                FUNCKJE MATEMATYCZNE
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

int policz(string dzialanie,long double &wynik,long double poprzedni_wynik = 0);
/**
    Zwraca numery bledow ktore obowiazuja jesli CZY_WSZYSTKO_OK == FALSE
    Prawdziwy WYNIK jest wysylany poprzez REFERENCJE
    Posiada DUZO ZABEZPIECZEN
    SPRAWDZA PRAKTYCZNIE WSZYSTKO
    Bardzo obszerny obszar obliczeniowy
*/

double srednia(string dzialanie,bool czy_korzysta_z_tego_policz=0);
/**
    Liczy srednia z liczb podanych po przecinku w przyslanym napisie
    Posiada pare ZEBEZPIECZEN w ktorzych zmienia czy_wszystko_ok na FALSE i zwraca NR BLEDU
    Wywoluje POLICZ i jest wywolywane przez POLICZ
*/

long double mediana(string dzialanie);
/**
    Liczy mediane z liczb podanych po przecinku w przyslanym napisie
    Posiada pare ZEBEZPIECZEN w ktorzych zmienia czy_wszystko_ok na FALSE i zwraca NR BLEDU
    Wywoluje POLICZ i jest wywolywane przez POLICZ
*/

long long int dzielenie(string dzialanie);
/**
    Dzieli dwie podane po spacji liczby calkowicie
    Posiada ZABEZPIECZENIA na bazie CZY_WSZYSTKO_OK oraz zwracania numeru bledu
*/

long double modulo(string napis);
/**
    Zwraca resztez dzielenia dwoch liczb podanych po spacji w napisie
    Ma Sporo zabezpieczen, uzywa wtedy CZY_WSZYSTKO_OK i zwraca numer bledu
*/

int dzielniki(string dzialanie);
/**
    Sprawdza dzielniki podanej liczby w stringu
    Ma duzo zabezpieczen, uzywa wtedy CZY_WSZYSTKO_OK
    Dzielniki sa zapisane w LISCIE GLOBALNEJ
*/

long double procent(string dzialanie, short int tryb);
/**
    Liczy procenty z dwoch liczb oddzielonych spacja w stringu dzialanie
    TRYBY:
    1. Liczy procent liczby X z Y
        EXAMPLE: "3 9"
        300% poniewaz 9 to 300% liczby 3
    2.Liczy procent z liczby
        EXAMPLE: "50 2"
        1 poniewaz 50% z 2 to 1
    3.Liczy liczbe na podstawie jej czesci i procentu tej czesci
        EXAMPLE: "25 4"
        16 poniewaz 25% z X to 4, zatem X jest rowne 16
    Posiada ZABEZPIECZENIA na bazie CZY_WSZYSTKO_OK i zwracania NR BLEDU
*/

long double silnia(string odp);
/**
    Przyjmuje napis
    Posiada duzo zabezpieczen
    Jesli wszystko w porzadku zwraca policzona funkcje
    Jesli cos jest nie tak zmiena czy_wszystko_ok na FALSE i zwraca numer bledu
    404 -> jesli liczba jest za dluga
    113 -> wprowadzono za duzo danych
    +69 -> podana liczba musi byc calkowita
    -69 -> Podana liczba musi byc dodatnia
    UZYWANE JEST STRING_NA_INT wiec jego bledy tez moga sie tutaj obajwic
*/

long double faktyczne_liczenie_silni(long double wynik);
/**
    Liczy srednia dla liczby
    Wszystkie zabezpieczenia sa funkcji silnia
*/

void segregowanie (string dzialanie);
/**
    Segreguje liczby podane po spacjach
    Wszystko jest zwracane w LISTACH ktore sa GLOBALNE
*/

void sortowanie (int *tablica, int lewy, int prawy);
/**
    QIUCK SORT
    Sortuje liczby od najmniejszej do najwiekszej
*/

int l_pierwsza(string napis);
/**
    Sprawdza czy LICZBA JEST PIERWSZA
    Jesli jest zwraca 1
    Jesli nie 0
    Ma pare zabezpieczen na bazie CZY_WSZYSTKO_OK i zwracania NR ERRORA
*/

string system_liczeniowy(string odp, int z_czego, int na_co, string bin_sd="", string bin_sz="");
/**
    GLOWNA FUNKCJA SYSTEMOW LICZENIOWYCH
    Korzysta ze wszystkich innych, dla specjalnych przypadkow czy zabezpieczen
    Posiada DUZY zasob ZABEZPIECZEN, zmienia wtedy CZY_WSZYSTKO_OK na FALSE i zwraca NR BLEDU
    Zlozona i duza funkcja
*/

void zmiana_systemu(int ktory, int &zamiana, string odp,int nasz_kolor, int kolor_saturnina,string &dwojkowy);
/**
    W wypadku podania blednego nowego systemu liczeniowego zmieni CZY_WSZYSTKO_OK na FALSE i zwroci w zmiennej ZAMIANA NR_BLEDU
    Jesli wszystko jest w porzadku podmieni zamiana na NOWY zmieniony SYSTEM
    Jesli zmienialismy na system dwojkowy w parametrze dwojkowy poda jaki to typ binarny
    MOZE modyfikowac podana ODPOWIEDZ ale MOZE tez zapytac o nowy SYSTEM <- jesli odp jest pusta
    ktory == 0 SYSTEM ZRODLOWY
    ktory == 1 SYSTEM DOCELOWY
*/

string Na_u1_u2(long double wynik, string bin_sd);
/**
    Zmienia liczbe z systemu dziesiatkowego na dowjkowy U1 lub U2
*/

int wzor(int kolor,int kolor2);
/**
    W TRAKCIE
*/

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                        FUNCKJE KONWERTUJACE
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

long double string_na_int(string liczba);
/**
    Zmienia stringa na long double
    Do tej funkcji nie mozna dawac liczby jezeli czy_wszystko_ok==false!!!
    Ma wlasne zabezpieczenia w ktorych ustawia czy_wszystko_ok na FALSE i zwraca numer bledu
    BLEDY:
    404 -> jesli liczba jest za dluga
    112 -> wprowadzono bledny znak
    113 -> wprowadzono za duzo danych
*/

string int_na_string(long double liczba, bool zamieniac_0_na_000=false);
/**
    Zmienia liczbe w long double na string
    Przecinek przyjmuje jako "."
    Jesli funkcja nie wykona sie poprawnie wypisze sie na ekranie "BLAD W INT NA STRING ty debilu"

*/

long double snr(long double stopnie);
/**
    Zmienia stopnie na radiany
    Oba w long double
*/

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                        FUNCKJE MODYFIKUJACE
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

string modp(string napis, bool bigtosmall = 1, bool plznaki = 1, bool poliznaki = 1, bool revers = 0);
/**
    OSTATECZNY MODYFIKATOR
    napis -> string na ktorym beda przeprowadzne modyfikacje
    bigtosmall -> czy zmieniac Wielkie litery na male
    plznaki -> czy zmieniac polskie znaki na zwykle
    poliznaki -> czy usuwac powielone znaki np  "eheeeej" -> "ehej"
    revers -> czy odwrocic napis (od tylu)
*/

string usp(string napis ,bool allsp=1 , bool doublesp=0 , bool startsp=0 , bool endsp=0 , string przed="" , string po="" , string miedzystart="" , string miedzystop="" , bool GOWNIANY_POMYSL_DANIELA=0 );
/**
    OSTATECZNY USUWACZ SPACJI

    napis- napis na ktorym beda wykonywane operacje

    allsp- czy usuwac wszystkie spacje
    doublesp- czy usuwac podwojne spacje
    startsp- czy usuwac spacje na poczatku napisu
    endsp- czy usuwac spacje na koncu napisu

    przed- wszystkie znaki przed ktorymi ma usunac spacje
    po- wszystkie znaki po ktorych ma usunac spacje

    miedzystart- Od ktorych znakow zaczac nie usuwanie spacji
    miedzystop- Na ktorych znakach konczyc nie usuwanie spacji

    MUSI BYC TYLE SAMO miedzystart ile jest miedzystop
*/

string zamieniacz_prawie_wszystkich_spacji_na_przecinki(string napis);
/**
    Zmienia WSZYSTKIE SPACJE na PRZECINKI POZA TYMI W {}
    Na potrzeby policz w medianie i sredniej
*/

string ptok(string napis);
/**
    Przecinki TO Kropki
    Zmienia przecinki w kropki
*/

string ptop(string napis);
/**
    Przestrzen TO Przecinki
    Zmienia spacje na przecinki
*/

int sprawdzacz_klawiszow(void);
/**
    Wczytuje znak
    Jesli jest on strza³k¹ to zwraca literke W A S lub D
    Jesli nie to zwraca NACISNIETY KLAWISZ
*/

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                FUNCKJE SPRAWDZAJACE I LICZACE ILOSC
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

int sprawdzacz_bledow(long double nr_bledu);
/**
    Jesli GLOBALNA ZMIENNA JEST FALSE wypisuje blad na podstawie nr_bledu
    Jesli jest TRUE wysiwetla po prostu zmienna NR_BLEDU ktory jest WYNIKIEM!!!
*/

bool palindrom(string napis);
/**
    Zwraca TRUE jesli napis JEST palindormem
    Zwraca FALSE jesli napis NIE JEST palindromem
*/

bool czy_to_liczba(string cyfra,bool czy_wliczac_minusy_i_kropki=false);
/**
    sprawdza CALEGO stringa czy jest rowny jakiejkolwiek cyfrze
    Wtedy TRUE
    Jesli NIE zwraca FALSE

    GDY czy_wliczac_minusy_i_kropki jest TRUE wtedy zwraca TRUE tez dla kropek i minusow

*/

bool czy_to_litera(string litera);
/**
    MODYFIKUJE odpowiedz z domniemanymi argumentami MODP
    Sprawdza czy to litera od "a" do "z" WTEDY ZWRACA TRUE
    Inaczej zwraca FALSE
*/

bool czy_jest_spacja(string napis);
/**
    Zwraca TRUE jesli jest w napisie JEST SPACJA
    Zwraca FALSE jesli w napisie nie ma spacji
*/

unsigned long long liczs (string napis);
/**
    Zwraca ilosc spacji w napisie
*/

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                    FUNCKJE BUFORU EKRANU
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

void ustaw_wskaznik(int x, int y);
/**
    USTAWIA wskaznik w konsoli w podanych wspolrzednych x, y
*/

void echo(bool enable = true);
/**
    dla FALSE wszystko co piszemy PISZE SIE ale tego NIE WIDAC
    dla TRUE wszystko jest normalnie lub wraca do normalnosci
    Stosowane np przy haslach
*/

void skok(unsigned long long liczba,string napis,string co_wsadzic=" ");
/**
    LEPSZY TAB
    Wypisze ci CO_WSADZIC ile zostalo znakow po liczba minus dlugosc napisu
    Jesli napis bedzie dluzszy od liczby WYPISZE na ekran KOMUNIKAT o bledzie
    JESLI
    EXAMPLE:
    liczba = 20 napis="qwerty"
    NA EKRANIE: "              " (14 spacji)
*/

void saturnin_mowi(int kolor);
/**
    Podajemy inta najczesciej zmienna KOLOR_SATURNINA, NASZ_KOLOR
    Ustawia kolor ktorym piszemy w konsoli na taki jaki chcemy
    01-Bialy-0xF 02-Szary-0x8 03-Srebrny-0x7 04-Zielony-0x2 05-Limonkowy-0xA 06-Oliwkowy-0x2 07-Lesny-0x2 08-Peridot-0x6 09-Niebieski-0x9 10-Turkusowy-0x3
    11-Morski-0xB 12-Granatowy0x1 13-Blekitny-0xB 14-Seledynowy-0x1 15-Czerwony-0xC 16-Krwisty-0x4 17-Burgynt-0x1 18-Bordowy-0x4 19-Pomaranczowy-0x1 20-Oranzowy-0x1
    21-Mandarynkowy-0x1 22-Fioletowy-0x5 23-Lawendowy-0x5 24-Purpurowy-0x5 25-Rozowy-0xD 26-Razmataz-0xD 27-Sinokoperkowy roz-0x6 28-Koperkowy-0x6 29-Magenta-0xD 30-Bezowy-0x6
    31-Orzechowy-0x6 32-Brazowy-0x1 33-Caput mortuum-0x6 34-Zolty-0xE 35-Kremowy-0xE 36-Zloty-0xE 37-Gumiguta-0xE
*/

int zmien_twoj_kolor(int kolor_saturnina,int nasz_kolor,string odp, string &czyszczenie);
/**
    Podmienia w pliku kolor_saturnina na to o co prosil uzytkownik
    Jednoczenie zmienna czyszczenie jest za pomoca REFERENCJI
*/

int zmien_moj_kolor(int kolor_saturnina,int nasz_kolor, string odp, string &czyszczenie);
/**
    Podmienia w pliku nasz_kolor na to o co prosil uzytkownik
    Jednoczenie zmienna czyszczenie jest za pomoca REFERENCJI
*/

void kropki(int czas);
/**
    Wyswietla na ekranie 3 kropki kazda w odstepie czasowym CZAS
*/

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            FUNCKJE UZYWAJACE DAT I CZASU
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

void jaki_czas(int r, int m, int d, int & kiedy);
/**
    W przekazywanym przez REFERENCJE argumencie ustawia
    10 dla daty przyszlej
    -1 dla daty terazniejszej
    1 dla daty przeszlej
*/

string sprawdzanie_daty();
/**
    Zwraca w stringu DATE w nastepujacym schemacie
    rok.miesiac.dzien   dzien_tygodnia
*/

void sprawdzanie_godziny_w_innym_kraju(string kraj, int nasz_kolor, int kolor_saturnina);
/**
    WYSWIETLA na ekranie AKTUALNA GODZINE w innym kraju
    Jesli kraj nie zostal podany pyta czy zaktualizowac baze danych
    Korzysta z PLIKOW
    Ma ZABEZPIECZENIA dotyczace STREF CZASOWYCH
*/

void sprawdzanie_godziny_w_innym_miescie(string miasto, int nasz_kolor, int kolor_saturnina);
/**
    WYSWIETLA na ekranie AKTUALNA GODZINE w innym miescie
    Jesli miasto nie zostalo podane pyta czy zaktualizowac baze danych
    Korzysta z PLIKOW
    Ma ZABEZPIECZENIA dotyczace STREF CZASOWYCH
*/

string sprawdzanie_czasu(float strefa);
/**
    Dla podanej w argumencie STREFY CZASOWEJ podaje jaka jest tam godzina
    Calosc zwraca ladnie w stringu i mozna to bezpiecznie od razu wypisac bo wyglada estetycznie
*/

string sprawdzanie_dnia_tygodnia(string odp, bool &specjalna_data, int &kiedy_czas);
/**
    GLOWNA funkcja DNI TYGODNIA, korzysta ze wszystkich innych
    Posiada bardzo duzo ZABEZPIECZEN, na bazie  CZY_WSZYSTKO_OK
    Spacjalna data sprawdza czy coutowac specjalne dane
    Kiedy czas oznacza czy data byla kiedys czy to dzis czy bedzie kiedys
*/

string dzienTygodnia(int dzien, int miesiac, int rok);
/**
    Zwraca w stringu jako dzien tygodnia byl w podanej w argumentach dacie
    Nie ma zabezpieczen ta funckja tylko LICZY DLA POPRAWNYCH danych dla blednych sie ZAWIESI
*/


inline int przestepny(int rok);
/**
    Zwaraca 1 jesli rok JEST przestepny, a 0 jesli NIE JEST
*/

string poprawne_daty(int rok, int miesiac, int dzien);
/**
    Sprawdza czy podana DATA ISTNIEJE
    Jesli nie CZY_WSZYSTKO_OK ustawi na false i zwroci numer bledu\
    Wbrew pozorom BLEDOW do wykrycia jest WIELE
*/

string specjalne_daty(int rok, int miesiac, int dzien, bool &specjalna_data);
/**
    Na podstawie roku, miesiaca i dnia sprawdza czy podana data nie jest SPECJALNA
    SPIS specjalnych dat jest w pliku tekstowym
    Jesli wystapil BLAD z plikiem zmieni CZY_WSZYSTKO_OK na FALSE
    Jesli faktycznie zajdzie specjalna data zmieni SPECJALNA_DATA na TRUE (REFERENCJA)
    Jesli data jest specjalna funkcja zwroci w stringu gotowa odpowiedz do wypisania
*/

string miesiac_napisany(string odp);
/**
    Zmienia wszystkie miesiace napisane slownie na cyfry w napisie
    EXAMPLE:
    odp = "1 marca 2001"
    ZWROCI "1 3 2001"
*/

string data_przeszla(string odp);
/**
    USUWA z ODP SPACJE KONCOWE
    Zmienia pne badz p.n.e. I WSZYSTKIE KOMBINACJE Z KROPKAMI na minusa na poczatku stringa
    Jesli nie znajdzie pne zwroci tylko z usunietymi spacjami na KONCU
*/


/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                  FUNKCJE PODSTAWOWE    (RESZTA)
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

int losowanie(string napis);
/**
    Losuje liczbe z podanego zakresu
    Samo losowanie jest krotkie ale funkcja ma duzo zabezpieczen przed wszystkim
    Zmienia wtedy CZY_WSZYSTKO_OK na false
    EXAMPLE:
    napis="1 3"
    Losuje liczbe z zakresu 1, a 3
*/

string wybierz(string napis);
/**
    Losuje wybor z podanych opcji w stringu napis
    Kazda opcja jest oddzielona SPACJA
*/

void przywitanie();
/**
    coutuje przywitanie zgodnie z godzina
    Przed 20 jest jeden zestaw
    Po 20 drugi zestaw
*/

void zegnaj(int kolor,string odp);
/**
    Wyswietla pozegnanie bazujac na aktualnej godzinie
*/


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                    KLASY
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */



#endif // FUNKCJE.H

