#include <iostream>
using namespace std;

void func1(int x) {			//передаём аргумент по значеню
	x = x * 2;
}

void func2(int* px) {		//передаём аргумент по указателю
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