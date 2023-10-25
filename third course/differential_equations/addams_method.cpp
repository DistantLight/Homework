#include <iostream>
using namespace std;

double func(double x, double y)
{
	return 1 + 0.4 * y * sin(x) - 1.5 * y * y;
}

int main() {
	setlocale(LC_ALL, "ru");

	double a, b, h, xt, yt, r, ys;
	double R[4];

	cout << "Введите границы отрезка" << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "Введите шаг" << endl;
	cin >> h;
	int n = 10;

	double* X = new double[n + 1];
	double* Y = new double[n + 1];
	double* Q = new double[n];
	double* dQ = new double[n - 1];
	double* d2Q = new double[n - 2];
	cout << "Введите начальное значение y" << endl;
	cin >> Y[0];
	X[0] = a;

	//вторая и третья точки
	xt = a;
	yt = 0;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 3)
			{
				R[i] = h * func(X[j] + h, yt);
			}
			else
			{
				R[i] = h * func(X[j] + 0.5 * h, yt);
			}
			yt = Y[j] + 0.5 * R[i];
		}
		Y[j+1] = Y[j] + (double)1 / 6 * (R[0] + 2 * R[1] + 2 * R[2] + R[3]);
		yt = Y[j+1];
		X[j+1] = X[j] + h;
	}

	Q[0] = h * func(X[0], Y[0]);
	Q[1] = h * func(X[1], Y[1]);
	Q[2] = h * func(X[2], Y[2]);
	dQ[0] = Q[1] - Q[0];
	dQ[1] = Q[2] - Q[1];
	d2Q[0] = dQ[1] - dQ[0];

	for (int i = 3; i < n + 1; i++)
	{
		Q[i - 1] = h * func(X[i - 1], Y[i - 1]);
		dQ[i - 2] = Q[i - 1] - Q[i - 2];
		d2Q[i - 3] = dQ[i - 2] - dQ[i - 3];
		X[i] = X[i - 1] + h;
		Y[i] = Y[i - 1] + Q[i - 1] + 0.5 * dQ[i - 2] + (double)5 / 12 * d2Q[i - 3];
	}

	cout << "x     y" << endl;
	for (int i = 0; i < n + 1; i++)
	{
		cout << X[i] << " " << Y[i] << endl;
	}
	return 0;
}