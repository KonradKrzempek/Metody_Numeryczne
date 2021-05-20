#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

float sxy(vector<float> x, vector<float> y, float n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += x[i - 1] * y[i - 1];
	}
	return suma;
}
float sy(vector<float> y, float n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += y[i - 1];
	}
	return suma;
}
float sx1(vector<float> x, float n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += x[i - 1];
	}
	return suma;
}
float sx2(vector<float> x, float n)
{
	float suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += (x[i - 1]* x[i - 1]);
	}
	return suma;
}

int main() {
	int n;
	cout << "Podaj ilosc punktow" << endl;
	cin >> n;
	vector<float> x, y;
	float a, b;
	float s1, s2, s3, s4, t1, t2;
	

	for (int i = 0; i < n; i++)
	{
		cout << "Podaj x" << i + 1 << ": ";
		cin >> t1;
		x.push_back(t1);
		cout << "Podaj y" << i + 1 << ": ";
		cin >> t2;
		y.push_back(t2);
	}

	s1 = sxy(x, y, n);
	s2 = sy(y, n);
	s3 = sx1(x, n);
	s4 = sx2(x, n);
	//obliczenie wspó³czynników a i b
	a = (n * s1 - s2 * s3) / (n * s4 - (s3*s3));
	b = (s4 * s2 - s3 * s1) / (n * s4 - (s3 * s3));
	cout << "a jest rowne:" << a << endl;
	cout << "b jest rowne:" << b << endl;
	return 0;
}