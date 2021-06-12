/*������ ����������.����� �����, ��������, ������������, ������ ����������(����������� ����������, �����, ��������
���������, ������������� � �.�.), �������������(�������, �����, �������) � ������� ����� � ������ ������.����� ����
�� ������.
� ��������� ������ ����� �������:
-	���� ��������� ��������� � ����������;
-	����� ��������� ��������� � ���������� ����;
-	�������� �������� ����������������� ����������;
-	����� ����������;
-	������ ���������� � ����;
-	������ ������ �� �����.
*/
#include <iostream>
using namespace std;
void input(int size);
void output();
void find(char author[]);
void del(char name[]);
typedef struct Library
{
	char author[20];
	char nameBook[20];
	char pubHouse[10];
	char section[10];
	int obtain;
	bool avail;
} LIB;
int number; FILE* f; errno_t err;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice; char auth[16], name[20];
	do
	{
		cout << "\n1.����� �����\n";
		cout << "2.���� ����\n";
		cout << "3.����� �� ������\n";
		cout << "4.�������� ����� �� ����\n";
		cout << "0.����� �� ���������\n\n";
		cout << "������� ����� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� ���������� ����: ";
			cin >> number;
			input(number);  break;
		case 2: output(); break;
		case 3: {  cout << "������� ������: ";
			cin >> auth;
			find(auth); break;
		}
		case 4: {
			cout << "������� �������� �����, ������� ������ �������: ";
			cin >> name;
			del(name); break; }
		case 0: exit(0);  break;
		}
	} while (choice != 0);
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
			cout << "�������(1-��,2-���): "; 	cin >>a;
			if (a == 1) buf.avail = true;
			else buf.avail = false;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "������ �������� �����";
		return;
	}
}

void output()
{
	setlocale(LC_ALL, "Russian");
	LIB buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		char a[]="��",a1[]="���";
		cout << "\n�����       ��������       ������������      ������      ������ ������������      �������\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			
			cout << buf.author << "\t    " << buf.nameBook << "\t    " << buf.pubHouse << "\t    " << buf.section << "\t    " << buf.obtain << "\t    ";
			if (buf.obtain == 1)  printf("�������\t    ");
			else if (buf.obtain == 2)  printf("�����\t    ");
			else  printf("�������\t    ");
			if (buf.avail == true) printf("��\n");
			else printf("���\n");
			
			fread(&buf, sizeof(buf), 1, f);
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

LIB list[10];
int numb;
void del(char name[])
{
	bool flag = false;  LIB buf; int counter = 0,i=0;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			list[i] = buf; i++;
			if (strcmp(name, buf.author) == 0)
			{
				cout << "\n�����       ��������       ������������      ������      ������ ������������      �������\n";
				cout << buf.author << "\t    " << buf.nameBook << "\t    " << buf.pubHouse << "\t    " << buf.section << "\t    " << buf.obtain << "\t    ";
				flag = true; 
				numb = counter;
			}
			counter++;
		}
		fclose(f);
		if (!flag) cout << "������ �� �������\n";
		else {
			fopen_s(&f, "base.bin", "wb");
			for (int i = numb + 1; i < counter - 1; i++)
			{
				list[i - 1] = list[i];
			}
			for (int i = 0; i < counter - 2; i++)
			{
				buf = list[i];
				fwrite(&buf, sizeof(buf), 1, f);
			}
			fclose(f);
		}
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}


}
