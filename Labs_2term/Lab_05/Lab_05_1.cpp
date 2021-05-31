///*1	Создать список, содержащий элементы целого типа.Найти сумму положительных элементов или выдать сообщение, что положительных элементов нет.
//3	Создать список, содержащий элементы целого типа.Найти сумму положительных элементов, кратных 5, или выдать сообщение, что таких элементов нет.*/
//
//
//#include <iostream>
//#include <fstream>
//using namespace std;
//struct list
//{
//	int symbol;
//	list* next;
//};
//
//void insert(list*& p, int value); //Добавление символа в начало списка
//void printList(list* p);       //Вывод списка 
//int del(list*& p, int value);  //удаление элемента
//list* find(list*& p, int value);  //поиск
//int sum(list*& p);
//int sum1(list*& p);
//void toFile(list*& p);         //Запись в файл
//void fromFile(list*& p);       //Считывание из файла
//void menu(void);               //Вывод меню 
//int IsEmpty(list*);
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	list* first = nullptr;
//	int choice; int value;
//	menu();    // вывести меню 
//	cout << " ? ";
//	cin >> choice;
//	while (choice != 0)
//	{
//		switch (choice)
//		{
//		case 1:  	cout << "Введите символ ";
//			cin >> value;
//			insert(first, value);
//			printList(first);
//			break;
//		case 2: cout << "Введите символ ";
//			cin >> value;
//			del(first, value); break;
//		case 3: cout << "Введите символ ";
//			cin >> value;
//			list* p;
//			if (!IsEmpty(first))
//			{
//				p = find(first, value);
//				if (p != 0)
//				{
//					cout << "-->" << p->symbol;
//					p = p->next;
//					if (p != NULL)
//						cout << "-->" << p->symbol << endl;
//					else cout << "-->NULL" << endl;
//				}
//				else  cout << "Няма" << endl;
//			}
//			else cout << "Список пуст" << endl;
//			break;
//		case 4: cout << "Введите символ ";
//			cin >> value;
//			int t;
//			if (!IsEmpty(first))
//			{
//				t = sum(first);
//
//				if (t != 0)
//				{
//					cout << "sum = " <<t<< endl;
//				}
//				else  cout << "Няма" << endl;
//			}
//			else cout << "Список пуст" << endl;
//			break;
//		case 5: cout << "Введите символ ";
//			cin >> value;
//			if (!IsEmpty(first))
//			{
//				t = sum(first);
//
//				if (t != 0)
//				{
//					cout << "sum = " << t << endl;
//				}
//				else  cout << "Няма" << endl;
//			}
//			else cout << "Список пуст" << endl;
//			break;
//		case 6: if (!IsEmpty(first)) printList(first);
//			  else cout << "Список пуст" << endl; break;
//		case 7:    toFile(first);
//			break;
//		case 8:    fromFile(first);
//			break;
//		default:   cout << "Неправильный выбор" << endl;
//			menu(); break;
//		}
//		cout << "?  ";
//		cin >> choice;
//	}
//	return 0;
//}
//
//void insert(list*& p, int value) //Добавление символа в начало списка
//{
//	list* newP = new list;
//	if (newP != NULL)     //есть ли место?  
//	{
//		newP->symbol = value;
//		newP->next = p;
//		p = newP;
//	}
//	else
//		cout << "Операция добавления не выполнена" << endl;
//}
//
//int del(list*& p, int value)  // Удаление числа 
//{
//	list* temp;
//
//	p = find(p, value);
//	temp = p;
//	p = p->next;    // отсоединить узел 
//	delete temp;      //освободить отсоединенный узел 
//	return value;
//}
//
//list* find(list*& p, int value)
//{
//	list* previous, * current, * temp = 0;
//	if (value == p->symbol)
//	{
//		temp = p;
//	}
//	else
//	{
//		previous = p;
//		current = p->next;
//		while (current != NULL && current->symbol != value)
//		{
//			previous = current;
//			current = current->next; // перейти к следующему 
//		}
//		if (current != NULL)
//		{
//			temp = current;
//		}
//	}
//	return temp;
//}
//
//int sum(list*& p)
//{
//	int sum = 0;
//	while (p != NULL)
//	{
//		if (p->symbol > 0) sum += p->symbol;
//		p = p->next;
//	}
//	return sum;
//}
//
//int sum1(list*& p)
//{
//	int sum = 0;
//	int temp;
//	while (p != NULL)
//	{
//		temp = p->symbol % 5;
//		if ((p->symbol > 0)&&( temp  = 0)) sum += p->symbol;
//		p = p->next;
//	}
//	return sum;
//}
//
//void printList(list* p)  //Вывод списка 
//{
//	if (p == NULL)
//		cout << "Список пуст" << endl;
//	else
//	{
//		cout << "Список:" << endl;
//		while (p != NULL)
//		{
//			cout << "-->" << p->symbol;
//			p = p->next;
//		}
//		cout << "-->NULL" << endl;
//	}
//}
//
//void toFile(list*& p)
//{
//	list* temp = p;
//	list buf;
//	ofstream frm("mList.dat");
//	if (frm.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (temp)
//	{
//		buf = *temp;
//		frm.write((char*)&buf, sizeof(list));
//		temp = temp->next;
//	}
//	frm.close();
//	cout << "Список записан в файл mList.dat\n";
//}
//
//void fromFile(list*& p)          //Считывание из файла
//{
//	list buf, * first = nullptr;
//	ifstream frm("mList.dat");
//	if (frm.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	frm.read((char*)&buf, sizeof(list));
//	while (!frm.eof())
//	{
//		insert(first, buf.symbol);
//		cout << "-->" << buf.symbol;
//		frm.read((char*)&buf, sizeof(list));
//	}
//	cout << "-->NULL" << endl;
//	frm.close();
//	p = first;
//	cout << "\nСписок считан из файла mList.dat\n";
//}
//
//int IsEmpty(list* p)
//{
//	return p == NULL;
//}
//
//
//void menu(void)     //Вывод меню 
//{
//	cout << "Сделайте выбор:" << endl;
//	cout << " 1 - Ввод символа" << endl;
//	cout << " 2 - Удаление символа" << endl;
//	cout << " 3 - Поиск символа+следующий за ним" << endl;
//	cout << " 4 - Сумма положительных элементов" << endl;
//	cout << " 5 - Сумма положительных элементов, кратных 5" << endl;
//	cout << " 6 - Печать списка" << endl;
//	cout << " 7 - Запись списка в файл" << endl;
//	cout << " 8 - Чтение списка из файла" << endl;
//	cout << " 0 - Выход" << endl;
//}
//
