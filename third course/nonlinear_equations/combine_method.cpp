#include <iostream>
using namespace std;

const int n = 3;

double function(double x, double(&arr)[n + 1])
{
    double temp = 0;
    for (int i = 0; i < n + 1; i++)
    {
        temp = temp + arr[i] * pow(x, i);
    }
    return temp;
}

double functionp(double x, double(&arr)[n + 1]) {
    double temp = 0;
    for (int i = 0; i < n + 1; i++)
    {
        temp = temp + arr[i] * pow(x, i - 1) * i;
    }
    return temp;
}

int main() {
    setlocale(LC_ALL, "ru");
    double x, xt, e;
    double arr[n + 1];
    e = 0.001;
    cout << "Введите коэффициенты многочлена, начиная с последнего" << endl;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    cout << "Введите границы интервала" << endl;
    cout << "A: ";
    cin >> x;
    cout << "B: ";
    cin >> xt;

    while (abs(x-xt) > e) {
        xt = xt - function(xt,arr) / functionp(xt, arr);
        x = x - function(x, arr) * (xt - x) / (function(xt, arr) - function(x, arr));
    }

    cout << "Результат: " << xt << endl;

    return 0;
}