#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Stack
{
	int data;
	Stack* head;
	Stack* next;
};
struct Stack1
{
	char data;
	Stack1* head;
	Stack1* next;
};
void show(Stack* myStk);
int pop(Stack* myStk);
void push(int x, Stack* myStk);
void clear(Stack* myStk);
void toFile(Stack*& myStk);
void fromFile(Stack*& myStk);
bool if4(Stack* myStk);
void dop1();
void dop2();
void dop3(Stack* myStk);