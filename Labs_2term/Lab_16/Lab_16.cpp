#include "Hash_ Twin_Chain.h"
#include <iostream>
#include <stddef.h>
using namespace std;

struct AAA
{
	int key;
	char* mas;
	char a[1] = "";
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = a;
	}
};
//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}

//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Ведите размер хэш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хэш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //выход
			exit(0);
		case 2: //добавление элемента
		{
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;
			cin >> k;
			a->key = k;
			cout << "введите строку" << endl;
			cin >> str;
			a->mas = str;
			H.insert(a);
		}
		break;
		case 1:
			H.Scan();
			break;
		case 3: //удаление элемента
		{
			AAA* b = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
		break;
		case 4: //поиск элемента
			AAA * c = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else {
				cout << "Первый элемент с данным клю-чом" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
