#include <iostream>
using namespace std;

double funcF(double x, double y)
{
	return tan(x * y + 0.3) - pow(x, 2);
}

double funcG(double x, double y)
{
	return 0.9 * pow(x, 2) + 2 * pow(y, 2) - 1;
}

double df_dx(double x, double y)
{
	return y * ( pow ( tan (x * y + 0.3), 2) + 1) - 2 * x;
}

double df_dy(double x, double y)
{
	return x * ( pow(tan( x * y + 0.3), 2) + 1);
}

double dg_dx(double x)
{
	return 1.8 * x;
}

double dg_dy(double y)
{
	return 4 * y;
}

int main() {
	setlocale(LC_ALL, "ru");

	double x, y, xlast = 1000, ylast = 1000, e = 0.001;
	cout << "Система уравнений:" << endl;
	cout << "F(x,y) = tan(xy+0.4)-x^2\nG(x,y) = 0.9x^2+2y^2-1" << endl;
	cout << endl;
	cout << "Начальное приближение: ";
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	double dn, dh, dk;

	while (abs(x - xlast) > e & abs(y - ylast) > e)
	{
		xlast = x;
		ylast = y;

		dn = df_dx(x, y) * dg_dy(y) - df_dy(x, y) * dg_dx(x);
		dh = df_dy(x, y) * funcG(x, y) - funcF(x, y) * dg_dy(y);
		dk = funcF(x, y) * dg_dx(x) - funcG(x, y) * df_dx(x, y);

		x = xlast + dh / dn;
		y = ylast + dk / dn;

	}


	cout << "x=" << x << endl << "y=" << y;
	return 0;
}