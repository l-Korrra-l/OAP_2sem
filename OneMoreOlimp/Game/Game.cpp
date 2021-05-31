#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int arr[3] = { 1,0,0 };
int A(int a)
{
	if (a == 1) return 2;
	else if (a == 2) return 1;
	else return a;
}
int B(int a)
{
	if (a == 3) return 2;
	else if (a == 2) return 3;
	else return a;
}
int C(int a)
{
	if (a == 1) return 3;
	else if (a == 3) return 1;
	else return a;
}
int main()
{
	string s;

	getline(cin, s);
	int numb = 1;
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case 'A':numb = A(numb); break;
		case 'B':numb = B(numb); break;
		case 'C':numb = C(numb); break;
		}

	}
	cout << numb;
	return 0;
}