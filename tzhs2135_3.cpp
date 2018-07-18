#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int Maxn = 1e3 + 7;
 
int n, res[Maxn];
int a[Maxn], b[Maxn], m[Maxn], s[Maxn];
 
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    for(int i = 1; i <= n; ++i) scanf("%d", b+i);
	// init
	for(int i = 1; i <= n; ++i)
	{
		m[i] = min(a[i], b[i]);
		s[i] = i;
	}
	// sort
	for(int i = 1; i < n; ++i)
		for(int j = i+1; j <= n; ++j)
			if(m[i] > m[j])
			{
				swap(m[i], m[j]);
				swap(s[i], s[j]);
			}
	// order
	for(int i = 1, l = 0, r = n+1; i <= n; ++i)
		if(m[i] == a[s[i]]) res[++l] = s[i];
		else res[--r] = s[i];
	// calc
    int ta = 0, tb = 0;
    for(int i = 1; i <= n; ++i)
    {
        ta += a[res[i]];
        tb = max(tb, ta);
        tb += b[res[i]];
    }
    printf("%d\n%d", tb, res[1]);
    for(int i = 2; i <= n; ++i)
        printf(" %d", res[i]);
    return 0;
}
