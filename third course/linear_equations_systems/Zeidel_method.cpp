#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");

	const int m = 3;

	double A[m][m] = { 0.75,-0.05,-0.08,
						-0.02,0.87,-0.03,
						-0.06,-0.03,0.83 };

	double B[m] = { -0.41,0.73,-0.24 };


	double X[m];
	double Xlast[m];
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		Xlast[i] = B[i];		/
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
			Xlast[i] = X[i];
			X[i] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << "x" << i + 1 << "= " << Xlast[i] << endl;
	}

	system("pause");
	return 0;

}