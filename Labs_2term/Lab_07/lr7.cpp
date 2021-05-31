#include<iostream> 
using namespace std;

void add();
void add_element();
void show_all();
void delete_element();
void determine_size();
void delete_and_showsize();
void max_element();
void menu();

int max_size, current_size;

struct queue
{
    int value;
    queue* next;
};

queue* bottom = nullptr;
queue* top = new queue;
queue* current = new queue;
queue* buffer = new queue;
queue* previouse = new queue;

void add(int size)
{
	int i;
	for (int m = 0; m < size; m++)
	{
		cout << "Введите число типа int: "; cin >> i; cout << endl;
		if (!i)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			break;
		}

		queue* current = new queue;
		current->next = NULL;

		if (bottom == NULL)
		{
			top = bottom = current;
		}
		if (bottom != NULL)
		{
			current->value = i;
			top->next = current;
			top = current;
		}
		::current_size = m + 1;
	}
	menu();
}

void add_element()
{
	int i;	
	for (;;)
	{
		cout << "Введите число типа int: "; cin >> i; cout << endl;
		if (!i || current_size >= max_size)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			cout << "Очередь переполнена!" << endl;
			break;
		}
		queue* current = new queue;
		current->next = NULL;


		current->value = i;
		top->next = current;
		top = current;
		current_size++;
	}
	menu();
}

void show_all()
{
	current = bottom;
	while (current)
	{
		cout << current->value << "  ";
		current = current->next;
	}
	menu();
}

void delete_element()
{
	int element;
	cout << "Введите элемент который нужно удалить: "; cin >> element; 
	current = bottom;
	while (current)
	{
		if (current->value == element)
		{
			if (bottom == current)
			{
				buffer = bottom;
				current = current->next;
				bottom = current;
				delete buffer;	
				::current_size--;
				break;
			}
			
			if (bottom != current)
			{
				previouse->next = current->next;
				delete current;
				::current_size--;
				break;
			}
		}
		
			previouse = current;
			current = current->next;
		
	}
	menu();
}

void determine_size()
{
	cout << "Размер очереди: " << ::current_size << endl;
	menu();
}

void delete_and_showsize()
{
	int element;
	cout << "Введите элемент который нужно удалить: "; cin >> element;
	current = bottom;
	while (current)
	{
		if (current->value == element)
		{
			if (bottom == current)
			{
				buffer = bottom;
				current = current->next;
				bottom = current;
				delete buffer;
				::current_size--;
				break;
			}

			if (bottom != current)
			{
				previouse->next = current->next;
				delete current;
				::current_size--;
				break;
			}
		}

		previouse = current;
		current = current->next;

	}

	determine_size();
}

void max_element()
{
	int max_el = 0;
	current = bottom;
	while (current)
	{
		if (max_el < current->value) max_el = current->value;
		current = current->next;
	}
	cout << "Максимальный элемент очереди: " << max_el << endl;
	menu();
}

void menu()
{
	setlocale(LC_ALL, "rus");
	int ch;
	cout << endl << "Создать очередь - 1" << endl << "Добавить элемент в очередь - 2" << endl << "Показать содержимое очереди - 3 " << endl << "Удалить элемент очереди - 4 " << endl << "определить размер очереди - 5" << endl << "Удалить элемент и вывести оставшийся размер - 6" << endl << "Найти максиальный элемент очереди - 7 " <<  endl;
	cout << "Введите номер действия: "; cin >> ch; cout << endl;
	switch (ch)
	{
	case 1: 
	{
	cout << "Введите размер максимальный очереди: "; cin >> ::max_size;
		add(::max_size);
	}
	case 2: add_element();
	case 3: show_all();	
	case 4: delete_element();
	case 5: determine_size();
	case 6: delete_and_showsize();
	case 7: max_element();
	case 0: exit(1);
	}
}

int main()
{	
	setlocale(LC_ALL, "rus");
	menu();	
    return 0;
}
