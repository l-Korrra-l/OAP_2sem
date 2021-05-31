#pragma once

#define LISTNIL (Element*)-1

#include <iostream>

namespace listx

{

	struct Element

		// ������� ������, � ������� ���������� ���� void data, �� ���� � �� ������ ������������� ����

	{

		Element* Prev; Element* Next; void* Data;

		Element(Element* prev, void* data, Element* next)

			// �����������, � ������� ����� � �� ����������, �� ��������� � �� ������

		{

			Prev = prev; Data = data; Next = next;

		}

		Element* GetNext() { return Next; };

		Element* GetPrev() { return Prev; };

	};

	static Element* NIL = NULL; // ����������� � NIL

	struct Object // ��������� Object, � ������ ������ ��� ������

	{

		Element* Head;

		Object() { Head = NIL; }; // �����������, ������� ������������� � �� ������ � NULL

		Element* GetFirst() { return Head; }; // ������� ��� ��� ������ � - ������
		Element* GetLast();

		Element* Search(char* key, char* getkey(void*)); // ������� ������ �-� �� �����

		// � ���-�������� ������������ �� ��� ������, � ������ ����� � ����� � ���-�������� ����������

		// int getkey(void*) - ������� ���������� ����� �� �-�

		bool Insert(void* data); // ������� �������

		bool Delete(Element* e); // �������� �� �-��

		bool Delete(char* key, char* getkey(void*)); // �������� �� �����

		// ������� ��� ������ �-��

		void Scan(void(*f)(Element*), Element* e); // ����� ������ �-�

		void Scan(void(*f)(Element*)); // ����� ����� ������

	};

	Object Create(); // ������� �������� ������ ��������� Object, ����� ���� �� ������������ new

	// ���� Create ��������� � ������������ ��� listx

}