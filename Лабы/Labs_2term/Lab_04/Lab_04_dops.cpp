/*10	�����������.������������, �������, ����������� ���������, �������.����� ����������� �� ���������� �������(> ��������� ��������).
����� ��������� ����������� � ������� ������������.*/
//#include <iostream>
//using namespace std;
//void input(int size);
//void output();
//void find(int);
//
//typedef struct State
//{
//	char name[20];
//	char capital[20];
//	int population;
//	int area;
//	int govform;
//} ST;
//int number; FILE* f; errno_t err;
//ST list[10];
//
//enum govForm
//{
//	monarcy,democracy,oligarchy
//};
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int choice, ye; char auth[16], name[20];
//	do
//	{
//		cout << "\n1.�������� �����������\n";
//		cout << "2.����\n";
//		cout << "3.����� �� �������\n";
//		cout << "0.����� �� ���������\n\n";
//		cout << "������� ����� ��������: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "������� ���������� : ";
//			cin >> number;
//			input(number);  break;
//		case 2: output(); break;
//		case 3: {  cout << "������� �������: ";
//			cin >> ye;
//			find(ye); break;
//		}
//		case 0: exit(0);  break;
//		}
//	} while (choice != 0);
//}
//
//void input(int size)
//{
//	setlocale(LC_ALL, "Russian");
//	ST buf = { ' ', ' ', ' ',' ' };
//	int a;
//	if (!fopen_s(&f, "st.bin", "ab"))
//	{
//		for (int p = 0; p < size; p++)
//		{
//			cout << "������������: "; 	cin >> buf.name; 
//			cout << "\n�������: "; 	cin >> buf.capital; 
//			cout << "\n����������� ���������: "; 	cin >> buf.population; 
//			cout << "\n�������: "; 	cin >> buf.area; 
//			cout << "\n����� ���������(0-��������, 1-����������, 2-���������)"; cin >> buf.govform;
//			fwrite(&buf, sizeof(buf), 1, f);
//		}
//		fclose(f);
//	}
//	else {
//		cout << "\n������ �������� �����";
//		return;
//	}
//}
//
//void output()
//{
//	setlocale(LC_ALL, "Russian");
//	ST buf;
//	if (!fopen_s(&f, "st.bin", "rb"))
//	{
//
//		fread(&buf, sizeof(buf), 1, f);
//		while (!feof(f))
//		{
//			cout << "\n������������: "<< buf.name;
//			cout << "\n�������: "<< buf.capital;
//			cout << "\n����������� ���������: "<< buf.population;
//			cout << "\n�������: "<< buf.area;
//			cout << "\n����� ���������:";
//			if (buf.govform == 0) cout << "��������\n";
//			if (buf.govform == 1) cout << "����������\n";
//			if (buf.govform == 2) cout << "���������\n";
//			fread(&buf, sizeof(buf), 1, f);
//		}
//		cout << endl;
//		fclose(f);
//	}
//	else
//	{
//		cout << "\n������ �������� �����";
//		return;
//	}
//}
//
//void find(int ye)
//{
//	bool flag = false;  ST buf;
//	if (!fopen_s(&f, "st.bin", "rb"))
//	{
//		while (!feof(f))
//		{
//			fread(&buf, sizeof(buf), 1, f);
//			if (buf.area>=ye)
//			{
//				cout << "\n������������: " << buf.name;
//				cout << "\n�������: " << buf.capital;
//				cout << "\n����������� ���������: " << buf.population;
//				cout << "\n�������: " << buf.area;
//				cout << "\n����� ���������";
//				if (buf.govform == 0) cout << "��������\n";
//				if (buf.govform == 1) cout << "����������\n";
//				if (buf.govform == 2) cout << "���������\n";
//				flag = true; 
//			}
//		}
//		fclose(f);
//		if (!flag) cout << "������ �� �������\n";
//	}
//	else
//	{
//		cout << "������ �������� �����";
//		return;
//	}
//}


/*10	���������.�.�.�., ���� ��������, �����, ���(�, �).����������� ������� �� ���� ��������.*/
//#include <iostream>
//#include <Windows.h>
//using namespace std;
//#define size 5
//
//enum gender
//{
//	maskulan, femenum
//};
//
//struct date
//{
//	unsigned short day : 8;
//	unsigned short month : 8;
//	unsigned short year : 8;
//};
//
//struct peaples
//{
//	char last_name[12];
//	char name[12];
//	char second_name[12];
//	date data;
//	char adress[20];
//	int gend;
//};
//
//struct peaples list_of_peaples[size];
//int current_size = 0; int choice;
//
//void input_data();
//void output_data();
//void search_data();
//
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	cout << "1 - �������� ������" << endl;
//	cout << "2 - ����" << endl;
//	cout << "3 - �����" << endl;
//	cout << "0 - �����" << endl;
//	cout << "��� �����: " << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1: input_data();
//			break;
//		case 2: output_data();
//			break;
//		case 3: search_data();
//			break;
//		default:
//			break;
//		}
//	} while (choice != 0);
//}
//
//
//
//void input_data()
//{
//	int amt;
//	int t;
//	cout << "���������� ����������� �������: ";
//	cin >> amt;
//	for (int i = current_size; i < current_size + amt; i++)
//	{
//		cout << "\n�.�.�.:\n" << endl;
//		cin >> list_of_peaples[i].last_name;
//		cin >> list_of_peaples[i].name;
//		cin >> list_of_peaples[i].second_name;
//		cout << "�����: ";
//		cin >> list_of_peaples[i].adress;
//		cout << "���� ��������:" << endl;
//		cout << "����: "; cin >> t;list_of_peaples[i].data.day = t;
//		cout << "�����: "; cin >> t; list_of_peaples[i].data.month = t;
//		cout << "���: "; cin >> t; list_of_peaples[i].data.year = t;
//		cout << "��� (0 - �������, 1 - �������): ";
//		cin >> list_of_peaples[i].gend;
//	}
//	current_size += amt;
//	cout << "\n��������� �����: ";
//	cin >> choice;
//}
//
//void output_data()
//{
//	for (int i = 0; i < current_size; i++)
//	{
//		cout << "\n�.�.�: " << list_of_peaples[i].last_name << " " << list_of_peaples[i].name << " " << list_of_peaples[i].second_name << endl;
//		cout << "�����: " << list_of_peaples[i].adress << endl;
//		cout << "���� ��������: " << list_of_peaples[i].data.day << "." << list_of_peaples[i].data.month << "." << list_of_peaples[i].data.year << endl;
//		cout << "���: ";
//		switch (list_of_peaples[i].gend)
//		{
//		case 1: cout << "�������";
//		case 0: cout << "�������";
//		default:
//			break;
//		}
//	}
//	cout << "\n��������� �����: ";
//	cin >> choice;
//}
//
//
//
//void search_data()
//{
//	int q, w, e;
//	cout << "������� ���� ��������:" << endl;
//	cout << "����: "; cin >> q;
//	cout << "�����: "; cin >> w;
//	cout << "���: "; cin >> e;
//	for (int i = 0; i < current_size; i++)
//	{
//		if (q == list_of_peaples[i].data.day &&
//			w == list_of_peaples[i].data.month &&
//			e == list_of_peaples[i].data.year)
//		{
//			cout << "\n�.�.�: " << list_of_peaples[i].last_name << " " << list_of_peaples[i].name << " " << list_of_peaples[i].second_name << endl;
//			cout << "�����: " << list_of_peaples[i].adress << endl;
//			cout << "���� ��������: " << list_of_peaples[i].data.day << "." << list_of_peaples[i].data.month << "." << list_of_peaples[i].data.year << endl;
//			cout << "���: ";
//			switch (list_of_peaples[i].gend)
//			{
//			case 1: cout << "�������";
//				break;
//			case 0: cout << "�������";
//				break;
//			default:
//				break;
//			}
//		}
//	}
//	cout << "\n������� ����� ��������: ";
//	cin >> choice;
//}

/*13	�����������.������������, �������, ����������� ���������, �������, ������� ����������.����� ����������� �� ��������.*/
#include <iostream>
using namespace std;
void input(int size);
void output();
void find(char name[]);

typedef struct State
{
	char name[20];
	char capital[20];
	int population;
	int area;
	int govform;
	char prsurname[20];
} ST;
int number; FILE* f; errno_t err;
ST list[10];

enum govForm
{
	monarcy,democracy,oligarchy
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice, ye; char auth[16], name[20];
	do
	{
		cout << "\n1.�������� �����������\n";
		cout << "2.����\n";
		cout << "3.����� �� ��������\n";
		cout << "0.����� �� ���������\n\n";
		cout << "������� ����� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� ���������� : ";
			cin >> number;
			input(number);  break;
		case 2: output(); break;
		case 3: {  cout << "������� �������: ";
			cin >> name;
			find(name); break;
		}
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	setlocale(LC_ALL, "Russian");
	ST buf = { ' ', ' ', ' ',' ' };
	int a;
	if (!fopen_s(&f, "st.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "������������: "; 	cin >> buf.name; 
			cout << "\n�������: "; 	cin >> buf.capital; 
			cout << "\n����������� ���������: "; 	cin >> buf.population; 
			cout << "\n�������: "; 	cin >> buf.area; 
			cout << "\n����� ���������(0-��������, 1-����������, 2-���������)"; cin >> buf.govform;
			cout << "\n������� ���������� "; 	cin >> buf.prsurname;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "\n������ �������� �����";
		return;
	}
}

void output()
{
	setlocale(LC_ALL, "Russian");
	ST buf;
	if (!fopen_s(&f, "st.bin", "rb"))
	{

		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << "\n������������: "<< buf.name;
			cout << "\n�������: "<< buf.capital;
			cout << "\n����������� ���������: "<< buf.population;
			cout << "\n�������: "<< buf.area;
			cout << "\n������� ���������� "<< buf.prsurname;
			cout << "\n����� ���������:";
			if (buf.govform == 0) cout << "��������\n";
			if (buf.govform == 1) cout << "����������\n";
			if (buf.govform == 2) cout << "���������\n";

			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "\n������ �������� �����";
		return;
	}
}

void find(char name[])
{
	bool flag = false;  ST buf;
	if (!fopen_s(&f, "st.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(name, buf.prsurname) == 0)
			{
				cout << "\n������������: " << buf.name;
				cout << "\n�������: " << buf.capital;
				cout << "\n����������� ���������: " << buf.population;
				cout << "\n�������: " << buf.area;
				cout << "\n������� ���������� "<<buf.prsurname;
				cout << "\n����� ���������";
				if (buf.govform == 0) cout << "��������\n";
				if (buf.govform == 1) cout << "����������\n";
				if (buf.govform == 2) cout << "���������\n";
				flag = true; 
				break;
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