/*3. ���������� ��������� ��� ������������� ���������� � ������� ���������� �������, ���������� ��������� ���� : 
�������� ���������, ����� ������������, �������� �������, ���������� �������.����������� ��������� ������ � ���� �������, 
������������ �� �� �������� �������� ����������.� �������� ������ ������ ������ ������������� �� ��������� ����������.������������ 
����� ���������� � ����� �����������.*/
#include <iostream>
using namespace std;
void input(int size);
void output();
void find(char author[]);
void del(char name[]);

typedef struct Camp
{
	char name[20];
	char place[20];
	char prof[10];
	int amount;
};
Camp list[15];
FILE* f; errno_t err;
char profs[10];

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice; char auth[16], name[20];
	int a = sizeof(list->prof);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < sizeof(profs); j++)
		{
			if 
		}
	}
}

void input(int size)
{
	setlocale(LC_ALL, "Russian");
	LIB buf = { ' ', ' ', ' ',' ' };
	int a;
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "�����: "; 	cin >> buf.author;
			cout << "��������: "; 	cin >> buf.nameBook;
			cout << "������������: "; 	cin >> buf.pubHouse;
			cout << "������: "; 	cin >> buf.section;
			cout << "������ ������������(1-�������,2-�����,3-�������): "; 	cin >> buf.obtain;
			cout << "�������(1-��,2-���): "; 	cin >> a;
			if (a == 1) buf.avail = true;
			else buf.avail = false;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
		number += size;
	}
	else {
		cout << "������ �������� �����";
		return;
	}
}

void output()
{
	setlocale(LC_ALL, "Russian");
	LIB buf; int a = 1;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		cout << "\n�����       ��������       ������������      ������      ������ ������������      �������\n";
		fread(&buf, sizeof(buf), 1, f);
		while ((!feof(f)))
		{
			cout << buf.author << "\t    " << buf.nameBook << "\t              " << buf.pubHouse << "\t             " << buf.section << "\t       ";

			if (buf.obtain == 1) cout << "�������\t    ";
			else if (buf.obtain == 2)  cout << "�����\t    ";
			else  cout << "�������\t    ";
			if (buf.avail == true) cout << "��\n";
			else cout << "���\n";

			fread(&buf, sizeof(buf), 1, f);
			a++;

		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}
}

void find(char lastName[16])
{
	bool flag = false;  LIB buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.author) == 0)
			{
				cout << "\n�����       ��������       ������������      ������      ������ ������������      �������\n";
				cout << buf.author << "\t    " << buf.nameBook << "\t    " << buf.pubHouse << "\t    " << buf.section << "\t    " << buf.obtain << "\t    ";
				flag = true; break;
			}

		}
		fclose(f);
		if (!flag) cout << "������ �� �������\n";
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}
}


void del(char name[])
{
	LIB list[10];
	bool flag = false;  LIB buf; int a = 0;
	if (!fopen_s(&f, "base.bin", "rb+"))
	{
		while (!feof(f))
		{

			fread(&buf, sizeof(buf), 1, f);
			list[a] = buf; a++;
			if (strcmp(name, buf.nameBook) == 0)
			{
				cout << "\n�����       ��������       ������������      ������      ������ ������������      �������\n";
				cout << buf.author << "\t    " << buf.nameBook << "\t    " << buf.pubHouse << "\t    " << buf.section << "\t    " << buf.obtain << "\t    ";
				a--;
			}

		}
		a--;

		fclose(f);
		fopen_s(&f, "base.bin", "wb+");
		for (int i = 0; i < a; i++)
		{
			fwrite(&list[i], sizeof(list[i]), 1, f);
		}
		number = a;
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}

	fclose(f);
}