#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;
const int Maxm = 2e6+7;

int n, m, k, ans;
int du[Maxn], ver[Maxm], fir[Maxn], nex[Maxm];

struct Node
{
    int v, id;
    bool operator < (const Node &b) const
    {
        return v > b.v;
    }
} a[Maxn];

inline void read(int &x)
{
    char c;
    while(!isdigit((c=getchar())));
    x = c-'0';
    while(isdigit((c=getchar())))
        x = (x<<1)+(x<<3) + c-'0';
}

int main()
{
    // scanf("%d%d%d", &n, &m, &k);
    read(n); read(m); read(k);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i].v), a[i].id = i;
    for(int i = 1, x, y; i <= m; ++i)
    {
        // scanf("%d%d", &x, &y);
        read(x); read(y);
        ver[i] = y;
        nex[i] = fir[x];
        fir[x] = i;
        du[y]++;
    }
    sort(a+1, a+n+1);
    for(int i = 1, cnt = 0; i <= n; ++i)
    {
        if(du[a[i].id])
        {
            ans += a[i].v;
            if(++cnt == k) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
