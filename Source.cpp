#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double eps = 1e-10; // dok³adnoœæ
double a = 1.0;  // pocz¹tek i koniec przedzia³u
double b = 2.0;  

double f(double x) // funkcja 
{
    return(x*x*x+x*x-3*x-3);
}


int main()
{
    double fa, fb, fx, x0;

    cout << setprecision(10) << fixed;
 

    // obliczamy wartoœci funkcji na krañcach przedzia³u [a,b]
    fa = f(a);
    fb = f(b);

    // sprawdzamy, czy na krañcach przedzia³u [a,b] wartoœci funkcji maj¹ ró¿ne znaki

    if (fa * fb > 0) {
        cout << "Funkcja musi miec rozne znaki na koncach przedzialow" << endl;
       return 1;
    }
    else

        // w pêtli wyznaczamy kolejne przybli¿enia pierwiastka
        do 
        {
            // wyznaczamy x0
            x0 = (fa * b - fb * a) / (fa - fb);

            // obliczamy i zapamiêtujemy wartoœæ funkcji w punkcie x0
            fx = f(x0);

            // za nowy przedzia³ [a,b] przyjmujemy t¹ z czêœci [a,x0], [x0,b],
            // w której funkcja ma ró¿ne znaki na krañcach
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
        // pêtle wykonujemy do czasu uzyskania oczekiwanej dok³adnoœci
    

   cout << "x0 wynosi:  " << x0 << endl;
       

    return 0;
}
