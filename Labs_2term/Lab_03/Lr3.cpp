/*Личная библиотека.Автор книги, название, издательство, раздел библиотеки(специальная литература, хобби, домашнее
хозяйство, беллетристика и т.д.), происхождение(покупка, кража, подарок) и наличие книги в данный момент.Выбор книг
по автору.
В программу должны войти функции:
-	ввод элементов структуры с клавиатуры;
-	вывод элементов структуры в консольное окно;
-	удаление заданной структурированной переменной;
-	поиск информации;
-	запись информации в файл;
-	чтение данных из файла.
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
		cout << "\n1.Новые книги\n";
		cout << "2.База книг\n";
		cout << "3.Поиск по автору\n";
		cout << "4.Удаление книги из базы\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество книг: ";
			cin >> number;
			input(number);  break;
		case 2: output(); break;
		case 3: {  cout << "Введите автора: ";
			cin >> auth;
			find(auth); break;
		}
		case 4: {
			cout << "Введите название книги, которую хотите удалить: ";
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
			cout << "Автор: "; 	cin >> buf.author;
			cout << "Название: "; 	cin >> buf.nameBook;
			cout << "Издательство: "; 	cin >> buf.pubHouse;
			cout << "Раздел: "; 	cin >> buf.section;
			cout << "Способ приобретения(1-покупка,2-кража,3-подарок): "; 	cin >> buf.obtain;
			cout << "Наличие(1-да,2-нет): "; 	cin >>a;
			if (a == 1) buf.avail = true;
			else buf.avail = false;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	setlocale(LC_ALL, "Russian");
	LIB buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		char a[]="да",a1[]="нет";
		cout << "\nАвтор       Название       Издательство      Раздел      Способ приобретения      Наличие\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			
			cout << buf.author << "\t    " << buf.nameBook << "\t    " << buf.pubHouse << "\t    " << buf.section << "\t    " << buf.obtain << "\t    ";
			if (buf.obtain == 1)  printf("Покупка\t    ");
			else if (buf.obtain == 2)  printf("Кража\t    ");
			else  printf("Подарок\t    ");
			if (buf.avail == true) printf("Да\n");
			else printf("Нет\n");
			
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
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
				cout << "\nАвтор       Название       Издательство      Раздел      Способ приобретения      Наличие\n";
				cout << buf.author << "\t    " << buf.nameBook << "\t    " << buf.pubHouse << "\t    " << buf.section << "\t    " << buf.obtain << "\t    ";
				flag = true; break;
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
				cout << "\nАвтор       Название       Издательство      Раздел      Способ приобретения      Наличие\n";
				cout << buf.author << "\t    " << buf.nameBook << "\t    " << buf.pubHouse << "\t    " << buf.section << "\t    " << buf.obtain << "\t    ";
				flag = true; 
				numb = counter;
			}
			counter++;
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
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
		cout << "Ошибка открытия файла";
		return;
	}


}
