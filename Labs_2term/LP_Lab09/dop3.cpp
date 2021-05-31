//
////3. ƒано n различных натуральных чисел(n = 5).Ќапечатать все перестановки этих чисел.
//#include <iostream>
//using namespace std;
//int a, A[] = { 1,2,3,4,5,6,7 };
//int factorial(int numb) {
//	if (numb == 0) {
//		return 1;
//	}
//	else {
//		int	value = factorial(numb - 1);
//		return  numb * value;
//	}
//}
//
//void print()
//{
//	printf("\n");
//	for (int i = 0; i < a; i++)
//		printf("%d", A[i]);
//};
//
//int func(int m)
//{
//
//	int n;
//	for (int j = 0; j < m; j++)
//	{
//		if ((m <= 2) && (m > 0))
//		{
//			int n = A[a - 2];
//			A[a - 2] = A[a - 1];
//			A[a - 1] = n;
//			//	 print();
//		}
//		else {
//			int n = A[a - m];
//			for (int i = a - m; i < a - 1; i++)
//				A[i] = A[i + 1];
//			A[a - 1] = n;
//			print();
//			func(m - 1);
//
//		};
//		print();
//	}
//
//	return 0;
//}
//int main()
//{
//	int m;
//	cout << "Enter a number: ";
//	//cin >> m;
//	m = 5;
//	a = m;
//	func(m);
//	system("pause");
//}
