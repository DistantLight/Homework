#include <iostream>
using namespace std;

void func1(int x) {			//������� �������� �� �������
	x = x * 2;
}

void func2(int* px) {		//������� �������� �� ���������
	*px = *px * 2;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int a = 5;
	func1(a);
	cout << a << endl;

	func2(&a);
	cout << a << endl;

	return 0;
}