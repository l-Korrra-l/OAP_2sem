///*1.Ввести массив А, в массив В скопировать все элементы массива А, имеющие четный индекс.Массив В отсортировать по убыванию, используя алгоритмы 
//сортировок : «пузырек», сортировка простой вставкой.*/
//#include <iostream>
//#include <ctime>
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
//			if (a[j - 1] > a[j])
//			{
//				t = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = t;
//			}
//}
//
//void insertSort(int* A, int size)
//{
//	int t, i, j;
//	for (i = 1; i < size; i++)
//	{
//		t = A[i];
//		for (j = i - 1; j >= 0 && A[j] > t; j--)
//			A[j + 1] = A[j];
//		A[j + 1] = t;
//	}
//}
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
//
//	cout << "\n";
//	int j = 0;
//	for (int i = 0; i < sizeA; i+=2,j++)
//	{
//		B[j] = A[i];
//			cout << B[j] << "  ";
//	}
//	insertSort(B, j);
//	//	bubbleSort(B, j); 
//	print(j, B);
//}
