#include<iostream>
#include<fstream>
#include<Windows.h>
#define size 10

using namespace std;

void write_clients();
void delete_client();
void write_in_file();
void read_out_file();
void search_client();

struct clients
{
	char passport[9];
	char date_in[8];
	char date_out[8];
	int nomer;
	char type[20];
	char last_name[20];
};
struct clients list_of_clients[size];
struct clients bad;

int current_size = 0, choice;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "�������:" << endl;
	cout << "1 - ������ ��������" << endl;
	cout << "2 - �������� ������ � �������" << endl;
	cout << "3 - ������ ���������� � �������� � ����" << endl;
	cout << "4 - ����� ���������� �� �����" << endl;
	cout << "5 - ����� ������� �� �������" << endl;
	cout << "0 - �����" << endl;
	cout << "��� �����: ";
	cin >> choice;

	do
	{
		switch (choice)
		{
		case 1: write_clients();
			break;
		case 2: delete_client();
			break;
		case 3: write_in_file();
			break;
		case 4: read_out_file();
			break;
		case 5: search_client();
			break;
		default:
			break;
		}
	} while (choice != 0);
}


void write_clients()
{
	int size_buff;
	cout << "\n������� ���������� ����������� ��������(����� ��� " << size - current_size << "): ";
	cin >> size_buff;
	if (current_size + size_buff > size)
		cout << "�� �� ������ ������ ������� ����������" << endl;
	else
		for (int i = current_size; i < current_size + size_buff; i++)
		{
			cout << "���� ���������� � " << i + 1 << "-�� �������:" << endl;
			cout << "�������: ";
			cin >> list_of_clients[i].last_name;
			cout << "������ ��������: ";
			cin >> list_of_clients[i].passport;
			cout << "����� �������: ";
			cin >> list_of_clients[i].nomer;
			cout << "��� ������: ";
			cin >> list_of_clients[i].type;
			cout << "���� ��������: ";
			cin >> list_of_clients[i].date_in;
			cout << "���� ������: ";
			cin >> list_of_clients[i].date_out;
			cout << endl;
		}
	current_size += size_buff;
	cout << "���������� ����� ��������: ";
	cin >> choice;
}

void delete_client()
{
	int client;
	cout << "���������� � ������� ��� ����� ������� �� ������ �������?" << endl;
	cout << "�����: ";
	cin >> client;
	for (int i = client - 1; i < current_size - 1; i++)
		list_of_clients[i] = list_of_clients[i + 1];
	current_size--;
	ofstream file_write("clients.txt");
	if (!file_write)
		cout << "error open file clients.txt" << endl;
	else
		for (int i = 0; i < current_size; i++)
		{
			file_write << "�������: " << list_of_clients[i].last_name << endl;
			file_write << "������ ��������: " << list_of_clients[i].passport << endl;
			file_write << "����� �������: " << list_of_clients[i].nomer << endl;
			file_write << "��� �������: " << list_of_clients[i].type << endl;
			file_write << "���� ��������: " << list_of_clients[i].date_in << endl;
			file_write << "���� ������: " << list_of_clients[i].date_out << endl;
			file_write << endl;
		}
	file_write.close();
	cout << "\n���������� ����� ��������: ";
	cin >> choice;
}

void write_in_file()
{
	if (current_size != 0)
	{
		ofstream file_write("clients.txt");
		if (!file_write)
			cout << "error open file clients.txt" << endl;
		else
		{
			for (int i = 0; i < current_size; i++)
			{
				file_write << "�������: " << list_of_clients[i].last_name << endl;
				file_write << "������ ��������: " << list_of_clients[i].passport << endl;
				file_write << "����� �������: " << list_of_clients[i].nomer << endl;
				file_write << "��� �������: " << list_of_clients[i].type << endl;
				file_write << "���� ��������: " << list_of_clients[i].date_in << endl;
				file_write << "���� ������: " << list_of_clients[i].date_out << endl;
				file_write << endl;
			}
			cout << "������ ������� ��������" << endl;
		}
		file_write.close();
	}
	else
		cout << "���������� ��� ������ �� �������" << endl;
	cout << "\n���������� ����� ��������: ";
	cin >> choice;
}

void read_out_file()
{
	ifstream file_read("clients.txt");
	char buff[50];
	if (!file_read)
		cout << "error open file clients.txt" << endl;
	else
	{
		cout << "\n������ �� �����:" << endl;
		while (file_read.getline(buff, 100))
			cout << buff << endl;
	}
	file_read.close();
	cout << "���������� ����� ��������: ";
	cin >> choice;
}


void search_client()
{
	ifstream file_read("clients.txt");
	if (!file_read)
		cout << "error open file clients.txt" << endl;
	else
	{
		char last_name[20], buff[100];
		bool b = true, bb = false;
		cout << "������� ������� �������, ���������� � ������� �� ������ �����: ";
		cin >> last_name;
		while (file_read.getline(buff, 100))
		{
			b = true;
			for (int i = 9, j = 0; j < strlen(last_name); i++, j++)
				if (buff[i] != last_name[j])
					b = false;
			if (b)
			{
				cout << "������ ��������� ����������:" << endl;
				bb = true;
				for (int i = 0; i < 6; i++)
				{
					cout << buff << endl;
					file_read.getline(buff, 100);
				}
				break;
			}
		}
		if (!bb)
			cout << "������ �� ������ �� �������" << endl;
	}
	file_read.close();
	cout << "���������� ����� ��������: ";
	cin >> choice;
}