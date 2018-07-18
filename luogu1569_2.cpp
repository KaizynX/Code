#include <iostream>
#include <cstdio>
#define DEBUG

using namespace std;

const int Maxn = 1007;
const int INF = 0x3f3f3f3f;

int n;
int s[Maxn];
int f[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1, a; i <= n; ++i)
	{
		scanf("%d", &a);
		s[i] = s[i-1] + a;
		if(s[i] >= 0) f[i] = 1;
	}
	if(s[n] < 0) 
	{
		puts("Impossible");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j < i; ++j)
			if(f[j] && s[i] - s[j] >= 0)
				f[i] = max(f[i], f[j] + 1);
	printf("%d\n", f[n]);
	return 0;
}
