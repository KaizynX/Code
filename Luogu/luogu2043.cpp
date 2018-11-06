#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e4+7;

int n;
int p[Maxn], tot, c[Maxn], k[Maxn];

inline void prime(int N)
{
    for(int i = 2; i <= N; ++i)
    {
        if(!c[i]) p[++tot] = i;
        for(int j = 1; j <= tot && i*p[j] <= N; ++j)
        {
            c[i*p[j]] = 1;
            if(i%p[j] == 0) break;
        }
    }
}

inline void f(int x)
{
    for(int i = 1; i <= tot && p[i] <= x; ++i)
        for(; x%p[i] == 0; x /= p[i], k[i]++);
}

int main()
{
    scanf("%d", &n);
    prime(n);
    for(int i = 1; i <= n; ++i) f(i);
    for(int i = 1; i <= tot; ++i)
        if(k[i]) printf("%d %d\n", p[i], k[i]);
    return 0;
}
