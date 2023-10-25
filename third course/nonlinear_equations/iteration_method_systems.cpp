#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");

	double x, y, xlast = 1000, ylast = 1000, e = 0.001;
	cout << "Система уравнений:" << endl;

	cout << endl;
	cout << "Начальное приближение: ";
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	while (abs(x - xlast) > e & abs(y - ylast) > e)
	{
		xlast = x;
		ylast = y;

		y = sin(x + 0.5) - 1;
		x = (-1) * (cos(y - 2));
	}


	cout << "x=" << x << endl << "y=" << y;
	return 0;
}