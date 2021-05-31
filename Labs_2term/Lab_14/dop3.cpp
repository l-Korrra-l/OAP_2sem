///*4. Дан массив из 15 целых чисел на отрезке [-5; 5]. Упорядочить массив, удалив повторяющиеся элементы.*/
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int getHoarBorder(int A[], int sm, int em)
//{
//	int i = sm - 1, j = em + 1;
//	int brd = A[sm];
//	int buf;
//	while (i < j)
//	{
//		while (A[--j] > brd);
//		while (A[++i] < brd);
//		if (i < j)
//		{
//			buf = A[j];
//			A[j] = A[i];
//			A[i] = buf;
//		};
//	}
//	return j;
//}
//int* sortHoar(int A[], int sm, int em)
//{
//	if (sm < em)
//	{
//		int hb = getHoarBorder(A, sm, em);
//		sortHoar(A, sm, hb);
//		sortHoar(A, hb + 1, em);
//	}
//	return A;
//};
//
//int repeat(int A[], int n)
//{
//	for (int i = 0; i < n; i++)
//		for (int j = i+1; j < n; j++)
//		{
//			if (A[i] == A[j])
//			{
//				for (int k = j; k < n - 1; k++)
//					A[k] = A[k + 1];
//				n--;
//				j--;
//			}
//		}
//	return n;
//}
//
//void fill(int n, int a[])
//{
//	srand(time(NULL));
//	cout << "\nИсходный массив: ";
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 10-5;
//		cout << a[i] << "  ";
//	}
//}
//
//void print(int n, int a[])
//{
//	cout << "\nРезультирующий массив: ";
//	for (int i=0; i < n; i++)
//	{
//		cout << a[i] << "  ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int n;
//	int B[100];
//	clock_t  t1, t2;
//	cout << "Enter array length: "; cin >> n;
//
//
//	cout << "sortHoar:";
//	fill(n, B);
//	n=repeat(B,n);
//	print(n, B);
//    sortHoar(B, 0, n-1);
//	print(n, B);
//	cout << endl;
//
//	return 0;
//}
