#include "Hash.h"
#include <iostream>
using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;   return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	char a[] = "one", b[]="two", c[]="three", d[]="fo";
	AAA a1(1, a), a2(2, b), a3(4, c), a4(2, d);
	int siz = 10, choice, k;
	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
	Object H = create(siz, key);
	Object H1 = create(siz, key);
	for (;;)
	{
		cout << "---------------Модульная хеш-функция---------------------- " << endl;
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: { AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;	cin >> k;
			a->key = k;
			cout << "введите строку" << endl; cin >> str;
			a->mas = str;
			if (H.N >= H.size /7)
				H.size *= 3;
				H.insert(a);
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));
		}  break;
		case 11: H1.scan(AAA_print);  break;
		case 12: { AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;	cin >> k;
			a->key = k;
			cout << "введите строку" << endl; cin >> str;
			a->mas = str;
			if (H1.N == H1.size)
				cout << "Таблица заполнена" << endl;
			else
				H1.insertmult(a);
		} break;
		case 13: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H1.deleteByKeymult(k);
		}  break;
		case 14: {  cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H1.searchmult(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H1.searchmult(k));
		}  break;
		}
	}
	return 0;
}
