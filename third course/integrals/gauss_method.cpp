#include <iostream>
using namespace std;

double func(double x)
{
	return (x - 0.5) / pow((pow(x, 2) - 1), 0.5);
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
	double* t = new double[n];
	double* c = new double[n];

	h = (b - a) / n;

	if (n == 4)
	{
		t[0] = -0.8611363;
		t[1] = -0.3399810;
		t[2] = 0.3399810;
		t[3] = 0.8611363;
		c[0] = 0.3478548;
		c[1] = 0.6521451;
		c[2] = 0.6521451;
		c[3] = 0.3478548;
	}
	else if (n==5)
	{
		t[0] = -0.9061798;
		t[1] = -0.5384693;
		t[2] = 0;
		t[3] = 0.5384693;
		t[4] = 0.9061798;
		c[0] = 0.2369269;
		c[1] = 0.4786287;
		c[2] = 0.5688888;
		c[3] = 0.4786287;
		c[4] = 0.2369269;
	}

	for (int i = 0; i < n; i++)
	{
		x[i] = (a + b) / 2 + (b - a) / 2 * t[i];
		y[i] = func(x[i]) * c[i];

		res += y[i];
	}
	res = res * (b - a) / 2;

	cout << "x=" << res << endl;
	return 0;
}