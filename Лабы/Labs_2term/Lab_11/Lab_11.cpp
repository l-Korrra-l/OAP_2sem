﻿/*4. Добавить к проекту  функции смешанного и нисходящего обхода дерева с выводом  на консоль, проверки сбалансированности 
дерева и функцию в соответствии с вариантом из таблицы, представленной в лабораторной работе № 11, изменив ее так, чтобы функция
соответствовала проекту данной лабораторной работы.
Дан указатель p1 на корень непустого дерева.Написать функцию вывода количества листьев данного дерева.*/
#include "Tree.h"
#include <fstream>
using namespace std;
using namespace btree;
struct NodeTree
{
	int  key;
};
//-------------------------------
btree::CMP cmpfnc(void* x, void* y)    // Сравнение
{
	btree::CMP rc = btree::EQUAL;
	if (((NodeTree*)x)->key < ((NodeTree*)y)->key)
		rc = btree::LESS;
	else
		if (((NodeTree*)x)->key > ((NodeTree*)y)->key)
			rc = btree::GREAT;
	return rc;
}
//-------------------------------
void printNode(void* x)               // Вывод при обходе
{
	cout << ((NodeTree*)x)->key << ends;
}
//-------------------------------
bool buildTree(char* FileName, btree::Object& tree) //Построение дерева из файла
{
	bool rc = true;
	FILE* inFile;
	fopen_s(&inFile, FileName, "r");
	if (inFile == NULL)
	{
		cout << "Ошибка открытия входного файла" << endl;
		rc = false; return rc;
	}
	while (!feof(inFile)) // заполнение дерева 
	{
		int num;
		fscanf_s(inFile, "%d", &num, 1);
		NodeTree* a = new NodeTree();
		a->key = num;
		tree.insert(a);
	}
	fclose(inFile);
	return rc;
}
FILE* outFile;
//-------------------------------
void saveToFile(void* x)              // Запись одного элемента в файл
{
	NodeTree* a = (NodeTree*)x;
	int q = a->key;
	fprintf(outFile, "%d\n", q);
}
//-------------------------------
void saveTree(btree::Object& tree, char* FileName)    //Сохранение дерева в файл 
{
	fopen_s(&outFile, FileName, "w");
	if (outFile == NULL)
	{
		cout << "Ошибка открытия выходного файла" << endl;
		return;
	}
	tree.Root->scanDown(saveToFile);
	fclose(outFile);

}
//-------------------------------



int main()
{
	setlocale(LC_CTYPE, "Russian");
	btree::Object demoTree = btree::create(cmpfnc);
	int k, choice;
	char file[] ="G.txt" ;
	NodeTree a1 = { 1 }, a2 = { 2 }, a3 = { 3 }, a4 = { 4 }, a5 = { 5 }, a6 = { 6 };
	bool rc = demoTree.insert(&a4);   //           4  
	rc = demoTree.insert(&a1);        //   1             
	rc = demoTree.insert(&a6);        //                   6
	rc = demoTree.insert(&a2);        //      2     
	rc = demoTree.insert(&a3);        //         3
	rc = demoTree.insert(&a5);        //                 5	
	for (;;)
	{
		NodeTree* a = new NodeTree;
		cout << "1 - вывод дерева на экран" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - сохранить в файл" << endl;
		cout << "5 - загрузить из файла" << endl;
		cout << "6 - очистить дерево" << endl;
		cout << "7 - нисходящий обход" << endl;
		cout << "8 - смешанный обход" << endl;
		cout << "9 - проверка сбалансированности дерева" << endl;
		cout << "10- количество листьев" << endl;
		cout << "11- доп 2" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choice;
		switch (choice)
		{
		case 0:   	exit(0);
		case 1:  	if (demoTree.Root)
			demoTree.Root->scanByLevel(printNode);
			  else
			cout << "Дерево пустое" << endl;
			break;
		case 2: 	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.insert(a);
			break;
		case 3:  	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.deleteByData(a);
			break;
		case 4:   	saveTree(demoTree, file);
			break;
		case 5:  	buildTree(file, demoTree);
			break;
		case 6:	while (demoTree.Root)
			demoTree.deleteByNode(demoTree.Root);
			break;
		case 7:  	if (demoTree.Root)
			demoTree.Root->scanklr(printNode);
			  else
			cout << "Дерево пустое" << endl;
			break;
		case 8: if (demoTree.Root)
			demoTree.Root->scanlkr(printNode);
			  else
			cout << "Дерево пустое" << endl;
			break;
		case 9: if (demoTree.Root)
			demoTree.isbal(demoTree.Root);
			  else
			cout << "Дерево пустое" << endl;
			break;
		case 10: if (demoTree.Root)
		{
			int k = 0;
			demoTree.scann(demoTree.Root,k);
			cout << k << " leaves\n";
		}
			  else
			cout << "Дерево пустое" << endl;
			break;
		case 11:while (demoTree.Root)
			demoTree.deleteByNode(demoTree.Root);

			cout << "\nВведите количество элементов\n";
			int size;
			cin >> size;
			NodeTree a1 = { 0 }; rc = demoTree.insert(&a1);
			for (int i = 1; i < size; i+=2)
			{
				if (i+1 < size){NodeTree* a = new NodeTree;
				a->key = i + 1;
				demoTree.insert(a); }
				NodeTree* b = new NodeTree;
				b->key = i;
				demoTree.insert(b);
			}

			break;
		}
	}
	return 0;
}
