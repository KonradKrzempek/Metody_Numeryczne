#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double eps = 1e-10; // dokładność
double a = 1.0;  // początek i koniec przedziału
double b = 2.0;  

double f(double x) // funkcja 
{
    return(x*x*x+3*x*x-3*x-5);
}


int main()
{
    double fa, fb, fx, x0;

    cout << setprecision(10) << fixed;
 

    // obliczamy wartości funkcji na krańcach przedziału [a,b]
    fa = f(a);
    fb = f(b);

    // sprawdzamy, czy na krańcach przedziału [a,b] wartości funkcji mają różne znaki

    if (fa * fb > 0) {
        cout << "Funkcja musi miec rozne znaki na koncach przedzialow" << endl;
       return 1;
    }
    else

        // w pętli wyznaczamy kolejne przybliżenia pierwiastka
        do 
        {
            // wyznaczamy x0
            x0 = (fa * b - fb * a) / (fa - fb);

            // obliczamy i zapamiętujemy wartość funkcji w punkcie x0
            fx = f(x0);

            // za nowy przedział [a,b] przyjmujemy tą z części [a,x0], [x0,b],
            // w której funkcja ma różne znaki na krańcach
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
        // pętle wykonujemy do czasu uzyskania oczekiwanej dokładności
    

   cout << "x0 wynosi:  " << x0 << endl;
       

    return 0;
}
