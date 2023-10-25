#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

double func(double x)
{
	return 1 / pow((2 * pow(x, 2) + 3), 0.5);
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

	double startTime = omp_get_wtime();

	h = (b - a) / n;

	omp_set_num_threads(2);

#pragma omp parallel shared(x,y,res)
	{
		#pragma omp for
		for (int i = 1; i < 10; i++) //вставить n
		{
			x[i] = a + i * h;
			y[i] = func(x[i]);

			res += y[i];
		}
	}
	res = (res + (func(a) + func(b)) / 2) * h;

	cout << "I=" << res << endl;
	double executeTime = omp_get_wtime() - startTime;
	cout << "Executing time: " << executeTime << endl;
	return 0;
}