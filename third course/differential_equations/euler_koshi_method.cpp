#include <iostream>
using namespace std;

double func(double x, double y)
{
	return 0.221 * (pow(x, 2) + sin(1.2 * x)) + 0.452 * y;
}

int main() {
	setlocale(LC_ALL, "ru");

	double a, b, h;

	cout << "Введите границы интервала" << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "Введите шаг" << endl;
	cin >> h;

	int n = (b - a) / h;

	double* x = new double[n];
	double* y = new double[n];
	double* yt = new double[n];

	cout << "Введите начальное условие" << endl;
	cin >> y[0];
	x[0] = a;
	yt[0] = 0;

	cout << "x     y" << endl;
	cout << x[0] << "  " << y[0] << endl;

	for (int i = 1; i < n + 1; i++)
	{
		x[i] = x[i - 1] + h;
		yt[i] = y[i - 1] + h * func(x[i-1], y[i-1]);
		y[i] = y[i - 1] + h * (func(x[i - 1], y[i - 1]) + func(x[i], yt[i])) / 2;
		cout << x[i] << "  " << y[i] << endl;
	}

	return 0;
}