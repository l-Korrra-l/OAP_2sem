#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void main()
{
	string s;
	getline(cin, s);
	int l, lett = 0, coin = 0, n;
	char* ps;
	bool ifr = false;
	l = 0;
	s += ' ';

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			n = l;
			for (int j = i; j < s.size(); j++)
			{

				if (s[j] == s[n]) coin++;
                lett++; n++;
				if (s[j] == ' ')
				{
					if ((lett == coin)&&(lett!=1)) ifr = true;
					n = l; lett = 0; coin = 0;
				}
				
			}
		l = i + 1;
		}

	}
	if (ifr == true)
		puts("no\n");
	else
		puts("yes\n");
}
