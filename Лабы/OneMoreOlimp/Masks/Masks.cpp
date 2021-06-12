#include <stdio.h>
# include <cstring>
void main()
{
	char s[20];
	int l,lett=0,coin=0,n;
	char* ps, *pi;
	bool ifr = false;
	puts("Enter string: ");
	gets_s(s);
	l = 0; 
	ps = s; pi = s;
	for (int i=0; i<strlen(s); i++)
	{
		if (i == ' ')
		{
			n = l;
			for (int j=l; j< strlen(s); j++)
			{
				
				if (*(ps + j) == *(ps + n)) coin++;
				if (*(ps + j) == ' ')
				{
					if (lett == coin) ifr = true;
					n = l; lett = 0; coin = 0;
				}
                 lett++; n++;
			}
		}
		l = i+1;
	}
	if (ifr==true)
		puts("no\n");
	else
		puts("yes\n");
}
