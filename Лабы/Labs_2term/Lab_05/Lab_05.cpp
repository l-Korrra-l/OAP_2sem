///*4.  В соответствии со своим вариантом разработать программу с использованием односвязного списка по данным, представ-ленным
//в таблице ниже. 
//Программа должна содержать меню с пунктами: добавление элемента, удаление элемента, поиск элемента, вывод списка в консольное
//окно, запись списка в файл, считывание списка из файла. 
//
//4.Создать список, содержащий символы.Найти символ, равный введенному с клавиатуры, вывести его и следующий за ним символ.
//11.Создать список, содержащий символы. Найти символ, равный введенному с клавиатуры, вывести этот символ и предыдущий.*/
//#include <iostream>
//#include <fstream>
//using namespace std;
//struct list
//{
//	char symbol;
//	list* next;
//};
//
//void insert(list*& p, char value); //Добавление символа в начало списка
//void printList(list* p);       //Вывод списка 
//char del(list*& p, char value);  //удаление элемента
//list* find(list*& p, char value);  //поиск-----------------------------------------------
//list* findpr(list*& p, char value);
//void toFile(list*& p);         //Запись в файл
//void fromFile(list*& p);       //Считывание из файла
//void menu(void);               //Вывод меню 
//int IsEmpty(list*);
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	list* first = nullptr;
//	int choice; char value;
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
//			del(first,value); break;
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
//				 break;
//		case 4: cout << "Введите символ ";
//			cin >> value;
//			list* t;
//			if (!IsEmpty(first))
//			{
//				t = findpr(first, value);
//
//				if (t != 0)
//				{
//				cout <<  t->symbol;
//				if (t != 0)
//				{
//					t = find(first, value);
//					cout << "-->" << t->symbol << endl;
//				}
//				}
//				else  cout << "Няма" << endl;
//			}
//			else cout << "Список пуст" << endl;
//			break;
//		case 5: if (!IsEmpty(first)) printList(first); 
//			else cout << "Список пуст" << endl; break;
//		case 6:    toFile(first);
//			break;
//		case 7:    fromFile(first);
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
//void insert(list*& p, char value) //Добавление символа в начало списка
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
//char del(list*& p, char value)  // Удаление числа 
//{
//	list* temp;
//
//		p = find(p,value);
//		temp = p;
//		p = p->next;    // отсоединить узел 
//		delete temp;      //освободить отсоединенный узел 
//		return value;
//}
//
//list* find(list*& p, char value)
//{
//	list* previous, * current, * temp=0;
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
//list* findpr(list*& p, char value)
//{
//	list* previous, * current, * temp = 0;
//	if (value == p->next->symbol)
//	{
//		previous = p;
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
//	return previous;
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
//	cout << " 4 - Поиск символа+предыдущий" << endl;
//	cout << " 5 - Печать списка" << endl;
//	cout << " 6 - Запись списка в файл" << endl;
//	cout << " 7 - Чтение списка из файла" << endl;
//	cout << " 0 - Выход" << endl;
//}
//
