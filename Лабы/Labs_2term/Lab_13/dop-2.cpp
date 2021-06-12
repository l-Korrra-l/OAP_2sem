///*7.Ввести массивы А и В.В массив С перенести четные элементы массива А и нечетные элемента массива В.Массив С отсортировать по убыванию, 
//используя алгоритмы сортировок : «пузырек», сортировка Хоара.*/
//#include <ctime>
//#include <iostream>
//using namespace std;
//
//void swap(int a, int b)
//{
//	int t = a;
//	a = b;
//	b = a;
//}
//void bubbleSort(int a[], int n)
//{
//	int i, j, t;
//	for (i = 1; i < n; i++)
//		for (j = n - 1; j >= i; j--)
//			if (a[j - 1] < a[j])
//			{
//				t = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = t;
//			}
//}
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
//
//
//
//int fill(int n, int a[])
//{
//	int min = 100;
//	srand(time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 50;
//		if (a[i] < min) min = a[i];
//		cout << a[i] << "  ";
//	}
//	return min;
//}
//
//void print(int n, int a[])
//{
//	cout << "\nРезультирующий массив: ";
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << "  ";
//	}
//	cout << endl;
//}
//void main()
//{
//	setlocale(LC_ALL, "Rus");
//	int sizeA, sizeB, minB;
//	int A[100], B[100], C[100];
//	cout << "\nКоличество элементов массива А = ";
//	cin >> sizeA;  
//	fill(sizeA, A);
//
//	cout << "\nКоличество элементов массива В = ";
//	cin >> sizeB;
//	minB = fill(sizeB, B);
//
//	cout << "\n";
//	int j = 0;
//	for (int i = 0; (i < sizeA) || (i < sizeB); i++)
//	{
//		if ((A[i] % 2 == 0) && (i < sizeA))
//		{
//			C[j] = A[i];
//			cout << C[j] << "  ";
//			j++;
//		}
//		if ((B[i] % 2 != 0) && (i < sizeB))
//		{
//			C[j] = B[i];
//			cout << C[j] << "  ";
//			j++;
//		}
//	}
//	sortHoar(C, 0, j-1);
//		//bubbleSort(C, j); 
//	print(j, C);
//}
