#include "..\_Headers\funkcje.h"
#include "FunkcjePI.h"

void wypisz_pi(int miejsce, int kolor_saturnina)
{
    fstream pi; string linia;
    pi.open("../Pliki/przyblizenie_pi",ios::in);
            system("cls");
            string calosc ="";
            while(getline(pi,linia))
            {
                calosc += linia;
            }
            pi.close();
            saturnin_mowi(kolor_saturnina);
            cout << "3.";
            for(int i=1;i<=miejsce;i++)
            {
                cout << calosc.substr(i-1,1);
                if(i%6 == 0&&i!=0) cout << "\n  ";
            }
}

void rysowanie_calc(int wiersz, int pole, int nasz_kolor,int kolor_saturnina)
{
    saturnin_mowi(1);
    for(int i = 1;i<=3;i++)
    {
        ustaw_wskaznik(1+3+5,wiersz+ i*6);
        for(int i=0;i<20;i++)
        {
            cout << "-";
        }
    }
    for(int i=1;i<=2;i++)
    {
        for(int j=wiersz+1;j<=wiersz+23;j++)
        {
            ustaw_wskaznik(i*7+8,j);
            cout << "|";
        }
    }
    int kolorek = kolor_saturnina;
    saturnin_mowi( pole == 1 ? nasz_kolor : kolorek);
    ustaw_wskaznik(10,wiersz+1); cout << " xx ";
    ustaw_wskaznik(10,wiersz+2); cout << "xxx ";
    ustaw_wskaznik(10,wiersz+3); cout << " xx ";
    ustaw_wskaznik(10,wiersz+4); cout << " xx ";
    ustaw_wskaznik(10,wiersz+5); cout << "xxxx";

    saturnin_mowi( pole == 2 ? nasz_kolor : kolorek);
    ustaw_wskaznik(17,wiersz+1); cout << "xxxx";
    ustaw_wskaznik(17,wiersz+2); cout << "x  x";
    ustaw_wskaznik(17,wiersz+3); cout << "  x ";
    ustaw_wskaznik(17,wiersz+4); cout << " x  ";
    ustaw_wskaznik(17,wiersz+5); cout << "xxxx";

    saturnin_mowi( pole == 3 ? nasz_kolor : kolorek);
    ustaw_wskaznik(24,wiersz+1); cout << "xxxx";
    ustaw_wskaznik(24,wiersz+2); cout << "   x";
    ustaw_wskaznik(24,wiersz+3); cout << "xxxx";
    ustaw_wskaznik(24,wiersz+4); cout << "   x";
    ustaw_wskaznik(24,wiersz+5); cout << "xxxx";

    saturnin_mowi( pole == 4 ? nasz_kolor : kolorek);
    ustaw_wskaznik(10,wiersz+7);  cout << "  x ";
    ustaw_wskaznik(10,wiersz+8);  cout << " xx ";
    ustaw_wskaznik(10,wiersz+9);  cout << "x x ";
    ustaw_wskaznik(10,wiersz+10); cout << "xxxx";
    ustaw_wskaznik(10,wiersz+11); cout << "  x ";

    saturnin_mowi( pole == 5 ? nasz_kolor : kolorek);
    ustaw_wskaznik(17,wiersz+7);  cout << "xxxx";
    ustaw_wskaznik(17,wiersz+8);  cout << "x   ";
    ustaw_wskaznik(17,wiersz+9);  cout << "xxxx";
    ustaw_wskaznik(17,wiersz+10); cout << "   x";
    ustaw_wskaznik(17,wiersz+11); cout << "xxxx";

    saturnin_mowi( pole == 6 ? nasz_kolor : kolorek);
    ustaw_wskaznik(24,wiersz+7);  cout << "xxxx";
    ustaw_wskaznik(24,wiersz+8);  cout << "x   ";
    ustaw_wskaznik(24,wiersz+9);  cout << "xxxx";
    ustaw_wskaznik(24,wiersz+10); cout << "x  x";
    ustaw_wskaznik(24,wiersz+11); cout << "xxxx";

    saturnin_mowi( pole == 7 ? nasz_kolor : kolorek);
    ustaw_wskaznik(10,wiersz+13); cout << "xxxx";
    ustaw_wskaznik(10,wiersz+14); cout << "x  x";
    ustaw_wskaznik(10,wiersz+15); cout << "  x ";
    ustaw_wskaznik(10,wiersz+16); cout << " x  ";
    ustaw_wskaznik(10,wiersz+17); cout << "x   ";

    saturnin_mowi( pole == 8 ? nasz_kolor : kolorek);
    ustaw_wskaznik(17,wiersz+13); cout << "xxxx";
    ustaw_wskaznik(17,wiersz+14); cout << "x  x";
    ustaw_wskaznik(17,wiersz+15); cout << "xxxx";
    ustaw_wskaznik(17,wiersz+16); cout << "x  x";
    ustaw_wskaznik(17,wiersz+17); cout << "xxxx";

    saturnin_mowi( pole == 9 ? nasz_kolor : kolorek);
    ustaw_wskaznik(24,wiersz+13); cout << "xxxx";
    ustaw_wskaznik(24,wiersz+14); cout << "x  x";
    ustaw_wskaznik(24,wiersz+15); cout << "xxxx";
    ustaw_wskaznik(24,wiersz+16); cout << "   x";
    ustaw_wskaznik(24,wiersz+17); cout << "xxxx";

    saturnin_mowi( pole == 10 ? nasz_kolor : kolorek);
    ustaw_wskaznik(9,wiersz+19); cout << "xxxxxx";
    ustaw_wskaznik(9,wiersz+20); cout << "x x x ";
    ustaw_wskaznik(9,wiersz+21); cout << "  x x ";
    ustaw_wskaznik(9,wiersz+22); cout << "  x x ";
    ustaw_wskaznik(9,wiersz+23); cout << "  x x ";

    saturnin_mowi( pole == 11 ? nasz_kolor : kolorek);
    ustaw_wskaznik(17,wiersz+19); cout << "xxxx";
    ustaw_wskaznik(17,wiersz+20); cout << "x  x";
    ustaw_wskaznik(17,wiersz+21); cout << "x  x";
    ustaw_wskaznik(17,wiersz+22); cout << "x  x";
    ustaw_wskaznik(17,wiersz+23); cout << "xxxx";

    saturnin_mowi( pole == 12 ? nasz_kolor : kolorek);
    ustaw_wskaznik(23,wiersz+19); cout << "x    x";
    ustaw_wskaznik(23,wiersz+20); cout << "x xx x";
    ustaw_wskaznik(23,wiersz+21); cout << "xxxxxx";
    ustaw_wskaznik(23,wiersz+22); cout << "x xx x";
    ustaw_wskaznik(23,wiersz+23); cout << "x    x";

    ustaw_wskaznik(1,wiersz+24);
}
