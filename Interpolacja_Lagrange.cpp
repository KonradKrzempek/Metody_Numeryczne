#include <iostream>
using namespace std;

float lagrange_interpolation(float xi, float x[], float y[], int n)
{
	float yi = 0;
	for (int i = 1; i <= n; i++)
	{
		float a = 1;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				a = a * (xi - x[j]) / (x[i] - x[j]);
			}
		}
		yi = yi + a * y[i];
	}
	return yi;
}
int main()
{

	int n;
	float xi, wynik, x[50], y[50], l, min, max;

	cout << "Podaj ilosc wprowadzanych punktow: ";
	cin >> n;

	if (n <= 0) {
		cout<<"Ilosc pkt nie moze byc rowna lub mniejsza niz zero ";
		return 0;
	}

	cout << "Wprowadz dane (wartosci x nie moga sie powtarzac):" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "podaj x ";
		cin >> x[i];
		cout << "podaj y ";
		cin >> y[i];
		cout << endl;

		if (i == 1) {
			min = x[i];
			max = x[i];
		}
		else if (x[i] < min) {
			min = x[i];
		}
		else if (x[i] > max) {
			max = x[i];
		}
	}

	cout<<"Wprowadz punkt interpolacji: ";
	cin >> xi;

	while (xi > max || xi < min) {
		cout<<"Punkt z poza przedzialu wprowadz ponownie: ";
		cin >> xi;
	}

	wynik = lagrange_interpolation(xi,x,y,n);
	
	cout << "Wartosc interpolowana funkcji w punkcie " << xi << " wynosi " << wynik << endl;

}