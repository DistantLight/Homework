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
	ListElem* head;				//уазатель на последний объект класс listElem

	List()
	{
		this->head = 0;
	}

	void add(int value)
	{
		if (ListElem::count == 0)					//для первого элема
		{
			ListElem* lr = new ListElem();
			this->head = lr;
			lr->value = value;
			cout << this->head->value << endl;			//для проверки
		}
		else {
			ListElem* lr = new ListElem();
			lr->value = value;
			lr->next = this->head;					//   добавляемому об даем ссылку на последний
			this->head = lr;						//присваиваем head ссылку на текущий объект
			cout << this->head->value << endl;		//для проверки
			//cout << this->var->next << endl;
		}
	}


	int getValue()					//получить значение элемента на вершине
	{
		return this->head->value;

	}


	void deleteElem()
	{
		ListElem* var1 = this->head;				//var1 промежуточная переменная для удаления первого элемента из памяти 

		this->head = head->next;					//присваеваем head ссылку на предыдущий добавленный объект
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


	cout << "элем на вершине" << endl;
	cout << list.getValue() << endl;

	cout << "элем после удаления" << endl;
	list.deleteElem();
	cout << list.getValue() << endl;

	cout << "количество элемов после удаления: " << ListElem::count;


	return 0;
}