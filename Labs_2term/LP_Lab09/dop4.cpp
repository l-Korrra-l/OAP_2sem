////4. По заданному числу n определить символ, который стоит на n - ом месте последовательности, получившейся после шага c номером 26.
#include <iostream>
using namespace std;
int a, A[] = { 1,2,3,4,5,6,7,8,9,10 };

int func(int m,int n)
{
	m += m;
	if (m > sizeof(A)/sizeof(int)) m -=26;
	if (n < 26) func(m,n+1);

	return m;
}
int main()
{
	int m;
	int n = 0;
	cout << "Enter a number: ";
	cin >> m;
	m=func(m,n);
	cout << A[m-1];
	system("pause");
}