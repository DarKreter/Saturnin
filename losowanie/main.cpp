<?xml version="1.0" encoding="utf-8"?>
<d:error xmlns:d="DAV:" xmlns:s="http://sabredav.org/ns">
  <s:exception>Doctrine\DBAL\Exception\DeadlockException</s:exception>
  <s:message>An exception occurred while executing 'UPDATE `oc_file_locks` SET `lock` = `lock` + 1, `ttl` = ? WHERE `key` = ? AND `lock` &gt;= 0' with params [1588213443, "files\/d52d63d07ff20dd78b33af28d841e04c"]:

SQLSTATE[40001]: Serialization failure: 1213 Deadlock found when trying to get lock; try restarting transaction</s:message>
</d:error>
ios::in);
    string lokacja;
    getline(plik,lokacja);
    plik.close();
    lokacja = lokacja + "Saturnin/";
    string nazwa = lokacja + "kolory";

    plik.open(nazwa.c_str(),ios::out|ios::app); ///TU
    plik.close();
    plik.open(nazwa.c_str(),ios::in); ///TU
    if(plik.good()==false){czy_wszystko_ok= false; sprawdzacz_bledow(0);}
    plik >> kolor_saturnina >> nasz_kolor;
    plik.close();

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

    for(;;)
    {
        czy_wszystko_ok = true;
        saturnin_mowi(kolor_saturnina);
        cout << "Podaj minimum i maximum przedzialu z ktorej mam wylosowac liczbe: ";
        saturnin_mowi(nasz_kolor);
        getline(cin,odp);
        saturnin_mowi(kolor_saturnina);
        if(usp(modp(odp)) == "/wyjdz")
        {
            zegnaj(kolor_saturnina,odp);
            getch();
            return EXIT_SUCCESS;
        }
    dalej:
    saturnin_mowi(kolor_saturnina);
    wynik = losowanie(odp);
    int los = rand() % 5 ;
    if(czy_wszystko_ok==false)
    {
        sprawdzacz_bledow(wynik);
        continue;
    }
    if(rand() % 20 == 0)    cout << odpowiedz_losowa[5]   << wynik << endl;
    else                    cout << odpowiedz_losowa[los] << wynik << endl;
    }
}
