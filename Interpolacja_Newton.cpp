#include <iostream>
using namespace std;

float N_interpolation(int* x, int* y, int a, int i) 
{
	if (a == 0)return 1;							
	if (a == 1)return (y[i + 1] - y[i]) / (x[i + 1] - x[i]);	
	return	(N_interpolation(x, y, a - 1, i + 1) - N_interpolation(x, y, a - 1, i)) / (x[i + a] - x[i]);
}
int main() {

	int xi, n;

	cout << "Wprowadz punkt interpolacji: ";
	cin >> xi;
	
	cout << "Podaj ilosc wprowadzanych punktow: ";
	cin >> n;

	if (n <= 0) 
	{
		cout << "Ilosc pkt nie moze byc rowna lub mniejsza niz zero ";
		return 0;
	}

	cout << "Wprowadz dane (wartosci x nie moga sie powtarzac):" << endl;
	int* x = new int[n];
	int* y = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Podaj x ";
		cin >> x[i];
		cout << "Podaj y ";
		cin >> y[i];
		cout << endl;
	}


	float wynik = y[0]; 
	int  b = 0;			
	for (int i = 0; i < n; i++)
	{
		b = 0;
		for (int j = 0; j < i; j++)
		{
			if (j == 0)b = xi - x[0];
			else b *= xi - x[j];
		}
		wynik = wynik + b * N_interpolation(x, y, i, 0);
	}
	cout << "Wynik dla x = " << xi<< " to: " << wynik << endl;

	system("pause");
}
