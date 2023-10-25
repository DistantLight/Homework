#include <iostream>
using namespace std;

double func(double x)
{
	return pow((2 * pow(x, 2) + 1.6), 0.5) / (2 * x + pow((0.5 * pow(x, 2) + 3), 0.5) );
}

int main() {
	setlocale(LC_ALL, "ru");

	double a, b, n, h, res = 0, e = 0.001;

	cout << "Введите границы интервала интегрирования" << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "Введите количество шагов" << endl;
	cin >> n;
	double* x = new double[n];
	double* y = new double[n];

	h = (b - a) / n;

	for (int i = 0; i < n; i++)
	{
		x[i] = a + (i+1) * h;
		y[i] = func(x[i]);

		res += y[i];
	}
	res = res * h;

	cout << "x=" << res << endl;
	return 0;
}