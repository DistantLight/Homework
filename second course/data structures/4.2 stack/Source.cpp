#include <string>
#include <iostream>
using namespace std;

class ListElem
{

public:
	static int count;					//������� ��������
	ListElem* next;
	int value;

	ListElem()							//����������� ������
	{
		count++;
		value = 0;
		next = 0;
	}

};

int ListElem::count = 0;



class List
{
public:
	ListElem* head;				//�������� �� ��������� ������ ����� listElem

	List()
	{
		this->head = 0;
	}

	void add(int value)
	{
		if (ListElem::count == 0)					//��� ������� �����
		{
			ListElem* lr = new ListElem();
			this->head = lr;
			lr->value = value;
			cout << this->head->value << endl;			//��� ��������
		}
		else {
			ListElem* lr = new ListElem();
			lr->value = value;
			lr->next = this->head;					//   ������������ �� ���� ������ �� ���������
			this->head = lr;						//����������� head ������ �� ������� ������
			cout << this->head->value << endl;		//��� ��������
			//cout << this->var->next << endl;
		}
	}


	int getValue()					//�������� �������� �������� �� �������
	{
		return this->head->value;

	}


	void deleteElem()
	{
		ListElem* var1 = this->head;				//var1 ������������� ���������� ��� �������� ������� �������� �� ������ 

		this->head = head->next;					//����������� head ������ �� ���������� ����������� ������
		delete var1;

		ListElem::count--;

	}


};




int main()
{
	setlocale(LC_ALL, "Rus");


	List list;
	list.add(3);
	cout << list.head << endl;
	list.add(111);
	cout << list.head << endl;
	list.add(21);
	cout << list.head << endl;
	list.add(5);
	cout << list.head << endl;


	cout << "���� �� �������" << endl;
	cout << list.getValue() << endl;

	cout << "���� ����� ��������" << endl;
	list.deleteElem();
	cout << list.getValue() << endl;

	cout << "���������� ������ ����� ��������: " << ListElem::count;


	return 0;
}