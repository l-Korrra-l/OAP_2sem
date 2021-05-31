/*3. N человек  располагаются  по кругу.Начав отсчет от первого, удаляют каждого k - го, смыкая круг после удаления.Определить
порядок удаления людей из круга.Использовать линейный список.*/
#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	Address* next;
	Address* prev;
};

//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << endl;
		t = t->next;
	}
	cout << "" << endl;
}

//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени 
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}


//----------------------------------------------------------------
int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	Address* a = head;
	Address* t = head;
	int N,k;
	setlocale(LC_CTYPE, "Rus");
	cout << "Введите количество человек: "; cin >> N;
	setElement();
	for (int i = 0; i < N; i++)
	{
		insert(setElement(), &head, &last);
	}
	cout << "Введите k: "; cin >> k;
	for (int i = 0; i < N; i++)
	{
			cout << "Список: " << endl;;
	        outputList(&head, &last);
			for (int j = 0; j < k; j++)
			{
				if (t == last) t = head;
				else   t = t->next;
			}
			delet(t->name, &head, &last);
	}
	return 0;
}