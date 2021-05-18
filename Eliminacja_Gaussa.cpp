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
    for (i = 0; i < n - 1; i++)          //p�tla eliminacji Gaussa
        for (k = i + 1; k < n; k++)
        {
            double t = A[k][i] / A[i][i];
            for (j = 0; j <= n; j++)
                A[k][j] = A[k][j] - t * A[i][j];    //zerowanie element�w w macierzy 
        }

    cout << "\n\nMacierz po eliminacji Gaussa:" << endl;
    wyswietl(n, A, x);

    for (i = n - 1; i >= 0; i--)        //rozwiazywanie macierzy od ko�ca
    {              //x jest macierz� kt�rej warto�ci odpowiadaj� warto�ci� x1,x2,x3...
        x[i] = A[i][n];              //obliczanie warto�ci zaczynaj�c od prawej strony
        for (j = i + 1; j < n; j++)
            if (j != i)
                //podstawienie wszystkich warto�ci kt�re s� znane na danym etapie oblicze�
                x[i] = x[i] - A[i][j] * x[j];
        x[i] = x[i] / A[i][i];       //podzielenie prawej strony przez wsp�czynnik zmiennej do obliczenia
    }
    cout << "\nWyniki:" << endl;
    for (i = 0; i < n; i++)
        cout << x[i] << endl;        // wy�wietlenie wynik�w  
}


int main() 
{
    int n;
    double** A, * x;                   //tablice dynamiczne
        cout.precision(5);             //ustawienie dok�adno�ci

    cout << "Podaj liczbe niewiadomych:" << endl;
    cin >> n;                      //pobranie ilo�ci niewiadomych

    if (n <= 0)                    //sprawdzenie czy ilo�� niewiadomych jest dodatnia
    {
        cout << "Ilosc niewiadomyuch musi byc wieksza niz 0 ";
        return 0;
    }
    else

        A = new double* [n];
    for (i = 0; i < n; i++) A[i] = new double[n + 1]; //stworzenie tablicy
    x = new double[n];           //stworzenie macierzy do przechowywania warto�ci r�wna�  

    cout << "\nPodaj wartosci macierzy" << endl;// podanie warto�ci 
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            cin >> A[i][j];         //przypisanie warto�ci do macierzy

    cout << "\nMaceirz rzed przestawieniem: " << endl;
    wyswietl (n, A, x);

    for (i = 0; i < n; i++)                      //przestawienie
        for (k = i + 1; k < n; k++)
            if (abs(A[i][i]) < abs(A[k][i])) //warunek dla przestawiania 
                for (j = 0; j <= n; j++)
                {
                    double temp = A[i][j];
                    //przestawienie warto�ci w tablicy z u�yciem zmiennej pomocniczej
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
    cout << "\nMaceirz po przestawieniu: " << endl;
    wyswietl(n, A, x);

    gauss(n, A, x);
    
	system("pause");
    
}