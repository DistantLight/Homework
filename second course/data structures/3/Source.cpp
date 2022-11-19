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

	int getValue(int number)					//�������� �������� �� �������
	{

		ListElem* var1 = this->head;				//var1 ������������� ����������
		if (number == 1)
		{
			return var1->value;
		}
		for (int i = 0; i < number - 1; i++)
		{
			var1 = var1->next;
		}
		return var1->value;
	}

	void deleteElem(int number)
	{

		ListElem* var1 = this->head;				//var1 ������������� ���������� ��� ����������� ������������ ���������� ��
		ListElem* var2 = this->head;				//var2 ������������� ���������� ��� ���������� ������������ ���������� ��

		if (number == 1)							//���� ����� ������� ������ ����
		{
			this->head = head->next;
		}

		for (int i = 0; i < number; i++)		//����� 1		���� �� ������� �����
		{
			var2 = var2->next;						//���������� �������� �� ���������� var2
			if (i == number - 3)					//������� ���������� ����
			{
				var1 = var2;
			}
		}
		delete var1->next;							//������� �� ������ ������ �������
		var1->next = var2;							//����������� ����� ���� ������ �� ���������
		ListElem::count--;							//�������� ������� �� �������� ���������
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

	cout << "�������� ������ 1 � 3" << endl;
	cout << list.getValue(1) << endl;
	cout << list.getValue(3) << endl;


	cout << "����� ����� ��������" << endl;
	list.deleteElem(2);
	cout << list.getValue(1) << endl;
	cout << list.getValue(2) << endl;
	cout << list.getValue(3) << endl;

	cout << "���������� ������ ����� ��������: " << ListElem::count;


	return 0;
}