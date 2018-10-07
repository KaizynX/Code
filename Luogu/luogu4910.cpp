#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 1e9+7;

int T, n;
int f[Maxn];

inline void init()
{
	f[0] = f[1] = 1;
	for(int i = 2; i < Maxn; ++i)
		f[i] = (f[i-1]+f[i-2])%MOD;
}

int main()
{
	init();
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		if(n == 1) puts("1");
		else if(n == 2) puts("3");
		else if(n == 3) puts("4");
		else if(n == 4) puts("7");
		else printf("%d\n", (f[n+1]-f[n-3]+MOD)%MOD);
	}
	return 0;
}
