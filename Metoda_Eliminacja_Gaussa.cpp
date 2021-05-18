#include <iostream>
#include <iomanip>

using namespace std;
int i,j,k;
void wyswietl(int n, double** A, double* x) 
{
    for (i = 0; i < n; i++)            //wyswietlenie
    {
        for (j = 0; j <= n; j++)
            cout << A[i][j] << setw(10);
        cout << "\n";
    }
}

void gauss(int n, double** A, double* x)
{
    for (i = 0; i < n - 1; i++)          //pętla eliminacji Gaussa
        for (k = i + 1; k < n; k++)
        {
            double t = A[k][i] / A[i][i];
            for (j = 0; j <= n; j++)
                A[k][j] = A[k][j] - t * A[i][j];    //zerowanie elementów w macierzy 
        }

    cout << "\n\nMacierz po eliminacji Gaussa:" << endl;
    wyswietl(n, A, x);

    for (i = n - 1; i >= 0; i--)        //rozwiazywanie macierzy od końca
    {              //x jest macierzą której wartości odpowiadają wartością x1,x2,x3...
        x[i] = A[i][n];              //obliczanie wartości zaczynając od prawej strony
        for (j = i + 1; j < n; j++)
            if (j != i)
                //podstawienie wszystkich wartości które są znane na danym etapie obliczeń
                x[i] = x[i] - A[i][j] * x[j];
        x[i] = x[i] / A[i][i];       //podzielenie prawej strony przez współczynnik zmiennej do obliczenia
    }
    cout << "\nWyniki:" << endl;
    for (i = 0; i < n; i++)
        cout << x[i] << endl;        // wyświetlenie wyników  
}


int main() 
{
    int n;
    double** A, * x;                   //tablice dynamiczne
        cout.precision(5);             //ustawienie dokładności

    cout << "Podaj liczbe niewiadomych:" << endl;
    cin >> n;                      //pobranie ilości niewiadomych

    if (n <= 0)                    //sprawdzenie czy ilość niewiadomych jest dodatnia
    {
        cout << "Ilosc niewiadomyuch musi byc wieksza niz 0 ";
        return 0;
    }
    else

        A = new double* [n];
    for (i = 0; i < n; i++) A[i] = new double[n + 1]; //stworzenie tablicy
    x = new double[n];           //stworzenie macierzy do przechowywania wartości równań  

    cout << "\nPodaj wartosci macierzy" << endl;// podanie wartości 
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            cin >> A[i][j];         //przypisanie wartości do macierzy

    cout << "\nMaceirz rzed przestawieniem: " << endl;
    wyswietl (n, A, x);

    for (i = 0; i < n; i++)                      //przestawienie
        for (k = i + 1; k < n; k++)
            if (abs(A[i][i]) < abs(A[k][i])) //warunek dla przestawiania 
                for (j = 0; j <= n; j++)
                {
                    double temp = A[i][j];
                    //przestawienie wartości w tablicy z użyciem zmiennej pomocniczej
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
    cout << "\nMaceirz po przestawieniu: " << endl;
    wyswietl(n, A, x);

    gauss(n, A, x);
    
	system("pause");
    
}
