
#include "iostream";
using namespace std;

int main() {

    setlocale(LC_ALL, "Rus");

    int* a = new int(2);
    cout << "адрес а : " << a << " значение : " << *a << "\n";

    delete a;

    cout << "адрес а после удаления : " << a << "\n";

    a = new int(5);
    cout << "адрес а : " << a << " значение : " << *a << "\n";

    int* b = a;

    delete a;
    cout << "адрес b : " << b << " значение : " << *b << "\n";

    delete b;
}