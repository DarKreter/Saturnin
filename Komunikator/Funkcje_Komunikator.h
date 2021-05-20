#ifndef Funkcje_Komunikator.h

#define Funkcje_Komunikator.h

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                        FUNCKJE KOMUNIKATOR
-----------------------------------------------------------------------------------------------------------------------------------------------------------  */

void rozdzielenie(string napis, string &pierwsza_czesc, string &druga_czesc);
/**
    Rozdziela NAPIS na pierwsza czesc i druga czesc ktore sa przyslane PRZEZ REFERENCJE
    DWUKROPEK rozdziela stringa
    Na potrzeby KOMUNIKATORA
*/

void rozdzielenie_historia(string napis, string &pierwsza_czesc, string &druga_czesc);
/**
    Usprawniona wersja ROZDZIELENIA na potrzeby HISTORII
    Na potrzeby KOMUNIKATORA
*/

class Komunikator {
    /**
        Klasa stworzona tylko po to zeby gdy obiekt umrze zostalo wpisane do pliku ze uzytkownik opuscil czat
        Niestety w podejsciu proceduralnym nie dziala dla klikniecia IKSA konsoli
    */
    string uzytkownik;
        ///Przechowywujemy nazwe uzytkownika
public:
    Komunikator(string u = "Gosc");
    /**
        KONSTRUKTOR -> ustawia uzytkownika
    */
    ~Komunikator();
    /**
        DESTRUKTOR -> wpisuje do pliku ze OPUSCILISMY CZAT
    */
};

#endif // Funkcje_Komunikator
