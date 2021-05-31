#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int arr[6];
void numb(int a, int i)
{

	arr[i] = a % 10;
	if (i>0) numb(a / 10, i - 1);

}
bool ifdiff(int a)
{
	bool ifi = true;
	for (int i = 0; i < 6; i++)
	{
		if ((arr[i] == 0) || (a % arr[i] != 0)) {
			ifi = false; break;
		}
	for (int j = i+1; j < 6; j++)
	{
		if (arr[i] == arr[j]) { ifi = false; break; }
	}
	}
	return ifi;
}
int main()
{
	string s;
	int fst, lst, num=0;


	getline(cin, s);

	fst = stoi(s);
	lst = atoi(s + 7);

	for (int i = fst; i <= lst; i++)
	{
		numb(i,5);
		if (ifdiff(i)) num++;
	}
	cout << num;
	return 0;
}