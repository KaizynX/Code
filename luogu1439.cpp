#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1e5 + 7;

int n;
// int a[Maxn], b[Maxn];
int pos[Maxn], map[Maxn];
int len, cot[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1, tmp; i <= n; ++i) // read arr a
	{
		scanf("%d", &tmp);           // scanf("%d", a+i);
		pos[tmp] = i;                // num i in a's pos
	}
	for(int i = 1, tmp; i <= n; ++i) // read arr b
	{
		scanf("%d", &tmp);           // scanf("%d", b+i);
		map[i] = pos[tmp];           // b[i] == a[ map[i] ]
	}
	cot[++len] = map[1];
	for(int i = 2; i <= n; ++i)
	{
		if(map[i] > cot[len]) cot[++len] = map[i];
		else
		{
			// find cot[] > map[i]
			*(upper_bound(cot+1, cot+len, map[i])) = map[i];
		}
	}
	printf("%d\n", len);
	return 0;
}

