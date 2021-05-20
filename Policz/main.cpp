#include "../_Headers/funkcje.h"

int main(int argc, char*argv[])
{
    //cout << GetActiveWindowTitle()<<endl;
    srand(time(NULL));
    string ol[] = ///odpowiedz losowa
    {
        "Otoz wynik brzmi ","Udalo mi sie, odpowiedz brzmi ","Bez problemu doszedlem ze wynik rowna sie ",
        "Odpowiedz ktorej oczekujesz jest nastepujaca ","Wynikiem jest ","Zakladam ze wynik to ","To bylo proste odpowiedz wynosi ",
        "Wynik to ", "Serio nie wiedziales? to oczywiste ze odpowiedz to ","Policzenie tego nie zajelo mi nawet milionowej sekundy: ",
        "Dluzej wymyslales to dzialanie niz ja je policzylem: "
    } ;

    int licznik_pomocy=0;
    string ol_pomocniczy[] =
    {
        "Widze ze masz pewne problemy z uzywaniem funkcji policz,\n zawsze mozesz uzyc /pomoc "

    };
    string odp = "";
    fstream plik;
    long double wynik; long double poprzedni_wynik=0;

    plik.open("../Pliki/lokalizacja",ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    int nasz_kolor, kolor_saturnina,losowanko;
    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik>> kolor_saturnina >> nasz_kolor;
    plik.close();


    string linia = "";
    argv++;
	for(int i = 1; i<argc; i++)
	{
		linia += *argv;
		argv++;
		if(i!=argc-1)linia+= " ";
	}
    if(linia!=""){
        odp = linia;
        goto dalej;

    }
    for(;;){
    czy_wszystko_ok=true;


    //plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    //plik.close();
    nazwa = lokacja + "kolory";
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){ czy_wszystko_ok= false; sprawdzacz_bledow(10);}
    plik>> kolor_saturnina >> nasz_kolor;
    plik.close();

    ///Policz
    odp="";
    while(usp(odp) == "")
    {
        saturnin_mowi(kolor_saturnina);
        cout << "Podaj dzialanie jakie chcialbys obliczyc: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        saturnin_mowi(kolor_saturnina);
    }
    if(modp(odp) == "/wyjdz"){
        zegnaj(kolor_saturnina,odp);
        getch();
        return EXIT_SUCCESS;
    }
    if(modp(odp) == "/pomoc" || modp(odp) == "/help"){
        system("start ../policz_help/policz_help.exe");
        continue;
    }
    if(modp(odp) == "/czysc" || modp(odp) == "/wyczysc"|| modp(odp) == "/cls"){
        system("cls");
        continue;
    }
    if(modp(odp.substr(0,11)) == "/zaokraglij"){
        //cout<<zaokraglij(poprzedni_wynik,1)<<endl;
        continue;
    }
    dalej:
    saturnin_mowi(kolor_saturnina);
    losowanko = rand()%11;
    int pomoc = policz (odp,wynik,poprzedni_wynik);
    poprzedni_wynik=wynik;

    if(czy_wszystko_ok==false)
    {
        sprawdzacz_bledow(pomoc);

        losowanko = rand()%100;
        if(losowanko < 30*licznik_pomocy){
            cout<< ol_pomocniczy[0]<<endl;
        }
        if(pomoc==12 || pomoc== 112) licznik_pomocy++;
        continue;
    }
    licznik_pomocy=0;
    cout <<ol[losowanko]<<wynik<<endl;


    }

}

