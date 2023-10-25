#include <iostream>
using namespace std;

double func(double x)
{
	return pow(x, 0.5) * cos(pow(x, 2));
}

int main() {
	setlocale(LC_ALL, "ru");

	double a, b, n, h, res = 0, e = 0.001;
	double s1=0, s2=0;
	cout << "Введите границы интервала интегрирования" << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	cout << "Введите количество шагов" << endl;
	cin >> n;
	double* x = new double[n];

	h = (b - a) / n;

	for (int i = 1; i < n; i++)
	{
		x[i] = a + i * h;

		if (i % 2 == 0)
		{
			s2 += func(x[i]);
		}
		else
		{
			s1 += func(x[i]);
		}

	}
	res = (func(a) + func(b) + 4 * s1 + 2 * s2) * h/3;

	cout << "I=" << res << endl;
	return 0;
}