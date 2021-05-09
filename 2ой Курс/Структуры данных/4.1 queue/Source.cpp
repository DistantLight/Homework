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
	ListElem* head;				//�������� �� ������ ��
	ListElem* var;				//��������� �� ������� ������ listReal

	List()
	{
		this->head = 0;
		this->var = 0;
	}

	void add(int value)
	{
		if (ListElem::count == 0)					//��� ������� �����
		{
			ListElem* lr = new ListElem();
			this->head = lr;
			this->var = lr;
			lr->value = value;
			cout << this->var->value << endl;			//��� ��������
		}
		else {
			ListElem* lr = new ListElem();
			lr->value = value;
			this->var->next = lr;					//this   ����������� �� ���� ������ �� �������
			this->var = lr;							//����������� ���� ������ �� ������� ������
			cout << this->var->value << endl;		//��� ��������
			//cout << this->var->next << endl;
		}
	}

	int getValueFirst()					//�������� �������� ������� ��������
	{
		return this->head->value;

	}

	void deleteElem()
	{
		ListElem* var1 = this->head;				//var1 ������������� ���������� ��� �������� ������� �������� �� ������ 

		this->head = head->next;
		delete var1;
		ListElem::count--;

	}



};




int main()
{
	setlocale(LC_ALL, "Rus");


	List list;
	list.add(7);
	cout << list.var << endl;
	list.add(111);
	cout << list.var << endl;
	list.add(21);
	cout << list.var << endl;
	list.add(5);
	cout << list.var << endl;

	cout << "���-�� -  " << ListElem::count << endl;

	cout << "�������� ����� 1 " << endl;
	cout << list.getValueFirst() << endl;


	cout << "�������� 1 ����� ����� ��������" << endl;
	list.deleteElem();
	cout << list.getValueFirst() << endl;
	

	cout << "���������� ������ ����� ��������: " << ListElem::count;


	return 0;
}