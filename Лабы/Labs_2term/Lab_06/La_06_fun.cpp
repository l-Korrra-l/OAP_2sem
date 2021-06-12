#include "Lab_06.h"

void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
}

int pop(Stack* myStk)   
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               
	}
	else
	{
		Stack* e = myStk->head;   
		int a = myStk->head->data;   
		myStk->head = myStk->head->next; 
		delete e;                        
		return a;                        
	}
}

void show(Stack* myStk)    
{
	Stack* e = myStk->head;   
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void toFile(Stack*& myStk)
{
	Stack* temp = myStk->head;
	Stack buf;
	ofstream frm("Stack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(Stack));
		temp = temp->next;
	}
	frm.close();
}



void fromFile(Stack*& myStk)          
{
	clear(myStk);
	Stack buf, * first = myStk->head;
    Stack* e = new Stack;
	ifstream frm("Stack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(Stack));
	while (!frm.eof())
	{
		e->data = buf.data;
		e->next = myStk->head;
		myStk->head = e;
		cout << "   " << buf.data;
		frm.read((char*)&buf, sizeof(Stack));
	}
	cout  << endl;
	frm.close();
	myStk = first;

}

void clear(Stack* myStk)
{
	myStk->head = NULL;
};

bool if4(Stack* myStk)
{
	bool flag=false;
	int a,a1;
	Stack* e = myStk->head;
	Stack* e1 = myStk->head;
	a1 = e1->data;
	e1 = e1->next;

	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e1 != NULL)
	{

			a = e->data;
			a1 = e1->data;
			if (a == a1) flag = true;
			e1 = e1->next;
			e = e->next;

	}
	return flag;
};


void push1(char x, Stack1* myStk)
{
	Stack1* e = new Stack1;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
}
void dop1()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack1* my = new Stack1; //выделение памяти для стека
	my->head = NULL;       //инициализация первого элемента
	char a[] = { "привет" };
	char b[sizeof(a)];
	for (int i = 0;(sizeof(a))/2 > i; i++)
	{
		push1(a[i], my);
	}
	Stack1* e = my->head;
	int i = 0;
	while (e != NULL)
	{
		b[i] = e->data;
		i++;
		e = e->next;
	}
	for (int i = (sizeof(a)) / 2; sizeof(a)-1> i; i++)
	{
		push1(a[i], my);
	}
	e = my->head;
	while (e != NULL)
	{
		b[i] = e->data;
		i++;
		e = e->next;
	}
	for (int i =0; sizeof(a)  - 1 > i; i++)
	{
		cout << b[i];
	}

}

void dop2()
{
	    setlocale(LC_ALL, "rus");
		Stack* myy = new Stack; //выделение памяти для стека
		myy->head = NULL;       //инициализация первого элемента  
		char buff[50];
		int count=0, size;
        ifstream fin("a.txt");     
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        while (fin.getline(buff, 50))
        {
			count++;
			size =strlen(buff);
			push(strlen(buff), myy);
        }
        fin.close();
    }
	show(myy);
	cout << "\nNumber: " << count << "\nSize: " << size << endl;
}




void dop3(Stack* myStk)
{
	Stack* e = myStk->head;
	Stack* a = e;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		if (e->next->data < 0) {e->next = e->next->next; break; }
		e = e->next;
	}
	cout << endl;
}