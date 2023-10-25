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

double find_det(double(&A)[m][m])
{
	double arr[m][m];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = A[i][j];
		}
	}

	double temp;

	double det = 1;

	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			temp = arr[j][i];

			for (int b = 0; b < m; b++)
			{
				if (arr[i][i] != 0)
				{
					arr[j][b] = arr[j][b] - arr[i][b] * temp / arr[i][i];
				}
			}
			show_array(arr);

		}
	}

	for (int i = 0; i < m; i++)
	{
		if (arr[i][i] != 0)
		{
			det *= arr[i][i];
		}
	}
	return det;
}


int main()
{
	setlocale(LC_ALL, "Rus");


	double A[m][m] = { 1,3,5,7,
						  3,5,7,1,
						  5,7,1,3,
						  7,1,3,5 };
	double B[m] = { 12, 0, 4, 16 };
	show_array(A);


	double main_det;
	main_det = find_det(A);

	double X[m];
	double tempArr[m];   //столбец A


	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < m; i++)
		{
			tempArr[i] = A[i][j];
			A[i][j] = B[i];
			if (i == m - 1)
			{
				X[j] = abs(find_det(A)) / main_det;

				for (int k = 0; k < m; k++)
				{
					A[k][j] = tempArr[k];
				}

				cout << "x" << j + 1 << "=" << X[j] << endl;
			}
		}
	}

	system("pause");
	return 0;

}