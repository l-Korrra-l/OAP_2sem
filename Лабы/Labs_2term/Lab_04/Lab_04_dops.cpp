/*10	Государство.Наименование, столица, численность населения, площадь.Выбор государства по занимаемой площади(> заданного значения).
Форму правления реализовать с помощью перечисления.*/
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
//		cout << "\n1.Добавить государство\n";
//		cout << "2.База\n";
//		cout << "3.Поиск по площади\n";
//		cout << "0.Выход из программы\n\n";
//		cout << "Введите номер операции: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите количество : ";
//			cin >> number;
//			input(number);  break;
//		case 2: output(); break;
//		case 3: {  cout << "Введите площадь: ";
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
//			cout << "Наименование: "; 	cin >> buf.name; 
//			cout << "\nСтолица: "; 	cin >> buf.capital; 
//			cout << "\nЧисленность населения: "; 	cin >> buf.population; 
//			cout << "\nПлощадь: "; 	cin >> buf.area; 
//			cout << "\nФорма правления(0-монархия, 1-демократия, 2-олигархия)"; cin >> buf.govform;
//			fwrite(&buf, sizeof(buf), 1, f);
//		}
//		fclose(f);
//	}
//	else {
//		cout << "\nОшибка открытия файла";
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
//			cout << "\nНаименование: "<< buf.name;
//			cout << "\nСтолица: "<< buf.capital;
//			cout << "\nЧисленность населения: "<< buf.population;
//			cout << "\nПлощадь: "<< buf.area;
//			cout << "\nФорма правления:";
//			if (buf.govform == 0) cout << "Монархия\n";
//			if (buf.govform == 1) cout << "Демократия\n";
//			if (buf.govform == 2) cout << "Олигархия\n";
//			fread(&buf, sizeof(buf), 1, f);
//		}
//		cout << endl;
//		fclose(f);
//	}
//	else
//	{
//		cout << "\nОшибка открытия файла";
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
//				cout << "\nНаименование: " << buf.name;
//				cout << "\nСтолица: " << buf.capital;
//				cout << "\nЧисленность населения: " << buf.population;
//				cout << "\nПлощадь: " << buf.area;
//				cout << "\nФорма правления";
//				if (buf.govform == 0) cout << "Монархия\n";
//				if (buf.govform == 1) cout << "Демократия\n";
//				if (buf.govform == 2) cout << "Олигархия\n";
//				flag = true; 
//			}
//		}
//		fclose(f);
//		if (!flag) cout << "Ничего не найдено\n";
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}


/*10	Горожанин.Ф.И.О., дата рождения, адрес, пол(м, ж).Реализовать выборку по году рождения.*/
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
//	cout << "1 - добавить запись" << endl;
//	cout << "2 - база" << endl;
//	cout << "3 - поиск" << endl;
//	cout << "0 - выход" << endl;
//	cout << "Ваш выбор: " << endl;
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
//	cout << "Количество добавляемых позиций: ";
//	cin >> amt;
//	for (int i = current_size; i < current_size + amt; i++)
//	{
//		cout << "\nФ.И.О.:\n" << endl;
//		cin >> list_of_peaples[i].last_name;
//		cin >> list_of_peaples[i].name;
//		cin >> list_of_peaples[i].second_name;
//		cout << "Адрес: ";
//		cin >> list_of_peaples[i].adress;
//		cout << "Дата рождения:" << endl;
//		cout << "день: "; cin >> t;list_of_peaples[i].data.day = t;
//		cout << "месяц: "; cin >> t; list_of_peaples[i].data.month = t;
//		cout << "год: "; cin >> t; list_of_peaples[i].data.year = t;
//		cout << "Пол (0 - мужской, 1 - женский): ";
//		cin >> list_of_peaples[i].gend;
//	}
//	current_size += amt;
//	cout << "\nСледующий выбор: ";
//	cin >> choice;
//}
//
//void output_data()
//{
//	for (int i = 0; i < current_size; i++)
//	{
//		cout << "\nФ.И.О: " << list_of_peaples[i].last_name << " " << list_of_peaples[i].name << " " << list_of_peaples[i].second_name << endl;
//		cout << "Адрес: " << list_of_peaples[i].adress << endl;
//		cout << "Дата рождения: " << list_of_peaples[i].data.day << "." << list_of_peaples[i].data.month << "." << list_of_peaples[i].data.year << endl;
//		cout << "Пол: ";
//		switch (list_of_peaples[i].gend)
//		{
//		case 1: cout << "женский";
//		case 0: cout << "мужской";
//		default:
//			break;
//		}
//	}
//	cout << "\nСледующий выбор: ";
//	cin >> choice;
//}
//
//
//
//void search_data()
//{
//	int q, w, e;
//	cout << "Введите дату рождения:" << endl;
//	cout << "День: "; cin >> q;
//	cout << "Месяц: "; cin >> w;
//	cout << "Год: "; cin >> e;
//	for (int i = 0; i < current_size; i++)
//	{
//		if (q == list_of_peaples[i].data.day &&
//			w == list_of_peaples[i].data.month &&
//			e == list_of_peaples[i].data.year)
//		{
//			cout << "\nФ.И.О: " << list_of_peaples[i].last_name << " " << list_of_peaples[i].name << " " << list_of_peaples[i].second_name << endl;
//			cout << "Адрес: " << list_of_peaples[i].adress << endl;
//			cout << "Дата рождения: " << list_of_peaples[i].data.day << "." << list_of_peaples[i].data.month << "." << list_of_peaples[i].data.year << endl;
//			cout << "Пол: ";
//			switch (list_of_peaples[i].gend)
//			{
//			case 1: cout << "женский";
//				break;
//			case 0: cout << "мужской";
//				break;
//			default:
//				break;
//			}
//		}
//	}
//	cout << "\nВведите номер операции: ";
//	cin >> choice;
//}

/*13	Государство.Наименование, столица, численность населения, площадь, фамилия президента.Выбор государства по названию.*/
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
		cout << "\n1.Добавить государство\n";
		cout << "2.База\n";
		cout << "3.Поиск по названию\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество : ";
			cin >> number;
			input(number);  break;
		case 2: output(); break;
		case 3: {  cout << "Введите фамилию: ";
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
			cout << "Наименование: "; 	cin >> buf.name; 
			cout << "\nСтолица: "; 	cin >> buf.capital; 
			cout << "\nЧисленность населения: "; 	cin >> buf.population; 
			cout << "\nПлощадь: "; 	cin >> buf.area; 
			cout << "\nФорма правления(0-монархия, 1-демократия, 2-олигархия)"; cin >> buf.govform;
			cout << "\nФамилия президента "; 	cin >> buf.prsurname;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "\nОшибка открытия файла";
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
			cout << "\nНаименование: "<< buf.name;
			cout << "\nСтолица: "<< buf.capital;
			cout << "\nЧисленность населения: "<< buf.population;
			cout << "\nПлощадь: "<< buf.area;
			cout << "\nФамилия президента "<< buf.prsurname;
			cout << "\nФорма правления:";
			if (buf.govform == 0) cout << "Монархия\n";
			if (buf.govform == 1) cout << "Демократия\n";
			if (buf.govform == 2) cout << "Олигархия\n";

			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "\nОшибка открытия файла";
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
				cout << "\nНаименование: " << buf.name;
				cout << "\nСтолица: " << buf.capital;
				cout << "\nЧисленность населения: " << buf.population;
				cout << "\nПлощадь: " << buf.area;
				cout << "\nФамилия президента "<<buf.prsurname;
				cout << "\nФорма правления";
				if (buf.govform == 0) cout << "Монархия\n";
				if (buf.govform == 1) cout << "Демократия\n";
				if (buf.govform == 2) cout << "Олигархия\n";
				flag = true; 
				break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}