#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e6+7;

int n, m, r[Maxn];
int d[Maxn], s[Maxn], t[Maxn];
int cur, a[Maxn];

inline void read(int&);
inline bool check(int mid)
{
    while(cur < mid)
    {
        ++cur;
        a[s[cur]] += d[cur];
        a[t[cur]+1] -= d[cur];
    }
    while(cur > mid)
    {
        a[s[cur]] -= d[cur];
        a[t[cur]+1] += d[cur];
        --cur;
    }
    for(int i = 1, tmp = 0; i <= n; ++i)
    {
        tmp += a[i];
        if(r[i] < tmp) return false;
    }
    return true;
}

int main()
{
    read(n); read(m);
    for(int i = 1; i <= n; ++i) read(r[i]);
    for(int i = 1; i <= m; ++i) read(d[i]), read(s[i]), read(t[i]);
    int l = 1, r = m, mid;
    while(l < r)
    {
        mid = (l+r) >> 1;
        if(check(mid)) l = mid+1;
        else r = mid;
    }
    if(l >= m && check(m)) puts("0");
    else printf("-1\n%d\n", l);
    return 0;
}

inline void read(int &x)
{
    char c;
    while((c=getchar()) < '0' || c > '9');
    x = c-'0';
    while((c=getchar()) >= '0' && c  <= '9')
        x = (x<<1)+(x<<3) + c-'0';
}
