#include <iostream>
using namespace std;

double func(double x)
{
	return log10(pow(x, 2) + 2);
}

double calc(int n, double a, double b)
{
	double h, res = 0;
	double s1 = 0, s2 = 0;

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
	res = (func(a) + func(b) + 4 * s1 + 2 * s2) * h / 3;

	return res;
}

int main()
{
	setlocale(LC_ALL, "ru");

	double a, b;

	cout << "Введите границы интервала интегрирования" << endl;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;

	int n1;
	cout << "Введите количество шагов для первого интеграла" << endl;
	cin >> n1;

	double res1 = calc(n1, a, b);

	int n2;
	cout << "Введите количество шагов для второго интеграла" << endl;
	cin >> n2;

	double res2 = calc(n2, a, b);
	int m = 4;
	double I = res2 + pow(n1, m) * (res2 - res1) / (pow(n2, m) - pow(n1, m));

	cout << "I=" << I << endl;
	return 0;
}