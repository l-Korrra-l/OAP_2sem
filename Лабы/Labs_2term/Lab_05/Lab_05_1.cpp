///*1	������� ������, ���������� �������� ������ ����.����� ����� ������������� ��������� ��� ������ ���������, ��� ������������� ��������� ���.
//3	������� ������, ���������� �������� ������ ����.����� ����� ������������� ���������, ������� 5, ��� ������ ���������, ��� ����� ��������� ���.*/
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
//void insert(list*& p, int value); //���������� ������� � ������ ������
//void printList(list* p);       //����� ������ 
//int del(list*& p, int value);  //�������� ��������
//list* find(list*& p, int value);  //�����
//int sum(list*& p);
//int sum1(list*& p);
//void toFile(list*& p);         //������ � ����
//void fromFile(list*& p);       //���������� �� �����
//void menu(void);               //����� ���� 
//int IsEmpty(list*);
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	list* first = nullptr;
//	int choice; int value;
//	menu();    // ������� ���� 
//	cout << " ? ";
//	cin >> choice;
//	while (choice != 0)
//	{
//		switch (choice)
//		{
//		case 1:  	cout << "������� ������ ";
//			cin >> value;
//			insert(first, value);
//			printList(first);
//			break;
//		case 2: cout << "������� ������ ";
//			cin >> value;
//			del(first, value); break;
//		case 3: cout << "������� ������ ";
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
//				else  cout << "����" << endl;
//			}
//			else cout << "������ ����" << endl;
//			break;
//		case 4: cout << "������� ������ ";
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
//				else  cout << "����" << endl;
//			}
//			else cout << "������ ����" << endl;
//			break;
//		case 5: cout << "������� ������ ";
//			cin >> value;
//			if (!IsEmpty(first))
//			{
//				t = sum(first);
//
//				if (t != 0)
//				{
//					cout << "sum = " << t << endl;
//				}
//				else  cout << "����" << endl;
//			}
//			else cout << "������ ����" << endl;
//			break;
//		case 6: if (!IsEmpty(first)) printList(first);
//			  else cout << "������ ����" << endl; break;
//		case 7:    toFile(first);
//			break;
//		case 8:    fromFile(first);
//			break;
//		default:   cout << "������������ �����" << endl;
//			menu(); break;
//		}
//		cout << "?  ";
//		cin >> choice;
//	}
//	return 0;
//}
//
//void insert(list*& p, int value) //���������� ������� � ������ ������
//{
//	list* newP = new list;
//	if (newP != NULL)     //���� �� �����?  
//	{
//		newP->symbol = value;
//		newP->next = p;
//		p = newP;
//	}
//	else
//		cout << "�������� ���������� �� ���������" << endl;
//}
//
//int del(list*& p, int value)  // �������� ����� 
//{
//	list* temp;
//
//	p = find(p, value);
//	temp = p;
//	p = p->next;    // ����������� ���� 
//	delete temp;      //���������� ������������� ���� 
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
//			current = current->next; // ������� � ���������� 
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
//void printList(list* p)  //����� ������ 
//{
//	if (p == NULL)
//		cout << "������ ����" << endl;
//	else
//	{
//		cout << "������:" << endl;
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
//		cout << "\n ������ �������� �����";
//		exit(1);
//	}
//	while (temp)
//	{
//		buf = *temp;
//		frm.write((char*)&buf, sizeof(list));
//		temp = temp->next;
//	}
//	frm.close();
//	cout << "������ ������� � ���� mList.dat\n";
//}
//
//void fromFile(list*& p)          //���������� �� �����
//{
//	list buf, * first = nullptr;
//	ifstream frm("mList.dat");
//	if (frm.fail())
//	{
//		cout << "\n ������ �������� �����";
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
//	cout << "\n������ ������ �� ����� mList.dat\n";
//}
//
//int IsEmpty(list* p)
//{
//	return p == NULL;
//}
//
//
//void menu(void)     //����� ���� 
//{
//	cout << "�������� �����:" << endl;
//	cout << " 1 - ���� �������" << endl;
//	cout << " 2 - �������� �������" << endl;
//	cout << " 3 - ����� �������+��������� �� ���" << endl;
//	cout << " 4 - ����� ������������� ���������" << endl;
//	cout << " 5 - ����� ������������� ���������, ������� 5" << endl;
//	cout << " 6 - ������ ������" << endl;
//	cout << " 7 - ������ ������ � ����" << endl;
//	cout << " 8 - ������ ������ �� �����" << endl;
//	cout << " 0 - �����" << endl;
//}
//
