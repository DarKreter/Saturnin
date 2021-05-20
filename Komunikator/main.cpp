#include "..\_Headers\funkcje.h"
#include "Funkcje_Komunikator.h"

int main(int argc, char*argv[])
{
    fstream plik; string kupa;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    int nasz_kolor, kolor_saturnina,czas;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false)
    {
        czy_wszystko_ok= false;
        sprawdzacz_bledow(0);
    }
    plik>> kolor_saturnina >> nasz_kolor;
    plik.close();

    string linia,uzytkownik ="";
    if(argc > 1)
    {
        argv++;
        uzytkownik = *argv;
    }
    if(uzytkownik == "") uzytkownik = "Gosc";


    fstream komunikacja, logowanie, kolor_kogos, plik_historyczny;   ///Deklarujemy sobie plik
    string zmiennaa, napis, my_piszemy, operacje_na_plikach, jeden, dwa;    ///Kilka taktycznych stringow
    vector <string> inni_uzytkownicy, pierwsze_nadpisanie, historia;  ///vectory bardzo fajna rzecz
    int kolory_innych ;
    int k = 0, ilosc_linii = 0, limit[100];
    saturnin_mowi(kolor_saturnina);
    cout << "Saturnin.net" <<endl;

    operacje_na_plikach = "../komunikator/kolory/" + uzytkownik + "_kolor" ; ///Dobry dzialajacy string
    kolor_kogos.open(operacje_na_plikach.c_str(),ios::out);  ///Dajemy nasz kolor innym
    kolor_kogos << nasz_kolor;
    kolor_kogos.close();
/*
    operacje_na_plikach ="../komunikator/zalogowani/" + uzytkownik ; ///Wpisujemy ze jestesmy zalogowani
    komunikacja.open(operacje_na_plikach.c_str(),ios::out);
    komunikacja << "tak";
    komunikacja.close();
*/
    ///NAZWY UZYTKOWNIKOW DO VECTORA
    logowanie.open("../Pliki/logowanie",ios::in);
    string tak_o;
    while(getline(logowanie, tak_o))  ///Bierzemy nazwy uzytkownikow i wsadzamy je do vectora
    {
        if(k%2 == 0&&tak_o != uzytkownik)    {inni_uzytkownicy.push_back(tak_o);} ///Co dwa sa nazwy
        k++;
    }
    logowanie.close();

    ///WYCZTANIE HISTORII DO VECTORA
    plik_historyczny.open("../komunikator/historia",ios::in);
    while(getline(plik_historyczny,linia))  ///Wczytujemy historie
    {
        historia.push_back(linia);
    }

    ///WYPISANIE 10 OSTATNICH WIADOMOSCI Z HISTORII
    for(int j = historia.size()-10, k= 0; k<10; j++,k++ ) ///Wyswietlamy 10 ostatnich wiadomosci
    {
        rozdzielenie_historia(historia[j], jeden, dwa);
        cout << jeden;
        saturnin_mowi(nasz_kolor);
        cout << dwa << endl;
        saturnin_mowi(kolor_saturnina);
    }
    plik_historyczny.close();

    ///WPISANIE DO HISTORII ZE DOLACZYLISMY
    string x = sprawdzanie_czasu(0), y = sprawdzanie_daty();
    x.erase(5,x.length());
    y = y.substr(5,5); ///Data, godzina
    kupa = y.substr(0,2);
    y.replace(0,2,y.substr(3,2));
    y.replace(3,2,kupa);
    plik_historyczny.open("../komunikator/historia",ios::out|ios::app); ///Wpisujemy ze dolaczylismy do czatu w historii
    plik_historyczny <<y<<" "<<x<<" "<< uzytkownik << " dolaczyl do czatu!" <<endl;
    plik_historyczny.close();

    ///WPISANIE DO PLIKU ZE DOLACZYLISMY
    operacje_na_plikach ="../komunikator/" + uzytkownik ; ///Wpisujemy ze dolaczylismy do czatu
    komunikacja.open(operacje_na_plikach.c_str(),ios::out|ios::app);
    komunikacja <<endl<< uzytkownik << " dolaczyl do czatu!" ;
    komunikacja.close();

    ///USTALENIE LIMITU DLA KAZDEGO UZYTKOWNIKA
    for (int l = 0; l < inni_uzytkownicy.size(); l++) ///Musi stworzyc tyle limitow ile jest uzytkownikow
    {
        operacje_na_plikach ="../komunikator/" + inni_uzytkownicy[l] ; ///Dobry dzialajacy string
        komunikacja.open(operacje_na_plikach.c_str(),ios::in); ///Otwieramy plik uzytkownika po kolei wszystkich
        ilosc_linii = 0;
        while(getline(komunikacja,zmiennaa))
        {
            ilosc_linii ++;
        }
        limit[l] = ilosc_linii; ///Mamy limit dla kazdego uzytkownika
        komunikacja.close();
    }

    cout << "Dolaczyles do czatu" <<endl ;
na_sama_gore:
    for(Komunikator x(uzytkownik);;) ///Tworzymy obiekt w petli jesli petla sie skonczy obiekt zostanie zniszczony i odpali sie destruktor
    {
        for (unsigned int l = 0; l < inni_uzytkownicy.size(); l++) ///KTOS NAPISAL
        {
            ilosc_linii = 1;
            operacje_na_plikach ="../komunikator/" + inni_uzytkownicy[l];
            komunikacja.open(operacje_na_plikach.c_str(),ios::in);
                while(getline(komunikacja,zmiennaa))  ///Wczytujemy z czyjegos pliku az do konca
                {
                    if(ilosc_linii > limit[l]) ///Jesli pojawila sie nowa linijka i ktos przekroczyl limit wypisujemy to
                    {
                        //cout << "Limit byl " << limit[l] << " a ilosc linii "<<ilosc_linii<<endl;
                        operacje_na_plikach ="../komunikator/kolory/" + inni_uzytkownicy[l] + "_kolor";
                        kolor_kogos.open(operacje_na_plikach.c_str(), ios :: in); ///Bierzemy kolor tego kogo sprawdzamy
                        getline(kolor_kogos,linia); ///Wczytujemy kolor
                        kolory_innych = string_na_int(linia); ///Oczywiscie robimy w inta
                        kolor_kogos.close();
                        string x = sprawdzanie_czasu(0), y = sprawdzanie_daty();
                        x.erase(5,x.length());
                        y = y.substr(5,5); ///Data, godzina
                        kupa = y.substr(0,2);
                        y.replace(0,2,y.substr(3,2));
                        y.replace(3,2,kupa);
                        rozdzielenie(zmiennaa, jeden, dwa); ///Rozdzielamy napis zeby pisac w kolorakach saturnina i naszych
                        saturnin_mowi(kolor_saturnina);
                        cout<<y<<" " <<x<<" "<< jeden ;  ///Data, godzina
                        saturnin_mowi(kolory_innych);  ///Kolor tego kogos
                        cout<<dwa<<endl;          ///wypisujemy na ekran to co jest w pliku
                        saturnin_mowi(kolor_saturnina);
                        limit[l] ++; ///Zwiekszamy limit zeby znowu nie wszedl w ta linijke
                        //cout << "Zwiekszylem limit na tyle " << limit[l] <<endl;
                    }
                    ilosc_linii ++; ///Nastepne przejscie petli
                }
            komunikacja.close();
        }
        if( kbhit()==true)     ///Czeka az ktos kliknie jakis znak na klawiaturze tylko wtedy ten if sie wykonuje MY PISZEMY
        {
            string x = sprawdzanie_czasu(0), y = sprawdzanie_daty();
            x.erase(5,x.length());
            y = y.substr(5,5); ///Data, godzina
            kupa = y.substr(0,2);
            y.replace(0,2,y.substr(3,2));
            y.replace(3,2,kupa);
            cout <<y<<" "<< x <<" "<< uzytkownik << ": "; ///Data godzina i my
            operacje_na_plikach ="../komunikator/" + uzytkownik ;
            komunikacja.open(operacje_na_plikach.c_str(),ios::out|ios::app);
            saturnin_mowi(nasz_kolor);
            getline(cin,my_piszemy);            ///wpisujemy wiadomosc i zapisujemy pod my_piszemy
            saturnin_mowi(kolor_saturnina);
            if(usp(usp(my_piszemy)) == "/wyjdz")   ///Gdyby ktos chcial sobie pojsc
            {
                cout << "Opusciles czat...";
                break;
            }
            if(usp(modp(my_piszemy)) == "")  ///I TAK WYPISZEMY U NAS ALE NIE MUSIMY W HISTORII I DLA INNYCH
            {
                komunikacja.close();
                continue;
            }
            komunikacja <<endl<<uzytkownik<<": "<< my_piszemy;     ///wpisujemy do pliku komunikacja zeby ktos mogl dostrzec zmiane pliku
            plik_historyczny.open("../komunikator/historia",ios::app|ios::out);
            plik_historyczny <<y<<" "<< x << " " << uzytkownik << ": " << my_piszemy<<endl  ; ///Uaktulaniamy historie
            plik_historyczny.close();
            komunikacja.close();
            continue;
        }
    }
    getch();
    return EXIT_SUCCESS;
}
