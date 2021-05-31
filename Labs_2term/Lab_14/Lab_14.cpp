///*4. В соответствии со своим вариантом написать программу для сортировок массивов указанными в таблице методами.Исходные массивы 
//заполняются случайными числами.
//Определить зависимость времени выполнения алгоритмов от количества элементов для каждого из алгоритмов.Выполнить моделирование для 
//массивов размером 1000, 2000, 3000, 4000, 5000 (в зависимости от быстродействия компьютера размеры массивов можно увеличивать).
//Произвести сравнение эффективности алгоритмов(построить график в приложении Excel).
//4	Сортировка Хоара, пирамидальная сортировка, сортировка слиянием*/
//#include <iostream>
//#include <ctime>
//using namespace std;
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
////------------------------------------------------------
//void heapify(int A[], int pos, int n)
//{
//	int t, tm;
//	while (2 * pos + 1 < n)
//	{
//		t = 2 * pos + 1;
//		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
//			t = 2 * pos + 2;
//		if (A[pos] < A[t])
//		{
//			tm = A[pos];
//			A[pos] = A[t];
//			A[t] = tm;
//			pos = t;
//		}
//		else break;
//	}
//}
//void piramSort(int A[], int n)
//{
//	for (int i = n - 1; i >= 0; i--)
//		heapify(A, i, n);
//	while (n > 0)
//	{
//		int tm = A[0];
//		A[0] = A[n - 1];
//		A[n - 1] = tm;
//		n--;
//		heapify(A, 0, n);
//	}
//}
////--------------------------------------------------
//void insOrd(int m[], int sm, int em, int e)
//{ 
//	int buf;
//	int i = sm;
//	while (i <= em && m[i] < e)
//	{
//		if (i - 1 >= sm)
//			m[i - 1] = m[i];
//		i++;
//	}  m[i - 1] = e;
//}
//int* merge(int m[], int sm, int cm, int em)
//{
//	for (int i = 0; i <= sm; i++)
//	{
//		if (m[i] > m[cm + 1])
//		{
//			int buf = m[i];
//			m[i] = m[cm + 1];
//			insOrd(m, cm + 1, em, buf);
//		}
//	}
//	return m;
//}
//int* sortMerge(int m[], int lm, int sm = 0)
//{
//	if (lm > 1)
//	{
//		sortMerge(m, lm / 2, sm);
//		sortMerge(m, lm - lm / 2, sm + lm / 2);
//		merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
//	};
//	return m;
//}
//
//int fill(int n, int a[])
//{
//	int min = 100;
//	srand(time(NULL));
//	for (int i = 0; i <n; i++)
//	{
//		a[i] = rand() % 50;
//		cout << a[i] << "  ";
//	}
//	return min;
//}
//
//void print(int n, int a[], int b=0)
//{
//	int i = 0;
//	if (b == 1) { i++; n++; }
//	cout << "\nРезультирующий массив: ";
//	for ( i ; i < n; i++)
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
//		cout << "sortHoar:";
//        fill(n, B);
//		sortHoar(B,0,n);
//		print(n, B,1);
//		cout << endl;
//
//		cout << "sortMerge:";
//		fill(n, B);
//		sortMerge(B, n);
//		print(n, B);
//		cout << endl;
//
//		cout << "piramSort:";
//		fill(n, B);
//		piramSort(B, n);
//		print(n, B);
//		cout << endl;
//	
//	return 0;
//}
