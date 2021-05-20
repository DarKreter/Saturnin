
#include "funkcje.h"

using namespace std;

bool czy_wszystko_ok = true;
list <long double> lista_globalna;
int kolor_saturnina, nasz_kolor, kolor_przeciwnika;

nullptr_t Pusty_adres = nullptr; /**oznacza wskaznik ktory na nic nie wskazuje osobny typ przyjmujacy tylko jedna wartosc*/

int sprawdzacz_klawiszow(void){
        unsigned char znak = getch();
        if(znak==224){
            switch(getch()){
                case 75:
                    return 97;
                break;
                case 77:
                    return 100;
                break;
                case 72:
                    return 119;
                break;
                case 80:
                    return 115;
                break;
            }
        }
        else return znak;

}

bool czy_otwarty(fstream plik){
    if(plik.good()== false){
        czy_wszystko_ok= false;
        cerr<<"Nie Mozna odczytac Pliku"<<endl;
        return false;
    }
    return true;
}

void skok(unsigned long long liczba,string napis,string co_wsadzic){
    /**
        ARGUMENTY DOMNIEMANE:
        string co_wsadzic = " "
    */
    unsigned long long dlugosc=napis.length();
    if(liczba<dlugosc){
        cerr<<" Error w funkcji skok <napis jest wiekszy od wykonanego skoku> ";
        return;
    }
    for(int i=1;i<=liczba-dlugosc;i++){
        cout<<co_wsadzic;
    }
return;
}

bool czy_to_liczba(string cyfra,bool czy_wliczac_minusy_i_kropki){
    /**
        ARGUMENTY DOMNIEMANE:
        bool czy_wliczac_minusy_i_kropki = false
    */
    if(cyfra=="0"||cyfra=="1"||cyfra=="2"||cyfra=="3"||cyfra=="4"||
        cyfra=="5"||cyfra=="6"||cyfra=="7"||cyfra=="8"||cyfra=="9"){
        return true;
    }
    if(czy_wliczac_minusy_i_kropki){
        if( cyfra=="." || cyfra=="-" ) return true;
    }
    else return false;
}

string modp(string napis, bool bigtosmall, bool plznaki, bool poliznaki, bool revers){
    /**
        napis -> string na ktorym beda przeprowadzne modyfikacje
        bigtosmall -> czy zmieniac Wielkie litery na male
        plznaki -> czy zmieniac polskie znaki na zwykle
        poliznaki -> czy usuwac powielone znaki np  "eheeeej" -> "ehej"
        revers -> czy odwrocic napis (od tylu)
    */
    /**
        ARGUMENTY DOMNIEMANE:
        bool bigtosmall = 1
        bool plznaki = 1
        bool poliznaki = 1
        bool revers = 0
    */
    fstream wyjatki;
    string zabezpieczenie="",linia;
    if(poliznaki == 1)
    {
        string pomoc = modp(napis,1,1,0);
        fstream plik;
        plik.open("../Pliki/wyjatki_wyjatkow_modp",ios::out|ios::app);
        plik.close();
        plik.open("../Pliki/wyjatki_wyjatkow_modp",ios::in);
        string linia;
        while(getline(plik,linia))
        {
            if(linia == pomoc)  {napis = pomoc; goto tu;}
        }
        plik.close();
    }

    char x;
    for (unsigned long long i = 0; i < napis.length(); i++)
    {
        //cout << napis << endl;
        if(bigtosmall == true)
        {
            x = napis[i];
            x = tolower(x);
            napis[i] = x;
        }
        if(plznaki == true)
        {
            x = napis[i];
            if(x == '\206'||x=='\217') x = 'c'; //æ
            else if(x == '\210'||x=='\235') x = 'l'; //³
            else if(x == '\230'||x=='\227') x = 's'; //œ
            else if(x == '\242'||x=='\340') x = 'o'; //ó
            else if(x == '\245'||x=='\244') x = 'a'; //¹
            else if(x == '\251'||x=='\250') x = 'e'; //ê
            else if(x == '\253'||x == '\276'||x=='\275'||x=='\215') x = 'z'; // ¿ Ÿ
            else if(x == '\344'||x=='\343') x = 'n';
            napis[i] = x;
        }
        if(poliznaki == true && czy_to_liczba(napis.substr(i,1)) == false && napis.substr(i,1) == modp(napis.substr(i+1,1),1,1,0))
        {
            int j = 0;
            for(;napis.substr(i+j,1) == modp(napis.substr(i+j+1,1),1,1,0);j++)  {;}
            //,cout << j <<endl; getch();
            napis.erase(i,j);
            i --;
        }
        else    zabezpieczenie.insert(i, napis.substr(i,1));
        wyjatki.open("../Pliki/Wyjatki",ios::in);
        while(getline(wyjatki,linia))
        {
            if(zabezpieczenie == linia)  {wyjatki.close(); goto tu;}
        }
        wyjatki.close();
    }
    tu:
    if(revers == true)
    {
        string obrot;
        for(unsigned long long i = napis.length();i>0; i--)
        {
            obrot.insert(0,napis.substr(i,1));
        }
        return obrot;
    }
    else    return napis;
}

bool czy_to_litera(string litera){
    litera= modp(litera);

    if(litera=="a" || litera=="b" || litera=="c" || litera=="d" || litera=="e" || litera=="f" || litera=="g" || litera=="h" || litera=="i" || litera=="j" || litera=="k" || litera=="l"
    || litera=="m" || litera=="n" || litera=="o" || litera=="p" || litera=="r" || litera=="s" || litera=="t" || litera=="u" || litera=="w" || litera=="x" || litera=="y" || litera=="z"
    || litera=="q" || litera=="v")

    return true;
    else return false;
}

void tworzymy_pliki(){
    fstream plik,hej; string linia, nazwa_pliku, lokacja;
    plik.open("../Pliki/lokalizacja",ios::in);
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin";
    CreateDirectory(TEXT(lokacja.c_str()), NULL);
    CreateDirectory(TEXT("../komunikator"), NULL);
    CreateDirectory(TEXT("../komunikator/kolory"), NULL);
    CreateDirectory(TEXT("../komunikator/zalogowani"), NULL);
    hej.open("../Pliki/foldery_C",ios::in);
    lokacja = lokacja + "/";
    while(getline(hej,linia))
    {
        nazwa_pliku = lokacja + linia;
        plik.open(nazwa_pliku.c_str(),ios::out|ios::app);
        plik.close();
    }
    hej.close();

}

void kropki(int czas){
    for(int i=1;i<=3;i++){
        Sleep(czas);
        cout<<".";
    }
    Sleep(czas);}

void echo(bool enable){
    /*
        ARGUMENTY DOMNIEMANE:
        bool enable = true
    */
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    if( !enable )
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;

    SetConsoleMode(hStdin, mode );

#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

string odwrocenie (string pomoc){
     size_t size = pomoc.size();
     string nowy;
     for(size_t i = 0; i < size; ++i)
     {
         nowy += pomoc[size-i-1];
     }
     return nowy;
 }

void ustaw_wskaznik(int x, int y){
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

unsigned long long liczs (string napis){ ///liczy ilosc spacji
    unsigned long long wynik=0;
     for(unsigned long long i=0;i<napis.length();i++){
        if(napis.substr(i,1)==" "){
            wynik++;
        }
    }
    return wynik;
}

string ptok(string napis){
    for(int i=0;i<napis.length();i++){
        if(napis.substr(i,1)==","){
           napis.replace(i,1,".");
           continue;
        }
    }
    return napis;
}

string usp(string napis ,bool allsp , bool doublesp , bool startsp , bool endsp , string przed , string po , string miedzystart , string miedzystop , bool GOWNIANY_POMYSL_DANIELA){/// OSTATECZNY USUWACZ SPACJI
    /*
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

    /*
        ARGUMENTY DOMNIEMANE:
        bool allsp=1
        bool doublesp=0
        bool startsp=0
        bool endsp=0
        string przed=""
        string po=""
        string miedzystart=""
        string miedzystop=""
        bool GOWNIANY_POMYSL_DANIELA=0
    */

    if ( GOWNIANY_POMYSL_DANIELA == false ){  ///NORMALNY TRYB

    string tprzed[przed.length()],tpo[po.length()];     ///tworzymy 2 tablice ze znakami przed i po ktorych usuwamy spacje

    string mstart[miedzystart.length()],mstop[miedzystop.length()]; ///tworzymy 2 tablice ze znakami miedzy ktorymi nie usuwamy spacji
    long long milosc[miedzystart.length()]; /// tabela ktora przetrzymuje wartosci czy usuwac spacje
    bool musun=true; /// zmienna przedstawiajaca czy mozna usuwac spacje na podstawie tabeli milosc (true- mozna usuwac, false- nie mozna usuwac)

    bool koniec_startu=false;                           ///bool ktory mowi nam czy to jeszcze jest poczatek

    if(przed!=""){                                      ///Przypisujemy do tablicy wszystkie znaki przed ktorymi bedziemy usuwac spacje
        for(unsigned long long i=0;i<przed.length();i++){
            tprzed[i]=przed.substr(i,1);
        }
    }

    if(po!=""){                                         ///Przypisujemy do tablicy wszystkie znaki po ktorymi bedziemy usuwac spacje
        for(unsigned long long i=0;i<po.length();i++){
            tpo[i]=po.substr(i,1);
        }
    }

    if(miedzystart!=""){                                      ///Przypisujemy do tablicy wszystkie znaki przed ktorymi bedziemy usuwac spacje
        for(unsigned long long i=0;i<miedzystart.length();i++){
            //cout<<miedzystart<<" KK"<<endl;
            mstart[i]=miedzystart.substr(i,1);
            mstop[i]=miedzystop.substr(i,1);
            milosc[i]=0;
            //cout<<mstart[i]<<" KK"<<endl;
        }
    }

    //cout<<tprzed[0]<<endl;

    for(unsigned long long i=0;i<napis.length();i++){   ///Usuwamy spacje
        //cout<<"i-"<<i<<" czo-"<< napis.substr(i,1)<<endl;
        if(musun==false){
            ///kupa
        }
        else if( ( napis.substr(i,1)==" " && ( startsp==true && koniec_startu==false || allsp==true) )){ ///usuwamy spacje na poczatku lub wszystkie
            napis.erase(i,1); i--; continue;
        }

        else if( koniec_startu=true , napis.substr(i,2)=="  " && doublesp==true){ ///usuwamy podwojne spacje
            napis.erase(i,1); i--; continue;
        }
        else if(przed!="" || po!=""){ ///usuwamy spacje przed i po wybranych znakach
            wyzej:
            for(unsigned long long j=0;j<przed.length();j++){
                //cout<<"j-"<< j<<endl;
                if( tprzed[j] == napis.substr(i,1) ){
                    if(i!=0 && napis.substr(i-1,1)==" " ){ ///upewniam sie czy jest cos przed tym znakiem
                        napis.erase(i-1,1); i--;
                        goto wyzej;
                    }
                }
            }
            wyzej2:
            for(unsigned long long j=0;j<po.length();j++){
                //cout<<"j-"<< tpo[j]<<endl;
                if( tpo[j] == napis.substr(i,1) ){
                    if( napis.substr(i+1,1)==" " ){ ///upewniam sie czy jest cos przed tym znakiem
                        napis.erase(i+1,1);
                        goto wyzej2;
                    }
                }
            }
        }
        if(miedzystart!=""){
            for(int j=0;j<miedzystart.length();j++){
                if(milosc[j]>0){    ///zaleznie od tego bedziemy sprawdzac najpierw mstop lub mstart
                    if(napis.substr(i,1)==mstop[j]){
                        milosc[j]-=1;
                        //cout<<milosc[j]<<" deb" << endl;
                    }
                    else if(napis.substr(i,1)==mstart[j]){
                        milosc[j]+=1;
                        //cout<<milosc[j]<<" deb" << endl;
                    }
                }
                else{
                //cout<<napis.substr(i,1)<<","<<mstart[j]<<endl;
                    if(napis.substr(i,1)==mstart[j]){
                        milosc[j]+=1;
                        //cout<<milosc[j]<<" deb" << endl;
                    }
                    else if(napis.substr(i,1)==mstop[j]){
                        milosc[j]-=1;
                        //cout<<milosc[j]<<" deb" << endl;
                    }
                }
            }
            for(int j=0;j<miedzystart.length();j++){
                if(milosc[j]>0 ){
                    musun=false;
                }
                else{
                    musun=true;
                }
            }
        }
    }

    if(endsp==true){
        for(unsigned long long i=napis.length()-1;i>0;i--){
            if(napis.substr(i,1)!=" "){
                break;
            }
            else napis.erase(i,1);
        }
    }

    return napis;
    }
    else{ ///---------------------------------- TRYB "GOWNIANY POMYSL DANIELA"
     /// o boze programistow wybacz mi ze to zrobilem, zchanbilem sie tak gównianym rozwiazeniem ale zmusil mnie do tego daniel
     /// daniel ty smieciu
    string zabezpieczenie,linia ;
    fstream plik;
    plik.open("../Pliki/Wyjatki",ios::in);
     int x = napis.length();
     for(int i = 0, j = 0; i < x  ;i ++){
        if(napis.substr(i,1)==" "){
            napis.erase(i,1);
            x --;
            i--;}
        else if(czy_to_liczba(napis.substr(i,1)) == true)
        {
            plik.close();
            return napis;
        }
        else {zabezpieczenie.insert(j, napis.substr(i,1)); j++;}
        while(getline(plik,linia)){
//        zmiana_wielkosci_liter(zabezpieczenie);
        if(modp(zabezpieczenie,1,1,0) == linia) {
                plik.close(); return napis;
        }
        }
          plik.close();
          plik.open("../Pliki/Wyjatki",ios::in);
     }
    plik.close();
    return napis;


    }
}

int sprawdzacz_bledow(long double nr_bledu){
    setprecision(20);
    int x=nr_bledu;
    //cout << x<< endl<<endl;
    if(czy_wszystko_ok == false){
        switch(x){
        case 10:
            cerr <<"Bledny odczyt pliku\n";
            break;
        case 1:
            cerr <<"Error 1, Podano za malo danych\n";
            break;
        case 6:
            cerr <<"Error 6, Nie dziel przez 0!\n";
            break;
        case -6:
            cerr <<"Error -6, jeszcze nie umiem przeprowadzac operacji na liczbach urojonych\n";
            break;
        case 0:
            cerr <<"Error 0, Jezeli to widzisz oznacza to ze cos sie zepsulo\n";
            break;
        case 8:
            cerr <<"Error 8, Wykladnik pierwiastka nie moze wynosic zero\n";
            break;
        case 37:
            cerr <<"Error 37, Znak procentu prosze wstawic tylko przy liczbie ktora ma byc procentem\n";
            break;
        case 69:
            cerr <<"Error 69, Podana liczba musi byc calkowita\n";
            break;
        case 12:
            cerr <<"Error 12, Wprowadzono znaki w blednej kolejnosci\n";
            break;
        case 999:
            cerr <<"Error 999, Gdzies zostala dostarczona pustka przez co nie moge dzialac poprawnie - Alex zepsules\n";
            break;
        case 113:
            cerr <<"Error 113, Wprowadzono za duzo danych\n";
            break;
        case 112:
            cerr <<"Error 112, Wprowadzono bledny znak\n";
            break;
        case 404:
            cerr <<"Error 404, Wynik przekracza wszelkie granice\n";
            break;
        case -69:
            cerr <<"Error -69, Podana liczba musi byc dodatnia\n";
            break;
        case 70:
            cerr << "Przypominam ze jest 12 miesiecy\n";
            break;
        case 71:
            cerr << "Tak tylko chce wspomniec ze dzien miesiaca nie moze miec wartosci mniejszej niz 1\n";
            break;
        case 72:
            cerr << "Ta data nie istnieje ~ Grzegorz XIII :)\n";
            break;
        case 73:
            cerr << "Przypomiam, ze Luty w tym roku nie moze miec wiecej niz 29 dni\n";
            break;
        case 74:
            cerr << "Przypomiam, ze Luty w tym roku nie moze miec wiecej niz 28 dni\n";
            break;
        case 75:
            cerr << "Chcialbym wspommniec ze kwiecien ma 30 dni\n";
            break;
        case 76:
            cerr << "Chcialbym wspommniec ze czerwiec ma 30 dni\n";
            break;
        case 77:
            cerr << "Chcialbym wspommniec ze wrzesien ma 30 dni\n";
            break;
        case 78:
            cerr << "Chcialbym wspommniec ze listopad ma 30 dni\n";
            break;
        case 79:
            cerr << "Chcialbym wspommniec ze styczen ma 31 dni\n";
            break;
        case 80:
            cerr << "Chcialbym wspommniec ze marzec ma 31 dni\n";
            break;
        case 81:
            cerr << "Chcialbym wspommniec ze maj ma 31 dni\n";
            break;
        case 82:
            cerr << "Chcialbym wspommniec ze lipiec ma 31 dni\n";
            break;
        case 83:
            cerr << "Chcialbym wspommniec ze sierpien ma 31 dni\n";
            break;
        case 84:
            cerr << "Chcialbym wspommniec ze pazdziernik ma 31 dni\n";
            break;
        case 85:
            cerr << "Chcialbym wspommniec ze grudzien ma 31 dni\n";
            break;
        case 86:
            cerr << "Podany rok przekracza wszelkie granice\n";
            break;
        case 90:   ///UWAGA
            cerr << "Error 90, Liczba przekracza wszelkie granice\n";
            break;
        case 91:
            cerr << "Minimum nie moze byc wieksze od maximum\n";
            break;
        case 92:
            cerr << "Przeliczam tylko systemy liczbowe od 2 do 16\n";
            break;
        case 111:
            cerr << "Error 111, Prosze nie uzywac 0 w tej komendzie\n";
            break;
        case -1:
            cerr << "Error -1, Podstawa logarytmu nie moze byc liczba ujemna\n";
            break;
        case -10:
            cerr << "Error -10, Podstawa logarytmu nie moze wynosic 0\n";
            break;
         case -11:
            cerr << "Error -11, Podstawa logarytmu nie moze wynosic 1\n";
            break;
        case -100:
            cerr << "Error -100, Liczba z ktorej wyciagasz logarytm nie moze byc ujemna\n";
            break;
        case 270:
            cerr << "Error 270, Tangens z tej liczby nie istnieje\n";
            break;
        case 360:
            cerr << "Error 360, Cotangens z tej liczby nie istnieje\n";
            break;
        }
    }
    else{
        cerr << nr_bledu << endl;

    }

return 10;
}

bool czy_jest_spacja(string napis){
    int x = napis.length();
    for(int i = 0; i < x  ;i ++){
        if(napis.substr(i,1)==" "){
            return true;
            }
}
return false;
}

string zamieniacz_prawie_wszystkich_spacji_na_przecinki(string napis){
    int nawiasy=0;
    for(int i=0;i<napis.length();i++){
        if(napis.substr(i,1)==" "&&nawiasy==0){
            napis.replace(i,1,","); i--;
        }
        else if(napis.substr(i,1)=="{"){
            nawiasy+=1;
        }
        else if(napis.substr(i,1)=="}"){
            nawiasy-=1;
        }

    }
    return napis;
}

string ptop(string napis){
    //cout<<"PTOP START-"<<napis<<endl;
    for(unsigned long long i=0;i<napis.length();i++){
        if(napis.substr(i,1)==" "){
            napis.replace(i,1,",");
        }
    }
    //cout<<"PTOP END-"<<napis<<endl;
    return napis;
}

void saturnin_mowi(int kolor){
switch(kolor){
    case 1:{  ///bialy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF);break;
    }
    case 2:{  ///szary
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x8);break;
    }
    case 3:{  ///srebrny
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);break;
    }
    case 4:{  ///zielony
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x2);break;
    }
    case 5:{  ///limonkowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA);break;
    }
    case 6:{  ///oliwkowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x2);break;
    }
    case 7:{  ///lesny
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x2);break;
    }
    case 8:{  ///Peridot
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);break;
    }
    case 9:{  ///niebieski
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x9);break;
    }
    case 10:{ ///turkusowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x3);break;
    }
    case 11:{ ///morski
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xB);break;
    }
    case 12:{ ///granatowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1);break;
    }
    case 13:{ ///blekitny
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xB);break;
    }
    case 14:{ ///seledynowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1);break;
    }
    case 15:{ ///czerwony
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xC);break;
    }
    case 16:{ ///krwisty
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);break;
    }
    case 17:{ ///burgynt
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1);break;
    }
    case 18:{ ///bordowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x4);break;
    }
    case 19:{ ///pomaranczowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1);break;
    }
    case 20:{ ///orazowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1);break;
    }
    case 21:{ ///mandarynkowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1);break;
    }
    case 22:{ ///fioletowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x5);break;
    }
    case 23:{ ///lawendowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x5);break;
    }
    case 24:{ ///purpurururowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x5);break;
    }
    case 25:{ ///rozowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD);break;
    }
    case 26:{ ///razzmatazz
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD);break;
    }
    case 27:{ ///Sinokoperkowy roz
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);break;
    }
    case 28:{ ///koperkowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);break;
    }
    case 29:{ ///magenta
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD);break;
    }
    case 30:{ ///bezowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);break;
    }
    case 31:{ ///orzechowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);break;
    }
    case 32:{ ///brazowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x1);break;
    }
    case 33:{ ///caputmortuum
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6);break;
    }
    case 34:{ ///zolty
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE);break;
    }
    case 35:{ ///kremowy
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE);break;
    }
    case 36:{ ///zloty
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE);break;
    }
    case 37:{ ///gumiguta
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE);break;
    }
}
}

void sortowanie (int *tablica, int lewy, int prawy){
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) sortowanie(tablica,lewy, j);
    if(i<prawy) sortowanie(tablica, i, prawy);
}

long double string_na_int(string liczba){       ///Do tej funkcji nie mozna dawac liczby jezeli czy_wszystko_ok==false
    long double dlugosc=0,x=1,wynik=0;// string test;
    //cout<<"TURURURU-"<<liczba<<Endl;
    if(czy_wszystko_ok==false){  /// <-- Jesli cos nie dziala to moze byc blad
    //cout<<"GOWNO-"<<liczba<<Endl;
    return 112;
    }
    cout << setprecision(100000);
    dlugosc = liczba.length();
    if(dlugosc > 10006){

        czy_wszystko_ok=false;
        //cout<< liczba<< "  HAHAH"<<ENDL;
        return 404;
    }
    else if(dlugosc==1){
        if(liczba=="0") return 0;
        if(liczba=="1") return 1;
        if(liczba=="2") return 2;
        if(liczba=="3") return 3;
        if(liczba=="4") return 4;
        if(liczba=="5") return 5;
        if(liczba=="6") return 6;
        if(liczba=="7") return 7;
        if(liczba=="8") return 8;
        if(liczba=="9") return 9;
        else{czy_wszystko_ok=false; return 113;}
    }
    else{
        for(long double i=dlugosc-1;i>=0;i--){
             if(liczba.substr(i,1)=="."||liczba.substr(i,1)==","){
                wynik=wynik/x;
                x=1;
            } else if(czy_to_liczba(liczba.substr(i,1))==true){
                wynik=wynik+string_na_int(liczba.substr(i,1))*x;
                x*=10;}
            else if(liczba.substr(i,1)==" "){
                czy_wszystko_ok=false;
                return 113;
            }
            else if(liczba=="inf"){
                czy_wszystko_ok=false;
                return 404;
            }
            else if(liczba.substr(i,1)!="-"){
                czy_wszystko_ok=false;
                //cout<<"AAA-"<<liczba.substr(i,1)<<ENDL;
                return 112;
            }
        }}
    there:
    if(liczba.substr(0,1)=="-"){
        wynik=-wynik;
    }
    //cout<<wynik<<endl;
    return wynik;

}

string int_na_string(long double liczba, bool zamieniac_0_na_000 /* =false */){
    /**
     zmienia liczbe w long double na string
     przecinek przyjmuje jako "."
     jesli funkcja nie wykona sie poprawnie wypisze sie na ekranie "BLAD W INT NA STRING ty debilu"
    */
    /*
        ARGUMENTY DOMNIEMANE
        bool zamieniac_0_na_000=false
    */
    fstream napis; string wynik;
    fstream plik; string lokacja;
    plik.open("../Pliki/lokalizacja",ios::in);
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/int_na_string.txt";

    napis.open(lokacja.c_str(),ios::out);
    if(napis.good()==false){ cout<< "BLAD W INT NA STRING ty debilu";return "10";}
    napis<<setprecision(100000);
    napis<< liczba<<endl;
    napis.close();

    napis.open(lokacja.c_str(),ios::in);
    if(napis.good()==false){cout<< "BLAD W INT NA STRING ty debilu"; return "10";}
    napis >> wynik;
    napis.close();

    if(zamieniac_0_na_000==true){
        if(wynik.length()==1) wynik="00"+wynik;
        else if( wynik.length()==2) wynik="0"+wynik;
    }
    //cout<< wynik<<endl;
    return wynik;
}

long double faktyczne_liczenie_silni(long double wynik){   ///Brakuje zabezpieczen choc podobno wiekszosc jest w string na int a ta przyjmuje juz liczbe
    if(wynik == 0)
    {
        return 1;
    }
    else if(wynik == 1)
    {
        return 1;
    }
    else
    {
        return wynik * faktyczne_liczenie_silni(wynik - 1);
    }

}

long double silnia(string odp){
    long double wynik = 0;
    if(czy_jest_spacja(odp) == true)  ///Wiecej liczb
    {
        czy_wszystko_ok = false;
        return 113;
    }
    wynik = string_na_int(odp);
    if(czy_wszystko_ok == false)
    {
        return wynik;
    }
    if (wynik > 1754) ///Za duza liczba
    {
        czy_wszystko_ok = false;
        return 404;
    }
    else if(wynik < 0)
    {
        czy_wszystko_ok = false ;
        return -69;
    }
    else if(wynik != round(wynik))
    {
        czy_wszystko_ok = false;
        return 69;
    }
    wynik = faktyczne_liczenie_silni(wynik); ///Zebym mogl wyslac liczbe
    return wynik ;
}

long double mediana(string dzialanie){
    long double wynik=0;
    list <long double> lista; ///deklarujemy liste
    int ilosc=0;
    dzialanie=usp(dzialanie,0,0,1,1);
    dzialanie.insert(dzialanie.length(),"=");

       for(int i=0;i<dzialanie.length();i++){ /// Usuwacza podwójnych spacji pomiedzy liczbami
        //cout<<"dzialanie-" <<dzialanie<<"    -"<<dzialanie.substr(i,1) <<endl;
        if(dzialanie.substr(i,1)=="="){ /// potrzebne jakby jakis smieszek dal liczby po = i by program sprawdzal je mimo wszystko
            break;
        }
        else if(dzialanie.substr(i,1)==" " && dzialanie.substr(i+1,1)==" "){
            dzialanie.erase(i,1);
            i--;
            continue;
        }
    }
   dzialanie=usp(dzialanie,0,0,0,0,"qwertyuiopasdfghjklxzcvbnm(){}:.,[]&!@#$%^&*?'","qwertyuiopasdfghjklxzcvbnm(){}:.,[]&!@#$%^&*?'");
   dzialanie=zamieniacz_prawie_wszystkich_spacji_na_przecinki(dzialanie);
   //cout<<"Mediana-"<<dzialanie<<" "<<czy_wszystko_ok<<endl;
    for(int j = 0;; j++){
        for(int i=0; i<dzialanie.length(); i++)
        {
            if(dzialanie.substr(i,1)==",")     ///jesli to ',' ( ',' jest po liczbie) przypisuje ta liczbe do listy
            {
                int pomocny_int=policz(dzialanie.substr(0,i),wynik);
                if(czy_wszystko_ok==false){
                    return pomocny_int;
                }
                //cout<<"MEDIANA DZIALANIE(,)-"<<dzialanie<<endl;
                //cout<<"MEDIANA CO WSADZAMY DO LISTY(,)-"<<wynik<<endl;
                lista.push_front(wynik);     ///dodaje na poczatku listy -> string na int z -> dzialania przed ','
                dzialanie.erase(0,i+1);   ///usuwa ta liczbe ze ',' zeby mozna znowu zrobic to samo
                //cout<<"WAT "<<i<<ENDL;
                break;
            }
            else if(dzialanie.substr(i,1)=="=")   ///jesli to = (= jest po liczbie) przypisuje ta liczbe do listy
            {
                int pomocny_int=policz(dzialanie.substr(0,i),wynik);
                if(czy_wszystko_ok==false){
                    return pomocny_int;
                }
                //cout<<"MEDIANA DZIALANIE(=)-"<<dzialanie<<endl;
                //cout<<"MEDIANA CO WSADZAMY DO LISTY(=)-"<<wynik<<endl;
                lista.push_front(wynik);   ///dodaje na poczatku listy -> string na int z -> dzialania przed =
                //cout<<"???!!??! "<<i<<ENDL;
                goto operacje;    ///idzie sobie bo trafil na =
            }
        }
    }
    operacje:
    wynik=0;
    lista.sort();    ///wesolo sortujemy liste
    ilosc = lista.size();    ///taka zmienna na potrzeby
    //cout<<"Ilosc to - "<<ilosc<<endl;
    if(ilosc%2==0)    ///jesli jest parzysta ilosc liczb
    {
        int k = 0;
        for(;;)
            {
                k = lista.size()-2;        ///no bo jak sa tylko 2 to nie moze najpierw usunac dlatego -2
                if(k == 2){             ///jesli zostaly juz tylko dwie
                    lista.pop_front();    ///usuwanie z poczatku
                    lista.pop_back();     /// usuwanie z konca
                    wynik = (lista.front() + lista.back()) / 2 ;   ///biore dwie ktore zostaly i licze ich srednia
                break;  ///idzemy sobie bo wynik jest przypisany
                }
                else if(ilosc == 2)    ///jesli podane byly tylko dwie
                {
                    wynik = (lista.front() + lista.back()) / 2 ;
                    break;
                }
                lista.pop_front();
                lista.pop_back();
            }
    }
    else   ///jesli jest nie parzysta ilosc liczb
    {
        int k=0;
        for(;;)
        {
            k =  lista.size() - 1;   /// minus jeden bo pop jest pozniej
            if(k == (ilosc-1)/2){   ///jesli przed nami srodkowa liczba
                wynik = lista.front();   ///wynik to srodkowa
                break;   ///idziemy sobie bo wynik jest przypisany
            }
            lista.pop_front();    ///usuwanie jednej z poczatku
        }
    }

    return wynik;
}

double srednia(string dzialanie,bool czy_korzysta_z_tego_policz){
    /*
        ARGUMENTY DOMNIEMANE
        bool czy_korzysta_z_tego_policz=0
    */
    list <long double> lista;
    double  wynik=0; int ilosc=0;
    long double wynik2=0;   ///Uzywany do wsadzania do policz
    if(czy_korzysta_z_tego_policz==0) {
        //cout<<"SREDNIA1s-"<<dzialanie<<endl;
        dzialanie=usp(dzialanie,0,1,1,1,"","");
        dzialanie.insert(dzialanie.length(),"=");
        ;
        //cout <<"poczatek sredniej- " <<czy_wszystko_ok<<endl;
        //cout <<"dzialanie-"<< dzialanie<< endl;
        for(int i=0;i<dzialanie.length();i++){ /// Usuwacza podwójnych spacji pomiedzy liczbami

            //cout<<"dzialanie-" <<dzialanie<<"    -"<<dzialanie.substr(i,1) <<endl;
            if(dzialanie.substr(i,1)=="="){ /// potrzebne jakby jakis smieszek dal liczby po = i by program sprawdzal je mimo wszystko
                break;
            }
            else if(dzialanie.substr(i,1)==" " && dzialanie.substr(i+1,1)==" "){
                dzialanie.erase(i,1);
                i--;
                continue;
            }
        }
    dzialanie=usp(dzialanie,0,0,0,0,"qwertyuiopasdfghjklxzcvbnm(){}:.,[]&!@#$%^&*?'","qwertyuiopasdfghjklxzcvbnm(){}:.,[]&!@#$%^&*?'");
    dzialanie=zamieniacz_prawie_wszystkich_spacji_na_przecinki(dzialanie);
    //cout<<"SREDNIA2s"<<dzialanie<<endl;
    }
    else{
       // cout<<"SREDNIA1p-"<<dzialanie<<endl;
        dzialanie=usp(dzialanie,0,1,1,1,"","");
        dzialanie.insert(dzialanie.length(),"=");
        //cout<<"SREDNIA2p-"<<dzialanie<<endl;
    }
    for(int j=0;;j++){
        //cout<<"LEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEECIMY"<<ENDL;
        for(int i=0;;i++){
            if(dzialanie.substr(i,1)=="="){///WPISUJE CALA LICZBE SPRZED = DO LICZBA[J] i WYCHODZI Z PETLI
                //cout<< '"'<<dzialanie<< "\' co dajemy?-"<<dzialanie.substr(0,i)<<"  wszystko ok?-"<<czy_wszystko_ok<<endl;
                int pomocny_int=policz(dzialanie.substr(0,i),wynik2);
                //cout<<wynik2<<endl;
                if(czy_wszystko_ok==false){
                    //cout << "lol";
                    return pomocny_int;
                }
                lista.push_front(wynik2);  ///Sprawdza bledy String na Int
                //cout<< "wchodzi tuuu"<<endl;
                if(czy_wszystko_ok==false){ ///SPRAWDZACZ BLEDOW W  STRING_NA_INT
                    //cout<< "a potem tuuuu"<<endl;
                   // cout << "lol1";
                    return lista.front();}
                else{
                    //cout<< dzialanie<<endl<<" liczba ktora wsadzimy do "<<i<<" miejsca w liscie-"<<lista.front()<<endl;
                    ilosc++;
                    goto wyjscie;}
            }
            else if(dzialanie.substr(i,1)==","){   ///WPISUJE CALA LICZBE SPRZED ',' DO LICZBA[J] i USUWA J¥ Z DZIALANIA
                //cout<<"zaraz wsadzamy do policz-"<<dzialanie.substr(0,i)<<" dzialanie-"<<dzialanie <<endl;
                //cout<<"wszystko ok? -" <<czy_wszystko_ok<< endl;
                int pomocny_int=policz(dzialanie.substr(0,i),wynik2);
                //cout<<"WYNIK Z POLICZ (w sredniej)-"<<wynik2<<endl;
                if(czy_wszystko_ok==false){
                    //cout << "lol2";
                    return pomocny_int;
                }
                lista.push_front(wynik2); ///Sprawdza bledy String na Int
                if(czy_wszystko_ok==false){
                   //cout << "lol3";
                    return lista.front();
                }
                ilosc++;
                //cout<<"wszystko ok? -" <<czy_wszystko_ok<< endl;
                dzialanie.erase(0,i+1);
                //cout<<"koncoweczka srednia-"<< dzialanie<<endl;
                break;
            }
            /*
            else if(czy_to_liczba(dzialanie.substr(i,1))==true||dzialanie.substr(i,1)=="."||dzialanie.substr(i,1)=="-"){

                    if(dzialanie.substr(i+1,1)==" "||dzialanie.substr(i+1,1)=="="){ ///JESLI CYFRA JEST OSTATNIA CYFRA W LICZBIE DODAJ DO ILOSCI 1
                        ilosc++;
                    }
                continue;
            }
            else{                           ///ERROR Z BRAKIEM ZNAKU W BAZIE GOWNO POLICZ MA TE RZECZY
                czy_wszystko_ok=false;
                return 112;
            } */
        }
    }
    czy_wszystko_ok=false;
    return 113;
    wyjscie:
    //cout<<"ilosc-"<<ilosc<<endl;
    for(list <long
         double> ::iterator i = lista.begin();i !=lista.end();++i){
           // cout<< "liczba " << i << " "<< liczba[i]<< endl;
            wynik+=*i;
    }
        //cout <<"koniec sredniej- " <<czy_wszystko_ok<<endl;
       //cout <<wynik<<"-"<< ilosc<< endl;
    return wynik/ilosc;
}

long double snr(long double stopnie){/// stopnie na radiany
    return stopnie*(/*M_PI*/3.14/180);  //@fixme
}

int policz(string dzialanie,long double &wynik,long double poprzedni_wynik /* = 0 */){
    /** użyj do poprzedniego_wyniku przedrostka static!!
    popraw warosc bezwzgledna na abs
    a poprzedni wynik na ans
    */
    /*
        ARGUMENTY DOMNIEMANE
        long double poprzedni_wynik = 0
    */

    ///Podobamy mi sie styl komentarzy
    //cout<<"wchodze do policz"<<endl;
    if(dzialanie.substr(dzialanie.length()-1,1)!="=") dzialanie.insert(dzialanie.length(),"="); ///Dopisywanie na koncu rowna sie
    dzialanie.insert(0,"#"); ///dzialanie zaczynac sie bedzie od # zebym wiedzial gdzie jest poczatek
     //cout<<"policz0-"<<dzialanie<<endl;
    dzialanie=modp(usp(dzialanie,1,0,0,0,"","","{","}"),1,1,0);
    //cout<<"policz1-"<<dzialanie<<endl;
    cout << setprecision(10000);
    //cout<<"policz-"<<czy_wszystko_ok<<endl;
    if(dzialanie==""){
        czy_wszystko_ok=false;
        return 999;
    }
                                                                        ///DEFINIOWANIE ZMIENNYCH
        int nawiasy=0; ///Dodaje gdy widzi '(' a odejmuje gdy widzi ')'
        int nawiasy2=0; ///Dodaje gdy widzi '{' a odejmuje gdy widzi '}'
        int nawiasy3=0; ///Dodaje gdy widzi '[' a odejmuje gdy widzi ']'
        int wb=0;      ///Wartosc Bezwzgledna dodaje gdy widzi '|'
        string pomoc; ///tu przez chwile bedziemy przechowywaæ wyniki z pojedynczych dzialan w policz
        long double liczba1,liczba2;///tu przechowamy liczby na ktorych bedziemy wykonywac dzialanie

    for(int i=0;;i++){                                                  ///USUWANIE SPACJI W NIEPOTRZEBNYCH MIEJSCACH
        if(dzialanie.substr(i,1)=="{"&&dzialanie.substr(i+1,1)==" "){
            dzialanie.erase(i+1,1);
            i--;
            continue;
        }
        else if(dzialanie.substr(i,1)=="="){
            break;
        }
    }
    for(int i=0;;i++){                                                  ///ZAMIANA "--" NA '+' JEZELI NIE JEST TO "---"
        if(dzialanie.substr(i,2)=="--"){
            if(dzialanie.substr(i,3)=="---"){
                czy_wszystko_ok=false;
                //cout << "xD";
                return 12;
            }
            else{
                dzialanie.replace(i,2,"+");
                //dzialanie.erase(i,2); hihi
                //dzialanie.insert(i,"+");
                continue;
            }
        }
        else if(dzialanie.substr(i,1)=="="){
            break;
        }
    }
    for(int i=0;;i++){                                                  ///SPRAWDZAMY POPRAWNOSC NAWIASOW I WARTOSCI BEZWZGLEDNEJ I ZMIANY SYSTEMÓW LICZBOWYCH
        //cout<<"liczba nawiasow-"<<nawiasy2<<" dzialanie-"<<dzialanie<<endl;
        if(dzialanie.substr(i,1)=="|"){
            wb++;
            continue;
        }
        else if(dzialanie.substr(i,1)=="("){
            nawiasy++;
            continue;
        }
        else if(dzialanie.substr(i,1)==")"){
            nawiasy--;
            if(nawiasy<0){
                czy_wszystko_ok=false;
                //cout << "xD1 " <<dzialanie.substr(i,1);
                return 12;
            }
        }
        else if(dzialanie.substr(i,1)=="["){
            if(czy_to_liczba(dzialanie.substr(i-1,1))==false && czy_to_litera(dzialanie.substr(i-1,1)) ==false) {
                czy_wszystko_ok=false;
                return 12;
            }
            nawiasy3++;
            continue;
        }
        else if(dzialanie.substr(i,1)=="]"){
            nawiasy3--;
            if(nawiasy3<0){
                czy_wszystko_ok=false;
                //cout << "xD2 "<<dzialanie.substr(i,1);
                return 12;
            }
            continue;
        }
        else if(dzialanie.substr(i,1)=="}"){
            nawiasy2--;
            if(nawiasy<0){
                czy_wszystko_ok=false;
                //cout << "xD2 "<<dzialanie.substr(i,1);
                return 12;
            }
        }
        else if(dzialanie.substr(i,1)=="{"){
            nawiasy2++;
        }
        else if(dzialanie.substr(i,1)=="="){
            if(nawiasy!=0){
                czy_wszystko_ok=false;
                //cout << "xD3 ";
                return 12;
            }
            else if(wb%2==1){
                czy_wszystko_ok=false;
                //cout << "xD4 ";
                return 12;
            }
            else if(nawiasy2!=0){
                czy_wszystko_ok=false;
                //cout << "xD5 ";
                return 12;
            }
            if(nawiasy3!=0){
                czy_wszystko_ok=false;
                //cout << "xD2 "<<dzialanie.substr(i,1);
                return 12;
            }
            break;
        }
    ///Spytne
    }
    for(int i=0;i<dzialanie.length();i++){                              ///ZAMIANA W CHOLERE RZECZY
         /**
            ZAMIENIA (DOKLADNIE W TAKIEJ KOLEJNOSCI) :
                "ln" -> "log(e)"
                "tg" -> "tan"
                "x" -> "*"
                "pi" -> (3.141592)
                "e" -> (2.718281)
                "-" -> "&"  ale nie w kazdym wypadku
                ":" -> "/"
                "abs" -> "(" poprzedni_wynik ")"
                "sqrt" ->  "(2v" liczba ")"
                "cbrt -> "(3v" liczba ")"
                "modulo" -> "%"
                "mod" -> "%"
                "rt" -> "v"
                "log" x "(" y ")" -> x "@" y
                "rnd" x "(" y ")" -> x "$" y
                "[" x "]" -> "[(" x ")]" ale nie zawsze
         **/

         if(dzialanie.substr(i,1)=="-"){             ///Jezeli widzi minusa
            if(dzialanie.substr(i,3)=="---"){
                czy_wszystko_ok=false; ///Juz tego nie sprawdzilismy ?
                //cout << "xD";
                return 12;
            }
            else if(czy_to_liczba(dzialanie.substr(i-1,1))==false&&dzialanie.substr(i-1,1)!=")"){   ///I z ty³u minusa jest znak to go zostawia
                continue;
            }
            else{               ///Jesli jednak przed minusem jest liczba
                dzialanie.replace(i,1,"&");      ///zamienia '-' na '&' hihi
            }
        }
        else if(dzialanie.substr(i,1)==":"){
            dzialanie.replace(i,1,"/"); //:)
        }
        else if(dzialanie.substr(i,2)=="ln"){
            dzialanie.replace(i,2,"log(e)");
        }
        else if(dzialanie.substr(i,1)=="x"){
            dzialanie.replace(i,1,"*");
        }
        else if(dzialanie.substr(i,1)=="tg"){
            dzialanie.replace(i,1,"tan");
        }
        else if(dzialanie.substr(i,2)=="pi"){
            dzialanie.replace(i,2,"(3.141592)");
        }
        else if(dzialanie.substr(i,1)=="e"&& dzialanie.substr(i+1,1)!="d"){
            dzialanie.replace(i,1,"(2.718281)");
        }
        else if(dzialanie.substr(i,3)=="abs"){
            dzialanie.replace(i,3,"("+int_na_string(poprzedni_wynik)+")");
        }
        else if(dzialanie.substr(i,4)=="sqrt"){ ///Jesli widzi "sqrt"
            dzialanie.replace(i,4,"(2v"); ///Czemu tutaj nie wykonujemy dzialania? bo ³atwiej bedzie nam edytowac program gdy dodamy kolejne dzia³ania
             ///A czemu ten nawias ?
             for(int j=4;;j++){
                    ///A ta petla nizej co robi ? hmm edit: ta czworka to sprytna jednak
                //cout<<dzialanie.substr(j+i,1)<<endl;
                if(czy_to_liczba(dzialanie.substr(j+i,1))!=true&&dzialanie.substr(j+i,1)!="."&&dzialanie.substr(j+i,1)!="-"&&dzialanie.substr(j+i,1)!="|"&&dzialanie.substr(j+i,1)!="("
                   &&dzialanie.substr(j+i,1)!="c"&&dzialanie.substr(j+i,1)!="b"&&dzialanie.substr(j+i,1)!="r"&&dzialanie.substr(j+i,1)!="t"&&dzialanie.substr(j+i,1)!="s"&&dzialanie.substr(j+i,1)!="q"){
                    //cout<<dzialanie<<endl;
                    //cout<<"i-"<<i <<" j-"<<j<<endl;
                    dzialanie.insert(i+j,")");
                    //cout<<dzialanie<<endl;
                    break;
             /// AAAAA DODAJE NAWIAS GDY SKONCZY SIE LICZBA CZYLI JAKIES INNE DZIALANIE DLATEGO - ZMIENIALES NA &
                }
            }
        }
        else if(dzialanie.substr(i,4)=="cbrt"){ ///Jesli widzi "cbrt"
            dzialanie.replace(i,4,"(3v");
            for(int j=4;;j++){
                //cout<<dzialanie.substr(j+i,1)<<endl;
                if(czy_to_liczba(dzialanie.substr(j+i,1))!=true&&dzialanie.substr(j+i,1)!="."&&dzialanie.substr(j+i,1)!="-"&&dzialanie.substr(j+i,1)!="|"&&dzialanie.substr(j+i,1)!="("
                   &&dzialanie.substr(j+i,1)!="c"&&dzialanie.substr(j+i,1)!="b"&&dzialanie.substr(j+i,1)!="r"&&dzialanie.substr(j+i,1)!="t"&&dzialanie.substr(j+i,1)!="s"&&dzialanie.substr(j+i,1)!="q"){
                    //cout<<dzialanie<<endl;
                    //cout<<"i-"<<i <<" j-"<<j<<endl;
                    dzialanie.insert(i+j,")");
                    //cout<<dzialanie<<endl;
                    break;
                }
            }
            continue;
        }
        else if(dzialanie.substr(i,6)=="modulo"){
            dzialanie.replace(i,6,"%");
        }
        else if(dzialanie.substr(i,3)=="mod"){
            dzialanie.replace(i,3,"%");
        }
        else if(dzialanie.substr(i,2)=="rt"){
            dzialanie.replace(i,2,"v"); //:)
        }
        else if(dzialanie.substr(i,3)=="log"){ ///znajdujemy "log" w tekscie
            if(dzialanie.substr(i+3,1)=="("){ /// jezeli nie podano podstawy
                dzialanie.insert(i+3,"10");
            }

            dzialanie.replace(i,3,"@");
            for(int j=i+1 ; j<dzialanie.length() ;j++){ /// i - miejsce '@'   j - odleglosc od poczatku
                //cout<<j <<"/"<< dzialanie.length()<<"  "<<dzialanie<<endl;
                if(dzialanie.substr(j,1)=="("){ /// wszystko ok
                    //cout<<"!!! "<<dzialanie<<endl;
                    dzialanie.insert(i,"("+dzialanie.substr(i+1,j-i-1)+")");
                    //cout<<"!!!! "<<dzialanie<<endl;
                    //cout<<i<<" "<<j<<endl;
                    int szybki_int=i;
                    i += j-i+1; /// poprawka 'i' i 'j' bo miejsce '@' sie przesunelo
                    j += j-szybki_int+1;
                    //cout<<i<<" "<<j<<endl;
                    dzialanie.erase(i+1,j-i-1);
                    //cout<<"!!!!! "<<dzialanie<<endl;
                    break;
                }
            }
        }
        else if(dzialanie.substr(i,3)=="rnd"){ ///znajdujemy "rnd" w tekscie
//            cout<<dzialanie<<"----"<<endl;
            if(dzialanie.substr(i+3,1)=="("){ /// jezeli nie podano podstawy
                dzialanie.insert(i+3,"0");
            }

            dzialanie.replace(i,3,"$");
            for(int j=i+1 ; j<dzialanie.length() ;j++){ /// i - miejsce '$'   j - miejsce "("
                //cout<<j <<"/"<< dzialanie.length()<<"  "<<dzialanie<<endl;
                if(dzialanie.substr(j,1)=="("){ /// wszystko ok
                    //cout<<"!!! "<<dzialanie<<endl;
                    dzialanie.insert(i,"("+dzialanie.substr(i+1,j-i-1)+")");
                    //cout<<"!!!! "<<dzialanie<<endl;
                    //cout<<i<<" "<<j<<endl;
                    int szybki_int=i;
                    i += j-i+1; /// poprawka 'i' i 'j' bo miejsce '$' sie przesunelo
                    j += j-szybki_int+1;
                    //cout<<i<<" "<<j<<endl;
                    dzialanie.erase(i+1,j-i-1);
                    //cout<<"!!!!! "<<dzialanie<<endl;
//                    cout<<dzialanie<<"----"<<endl;
                    break;
                }
            }
        }
        else if(dzialanie.substr(i,1)=="["){ ///znajdujemy "["
            if(dzialanie.substr(i,4)=="[zm]"||dzialanie.substr(i,4)=="[u1]"||dzialanie.substr(i,4)=="[u2]");
            else{
                dzialanie.insert(i+1,"(");
                for(int j=i;;j++){
                    if(dzialanie.substr(j,1)=="]"){
                        dzialanie.insert(j,")");
                        break;
                    }

                }
            }
        }
    }
                    jeszcze_raz:
    for(int i=0;i<=dzialanie.length()-1;i++){                           ///ZAMIANA PUSTYCH MIEJSC MIEDZY LICZBA A NAWIASEM NA '*'
        if(czy_to_liczba(dzialanie.substr(i,1))==true&& dzialanie.substr(i+1,1)=="("){ ///Jesli liczba i '(' sa obok siebie
            dzialanie.insert(i+1,"*"); ///to wpisz miedzy nich '*'
        }
        else if(dzialanie.substr(i,1)==")"&&(czy_to_liczba(dzialanie.substr(i+1,1))==true|| dzialanie.substr(i+1,1)=="(")){ ///Jesli ')' i liczba (lub '(' )  sa obok siebie
            dzialanie.insert(i+1,"*"); ///to wpisujesz miedzy nich '*'
        }

    }
    for(int i=dzialanie.length()-1;i>=0;i--){                           ///NAWIASY I REKURENCJA POLICZ
        //cout <<"pieeerwsza petla-"<<dzialanie.substr(i,1)<<endl;
        if(dzialanie.substr(i,1)=="("){  ///sprawdzamy od konca gdyz w innym wypadku problem bylby z nawiasami w nawiasach
            //cout<<dzialanie<<" "<< i <<endl;
            for(int j=1; i+j<dzialanie.length() ;j++){ ///genialny warunek
               // cout<<"druuuuuuga petla-"<<dzialanie.substr(i+j,1)<<endl;
                if(dzialanie.substr(i+j,1)==")"){
                    //cout<< "i="<<i << " j="<<j <<endl;
                    cout <<"przed "<<dzialanie<<endl;
                    //cout<<"Wchodzimy do Rekurencji-"<<dzialanie<<" > "<< dzialanie.substr(i+1,j-1)<<endl;
                    //unsigned int przecinek=dzialanie.length();

                    int szybka_pomoc_w_incie=policz(dzialanie.substr(i+1,j-1),wynik,poprzedni_wynik); /// bierzemy do policz to co jest miedzy nawiasami
                    //cout<<"Wyjscie z Rekurencji-"<<szybka_pomoc_w_incie<<endl;
                    if(czy_wszystko_ok==false){
                        return szybka_pomoc_w_incie;
                    }
                    pomoc=int_na_string(wynik);      ///Wynik z policz zamieniamy w string i wsadzamy do pomoc
                    dzialanie.replace(i,j+1,pomoc);///Usuwamy wszystko razem z nawiasami
                    //cout <<"zaraz "<<dzialanie<<endl;
                    cout <<"po "<<dzialanie<<endl;
                    break;
                }
            }
            continue; ///Powtarzamy petle do konca dzialania   to tu ma byc ? przeciez petla i tak sie przejdzie
        }
    }
    for(unsigned int i=0;i<=dzialanie.length()-1;i++){                  ///ZAMIANA SYSTEMÓW LICZBOWYCH
        if(dzialanie.substr(i,1)=="["){
            string system;
            for(int j=1;;j++){
                if(dzialanie.substr(i+j,1)=="]"){
                    system=dzialanie.substr(i+1,j-1);
                    dzialanie.erase(i+1,j);
                    break;
                }
            }
            for(int j=1;;j++){
                //cout<<" "<<dzialanie.substr(i-j,1)<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false && czy_to_litera(dzialanie.substr(i-j,1))== false){
                    //cout<<dzialanie.substr(i-j+1,j-1)<<endl;
                    pomoc=dzialanie.substr(i-j+1,j-1);
                    dzialanie.erase(i-j+1,j);
                    i=i-j+1;
                    break;
                }
            }
            //cout<<"1-" <<pomoc<< " 2-"<< system<<endl;
            if(system=="zm" || system=="u1" || system=="u2"){
                //cout<<"ka ka"<<endl;
                pomoc=system_liczeniowy( pomoc, 2 ,10,"",system );
            }
            else pomoc=system_liczeniowy( pomoc, string_na_int(system) ,10,"","" );
            if(czy_wszystko_ok==false){
                //cout<<"gowno"<<endl;
                return string_na_int(pomoc);
            }
            dzialanie.insert(i,pomoc);
//            cout<<dzialanie<<endl;

        }
    }
    for(int i=0;;i++){                                                  ///WARTOSC BEZWZGLEDNA
       // cout<<"przed-"<<dzialanie.substr(i,1)<<Endl;
        if(dzialanie.substr(i,1)=="|"){ ///szukamy pierwszego '|'
            if(czy_to_liczba(dzialanie.substr(i-1,1))==true){ /// Jezeli przed otwieraj¹cym '|' jest liczba to wstaw pomiedzy ich '*'
                dzialanie.insert(i,"*");
                i++;
                //cout<<dzialanie<<endl;
            }

            for(int j=1;;j++){ ///szukamy drugiego '|'
                //cout<<"w czasie-"<<dzialanie.substr(i+j,1)<<Endl;
                if(dzialanie.substr(i+j,1)=="|"){   ///szukamy drugiego '|'
                    if(czy_to_liczba(dzialanie.substr(i+j+1,1))==true){
                        dzialanie.insert(i+j+1,"*");
                        //cout<<dzialanie<<endl;
                    }
                    if(dzialanie.substr(i+1,j-1)==""){
                        czy_wszystko_ok=false;
                        //cout << "xD";
                        return 12;
                    }
                    //cout<<"i-"<<i<<" j-"<<j<<endl;
                    //cout<<"dzialanie-"<<dzialanie<<endl;
                    //cout<<"w srodkuu-"<<dzialanie.substr(i+1,j-1)<<endl;
                    long long szybka_pomoc_w_incie=policz(dzialanie.substr(i+1,j-1),wynik,poprzedni_wynik); ///wsadzam dzialanie do policz
                    if(czy_wszystko_ok==false){
                        return szybka_pomoc_w_incie;
                    }
                    pomoc=int_na_string(fabs(wynik)); ///wsadzam wynik do pomoc
                    //cout<<"ON WYSZEDL!!!! TRYIUMF!!!!!!!"<<ENDL;
                    dzialanie.erase(i,j+1);
                    dzialanie.insert(i,pomoc);
                    //cout<<dzialanie<<endl;
                    break;
                }
            }
        }
        else if(dzialanie.substr(i,1)=="="){
            //cout<<dzialanie<<endl;
            break;
        }

    }
    for(unsigned int i=dzialanie.length()-1;i>=0;i--){                  ///SREDNIA I MEDIANA
        //cout<<i<< ","<< dzialanie.substr(i,8)<<endl; Sleep(500);
        if(dzialanie.length()<8||dzialanie.length()<i){
            break;
        }
        else if(dzialanie.substr(i,8)=="srednia{"){ ///SZUKAMY SREDNIA
            //cout<<"???????????????????????????????????????????"<<endl;
            i=i+7;     ///Ustawiamy 'i' na '{'
            for(unsigned long long j=0;;j++){
                if(dzialanie.substr(i+j,1)=="}"){
                    //cout<<"HAHAJA-"<< dzialanie.substr(i+1,j-1)<<endl;

                    pomoc= int_na_string( srednia( ptop( usp( dzialanie.substr(i+1,j-1) ,0,1,1,1,"","" ) ) ,1 ) );
                    //cout<<"KUPA"<<ENDL;
                    dzialanie.replace(i-7,j+8,pomoc);
                    //cout<<"DUPA-"<<dzialanie<<endl;
                    break;
                }
            }
        }
        else if(dzialanie.substr(i,8)=="mediana{"){ ///SZUKAMY MEDIANA
                //cout<<"???????????????????????????????????????????"<<endl;
            i=i+7;     ///Ustawiamy 'i' na '{'
            for(unsigned long long j=0;;j++){
                if(dzialanie.substr(i+j,1)=="}"){
                    //cout<<"HAHAJA-"<< dzialanie.substr(i+1,j-1)<<endl;
                    pomoc= int_na_string( mediana( ptop( usp( dzialanie.substr(i+1,j-1) ,0,1,1,1,"","" ) )  ) );
                    //cout<<"KUPA"<<ENDL;
                    dzialanie.replace(i-7,j+8,pomoc);
                    //cout<<"DUPA-"<<dzialanie<<endl;
                    break;
                }
            }
        }
    }
    for(unsigned int i=0;i<dzialanie.length()-1;i++){                   ///WRACA DO jeszcze_raz JESLI JAKIES NAWIASY NIE ZOSTALY OBLICZONE
        //cout<< "Z"<<endl;
        if(dzialanie.substr(i,1)=="("||dzialanie.substr(i,1)==")"||dzialanie.substr(i,1)=="|"||dzialanie.substr(i,1)=="{"){
            goto jeszcze_raz;
        }
    }
    for(int i=0;;i++){                                                  ///PONOWNA ZAMIANA '-' na '&' PO PETLI I ZAMIANA "--" NA '+'
        //cout<<dzialanie<<endl;
        if(dzialanie.substr(i,1)=="-"){             ///Jezeli widzi minusa
            if(dzialanie.substr(i,2)=="--"){
                dzialanie.erase(i,2);
                dzialanie.insert(i,"+");
            }
            if(czy_to_liczba(dzialanie.substr(i-1,1))==false&&dzialanie.substr(i-1,1)!=")"){   ///I z ty³u minusa jest znak to go zostawia
                continue;
            }
            else{               ///Jesli jednak przed minusem jest liczba
                dzialanie.erase(i,1); dzialanie.insert(i,"&"); ///zamienia '-' na '&'
            }
        }
        else if(dzialanie.substr(i,1)=="="){
            break;
        }
    }
    for(unsigned int i=0;i<=dzialanie.length()-3;i++){                  ///FUNKCJE TRYGONOMETRYCZNE
        if(dzialanie.substr(i,3)=="cos"){   /// COSINUS
            if(czy_to_liczba(dzialanie.substr(i-1,1))){ /// jezeli przed funkcja jest liczba dajemy pomiedzy ich "*"
                dzialanie.insert(i,"*");
                i++;
            }
            for(unsigned int j=i+3; j<dzialanie.length() ;j++){ /// wykonywanie dzialania
                if(czy_to_liczba(dzialanie.substr(j,1),1) == false){
                    if(j==i+3){ /// uzytkownik nie wprowadzil zadnej liczby
                        czy_wszystko_ok=false;
                        return 12;
                    }
                    //dzialanie.replace(i,j-i, int_na_string(zaokraglij(cos(snr(string_na_int(dzialanie.substr(i+3,j-i-3)))), 6)));
                    //cout<<dzialanie<<endl;
                    break;
                }
            }
        }
        if(dzialanie.substr(i,3)=="sin"){   /// SINUS
            if(czy_to_liczba(dzialanie.substr(i-1,1))){ /// jezeli przed funkcja jest liczba dajemy pomiedzy ich "*"
                dzialanie.insert(i,"*");
                i++;
            }
            for(unsigned int j=i+3; j<dzialanie.length() ;j++){ /// wykonywanie dzialania
                if(czy_to_liczba(dzialanie.substr(j,1),1) == false){
                    if(j==i+3){ /// uzytkownik nie wprowadzil zadnej liczby
                        czy_wszystko_ok=false;
                        return 12;
                    }

                    //dzialanie.replace(i,j-i, int_na_string(zaokraglij(sin(snr(string_na_int(dzialanie.substr(i+3,j-i-3)))), 6)));
                    //cout<<dzialanie<<endl;
                    break;
                }
            }
        }
        if(dzialanie.substr(i,3)=="tan"){   /// TANGENS
            if(czy_to_liczba(dzialanie.substr(i-1,1))){ /// jezeli przed funkcja jest liczba dajemy pomiedzy ich "*"
                dzialanie.insert(i,"*");
                i++;
            }
            for(unsigned int j=i+3; j<dzialanie.length() ;j++){ /// wykonywanie dzialania
                if(czy_to_liczba(dzialanie.substr(j,1),1) == false){
                    if(j==i+3){ /// uzytkownik nie wprowadzil zadnej liczby
                        czy_wszystko_ok=false;
                        return 12;
                    }
                    /// zabezpieczenia przed podaniem 90 stopni
                    if( sin(snr(string_na_int(dzialanie.substr(i+3,j-i-3)))) == 1 || sin(snr(string_na_int(dzialanie.substr(i+3,j-i-3)))) == -1 ){ /// musi tak byc bo tan nie dziala rowniez dla 90,-90, 270, -270 itd.
                        czy_wszystko_ok=false;
                        return 270;
                    }

                    //dzialanie.replace(i,j-i, int_na_string(zaokraglij(tan(snr(string_na_int(dzialanie.substr(i+3,j-i-3)))), 6)));
                    //cout<<dzialanie<<endl;
                    break;
                }
            }
        }
        if(dzialanie.substr(i,3)=="ctg"){   /// COTANGENS
            if(czy_to_liczba(dzialanie.substr(i-1,1))){ /// jezeli przed funkcja jest liczba dajemy pomiedzy ich "*"
                dzialanie.insert(i,"*");
                i++;
            }
            for(unsigned int j=i+3; j<dzialanie.length() ;j++){ /// wykonywanie dzialania
                if(czy_to_liczba(dzialanie.substr(j,1),1) == false){
                    if(j==i+3){ /// uzytkownik nie wprowadzil zadnej liczby
                        czy_wszystko_ok=false;
                        return 12;
                    }

                    /// zabezpieczenia przed podaniem 0 stopni
                    if( sin(snr(string_na_int(dzialanie.substr(i+3,j-i-3)))) == 0 ){ /// musi tak byc bo tan nie dziala rowniez dla 90,-90, 270, -270 itd.
                        czy_wszystko_ok=false;
                        return 270;
                    }

                    //dzialanie.replace(i,j-i, int_na_string(zaokraglij(1/(tan(snr(string_na_int(dzialanie.substr(i+3,j-i-3))))), 6)));
                    //cout<<dzialanie<<endl;
                    break;
                }
            }
        }
    }
    for(int i=0;;i++){                                                  ///SPRAWDZAMY CZY NIE MA 2 ZNAKÓW OBOK SIEBIE I CZY ZNAKI SIE ZGADZAJA
        //cout<<"KUPA"<<endl;
        if(dzialanie.substr(i,1)=="="){
            break;
       }
       else if(dzialanie.substr(i,1)=="-"&&dzialanie.substr(i+1,1)=="-"){ /// zmiana -- na +
            dzialanie.replace(i,2,"+");
            i--;

       }
       else if(czy_to_liczba(dzialanie.substr(i,1))== false && dzialanie.substr(i,1)!=")"&&dzialanie.substr(i,1)!="|"&&dzialanie.substr(i,1)!="!"){
            if(czy_to_liczba(dzialanie.substr(i+1,1))==false&&dzialanie.substr(i+1,1)!="-"&&dzialanie.substr(i+1,1)!="("&&dzialanie.substr(i+1,1)!="|"){
                czy_wszystko_ok=false;
                //cout <<"HI: "<< dzialanie.substr(i,1)<<endl<<"HII: " << dzialanie.substr(i+1,1)<<endl;
                //cout << "xD "<<endl;
                return 12;
            }
       }
    }
    for(unsigned int i=0;;i++){                                         ///WRACAMY DO POCZATKU
        if(dzialanie.length()<8||dzialanie.length()<i){
            break;
        }
        else if(dzialanie.substr(i,8)=="srednia{"){
            goto jeszcze_raz;
        }
    }
    //cout<<setprecision(12)<<"tutut "<<dzialanie<<endl;
    for(unsigned int i=0;i<dzialanie.length();i++){                     ///SPRAWDZAMY ZAOKRAGLANIE
        if(dzialanie.substr(i,1)=="$"){
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za '$'   np dla 2$4 szuka  2
                //cout<<i<<"  "<<j<<dzialanie<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                        //cout<<"jestem w srodku"<<endl;
                    liczba1=string_na_int(dzialanie.substr(i-j+1,j-1)); ///wpisujemy liczbe sprzed '@' do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed '@'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    //cout<<"PO ustaleniu liczby1 "<<dzialanie<< "liczba1-"<<liczba1<<endl;
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    cout<<dzialanie<<endl;
                    liczba2=string_na_int(dzialanie.substr(i+1,j-1)); ///Wpisujemy liczbe po '$' do liczby2
                    cout<<setprecision(1400000)<<liczba2<<endl;
                    cout<<string_na_int(dzialanie.substr(i+1,j-1))<<endl;
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba2;
                    }

                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po '$'
                     //cout<<"PO ustaleniu liczby2 "<<dzialanie<< "liczba2-"<<liczba2<<endl;
                    break;
                }
            }
            ///ZAOKRAGLAMY
            //cout<<"1-"<<liczba1<<" 2-"<<liczba2<<" "<<endl;
            //pomoc = int_na_string(zaokraglij(liczba2,liczba1));
            //cout<<pomoc<<" " << liczba2<<" " <<liczba1<<endl;
            dzialanie.replace(i,1,pomoc); i--;

        }
    }
    for(int i=0;;i++){                                                  ///SPRAWDZAMY SILNIE
        //cout<<i<<"-"<<dzialanie<<endl;
        if(dzialanie.substr(i,1)=="!"){
            //cout<<"TU"<<ENDL;
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                    pomoc=int_na_string(silnia(dzialanie.substr(i-j+1,j-1)));
                    if(czy_wszystko_ok==false){
                        czy_wszystko_ok=true;
                        int pomocny_int=string_na_int(pomoc);
                        czy_wszystko_ok=false;
                        return pomocny_int;
                    }
                    dzialanie.erase(i-j+1,j);
                    i=i-(j-1);
                    dzialanie.insert(i,pomoc);
                    //cout<<"TA PETLA POWTARZA SIE W NIESKONCZONOSC"<<endl;
                    break;
                }
            }
        }
        else if(dzialanie.substr(i,1)=="="){
            break;
        }


    }
    for(int i=0;;i++){                                                  ///SPRAWDZAMY POTEGOWANIE I PIERWIASTKOWANIE I LOGARYTMOWANIE
    //cout<< i<<"-"<<dzialanie.substr(i,1)<<"  dzialanie-"<<dzialanie<<endl;

        if(dzialanie.substr(i,1)=="^"){ ///sprawdzamy potegowanie
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za '^'   np dla 25^5 szuka  25
                //cout<<i<<"  "<<j<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                    //cout<<"liczba1-"<<dzialanie.substr(i-j+1,j-1)<<endl;
                    liczba1=string_na_int(dzialanie.substr(i-j+1,j-1)); ///wpisujemy liczbe sprzed ^ do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed '^'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    //cout<<"liczba2-"<<dzialanie.substr(i+1,j-1)<<endl;
                    liczba2=string_na_int(dzialanie.substr(i+1,j-1)); ///Wpisujemy liczbe po '^' do liczby2
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba2;
                    }
                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po '^'
                    break;
                }
            }
            //cout<<liczba1<<" "<<liczba2<<endl;
            pomoc= int_na_string(pow(liczba1,liczba2)); ///zapisujemy w stringu wynik potêgowania dwóch liczb
            dzialanie.erase(i,1); i--; ///Usuniecie '^' i przesuniecie 'i' o jeden
            dzialanie.insert(i+1,pomoc);
            continue;
        }
        else if(dzialanie.substr(i,1)=="v"){ ///Sprawdzamy pierwiastkowanie
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za 'v'   np dla 2v4 szuka  2
                //cout<<i<<"  "<<j<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                    liczba1=string_na_int(dzialanie.substr(i-j+1,j-1)); ///wpisujemy liczbe sprzed 'v' do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed 'v'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    liczba2=string_na_int(dzialanie.substr(i+1,j-1)); ///Wpisujemy liczbe po 'v' do liczby2
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba2;
                    }

                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po 'v'
                    break;
                }
            }
            ///jezeli po liczbie ktora jest po 'v' jest 'v' to pomnó¿ liczbe przed pierwszym 'v' z liczb¹ po nim.
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    if(dzialanie.substr(i+j,1)=="v"){
                        //cout<< liczba1<<" " <<liczba2<<endl;
                        pomoc=int_na_string(liczba1*liczba2);
                        dzialanie.erase(i,1);  ///usuwamy 'v'
                        //cout<< dzialanie<<endl;
                        dzialanie.insert(i,pomoc); i--;
                        //cout<< dzialanie<<endl;
                        goto koniec_pierwiastkowania;
                    }
                    break;
                }

            }
            long long szybka_pomoc_w_incie=liczba1; ///nie zmodulujesz double
            //cout<< liczba2 <<" "<<liczba1<< " "<<szybka_pomoc_w_incie<<endl;
            if(liczba2<0&&szybka_pomoc_w_incie%2==0){ ///blad z pierwiastkowaniem ujemnej liczby
                czy_wszystko_ok=false;
                return -6;
            }
            else if(liczba1==0){
                czy_wszystko_ok=false;
                return 8;
            }
            if(liczba2<0&&szybka_pomoc_w_incie%2!=0){   ///Odwracamy liczbe jesli jest ujemna
                liczba2= -liczba2;
            }
            pomoc=int_na_string(pow(liczba2,1/liczba1));
            /*    ///Liczymy pierwiastkowanie
            long double szybka_pomoc=2;
            for(;;){
                szybka_pomoc = (szybka_pomoc +  / szybka_pomoc) /2;
            }
            */
            dzialanie.erase(i,1); i--; ///usuwamy 'v'
            dzialanie.insert(i+1,pomoc);
        }
        else if(dzialanie.substr(i,1)=="@" ){ ///Sprawdzamy logaryryryryrytmowanie
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za '@'   np dla 2@4 szuka  2
                //cout<<i<<"  "<<j<<dzialanie<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                        //cout<<"jestem w srodku"<<endl;
                    liczba1=string_na_int(dzialanie.substr(i-j+1,j-1)); ///wpisujemy liczbe sprzed '@' do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed '@'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    //cout<<"PO ustaleniu liczby1 "<<dzialanie<< "liczba1-"<<liczba1<<endl;
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    liczba2=string_na_int(dzialanie.substr(i+1,j-1)); ///Wpisujemy liczbe po '@' do liczby2
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba2;
                    }

                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po '@'
                     //cout<<"PO ustaleniu liczby2 "<<dzialanie<< "liczba2-"<<liczba2<<endl;
                    break;
                }
            }
            /// BLEDY
            if( liczba1 < 0 ){
                czy_wszystko_ok=false;
                return -1;
            }
            if(liczba1 == 0){
                czy_wszystko_ok=false;
                return -10;
            }
            if(liczba1 == 1){
                czy_wszystko_ok=false;
                return -11;
            }
            if(liczba2 < 0){
                czy_wszystko_ok=false;
                return -100;
            }

            /// ALGORYTM NA LOGARYTM
            //cout<<"algorytm na logarytm"<<endl;
            //cout<<"logarytm naturalny z podstawy- "<<log(liczba1)<<endl;
            pomoc = int_na_string((log(liczba2))/(log(liczba1)));
            //cout<< pomoc<<endl;
            dzialanie.erase(i,1);   ///usuwamy '@'
            dzialanie.insert(i,pomoc); i--;
            //cout<<dzialanie<<endl;
        }
        koniec_pierwiastkowania: ;
        if(dzialanie.substr(i,1)=="="){
            //cout<<"tu tu ruu"<<endl;
            break;
        }
    }
    for(int i=0;;i++){                                                  ///SPRAWDZAMY MNOZENIE I DZIELENIE I MODULO
        if(dzialanie.substr(i,1)=="*"){             ///SPRAWDZAMY MNOZENIE
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za '*'   np dla 25*5 szuka  25
                //cout<<i<<"  "<<j<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                    //cout<<"liczba1-"<<dzialanie.substr(i-j+1,j-1)<<endl;
                    liczba1=string_na_int(dzialanie.substr(i-j+1,j-1)); ///wpisujemy liczbe sprzed * do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed '*'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    //cout<<"liczba2-"<<dzialanie.substr(i+1,j-1)<<endl;
                    liczba2=string_na_int(dzialanie.substr(i+1,j-1)); ///Wpisujemy liczbe po '*' do liczby2
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba2;
                    }
                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po '*'
                    break;
                }
            }
            //cout<<liczba1 <<endl <<liczba2<<endl;
            pomoc= int_na_string(liczba1*liczba2); ///zapisujemy w stringu wynik mno¿enia
            dzialanie.erase(i,1); i--; ///Usuniecie '*' i przesuniecie 'i' o jeden
            dzialanie.insert(i+1,pomoc);
            continue;
        }
        else if(dzialanie.substr(i,1)=="/"){        ///SPRAWDZAMY DZIELENIE
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za '/'   np dla 2/4 szuka  2
                //cout<<i<<"  "<<j<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                    //cout<<"liczba1-"<<dzialanie.substr(i-j+1,j-1)<<endl;
                    liczba1=string_na_int(dzialanie.substr(i-j+1,j-1)); ///wpisujemy liczbe sprzed / do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed '/'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    liczba2=string_na_int(dzialanie.substr(i+1,j-1)); ///Wpisujemy liczbe po '/' do liczby2
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba2;
                    }
                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po '/'
                    break;
                }
            }
            if(liczba2==0){ ///Sprawdzamy dzielenie przez 0
                czy_wszystko_ok=false;
                return 6;
            }
            pomoc=int_na_string(liczba1/liczba2);///Liczymy dzielenie
            dzialanie.erase(i,1); i--;
            dzialanie.insert(i+1,pomoc);
        }
        else if(dzialanie.substr(i,1)=="%"){        ///SPRAWDZAMY MODULO
            string liczba1_string,liczba2_string;
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za '%'   np dla 25%5 szuka  25
                //cout<<i<<"  "<<j<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                    //cout<<"liczba1-"<<dzialanie.substr(i-j+1,j-1)<<endl;
                    liczba1_string=dzialanie.substr(i-j+1,j-1); ///wpisujemy liczbe sprzed % do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed '%'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    //cout<<"liczba2-"<<dzialanie.substr(i+1,j-1)<<endl;
                    liczba2_string=dzialanie.substr(i+1,j-1); ///Wpisujemy liczbe po '%' do liczby2
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        //cout << "gowno";
                        return liczba2;
                    }
                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po '%'
                    break;
                }
            }
            //string pomocny_string= liczba1_string+" "+liczba2_string;
            //cout<<liczba1_string <<endl <<liczba2_string<<endl;
            long long szybka_pomoc_w_incie=modulo(liczba1_string+" "+liczba2_string);
            if(czy_wszystko_ok==false){
                return szybka_pomoc_w_incie;
            }
            pomoc= int_na_string(szybka_pomoc_w_incie); ///zapisujemy w stringu wynik modulo
            dzialanie.erase(i,1); i--; ///Usuniecie '%' i przesuniecie 'i' o jeden
            dzialanie.insert(i+1,pomoc);
            //cout<<dzialanie<<endl;
            continue;
        }
        else if(dzialanie.substr(i,1)=="="){
            break;
        }
    }
    for(int i=0;;i++){                                                  ///SPRAWDZAMY DODAWANIE I ODEJMOWANIE
        if(dzialanie.substr(i,1)=="+"){ ///sprawdzamy dodawanie
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za '+'   np dla 25+5 szuka  25
                //cout<<i<<"  "<<j<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                    //cout<<"liczba1-"<<dzialanie.substr(i-j+1,j-1)<<endl;
                    liczba1=string_na_int(dzialanie.substr(i-j+1,j-1)); ///wpisujemy liczbe sprzed + do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed '+'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    //cout<<"liczba2-"<<dzialanie.substr(i+1,j-1)<<endl;
                    liczba2=string_na_int(dzialanie.substr(i+1,j-1)); ///Wpisujemy liczbe po '+' do liczby2
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        return liczba2;
                    }
                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po '+'
                    break;
                }
            }
            //cout<<liczba1 <<endl <<liczba2<<endl;
            pomoc= int_na_string(liczba1+liczba2); ///zapisujemy w stringu wynik dodawnia
            dzialanie.erase(i,1); i--; ///Usuniecie '+' i przesuniecie 'i' o jeden
            dzialanie.insert(i+1,pomoc);



            continue;
        }
        else if(dzialanie.substr(i,1)=="&"){ ///Sprawdzamy odejmowanie
            for(int j=1;;j++){ ///Szuka koñca liczby stoj¹cej za '&'   np dla 2-4 szuka  2
                //cout<<i<<"  "<<j<<endl;
                if(czy_to_liczba(dzialanie.substr(i-j,1))==false&&dzialanie.substr(i-j,1)!="-"&&dzialanie.substr(i-j,1)!="."){
                    //cout<<"liczba1-"<<dzialanie.substr(i-j+1,j-1)<<endl;
                    liczba1=string_na_int(dzialanie.substr(i-j+1,j-1)); ///wpisujemy liczbe sprzed & do liczby1
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        return liczba1;
                    }
                    dzialanie.erase(i-j+1,j-1); ///usuwamy z napisu liczbe przed '&'
                    i=i-(j-1); ///przesuwamy 'i' o tyle kratek w lewo ile usunelismy kratek w tablicy
                    break;
                }
            }
            for(int j=1;;j++){
                if(czy_to_liczba(dzialanie.substr(i+j,1))==false&&dzialanie.substr(i+j,1)!="-"&&dzialanie.substr(i+j,1)!="."){
                    //cout<<"liczba2-"<<dzialanie.substr(i+1,j-1)<<endl;
                    liczba2=string_na_int(dzialanie.substr(i+1,j-1)); ///Wpisujemy liczbe po '&' do liczby2
                    if(czy_wszystko_ok==false){ ///sprawdzamy bledy
                        return liczba2;
                    }
                    dzialanie.erase(i+1,j-1);/// usuwamy liczbe po '&'
                    break;
                }
            }
            pomoc=int_na_string(liczba1-liczba2);///Liczymy odejmowanie
            dzialanie.erase(i,1); i--;
            dzialanie.insert(i+1,pomoc);
        }
        else if(dzialanie.substr(i,1)=="="){
            break;
        }

    }
    //cout<<czy_wszystko_ok<<Endl;
    dzialanie.erase(0,1);  dzialanie.erase(dzialanie.length()-1,1);///usuwamy # na poczatku i = na koncu
    //cout<<dzialanie<<endl;
    wynik=string_na_int(dzialanie);
    if(wynik==-0) wynik = 0;
    //cout<<"wynik-"<<wynik<<endl;

    string pomocny_string= int_na_string(wynik);

    for(unsigned int i=0;i<pomocny_string.length()-1;i++){
        if(pomocny_string.substr(i,1)=="."){
             cout<<setprecision(11);
        }
    }

    if(czy_wszystko_ok==false){
        //cout<<czy_wszystko_ok<<ENDL;
        return wynik;
    }

    return 0;
}

void sprawdzanie_godziny_w_innym_kraju(string kraj, int nasz_kolor, int kolor_saturnina){
    bool czy_byl_kraj = false; ///Na poczatku zakladamy ze kraju nie bylo
    fstream inne_kraje;
    int ilosc_linii= 0;
    float strefa_czasowa;
    string pomocna_zmienna, tak, help;
    inne_kraje.open("../Pliki/Godzina w innym kraju",ios::in);
    while(getline(inne_kraje, pomocna_zmienna))
    {
        if(ilosc_linii%2 == 0&&kraj == pomocna_zmienna) ///Co dwa sa kraje no i sprawdzamy czy mamy taki kraj
        {
            getline(inne_kraje,pomocna_zmienna); ///Wczytujemy strefe czasowa
            strefa_czasowa = atof(pomocna_zmienna.c_str()); ///Wczytujemy jako string wiec zmieniamy na inta
            cout << "W stolicy tego kraju jest: ";
            help = sprawdzanie_czasu(strefa_czasowa-1.0); ///Odsylamy do sprawdzenia czasu, -1 bo jestesmy w pierwszej strefie a on bierze pod uwage lokalny czas
            cout << help <<endl ;
            czy_byl_kraj = true; ///Kraj byl
            break;
        }
    }
    inne_kraje.close();
    if(!czy_byl_kraj) ///Jesli nie bylo kraju
    {
        cout << "Nie mam kraju w bazie danych!"<<endl;
        bledna_odpowiedz:
        cout<<"Czy chcesz wprowadzic kraj do bazy danych ?(Podaj Tak lub Nie)"<<endl;
        boze:
        saturnin_mowi(nasz_kolor);
        getline(cin,tak);
        saturnin_mowi(kolor_saturnina);
        tak = usp(modp(tak),1);
        if(tak == "") goto boze;
        if(tak == "tak")
        {
            cout << "Wprowadz strefe czasowa tego kraju: ";
            saturnin_mowi(nasz_kolor);
            string pomoc;
            getline(cin,pomoc);
            saturnin_mowi(kolor_saturnina);
            if(czy_jest_spacja(usp(pomoc,0,0,1,1)) == true)  ///Wiecej liczb
            {
                czy_wszystko_ok = false ;
                sprawdzacz_bledow(113);
                goto koniec;
            }
            strefa_czasowa = string_na_int(pomoc);
            if(strefa_czasowa != trunc(strefa_czasowa)&&strefa_czasowa - trunc(strefa_czasowa)!=0.5)
            {
                saturnin_mowi(kolor_saturnina);
                   cout << "Strefy czasowe to tylko liczby ca\210kowite oraz po\210owki\n";
                   goto koniec;
            }
            else if(strefa_czasowa < -12 || strefa_czasowa > 12) /// Strefy czasowe sa od -12 do 12
            {
                saturnin_mowi(kolor_saturnina);
                cout << "Tyko przypominam ze strefy czasowe sa od -12 do 12\n";
                goto koniec;
            }
            saturnin_mowi(kolor_saturnina);

            inne_kraje.open("../Pliki/Godzina w innym kraju",ios::out|ios::app);
            inne_kraje << kraj << endl << strefa_czasowa << endl; ///Wpisujemy kraj do pliku
            inne_kraje.close();
            cout << "Baza danych zaktualizowana, kraj dostepny!"<<endl;
        }
        else if(tak == "nie") cout << "Rozumiem"<<endl;
        else {cout << "Bledna odpowiedz nalezy podac \"Tak\" lub \"Nie\"\n";goto bledna_odpowiedz;}
        koniec:
        ;
    }
}

void sprawdzanie_godziny_w_innym_miescie(string miasto, int nasz_kolor, int kolor_saturnina){
    bool czy_bylo_miasto = false; ///Na poczatku zakladamy ze kraju nie bylo
    fstream inne_miasta;
    int ilosc_linii= 0;
    float strefa_czasowa = 0;
    string pomocna_zmienna, tak, help;
    inne_miasta.open("../Pliki/Godzina w innych miastach",ios::in);
    while(getline(inne_miasta, pomocna_zmienna))
    {
        if(ilosc_linii%2 == 0&&miasto == pomocna_zmienna) ///Co dwa sa kraje no i sprawdzamy czy mamy taki kraj
        {
            getline(inne_miasta,pomocna_zmienna); ///Wczytujemy strefe czasowa
            strefa_czasowa = atof(pomocna_zmienna.c_str()); ///Wczytujemy jako string wiec zmieniamy na inta
            cout << "W tym miescie jest: ";
            help = sprawdzanie_czasu(strefa_czasowa-1.0); ///Odsylamy do sprawdzenia czasu, -1 bo jestesmy w pierwszej strefie a on bierze pod uwage lokalny czas
            cout << help <<endl ;
            czy_bylo_miasto = true; ///Kraj byl
            break;
        }
    }
    inne_miasta.close();
    if(!czy_bylo_miasto) ///Jesli nie bylo kraju
    {
        cout << "Nie mam miasta w bazie danych!"<<endl;
        bledna_odpowiedz:
        cout<<"Czy chcesz wprowadzic miasto do bazy danych ?(Podaj Tak lub Nie)"<<endl;
        maj_gad:
        saturnin_mowi(nasz_kolor);
        getline (cin,tak);
        saturnin_mowi(kolor_saturnina);
        tak = usp(modp(tak));
        if(tak == "") goto maj_gad;
        if(tak == "tak")
        {
            cout << "Wprowadz strefe czasowa tego miasta: ";
            saturnin_mowi(nasz_kolor);
            string pomoc;
            getline(cin,pomoc);
            saturnin_mowi(kolor_saturnina);
            if(czy_jest_spacja(usp(pomoc,0,0,1,1)) == true)  ///Wiecej liczb
            {
                czy_wszystko_ok = false ;
                sprawdzacz_bledow(113);
                return;
            }
            strefa_czasowa = string_na_int(pomoc);
            if(strefa_czasowa != trunc(strefa_czasowa)&&strefa_czasowa - trunc(strefa_czasowa)!=0.5)
            {
                saturnin_mowi(kolor_saturnina);
                   cout << "Strefy czasowe to tylko liczby ca\210kowite oraz po\210owki\n";
                   return;
            }
            else if(strefa_czasowa < -12 || strefa_czasowa > 12) /// Strefy czasowe sa od -12 do 12
            {
                saturnin_mowi(kolor_saturnina);
                cout << "Tyko przypominam ze strefy czasowe sa od -12 do 12\n";
                return;
            }
            saturnin_mowi(kolor_saturnina);

            inne_miasta.open("../Pliki/Godzina w innych miastach",ios::out|ios::app);
            inne_miasta << miasto << endl << strefa_czasowa << endl; ///Wpisujemy kraj do pliku
            inne_miasta.close();
            cout << "Baza danych zaktualizowana, miasto dostepne!"<<endl;
        }
        else if(tak == "nie") cout << "Rozumiem"<<endl;
        else {cout << "Bledna odpowiedz nalezy podac \"Tak\" lub \"Nie\"\n";goto bledna_odpowiedz;}
    }
}

int l_pierwsza(string napis){ /// Funkcja nie moze byc bool gdyz errory zwraca w intach
    unsigned long long liczba; long double wynik=0;
    napis=usp(napis,0,1,1,1);
    napis.insert(napis.length(),"=");
    if(napis.length()>17){
        czy_wszystko_ok=false;
        return 404;
    }
    if(napis=="1="||napis=="0="){
        return 0;
    }
    for(unsigned long long i=0;i<napis.length();i++){
        if(czy_to_liczba(napis.substr(i,1))==true){
            continue;
        }
        else if(napis.substr(i,1)=="="){
            liczba=string_na_int(napis.substr(0,i));
            if(czy_wszystko_ok==false){
                return 404;
            }
            goto wyjscie;
        }
        else if(napis.substr(i,1)=="."){ ///Zmiennoprzecinkowa liczba nie zwraca bledu
            return 0;
        }
        else if(napis.substr(i,1)==" "){ ///Podano wiecej liczb
            czy_wszystko_ok=false;
            return 113;
        }
        else if(napis.substr(i,1)=="-"){ ///Ujemna liczba nie zwraca bledu
            return 0;
        }
        else{
            czy_wszystko_ok=false;
            return 112;
        }
    }
    czy_wszystko_ok=false;///<--- to chyba nie ma sensu bo jest zabezpieczenie w ifie ale zostawie na wszelki
    return 113;
    wyjscie:
    //cout<< y;
    if(czy_wszystko_ok==false){
        return liczba;
    }
    for(unsigned long long i=1;i<=liczba;i++)
        {
            if(liczba%i==0)
            {
                wynik++;
            }
        }
    cout<<setprecision(16);
    return wynik<=2 ? 1:0; /// uhuhuhuhu usprawnienie

czy_wszystko_ok=false;  ///No jak tu dojdzie to tragedia
return 10;
}

int zmien_twoj_kolor(int kolor_saturnina,int nasz_kolor,string odp, string &czyszczenie){
fstream plik; int nr_linii=0; string linia;
odp=usp(odp);
transform(odp.begin(),odp.end(),odp.begin(),::tolower);
//cout<< odp<<endl;
plik.open("../Pliki/dostepne_kolory",ios::in); string lokacja;
if(plik.good()==false) return 1;
    while (getline(plik,linia)){
        nr_linii++;
        linia = usp(modp(linia));
        if(linia==odp){
            break;
        }
        if(linia == "witaj"){czyszczenie = "Koloru nie ma w bazie danych!";goto nie_ma_koloru;}
    }
    plik.close();

    plik.open("../Pliki/lokalizacja",ios::in);

    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/kolory";

    plik.open(lokacja.c_str(),ios::out); ///TU
    if(plik.good()==false) return 1;
    plik << nr_linii << endl << nasz_kolor;
    plik.close();
    saturnin_mowi(nr_linii);
    czyszczenie = "Zmiana koloru powiodla sie!";
    //cout<< nr_linii<<endl;
    return nr_linii;
    nie_ma_koloru:
    return kolor_saturnina;
}

int losowanie(string napis){
    int ilosc_spacji = 0; long double liczba1 = 0, liczba2 = 0;
    napis = usp(napis,0,0,1,1);

    for(unsigned int i=0;i < napis.length();i++)
    {
       // cout << odp.substr(i,1) <<endl;
       if(czy_to_liczba(napis.substr(i,1)) == false&&napis.substr(i,1)!=" " && napis.substr(i,1) != "-" &&napis.substr(i,1) != "."&&napis.substr(i,1) != ",") ///Jesli jest napis czy cokolwiek innego np 2.5
        {
            //cout << ilosc_spacji << " " <<odp.substr(i,1)<<endl;
            czy_wszystko_ok = false ;
            return 112;
        }
        ///Liczba po przecinku
        else if(napis.substr(i,1) == "."&&napis.substr(i,1) == ",")
        {
            czy_wszystko_ok = false ;
            return 69;
        }
        else if(napis.substr(i,1) == "-")
        {
            string help = napis.substr(i+1,napis.length() - (i+1));
            help = usp(help,0,0,1);
            napis.replace(i+1,napis.length()-(i+1),help);

        }
        else if(napis.substr(i,1) == " ")
        {
            ilosc_spacji ++; ///Zwiekszamy ilosc spacji po petli sprawdzimy ile jest spacji
        }
       // cout << "Ilosc spacji to: " << ilosc_spacji << endl;
    }
    if(ilosc_spacji > 1)
    {
        czy_wszystko_ok = false;
        return 113;
    }
    ///Za malo danych
    else if(ilosc_spacji < 1)
    {
        liczba1 = 1;
        napis.insert(napis.length(), " ");
    }
    ///Za duza liczba, moze za mala, moze ma za duzo po przecinku
    for(unsigned int i = 0;i<napis.length();++i)
    {
        if(napis.substr(i,1) == " ")
        {
            string pomoc = napis.substr(0,i);
            if(pomoc.length() > 28)
            {
                czy_wszystko_ok = false;
                return 90;
            }
            pomoc = napis.substr(i+1,napis.length() - (i+1));
            if(pomoc.length() > 28)
            {
                czy_wszystko_ok = false;
                return 90;
            }
            if(liczba1 == 1)
            {
                liczba2 = string_na_int(napis.substr(0,i));
            }
            else
            {
                liczba1 = string_na_int(napis.substr(0,i)) ;
                liczba2 = string_na_int(napis.substr(i+1,napis.length() - (i+1))) ;
            }
        }
    }
    ///Minimum nie moze byc wieksze od maksimum
    if(liczba1 > liczba2)
    {
        czy_wszystko_ok = false ;
        return 91;
    }
    //cout << liczba1 << endl;
    //cout << liczba2 << endl;
    long long help = liczba2 - liczba1 + 1; ///Plus jeden musi byc tutaj
    //cout << "roznica: " << help << endl;
    ///Robimy modulo roznice z liczb i plus pierwsza liczba bo ta roznica jest pomiedzy nimi
    return (rand() % help) + liczba1;
}

int zmien_moj_kolor(int kolor_saturnina,int nasz_kolor, string odp, string &czyszczenie){
    odp=usp(modp(odp));
    //transform(odp.begin(),odp.end(),odp.begin(),::tolower);
    fstream plik; int nr_linii = 0; string linia;string lokacja;
    plik.open("../Pliki/dostepne_kolory",ios::in);
    if(plik.good()==false) return 1;
    while (getline(plik,linia)){
        nr_linii++;
        if(usp(modp(linia))==odp){
            break;
        }
        if(linia == "WITAJ") {czyszczenie = "Koloru nie ma w bazie danych!"; goto niemakoloru;}
    }
    plik.close();

    plik.open("../Pliki/lokalizacja",ios::in);

    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/kolory";

    plik.open(lokacja.c_str(),ios::out);  ///TU
    plik<< kolor_saturnina <<endl << nr_linii <<endl;
    plik.close();
    saturnin_mowi(kolor_saturnina);
    czyszczenie = "Zmiana koloru powiodla sie!";
    return nr_linii;
    niemakoloru:
    return nasz_kolor;
    }

void zegnaj(int kolor,string odp){
    string pozegnanie [] = {"Trzymaj sie","Papa","Bywaj","Zegnaj","Zegnam","Slodkich snow","Milej nocy","Dobranoc"};
    string czas = sprawdzanie_czasu(0);
    saturnin_mowi(kolor);
    if(string_na_int(czas.substr(0,2)) > 5 && string_na_int(czas.substr(0,2)) < 20)
    {
        int x = rand() % 5;
        cout << pozegnanie[x] <<"!"<< endl ;
    }
    else
    {
        int x = rand() % 8;
        cout << pozegnanie[x] <<"!"<< endl ;
    }
}

void przywitanie(){
    fstream plik; string linia;
    string przywitania [20];
    int licznik = 0;
    plik.open("../Pliki/Przywitania",ios::in);
    while(getline(plik,linia))
    {
        przywitania[licznik] = linia;
        licznik ++ ;
    }
    plik.close();
    string czas = sprawdzanie_czasu(0);
    if(string_na_int(czas.substr(0,2)) > 5 && string_na_int(czas.substr(0,2)) < 20)
    {
        int x = rand() % 8;
        cout << przywitania[x] <<"!"<< endl ;
    }
    else
    {
        int x = (rand()%8) +1;
        cout << przywitania[x] <<"!"<< endl ;
    }
}

void segregowanie (string dzialanie){
    lista_globalna.clear();  /// Swietosc swietosci prosze nie tykac bo bedziemy godzine szukac o co chodzi
    dzialanie=usp(dzialanie,0,0,1,1);
    dzialanie.insert(dzialanie.length(),"=");     ///dodajemy = sie zeby wywalal petle nizej
    for(int j = 0;; j++){
        for(unsigned int i=0; i<dzialanie.length(); i++){
            if(czy_to_liczba(dzialanie.substr(i,1))== true){    ///jesli to liczba idzie dalej
                continue;
            }
            else if(dzialanie.substr(i,1)==" "){    ///jesli to spacja (spacja jest po liczbie) przypisuje ta liczbe do listy
                lista_globalna.push_front(string_na_int(dzialanie.substr(0,i)));     ///dodaje na poczatku listy -> string na int z -> dzialania przed spacja
                dzialanie.erase(0,i+1);   ///usuwa ta liczbe ze spacja zeby mozna znowu zrobic to samo
                break;
            }
            else if(dzialanie.substr(i,1)=="="){  ///jesli to = (= jest po liczbie) przypisuje ta liczbe do listy
                lista_globalna.push_front(string_na_int(dzialanie.substr(0,i)));   ///dodaje na poczatku listy -> string na int z -> dzialania przed =
                goto funkcja;    ///idzie sobie bo trafil na =
            }
        }
    }
    funkcja:
    lista_globalna.sort();  ///wesolo sortujemy liste
    ///Pomocne cout moga sie przydac v
    //cout<<"Oto rozmiar listy - "<<liczba.size()<<endl;
    //for(list<long double> ::iterator i = liczba.begin(); i != liczba.end(); ++i)
                            //{
                               // cout<<*i<<" ";
                           // }
}

int wzor(int kolor,int kolor2){





// TU PISZESZ KACPEREK


}

int dzielniki(string dzialanie){
    long long liczba=0, polowa=0;    ///Musi byc int bo zwraca komunikaty o bledach w int
    dzialanie=usp(dzialanie,0,0,1,1);
{
    string pomoc = usp(dzialanie);
    if(pomoc.length() > 19)
    {
        czy_wszystko_ok = false;
        return 404;
    }
}
    dzialanie.insert(dzialanie.length(),"=");
    if(dzialanie.substr(0,1)=="-") dzialanie.erase(0,1); ///jesli ma na poczatku - to usuwa go bo wynik i tak bedzie taki sam dla dodatniej liczby
    for(unsigned int i=0;i<=dzialanie.length();i++){
       if(czy_to_liczba(dzialanie.substr(i,1))==true){
            continue;
       }
       else if(dzialanie.substr(i,1)=="="){
            liczba=string_na_int(dzialanie.substr(0,i));
            if(czy_wszystko_ok==false){
                return liczba;
            }
            break;
       }
       else if(dzialanie.substr(i,1)==" "){
            czy_wszystko_ok=false;
            return 113;
       }
       else if(dzialanie.substr(i,1)=="."){
            czy_wszystko_ok=false;
            return 69;
       }
       else {
            czy_wszystko_ok=false;
            return 112;
       }
    }
    polowa=liczba+1/2; ///ten plus jeden jest po to zeby dzielnikami 1 byl 1 i -1
    for( long long i=1;i<=polowa;i++){
        if(liczba%i==0){
            lista_globalna.push_front(i);
        }
    }
    lista_globalna.sort();
}

long double modulo(string napis){
    list <long double> lista;
    double liczba[2];
    napis=ptok(napis);
     liczba[1]=0; /// <-- JESLI ZMIENISZ TE LICZBY POCZATKOWE TO BEDZIEMY GODZINY SZUKAC PROBLEMU
    napis=usp(napis,0,0,1,1);
    //cout <<napis<<endl;
    napis.insert(napis.length(),"=");
  // cout <<napis<<endl;
    for(int i=0;i<napis.length();i++){
        if(napis.substr(i,1)=="."){
            czy_wszystko_ok=false;
            return 69;
        }
    }
    for(int j=0;j<2;j++){
        for(unsigned int i=0;i<=napis.length()-1;i++){
            //cout<< napis<< "   i= "<< i <<endl;
            if(napis.substr(i,1)==" "){ ///spytasz czemu nie erasowaæ o 1 liczby wiecej? To jak chcesz zrobiæ wiecej spacji miedzy liczbami? powiem jak-nie zrobisz
                napis.erase(i,1);
                j--;  ///NIE PYTAJ CO SIE TU DZIEJE TAK MA BYYYYYYYÆ BO DZIA£A
                break;
            }
            else  if(napis.substr(i,1)=="0"||napis.substr(i,1)=="1"||napis.substr(i,1)=="2"||napis.substr(i,1)=="3"||napis.substr(i,1)=="4"||
                    napis.substr(i,1)=="5"||napis.substr(i,1)=="6"||napis.substr(i,1)=="7"||napis.substr(i,1)=="8"||napis.substr(i,1)=="9"){
                        if(napis.substr(i+1,1)==" "){ ///Jesli znak pozniej to spacja wsadzamy cala wczesniejsza liczbe do zmiennej i usuwamy liczbe z napisu
                            //cout <<"( ) Wsadzamy to pod liczbe "<< j << "-"<< napis.substr(0,i+1)<<endl;
                            liczba[j]=string_na_int(napis.substr(0,i+1));
                            if(czy_wszystko_ok==false){ ///sprawdzamy errory z string_na_int
                                return liczba[0];
                            }
                            napis.erase(0,i+2);
                            break;
                        }
                        else if(napis.substr(i+1,1)=="="){ ///Jesli znak pozniej to = wsadzamy cala wczesniejsza liczbe do zmiennej i wychodzimy z petli
                            //cout <<"(=) Wsadzamy to pod liczbe "<< j << "-"<< napis.substr(0,i+1)<<endl;
                            liczba[j]=string_na_int(napis.substr(0,i+1));
                            if(czy_wszystko_ok==false){ ///sprawdzamy errory z string_na_int
                                return liczba[j];
                            }
                            else if(j==1 && liczba[1]==0){ ///sprawdzamy czy druga liczba nie jest 0 , gdyz nie mozna dzielic przez 0
                                czy_wszystko_ok=false;
                                return 6;
                            }
                            //cout << "TY SMIECIU"<< endl;
                            goto wyjscie;
                        }
                        continue;
                    }
            else if(napis.substr(i,1)!="0" && napis.substr(i,1)!="1" && napis.substr(i,1)!="2" && napis.substr(i,1)!="3" && napis.substr(i,1)!="4" && napis.substr(i,1)!="." &&
                 napis.substr(i,1)!="5" && napis.substr(i,1)!="6" && napis.substr(i,1)!="7" && napis.substr(i,1)!="8" && napis.substr(i,1)!="9" && napis.substr(i,1)!="-" ){
                czy_wszystko_ok=false;
                return 112; ///jesli podal nieznany znak
            }
        }
    }
    czy_wszystko_ok=false;
    return 113;
    wyjscie:
   // cout << liczba[0] <<"   " <<liczba[1]<< endl;
    long long liczba2[2];
    for(int i=0;i<2;i++){ ///Zamieniamy liczby na inty by móc uzyc funkcji modulo, przy okazji sprawdzaj¹c czy s¹ zmiennoprzecinkowe
        liczba2[i]=liczba[i];
        if(liczba[i]!=liczba2[i]){
            czy_wszystko_ok= false;
            //cout<<liczba[i]<<" " <<liczba2[i]<<ENDL;
            return 404;
        }
    }
    if(liczba[1]==0){ ///MIALEM PRZEBLYSK GENIUSZU, TU NIE SPRAWDZAMY CZY WPISANO DRUGA LICZBE ON TU SPRAWDZA CZY NIE WPISAL ZADNEJ DRUGIEJ LICZBY
        czy_wszystko_ok=false;
        return 1;
    }
  // cout << liczba[0]<< " " << liczba[1] <<endl;
    return liczba2[0]%liczba2[1]; ///No i gitara
}

long long int dzielenie(string dzialanie){ ///Dzielenie po prostu
    long double liczba[2]={10, 10};
    dzialanie=usp(dzialanie,0,0,1,1);
    dzialanie.insert(dzialanie.length(),"=");
    for(int j=0;j<2;j++){
        for(unsigned int i=0;i<dzialanie.length();i++){
            if(dzialanie.substr(i,1)==" "){
                dzialanie.erase(i,1);
                j--;  ///NIE PYTAJ CO SIE TU DZIEJE TAK MA BYYYYYYYÆ BO DZIA£A ,edit: po godzinie zastanawiania sie o co chodzi poj¹³em i uwa¿am ¿e jest to co najmniej genialne
                break;
            }
            else if(czy_to_liczba(dzialanie.substr(i,1))==true){ ///Wykorzysujac pewna zajebista funkcje sprawdzamy czy znak jest liczba
                if(dzialanie.substr(i+1,1)==" "){
                    liczba[j]= string_na_int(dzialanie.substr(0,i+1));
                    if(czy_wszystko_ok==false){
                        return liczba[j];
                    }
                    dzialanie.erase(0,i+2);
                    break;
                }
                else if(dzialanie.substr(i+1,1)=="="){
                    liczba[j]= string_na_int(dzialanie.substr(0,i+1));
                    if(czy_wszystko_ok==false){
                        return liczba[j];}
                    goto wyjscie;
                }
            }
            else {
                czy_wszystko_ok=false;
                return 112;
            }
        }
    }
    czy_wszystko_ok=false; return 113; ///Jesli wyjdzie z petli oznacza to ze chciano wpisac za duzo liczb i zwraca blad
    wyjscie:
        long long int wynik=liczba[0]/liczba[1]; ///Zapisujemy w incie zeby zaokraglil w dó³
        return wynik;
}

bool palindrom(string napis){
    for(unsigned int i=0;i<=napis.length();i++){
        if(i==napis.length()){

            return true;
        }
        else if(napis.substr(i,1)==napis.substr(napis.length()-i-1,1)){
            continue;
        }
        else return false;
    }
}

int zapis(string napis,int kolor,int kolor2,string &czyszczenie){
fstream plik; string help;
//cout << "W funkcji zapis: czyszczenie = "<<czyszczenie<<endl;
getch();
plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/zapis";

plik.open(lokacja.c_str(), ios::in);
getline(plik,help);
plik.close();
plik.open(lokacja.c_str(),ios::out | ios::app);
if(plik.good()==false){ saturnin_mowi(kolor); czyszczenie = "Mam problem z odczytem pliku!"; return 0;}
napis.erase(0,1);
plik << (help == "" ? "": "\n");
plik << napis;
plik.close();
saturnin_mowi(kolor); czyszczenie = "Zapis zakonczony powodzeniem!";
//cout << "W funkcji zapis an koniec: czyszczenie = "<<czyszczenie<<endl;
getch();
}

long double procent(string dzialanie, short int tryb){


    dzialanie=usp(dzialanie,0,1,1,1,"","");
    dzialanie.insert(dzialanie.length(),"=");


    bool ip=false; ///zaoszczedzammyyy mieeeejsce

    for(unsigned long long i=0;i<dzialanie.length();i++){ ///sprawdzamy czy nie ma 2 lub wiecej '%'
        if(ip==false && dzialanie.substr(i,1)=="%" ) ip= true;
   else if(ip==true && dzialanie. substr(i,1)=="%"){
            czy_wszystko_ok=false;
            return 37;
        }

        if(ip==true && tryb==1){
            czy_wszystko_ok=false;
            //cout<<"AAA"<<endl;
            return 112;
        }

    }

    //cout<<dzialanie<<endl;
    for(unsigned long long i=1;i<dzialanie.length();i++){ ///Usuwacz spacji przed procentem /// zaczynamy usuwac od 2 znaku zeby nie bylo bledu 2 linijki nizej
        //cout<< dzialanie.substr(i,1)<<"   dzialanie:"<<dzialanie<<endl;
        if(dzialanie.substr(i,1)=="%" && dzialanie.substr(i-1,1)==" "){
            dzialanie.erase(i-1,1); ///ta tutaj
            i--;
        }
    }
    //cout<<dzialanie<<endl;
    long double liczba[2]={0,0};

    for(unsigned long long i=0;i<dzialanie.length();i++){ ///jeden z errorow 112
        //cout<< dzialanie.substr(i,1)<<endl;
        if(czy_to_liczba(dzialanie.substr(i,1))==false && dzialanie.substr(i,1)!= "-" && dzialanie.substr(i,1)!= "." && dzialanie.substr(i,1)!= " " && dzialanie.substr(i,1)!= "="  && dzialanie.substr(i,1)!= "%"){
            czy_wszystko_ok=false;
            //cout<<"bum"<<ENDL;
            return 112;
        }
    }

    string sliczba[2]={"kupa", "kupa2"};

    for(unsigned long long int i=0;i<dzialanie.length();i++){ ///przypisywanie pod sliczby liczb w stringu
        //cout<<"wal sie"<<endl;
        if(dzialanie.substr(i,1) == " "){
            //cout<<"Co do chuja?"<<endl;
            sliczba[0]=dzialanie.substr(0,i);
            dzialanie.erase(0,i+1);

            if(dzialanie.substr(0,dzialanie.length()-1)=="="){
                czy_wszystko_ok=false;
                return 1;
            }
            sliczba[1]=dzialanie.substr(0,dzialanie.length()-1);
            break;
        }
    }
    //cout<<"x '"<< sliczba[0]<<"' '"<<sliczba[1]<<"'"<<endl;

    for(unsigned long long j=0;;){ ///przypisujemy pod liczbe[0] i [1] sliczby w zaleznosci od tego gdzie sa '%'
        //cout<< sliczba[j].substr(sliczba[j].length()-1,1)<<" dzialanie-"<< sliczba[j]<<endl;
        if(sliczba[j].substr(sliczba[j].length()-1,1)=="%"){ /// 'j' jest to numer w tablicy sliczby ktora aktualnie sprawdzamy

            //cout<<"ah-"<<sliczba[j].substr(0,sliczba[j].length()-1)<<endl;
            liczba[0]=string_na_int(sliczba[j].substr(0,sliczba[j].length()-1));/// bierzemy cala liczbe oprocz minusa
            if(czy_wszystko_ok==false) return liczba[0];

            liczba[1]=string_na_int(sliczba[j==0 ? 1 : 0]); ///jesli j==0 to przypisze sliczba[1], a jesli j==1 to przypisze sliczba[0], po prostu na odwrot
            if(czy_wszystko_ok==false) return liczba[1];

            break;
        }
        else if(j==1){ ///jesli juz sprawdzilismy druga liczbe i tam tez nie ma '%' to:
            liczba[0]=string_na_int(sliczba[0]);
            if(czy_wszystko_ok==false) return liczba[0];
            liczba[1]=string_na_int(sliczba[1]); ///zakladamy ze pierwsza liczba jest t¹ z '%'
            if(czy_wszystko_ok==false) return liczba[1];
            break;
        }
        else{
            j++; ///w nastepnym obejsciu petli bedziemy sprawdzac druga liczbe
            continue;
        }
    }
    //cout<<"y "<<liczba[0]<<" "<<liczba[1]<<endl;

    if(liczba[0]==0 || liczba[1]==0){
        czy_wszystko_ok=false;
        return 111;
    }

    long double wynik=0;

    switch(tryb){
     case 1:
        wynik= 100/(liczba[0]/liczba[1]);
        break;
     case 2:
         wynik= liczba[1]/(100/liczba[0]);
        break;
     case 3:
         wynik= (100/liczba[0])*liczba[1];
        break;
    }

    return wynik;
}

int dopis(string napis,int kolor,int kolor2, string & czyszczenie){
fstream plik;

plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/zapis";

plik.open(lokacja.c_str(),ios::out|ios::app);
if(plik.good()==false){ saturnin_mowi(kolor); czyszczenie = "Mam problem z odczytem pliku!"; return 10;}
plik <<" "<< napis;
plik.close();
saturnin_mowi(kolor); czyszczenie = "Dopisanie zakonczone powodzeniem!";
}

int odczyt(int kolor,int kolor2){
string napis; fstream plik;

plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/zapis";

plik.open(lokacja.c_str(),ios::in);
if(plik.good()==false){ saturnin_mowi(kolor); cout <<"Mam problem z odczytem pliku!"<<endl; return 10;}
saturnin_mowi(kolor);
cout <<'"';
int x = 0;
while(getline(plik,napis))
{
    cout << (x==0 ? "" : "\n");
    cout << napis;
    x ++;
}
cout <<'"';
plik.close();
}

int wyczysc(int kolor, string & czyszczenie){
    fstream plik;

    plik.open("../Pliki/lokalizacja",ios::in);
        string lokacja;
        getline(plik,lokacja);
        plik.close();
        lokacja = lokacja + "Saturnin/zapis";

    plik.open(lokacja.c_str(),ios::out);
    if(plik.good()==false){ saturnin_mowi(kolor); czyszczenie = "Mam problem z odczytem pliku!"; return 10;}

    plik << "";
    plik.close();
    saturnin_mowi(kolor); czyszczenie = "Wyczyszczenie pliku zakonczone powodzeniem!";
}

string wybierz(string napis){
    //cout<< napis<<endl;
    napis.insert(napis.length(),"=");
    napis=usp(napis,0,1,1,1);
    napis.replace(napis.length()-1,1," "); ///Teraz po kazdym slowie bedzie spacja
    //cout<< napis<<endl;
    //cout<<napis<<endl;

    unsigned long long liczba_spacji=liczs(napis);
    string wybory[liczba_spacji]; ///Wzór na ilosc s³ów w zdaniu

    for(unsigned long long i=0;i<liczba_spacji;i++){
        for(unsigned long long j=0;;j++){
            //cout<<"MALA PETLA CALY NAPIS-"<< napis<< "   PATRZYMY-" <<napis.substr(j,1)<<endl;
            if(napis.substr(j,1)==" "){
                wybory[i]=napis.substr(0,j);
                napis.erase(0,j+1);
                break;
            }
        }
        //cout<<"DUZA PETLA-"<<wybory[i]<<endl;
    }
    unsigned long long swiety_wybor_saturnina=rand()%liczba_spacji;
   // cout<<swiety_wybor_saturnina<<endl;
    return wybory[swiety_wybor_saturnina];
}

int przestepny(int rok) {   ///Zwraca 1 jesli rok jest przestepny a 0 jesli nie jest
    return ((rok % 4 == 0  &&  rok % 100 != 0) || rok % 400 == 0);
}

string dzienTygodnia(int dzien, int miesiac, int rok) {
    //cout << "Funckja dzienTygodnia wita\n";
    string tydzien[] =
    {"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"};
    int liczbaDni[] =
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};   ///0 miejsce tablicy to 0 dni 1 to 31 2 to 59 bo styczen i luty razem maja 59 dni itd
    int dzienRoku;
    int yy, c, g;
    int wynik;
    dzienRoku = dzien + liczbaDni[miesiac-1];   ///Liczba dni to ilosc dni + liczba dni jaka wynika z miesiecy ktore byly wyzej
    if ((miesiac > 2) && (przestepny(rok) == 1))  ///Jesli rok jest przestepny i miesiac wiekszy od 2 musimy dodac do dni 1
        dzienRoku++;
    ///HMMMMM
    yy = (rok - 1) % 100;
    c = (rok - 1) - yy;
    g = yy + (yy / 4);
    wynik = (((((c / 100) % 4) * 5) + g) % 7);
    wynik += dzienRoku - 1;
    ///HMMMM
    //cout << "Jestem przed ifem\n";
    if(rok<1582||(rok == 1582 && miesiac < 10 )||( rok == 1582 && miesiac == 10 && dzien <= 4)) ///Gdyby ta data byla przed  Usunieciem dni z kalendarza przed Grzegorza
    {

        wynik -= 4; ///Usunal 10 dni wiec wydzedl taki wzor
        /*cout <<"Jestem w tym waznym ifie - ";
        cout<<"Rok - "<<rok<<
        "Miesiac- "<<miesiac<<
        "Dzien - "<<dzien<<endl<< tydzien[wynik%7] << endl;*/
    }
    //cout << "Jestem po ifie\n";
    wynik %= 7;
    switch(wynik)  ///Czasami dla mamlych dat wychodza liczby ujemne wiec musimy temu zapowbiec i zmienic je wedlug tego wzoru
    {
    case -1:
        wynik = 6;
        break;
    case -2:
        wynik = 5;
        break;
    case -3:
        wynik = 4;
        break;
    case -4:
        wynik = 3;
        break;
    case -5:
        wynik = 2;
        break;
    case -6:
        wynik = 1;
        break;

    }
    //wynik = abs(wynik);
    //cout << tydzien[wynik] << endl;
    //cout << "Czas na return, wynik = "<< wynik << endl;
    return tydzien[wynik]; /// 0 to pondz 1 to wtorek itd
}

string sprawdzanie_czasu(float strefa){
    float strefa_m = 0 ;
    string napis = "";
    fstream pomocny_plik;
fstream plik;
    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/czas";

    pomocny_plik.open(lokacja.c_str(),ios::out);
    if(strefa != round(strefa))
    {
        strefa_m = 60*fabs( strefa - round(strefa) ) ;
        strefa = trunc(strefa) ;
    }
    SYSTEMTIME st;
    GetLocalTime(&st);
    int godzina = st.wHour + strefa;  ///Sprawdzanie czasu w innym kraju domyslne srefa to 0
    int minuta  = st.wMinute + strefa_m;
    int sekunda = st.wSecond;
    if(minuta > 59) {minuta -= 60; godzina += 1;}
    else if (minuta < 0) {minuta +=60; godzina -= 1;}
    if(godzina >= 24) godzina -= 24;
    else if(godzina<0) godzina += 24;
    ///Te ify to wzgledy estetyczne bo jak jest godzina 7 lepiej zeby bylo 07
    if(godzina<10)  {   pomocny_plik<<"0"<<godzina<<":";}
    else            {   pomocny_plik<<godzina<<":";     }
    if(minuta<10)   {   pomocny_plik<<"0"<<minuta<<":"; }
    else            {   pomocny_plik<<minuta<<":";      }
    if(sekunda<10)  {   pomocny_plik<<"0"<<sekunda;     }
    else            {   pomocny_plik<<sekunda;          }
    pomocny_plik.close();


    pomocny_plik.open(lokacja.c_str(),ios::in);
    getline(pomocny_plik,napis);
    pomocny_plik.close();
    return napis;
}

string specjalne_daty(int rok, int miesiac, int dzien, bool &specjalna_data){ ///Wszystkie specjalne daty dopiszemy tutaj
    //cout << "czy wszystko ok: "<< czy_wszystko_ok << endl ;
    fstream plik; string linia; int licznik = 0;
    plik.close();
    plik.open("../Pliki/specjalne_daty",ios::in);
    if(plik.good() == false)  ///Jakby plik sie nie otworzyl
    {
        czy_wszystko_ok = false;
        return "10";
    }
    bool czy_zmienny_rok;
    while(getline(plik,linia)) ///Wczytujemy z pliku
    {
        if(licznik % 4 == 0 && linia == "X")
        {
            czy_zmienny_rok = true;
            goto hop;
        }
        else if(licznik % 4 == 0 && rok == string_na_int(linia) )  ///Co 4 jest podany rok jesli rok sie zgadza idziemy dalej
        {
            hop:
            licznik ++;
            getline(plik,linia);
            if(string_na_int(linia) == miesiac)  ///Potem jest miesiac jesli on tez sie zgadza
            {
                licznik ++;
                getline(plik,linia);
                if(string_na_int(linia) == dzien)  ///Musi zgadzac sie tez dzien przeciez
                {
                    getline(plik,linia);
                    specjalna_data = true ;
                    plik.close();
                    string dzien = dzienTygodnia(31,10,rok);
                    return czy_zmienny_rok == true ? linia+dzien : linia;
                }
            }
        }
        licznik ++;
    }
    plik.close();
    //cout << "Czy wszytko ok: " << czy_wszystko_ok << Endl;
    return "112";
}

string sprawdzanie_daty(){
   SYSTEMTIME st;
   fstream plik;   string linia;
   GetLocalTime(&st);
   //cout << "Tym razem to ja sprawdzanie daty - ";
   //cout << dzien<< " "<<miesiac << " "<<rok<<endl;
   //dzienTygodnia(dzien, miesiac, rok); KIEDYS TU BYLO W SUMIE NIE WIEM PO CO WYWALILEM TO, JAKBY BYLY PROBLEMY Z CZYMS TO PEWNIE TEGO WINA
   plik.open("../Pliki/napis",ios::out);
   if(st.wMonth<10&&st.wDay<10){plik<<st.wYear<<".0"<<st.wMonth<<".0"<<st.wDay<<"\t"<<dzienTygodnia(st.wDay, st.wMonth, st.wYear)<<endl;}
   else if(st.wMonth < 10){plik<<st.wYear<<".0"<<st.wMonth<<"."<<st.wDay<<"\t"<<dzienTygodnia(st.wDay, st.wMonth, st.wYear)<<endl;}
   else if(st.wDay<10){plik<<st.wYear<<"."<<st.wMonth<<".0"<<st.wDay<<"\t"<<dzienTygodnia(st.wDay, st.wMonth, st.wYear)<<endl; }
   else plik<<st.wYear<<"."<<st.wMonth<<"."<<st.wDay<<"\t"<<dzienTygodnia(st.wDay, st.wMonth, st.wYear)<<endl;
    plik.close();
    plik.open("../Pliki/napis",ios::in);
    getline(plik,linia);
    plik.close();
    return linia;
}

string poprawne_daty(int rok, int miesiac, int dzien){  ///Sprawdz czy data istnieje
    if(miesiac>12||miesiac<1)
    {
        czy_wszystko_ok = false;
        return "70";
    }
    else if(dzien < 1)
    {
        czy_wszystko_ok = false;
        return "71";
    }
    else if(rok == 1582 && miesiac == 10 && dzien > 4 && dzien < 15) ///Dni usuniete przez naszego ukochanego Grzegorza
    {
        czy_wszystko_ok = false;
        return "72";
    }
    else if(rok < 1582 && rok%4 == 0 && miesiac == 2 && dzien > 29) ///Rok przestepny przed grzegorzem
    {
        czy_wszystko_ok = false;
        return "73";
    }
    else if(rok<1582 && rok%4 != 0 && miesiac == 2 && dzien > 28)  ///Rok nie przestepny przed grzogorzem
    {
        czy_wszystko_ok = false;
        return "74";
    }
    else if(rok > 1582 && miesiac==2 &&rok%4==0 && rok%100!=0 && dzien>29|| rok >1582 &&miesiac==2 &&rok%400==0 && dzien>29) ///Rok przestepny po grzegorzu
    {
        czy_wszystko_ok = false;
        return "73";
        cout <<"Przypominam, ze Luty ma w tym roku 29 dni\n";
    }
    else if(rok > 1582 &&rok%4!=0 && dzien>28&&miesiac==2||rok >1582 &&dzien>28&&miesiac == 2 && rok%100 == 0&&rok%400!=0) ///Rok nie przestepny po grzegorzu
    {
        czy_wszystko_ok = false;
        return "74";
    }
    else if(dzien>30&&miesiac==4)   ///Kwiecien ma 30 dni
    {
        czy_wszystko_ok = false;
        return "75";
    }
    else if(dzien>30&&miesiac==6) ///czerwiec ma 30 dni
    {
        czy_wszystko_ok = false;
        return "76";
    }
      else if(dzien>30&&miesiac==9) ///wrzesien ma 30 dni
    {
        czy_wszystko_ok = false;
        return "77";
    }
      else if(dzien>30&&miesiac==11) ///listopad ma 30 dni
    {
        czy_wszystko_ok = false;
        return "78";
    }
    else if(dzien>31&&miesiac==1)   ///Styczen ma 31
    {
        czy_wszystko_ok = false;
        return "79";
    }
      else if(dzien>31&&miesiac==3) ///marzec ma 31 dni
    {
        czy_wszystko_ok = false;
        return "80";
    }
      else if(dzien>31&&miesiac==5) ///maj ma 31 dni
    {
        czy_wszystko_ok = false;
        return "81";
    }
      else if(dzien>31&&miesiac==7) ///lipiec ma 31 dni
    {
        czy_wszystko_ok = false;
        return "82";
    }
      else if(dzien>31&&miesiac==8) ///sierpien ma 31 dni
    {
        czy_wszystko_ok = false;
        return "83";
    }
      else if(dzien>31&&miesiac==10) ///pazdziernik ma 31 dni
    {
        czy_wszystko_ok = false;
        return "84";
    }
      else if(dzien>31&&miesiac==12) ///grudzien ma 31 dni
    {
        czy_wszystko_ok = false;
        return "85";
    }
    else return "";
}

string data_przeszla(string odp){
    string help = modp(usp(odp));
    odp = usp(odp,0,0,1);
    string lata[] = {"pne.","p.n.e.","p.ne.","p.ne","p.n.e","pn.e.","pn.e","pne"};
    for(unsigned long long k = 0;k < 8;k++)
    {
    int y = help.find(lata[k]);
    int rok_miejsce = 0;
    if(y != FindNieZnalazl) ///Jesli nic nie znajdzie find zwraca to I know dziwne
    {
        for(unsigned long long i = 0;i < odp.length();i++) /// Skomplikowana sprawa i tak nie zrozumiesz ale nie ruszaj
        {
            if(czy_to_liczba(odp.substr(i,1)) == false) ///No dobra bo to zmienia pierwsdza napotkana nazwe miesiaca na numer ale jak podam 1 1 styczen to styczen bedzie 1 czyli dzien 1
            {
                rok_miejsce = i;  ///No wiec jesli miejcsce tego miesiaca to zero to nie bo to rok no ale dzien jest po roku wiec chce znac dlugosc roku
                //cout <<"Rok miesjce - "<< rok_miejsce << endl;
                break;
            }
        }
        if(y != rok_miejsce)
        {
            //cout << odp << endl;
            return odp;
        }

        string ja = lata[k];

        for(unsigned long long i = 0;i < ja.length();i++)
        {
            //cout << "Sprawdzam " << ja.substr(i,1) << " :\n";
            for(unsigned long long j = 0;j < odp.length();j++)
            {
                //cout <<"\t"<< odp.substr(j,1) << endl;
                if(odp.substr(j,1) == ja.substr(i,1))
                {
                    string tactic = odp.substr(j+1,odp.length() - (j+1));
                    //cout << "Tactic - " << tactic << endl;
                    tactic = usp(tactic,0,0,1);
                    //cout << "Tactic po usunieciu spacjiz przodu - " << tactic << endl;
                    odp.replace(j,odp.length()-j,tactic);
                    //cout << "Poprawiona odp - "<<odp << endl ;
                    break;
                }
            }
        }
        odp.insert(rok_miejsce," ");
        odp.insert(0,"-");

    }
    }
    //cout <<"Data przeszla ="<< odp << endl;
    return odp;
}

string miesiac_napisany(string odp){
    //cout << "Wszedlem do tego\n";
    string miesiace[] = {"styczen","luty","marzec","kwiecien","maj","czerwiec","lipiec","sierpien","wrzesien","pazdziernik","listopad","grudzien"  };
    string miesiace1[] = {"stycznia","lutego","marca","kwietnia","maja","czerwca","lipca","sierpnia","wrzesnia","pazdziernika","listopada","grudnia"};
    int miesiac = 13;
    string pomoc = modp(usp(odp));
    string co_sprawdzac = "";
    //cout << "Czas na pierwsza petle:\n";
    int rok_miejsce = 0;
    for(unsigned long long i = 0;i < odp.length();i++) /// Skomplikowana sprawa i tak nie zrozumiesz ale nie ruszaj
    {
        if(czy_to_liczba(odp.substr(i,1)) == false && odp.substr(i,1) != "-") ///No dobra bo to zmienia pierwsdza napotkana nazwe miesiaca na numer ale jak podam 1 1 styczen to styczen bedzie 1 czyli dzien 1
        {
            rok_miejsce = i;  ///No wiec jesli miejcsce tego miesiaca to zero to nie bo to rok no ale dzien jest po roku wiec chce znac dlugosc roku
            //cout <<"Rok miesjce - "<< rok_miejsce << endl;
            break;
        }
    }

    for(int i = 1;i<13;i++)
    {
        int y = pomoc.find(miesiace1[i-1]);
        if(y != FindNieZnalazl) ///Jesli nic nie znajdzie find zwraca to I know dziwne
        {
            if(y == 0)
            {
                return odp;
            }
            else if(y > rok_miejsce)
            {
                //cout << y  << "\n";
                return odp;
            }
            //cout << "Znalazlem ten miesiac ";
            co_sprawdzac = miesiace1[i-1];
            //cout << co_sprawdzac <<" ";
            miesiac = i;
            //cout << miesiac <<endl;
            break;
        }
        int x = pomoc.find(miesiace[i-1]);
        if(x != FindNieZnalazl) ///Jesli nic nie znajdzie find zwraca to I know dziwne
        {
            if(x == 0)
            {
                return odp;
            }
            else if(x > rok_miejsce)
            {
                //cout << x  << "\n";
                return odp;
            }
            //cout << "Znalazlem ten miesiac ";
            co_sprawdzac = miesiace[i-1];
            //cout << co_sprawdzac <<" ";
            miesiac = i;
            //cout << miesiac <<endl;
            break;
        }
    }
    if(miesiac == 13) ///Domyslne
    {
        //cout << "Nic nie znalazlem\n";
        return odp;
    }
    else
    {
        //cout << "Dobra ide dalej\n";
        for(int i = 0;i<co_sprawdzac.length();i++)  ///Powtarza sie tyle razy ile ma liter szukany miesiac
        {
            for(int j = 0 ;j < odp.length();j++)  ///Przelatuje caly napis
            {
                if(co_sprawdzac.substr(i,1) == odp.substr(j,1))  ///Sprawdzamy czy moze litera tego co sprawdzamy jest taka jak po kolei litera odp
                {
                    if(i == 0)
                    {
                        odp.insert(j,int_na_string(miesiac));
                        odp.insert(j," ");
                        if(miesiac < 9)
                        j += 2;
                        else j+=3;
                    }
                    odp.erase(j,1); ///Usuwamy te litere
                    if(i != co_sprawdzac.length() - 1)
                    {
                    string tactic = odp.substr(j,odp.length()); ///Bierzemy od tej litery do konca
                    tactic = usp(tactic,0,0,1); ///Usuwamy wszystkie spacje jakie nastapily po tej literze z "m  arzec" zrobi "arzec"
                    odp.replace(j,odp.length(),tactic); ///Zastepujemy
                    }
                    break; ///idziemy sprawdzic nastepna litera tego miesiaca
                }
            }
        }
        //cout << "Oto ostateczna odpowiedz: "<<odp<<endl;
        return odp;
    }
}

void zmiana_systemu(int ktory, int &zamiana, string odp,int nasz_kolor, int kolor_saturnina,string &dwojkowy){
    string jaki_system = ""; dwojkowy = "";
    saturnin_mowi(kolor_saturnina);
    int cos = 0;
    if(usp(odp) != "") ///Jesli ktos wpisal od razu jaki ma byc system
    {
        jaki_system = odp;
    }
    else if(ktory == 0) ///Jesli nikt nie podal to sie pytamy
    {
        cout << "Podaj nowy system zrodlowy: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,jaki_system);
        saturnin_mowi(kolor_saturnina);
    }
    else if(ktory == 1) ///Pytamy sie
    {
        cout << "Podaj nowy system docelowy: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,jaki_system);
        saturnin_mowi(kolor_saturnina);
    }
    jaki_system = usp(modp(jaki_system));
    ///TU NASTEPUJE ZMIENIENIE DWOJKOWY NA 2
    fstream plik;   string linia;
    plik.open("../Pliki/systemy",ios::in);  ///Wszystkie te odpowiedzi specjalne mamy w pliku
    while(getline(plik,linia))
    {
        long long x = jaki_system.find(linia);
        if(x != FindNieZnalazl)  ///Jesli cos znalazl to jest rozny bo jak nie znalazl o to zwraca
        {
            string tak;
            getline(plik,tak); ///Wczytujemy z drugiej linii system
            jaki_system.replace(x,linia.length(),tak); ///Podmieniamy swoja droga genialny pomysl mialem
            break;
        }
        getline(plik,linia); /// Co dwie linie
    }
    plik.close();

    //int y = jaki_system.find();
    //if(y != 4294967295)
    string dwojkowy_shit[] = {"nkb", "zm","u1","u2"}; string binarny_zap = "";
    for(unsigned long long i = 0;i < 4;i++)  ///Szukamy NKB, ZM, U1, U2...
    {
        int y = jaki_system.find(dwojkowy_shit[i]);
        if(y != FindNieZnalazl)
        {
            binarny_zap = dwojkowy_shit[i];
            jaki_system.erase(y,binarny_zap.length());
        }
    }

    for(unsigned long long i = 0;i < jaki_system.length();i++)  ///Nie ma takiego systemu
    {
        if(czy_to_liczba(jaki_system.substr(i,1)) == false)
        {
            czy_wszystko_ok = false;
            zamiana = 92;
            return;
            //goto koniec;
        }
    }
    cos = string_na_int(jaki_system);
    if(cos > 16 || cos < 2)  ///Jakby znowu nie bylo
    {
        czy_wszystko_ok = false;
        zamiana = 92;
        return;
        //goto koniec;
    }
    if(cos == 2 && binarny_zap != "")
    {
        dwojkowy = binarny_zap;
    }
    else if(cos == 2 && binarny_zap == "")
    {
        dwojkowy = "nkb";
    }
    zamiana = cos; ///Pracujemy na oryginale i mamy wskaznik wiec tyle starczy
    koniec: ;
}

void jaki_czas(int r, int m, int d, int & kiedy){
    string pomoc = sprawdzanie_daty();
    int teraz_r = string_na_int(pomoc.substr(0,4));
    int teraz_m = string_na_int(pomoc.substr(5,2));
    int teraz_d = string_na_int(pomoc.substr(8,2));
    //cout << teraz_r << endl << teraz_m << endl << teraz_d << endl;
    if((teraz_r < r)||(teraz_r == r && teraz_m < m)||(teraz_r == r && teraz_m == m && teraz_d < d)) ///Przyszlosc
    {
        //cout << "Przyszlosc\n";
        kiedy = 10;
    }
    else if(teraz_r == r && teraz_m == m && teraz_d == d) ///Teraz
    {
       //cout << "Terazniejszosc\n";
        kiedy = -1;
    }
    else ///Przeszlosc
    {
        //cout << "Przeszlosc\n";
        kiedy = 1;
    }
}

string Na_u1_u2(long double wynik, string bin_sd){
    wynik = fabs(wynik);
    int ilosc = 0;
    for(int i = 0;;i++) ///Ustalenie maksymalnej potegi przez ktora mozna podzilic na rzecz przyszlej petli
    {
        if(wynik - pow(2,i) < 0)
        {
            //cout << "wynik - " << wynik << " przez - " << pow(na_co,i) << endl;

            ilosc = i;
            break;
        }
        else if(wynik - pow(2,i) == 0 && bin_sd == "u2")
        {
            ilosc = i;
            break;
        }
    }
    long double potega = pow(2,ilosc);
    if(bin_sd == "u1")
    {
        potega --;   potega -= wynik;
        //cout << "liczba wysylana do system liczeniowy = "<<potega<<endl;
        string tuptaj = system_liczeniowy(int_na_string(potega),10,2,"nkb","");
        //cout <<  tuptaj << endl;
        string pomoc;
        for(unsigned int long long i = 0;i < ilosc;i++)
        {
            pomoc.insert(0,"0");
        }
        pomoc.insert(0,"1");
        for(unsigned int long long i = 0; i < pomoc.length()  - tuptaj.length()+2;i++)
        {
            tuptaj.insert(0,"0");
        }
        //cout << "Pomoc  " << pomoc << endl;
        //cout << "tuptaj " << tuptaj << endl;
        for(unsigned int long long i = 0;i < ilosc+1;i++)
        {
            if(tuptaj.substr(i,1) == "1")
            {
                pomoc.replace(i,1,"1");
            }
        }
        //cout << "po symbiozie " << pomoc << endl;
        return pomoc;
    }
    else
    {
        potega -= wynik;
        //cout << "liczba wysylana do system liczeniowy = "<<potega<<endl;
        string tuptaj = system_liczeniowy(int_na_string(potega),10,2,"nkb","");
        //cout <<  tuptaj << endl;
        string pomoc;
        for(unsigned int long long i = 0;i < ilosc;i++)
        {
            pomoc.insert(0,"0");
        }
        pomoc.insert(0,"1");
        for(unsigned int long long i = 0; i < pomoc.length()  - tuptaj.length()+2;i++)
        {
            tuptaj.insert(0,"0");
        }
        //cout << "Pomoc  " << pomoc << endl;
        //cout << "tuptaj " << tuptaj << endl;
        for(unsigned int long long i = 0;i < ilosc+1;i++)
        {
            if(tuptaj.substr(i,1) == "1")
            {
                pomoc.replace(i,1,"1");
            }
        }
        //cout << "po symbiozie " << pomoc << endl;
        return pomoc;
    }

}

string system_liczeniowy(string odp, int z_czego, int na_co, string bin_sd, string bin_sz){
    /*
        ARGUMENTY DOMNIEMANE
        string bin_sd=""
        string bin_sz=""
    */

    //z_czego = 8;
    int ile_spacji = 0, z_czego_na_chwile = 0;
    bool ujemna = false;
    string system[] = {"a","b","c","d","e","f"};
    if(z_czego > 10)
    {
        z_czego_na_chwile = z_czego - 10;
    }
    odp = usp(odp,0,0,1,1); ///I usuwamy spacje z poczatku i konca
    odp = modp(odp,1,1,0); ///No bo w 16 15 to f i F
    //cout << odp << endl;
    if(odp.substr(0,1) == "-")  ///Sprawdzamy czy liczba jest ujemna
    {
        if(z_czego == 2 ||  bin_sd == "nkb") ///Jesli jest z 2 lub na podstawowy 2 a wtedy sie nie da ujemnych to blad
        {
            czy_wszystko_ok = false;
            return "-69";
        }
        ujemna = true; ///Inaczej tak zeby uznac liczbe za ujemna pozniej
        odp.erase(0,1);
    }
    for(unsigned long long i = 0;i<odp.length();i++) ///Spacje i bledny znak
    {
        if(odp.substr(i,1) == " ")
        {
            ile_spacji ++; ///Liczymy ilosc spacji
        }

        else if(czy_to_liczba(odp.substr(i,1)) == false) /// Jesli jest cos innego od liczby i spacji bo wyzszy if
        {
            //cout << z_czego_na_chwile << endl;
            for(int j = 0; j < z_czego_na_chwile; j++) /// Powtarza sie tyle razy o ile system z ktorego liczymy jest wiekszy od 10
            {
               // cout << "co jest - " << odp.substr(i,1) << " ,a z czym porownuje - " << system[j] << endl;
                if(odp.substr(i,1) == system[j])  ///jesli jest rowne a, b, c to nie ma bledu a dla 11 b dla 12 itp
                {
                    //cout << "taaak\n";
                    goto koniec; ///Nie mozna continue bo to petla w petli
                }
            }
            if(odp.substr(i,1) == "," || odp.substr(i,1) == ".")  ///Jesli jest przecinek lub kropka to blad ze liczba musi byc calkowita
            {
                czy_wszystko_ok = false;
                return "69";
            }
            czy_wszystko_ok = false;
            return "112";
        }
        else if(string_na_int(odp.substr(i,1)) >= z_czego) ///No bo w systemie dwojkowym np nie mozna wprowadzic 2,3,4 tylko zera i jedynki
        {
            czy_wszystko_ok = false;
            return "112";
        }
        koniec: ;
    }
    ///Za duzo danych
    if(ile_spacji > 0) ///Za duzo danych
    {
        czy_wszystko_ok = false;
        return "113";
    }

    int tablica[odp.length()];
    long double wynik = 0;

    {   ///Systemy dwojkowe -> roznorakie operacje
         if(bin_sz == "zm")
        {
            if(odp.substr(0,1) == "1")
            {
                if(bin_sd == "nkb")
                {
                    czy_wszystko_ok = false;
                    return "-69";
                }
                ujemna = true;
            }
            odp.erase(0,1);
        }

        else if(bin_sz == "u1")
        {
            if(odp.substr(0,1) == "0") odp.erase(0,1);
            else
            {
                wynik = pow(2,odp.length() - 1) * -1 * string_na_int(odp.substr(0,1)) + 1;
                odp.erase(0,1);
                //cout << wynik << endl;
            }
        }
        else if(bin_sz == "u2")
        {
            wynik = pow(2,odp.length() - 1)* -1 *string_na_int(odp.substr(0,1));
            odp.erase(0,1);
        }
    }
    odp = modp(odp,0,0,0,1); ///Leci pod tablice od tylu bo jest wygodniej

    for(unsigned long long i = 0;i < odp.length();i++) ///Wszystko leci pod tablice, bo mamy juz czysta liczbe w stringu
    {
        if(odp.substr(i,1) == "a")  tablica[i] = 10;
        else if(odp.substr(i,1) == "b")  tablica[i] = 11;
        else if(odp.substr(i,1) == "c")  tablica[i] = 12;
        else if(odp.substr(i,1) == "d")  tablica[i] = 13;
        else if(odp.substr(i,1) == "e")  tablica[i] = 14;
        else if(odp.substr(i,1) == "f")  tablica[i] = 15;
        else tablica[i] = string_na_int(odp.substr(i,1));
        //cout << tablica[i] << " ";
    }
    //cout << endl;

    for(long long i = 0; i < odp.length();i++)   ///BARDZO WAZNA PETLA ZMIENIAMY OTRZYMANA LICZBE NA SYSTEM 10 ZAWSZE
    {
        //cout <<"Liczba w tablicy to - "<< tablica[i] << " ";
        //cout << "z_czego - " << z_czego << " ";
        //cout <<"To jest i czyli do ktorej potegi - "<< i << " ";
        //cout <<"Po przeliczeniu wag - "<< pow(z_czego,i) << " ";
        wynik += pow(z_czego,i) * tablica[i];  ///WYNIK ZWIEKSZA SIE O KOLEJNE CYFRY POMNOZONE PRZEZ JEJ WAGE CZYLI SYSTEM DO POTEGI, ZA KAZDA LICZBA O JEDEN WIEKSZEJ CZYLI "i"
        // cout << endl;
        //cout <<"teraz wynik to - "<< wynik << endl;
    }
    //cout <<"System dziesietny: "<< wynik << endl;
    wynik = round(wynik);

    if(na_co == 10)  ///Jesli robimy na 10 to od razu return bo po co z 10 na 10 zmieniac
    {
        if(odp == "") odp = "0";
        else if(ujemna == true)
        {
            wynik = -wynik;
        }
        return int_na_string(wynik);
    }
    if((bin_sd == "u1" || bin_sd == "u2")&&na_co == 2&&(ujemna == true||wynik <0))
    {
        //cout << "kupa\n";
        return Na_u1_u2(wynik, bin_sd);
    }
    int ilosc = 0;
    if(wynik < 0)
    {
        ujemna = true;
        wynik = -wynik;
    }
    for(int i = 0;;i++) ///Ustalenie maksymalnej potegi przez ktora mozna podzilic na rzecz przyszlej petli
    {
        if(wynik / pow(na_co,i) < 1)
        {
            //cout << "wynik - " << wynik << " przez - " << pow(na_co,i) << endl;
            ilosc = i - 1;
            break;
        }
    }
    //cout << ilosc << endl;
    int x = ilosc;
    int liczby[x+1], l = 0; ///Rezerwujemy tyle ile potrzeba czyli wyzsza petla
    long  double help = 0;
    do
    {
        ///
        if(x == 0) help = round(wynik / pow(na_co,x)); ///Rozwiazanie na Daniela bo bledy sa tylko  przy ostatniej liczbie  edit: ono ma sens bo przy ostatniej liczbie nie moze ucinac dlatego jest round
        else  help = trunc(wynik / pow(na_co,x));      ///dzielimy wynik przez najwieksza mozliwa teraz potege i ucinamy bo chcemy tylko wynik dzielenia a reszta z dzielenia ma zostacw tej liczbie
        //cout << "Wynik = " << wynik << " , podzielony przesz " << pow(na_co,x)<< endl;
        //cout << "Wynik tego to - " << help << endl;
        liczby[l] = help;
        wynik -= help * pow(na_co,x); ///Odejmujemy od glownego wyniku to co wlasnie policzylismy
        x--; ///Zmniejszamy o jeden zeby petla sie kiedys skonczyla
        //cout << "Wynik tego to - " << liczby[l] << endl;
        l ++ ; ///W koncu do dalszych czesci tablicy trzeba
    }while(x >= 0);
    odp.erase(0,odp.length());
    for(long long i = 0;i < ilosc+1 ;i++) ///Uzupelniamy stringa i przy okazji zmieniamy 10 na a itp
    {
        if(liczby[i] == 10)
        {
            odp.insert(i,"a");
        }
        else if(liczby[i] == 11)
        {
            odp.insert(i,"b");
        }
        else if(liczby[i] == 12)
        {
            odp.insert(i,"c");
        }
        else if(liczby[i] == 13)
        {
            odp.insert(i,"d");
        }
        else if(liczby[i] == 14)
        {
            odp.insert(i,"e");
        }
        else if(liczby[i] == 15)
        {
            odp.insert(i,"f");
        }
        else
        {
            odp.insert(i,int_na_string(liczby[i]));
        }

    }
    if(odp == "") odp = "0"; ///Jesli nic nie wpisal to zwrocmy zero
    if(ujemna == true && na_co != 2)
    {
            odp.insert(0,"-");
    }
    if(bin_sd == "zm")
    {
        if(ujemna == true) odp.insert(0,"1");
        else odp.insert(0,"0");
    }
    else if((bin_sd == "u1" || bin_sd == "u2") && ujemna == false )
    {
        odp.insert(0,"0");
    }


    return odp;
}

string sprawdzanie_dnia_tygodnia(string odp, bool &specjalna_data, int &kiedy_czas){ ///Zwraca sam dzien tygodnia w string albo nazwe bledu i czy_wszystko_ok false
    int miesiac=0, rok=0, dzien=0, ilosc_spacji = 0;
    string wynik = "";

    odp = data_przeszla(odp);

    odp = miesiac_napisany(odp);

    odp = usp(odp,0,1,1,1);
    odp.insert(odp.length(),"="); ///Dodajemy rowna sie zeby dzialal usuwacz podwojnych spacji
    odp.erase(odp.length()-1,1); ///Usuwamy rowna sie
    for(unsigned int i=0;i < odp.length();i++) ///
    {
       // cout << odp.substr(i,1) <<endl;
        if(odp.substr(i,1) == "-")
        {
            string help = odp.substr(i+1,odp.length());
            help = usp(help,0,0,1);
            odp.replace(i+1,odp.length(),help);
        }
        if(odp.substr(i,1) == " ") ilosc_spacji ++; ///Zwiekszamy ilosc spacji po petli sprawdzimy ile jest spacji
        if(ilosc_spacji != 1 && czy_to_liczba(odp.substr(i,1)) == false&&odp.substr(i,1)!=" " &&odp.substr(i,1)!="-") ///Jesli jest napis czy cokolwiek innego a nie jest to miesiac
        {
            //cout << ilosc_spacji << " " <<odp.substr(i,1)<<endl;
            czy_wszystko_ok = false ;
            return "112";
        }
       // cout << "Ilosc spacji to: " << ilosc_spacji << endl;
    }
    ///Za duzo danych
    if(ilosc_spacji > 2)
    {
        czy_wszystko_ok = false;
        wynik = int_na_string(113);
        return wynik;
    }
    ///Za malo danych
    else if(ilosc_spacji < 2)
    {
        czy_wszystko_ok =false;
        return "1";
    }
    odp.insert(odp.length()," ");
    ilosc_spacji = 0;
    ///Wpisujemy pod inty rok miesiac dzien
    for(int i = 0, j= odp.length(); i<j ; i++)
    {
        if(odp.substr(i,1) == " "&&ilosc_spacji == 0)  ///ROK
        {
            ilosc_spacji ++;
            string hej = odp.substr(0,i);
            if(hej.length() > 8)
            {
                //cout << "tak to ja\n";
                czy_wszystko_ok = false;
                return "86";
            }
            rok = string_na_int(odp.substr(0,i)); ///No i mamy rok
            odp.erase(0,i+1); ///Bo spacje usuwamy
            i = 0; j =odp.length();
        }
        if(odp.substr(i,1) == " "&&ilosc_spacji == 1) ///MIESIAC TU MUSZE WPROWADZIC MARZEC -> 3 edit: DZIALA
        {
            ilosc_spacji ++;
            miesiac = string_na_int(odp.substr(0,i)); ///No i mamy miesiac
            odp.erase(0,i+1); ///Bo spacje usuwamy
            i = 0;  j =odp.length();
        }
        if(odp.substr(i,1) == " "&&ilosc_spacji == 2) ///DZIEN
        {
            ilosc_spacji ++;
            dzien = string_na_int(odp.substr(0,i)); ///No i mamy dzien
            odp.erase(0,i+1); ///Bo spacje usuwamy
            i = 0;  j = odp.length();
        }
        if(ilosc_spacji > 3)    break; ///Zeby wiecej nie sprawdzal
    }

    wynik = poprawne_daty(rok,miesiac,dzien);  ///Sprawdzamy czy data istnieje np 43 lipca 2017 lub 29 lutego 2003
    if(czy_wszystko_ok == false)  return wynik;

    wynik = specjalne_daty(rok,miesiac,dzien,specjalna_data);
    if(czy_wszystko_ok == false)    return wynik;
    if(specjalna_data == true)      return wynik; ///Zwracamy specjalna date
   //cout << "Teraz to najwazniejsza funkcja - ";
   //cout << "Teraz uzyje dzienTygodnia\n";
    wynik = dzienTygodnia(dzien, miesiac, rok); ///Mamy dzien tygodnia w stringu z tej funkcji
    //cout << wynik << endl;
    //cout << "Teraz uzyje jaki_czas\n";
    jaki_czas(rok,miesiac,dzien,kiedy_czas);
    //cout << "Wracam do glownego programu wynik = " << wynik<<ENDL;
    return wynik;
}


