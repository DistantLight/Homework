#include <string>
#include <iostream>
using namespace std;

class ListElem
{

public:
	static int count;					//счетчик объектов
	ListElem* next;
	int value;

	ListElem()							//конструктор элемов
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
	ListElem* head;				//уазатель на первый об
	ListElem* var;				//указатель на текущий объект listReal

	List()
	{
		this->head = 0;
		this->var = 0;
	}

	void add(int value)
	{
		if (ListElem::count == 0)					//для первого элема
		{
			ListElem* lr = new ListElem();
			this->head = lr;
			this->var = lr;
			lr->value = value;
			cout << this->var->value << endl;			//для проверки
		}
		else {
			ListElem* lr = new ListElem();
			lr->value = value;
			this->var->next = lr;					//this   предыдущему об даем ссылку на текущий
			this->var = lr;							//присваиваем вару ссылку на текущий объект
			cout << this->var->value << endl;		//для проверки
			//cout << this->var->next << endl;
		}
	}

	int getValueFirst()					//получить значение первого элемента
	{
		return this->head->value;

	}

	void deleteElem()
	{
		ListElem* var1 = this->head;				//var1 промежуточная переменная для удаления первого элемента из памяти 

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

	cout << "Кол-во -  " << ListElem::count << endl;

	cout << "значения элема 1 " << endl;
	cout << list.getValueFirst() << endl;


	cout << "значение 1 элема после удаления" << endl;
	list.deleteElem();
	cout << list.getValueFirst() << endl;
	

	cout << "количество элемов после удаления: " << ListElem::count;


	return 0;
}