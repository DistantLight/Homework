#include <iostream>
using namespace std;

double func(double x, double y)
{
	return x + cos(y / 3.14);
}

int main() {
	setlocale(LC_ALL, "ru");

	double a, b, h, f, y0, ft0, y1, ft1, y2, ft2;

	cout << "Введите границы интервала" << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "Введите шаг" << endl;
	cin >> h;

	double n = (b - a) /h;
	cout << n << endl;
	double* x = new double[n];
	double* y = new double[n];

	cout << "Введите начальное условие" << endl;
	cin >> y[0];
	x[0] = a;

	cout << "x     y" << endl;
	cout << x[0] << "  " << y[0] << endl;

	for (int i = 1; i < n; i++)
	{
		f = func(x[i-1], y[i-1]);
		y0 = y[i-1] + h * f;
		ft0 = func(x[i-1] + h, y0);
		while (true)
		{
			y1 = y[i-1] + 0.5 * h * (f + ft0);
			ft1 = func(x[i-1] + h, y1);
			y2 = y[i - 1] + 0.5 * h * (f + ft1);
			ft2 = func(x[i - 1] + h, y2);
			if (abs(ft2 - ft1) < 0.001)
			{
				break;
			}
			y1 = y2;
			ft1 = ft2;
		}
		x[i] = x[i - 1] + h;
		y[i] = y2;
		cout << x[i] << "  " << y[i] << endl;
	}

	return 0;
}