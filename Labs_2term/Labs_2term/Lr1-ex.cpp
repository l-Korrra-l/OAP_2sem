//#include <stdio.h>
//#include <iostream>
//int main()
//{
//	setlocale(LC_ALL, "");
//	int a; errno_t err;           // errno_t ���������� � ��������������� ���������� ��� ����������� ��� ������ � ������ ������. 
//	FILE *f;
//	err = fopen_s(&f, "a.txt", "w");
//	if (err != 0)
//	{                                         //������� perror() �������������� �������� ���������� ���������� ERRNO � ������ � ������� ���
//		perror("���������� ������� ����\n");  //������ �� ����������� ����� ������ � ����������, ��������� � ��������� �������.
//		return EXIT_FAILURE;            //������ EXIT_FAILURE ������������ ��� ����������� ���� ���������� ���������� ���-������.
//	}
//	for (a = 0; a < 70; a += 3)
//	{
//		fprintf(f, "%d, ", a);
//	}
//	printf("������ �������� � ���� a.txt\n");
//	fclose(f);
//	return 0;
//}

//#include <iostream>
//#include <stdio.h> 
//#include <conio.h>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	FILE *mf; char str[50];   errno_t err;
//	char *estr;
//	printf("������� ����� ");   gets_s(str);
//	fopen_s(&mf, "tst.txt", "w");       //�������� ��� ������
//	fputs(str, mf); fputs("\n", mf);
//	fclose(mf);
//	err = fopen_s(&mf, "tst.txt", "r");  //�������� ��� ������
//	if (err != NULL)                 //�������� �������� �����
//	{
//		printf("������ �������� �����\n"); return -1;
//	}
//	else
//		printf("\n������� ������:\n");
//	estr = fgets(str, sizeof(str), mf); //������ ������ �����      
//	if (estr == NULL)         //����� ����� ��� ������ ������?
//		if (feof(mf) != 0)
//			printf("\n������ ����� ���������\n");
//		else
//		{
//			printf("\n������ ������ �� �����\n");
//			return -1;
//		}
//	puts(str);
//	if (fclose(mf) == EOF)
//		printf("������ ��������\n");
//	_getch();
//	return 0;
//
//}


//#include <iostream>   
//#include <stdio.h>  
//#include <conio.h>
//int main(void)
//{
//	setlocale(LC_CTYPE, "Russian");
//	FILE *fp;
//	errno_t err;
//	char const *st = "hello";
//	char read[10];
//	err = fopen_s(&fp, "a.bin", "w");
//	if (err != 0)
//	{
//		perror("������ �������� a.txt");
//		return EXIT_FAILURE;
//	}
//	fwrite(st, strlen(st), 1, fp);
//	printf("������� �������\n");
//	fgets(read, strlen(st),fp);
//	 puts(read);
//	fclose(fp);
//	_getch();
//	return 0;
//}

//
//#include <iostream>
//#include <conio.h>
//using namespace std;
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int m = 0, number = 0, pr = 0;
//	long fsize;
//	char pd;
//	FILE *fd;
//	errno_t err;
//	err = fopen_s(&fd, "b.txt", "r");
//	if (err != 0)
//	{
//		perror("������ �������� a.txt");
//		return;
//	}
//	fseek(fd, 0L, SEEK_END);
//	fsize = ftell(fd);
//	fseek(fd, 0L, SEEK_SET);
//	printf("������� ����� ����������� ");
//	scanf_s("%d", &number);
//	_getch();
//	for (int k = 1; k <= fsize; k++)
//	{
//		fread((void*)&pd, sizeof(char), 1, fd);
//		if (pd == '.')   pr++;
//		if ((number - 1) == pr)  m++;
//		if (number == pr)
//		{
//			long pos1 = k - m - 1;
//			if (number != 1) pos1++;
//			fseek(fd, pos1, SEEK_SET);
//			printf("%d-� �����������: ", number);
//			for (int i = 0; i <= m; i++)
//			{
//				fread((void*)&pd, sizeof(char), 1, fd);
//				printf("%c", pd);
//			}
//			break;
//		}
//	}
//	if (number > pr)
//		printf("������ ������ ���");
//_getch();
//	fclose(fd);
//	
//}
