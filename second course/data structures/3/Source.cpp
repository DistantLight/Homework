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

	int getValue(int number)					//получить значение по индексу
	{

		ListElem* var1 = this->head;				//var1 промежуточная переменная
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

		ListElem* var1 = this->head;				//var1 промежуточная переменная для предыдущего относительно удаляемого об
		ListElem* var2 = this->head;				//var2 промежуточная переменная для следующего относительно удаляемого об

		if (number == 1)							//если нужно удалить первый элем
		{
			this->head = head->next;
		}

		for (int i = 0; i < number; i++)		//кроме 1		цикл до следующ элема
		{
			var2 = var2->next;						//перебираем элементы по переменной var2
			if (i == number - 3)					//находим предыдущий элем
			{
				var1 = var2;
			}
		}
		delete var1->next;							//удаляем из памяти нужный элемент
		var1->next = var2;							//предыдущему элему даем ссылку на следующий
		ListElem::count--;							//отнимаем еденицу из счетчика элементов
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

	cout << "значения элемов 1 и 3" << endl;
	cout << list.getValue(1) << endl;
	cout << list.getValue(3) << endl;


	cout << "элемы после удаления" << endl;
	list.deleteElem(2);
	cout << list.getValue(1) << endl;
	cout << list.getValue(2) << endl;
	cout << list.getValue(3) << endl;

	cout << "количество элемов после удаления: " << ListElem::count;


	return 0;
}