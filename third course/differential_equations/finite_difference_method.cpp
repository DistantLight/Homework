#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	double a, b, h, xt, yt, r, ys, y1;

	cout << "Введите границы отрезка" << endl;
	cout << "A: ";
	a = 0.6;
	cout << "B: ";
	b = 0.9;
	cout << "Введите шаг" << endl;
	h = 0.05;
	int n = 6;

	double a0 = 0, a1 = 1, b0 = 1, b1 = -0.5, A = 0.7, B = 1, p = 2;

	double* X = new double[n + 1];
	double* Y = new double[n + 1];
	double* q = new double[n + 1];
	double* c = new double[n + 1];
	double* d = new double[n + 1];
	double* m = new double[n + 1];
	double* N = new double[n + 1];
	double* F = new double[n + 1];

	X[0] = a;

	cout << "Введите начальное значение y" << endl;
	//cin >> Y[0];

	q[0] = X[0] * (-1);
	c[0] = a1 / (a0 * h - a1);
	d[0] = A * h;

	cout << d[0] << endl;
	for (int i = 1; i < n + 1; i++)
	{
		X[i] = X[i - 1] + h;
		q[i] = (-1) * X[i];
	}

	for (int i = 0; i < n + 1; i++)
	{
		m[i] = (2 * h * h * q[i] - 4) / (2 + h * p);
		N[i] = (2 - h * p) / (2 + h * p);
		F[i] = (2 * X[i] * X[i]) / (2 + h * p);
	}

	for (int i = 1; i < n + 1; i++)
	{
		c[i] = 1 / (m[i] - N[i] * c[i - 1]);
		d[i] = F[i] * h * h - N[i] * d[i - 1] * c[i - 1];
	}

	Y[n] = (B * h + b1 * c[n] * d[n]) / (b0 * h + b1 * (c[n] + 1));

	for (int i = n - 1; i >= 0; i--)
	{
		Y[i] = c[i] * (d[i] - Y[i + 1]);
	}

	cout << "x     y" << endl;
	for (int i = 0; i < n + 1; i++)
	{
		cout << X[i] << " " << Y[i] << endl;
	}
	return 0;
}