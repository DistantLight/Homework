
#include "iostream";
using namespace std;

int main() {

    setlocale(LC_ALL, "Rus");

    int* a = new int(2);
    cout << "����� � : " << a << " �������� : " << *a << "\n";

    delete a;

    cout << "����� � ����� �������� : " << a << "\n";

    a = new int(5);
    cout << "����� � : " << a << " �������� : " << *a << "\n";

    int* b = a;

    delete a;
    cout << "����� b : " << b << " �������� : " << *b << "\n";

    delete b;
}