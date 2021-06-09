#include <iostream>
#include <iomanip>
using namespace std;

float f(float x, float y)
{
    return 3*x*x-5*y;    //funckja f(x)
}

void euler(float x0, float y, float h, float x)
{
    cout << "Rozwiazanie dla x = " << setprecision(1) << fixed << x0;
    cout << "  wynosi  " << setprecision(5) << fixed << y << endl;

    while (x0 < x) {  
    //pêtla wykonywana do osi¹gniêcia przez punkt pocz¹tkowy wartoœci koñca przedzia³u

        y = y + h * f(x0, y); //obliczanie y
        x0 = x0 + h;          //zwiêkszenie wartoœci x0 o h 
        cout << "Rozwiazanie dla x = " << setprecision(1) << fixed<< x0;
        cout<<"  wynosi  " << setprecision(5) << fixed << y << endl;
    }
}

int main()
{
    float x0 = 0;  //pocz¹tek przedzia³u
    float y0 = 12;
    float h = 0.3; //krok
    float x = 1.5;   //koniec przedzia³u

    euler(x0, y0, h, x);

    return 0;
}