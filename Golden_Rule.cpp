#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

double eps = 1e-6;  // przybli¿ona wartoœæ zera

double funkcja(double x)
{
	return(3*x*x*x-14*x*x+8);
}

double zlotypodzial(double a, double b)
{
    double k = 0.61803398;  //z³ota liczba
    double xl = b - k * (b - a);
    double xp = a + k * (b - a);

    
    while ((b - a) > eps)
    //pêtla powtarza siê dopóki b-a jest wiêksze od naszego przybli¿enia zera
    {
        if (funkcja(xl) < funkcja(xp))
        {
            b = xp;
            xp = xl;
            xl = b - k * (b - a);
        }
        else
        {
            a = xl;
            xl = xp;
            xp = a + k * (b - a);
        }
    }
    return (a + b) / 2; // zwrócenie wyniku
}

int main() {
    double a, b;
    cout << "podaj a i b" << endl;
    cin >> a;
    cin >> b;
    
	cout << "wynik metody zlotego podzialu: " << zlotypodzial(a,b) << endl;
	

	system("pause");

}