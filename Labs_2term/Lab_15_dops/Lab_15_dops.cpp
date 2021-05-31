//12	Реализовать динамическую хеш - таблицу с открытой адресацией для хранения строк.Таблица должна увеличивать свой размер вдвое 
//при достижении 50 % заполнения.

#include "Hash.h"

#include <iostream>

using namespace std;

struct AAA 
{

	int key; 

	char* mas; 

	AAA(int k, char* z)
	{

		key = k;

		mas = z;

	}

	AAA() {} 

};

int key(void* d) 

{

	AAA* f = (AAA*)d; 

	return f->key;
}

void AAA_print(void* d) 

{

	cout << "Ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;

}

int main()

{

	system("chcp 1251");

	setlocale(LC_ALL, "rus");

	int siz;

	AAA* a;

	char* str;

	cout << "Введите размер хэш-таблицы" << endl;

	cin >> siz;

	Object H = Create(siz, key);

	int choise; 

	int k;

	for (;;)

	{

		system("cls");

		cout << "Меню:" << endl;

		cout << "1 - вывод хэш-таблицы" << endl;

		cout << "2 - добавление элемента" << endl;

		cout << "3 - удаление элемента" << endl;

		cout << "4 - поиск элемента" << endl;

		cout << "0 - выход" << endl;

		cout << "сделайте выбор" << endl; cin >> choise;

		switch (choise)

		{

		case 0: exit(0); 

		case 1: H.Scan(AAA_print); break;

		case 2:

			a = new AAA(); 
			cout << "Введите ключ" << endl;

			cin >> k;

			a->key = k;

			str = new char[20];

			cout << "Введите строку" << endl;

			cin >> str;

			a->mas = str;

			if (H.N >= H.Size / 7)

				H.Size *= 3;

			 H.Insert(a);

			break;

		case 3:

			cout << "Введите ключ для удаления " << endl;

			cin >> k;

			H.Delete(k);

			break;

		case 4:

			cout << "Введите ключ для поиска " << endl;

			cin >> k;

			if (H.Search(k) == NULL)

				cout << "Элемент не найден" << endl;

			else AAA_print(H.Search(k));

			break;



		}

		system("pause");

	}

}