#include <iostream>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

double qwerty(int m, int n)
{
	int f;
	if ((m + n) % 2 == 0)
		if (m > n)
			return m;
		else
			return n;
	else
	{
		f = qwerty((n + m + 1) / 2, n + 1) + qwerty(m, (n + m + 1) / 2);
		return f;
	}
}

int main()
{
	int m, n;
	cout << "m = ";
	cin >> m;
	cout << "n = ";
	cin >> n;
	cout << "answer: " << qwerty(m, n) << endl;
	system("pause");
	return 0;
}