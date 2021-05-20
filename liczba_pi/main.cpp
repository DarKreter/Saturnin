#include "..\_Headers\funkcje.h"
#include "FunkcjePI.h"

int main(int argc, char*argv[])
{
    string granica_liczb[] = {"Nawet ja nie znam takiego przyblizenia!", "Nie oszukujmy sie nie potrzebujesz tak duzego przyblizenia do niczego!", "Tu jest moja granica, sprytny testerze!","Przykro mi tu juz nie siega moja wladza!",
                              "Twoje starania sa daremne, tam dalej sa same losowe cyfry, nie znajdziesz reguly..."};
    string blad [11] = {"To nie jest prawidlowa odpowiedz!", "Tym razem nie masz racji!", "Twoj tok rozumowania jest bledny!", "Pomyliles sie!", "To nie prawda!", "Chcialbym to uznac ale nie moge!", "Tym razem to nie prawda!",
                        "Jestes pewien ze to pamietasz, a nie strzelasz?", "Prosze przestac klikac losowe cyfry, to powazny szanujacy program dla profesjonalistow!", "Naprawde nie pamietasz?", "To jest proste, nie wierze ze sie tu pomyliles!"};
    string udalo_sie[12] = {"Gratulacje!", "Brawo!", "Jestem z ciebie dumny!", "Udalo ci sie!", "Jestem pod wrazeniem, ze dales rade!", "Od razu wiedzialem ze ci sie uda!", "To bylo proste kazdy by to zrobil!",
                            "\"CLAP\" \"CLAP\" \"CLAP\", niezle!", "Skladam hold gratulacyjny!", "Czekaj... Udalo ci sie ...? Znaczy GRATULACJE!", "Ty to masz pamiec!", "Nie oszukujmy sie, mogles wiecej!"};
    ///POBIERANIE LOKALIZACJI W CELU ZNALEZIENIA FOLDERU PLIKOW DOCELOWYCH
    fstream plik;
    srand(time(NULL));
    plik.open("../Pliki/lokalizacja",ios::in);  ///TE PLIKI NA C NIE ISTNIEJA NIE MARTW SIE I TAK WSZYSTKO SIE NA NICH DOBRZE ZAPISUJE :) po prostu ich nie znajdziesz recznie
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";

    ///KOLORY Z PLIKU
    string nazwa = lokacja + "kolory";
    int kolor_saturnina, nasz_kolor;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();

    ///JAKBY KTOS PODAL ODP W CENTRALNYM SATURNINIE
    string odp;
    string linia = "";
    argv++;
	for(int i = 1; i<argc; i++)
	{
		linia += *argv;
		argv++;
		if(i!=argc-1)linia+= " ";
	}
    if(linia!="")
    {
        odp = linia;
        goto dalej;
    }
    while(1415)
    {
        czy_wszystko_ok = true;
        saturnin_mowi(kolor_saturnina);
        cout << "Podaj do ktorego miejsca po przecinku mam wypisac liczbe pi: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        if(usp(modp(odp)) == "/wyjdz")
        {
            saturnin_mowi(kolor_saturnina);
            zegnaj(kolor_saturnina,odp);
            getch();
            return EXIT_SUCCESS;
        }
        dalej:
        ///ZABEZPIECZNIA CZY TO ABY TO BYLA LICZBA NATURALNA
        bool tak = false;
        odp = usp(ptok(odp),1);
        for(int i=0;i < odp.length();i++)
        {
            if(czy_to_liczba(odp.substr(i,1)) == false && odp.substr(i,1) != "." && odp.substr(i,1) != "-")
            {
                saturnin_mowi(kolor_saturnina);
                czy_wszystko_ok = false;
                sprawdzacz_bledow(112);
                getch();
                system("cls");
                tak = true;
                break;
            }
        }
        if(tak) continue;
        int licznik = 0;
        for(int i=0;i<odp.length();i++)
        {
            if(odp.substr(i,1) == ".")  licznik ++;
        }
        if(licznik == 1)
        {
            saturnin_mowi(kolor_saturnina);
            czy_wszystko_ok = false;
            sprawdzacz_bledow(69);
            getch();
            system("cls");
            continue;
        }
        else if(licznik > 1)
        {
            saturnin_mowi(kolor_saturnina);
            czy_wszystko_ok = false;
            sprawdzacz_bledow(112);
            getch();
            system("cls");
            continue;

        }
        long long miejsce = string_na_int(odp);
        if(miejsce <= 0)
        {
            saturnin_mowi(kolor_saturnina);
            czy_wszystko_ok = false;
            sprawdzacz_bledow(-69);
            getch();
            system("cls");
            continue;
        }
        if(miejsce > 100000)
        {
            int granica = rand() % 5;
            saturnin_mowi(kolor_saturnina);
            cout << granica_liczb[granica] << endl;
            getch();
            system("cls");
            continue;
        }
        ///KONIEC ZABEZPIECZEN
        short int gdzie_jest_znacznik = 1;
        while(true)
        {
            system("cls");
            saturnin_mowi(kolor_saturnina);
            cout << "Prosze wybrac tryb wypisywania:\n\n";
            saturnin_mowi( gdzie_jest_znacznik == 1 ? nasz_kolor : kolor_saturnina );
            cout << (gdzie_jest_znacznik == 1 ? "-" : " ") << "Tryb podstawowy\n";
            saturnin_mowi( gdzie_jest_znacznik == 2 ? nasz_kolor : kolor_saturnina );
            cout << (gdzie_jest_znacznik == 2 ? "-" : " ") << "Tryb treningowy";
            short int x = getch();
            if(x == 115) //S
            {
                gdzie_jest_znacznik = 2;
            }
            if(x == 119) //w
            {
                gdzie_jest_znacznik = 1;
            }
            if(x == 13) //enter
            {
                break;
            }
        }
        fstream pi;
        if(gdzie_jest_znacznik == 1)  ///TRYB PODSTAWOWY
        {
            wypisz_pi(miejsce, kolor_saturnina);
            cout << "\n\nCzy chcesz wyswietlic do innego miejsca ?\nTAK - wpisz TAK,\tNIE - cokolwiek innego\n";
            saturnin_mowi(nasz_kolor);
            getline(cin,linia);
            if(modp(usp(linia)) == "tak") {system("cls"); continue;}
            else while(true)    getch();
        }
        else ///TRYB TRENINGOWY
        {
            pi.open("../Pliki/przyblizenie_pi",ios::in);
            long long glupia_pi[miejsce+2] ;
            int licznikk = 0;
            while(getline(pi,linia))
            {
                if(licznikk*6 +1 > miejsce+2) break;
                glupia_pi[1 + licznikk * 6] = string_na_int(linia.substr(0,1));
                if(licznikk*6 +2 > miejsce+2) break;
                glupia_pi[2 + licznikk * 6] = string_na_int(linia.substr(1,1));
                if(licznikk*6 +3 > miejsce+2) break;
                glupia_pi[3 + licznikk * 6] = string_na_int(linia.substr(2,1));
                if(licznikk*6 +4 > miejsce+2) break;
                glupia_pi[4 + licznikk * 6] = string_na_int(linia.substr(3,1));
                if(licznikk*6 +5 > miejsce+2) break;
                glupia_pi[5 + licznikk * 6] = string_na_int(linia.substr(4,1));
                if(licznikk*6 +6 > miejsce+2) break;
                glupia_pi[6 + licznikk * 6] = string_na_int(linia.substr(5,1));
                licznikk ++;
            }
            pi.close();
            system("cls");
            int gdzie_jest_znacznik = 1, wiel_szostki = miejsce / 6 + 1;
            bool czy_dobrze = true;
            int x, y, licznik_bledow = 0;
            for(int i = 1; i<miejsce+1;i++)
            {
                wypisz_pi(i-1, kolor_saturnina);
                saturnin_mowi(kolor_saturnina);
                x = rand() % 11;
                if(czy_dobrze == false) cout << endl << blad[x];
                while(true) ///MENU
                {
                    rysowanie_calc(i/6 +2,gdzie_jest_znacznik,nasz_kolor, kolor_saturnina);
                    y = getch();
                    if(y == 13 && gdzie_jest_znacznik != 10 && gdzie_jest_znacznik != 12) break;
                    if(y == 115 && gdzie_jest_znacznik < 10) ///S
                    {
                        gdzie_jest_znacznik += 3;
                    }
                    if(y == 119 && gdzie_jest_znacznik > 3) ///W
                    {
                        gdzie_jest_znacznik -= 3;
                    }
                    if(y == 97 && gdzie_jest_znacznik % 3 != 1) ///A
                    {
                        gdzie_jest_znacznik --;
                    }
                    if(y == 100 && gdzie_jest_znacznik % 3 != 0) ///D
                    {
                        gdzie_jest_znacznik ++;
                    }
                }
                gdzie_jest_znacznik = (gdzie_jest_znacznik == 11) ? 0 : gdzie_jest_znacznik;
                if(gdzie_jest_znacznik == glupia_pi[i]) czy_dobrze = true;
                else {czy_dobrze = false; i--; licznik_bledow ++;}
                gdzie_jest_znacznik = (gdzie_jest_znacznik == 0) ? 11 : gdzie_jest_znacznik;
            }
            system("cls");
            wypisz_pi(miejsce, kolor_saturnina);
            nope:
            x = rand()% 12;
            if(x == 6 && miejsce > 100) goto nope;
            cout << "\n" << udalo_sie[x] << endl << "Ilosc zapamietanych miejsc: "<< miejsce<<"\tIlosc bledow: " << licznik_bledow;
            cout << "\n\nCzy chcesz sprobowac jeszcze raz?\nTAK - wpisz TAK,\tNIE - cokolwiek innego\n";
            saturnin_mowi(nasz_kolor);
            getline(cin,linia);
            if(modp(usp(linia)) == "tak") {system("cls"); continue;}
            else while(true)    getch();
        }

    }
}
