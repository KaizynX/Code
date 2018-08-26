#include <cstdio>
#include <iostream>
#include <algorithm>
// #define DEBUG

using namespace std;

const int Maxn = 150007;

int n;
int a[Maxn][2];
int p[100], tot;

inline void depart(int x)
{
    for(int i = 2; i*i <= x; ++i)
    {
        if(x%i == 0) p[++tot] = i;
        while(x%i == 0) x /= i;
    }
    if(x > 1) p[++tot] = x;
}

inline void erase(int i)
{
    swap(p[i], p[tot--]);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i][0], &a[i][1]);
    depart(a[1][0]);
    if(n == 1)
    {
        printf("%d\n", p[1]);
        return 0;
    }

    depart(a[1][1]);
    sort(p+1, p+tot+1);
    tot = unique(p+1, p+tot+1)-p-1;
#ifdef DEBUG
    for(int i = 1; i <= tot; ++i)
        printf("%d ", p[i]);
    putchar('\n');
#endif
    for(int i = 2, flag; i <= n; ++i)
    {
        flag = 0;
        for(int j = 1; j <= tot; ++j)
        {
            if(a[i][0]%p[j] && a[i][1]%p[j])
            {
                erase(j);
                j--;
            }
            else flag = 1;
        }
        if(!flag || !tot)
        {
            puts("-1");
            return 0;
        }
    }
    printf("%d\n", p[1]);
    return 0;
}
