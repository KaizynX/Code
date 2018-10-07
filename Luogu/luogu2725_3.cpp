#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 60;
const int Maxv = 2e6+1;

int n, k;
int a[Maxn];
int f[Maxv];

int main()
{
	int maxa = 0, maxv;
    scanf("%d%d", &k, &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", a+i);
		maxa = max(maxa, a[i]);
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	maxv = maxa*k;
    for(int i = 0; i < n; ++i)
    {
		for(int j = a[i]; j <= maxv; ++j)
			if(f[j-a[i]]+1 <= k)
				f[j] = min(f[j], f[j-a[i]]+1);
    }
    for(int i = 1; i <= maxv+1; ++i)
        if(f[i] > k)
        {
            printf("%d\n", i-1);
            break;
        }
    return 0;
}
