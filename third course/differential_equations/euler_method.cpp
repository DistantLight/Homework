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
	double* f = new double[n];

	cout << "Введите начальное условие" << endl;
	cin >> y[0];
	x[0] = a;
	f[0] = func(x[0] + h / 2, y[0] + h /2 * func(x[0], y[0]));

	cout << x[0] << "  " << y[0] << endl;

	for (int i = 1; i < n + 1; i++)
	{
		x[i] = x[i - 1] + h;
		y[i] = y[i - 1] + h * f[i - 1];
		f[i] = func(x[i] + h / 2, y[i] + h * func(x[i], y[i]) / 2);
		cout << x[i] << "  " << y[i] << endl;
	}

	return 0;
}