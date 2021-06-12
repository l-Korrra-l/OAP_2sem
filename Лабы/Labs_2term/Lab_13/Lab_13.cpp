///*4.Ввести массивы А и В.В массив С перенести те элементы массива А, которые больше минимального элемента массива В.Массив С отсортировать по убыванию,
//используя алгоритмы сортировок : шейкерная сортировка, сортировка Шелла.*/
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//void swap(int a,int b)
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
//				swap(a[j - i], a[j]);
//			}
//}
//void shakerSort(int a[], int n)
//{
//	int i, j, t;
//	for (i = 0; i <= n / 2; i++,n--)
//	{
//		for (j = i; j < n-1; j++)
//			if (a[j] < a[j+1])
//			{
//				swap(a[j + i], a[j]);
//			}
//		for (j = n-1; j > i; j--)
//			if (a[j - 1] < a[j])
//			{
//				swap(a[j - i], a[j]);
//			}
//	}
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
//void ShellSort(int A[], int size)              
//{
//	int step, i, j, tmp;
//	for (step = 4; step > 0; step /= 2)
//		for (i = step; i < size; i++)
//			for (j = i - step; j >= 0 && A[j] < A[j + step]; j -= step)
//			{
//				//swap(A[j + step], A[j]);
//				int t = A[j + step];
//				A[j + step] = A[j];
//				A[j] = t;
//			}
//}
//
//int fill(int n, int a[])
//{
//	int min = 100;
//	srand(time(NULL));
//	for (int i = 0; i <n; i++)
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
//	for (int i = 1; i < n; i++)
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
//	for (int i = 0; i < sizeA; i++)
//	{	if (A[i] >= minB) C[j] = A[i];
//	cout << C[j] << "  ";
//	j++;
//    }
//	insertSort(C, j);   //	bubbleSort(A, size); 
//  /*  ShellSort(C, j);*/
//	print(j, C);
//}
