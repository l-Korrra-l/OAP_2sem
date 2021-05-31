///*2. Дан массив целых чисел, количество элементов которого надо ввести с клавиатуры.Найти максимальный элемент массива и его номер, при 
//условии, что все элементы различны.Найти минимальный элемент массива.*/
//#include <iostream>
//#include <ctime>
//using namespace std;
//void fill(int n, int a[])
//{
//	int min = 100, minn, maxn, max=-50;
//	srand(time(NULL));
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 100-50;
//		cout << a[i] << "  ";
//		if (a[i] <= min) { min = a[i]; minn = i; }
//		if (a[i] >= max) { max = a[i]; maxn = i; }
//	}
//	cout << "\n   Max element = " << max << "\tposition = " << maxn;
//	cout << "\n   Min element = " << min << "\tposition = " << minn;
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
//	fill(n, B);
//	cout << endl;
//
//	return 0;
//}