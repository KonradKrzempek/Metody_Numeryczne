#include<iostream>

using namespace std;

// funkcja
float f(float x, float y)
{
	return ((y*x*x)/((y-1)*(y-1)));
}

int main()
{
	float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
	int i, n;

	cout << "Podaj warunki wejœciowe dla x i y" << endl;
	cout << "x0 = ";
	cin >> x0;
	cout << "y0 = ";
	cin >> y0;
	cout << "Szukany x = ";
	cin >> xn;
	cout << "Podaj liczbe krokow ";
	cin >> n;


	h = (xn - x0) / n; //obliczamy h

	for (i = 0; i < n; i++)// pêtlê wykonujemy do osi¹gniêcia wybranej liczby kroków
	{
		k1 = h * (f(x0, y0));
		k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
		k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
		k4 = h * (f((x0 + h), (y0 + k3)));
		k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		// obliczamy kolejne wartoœci k

		yn = y0 + k;
		x0 = x0 + h;
		y0 = yn;
	}

	cout <<endl <<" Wartoœæ w punkcie x:" << xn << " wynosi " << yn;

	return 0;
}
