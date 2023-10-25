#include <string>
#include <iostream>
#include <typeinfo>
#include <complex>

using namespace std;

const int m = 3;

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



int main()
{
	setlocale(LC_ALL, "Rus");


	complex< double > A[m][m] = { 0.93,1.42,-2.55,
						1.42,-2.87,2.36,
						-2.55,2.36,-1.44 };
	complex< double > B[m] = { 2.48, -0.75, 1.83 };


	complex< double >  U[m][m];
	complex< double > Ut[m][m];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			U[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{

		U[i][i] = A[i][i];
		for (int k = 0; k < i; k++)
		{
			cout << U[i][i] << endl << U[k][i] << endl;
			U[i][i] = U[i][i] - U[k][i] * U[k][i];
		}
		U[i][i] = sqrt(U[i][i]);
		cout << U[i][i] << endl;

		for (int j = i + 1; j < m; j++)
		{
			U[i][j] = A[i][j];
			for (int k = 0; k < i; k++)
			{
				U[i][j] -= U[k][i] * U[k][j];
			}
			U[i][j] /= U[i][i];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Ut[i][j] = U[j][i];
		}
	}



	complex <double> Y[m];
	for (int i = 0; i < m; i++)
	{
		Y[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		Y[i] = B[i];
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				continue;
			}
			Y[i] = Y[i] - Ut[i][j] * Y[j];
		}
		Y[i] /= Ut[i][i];
	}
	for (int i = 0; i < m; i++)
	{
		cout << Y[i] << endl;
	}


	complex <double> X[m];
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
		cout << "x" << i + 1 << "= " << X[i].real() << endl;
	}



	system("pause");
	return 0;

}