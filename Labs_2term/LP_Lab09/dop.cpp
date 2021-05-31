#include <iostream>
using namespace std;
int fill(int* Array, int i, int size)
{
	if (i <= i)
	{
		Array[i] = i;
		i++;
		fill(Array,i,size);
		if (i > size) return *Array;
	}
}
int fact(int numb) {
	if (numb == 0) {
		return 1;
	}
	else {
		int	value = fact(numb - 1);
		return  numb * value;
	}
}


void main()
{
	int a, n, size;
	cout << "Enter a number: "; cin >> n;
	size = fact(n);
	int* Array = new int[size];

	fill(Array, n, size);
	for (int i = 0; i <= size; i++)
		cout << Array[i] << "\t  ";
}