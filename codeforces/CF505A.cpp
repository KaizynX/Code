#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, t[26];
char str[Maxn];

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	if(n == 1 || n > 26)
	{
		puts("Yes");
		return 0;
	}
	for(int i = 0; i < n; ++i)
		if(++t[str[i]-'a'] == 2)
		{
			puts("Yes");
			return 0;
		}
	puts("No");
	return 0;
}
