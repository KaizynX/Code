#include <bits/stdc++.h>

using namespace std;

string n;

int main()
{
	cin >> n;
	for(char c : n)
	{
		if(c == '1') putchar('9');
		else if(c == '9') putchar('1');
		else putchar(c);
	}
	return 0;
}
