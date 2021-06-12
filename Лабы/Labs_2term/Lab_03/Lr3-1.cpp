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

	cout << "Введите:" << endl;
	cout << "1 - Запись клиентов" << endl;
	cout << "2 - Удаление записи о клиенте" << endl;
	cout << "3 - Запись информации о клиентах в файл" << endl;
	cout << "4 - Вывод информации из файла" << endl;
	cout << "5 - Поиск клиента по Фамилии" << endl;
	cout << "0 - Выход" << endl;
	cout << "Ваш выбор: ";
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
	cout << "\nВведите количество добавляемых клиентов(можно еще " << size - current_size << "): ";
	cin >> size_buff;
	if (current_size + size_buff > size)
		cout << "Вы не можете ввести столько информации" << endl;
	else
		for (int i = current_size; i < current_size + size_buff; i++)
		{
			cout << "Ввод информации о " << i + 1 << "-ом клиенте:" << endl;
			cout << "Фамилия: ";
			cin >> list_of_clients[i].last_name;
			cout << "Данные паспорта: ";
			cin >> list_of_clients[i].passport;
			cout << "Номер комнаты: ";
			cin >> list_of_clients[i].nomer;
			cout << "Вид покоев: ";
			cin >> list_of_clients[i].type;
			cout << "Дата прибытия: ";
			cin >> list_of_clients[i].date_in;
			cout << "Дата выезда: ";
			cin >> list_of_clients[i].date_out;
			cout << endl;
		}
	current_size += size_buff;
	cout << "Дальнейший выбор действий: ";
	cin >> choice;
}

void delete_client()
{
	int client;
	cout << "Информацию о клиенте под каким номером вы хотите удалить?" << endl;
	cout << "Выбор: ";
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
			file_write << "Фамилия: " << list_of_clients[i].last_name << endl;
			file_write << "Данные паспорта: " << list_of_clients[i].passport << endl;
			file_write << "Номер комнаты: " << list_of_clients[i].nomer << endl;
			file_write << "Вид комнаты: " << list_of_clients[i].type << endl;
			file_write << "Дата прибытия: " << list_of_clients[i].date_in << endl;
			file_write << "Дата выезда: " << list_of_clients[i].date_out << endl;
			file_write << endl;
		}
	file_write.close();
	cout << "\nДальнейший выбор действий: ";
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
				file_write << "Фамилия: " << list_of_clients[i].last_name << endl;
				file_write << "Данные паспорта: " << list_of_clients[i].passport << endl;
				file_write << "Номер комнаты: " << list_of_clients[i].nomer << endl;
				file_write << "Вид комнаты: " << list_of_clients[i].type << endl;
				file_write << "Дата прибытия: " << list_of_clients[i].date_in << endl;
				file_write << "Дата выезда: " << list_of_clients[i].date_out << endl;
				file_write << endl;
			}
			cout << "Данные успешно записаны" << endl;
		}
		file_write.close();
	}
	else
		cout << "Информации для записи не найдено" << endl;
	cout << "\nДальнейший выбор действий: ";
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
		cout << "\nДанные из файла:" << endl;
		while (file_read.getline(buff, 100))
			cout << buff << endl;
	}
	file_read.close();
	cout << "Дальнейший выбор действий: ";
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
		cout << "Введите фамилию клиента, информацию о котором вы хотите найти: ";
		cin >> last_name;
		while (file_read.getline(buff, 100))
		{
			b = true;
			for (int i = 9, j = 0; j < strlen(last_name); i++, j++)
				if (buff[i] != last_name[j])
					b = false;
			if (b)
			{
				cout << "Выдача поисковой информации:" << endl;
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
			cout << "Данных по поиску не найдено" << endl;
	}
	file_read.close();
	cout << "Дальнейший выбор действий: ";
	cin >> choice;
}