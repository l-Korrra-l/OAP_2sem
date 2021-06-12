#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main()
{
	int a = 1300, b = 1400, c = 1500;
	int i, j,k, aa=0;
	i = sqrt(a) + 1;
	j = sqrt(b) + 1;
    double l =  j * j - i * i;
	for ( k = 10; k <= 110- j * j + i * i; k++,l+=2)
	{
		double ff = (int)sqrt(l) * (int)sqrt(l);
		if ((k + j*j <= i * i + 110) && (l == ff)) aa = k + j * j;
	}
	cout << aa;
	return 0;
}