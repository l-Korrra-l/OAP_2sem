#include<iostream>
#include<Windows.h>
#define size 9

using namespace std;
void input_information();
void search_train();
void output_list();


struct TRAIN
{
	char point_name[20];
	int numb;
	char time_drive[5];
};

struct TRAIN list_to_train[size];
struct TRAIN bad;

int choice;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do
	{
		cout << "Меню:" << endl;
		cout << "1 - Ввести расписание" << endl;
		cout << "2 - Найти поезд по времени отправления" << endl;
		cout << "3 - Вывести расписание" << endl;
		cout << "0 - ВЫХОД" << endl;
		cout << "Выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1:input_information();
			break;
		case 2:search_train();
			break;
		case 3:output_list();
			break;
		default:
			break;
		}
	} while (choice != 0);
}

void input_information()
{
	cout << "\nВведите расписание поездов (8 маршрутов):" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << "\nИнформация " << i + 1 << " маршрута:" << endl;
		cout << "Пункт назначения: ";
		cin >> list_to_train[i].point_name;
		cout << "Номер поезда: #";
		cin >> list_to_train[i].numb;
		cout << "Время отправления (чч:мм): ";
		cin >> list_to_train[i].time_drive;
	}
	for (int i = 0; i < size - 2; i++)
		for (int j = i + 1; j < size - 1; j++)
			if (strcmp(list_to_train[i].point_name, list_to_train[j].point_name) > 0)
			{
				list_to_train[8] = list_to_train[i];
				list_to_train[i] = list_to_train[j];
				list_to_train[j] = list_to_train[8];
			}
	cout << "\nДальнейшее действие: ";
	cin >> choice;
}

void search_train()
{
	char drive[5];
	bool b = false;
	cout << "\nВведите время отправления: " << endl;
	cin >> drive;
	cout << "Результаты поиска:" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		if (strcmp(drive, list_to_train[i].time_drive) == 0)
		{
			cout << list_to_train[i].point_name << "\t#" << list_to_train[i].numb << "\t" << list_to_train[i].time_drive << endl;
			b = true;
		}
	}
	if (!b)
		cout << "Не найдено" << endl;
	cout << "\nДальнейшее действие: ";
	cin >> choice;
}

void output_list()
{
	cout << "\nРасписание:" << endl;
	for (int i = 0; i < size - 1; i++)
		cout << list_to_train[i].point_name << "\t#" << list_to_train[i].numb << "\t" << list_to_train[i].time_drive << endl;
	cout << "\nДальнейшее действие: ";
	cin >> choice;
}