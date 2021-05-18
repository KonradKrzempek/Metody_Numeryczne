#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

int main() {

	double X[] = {0,5,5,0};
	double Y[] = {0,0,5,5};
	// deklaracja 2 tablic przechowywuj¹cych wspó³rzêdne punktów
	int i; int j;
	double xksi, yksi, xni, yni, powierzchnia=0.0;
	double pksi[2][4];
	double pni[2][4];
	double fun[2][2];
	double punkt[2];
	double waga[2];
	// zadeklarowanie wszystkich zmiennych i tablic
	punkt[0] = -0.5773502692; 
	punkt[1] = 0.5773502692;
	waga[0] = 1;
	waga[1] = 1;
	
	for (j = 0; j< 2; j++) {
		for (i = 0; i <2; i++) {

			pksi[j][0] = -0.25 * (1 - punkt[j]); //obliczanie wartosci pochodnych ksi
			pksi[j][1] = 0.25 * (1 - punkt[j]);
			pksi[j][2] = 0.25 * (1 + punkt[j]);
			pksi[j][3] = -0.25 * (1 + punkt[j]);

			pni[i][0] = -0.25 * (1 - punkt[i]); // obliczanie wartosci pochodnych ni
			pni[i][1] = -0.25 * (1 + punkt[i]);
			pni[i][2] = 0.25 * (1 + punkt[i]);
			pni[i][3] = 0.25 * (1 - punkt[i]);

			xksi = pksi[j][0] * X[0] + pksi[j][1] * X[1] + pksi[j][2] * X[2] + pksi[j][3] * X[3];
			yksi = pksi[j][0] * Y[0] + pksi[j][1] * Y[1] + pksi[j][2] * Y[2] + pksi[j][3] * Y[3];
			//obliczenie wartoœci dx od ksi i dy od ksi 
			//poprzez zsumowanie wartoœci punktu * wartoœæ pochodnej od ksi dla wszystkich 4 punktów

			xni = pni[i][0] * X[0] + pni[i][1] * X[1] + pni[i][2] * X[2] + pni[i][3] * X[3];
			yni = pni[i][0] * Y[0] + pni[i][1] * Y[1] + pni[i][2] * Y[2] + pni[i][3] * Y[3];
			//obliczenie wartoœci dx od ni i dy od ni w taki sam sposób jak dla ksi

			fun[i][j] = xksi * yni - xni * yksi; //obliczenie det|j|
		}
	}

	for (j = 0; j <2; j++) {
		for (i = 0; i <2; i++) {

			powierzchnia = powierzchnia + abs(fun[i][j])*waga[i]*waga[j]; 
			//obliczenie powierzchni
		}
	}

	cout <<"Powierzchnia wynosi: "<< powierzchnia<<endl;
	return 0;

}