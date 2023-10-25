#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

void array_check(double** arr, int m, int n)
{
	if (m != n - 1)
	{
		cout << "ошибка ввода" << endl;
	}

	string check = "double";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (typeid(arr[i][j]).name() != check)
			{
				cout << "ошибка ввода" << endl;
			}
		}
	}
}

void fill_array(double** arr, int m, int n)
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

void show_array(double** arr, int m, int n)
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

void method_Gaussa(double** arr, int m, int n)
{
	double temp1;
	double temp2;
	int k = 0;

	for (int i = 0; i < m; i++) {
		temp1 = arr[k][k];

		for (int j = 0; j < n; j++) {
			arr[i][j] /= temp1;
		}

		//show_array(arr);


		for (int a = i + 1; a < m; a++) {
			temp2 = arr[a][i];

			for (int b = 0; b < n; b++) {
				arr[a][b] = arr[a][b] - arr[i][b] * temp2;
			}

		}
		k++;
		//show_array(arr);
	}


	double* results = new double[m];
	for (int i = 0; i < m; i++)
	{
		results[i] = 0;
	}
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (j == m)
			{
				//присваиваем заначение результата элементу из b
				results[i] = arr[i][j];
				continue;
			}
			if (i == j)
			{
				//пропуск эл-ов на главной диагонали
				continue;
			}
			results[i] = results[i] - arr[i][j] * results[j];
		}
		cout << "x" << i+1 <<"= " << results[i] << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "Rus");


	int m;
	cout << "Введите количество строк";
	cin >> m;

	int n;
	cout << "Введите количество столбцов";
	cin >> n;

	double** arr = new double* [m];
	for (int i = 0; i < n; i++) {
		arr[i] = new double[n];
	}

	fill_array(arr, m, n);
	show_array(arr, m, n);
	array_check(arr, m, n);
	method_Gaussa(arr, m, n);

	system("pause");
	return 0;

}