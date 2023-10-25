#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");


	const int m = 4;

	double A[m][m] = { 0.18,-0.34,-0.12,0.15,
					  0.11,0.23,-0.15,0.32,
					  0.05,-0.12,0.14,-0.18,
					  0.12,0.08,0.06,0 };
	double B[m] = { -1.33,0.84,-1.16,0.57 };


	double X[m];
	double Xlast[m];
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		Xlast[i] = B[i];
		X[i] = 0;
	}

	while (count!=m)
	{
		count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				X[i] = X[i] + A[i][j] * Xlast[j];
				if (j == m - 1)
				{
					X[i] += B[i];
				}


			}
			if (abs(X[i] - Xlast[i]) < 0.001)
			{
				count += 1;
			}
		}


		for (int i = 0; i < m; i++)
		{
			Xlast[i] = X[i];
			X[i] = 0;
		}


		for (int i = 0; i < m; i++)
		{
			cout << Xlast[i] << endl;
		}
		cout << endl << endl;
	}

	for (int i = 0; i < m; i++)
	{
		cout << "x" << i + 1 << "= " << Xlast[i] << endl;
	}

	system("pause");
	return 0;

}