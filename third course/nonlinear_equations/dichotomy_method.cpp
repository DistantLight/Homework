#include <iostream>
using namespace std;

const int n = 4;

double function(double x, double(&arr)[n + 1])
{
    double temp = 0;
    for (int i = 0; i < n + 1; i++)
    {
        temp = temp + arr[i] * pow(x, i);
    }
    return temp;
}


int main()
{
    setlocale(LC_ALL, "ru");
    double x, a, b, e;
    double arr[n + 1];
    e = 0.001;
    cout << "Введите коэффициенты многочлена, начиная с последнего" << endl;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    cout << "Введите границы интервала" << endl;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    x = (a + b) / 2;

    while (abs(function(x,arr)) > e)
    {
        if (function(a,arr) * function(x,arr) < 0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
        x = (a + b) / 2;
        cout << x<< a << b <<endl;
    }

    cout << "Результат: " << x << endl;

    return 0;
}