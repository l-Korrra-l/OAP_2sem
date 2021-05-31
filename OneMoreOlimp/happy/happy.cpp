#include <iostream>
#include <cstring>
using namespace std;
int f = 0;
int ff(int a)
{
	if (a > 0) return pow(2, a) + ff(a - 1);
	else return 0;
}
void dd(int a, int k)
{

	if (k <= a / 2) { f = f * 10 + 4;}
	else { f = f * 10 + 7; k = k - a / 2; };
	if (a>1) dd(a/2, k);
}
void main()
{
	int k,i;
	cin >> k;
	for (i = 0; i <= 1000; i++)
	{
		if ((k >= ff(i)) && (k <= ff(i + 1))) break;
	}
	dd(ff(i+1)-ff(i),k-ff(i));
	cout << f/10;
}