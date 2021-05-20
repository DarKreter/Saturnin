#include "..\_Headers\funkcje.h"
#include "Funkcje_statkow.h"

int main(int argc, char*argv[])
{
    fstream plik; string przeciwnik; bool nasz_kolor_bad = false;

    string oddanie_strzalu[15] = {"Kalibruje dzialo!", "Kalibruje celownik!", "OGNIA!!!", "FIRE!", "W imie wolnego Saturnina strzelac!", "Laduj ... celuj ... PAL"
                                , "Dzialo sie zacielo, ladowac drugie!", "CEEEEEL! PAAAAAL!", "Uruchamiam automatyczne celowanie, prosze czekac!", "Pociski Taktyczne ZIEMIA-POWIETRZNE  w drodze...",
                                "Tylko poczekajcie az tym oberwiecie...", "Akcja kryptonim \"Kaszalot\", rozpoczeta...", "Caly wszechswiat zamarl, w ogniu, pyle i popiole jakie wyzionely ze wszystkich luf naraz.",
                                "Poslijcie ich w objecia smierci!", "Po tym sie nie pozbieraja Kapitanie!"};
    string trafiony[14] = {"Trafilismy!","To byly dobre wspolrzedne chlopcy, trafilismy!", "Oberwali!", "Jeszcze pare takich strzalow i po nich!","Celny strzal!",
                        "Za kazdy taki nastepny strzal, stawiam kazdemu kolejke!", "To jest to!", "Brawo chlopaki, az tutaj czuje fale uderzeniowa!", "TAK JEST!",
                        "BUM BUM BUM TO JEST TO OW YEA", "BOOOOOOOOOOOOOOOOOOOOOOOM", "Potwierdzam oberwali!", "Czyste trafienie.", "*Wpisauje do pamietnika* Znowu trafilismy, a oni nadal dychaja, nie wiem ile tak jeszcze damy rade..."};
    string pudlo[13] = {"PUDLO!", "Nie trafilismy...", "Jak tak dalej pojdzie zaraz wycelujemy we wlasne okrety...", "Co to mialy byc?! Gdzie celujecie BARANY?!",
                    "*Kapitan zapisuje w notesie* \"Podali nam zle informacje, podejrzewam najgorsze...\"", "Tak ich nie pokonamy!", "Ale nas wpakowali w maliny tymi wspolrzednymi...",
                    "To teraz juz po nas...", "Nic sie nie stalo spokojnie!", "Bez paniki zaraz to odrobimy!", "Jeden niecelny strzal nic nie znaczy!", "Spokojnie, MOWILEM SPOKOJNIE GDZIE Z TYM NOZEM ?! AAAAAaaargh... [...] Poprzedni kapitan zmarl w niewyjasnonych okolicznosciach, godnie zajalem jego stanowisko",
                    "Nastepnym razem nas popamietacie!"};
    string trafili_nas[16] = {"Trafili nas!", "Oberwalismy...", "Czy tak wyglada smierc, brudna i zapluta ?", "A wiec tak umre...", "Trafili nam jeden okret kapitanie!",
                            "Ale maja skurczybyki cela...", "Kapitanie... dostalismy...", "Trafiony ale nie zatopiony! Jeszcze sie trzymamy!", "To jeszcze nie koniec!",
                            "Juz ja im zaraz pokaze...", "Pulkowniku prosze do nastepnego strzalu uzyc glowic nuklearnych, tak zeby sie nie podniesli!", "To jeszcze nie koniec!",
                            "Ledwie ryska, nieistone marynarzu.", "Zalata sie przed nastepna bitwa.", "Do wesela sie zagoi.", "Jak tak dalej pojdzie to po nas!"};
    string pudlo_nas[15] = {"Nie trafili!", "Haha! Spudlowali!", "Ladni unik Kapralu.", "Bog dal nam kolejna szanse, szykowac dziala!", "Teraz to im sie dostanie!",
                            "Taki czysty strzal i nie trafic!", "uff... spudlowali...", "Bylo blisko!", "Teraz im dokopiemy!", "Nie oszczedzac sie!", "PUDLO!",
                            "I wtedy Saturnin zatrzasl swiatem w posadach, a pocisk chybil o wlos...", "Smierc zajrzala marynarzom w oczy, lecz przeszla!",
                            "Zniszczenie przeszlo obok, tak blisko ze niektorym zwialo czapki z glow...", "Mroczny zniwiarz otarl sie o kazdego... Kazdy go poczul... Lecz ON nikogo nie zabral... CHWALA SATURNINOWI!!!"};
    string wygralismy[12] = {"Zwyciestwo!!!", "Wygralismy!", "Tak oto zwyciezylismy!", "Wygralismy bitwe, ale nie wojne. Cala naprzoood!",
                            "Istnie piekne zwyciestwo!", "Tak wygrywaja najlepsi!", "Zwyciestwo godne orderu.","Kolejna wygrana, zasluzylciscie na awans admirale!",
                            "Czy zwyciestwo zawsze tak wyglada, pelne krwi i morza wylanych lez...", "To zwyciestwo bylo nieuniknione!",
                            "I wtedy Wielki Saurnin zszedl do marynarzy i osobiscie pogratulowal zwyciestwa.", "HUREY! THATS IT! WE WIIIN!!!"};
    string przegralismy[12] ={"Przegralismy!", "Przegrana!", "Przegrales!","Przegralismy bitwe, ale nie wojne!", "Nastepnym razem nam sie uda!",
                            "Jedna jaskolka wiosny nie czyni, mimo przegranej bitwy, mozemy wygrac wojne!", "Tym razem nam sie nie udalo...", "I wtedy Saturnin zszedl na pobojowisko i zabral zagubione dusze zeglazy do Raju.",
                            "Na pobojowisku pozostaly jedynie szczatki okretow i unoszaca sie won spalenizny...", "Tym razem rowniez ponieslimy porazke...",
                            "Koniec jest bliski, smierc zabierze nas wszystkich!","To byl nasz ostatni okret, przegralismy..."};
    string zatopili_nm[8] = {"Stracilismy okret!","Trafili, zatopili!", "Juz po jednym z naszych okretow!", "Jeden z naszych padl!",
                            "Zatopili gooo, bedziemy nastepniii, ratunkuuuu...", "Wszyscy umrzemy, pomocyyy, nas zatopia nastepnyyych...",
                            "Nadzieja umiera ostatnia przyjmiemy ta ofiare i pomscimy ich!", "Nie poddamy sie! Bedziemy walczyc do ostatniego okretu!"};
    string zatopilismy[8]  {"Trafiony, zatopiony!", "Zatopilismy!", "HAHA! Ten sie juz nie podniesie! Zatopiony!", "Potwierdzam zatopienie kapitanie!",
                            "Poszedl na dno!", "Po tym strzale juz sie cwaniaki nie podniosa! Zatopiony!", " Tego sie nie dalo przezyc, musieli pojsc na dno! Jeden okret mniej!",
                            "TAK JEST ZATOPILISMY GO!"};

    int *wsk = 0;
    srand(time(NULL));
    ///TWORZYMY FOLDERY (GDYBY PRZYPADKIEM ICH NIE BYLO) W KTORYCH BEDA PLIKI Z GRY
    string folderyANDpliki = "../Statki/files"; /// TRZEBA TAK ZROBIC PONIEWAZ JESLI ODPALAMY TEN PROGRAM POPRZEZ KOMENDE SYSTEMOWA W INNYM POGRAMIE DOMYSLNA LOKALIZACJA JEST W FOLDERZE TAMTEGO PROGRAMU
    CreateDirectory(TEXT(folderyANDpliki.c_str()), NULL);
    folderyANDpliki += "/rozgrywka";
    CreateDirectory(TEXT(folderyANDpliki.c_str()), NULL);

    ///ZNAJDUJEMY LOKALIZACJE PLIKOW SATURNINA NA DYSKU
    string lokacja,linia;
    plik.open("../Pliki/lokalizacja",ios::in);
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    ///WCZYTUJEMY KOLORY

    folderyANDpliki = lokacja + "kolory";
    plik.open(folderyANDpliki.c_str(),ios::in);
    plik >> kolor_saturnina >>  nasz_kolor;
    plik.close();

    if(nasz_kolor == 1 || nasz_kolor == 15 || nasz_kolor == 16 || nasz_kolor == 18) nasz_kolor_bad = true;
    ///WCZYTUJEMY JAKIM UZYTKOWNIKIEM JESTESMY
    string uzytkownik;
    if(argc > 1)
    {
        argv++;
        uzytkownik = *argv;
    }
    else uzytkownik = "Gosc";
//    cout << uzytkownik << endl; getch();
    saturnin_mowi(kolor_saturnina);

    ///LISTA UZYTKOWNIKOW
    vector <string> inni_uzytkownicy;
    int k =0;
    plik.open("../Pliki/logowanie",ios::in);
    while(getline(plik, linia))  ///Bierzemy nazwy uzytkownikow i wsadzamy je do vectora
    {
        if(k%2 == 0&&linia != uzytkownik &&linia!="Gosc")    {inni_uzytkownicy.push_back(linia); } ///Co dwa sa nazwy
        k++;
    }
    plik.close();
    ///WCZYTUJEMY Z PLIKU CZY KTOS NAS WYZWAL
    bool zostalem_wyzwany, zaczyna;
    folderyANDpliki = lokacja + "statki_przeciwnik";
    plik.open(folderyANDpliki.c_str(),ios::in);
    getline(plik,linia);
    zostalem_wyzwany = (linia == "") ? false : true;
    plik.close();

    plik.open(folderyANDpliki.c_str(),ios::out);
    plik.close();
    string MAM_CIE = linia;

    vector <string> Dkol;
    plik.open("../Pliki/dostepne_kolory",ios::in);
    while(getline(plik, linia))  ///Bierzemy nazwy uzytkownikow i wsadzamy je do vectora
    {
        if(linia == "WITAJ") break;
        Dkol.push_back(linia);
    }
    plik.close();
    ///----
    bool chce_zmienic_kolor = false, wskaznik = 0;
    if(!nasz_kolor_bad)
    {
        while(true)
        {
            system("cls");
            saturnin_mowi(kolor_saturnina);
            cout<< "Czy chcesz uzywac w programie swojego koloru, zarejestrowanego przez naczelnego Saturnina ?\n";
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
            char czar = static_cast <char> (sprawdzacz_klawiszow());
            switch(czar)
            {
            case 97: case 65:
                if(wskaznik) wskaznik=0;
                break;
            case 100: case 68:
                if(!wskaznik) wskaznik =1;
                break;
            case 13:
                goto spadaj;
                break;
            }
        }
        spadaj:
        if(wskaznik) {chce_zmienic_kolor = true;}
    }
    ///----
    if(nasz_kolor_bad == true || chce_zmienic_kolor == true)
    {
        int licznik = 1;
        while(true)
        {

            system("cls");
            saturnin_mowi(kolor_saturnina);
            cout<< (nasz_kolor_bad == true ? "Niestety twoj kolor jest zarezerwowany na potrzeby gry!\n" : "Zgodnie z zyczeniem zmieniamy kolor!\n");
            ustaw_wskaznik(25  + 1 + (Dkol[licznik].length() / 2) , 2);
            cout<<"^\n";
            cout<< "Wybierz swoj nowy kolor: ";
            saturnin_mowi(licznik + 1);
            cout << Dkol[licznik];
            ustaw_wskaznik(25  + 1 + (Dkol[licznik].length() / 2), 4);
            saturnin_mowi(kolor_saturnina);
            cout<<"v\n";
            char czar = static_cast <char> (sprawdzacz_klawiszow());
            switch(czar)
            {
            case 119: case 87:
                if(licznik != 1)
                {
                    licznik --;
                    if(licznik == 15) licznik -=2;
                    if(licznik == 17)licznik --;
                }
                break;
            case 115: case 83:
                if(licznik != Dkol.size() - 1)
                {
                    licznik ++;
                    if(licznik == 14) licznik +=2;
                    if(licznik == 17)licznik ++;
                }
                break;
            case 13:
                goto ustawiony;
                break;
            }
        }
        ustawiony:
        nasz_kolor = licznik + 1;
        system("cls");
    }
    if(zostalem_wyzwany)    ///JESLI W PLIKU Z WYZWANIEM OKAZUJE SIE ZE ZOSTALISMY WYZWANI
    {
        przeciwnik = MAM_CIE;
        plik.open(folderyANDpliki.c_str(),ios::out);    ///CZYSCI PLIK Z WYZWANIEM
        plik.close();
        folderyANDpliki = "../Statki/files/Przyjecia/" + uzytkownik;
        plik.open(folderyANDpliki.c_str(),ios::out);    ///DAJE ZNAC ZE PRZYJAL
        int x = rand() % 2;
        zaczyna = x == 0 ? true : false;
        plik << x;
        plik.close();
        system("cls");
        saturnin_mowi(kolor_saturnina);
        cout << "Lacze sie z serwerem..."; ///PIEKNE
        Sleep(rand() % 10000);
        system("cls");
        cout <<"Konfiguruje rozgrywke...\n";
        Sleep (2000);
    }
    else
    {
        odrzucono:
        bool koniec = false; int x=0;
        while(!koniec)
        {
            system("cls");
            saturnin_mowi(kolor_saturnina);
            cout << "Wybierz uzytkownika ktorego chcesz wyzwac:\n";
            for(int i=0;i<inni_uzytkownicy.size();i++)
            {
                saturnin_mowi(x == i ? nasz_kolor : kolor_saturnina);
                cout <<(x == i ? "-" : " ") << inni_uzytkownicy[i] << endl;
            }
            char czar = static_cast <char> (sprawdzacz_klawiszow());
            switch(czar)
            {
            case 119: case 87:
                if(x != 0) x -- ;
                break;
            case 115: case 83:
                if(x != inni_uzytkownicy.size() - 1) x ++;;
                break;
            case 13:
                goto koniec;
                break;
            }

        }
        koniec :
        przeciwnik = inni_uzytkownicy[x];
        string name = "../Statki/files/Wyzwania/"+przeciwnik;
        plik.open(name.c_str(),ios::out);
        plik << uzytkownik;
        plik.close();

        ///OCZEKIWANIE NA PRZECIWNIKA
        saturnin_mowi(kolor_saturnina);
        folderyANDpliki = "../Statki/files/Przyjecia/" + przeciwnik;
        string line;
        system("cls");
        while(line != "1" && line != "0")
        {
            cout << "Prosze czekac";
            kropki(700);
            plik.open(folderyANDpliki.c_str(),ios::in);
            getline(plik,line);
            plik.close();
            zaczyna = (line == "1") ? true : false;
            system("cls");
            if(line == "NIE")
            {
                cout << przeciwnik << " odrzucil/a twoje wyzwanie!\n";
                plik.open(folderyANDpliki.c_str(),ios::out);
                plik.close();
                getch();
                goto odrzucono;
            }
        }
        plik.open(folderyANDpliki.c_str(),ios::out);
        plik.close();
    }
    ///USTAWIAMY STATKI

        string pole[3][10][10];
    /**
        0 - ROBOCZY DO USTAWIANIA
        1 - MY
        2 - WROG (mozesz)
    */
    //for(int i=0;i<10;i++)   for(int j=0;j<10;j++) pole[0][i][j] = "x";
    int x = 0, y =0;
    //rysowanie_planszy(x,y,pole[0]);
    system("cls");
    saturnin_mowi(kolor_saturnina);
    cout << "USTAWIANIE STATKOW!";  y++;
    saturnin_mowi(1);
    rysowanie_planszy(x,y,pole[1]);
    bool wszystkie_statki = false, koniec = false;
    string statki[7][6] ;
    /**
        JEST 7 STATKOW
        W 0 JEST ZAPAMIETANE CZY ZOSTAL USTAWIONY
        W 1 JEST ZAPAMIETANE GDZIE JEST DZIUB
        W 2 CZY RESZTA JEST SKIEROWANA W PRAWO CZY W DOL
        W 3 DLUGOSC STATKU
        W 4 CZY DZIUB JEST W GORE, DOL, PRAWO CZY LEWO
        W 5 CZY ZATOPIONY
    */
    statki[0][3] = "5";statki[1][3] = "4";statki[2][3] = "3";statki[3][3] = "3";statki[4][3] = "2";statki[5][3] = "2";statki[6][3] = "1";
    for(int i=0;i<7;i++)statki[i][0]="false";
    for(int i=0;i<7;i++)statki[i][5]="false";
    int gdzie_jest_wskaznik = 0;

    while(!koniec)
    {

            menu_statkow(x,y,gdzie_jest_wskaznik, wszystkie_statki == false ? false : true);
            unsigned char czar = getch();
            if((czar == 97||czar==65) && gdzie_jest_wskaznik != (wszystkie_statki == false ? 0 : -1))          gdzie_jest_wskaznik--;
            else if((czar == 100||czar==68) && gdzie_jest_wskaznik != 6)    gdzie_jest_wskaznik++;
            else if(czar == 0 || czar == 224)
            {
                czar = getch();
                if(czar == 75&&gdzie_jest_wskaznik!=(wszystkie_statki == false ? 0 : -1))          gdzie_jest_wskaznik--;
                else if(czar == 77&&gdzie_jest_wskaznik!=6)    gdzie_jest_wskaznik++;
            }
            else if(czar == 13)
            {
                if(gdzie_jest_wskaznik == -1)   {koniec = true; continue;}
                if(statki[gdzie_jest_wskaznik][0] == "false")    ///USTAWIAMY OD NOWA
                {
                    statki[gdzie_jest_wskaznik][1] = "00";
                    statki[gdzie_jest_wskaznik][2] = "pion";  ///podstawowe wartosci
                    statki[gdzie_jest_wskaznik][4] = "dol";
                    for(int i=0;i<string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                    {
                        pole[0][0][i] = "#"; ///ustawiamy statek gdzie trzeba
                    }
                    system("cls");
                    while(true) ///ruszanie sie statkiem po planszy TUTURU
                    {
                        ruch_po_planszy:
                        rysowanie_planszy(x,y,pole[1]);
                        PPONS(x,y,pole[0]);
                        czar = getch();
                        ///lewo
                        if((czar == 97||czar==65) && ((((statki[gdzie_jest_wskaznik][2] == "pion"||(statki[gdzie_jest_wskaznik][2] == "poziom" && statki[gdzie_jest_wskaznik][4] == "prawo")) &&(int)string_na_int(statki[gdzie_jest_wskaznik][1])/10)!=0 )
                                                      || (statki[gdzie_jest_wskaznik][2] == "poziom" && statki[gdzie_jest_wskaznik][4] == "lewo" && (((int)string_na_int(statki[gdzie_jest_wskaznik][1])/10) - ((int)string_na_int(statki[gdzie_jest_wskaznik][3])))!=-1))) ///lewo
                        {
                            lewo:
                            if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - 1]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "#";
                                statki[gdzie_jest_wskaznik][1] = int_na_string(string_na_int(statki[gdzie_jest_wskaznik][1]) - 10);
                            }
                            if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - 1]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "#";
                                statki[gdzie_jest_wskaznik][1] = int_na_string(string_na_int(statki[gdzie_jest_wskaznik][1]) - 10);
                            }
                        }
                        ///prawo
                        else if((czar == 100||czar==68) && ((((statki[gdzie_jest_wskaznik][2] == "pion"||(statki[gdzie_jest_wskaznik][2] == "poziom" && statki[gdzie_jest_wskaznik][4] == "lewo")) && ((int)string_na_int(statki[gdzie_jest_wskaznik][1])/10)!=9)) ||
                                                              (statki[gdzie_jest_wskaznik][2] == "poziom" && statki[gdzie_jest_wskaznik][4] == "prawo" && (((int)string_na_int(statki[gdzie_jest_wskaznik][1])/10) + ((int)string_na_int(statki[gdzie_jest_wskaznik][3])))!=10)))
                        {
                            prawo:
                            if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + 1]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "#";
                                statki[gdzie_jest_wskaznik][1] = int_na_string(string_na_int(statki[gdzie_jest_wskaznik][1]) + 10);
                            }
                            else if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + 1]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "#";
                                statki[gdzie_jest_wskaznik][1] = int_na_string(string_na_int(statki[gdzie_jest_wskaznik][1]) + 10);
                            }
                        }
                        ///gora
                        else if((czar == 119||czar==87) && (((statki[gdzie_jest_wskaznik][2] == "poziom"||(statki[gdzie_jest_wskaznik][2] == "pion"&&statki[gdzie_jest_wskaznik][4]=="dol")) &&(int)string_na_int(statki[gdzie_jest_wskaznik][1])%10!=0) ||
                                                            (statki[gdzie_jest_wskaznik][2] == "pion"&&statki[gdzie_jest_wskaznik][4] == "gora" && ((((int)string_na_int(statki[gdzie_jest_wskaznik][1])%10) - (int)string_na_int(statki[gdzie_jest_wskaznik][3]))!=-1))))
                         {
                            gora:
                            if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - 1] = "#";
                                statki[gdzie_jest_wskaznik][1] = int_na_string(string_na_int(statki[gdzie_jest_wskaznik][1]) - 1);
                            }
                            if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - 1] = "#";
                                statki[gdzie_jest_wskaznik][1] = int_na_string(string_na_int(statki[gdzie_jest_wskaznik][1]) - 1);
                            }
                        }
                        ///dol
                        else if((czar == 115||czar==83)&& (((statki[gdzie_jest_wskaznik][2] == "poziom"||(statki[gdzie_jest_wskaznik][2] == "pion"&&statki[gdzie_jest_wskaznik][4] == "gora" ))&&(int)string_na_int(statki[gdzie_jest_wskaznik][1])%10!=9) ||
                                                            (statki[gdzie_jest_wskaznik][2] == "pion"&&statki[gdzie_jest_wskaznik][4] == "dol" && ((int)string_na_int(statki[gdzie_jest_wskaznik][1])%10) + (int)string_na_int(statki[gdzie_jest_wskaznik][3])!=10)))
                        {
                            dol:
                            if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + 1] = "#";
                                statki[gdzie_jest_wskaznik][1] = int_na_string(string_na_int(statki[gdzie_jest_wskaznik][1]) + 1);
                            }
                            if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + 1] = "#";
                                statki[gdzie_jest_wskaznik][1] = int_na_string(string_na_int(statki[gdzie_jest_wskaznik][1]) + 1);
                            }
                        }
                        /// ZNAKI SPECJALNE
                        else if(czar == 0 || czar == 224)
                        {
                            czar=getch();
                            ///STRZALKI
                            if((czar == 75) && ((((statki[gdzie_jest_wskaznik][2] == "pion"||(statki[gdzie_jest_wskaznik][2] == "poziom" && statki[gdzie_jest_wskaznik][4] == "prawo")) &&(int)string_na_int(statki[gdzie_jest_wskaznik][1])/10)!=0 )
                                                      || (statki[gdzie_jest_wskaznik][2] == "poziom" && statki[gdzie_jest_wskaznik][4] == "lewo" && (((int)string_na_int(statki[gdzie_jest_wskaznik][1])/10) - ((int)string_na_int(statki[gdzie_jest_wskaznik][3])))!=-1))) goto lewo;
                            else if((czar == 77) && ((((statki[gdzie_jest_wskaznik][2] == "pion"||(statki[gdzie_jest_wskaznik][2] == "poziom" && statki[gdzie_jest_wskaznik][4] == "lewo")) && ((int)string_na_int(statki[gdzie_jest_wskaznik][1])/10)!=9)) ||
                                                              (statki[gdzie_jest_wskaznik][2] == "poziom" && statki[gdzie_jest_wskaznik][4] == "prawo" && (((int)string_na_int(statki[gdzie_jest_wskaznik][1])/10) + ((int)string_na_int(statki[gdzie_jest_wskaznik][3])))!=10))) goto prawo;
                            else if((czar == 72) && (((statki[gdzie_jest_wskaznik][2] == "poziom"||(statki[gdzie_jest_wskaznik][2] == "pion"&&statki[gdzie_jest_wskaznik][4]=="dol")) &&(int)string_na_int(statki[gdzie_jest_wskaznik][1])%10!=0) ||
                                                            (statki[gdzie_jest_wskaznik][2] == "pion"&&statki[gdzie_jest_wskaznik][4] == "gora" && ((((int)string_na_int(statki[gdzie_jest_wskaznik][1])%10) - (int)string_na_int(statki[gdzie_jest_wskaznik][3]))!=-1)))) goto gora;
                            else if((czar == 80)&& (((statki[gdzie_jest_wskaznik][2] == "poziom"||(statki[gdzie_jest_wskaznik][2] == "pion"&&statki[gdzie_jest_wskaznik][4] == "gora" ))&&(int)string_na_int(statki[gdzie_jest_wskaznik][1])%10!=9) ||
                                                            (statki[gdzie_jest_wskaznik][2] == "pion"&&statki[gdzie_jest_wskaznik][4] == "dol" && ((int)string_na_int(statki[gdzie_jest_wskaznik][1])%10) + (int)string_na_int(statki[gdzie_jest_wskaznik][3])!=10)))goto dol;

                            ///
                        }
                        ///obrot w prawo
                        else if((czar==101||czar==69))
                        {
                            if((statki[gdzie_jest_wskaznik][2] == "pion" && statki[gdzie_jest_wskaznik][4] == "dol") && (((int)string_na_int(statki[gdzie_jest_wskaznik][1]) /10) + ((int)string_na_int(statki[gdzie_jest_wskaznik][3]))< 11 ))
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) ]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) + i] = "";
                                statki[gdzie_jest_wskaznik][2] = "poziom"; statki[gdzie_jest_wskaznik][4] = "prawo";
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + i ]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)] = "#";
                            }
                            else if((statki[gdzie_jest_wskaznik][2] == "pion"&& statki[gdzie_jest_wskaznik][4] == "gora")&&(((int)string_na_int(statki[gdzie_jest_wskaznik][1])/10) - ((int)string_na_int(statki[gdzie_jest_wskaznik][3])) > -2))
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10)]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- i] = "";
                                statki[gdzie_jest_wskaznik][2] = "poziom"; statki[gdzie_jest_wskaznik][4] = "lewo";
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - i ]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)] = "#";
                            }
                            else if((statki[gdzie_jest_wskaznik][2] == "poziom"&& statki[gdzie_jest_wskaznik][4] == "lewo")&&(((int)string_na_int(statki[gdzie_jest_wskaznik][1])%10) + ((int)string_na_int(statki[gdzie_jest_wskaznik][3])) <11))
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - i]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)] = "";

                                statki[gdzie_jest_wskaznik][2] = "pion"; statki[gdzie_jest_wskaznik][4] = "dol";

                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10)]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) + i] = "#";
                            }
                            else if((statki[gdzie_jest_wskaznik][2] == "poziom"&& statki[gdzie_jest_wskaznik][4] == "prawo")&&(((int)string_na_int(statki[gdzie_jest_wskaznik][1])%10) - ((int)string_na_int(statki[gdzie_jest_wskaznik][3])) >-2))
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + i]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)] = "";

                                statki[gdzie_jest_wskaznik][2] = "pion"; statki[gdzie_jest_wskaznik][4] = "gora";

                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10)]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) - i] = "#";
                            }
                        }
                        ///obrot w lewo
                        else if((czar==113||czar==81))
                        {
                            if((statki[gdzie_jest_wskaznik][2] == "pion" && statki[gdzie_jest_wskaznik][4] == "dol")&&(((int)string_na_int(statki[gdzie_jest_wskaznik][1])/10) - ((int)string_na_int(statki[gdzie_jest_wskaznik][3])) > -2))
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) ]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) + i] = "";

                                statki[gdzie_jest_wskaznik][2] = "poziom"; statki[gdzie_jest_wskaznik][4] = "lewo";

                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - i ]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)] = "#";
                            }
                            else if((statki[gdzie_jest_wskaznik][2] == "pion"&& statki[gdzie_jest_wskaznik][4] == "gora") && (((int)string_na_int(statki[gdzie_jest_wskaznik][1]) /10) + ((int)string_na_int(statki[gdzie_jest_wskaznik][3]))< 11 ))
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10)]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- i] = " ";
                                statki[gdzie_jest_wskaznik][2] = "poziom"; statki[gdzie_jest_wskaznik][4] = "prawo";
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + i ]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)] = "#";
                            }
                            else if((statki[gdzie_jest_wskaznik][2] == "poziom"&& statki[gdzie_jest_wskaznik][4] == "lewo")&&(((int)string_na_int(statki[gdzie_jest_wskaznik][1])%10) - ((int)string_na_int(statki[gdzie_jest_wskaznik][3])) >-2))
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - i]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)] = "";

                                statki[gdzie_jest_wskaznik][2] = "pion"; statki[gdzie_jest_wskaznik][4] = "gora";

                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10)]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) - i] = "#";
                            }
                            else if((statki[gdzie_jest_wskaznik][2] == "poziom"&& statki[gdzie_jest_wskaznik][4] == "prawo")&&(((int)string_na_int(statki[gdzie_jest_wskaznik][1])%10) + ((int)string_na_int(statki[gdzie_jest_wskaznik][3])) <11))
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + i]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)] = "";

                                statki[gdzie_jest_wskaznik][2] = "pion"; statki[gdzie_jest_wskaznik][4] = "dol";

                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10)]
                                [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10) + i] = "#";
                            }
                        }
                        ///ESC
                        else if(czar == 27)
                        {
                            if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                            }
                            if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                            {
                                for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                    [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                            }
                            if(statki[0][0]=="false"||statki[1][0]=="false"||statki[2][0]=="false"||statki[3][0]=="false"||statki[4][0]=="false"||statki[5][0]=="false"||statki[6][0]=="false")   wszystkie_statki = false;///TUTAJ DODAC OPJCE WYJSCIA W MENU WYBORU STATKOW (TRUDNE)
                                system("cls");
                                rysowanie_planszy(x,y,pole[1]);
                                break;
                        }
                        ///ENTER
                        else if(czar == 13) ///DODAC ZABEZPIECZENIA STAWIANIA
                        {
                            bool wolne = true;
                           if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        if(pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] == "#" || pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] == "`") wolne = false;

                                }
                                if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        if(pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] == "`"||pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] == "#")wolne = false;

                                }
                            if(wolne)
                            {
                                ///USUNIECIE
                                if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = " ";

                                }
                                if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = " ";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                }
                                ///DODANIE DO LISTY
                                if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "#";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                }
                                if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "#";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                }
                                ///DODANIE '`' JAKO ZNAKOW OBOK STATKOW TAM TEZ NIE MOZES STAWIAC
                                if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                                {
                                    for(int i=-1;i<=(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        if((int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : 1) >=0 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : 1) <= 9 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : 1) >= 0 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : 1) <= 9)
                                        pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : 1)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : 1)] = "`";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                    if((int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? -1 : 0) >=0 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? -1 : 0) <= 9 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? -1 : 0) >= 0 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? -1 : 0) <= 9)
                                    pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? -1 : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? -1 : 0)] = "`";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                        if((int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0) >=0 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0) <= 9 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0)  >= 0 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0) <= 9)
                                    pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0)] = "`";

                                    for(int i=-1;i<=(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        if((int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : -1) >=0 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : -1) <= 9&&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : -1 ) >= 0 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : -1 ) <= 9)
                                        pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : -1)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : -1 )] = "`";
                                }
                                if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                                {
                                    for(int i=-1;i<=(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        if((int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : 1) >=0 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : 1)<= 9 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : 1) >=0 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : 1) <= 9)
                                        pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : 1)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : 1)] = "`";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                    if((int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? -1 : 0) >=0 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? -1 : 0)<=9 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? -1 : 0) >=0 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? -1 : 0)<=9)
                                    pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? -1 : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? -1 : 0)] = "`";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                    if((int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) -(statki[gdzie_jest_wskaznik][2] == "poziom" ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0) >=0 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) -(statki[gdzie_jest_wskaznik][2] == "poziom" ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0) <= 9 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0) >= 0 &&
                                       (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0) <=9)
                                    pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) -(statki[gdzie_jest_wskaznik][2] == "poziom" ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0)] = "`";

                                    for(int i=-1;i<=(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        if((int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : -1) >=0 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : -1) <=9&&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : -1) >= 0 &&
                                           (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : -1) <= 9)
                                        pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : -1)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : -1)] = "`";

                                }
                                ///POLA WOKOL STATKOW
                                statki[gdzie_jest_wskaznik][0] = "true";
                                system("cls");
                                rysowanie_planszy(x,y,pole[1]);
                                if(statki[0][0]=="true"&&statki[1][0]=="true"&&statki[2][0]=="true"&&statki[3][0]=="true"&&statki[4][0]=="true"&&statki[5][0]=="true"&&statki[6][0]=="true")   wszystkie_statki = true;
                                break;
                            }
                        }

                    }
                    continue;
                }
                else if(statki[gdzie_jest_wskaznik][0] == "true")///MODYFIKUJEMY USTAWIONY STATEK
                {
                    statki[gdzie_jest_wskaznik][0] = "false";
                    ///USUNIECIE STATKU I ZNAKOW WOKOL NIEGO Z POLE[1]
                                if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = " ";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                }
                                if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        pole[1][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = " ";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                }
                                if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                                {
                                    int jeden,dwa;
                                    for(int i=-1;i<=(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    {
                                         dwa = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) + ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : 1);
                                         jeden = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : 1);
                                        if(jeden >=0 && jeden <= 9 && dwa >= 0 && dwa <= 9 &&
                                           ( jeden - 1 < 0 || pole[1][jeden - 1][dwa] != "#")&& ( jeden + 1 > 9 || pole[1][jeden + 1][dwa] != "#")
                                           && ( dwa + 1 > 9 || pole[1][jeden][dwa + 1] != "#") && ( dwa - 1 < 0 || pole[1][jeden][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa + 1 > 9 || pole[1][jeden + 1][dwa + 1] != "#") && ( jeden -1 < 0 || dwa -1 < 0 || pole[1][jeden - 1][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa - 1 < 0 || pole[1][jeden + 1][dwa - 1] != "#")&& ( jeden - 1 < 0 || dwa + 1 > 9 || pole[1][jeden - 1][dwa + 1] != "#"))

                                        pole[1][jeden][dwa] = " ";
                                    }


                                     dwa = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? -1 : 0);
                                         jeden = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? -1 : 0);

                                   if(jeden >=0 && jeden <= 9 && dwa >= 0 && dwa <= 9 &&
                                           ( jeden - 1 < 0 || pole[1][jeden - 1][dwa] != "#")&& ( jeden + 1 > 9 || pole[1][jeden + 1][dwa] != "#")
                                           && ( dwa + 1 > 9 || pole[1][jeden][dwa + 1] != "#") && ( dwa - 1 < 0 || pole[1][jeden][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa + 1 > 9 || pole[1][jeden + 1][dwa + 1] != "#") && ( jeden -1 < 0 || dwa -1 < 0 || pole[1][jeden - 1][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa - 1 < 0 || pole[1][jeden + 1][dwa - 1] != "#")&& ( jeden - 1 < 0 || dwa + 1 > 9 || pole[1][jeden - 1][dwa + 1] != "#"))

                                        pole[1][jeden][dwa] = " ";


                                        dwa = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0);
                                        jeden = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0);

                                        if(jeden >=0 && jeden <= 9 && dwa >= 0 && dwa <= 9 &&
                                           ( jeden - 1 < 0 || pole[1][jeden - 1][dwa] != "#")&& ( jeden + 1 > 9 || pole[1][jeden + 1][dwa] != "#")
                                           && ( dwa + 1 > 9 || pole[1][jeden][dwa + 1] != "#") && ( dwa - 1 < 0 || pole[1][jeden][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa + 1 > 9 || pole[1][jeden + 1][dwa + 1] != "#") && ( jeden -1 < 0 || dwa -1 < 0 || pole[1][jeden - 1][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa - 1 < 0 || pole[1][jeden + 1][dwa - 1] != "#")&& ( jeden - 1 < 0 || dwa + 1 > 9 || pole[1][jeden - 1][dwa + 1] != "#"))

                                        pole[1][jeden][dwa] = " ";


                                    for(int i=-1;i<=(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    {
                                         dwa =
                                         (int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) +
                                         ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : -1 ) ;
                                         jeden = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : -1);
                                        if(jeden >=0 && jeden <= 9 && dwa >= 0 && dwa <= 9 &&
                                           ( jeden - 1 < 0 || pole[1][jeden - 1][dwa] != "#")&& ( jeden + 1 > 9 || pole[1][jeden + 1][dwa] != "#")
                                           && ( dwa + 1 > 9 || pole[1][jeden][dwa + 1] != "#") && ( dwa - 1 < 0 || pole[1][jeden][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa + 1 > 9 || pole[1][jeden + 1][dwa + 1] != "#") && ( jeden -1 < 0 || dwa -1 < 0 || pole[1][jeden - 1][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa - 1 < 0 || pole[1][jeden + 1][dwa - 1] != "#")&& ( jeden - 1 < 0 || dwa + 1 > 9 || pole[1][jeden - 1][dwa + 1] != "#"))

                                        pole[1][jeden][dwa] = " ";
                                    }


                                }
                                if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                                {
                                    int jeden,dwa;
                                    for(int i=-1;i<=(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    {
                                         dwa = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : 1);
                                         jeden = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : 1);
                                        if(jeden >=0 && jeden <= 9 && dwa >= 0 && dwa <= 9 &&
                                           ( jeden - 1 < 0 || pole[1][jeden - 1][dwa] != "#")&& ( jeden + 1 > 9 || pole[1][jeden + 1][dwa] != "#")
                                           && ( dwa + 1 > 9 || pole[1][jeden][dwa + 1] != "#") && ( dwa - 1 < 0 || pole[1][jeden][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa + 1 > 9 || pole[1][jeden + 1][dwa + 1] != "#") && ( jeden -1 < 0 || dwa -1 < 0 || pole[1][jeden - 1][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa - 1 < 0 || pole[1][jeden + 1][dwa - 1] != "#")&& ( jeden - 1 < 0 || dwa + 1 > 9 || pole[1][jeden - 1][dwa + 1] != "#"))

                                        pole[1][jeden][dwa] = " ";
                                    }


                                     dwa = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? -1 : 0);
                                         jeden = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? -1 : 0);

                                   if(jeden >=0 && jeden <= 9 && dwa >= 0 && dwa <= 9 &&
                                           ( jeden - 1 < 0 || pole[1][jeden - 1][dwa] != "#")&& ( jeden + 1 > 9 || pole[1][jeden + 1][dwa] != "#")
                                           && ( dwa + 1 > 9 || pole[1][jeden][dwa + 1] != "#") && ( dwa - 1 < 0 || pole[1][jeden][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa + 1 > 9 || pole[1][jeden + 1][dwa + 1] != "#") && ( jeden -1 < 0 || dwa -1 < 0 || pole[1][jeden - 1][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa - 1 < 0 || pole[1][jeden + 1][dwa - 1] != "#")&& ( jeden - 1 < 0 || dwa + 1 > 9 || pole[1][jeden - 1][dwa + 1] != "#"))

                                        pole[1][jeden][dwa] = " ";


                                        dwa = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0);
                                        jeden = (int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) -(statki[gdzie_jest_wskaznik][2] == "poziom" ? (int)string_na_int(statki[gdzie_jest_wskaznik][3]) : 0);

                                        if(jeden >=0 && jeden <= 9 && dwa >= 0 && dwa <= 9 &&
                                           ( jeden - 1 < 0 || pole[1][jeden - 1][dwa] != "#")&& ( jeden + 1 > 9 || pole[1][jeden + 1][dwa] != "#")
                                           && ( dwa + 1 > 9 || pole[1][jeden][dwa + 1] != "#") && ( dwa - 1 < 0 || pole[1][jeden][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa + 1 > 9 || pole[1][jeden + 1][dwa + 1] != "#") && ( jeden -1 < 0 || dwa -1 < 0 || pole[1][jeden - 1][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa - 1 < 0 || pole[1][jeden + 1][dwa - 1] != "#")&& ( jeden - 1 < 0 || dwa + 1 > 9 || pole[1][jeden - 1][dwa + 1] != "#"))

                                        pole[1][jeden][dwa] = " ";


                                    for(int i=-1;i<=(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                    {
                                         dwa =(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0) - ((statki[gdzie_jest_wskaznik][2] == "pion") ? 0 : -1) ;
                                         jeden =(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? 0 : -1);
                                        if(jeden >=0 && jeden <= 9 && dwa >= 0 && dwa <= 9 &&
                                           ( jeden - 1 < 0 || pole[1][jeden - 1][dwa] != "#")&& ( jeden + 1 > 9 || pole[1][jeden + 1][dwa] != "#")
                                           && ( dwa + 1 > 9 || pole[1][jeden][dwa + 1] != "#") && ( dwa - 1 < 0 || pole[1][jeden][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa + 1 > 9 || pole[1][jeden + 1][dwa + 1] != "#") && ( jeden -1 < 0 || dwa -1 < 0 || pole[1][jeden - 1][dwa - 1] != "#")
                                           && ( jeden + 1 > 9 || dwa - 1 < 0 || pole[1][jeden + 1][dwa - 1] != "#")&& ( jeden - 1 < 0 || dwa + 1 > 9 || pole[1][jeden - 1][dwa + 1] != "#"))

                                        pole[1][jeden][dwa] = " ";
                                    }

                                }

                                ///DODANIE DO POLE[0]
                                if(statki[gdzie_jest_wskaznik][4] == "prawo" || statki[gdzie_jest_wskaznik][4] == "dol")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) + (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)+ ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "#";

                                }
                                if(statki[gdzie_jest_wskaznik][4] == "lewo" || statki[gdzie_jest_wskaznik][4] == "gora")
                                {
                                    for(int i=0;i<(int)string_na_int(statki[gdzie_jest_wskaznik][3]);i++)
                                        pole[0][(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) / 10) - (statki[gdzie_jest_wskaznik][2] == "poziom" ? i : 0)]
                                        [(int)((int)string_na_int(statki[gdzie_jest_wskaznik][1]) % 10)- ((statki[gdzie_jest_wskaznik][2] == "pion") ? i : 0)] = "#";   ///NAWET PO NAPISANIU NIE WIEM O CO CHODZI

                                }
                                goto ruch_po_planszy;


                }

            }
    }





    ///KONIEC USTAWIANIA STATKOW
    ///WYSLANIE ZE JUZ USTAWILISMY
    folderyANDpliki = "../Statki/files/Ustawienia/" + uzytkownik;
    plik.open(folderyANDpliki.c_str(), ios :: out);
    plik << "Ustawilem";
    plik.close();
    //cout <<  folderyANDpliki << endl; getch();
    folderyANDpliki = "../Statki/files/Ustawienia/" + przeciwnik;
    system("cls");
    saturnin_mowi(kolor_saturnina);
        cout << "Przeciwnik nadal ustawia!\nProsze czekac!\n";
        //cout <<  folderyANDpliki << endl;
    while(linia != "Ustawilem")
    {
        plik.open(folderyANDpliki.c_str(), ios::out | ios::app);
        plik.close();
        plik.open(folderyANDpliki.c_str(),ios::in);
        getline(plik,linia);
        plik.close();
    }
    plik.open(folderyANDpliki.c_str(), ios::out);
        plik.close();
    //cout <<  folderyANDpliki << endl; getch();
    ///CZYSZCZE POLE[0]
        for(int i = 0;i <10;i ++)
            for(int j = 0; j < 10; j++)
                pole[0][i][j] = "";
        for(int i = 0;i <10;i ++)
            for(int j = 0; j < 10; j++)
                pole[2][i][j] = "?";
    ///GRAMY
    system("cls");
    string UP = "";
    folderyANDpliki = "../Statki/files/Rozgrywka/" + uzytkownik + "-" + przeciwnik;
    plik.open(folderyANDpliki.c_str(),ios::out);
    plik.close();
    folderyANDpliki = "../Statki/files/Rozgrywka/" + uzytkownik + "_" + przeciwnik;
    plik.open(folderyANDpliki.c_str(),ios::out);
    plik.close();
    folderyANDpliki = "../Statki/files/Rozgrywka/" + przeciwnik + "_" + uzytkownik;
    plik.open(folderyANDpliki.c_str(),ios::out);
    plik.close();
    folderyANDpliki = "../Statki/files/Rozgrywka/" + przeciwnik + "-" + uzytkownik;
    plik.open(folderyANDpliki.c_str(),ios::out);
    plik.close();
    for(int i =( zaczyna == true ? 0 : 1);;i++)
    {
        if(i%2==0) /// STRZELAMY
        {
            trafileem:
            UP += "TWOJ RUCH";
            y=1;x=1;
            ustaw_wskaznik(1,1);
             for(int i=0;i<90;i++)   UP+= " ";
             saturnin_mowi(kolor_saturnina);
             czyszczenie(1,1);
            cout << UP;
            y+=2;
            rysowanie_planszy(x,y,pole[1],1);
            x += 25;
            rysowanie_planszy(x,y,pole[2]);
            char czar;  bool strzelilem = false;
            pole[0][0][0] = pole[2][0][0];
            int celownik[2] = {0,0};
            while(!strzelilem)
            {

                rysowanie_planszy(x,y,pole[2]);
                PPONS(x,y,pole[0]);
                czar = static_cast <char> (sprawdzacz_klawiszow());
                ///lewo
                if((czar == 97||czar==65) && celownik[0] - 1 != -1)
                        {
                            left:
                            pole[0][celownik[0]][celownik[1]] = "";
                            celownik[0] --;
                            pole[0][celownik[0]][celownik[1]] = pole[2][celownik[0]][celownik[1]] ;
                        }
                        ///prawo
                        else if((czar == 100||czar==68) && celownik[0] + 1 != 10)
                        {
                            right:
                            pole[0][celownik[0]][celownik[1]] = "";
                            celownik[0] ++;
                            pole[0][celownik[0]][celownik[1]] = pole[2][celownik[0]][celownik[1]] ;
                        }
                        ///gora
                        else if((czar == 119||czar==87) && celownik[1] - 1 != -1)
                         {
                            up:
                            pole[0][celownik[0]][celownik[1]] = "";
                            celownik[1] --;
                            pole[0][celownik[0]][celownik[1]] = pole[2][celownik[0]][celownik[1]] ;
                        }
                        ///dol
                        else if((czar == 115||czar==83)&& celownik[1] + 1 != 10)
                        {
                            down:
                            pole[0][celownik[0]][celownik[1]] = "";
                            celownik[1] ++;
                            pole[0][celownik[0]][celownik[1]] = pole[2][celownik[0]][celownik[1]] ;
                        }
                        /// ZNAKI SPECJALNE
                        else if(czar == 0 || czar == 224)   ///JUZ
                        {
                            czar=getch();
                            ///STRZALKI
                            if((czar == 75) && celownik[0] - 1 != -1) goto left;
                            else if((czar == 77) && celownik[0] + 1 != 10) goto right;
                            else if((czar == 72) && celownik[1] - 1 != -1) goto up;
                            else if((czar == 80)&& celownik[1] + 1 != 10) goto down;

                            ///
                        }
                        ///ENTER
                        else if(czar == 13 && pole[2][celownik[0]][celownik[1]] == "?")
                        {
                            pole[0][celownik[0]][celownik[1]] = "";
                            folderyANDpliki = "../Statki/files/Rozgrywka/" + uzytkownik + "_" + przeciwnik;
                            plik.open(folderyANDpliki.c_str(), ios :: out);
                            plik << celownik[0] << endl << celownik[1];
                            plik.close();

                            system("cls");
                            ustaw_wskaznik(1,1);
                            x= 1; y = 1;
                            int los = rand() % 15;
                            UP = oddanie_strzalu[los];
                            saturnin_mowi(kolor_saturnina);
                            czyszczenie(1,1);
                            cout << UP;
                            y+=2;
                            rysowanie_planszy(x,y,pole[1],1);
                            x += 25;
                            rysowanie_planszy(x,y,pole[2]);

                            folderyANDpliki = "../Statki/files/Rozgrywka/" + przeciwnik + "-" + uzytkownik;
                            string linia="";
                             while(linia == "")
                            {
                                plik.open(folderyANDpliki.c_str(), ios::out | ios::app);
                                plik.close();
                                plik.open(folderyANDpliki.c_str(),ios::in);
                                getline(plik,linia);
                                plik.close();
                            }
                            plik.open(folderyANDpliki.c_str(), ios::out);
                            plik.close();

                            if(linia == "O")
                            {
                                pole[2][celownik[0]][celownik[1]] = linia;
                                los = rand()%13;
                                UP = pudlo[los];
                                UP += "\n";
                                strzelilem = true;
                            }
                            else if(linia == "X")
                            {
                                pole[2][celownik[0]][celownik[1]] = linia;
                                los = rand()%14;
                                UP = trafiony[los];
                                UP += "\n";
                                goto trafileem;
                            }
                            else if(linia == "x")
                            {
                                pole[2][celownik[0]][celownik[1]] = "X";
                                wsk = new int;
                                *wsk = rand() % 8;
                                UP = zatopilismy[(*wsk)];
                                delete wsk; wsk = Pusty_adres;
                                UP += "\n";
                                goto trafileem;
                            }
                            else if(linia == "ILOSE")
                            {
                                pole[2][celownik[0]][celownik[1]] = "X";
                                ///PRZESLANIE DRUGIEMU GRACZOWI GDZIE BYLY NASZE STATKI
                                folderyANDpliki = "../Statki/files/END/"+przeciwnik;
                                fstream wspolrzedne;
                                wspolrzedne.open(folderyANDpliki.c_str(), ios::out);
                                for(int k=0;k<10;k++)
                                {
                                    for(int l = 0; l <10; l++)
                                    {
                                        if(pole[1][k][l] == "#")
                                        {
                                            wspolrzedne << k << l << endl;
                                        }
                                    }
                                }
                                wspolrzedne.close();
                                ///KONIEC PRZESYLANIA GDZIE BYLY NASZE STATKI
                                system("cls");
                                y=1;x=1;
                                ustaw_wskaznik(1,1);
                                for(int i=0;i<90;i++)   UP+= " ";
                                saturnin_mowi(kolor_saturnina);
                                czyszczenie(1,1);
                                wsk = new int;
                                *wsk = rand() % 12;
                                cout << wygralismy[(*wsk)];
                                delete wsk;
                                wsk = Pusty_adres;
                                y+=2;
                                rysowanie_planszy(x,y,pole[1],1);
                                x += 25;
                                rysowanie_planszy(x,y,pole[2]);
                                getch();    getch();    getch();
                                return 0;
                            }
                            else UP = "Wystapil nieoczekiwany blad!";


                        }


            }

        }
        else    ///CZEKAMY NA STRZAL WROGA
        {
            jednak_trafil:
            system("cls");
            y=1;x=1;
            UP += "RUCH PRZECIWNIKA";
            ustaw_wskaznik(1,1);
            for(int i=0;i<90;i++)   UP+= " ";
            saturnin_mowi(kolor_saturnina);
            czyszczenie(1,1);
            cout << UP;
            y+=2;
            rysowanie_planszy(x,y,pole[1],1);
            x += 25;
            rysowanie_planszy(x,y,pole[2]);

            int strzal[2];
            folderyANDpliki = "../Statki/files/Rozgrywka/" + przeciwnik + "_" + uzytkownik;
            string linia = "";
            while(!czy_to_liczba(linia))
            {
                plik.open(folderyANDpliki.c_str(), ios::out | ios::app);
                plik.close();
                plik.open(folderyANDpliki.c_str(),ios::in);
                getline(plik,linia);
                plik.close();
            }
            plik.open(folderyANDpliki.c_str(),ios::in);
            getline(plik,linia);
            strzal[0] = static_cast <int> (string_na_int(linia));
            getline(plik,linia);
            strzal[1] = static_cast <int> (string_na_int(linia));
            plik.close();
            plik.open(folderyANDpliki.c_str(), ios::out);
            plik.close();

            folderyANDpliki = "../Statki/files/Rozgrywka/" + uzytkownik + "-" + przeciwnik;
            plik.open(folderyANDpliki.c_str(), ios :: out);
            if(pole[1][strzal[0]][strzal[1]] == "#")
            {
                pole[1][strzal[0]][strzal[1]] = "X";
                bool zatopil = false;
                if(zatopiony(statki,pole[1]))
                {
                    zatopil = true;
                    if(przegralem(statki))
                    {
                        plik.close();
                        folderyANDpliki = "../Statki/files/Rozgrywka/" + uzytkownik + "-" + przeciwnik;
                        plik.open(folderyANDpliki.c_str(), ios :: out);
                        plik << "ILOSE";
                        plik.close();
                        ///czekanie na przeslanie plikow od przeciwnika gdzie mial nietrafione jeszcze okrety
                        folderyANDpliki = "../Statki/files/END/"+uzytkownik;
                        fstream wspolrzedne;
                        string x;
                        while(x == "")
                        {
                            wspolrzedne.open(folderyANDpliki.c_str(), ios::in);
                            getline(wspolrzedne,x);
                            wspolrzedne.close();
                        }


                        wspolrzedne.open(folderyANDpliki.c_str(), ios::in);
                        while(getline(wspolrzedne,x))
                        {
                            if(linia != "")pole[2][atoi((x.substr(0,1)).c_str())][atoi((x.substr(1,1)).c_str())] = "#";
                        }
                        wspolrzedne.close();
                        wspolrzedne.open(folderyANDpliki.c_str(), ios::out);
                        wspolrzedne.close();
                        ///mamy nadpisane wychdozimy
                        goto przegraleem;
                    }
                    else plik << "x" ;
                }
                else plik << pole[1][strzal[0]][strzal[1]] ;
                plik.close();
                if(zatopil)
                {
                    //int los = rand() % 16;
                    //UP = trafili_nas[los];
                    wsk = new int; *wsk = rand() % 8;
                    UP = zatopili_nm[(*wsk)];
                    delete wsk; wsk = Pusty_adres;
                }
                else
                {
                    int los = rand() % 16;
                    UP = trafili_nas[los];
                }
                UP += "\n";
                goto jednak_trafil;
            }

            else
            {
                int los = rand() % 15;
                UP = pudlo_nas[los];
                UP += "\n";
                pole[1][strzal[0]][strzal[1]] = "O";
                plik << pole[1][strzal[0]][strzal[1]] ;
                plik.close();
            }
        }
    }
    przegraleem:
    system("cls");

    y=1;x=1;
    ustaw_wskaznik(1,1);
    for(int i=0;i<90;i++)   UP+= " ";
    saturnin_mowi(kolor_saturnina);
    czyszczenie(1,1);

    wsk = new int;
    *wsk = rand() % 12;
    saturnin_mowi(kolor_saturnina);
    cout << przegralismy[(*wsk)];
    delete wsk;
    wsk = Pusty_adres;
    y+=2;
    rysowanie_planszy(x,y,pole[1],1);
    x += 25;
    rysowanie_planszy(x,y,pole[2],0,1);

    getch();    getch();    getch();
    return 0;

}


