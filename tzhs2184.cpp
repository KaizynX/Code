#include <algorithm>
#include <iostream>
#include <cstdio>
#define DEBUG

using namespace std;

const int Maxn = 1e6+7;

struct Node
{
    int v, index;
    bool operator < (const Node &b) const
    {
        return v < b.v;
    }
}a[Maxn];

int n, ans, b[Maxn], last[Maxn];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].v);
        a[i].index = i;
    }
    sort(a+1, a+n+1);
    a[0].v = -1;
    for(int i = 1, cnt = 0; i <= n; ++i)
    {
        if(a[i].v != a[i-1].v) ++cnt;
        b[a[i].index] = cnt;
    }
#ifdef DEBUG
    for(int i = 1; i <= n; ++i) printf("%d ", b[i]);
    putchar('\n');
#endif
    for(int i = 1, start = 0; i <= n; ++i)
    {
        if(last[b[i]] && start < last[b[i]])
        {
            start = last[b[i]];
            // ans = max(ans, i - start);
        }
        else
        {
            ans = max(ans, i - start);
        }
        last[b[i]] = i;
    }
    printf("%d\n", ans);
    return 0;
}
