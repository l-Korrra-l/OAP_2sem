#include <iostream>
using namespace std;
struct Tree          //дерево
{
	char name[10];  
	int number;
	int tarr;
	Tree* Left, * Right;
};
int tar1 = 0, tar2 = 0, tar3 = 0;
Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, char* s, int tarr);       //Создание нового элемента
Tree* insertElem(Tree* t, int tarr, char* name, int key);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
int count(Tree* t, char letter);  //Подсчет количества слов
void delAll(Tree* t);             //Очистка дерева
Tree* find(Tree* n, int key);   //Поиск элемента по ключу
void cleaves(Tree* t);    //вес дерева
void sleaves(Tree* t);    //сумма значений листьев
void evennodes(Tree* t);    //количество узлов с четными ключами

int c = 0;         //количество слов
Tree* Root = NULL; 	//указатель корня
int numb = 0;

void main()
{
	setlocale(0, "Russian");
	int tarr, choice, n, number;
	Tree* rc; char name[10], letter;
	for (;;)
	{
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск владельца по номеру\n";
		cout << "4 -	вывод дерева\n";
		cout << "5 -	наиболее востребованный тариф\n";
		cout << "0-	выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\nВведите тариф(1,2,3): "; cin >> tarr;
			cout << "Введите имя: "; cin >> name;
			cout << "Введите номер: "; cin >> number;
			insertElem(Root, tarr, name , number); break;
		case 3:  cout << "\nВведите номер: ";  cin >> number;
			rc = search(Root, number);
			cout << "Найденный владелец= ";
			puts(rc->name); break;
		case 4:  if (Root->number >= 0)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}break;
		case 5: if ((tar1 >= tar2) && (tar1 >= tar3)) cout << "\nНаиболее востребован первый тариф\n";
			  else if ((tar2 >= tar3)) cout << "\nНаиболее востребован второй тариф\n";
			  else cout << "\nНаиболее востребован третий тариф\n";
			break;
		case 0:  exit(0);
		}
	}
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
	int key; char s[10]; int tarr;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите номер: "; cin >> key;
		cout << "Введите имя владельца: "; cin >> s;
		cout << "Введите тариф(1,2,3): "; cin >> tarr;
		if (tarr == 1) tar1++;
		if (tarr == 2) tar2++;
		if (tarr == 3) tar3++;
		Root = list(key, s, tarr);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nВведите номер: ";  cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		cout << "Введите имя владельца: "; cin >> s;
		cout << "Введите тариф(1,2,3): "; cin >> tarr;
		if (tarr == 1) tar1++;
		if (tarr == 2) tar2++;
		if (tarr == 3) tar3++;
		insertElem(Root, tarr, s, key);
	}
	return Root;
}

Tree* list(int i, char* s,int tarr)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->number = i;
	t->tarr = tarr;
	for (i = 0; i < 10; i++)
		*((t->name) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int tarr, char* name, int key)  //Добавление нового элемента
{
	Tree* Prev = NULL;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->number)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->number) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key, name, tarr);           //создается новый узел 
		if (key < Prev->number)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}



Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->number))
			rc = search(n->Left, key);
		else
			if (key > (key, n->number))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}



void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->number;
		cout << tm << ' ';
		puts(t->name);
		view(t->Left, level + 1);	//вывод левого поддерева
	}
}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

