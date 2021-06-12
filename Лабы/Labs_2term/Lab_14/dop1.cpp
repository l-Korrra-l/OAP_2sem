///*3. Дан массив из 10 элементов.Первые 4 элемента упорядочить по возрастанию, последние 4 по убыванию.*/
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
//int getHoarBordermm(int A[], int sm, int em)
//{
//	int i = sm - 1, j = em + 1;
//	int brd = A[sm];
//	int buf;
//	while (i < j)
//	{
//		while (A[--j] < brd);
//		while (A[++i] > brd);
//		if (i < j)
//		{
//			buf = A[j];
//			A[j] = A[i];
//			A[i] = buf;
//		};
//	}
//	return j;
//}
//int* sortHoarmm(int A[], int sm, int em)
//{
//	if (sm < em)
//	{
//		int hb = getHoarBordermm(A, sm, em);
//		sortHoarmm(A, sm, hb);
//		sortHoarmm(A, hb + 1, em);
//	}
//	return A;
//};
//
//int fill(int n, int a[])
//{
//	int min = 100;
//	srand(time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 50;
//		if ((i == 4) || (i == n - 4)) cout << "|";
//		cout << a[i] << "  ";
//	}
//	return min;
//}
//
//void print(int n, int a[])
//{
//	cout << "\nРезультирующий массив: ";
//	for (int i=0; i < n; i++)
//	{
//		if ((i == 4)||(i==n-4)) cout << "|";
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
//	sortHoar(B, 0, 4);
//	sortHoarmm(B, n-4, n);
//	print(n, B);
//	cout << endl;
//
//	return 0;
//}
