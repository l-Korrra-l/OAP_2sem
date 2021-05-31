//5.  В проект добавить следующие функции : удаление минимального extractMin; удаление i - ого элемента extractI; 
//объединение unionHeap двух куч в одну.



#include "Heap.h"
#include <iostream>
#include <ctime>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//------------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice,min,l,n;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	heap::Heap h3 = heap::create(30, cmpAAA);
	heap::Heap h4 = heap::create(30, cmpAAA);
	heap::Heap h5 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - удалить минимальный элемент" << endl;
		cout << "5 - удалить i-тый элемент" << endl;
		cout << "6 - объединение двух куч" << endl;
		cout << "7 - вывод 2 кучи" << endl;
		cout << "-----dop--------" << endl;
		cout << "8 - обратный приоритет" << endl;
		cout << "9 - вывод 3 кучи" << endl;
		cout << "10 - автозаполнение трех куч" << endl;
		cout << "11 - объединение трех куч" << endl;
		cout << "12 - объединение трех куч в обратном порядке" << endl;
		cout << "13 - сумма всех элементов кучи" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  min=h1.scan(0);
			break;
		case 2: {	AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax();
			break;
		case 4:   h1.extractMin(min);
			break;
		case 5: cout << "введите номер элемента" << endl; 	cin >> k;  h1.extractI(k);
			break;
		case 6: cout << "введите количество элементов второй кучи" << endl; cin >> k;
			for (int i = 0; i < k; i++)
			{
				AAA* a = new AAA;
				cout << "введите ключ" << endl; 	cin >> l;
				a->x = l;
				h2.insert(a);
			}
			cout << "вторая куча" << endl;
			h2.scan(0);
			h1.unionHeap(&h2);
			break;
		case 7:  h2.scan(0);
			break;
		case 8: {	
			for (int i = 0; i < 6; i++)
			{
				AAA* a = new AAA;
				cout << "введите ключ" << endl; 	cin >> k;
				a->x = k;
				h3.insertr(a);
			}
			h3.scan(0);
		}break;
		case 9:  h3.scan(0);
			break;
		case 10: 
		{cout << "Введите количество элементов для куч: "; cin >> n;
		for (int i = 0; i < n; i++)
		{	
			AAA* a = new AAA;
		    AAA* b = new AAA;
		    AAA* c = new AAA;
			srand(time(NULL));
			a->x = rand() % 100 - i*2;
			h1.insertr(a);
			b->x = rand() % 10 - i*3;
			h2.insertr(b);
			c->x = rand() % 50 - i*5;
			h3.insertr(c);
		}break; }
		case 11: h3.unionHeap(&h4); h2.unionHeap(&h4); h1.unionHeap(&h4); h4.scan(0); break;
		case 12:  h3.unionHeapr(&h5); h2.unionHeapr(&h5); h1.unionHeapr(&h5); h5.scan(0); break;
		case 13: cout << h1.sum() << endl; break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
