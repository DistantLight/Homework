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
    double xt, a, b, e, lambda;
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
    xt = a;

    if (functionp(a,arr) >= functionp(b, arr))
    {
        lambda = 1 / functionp(a, arr);
    }
    else
    {
        lambda = 1 / functionp(b, arr);
    }



    while (abs(function(xt, arr)) > e) {
        xt = xt - lambda * function(xt, arr);
    }

    cout << "Результат: " << xt << endl;

    return 0;
}