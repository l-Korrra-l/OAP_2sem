///*5.Ввести массивы А и В.В массив С перенести элементы массива А с четным значением и элементы массива В с нечетным значением.Массив С отсортировать
//по возрастанию, используя алгоритмы сортировок : «пузырек», сортировка выбором.*/
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
//void selectSort(int A[], int size)
//{
//	int k, i, j;
//	for (i = 0; i < size - 1; i++)
//	{
//		for (j = i + 1, k = i; j < size; j++)
//			if (A[j] < A[k])
//				k = j;
//		int c = A[k];
//		A[k] = A[i];
//		A[i] = c;
//	}
//}
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
//	for (int i = 0; (i < sizeA)||(i<sizeB); i++)
//	{
//		if ((A[i] %2==0)&& (i < sizeA))
//		{C[j] = A[i];
//		cout << C[j] << "  ";
//		j++; }
//		if ((B[i] % 2 != 0)&& (i < sizeB))
//		{C[j] = B[i];
//		cout << C[j] << "  ";
//		j++; }
//	}
///*	selectSort(C, j);  */ 
//	bubbleSort(C, j); 
//	print(j, C);
//}
