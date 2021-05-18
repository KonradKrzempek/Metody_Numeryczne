#include <iostream>
#include <math.h>
using namespace std;

double funkcja(double x)
{
	return(cos(2*x)+x*x-3);
}

double prostokat(int n, double xp, double xk, double dx) 
{
	double w = 0.0;

	for (int i = 1; i < n; i++) //funkcja wywoluje sie n-1 razy
	{
		w += funkcja(xp + i * dx); //dodawanie sie pol poszczegolnych podprzedzialow

	}

	w *= dx;
	return w; //zwrocenie wyniku
}


double trapez(int n, double xp, double xk, double dx)
{
	double w = 0.0;
	double podst_a = funkcja(xp), podst_b; //podstawy trapezow

	for (int i = 1; i <= n; i++) // wywolanie funkcji n razy
	{
		podst_b = funkcja(xp + dx * i);
		w += (podst_a + podst_b);
		podst_a = podst_b; // przypisanie podstawie a wartosc podstawy b dla kolejnego wywolania petli
	}
	return w * dx/2; //zwrocenie pola wszystkich trapezow
}

int main() {
	double xp, xk, dx;
	int n;
	
	cout << "podaj poczatek przedzialu calkowania"<<endl;
	cin >> xp;
	cout << "podaj koniec przedzialu calkowania" << endl;
	cin >> xk;
	cout << "podaj liczbe przedzialow" << endl;
	cin >> n;

	dx = (xk - xp) / n;


	cout << "wynik metoda prostokatow: " << prostokat(n, xp, xk, dx) << endl;
	cout << "wynik metoda trapezow: " << trapez(n, xp, xk, dx) << endl;

	system("pause");

}