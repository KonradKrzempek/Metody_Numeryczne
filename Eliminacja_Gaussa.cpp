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
    for (i = 0; i < n - 1; i++)          //pêtla eliminacji Gaussa
        for (k = i + 1; k < n; k++)
        {
            double t = A[k][i] / A[i][i];
            for (j = 0; j <= n; j++)
                A[k][j] = A[k][j] - t * A[i][j];    //zerowanie elementów w macierzy 
        }

    cout << "\n\nMacierz po eliminacji Gaussa:" << endl;
    wyswietl(n, A, x);

    for (i = n - 1; i >= 0; i--)        //rozwiazywanie macierzy od koñca
    {              //x jest macierz¹ której wartoœci odpowiadaj¹ wartoœci¹ x1,x2,x3...
        x[i] = A[i][n];              //obliczanie wartoœci zaczynaj¹c od prawej strony
        for (j = i + 1; j < n; j++)
            if (j != i)
                //podstawienie wszystkich wartoœci które s¹ znane na danym etapie obliczeñ
                x[i] = x[i] - A[i][j] * x[j];
        x[i] = x[i] / A[i][i];       //podzielenie prawej strony przez wspó³czynnik zmiennej do obliczenia
    }
    cout << "\nWyniki:" << endl;
    for (i = 0; i < n; i++)
        cout << x[i] << endl;        // wyœwietlenie wyników  
}


int main() 
{
    int n;
    double** A, * x;                   //tablice dynamiczne
        cout.precision(5);             //ustawienie dok³adnoœci

    cout << "Podaj liczbe niewiadomych:" << endl;
    cin >> n;                      //pobranie iloœci niewiadomych

    if (n <= 0)                    //sprawdzenie czy iloœæ niewiadomych jest dodatnia
    {
        cout << "Ilosc niewiadomyuch musi byc wieksza niz 0 ";
        return 0;
    }
    else

        A = new double* [n];
    for (i = 0; i < n; i++) A[i] = new double[n + 1]; //stworzenie tablicy
    x = new double[n];           //stworzenie macierzy do przechowywania wartoœci równañ  

    cout << "\nPodaj wartosci macierzy" << endl;// podanie wartoœci 
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            cin >> A[i][j];         //przypisanie wartoœci do macierzy

    cout << "\nMaceirz rzed przestawieniem: " << endl;
    wyswietl (n, A, x);

    for (i = 0; i < n; i++)                      //przestawienie
        for (k = i + 1; k < n; k++)
            if (abs(A[i][i]) < abs(A[k][i])) //warunek dla przestawiania 
                for (j = 0; j <= n; j++)
                {
                    double temp = A[i][j];
                    //przestawienie wartoœci w tablicy z u¿yciem zmiennej pomocniczej
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
    cout << "\nMaceirz po przestawieniu: " << endl;
    wyswietl(n, A, x);

    gauss(n, A, x);
    
	system("pause");
    
}