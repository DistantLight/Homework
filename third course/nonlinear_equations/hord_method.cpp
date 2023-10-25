#include <iostream>
using namespace std;

const int n = 3;

double function(double x, double(&arr)[n+1])
{
    double temp=0;
    for (int i = 0; i < n + 1; i++)
    {
        temp = temp + arr[i] * pow(x, i);
    }
    return temp;
}

int main()
{
    setlocale(LC_ALL, "ru");
    double a, xt, e;
    double arr[n+1];
    e = 0.001;
    cout << "Введите коэффициенты многочлена, начиная с последнего"<<endl;
    for (int i = 0; i < n+1; i++)
    {
        cin >> arr[i];
    }
    cout << "Введите границы интервала"<<endl;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> xt;

    double f_a = function(a,arr);
    double f_xt = function(xt,arr);
    while (f_xt > e)
    {
        xt = a - f_a * (xt - a) / (f_xt - f_a);
        f_xt = function(xt,arr);
    }

    cout << "Ответ: " << xt << endl;
}