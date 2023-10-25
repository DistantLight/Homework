#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

const int m = 4;
const int n = 5;

void fill_array(double(&arr)[m][n])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Введите число" << i << " " << j << endl;
			cin >> arr[i][j];
		}
	}
}

void show_array(double(&arr)[m][n])
{
	for (int i = 0; i < m; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " | ";
		}
	}
	cout << endl << endl;
}

double find_norm(double(&arr)[m])
{
	double norm = 0;
	for (int i = 0; i < m; i++)
	{
		norm += arr[i] * arr[i];
	}
	return sqrt(norm);
}

void reflection_method(double(&A)[m][n])
{
	double S[m];
	double W[m];
	double E[m];
	double X[m];

	double Ed[m][m];
	double V[m][m];
	double T[m][m];
	double C[m][n];

	double sNorm;
	double wNorm;

	for (int N = 0; N < m - 1; N++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == j)
				{
					Ed[i][j] = 1;
				}
				else
				{
					Ed[i][j] = 0;
				}
				T[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++)
		{
			if (i <= N - 1) S[i] = 0;
			else S[i] = A[i][N];
		}

		for (int i = 0; i < m; i++)
		{
			if (i == N) E[i] = 1;
			else E[i] = 0;
		}

		sNorm = find_norm(S);
		for (int i = 0; i < m; i++)
		{
			W[i] = S[i] - sNorm * E[i];
		}

		wNorm = find_norm(W);
		for (int i = 0; i < m; i++)
		{
			W[i] /= wNorm;
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				T[i][j] += W[i] * W[j];
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				V[i][j] = Ed[i][j] - 2 * T[i][j];
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				C[i][j] = 0;
				for (int k = 0; k < m; k++)
				{
					C[i][j] += V[i][k] * A[k][j];
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				A[i][j] = C[i][j];
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		X[i] = A[i][m] / A[i][i];
	}
	double temp;
	for (int i = m-1; i >= 0; i--)
	{
		X[i] = A[i][m];
		temp = 0;
		for (int j = i + 1; j < m; j++)
		{
			temp += A[i][j] * X[j];
		}
		X[i] -= temp;
		X[i] /= A[i][i];
		cout << "x" << i <<"=" << X[i] << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "Rus");


	double A[m][n] = { 19,0,1,-3,0,
						-1,14,1,1,1,
						3,2,17,6,2,
						7,8,0,20,3};
	show_array(A);
	reflection_method(A);


	system("pause");
	return 0;

}