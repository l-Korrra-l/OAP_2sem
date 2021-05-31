//#include <fstream>
//#include <iostream>
//using namespace std;
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    char buff[50];            // буфер для хранения считываемого из файла текста
//    ofstream fout("t.txt");   // создание объекта fout класса ofstream для записи 
//    fout << "Работа с файлами в С++"; // запись строки в файл
//    fout.close();
//    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
//    if (!fin.is_open())
//        cout << "Файл не может быть открыт!\n";
//    else
//    {
//        fin >> buff;           // считывание первого слова из файла
//        cout << buff << endl;  // печать слова
//        fin.getline(buff, 50); // считывание строки из файла
//        fin.close();
//        cout << buff << endl;   // печать строки
//    }
//}

/*4.1. Скопировать из файла FILE1 в файл FILE2 все строки, которые не содержат цифры.Подсчитать количество строк, которые начинаются на 
букву «А» в файле FILE2.*/
//#include <stdio.h>  
//#include <fstream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL,"Rus");
//	FILE* fin;
//	fopen_s(&fin, "FILE1.txt", "rt");
//	ofstream fout1("FILE2.txt");
//	while (!feof(fin))
//	{
//
//		char s[255] = "";
//		fgets(s, 254, fin);
//		bool ifnumb = false;
//		for (int i = 0; i < strlen(s); i++)
//			if ((s[i] >= '0') && (s[i] <= '9')) ifnumb = true;
//		if (ifnumb==false) 
//			fout1 << s;
//	}
//	fclose(fin);
//	fout1.close();
//	ifstream fout2("FILE2.txt");
//	int counter = 0;
//	while (!feof(fin))
//	{
//
//		char s[255] = "";
//		fout2.getline(s, 50);
//		if ((s[0] == 'A') || (s[0] == 'a'))
//			counter++;
//	}
//	printf("В файле %d строки начинаютс на а(А)",counter);
//	return 0;
//}

/*4.2. Ввести строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл.Прочитать из файла данные,
подсчитать количество символов в самом длинном слове и вывести его.*/
//#include <fstream>
//#include <iostream>
//using namespace std;
//void main()
//{
//    setlocale(LC_ALL, "Rus");
//    char s[50], lonw[10]; 
//    int len=0,count=0;
//
//    ofstream fout("A.txt");  
//    fout << "S0me peop1e 123 are worth melting 4"; 
//    fout.close();
//
//
//    ifstream fin("A.txt");    
//    if (!fin.is_open())
//        cout << "файл не может быть открыт!\n";
//
//    fin.getline(s, 40);
//    int a=strlen(s);
//    s[a] = ' ';
//    for (int i = 0; i < a+1; i++)
//    {
//        if (s[i] == ' ') count++;
//    }
//    fin.close();
//
//    
//    ifstream fon("A.txt");
//    for (int i = 0; i < count; i++)
//    {
//        fon >> s;
//        if (strlen(s) > len) {
//            len = strlen(s);
//            for (int j = 0; j < strlen(s); j++)
//                lonw[j] = s[j];
//        }
//    }
//    fon.close();
//
//    printf("Самое длинное слово ");
//    for (int i = 0; i < len; i++)
//    {
//        cout << lonw[i];
//    }
//
//}

/*6.1. Скопировать из файла FILE1 в файл FILE2 строки, начиная с N до K.Подсчитать количество согласных букв в файле FILE2.*/
//#include <stdio.h>  
//#include <fstream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	int k,count=0,n; FILE* fin, *fon;
//	fopen_s(&fin, "file1.txt", "rt");
//	ofstream fout1("ff2.txt");
//	printf("Введите параметры n и k\n");
//	scanf_s("%d", &n);
//	scanf_s("%d", &k);
//	while (!feof(fin))
//	{
//		char s[255] = "";
//		fgets(s, 254, fin); count++;
//		if ((count>=n)&&(count<=k))
//			fout1 << s;
//		
//	}
//	fclose(fin);
//	fout1.close();
//
//	fopen_s(&fon, "ff2.txt", "rt");
//	count = 0; char lett[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' };
//	while (!feof(fon))
//	{
//		char s[255] = "";
//		fgets(s, 254, fin);
//		for (int j = 0; j < strlen(s); j++)
//		{
//			for (int i = 0; i < 21; i++)
//			{
//				if ((s[j] == lett[i])||(s[j] == lett[i]-('a'-'A'))) count++;
//			}
//		}
//
//	}
//	printf("Количество согласных букв в файле %d", count);
//	return 0;
//}

/*6.2. Ввести с клавиатуры строку символов, состоящую из групп цифр и нулей, и записать ее в файл.Прочитать из файла данные и вывести 
на экран группы с четным количеством символов.*/
//#include <fstream>
//#include <iostream>
//using namespace std;
//void main()
//{
//    setlocale(LC_ALL, "Rus");
//    char s[50]; 
//    int len=0,count=0;
//
//    ofstream fout("A.txt");  
//    printf("Введите строку символов, состоящую из групп цифр и нулей");
//    gets_s(s);
//    fout << s; 
//    fout.close();
//
//
//    ifstream fin("A.txt");    
//    if (!fin.is_open())
//        cout << "файл не может быть открыт!\n";
//
//    fin.getline(s, 40);
//    int a=strlen(s);
//    s[a] = ' ';
//    for (int i = 0; i < a+1; i++)
//    {
//        if (s[i] == ' ') count++;
//    }
//    fin.close();
//
//    
//    ifstream fon("A.txt");
//    for (int i = 0; i < count; i++)
//    {
//        fon >> s;
//        if (strlen(s) %2==0) {
//            for (int i = 0; i < strlen(s); i++)
//            {
//                cout << s[i];
//            }
//            cout << endl;
//        }
//    }
//    fon.close();
//
//}

/*9.1. Скопировать из файла FILE1 в файл FILE2 все строки, начинающиеся на букву «С», расположенные между строками с номерами N1 и N2.
Определить количество слов в первой строке файла FILE2.*/
//#include <stdio.h>  
//#include <fstream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	int k,count=0,n,amount=0; FILE* fin, *fon;
//	fopen_s(&fin, "file1.txt", "rt");
//	ofstream fout1("ff3.txt");
//	printf("Введите параметры n1 и n2\n");
//	scanf_s("%d", &n);
//	scanf_s("%d", &k);
//	while (!feof(fin))
//	{
//		char s[255] = "";
//		fgets(s, 254, fin); 
//		if (count == 0) { 
//			k = strlen(s);
//			s[k] = ' ';
//			for (int i = 0; i < strlen(s); i++)
//				if (s[i] == ' ') amount++;
//		}
//			count++;
//		if ((count>=n)&&(count<=k)&&(s[0]=='C'))
//			fout1 << s;
//		
//	}
//	fclose(fin);
//	fout1.close();
//
//
//	printf("Количество слов в первой строке %d", amount);
//	return 0;
//}
/*9.2. Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в файл.Прочитать из файла данные и
вывести на экран порядковый номер слова минимальной длины.Посчитать количество символов в слове.*/
//#include <fstream>
//#include <iostream>
//using namespace std;
//void main()
//{
//    setlocale(LC_ALL, "Rus");
//    char s[50],shorw[50]; 
//    int len=1000,count=0;
//
//    ofstream fout("A.txt");  
//    printf("Введите строку символов, состоящую из групп цифр и нулей");
//    gets_s(s);
//    fout << s; 
//    fout.close();
//
//
//    ifstream fin("A.txt");    
//    if (!fin.is_open())
//        cout << "файл не может быть открыт!\n";
//
//    fin.getline(s, 40);
//    int a=strlen(s);
//    s[a] = ' ';
//    for (int i = 0; i < a+1; i++)
//    {
//        if (s[i] == ' ') count++;
//    }
//    fin.close();
//
//    
//    ifstream fon("A.txt");
//    for (int i = 0; i < count; i++)
//    {
//        fon >> s;
//        if (strlen(s) < len) {
//            len = strlen(s);
//            for (int j = 0; j < strlen(s); j++)
//                shorw[j] = s[j];
//        }
//    }
//    fon.close();
//
//
//    printf("Самое короткое слово ");
//    for (int i = 0; i < len; i++)
//    {
//        cout << shorw[i];
//    }
//
//}





/*13.1. Скопировать из файла FILE1 в файл FILE2 все строки, в которых более 2 слов.Определить номер слова, в котором больше всего
гласных букв.*/
//#include <stdio.h>  
//#include <fstream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	char lonw[50];
//	int k,count=0,n,amount=0,amountall=0,lon=0,numb;
//	FILE* fin;
//	fopen_s(&fin, "file1.txt", "rt");
//	ofstream fout1("ff3.txt");
//
//	while (!feof(fin))
//	{
//		char s[255] = "";
//		fgets(s, 254, fin);  
//		k = strlen(s);
//		s[k] = ' ';
//		amount = 0;
//		for (int i = 0; i < strlen(s); i++)
//			if (s[i] == ' ') {
//				amount++; amountall++;
//			}
//
//		if (amount>2)
//			fout1 << s;
//		
//	}
//	fclose(fin);
//	fout1.close();
//
//	ifstream fon("file1.txt");
//	char lett[] = {'a','e','i','o','u','y'};
//	for (int i = 0; i < amountall; i++)
//	{
//		count = 0;
//		fon >> lonw;
//		for (int l = 0; l < strlen(lonw); l++) {
//			for (int j = 0; j < 6; j++)
//			{
//				if ((lonw[l] == lett[j]) || (lonw[l] == lett[j] - ('a' - 'A'))) count++;
//			}
//		}
//		if (count > lon) {
//			numb = i+1; lon = count;
//		}
//
//	}
//
//	printf("Больше всего гласных букв в слове %d", numb);
//	return 0;
//}
/*13.2. Ввести с клавиатуры строку символов, состоящую из цифр и скобок, и записать ее в файл. Прочитать из файла данные, посчитать
и вывести количество скобок различного вида.*/


#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    setlocale(LC_ALL, "Rus");
    char s[50]; 
    int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;

    ofstream fout("A.txt");  
    printf("Введите строку символов, состоящую из групп цифр и нулей");
    gets_s(s);
    fout << s; 
    fout.close();


    ifstream fin("A.txt");    
    if (!fin.is_open())
        cout << "файл не может быть открыт!\n";


    fin.getline(s, 40);
    int a=strlen(s);
 
    for (int i = 0; i < a+1; i++)
    {
        if (s[i] == '(') c1++;
        if (s[i] == ')') c2++;
        if (s[i] == '[') c3++;
        if (s[i] == ']') c4++;
        if (s[i] == '{') c5++;
        if (s[i] == '}') c6++;
    }
    fin.close();

    



    printf("Всего скобки открываются %d раз и закрываются %d раз\n", c1+c3+c5, c2+c4+c6);
    printf("Скобки вида '()' открываются %d раз и закрываются %d раз\n", c1, c2);
    printf("Скобки вида '[]' открываются %d раз и закрываются %d раз\n", c3, c4);
    printf("Скобки вида '{}' открываются %d раз и закрываются %d раз\n", c5, c6);

}
