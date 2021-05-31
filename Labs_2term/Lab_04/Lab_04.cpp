//#include <iostream>
//using namespace std;
//void input(int size);
//void output();
//void find(int);
//void del(char name[]);
//union Library_u
//{
//	char author[20];
//	char nameBook[20];
//	char pubHouse[10];
//	char section[10];
//	bool avail;
//	int obtain;
//	int year;
//} lib;
//typedef struct Library
//{
//	char author[20];
//	char nameBook[20];
//	char pubHouse[10];
//	char section[10];
//	bool avail;
//	int obtain;
//	int year;
//} LIB;
//int number; FILE* f; errno_t err;
//LIB list[10];
//
//enum obtain
//{
//	purchase=1,  theft, gift
//};
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int choice, ye; char auth[16], name[20];
//	do
//	{
//		cout << "\n1.Новые книги\n";
//		cout << "2.База книг\n";
//		cout << "3.Поиск по году\n";
//		cout << "4.Удаление книги из базы\n";
//		cout << "0.Выход из программы\n\n";
//		cout << "Введите номер операции: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1: cout << "Введите количество книг: ";
//			cin >> number;
//			input(number);  break;
//		case 2: output(); break;
//		case 3: {  cout << "Введите год: ";
//			cin >> ye;
//			find(ye); break;
//		}
//		case 4: {
//			cout << "Введите название книги, которую хотите удалить: ";
//			cin >> name;
//			del(name); break; }
//		case 0: exit(0);  break;
//		}
//	} while (choice != 0);
//}
//
//void input(int size)
//{
//	setlocale(LC_ALL, "Russian");
//	LIB buf = { ' ', ' ', ' ',' ' };
//	int a;
//	if (!fopen_s(&f, "base.bin", "ab"))
//	{
//		for (int p = 0; p < size; p++)
//		{
//			cout << "Автор: "; 	cin >> lib.author; strcpy_s(buf.author, lib.author);
//			cout << "Название: "; 	cin >> lib.nameBook; strcpy_s(buf.nameBook, lib.nameBook);
//			cout << "Издательство: "; 	cin >> lib.pubHouse; strcpy_s(buf.pubHouse, lib.pubHouse);
//			cout << "Раздел: "; 	cin >> lib.section; strcpy_s(buf.section, lib.section);
//			cout << "Способ приобретения(1-покупка,2-кража,3-подарок): "; 	cin >> lib.obtain; buf.obtain = lib.obtain;
//			cout << "Наличие(1-да,2-нет): "; 	cin >> a;
//			if (a == 1) lib.avail = true;
//			else lib.avail = false;
//			buf.avail=lib.avail;
//
//			cout << "Год: "; 	cin >> lib.year;   buf.year = lib.year;
//			fwrite(&buf, sizeof(buf), 1, f);
//		}
//		fclose(f);
//	}
//	else {
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void output()
//{
//	setlocale(LC_ALL, "Russian");
//	LIB buf;
//	if (!fopen_s(&f, "base.bin", "rb"))
//	{
//	
//		cout << "\nАвтор       Название       Издательство      Раздел      Способ приобретения      Наличие     Год\n";
//		fread(&buf, sizeof(buf), 1, f);
//		while (!feof(f))
//		{
//
//			cout << buf.author << "\t    " << buf.nameBook << "\t    " << buf.pubHouse << "\t    " << buf.section << "\t    " << buf.obtain << "\t    ";
//			
//			if (buf.obtain == purchase)  printf("Покупка\t    ");
//			else if (buf.obtain == theft)  printf("Кража\t    ");
//			else  printf("Подарок\t    ");
//
//			if (buf.avail == true) printf("Да\t     ");
//			else printf("Нет\t     ");
//
//			printf("%d\n", buf.year);
//			fread(&buf, sizeof(buf), 1, f);
//		}
//		cout << endl;
//		fclose(f);
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//}
//
//void find(int ye)
//{
//	bool flag = false;  LIB buf;
//	if (!fopen_s(&f, "base.bin", "rb"))
//	{
//		while (!feof(f))
//		{
//			fread(&buf, sizeof(buf), 1, f);
//			if (ye==buf.year)
//			{
//				cout << "\nАвтор       Название       Издательство      Раздел      Способ приобретения      Наличие     Год\n";
//
//				cout << buf.author << "\t    " << buf.nameBook << "\t       " << buf.pubHouse << "\t       " << buf.section << "\t       " << buf.obtain << "\t       ";
//
//				if (buf.obtain == purchase)  printf("Покупка\t      ");
//				else if (buf.obtain == theft)  printf("Кража\t      ");
//				else  printf("Подарок\t      ");
//
//				if (buf.avail == true) printf("Да\t       ");
//				else printf("Нет\t        ");
//
//				printf("%d\n", buf.year);
//				flag = true; break;
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
//
//
//int numb;
//void del(char name[])
//{
//	bool flag = false;  LIB buf; int counter = 0,i=0;
//	if (!fopen_s(&f, "base.bin", "rb"))
//	{
//		while (!feof(f))
//		{
//			fread(&buf, sizeof(buf), 1, f);
//			list[i] = buf; i++;
//			if (strcmp(name, buf.author) == 0)
//			{
//				cout << "\nАвтор       Название       Издательство      Раздел      Способ приобретения      Наличие     Год\n";
//
//				cout << buf.author << "\t    ";
//				cout << buf.nameBook << "\t    ";
//				cout << buf.pubHouse << "\t    "; 
//				cout << buf.section << "\t    ";
//				cout << buf.obtain << "\t    ";
//
//				if (buf.obtain == purchase)  printf("Покупка\t    ");
//				else if (buf.obtain == theft)  printf("Кража\t    ");
//				else  printf("Подарок\t    ");
//
//				if (buf.avail == true) printf("Да\t     ");
//				else printf("Нет\t     ");
//
//				printf("%d\n", buf.year);
//				flag = true; 
//				numb = counter;
//			}
//			counter++;
//		}
//		fclose(f);
//		if (!flag) cout << "Ничего не найдено\n";
//		else {
//			fopen_s(&f, "base.bin", "wb");
//			for (int i = numb+1; i < counter-1; i++)
//			{
//				list[i - 1] = list[i];
//			}
//			for (int i = 0; i < counter-2; i++)
//			{
//				buf = list[i];
//				fwrite(&buf, sizeof(buf), 1, f);
//			}
//			fclose(f);
//		}
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//
//
//}
