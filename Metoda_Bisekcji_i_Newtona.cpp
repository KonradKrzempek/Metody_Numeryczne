#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double eps = 1e-6;  // przybli¿ona wartoœæ zera
double x0 = -1;     // punkt startowy

double a = -1;     // podanie pocz¹tku i koñca przedzia³u
double b = 0;     

double funkcja(double x)  //funkcja pocz¹tkowa
{
    return atan(2*x*x*x)+0.2;
}

double pochodna(double x) // pochodna funkcji
{
    return (6*x*x)/(4*x*x*x*x*x*x+1);
}

double bisekcja(double a, double b,double eps)
{
    if (funkcja(a) == 0.0)return a; //sprawdzenia czy a lub b nie jest wynikiem.
    if (funkcja(b) == 0.0)return b;

    double srodek;

    while (b - a > eps)
    {
        srodek = (a + b) / 2;

        if (funkcja(srodek) == 0.0) //jesli miejsce zerowe jest w srodku 
            return srodek;

        if (funkcja(a) * funkcja(srodek) < 0) //rownanie metody bisekcji
            b = srodek;
        else
            a = srodek;
    }
    return (a + b) / 2; //zwrocenie wyniku
}
void newton()
{
    double f0, f1, x1; // zmienne
    bool result = false;

    while (true)
    {
        
        f0 = funkcja(x0);   // wartoœæ funkcji w punkcie x0
      
        if (fabs(f0) < eps) // porównanie naszej funkcji do 0
        {
            result = true;
            break;
        }

        f1 = pochodna(x0);  // zmienna f1 przechowuje wartoœæ dla pochodnej 
        x1 = x0;            // zapamiêtanie obecnego wyniku
                           
        x0 -= f0 / f1;      // obliczenie kolejnego przybli¿enia

        if (fabs(x1 - x0) < eps) // sprawdzamy dok³adnoœæ
        {
            result = true;
            break;
        }
        // powtarzamy obliczenia do uzyskania oczekiwanej dok³adnoœci
    }
    if (!result) cout << "Nie zadzialalo "<< endl;

    cout << "x0 = " << x0 << endl; //wyswietlenie wyniku
}
int main()
{
    cout << setprecision(7) << fixed;
    cout << "Wynik metody bisekcji" << endl;
    cout << "Miejsce zerowe wynosi: ";
    cout << bisekcja(a, b, eps) << endl << endl;

    cout << "Wyniki metody Newtona-Rhapsona" << endl;
    newton();
    
    

    return 0;
}