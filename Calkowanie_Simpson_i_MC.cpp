#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

double funkcja(double x)
{
	return(tan(2*x));
}

double Simpson(int n, double xp, double xk, double dx)
{
	double w = 0.0, x=0.0, a=0.0;
	
	dx = (xk - xp) / n; //dlugosc kazdego z podprzedzialow
	for (int i = 1; i <= n; i++)//wywo³ywanie petli w zaleznosci od ilosci przedzia³ow
	{
		x = xp + i * dx;
		a += funkcja(x - dx / 2); 
		if (i < n) //ten if nie bêdzie spe³niony przy ostatnim wywo³aniu pêtli
		{
			w += funkcja(x); 
		}
	}
	w = dx / 6 * (funkcja(xp) + funkcja(xk) + 2 * w + 4 * a); //obliczenie wyniku
	
	
	return w; //zwrocenie wyniku
}


double MC(int n, double xp, double xk, double dx)
{
	double w = 0.0; 
	dx = xk - xp; //dx - d³ugoœæ przedzia³u ca³kowania 
	for (int i = 1; i <= n; i++) //iloœæ wywo³añ pêtli zale¿y od liczby n podanej przez u¿ytkownika
	{
		w += funkcja(xp + ((double)rand() / (double)(RAND_MAX + 1) * dx));
		// zmiennej "w" przypisywana jest wartoœæ f(x) dla x=xp + liczba losowa *dx
	}
	w = dx * w / n; //obliczenie pola
	
	return w ; //zwrócenie wyniku
}

int main() {
	double xp, xk, dx;
	int n;
	srand(time(NULL));
	cout << "podaj poczatek przedzialu calkowania" << endl;
	cin >> xp;
	cout << "podaj koniec przedzialu calkowania" << endl;
	cin >> xk;
	cout << "podaj liczbe przedzialow/punktow" << endl;
	cin >> n;

	dx = (xk - xp) / n;


	cout << "wynik metoda Simpsona: " << Simpson(n, xp, xk, dx) << endl;
	cout << "wynik metoda Monte Carlo: " <<MC(n, xp, xk, dx) << endl;

	system("pause");

}