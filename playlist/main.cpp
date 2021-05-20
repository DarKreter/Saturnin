#include "../_Headers/funkcje.h"

int main()
{
    fstream plik;
    string linia, tytul, wykonawca, link, ocena;
    srand(time(NULL));

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
    nazwa = lokacja + "playlist";
    plik.open(nazwa.c_str(),ios::in);
    getline(plik,linia);
    string uzytkownik = linia;
    ///---------------------------------------------------------------------------------------------------
    uzytkownik = "Daniel";
    ///---------------------------------------------------------------------------------------------------
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


    /// WYCZTANIE DO VECTOROW
    vector <string> nazwy,wykonawcy,linki,oceny,liczby_ocen;
    string nazwa_pliku;
    nazwa_pliku = "../muzyka/"+uzytkownik+"_playlist";
    //cout << nazwa_pliku << endl;
    plik.open(nazwa_pliku.c_str(),ios::in);
    int licznik = 0, liczmy = 0;
    while(getline(plik,linia))  ///Wpisanie pliku  pod vectory
    {
        //cout << "X\n";
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

    string odp;
    bool czy_gramy = false, losowo = false, powtarzaj = false, powtarzaj_jeden = false;
    int powtorz_jeden = -1;
    ///GLOWNA PETLA
    for(int i = 0;;)
    {
        if(losowo == true)   i = rand()% nazwy.size();
        if(powtarzaj == true && i >= nazwy.size())   i = 0;
        if(powtarzaj_jeden == true)     i = powtorz_jeden;


        system("cls");
        saturnin_mowi(kolor_saturnina);
        cout << "Gram playliste dla uzytkownika "
             << uzytkownik
             << endl
             << "W razie watpliwosci zalecam uzyc komendy \"pomoc\"\n"
             << "Tryb losowy: " << losowo << " Powtarzanie calosci: " << powtarzaj << " Powtarzanie jedengo: "<< powtarzaj_jeden
             //<< nazwy.size()<<endl
             << endl;
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        odp = modp(usp(odp),1,1,0);
        saturnin_mowi(kolor_saturnina);
        if(odp == "wyjdz")
        {
            zegnaj(kolor_saturnina,odp);
            getch();
            return EXIT_SUCCESS;
        }
        else if(odp == "pomoc")
        {
            cout << "Pomagam ";
            for(int i = 0;i<3;i++)
            {
                cout << "!";
                Sleep(700);
            }
            system("start ../pomoc_muzyka/pomoc_muzyka.exe");
        }
        else if(odp == "losowo")
        {
            losowo = (losowo == true ? false : true);
            cout << (losowo == true ? "Uruchamiam tryb losowy" : "Wylaczam tryb losowy"); kropki(700);
        }
        else if(odp == "powtarzaj")
        {
            powtarzaj = (powtarzaj == true ? false : true);
            cout << (powtarzaj == true ? "Uruchamiam tryb powtarzania" : "Wylaczam tryb powtarzania"); kropki(700);
        }
        else if(odp == "powtarzajjeden")
        {
            powtorz_jeden = i;
            powtarzaj_jeden = (powtarzaj_jeden == true ? false : true);
            cout << (powtarzaj_jeden == true ? "Uruchamiam tryb powtarzania jednej piosenki" : "Wylaczam tryb powtarzania jednej piosenki"); kropki(700);
        }
        else if(odp.substr(0,4) == "graj")
        {
            bool znalazlem = false;
            if(odp.length() > 4)
            {
                string help;
                string odp2 = odp.substr(4,odp.length()-4);
                for(int k = 0;k<nazwy.size();k++)
                {
                    help = modp(usp(nazwy[k],1,0,0,0,"",""),1,1,0);
                    int y = odp2.find(help);
                    if(y != 4294967295)
                    {
                        help = modp(usp(wykonawcy[k],1,0,0,0,"",""),1,1,0);
                        y = odp2.find(help);
                        if(y != 4294967295)
                        {
                            znalazlem = true;
                            nazwa_pliku = "start " + linki[k];
                            cout << "Puszczam " << nazwy[k]; kropki(700);
                            system(nazwa_pliku.c_str());
                            i++;
                        }
                    }

                }
                if(znalazlem == false) {cout << "Nie znalazlem podanej piosenki"; kropki(700);

                }
            }
            else
            {
                if(i >= nazwy.size())
                {
                    cout << "Skonczyly mi sie piosenki"; kropki(700);
                }
                else
                {
                    nazwa_pliku = "start " + linki[i];
                    cout << "Puszczam " << nazwy[i]; kropki(700);
                    system(nazwa_pliku.c_str());
                    i++;
                }
            }


        }
        else if(odp == "pomin")
        {
            i++; powtorz_jeden ++ ;
            if(i >= nazwy.size())
            {
                cout << "Skonczyly mi sie piosenki"; kropki(700);
            }
            else
            {
                nazwa_pliku = "start " + linki[i];
                cout << "Puszczam " << nazwy[i]; kropki(700);
                system(nazwa_pliku.c_str());
            }
        }
        else
        {
            cout << "Nie rozpoznana komenda";
            kropki(700);
        }


    }
    saturnin_mowi (kolor_saturnina);
    cout << "PLAYLIST" << endl;
    return 0;
}
