/*4.1. ���������� ����� fileA � ����� �������� �� ���� �����, ������ ������������� ����� ������� ��, ������� �������������.�������� ���� fileB, � 
������� �� ���� �� ���� �������� ����� � ���������� ������(��������� ������� ���������� �����).*/
//#include <stdio.h>
//#include <iostream>
//#include <ctime>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	errno_t err;           // errno_t ���������� � ��������������� ���������� ��� ����������� ��� ������ � ������ ������. 
//	FILE *f, *g;
//	int A[20]; int i, min, *s, amount=0;
//	err = fopen_s(&f, "fileA.txt", "r");
//	err = fopen_s(&g, "fileB.txt", "w+");
//
//
//	if (err != 0)
//	{                                         //������� perror() �������������� �������� ���������� ���������� ERRNO � ������ � ������� ���
//		perror("���������� ������� ����\n");  //������ �� ����������� ����� ������ � ����������, ��������� � ��������� �������.
//		return EXIT_FAILURE;            //������ EXIT_FAILURE ������������ ��� ����������� ���� ���������� ���������� ���-������.
//	}
//
//	while ((fscanf_s(f, "%d ", &s) != EOF))
//	{
//		if (!f) break;   
//		amount += 1;
//	}
//
//	int fsize = 0;
//	int gsize = 0; int turn;
//	for (i = 0;i<amount ; i++)
//	{
//		fseek(g, gsize, 0);
//		fseek(f, fsize, 0);
//		fscanf_s(f, "%d,\n", &A[i]);
//		if (i == 0)
//		{
//			fprintf(g, "%d ", A[i]);
//			if (A[i] >= 0) turn = 0;
//			else turn = 1;
//		}
//		else {
//			if (turn == 0) if    (A[i] >= 0)  {A[i]*=(-1); fprintf(g, "%d ", A[i]);turn = 1; }
//			               else               { fprintf(g, "%d ", A[i]); turn = 1; }
//			else           if (A[i] >= 0) { fprintf(g, "%d ", A[i]); turn = 0; }
//			               else               { A[i] *= -1; fprintf(g, "%d ", A[i]); turn = 0; }
//		}  
//		fsize = ftell(f);
//		gsize = ftell(g);
//	}
//	fclose(f);
//	fclose(g);
//
//	return 0;
//
//}





/*4.2. ���������� ����� f � ����� ����������� �����.�������� ���� g, ������������ �� f ���������� ������ ����� ������� ���������� �����,
��������� � ����������.*/
//#include <stdio.h>
//#include <iostream>
//#include <ctime>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//    errno_t err;           // errno_t ���������� � ��������������� ���������� ��� ����������� ��� ������ � ������ ������. 
//	FILE *f,*g;
//	int A[20]; int i,min,*s,amount;
//	err = fopen_s(&f, "f.txt", "w+");
//	err = fopen_s(&g, "g.txt", "w+");
//
//
//	if (err != 0)
//	{                                         //������� perror() �������������� �������� ���������� ���������� ERRNO � ������ � ������� ���
//		perror("���������� ������� ����\n");  //������ �� ����������� ����� ������ � ����������, ��������� � ��������� �������.
//		return EXIT_FAILURE;            //������ EXIT_FAILURE ������������ ��� ����������� ���� ���������� ���������� ���-������.
//	}
//
//     int fsize;
//	printf("������� ���������� �����");
//	std::cin >> amount;
//	srand(time(NULL));
//	for (i = 0; i < amount; i++)
//	{
//		fprintf(f, "%d,", rand() % 100 - 50);
//		fprintf(f, "\n");
//		fsize = ftell(f);
//		fseek(f, fsize, 0);
//	}
//
//
//    printf("������� �����-�����");
//	std::cin >> min;
//	int *mn = &min;
//
//
//	fsize = 0;
//	int gsize = 0;
//	for (i = 0; i < amount; i++)
//	{		
//		fseek(g, gsize, 0);
//		fseek(f, fsize, 0);
//		fscanf_s(f, "%d,\n", &A[i]);
//		if (A[i]  > min) fprintf(g, "%d ", A[i]); 
//		fsize = ftell(f);
//		gsize = ftell(g);
//	}
//	fclose(f); 
//	fclose(g);
//	
//	return 0;
//}






/*����*/
/*6.1. ���������� ����� fA � ������������ �����(������������� � �������������).���������� � ������� �� ����� ���������� ����� ���� �� ���, 
������� �������� ������ � ���������� ������������� ������ �����.*/

//#include <stdio.h>
//#include <iostream>
//#include <ctime>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	errno_t err;          
//	FILE *f;
//	int i,amount=0;
//	float min=100, s, ent, clo;
//	err = fopen_s(&f, "fA.txt", "r");
//
//
//	if (err != 0)
//	{                                         
//		perror("���������� ������� ����\n");  
//		return EXIT_FAILURE;            
//	}
//
//	printf("������� �����");
//	std::cin >> ent;
//
//	while ((fscanf_s(f, "%f ", &s) != EOF))
//	{
//		if (!f) break;   
//		amount += 1;
//
//	}
//
//
//	int fsize = 0;
//	for (i = 0;i<amount ; i++)
//	{
//		fseek(f, fsize, 0);
//		fscanf_s(f, "%f ", &s);
//		if (abs(s - ent) < min) {
//			min = abs(s - ent);
//			clo = s;
//		}
//		fsize = ftell(f);
//	}
//
//	printf("�������� ������� � %f ����� %f",ent,clo);
//
//	fclose(f);
//
//
//	return 0;
//}



/*6.2. ������� ��������� ���� F1 �� �����, ��� �� 6 �����, � �������� � ���� ����������.����������� � ���� F2 ������ ������ ������ �� F1.*/
//#include <iostream>
//#include <conio.h>
//using namespace std;
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int pr[10],first=0,gloc=0,floc=0,i=0;
//	long fsize;
//	char pd;
//	FILE *f,*g;
//	errno_t err;
//	err = fopen_s(&f, "F1.txt", "r");
//	err = fopen_s(&g, "F2.txt", "w");
//	if (err != 0)
//	{
//		perror("������ �������� a.txt");
//		return;
//	}
//	fseek(f, 0L, SEEK_END);
//	fsize = ftell(f);
//	fseek(f, 0L, SEEK_SET);
//	for (int k = 1; k <= fsize; k++)
//	{
//		fread((void*)&pd, sizeof(char), 1, f);
//		if ((pd == '.')&&(pr[i-1]!= ftell(f))) { pr[i] = ftell(f); i++; }
//	}
//	for (int j = 0; j < i; j++)
//	{
//		if ((j + 1) % 2 == 0)
//		{
//			fseek(f, pr[j-1], SEEK_SET);
//			for (int l = 0; l <= pr[j]-pr[j-1]-2; l++)
//			{
//				fseek(g, gloc, 0);
//				fread((void*)&pd, sizeof(char), 1, f);
//				fprintf(g, "%c", pd);
//				gloc = ftell(g);
//	
//			}
//		}
//	}
//	_getch();
//	fclose(f);
//	fclose(g);
//
//}

/*9.1. ���������� ����� fileA �  ����� �����, �������� ������� �����������.�������� ���� fileB, ������������ �� fileA ����������� 
��������� ��������� ������ � ���� �� �����.*/
//
//#include <stdio.h>
//#include <iostream>
//#include <ctime>
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	errno_t err;           // errno_t ���������� � ��������������� ���������� ��� ����������� ��� ������ � ������ ������. 
//	FILE *f, *g;
//	int A[20]; int i, min, *s, amount=0;
//	err = fopen_s(&f, "fileA1.txt", "r");
//	err = fopen_s(&g, "fileB1.txt", "w+");
//
//
//	if (err != 0)
//	{                                         //������� perror() �������������� �������� ���������� ���������� ERRNO � ������ � ������� ���
//		perror("���������� ������� ����\n");  //������ �� ����������� ����� ������ � ����������, ��������� � ��������� �������.
//		return EXIT_FAILURE;             //������ EXIT_FAILURE ������������ ��� ����������� ���� ���������� ���������� ���-������.
//	}
//
//	while ((fscanf_s(f, "%d ", &s) != EOF))
//	{
//		if (!f) break;   
//		amount += 1;
//	}
//
//	int fsize = 0, gsize = 0;
//	int j = 0;
//	for (i = 0;i<amount ; i++)
//	{
//		fseek(f, fsize, 0);
//		fscanf_s(f, "%d ", &A[j]); j++;
//		for (int k = 0; k < j; k++)
//		{
//			if ((A[j-1] == A[k])&&((j-1)!=k)) j--;
//		}
//		fsize = ftell(f);
//	}
//	for (i = 0; i < j; i++)
//	{
//		fprintf(g, "%d ", A[i]); 
//	}
//
//	fclose(f);
//	fclose(g);
//
//	return 0;
//
//}
/*9.2. ������� ��������� ���� F1 �� �����, ��� �� 4 �����, � �������� � ���� ����������.����������� �� ����� F1 � ���� F2 ������,
���������� �������� � ������� ������, ��� �������� �����.*/

//#include <iostream>
//#include <conio.h>
//using namespace std;
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int pr[10],first=0,gloc=0,floc=0,i=0,min;
//	long fsize;
//	char pd;
//	FILE *f,*g;
//	errno_t err;
//	err = fopen_s(&f, "F11.txt", "r");
//	err = fopen_s(&g, "F3.txt", "w");
//	if (err != 0)
//	{
//		perror("������ �������� a.txt");
//		return;
//	}
//	printf("������� ����������� ���������� ��������");
//	std::cin >> min;
//	fseek(f, 0L, SEEK_END);
//	fsize = ftell(f);
//	fseek(f, 0L, SEEK_SET);
//	pr[0] = 0; i++;
//	for (int k = 1; k <= fsize; k++)
//	{
//		fread((void*)&pd, sizeof(char), 1, f);
//		if ((pd == '\n')&&(pr[i-1]!= ftell(f))) { pr[i] = ftell(f); i++; }
//	}
//	for (int j = 1; j < i; j++)
//	{
//		if (pr[j]-pr[j-1]-1>min)
//		{
//			fseek(f, pr[j-1], SEEK_SET);
//			for (int l = 0; l <= pr[j]-pr[j-1]-2; l++)
//			{
//				fseek(g, gloc, 0);
//				fread((void*)&pd, sizeof(char), 1, f);
//				fprintf(g, "%c", pd);
//				gloc = ftell(g);
//	
//			}
//		}
//	}
//	_getch();
//	fclose(f);
//	fclose(g);
//
//}
/*16.1. ���� ��� ����� ����� ����� � ������� fileA � fileB.�������� ����� ���� � ������ fileC, ������� �������� ����� ��������� 
������ fileA � fileB.*/
//#include <stdio.h>
//#include <iostream>
//#include <ctime>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	errno_t err;          
//	FILE *f,*g,*c;
//	int i,sum=0,s;
//	err = fopen_s(&f, "fileA.txt", "r");
//	err = fopen_s(&g, "fileB.txt", "r");
//	err = fopen_s(&c, "fileC.txt", "w");
//
//	if (err != 0)
//	{                                         
//		perror("���������� ������� ����\n");  
//		return EXIT_FAILURE;            
//	}
//
//
//	while ((fscanf_s(f, "%d ", &s) != EOF))
//	{
//		if (!f) break;   
//		sum += s;
//	}
//	while ((fscanf_s(g, "%d ", &s) != EOF))
//	{
//		if (!g) break;
//		sum += s;
//	}
//
//	fprintf(c,"����� ��������� 2 ������ %d",sum);
//	fclose(f);
//	fclose(g);
//	fclose(c);
//
//	return 0;
//}
/*16.2. ���������� ����� file1 �  ����� �����������(�������� �� ����) �����, ������ ������� ��������  5 ������������� �����, ����� 
5 �������������, � �.�.�������� ���� file2, � ������� �������� ����� �� ����� file1, ������� 10 ������������� �����, ����� 10 
������������� � �.�.*/
//#include <stdio.h>
//#include <iostream>
//#include <ctime>
//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	errno_t err;          
//	FILE *f,*g,*c;
//	int i,i1,sum=0,s,A[100],A1[100];
//	err = fopen_s(&f, "dd.txt", "r");
//	err = fopen_s(&g, "file2.txt", "w");
//
//	if (err != 0)
//	{                                         
//		perror("���������� ������� ����\n");  
//		return EXIT_FAILURE;            
//	}
//
//	i = 0; i1 = 0;
//	while ((fscanf_s(f, "%d ", &s) != EOF))
//	{
//		if (!f) break;   
//		if (s > 0) { A[i] = s; i++; }
//		else { A1[i1] = s; i1++; }
//		
//	}
//	int a = i + i1 - 1;
//	i = 0; i1 = 0; 
//	int last = 19, mid = 9, first = 0, gloc=0;
//	for (int k = 0; k < a; k++)
//	{
//		if ((k>=first)&&(k <= mid)) { fseek(g, gloc, 0); fprintf(g, "%d ", A[i]); i++; 	gloc = ftell(g);
//		}
//		else if ((k <= last)&&(k>=mid)) {
//			fseek(g, gloc, 0);
//			fprintf(g, "%d ", A1[i1]); i1++;
//			gloc = ftell(g);
//		}
//		if (k==last) { last += 20; mid += 20; first += 20; }
//	}
//
//	fclose(f);
//	fclose(g);
//
//	return 0;
//}