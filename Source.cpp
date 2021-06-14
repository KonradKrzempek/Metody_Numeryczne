#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double eps = 1e-10; // dok�adno��
double a = 1.0;  // pocz�tek i koniec przedzia�u
double b = 2.0;  

double f(double x) // funkcja 
{
    return(x*x*x+x*x-3*x-3);
}


int main()
{
    double fa, fb, fx, x0;

    cout << setprecision(10) << fixed;
 

    // obliczamy warto�ci funkcji na kra�cach przedzia�u [a,b]
    fa = f(a);
    fb = f(b);

    // sprawdzamy, czy na kra�cach przedzia�u [a,b] warto�ci funkcji maj� r�ne znaki

    if (fa * fb > 0) {
        cout << "Funkcja musi miec rozne znaki na koncach przedzialow" << endl;
       return 1;
    }
    else

        // w p�tli wyznaczamy kolejne przybli�enia pierwiastka
        do 
        {
            // wyznaczamy x0
            x0 = (fa * b - fb * a) / (fa - fb);

            // obliczamy i zapami�tujemy warto�� funkcji w punkcie x0
            fx = f(x0);

            // za nowy przedzia� [a,b] przyjmujemy t� z cz�ci [a,x0], [x0,b],
            // w kt�rej funkcja ma r�ne znaki na kra�cach
            if (fa * fx < 0)
            {
                b = x0;
                fb = fx;
            }
            else
            {
                a = x0;
                fa = fx;
            }
        } while (fabs(fx) > eps);
        // p�tle wykonujemy do czasu uzyskania oczekiwanej dok�adno�ci
    

   cout << "x0 wynosi:  " << x0 << endl;
       

    return 0;
}
