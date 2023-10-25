#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

const int m = 4;

void fill_array(double(&arr)[m][m])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "Введите число" << i << " " << j << endl;
			cin >> arr[i][j];
		}
	}
}

void show_array(double(&arr)[m][m])
{
	for (int i = 0; i < m; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " | ";
		}
	}
	cout << endl << endl;
}

void method_LU(double(&arr)[m][m], double(&B)[m])
{
	double temp1;
	double temp2;


	double L[m][m];
	double U[m][m];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			L[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			U[i][j] = arr[i][j];
		}
	}


	for (int i = 0; i < m; i++) {

		for (int a = i + 1; a < m; a++) {
			temp1 = U[i][i];
			temp2 = U[a][i];
			L[a][i] = temp2 / temp1;

			for (int b = 0; b < m; b++) {
				if (temp1 != 0)
				{
					U[a][b] = U[a][b] - U[i][b] * temp2 / temp1;

				}
			}

		}
	}

	cout << "U =";
	show_array(U);
	cout << "L =";
	show_array(L);


	double Y[m];
	for (int i = 0; i < m; i++)
	{
		Y[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		Y[i] = B[i];
		for (int j = 0; j < m; j++)
		{

			Y[i] = Y[i] - L[i][j] * Y[j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << Y[i] << endl;
	}

	double X[m];
	for (int i = 0; i < m; i++)
	{
		X[i] = 0;
	}

	for (int i = m - 1; i >= 0; i--)
	{
		X[i] = Y[i];
		for (int j = m - 1; j >= 0; j--)
		{
			if (i == j)
			{
				X[i] = X[i] / U[i][j];
				continue;
			}

			X[i] = X[i] - U[i][j] * X[j];
		}
		cout << "x" << i + 1 << "= " << X[i] << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");


	double A[m][m] = { 1,2,4,1,
						  2,8,6,4,
						  3,10,8,8,
						  4,12,10,6 };
	double B[m] = { 21, 52, 79, 82 };
	show_array(A);
	method_LU(A, B);


	system("pause");
	return 0;

}