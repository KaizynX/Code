#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e3+7;
const int Maxm = 5e5+7;

int n, m, k, tot, rk[Maxn], num[Maxn];
long long res[Maxm];

struct Line
{
    long long k, b, y;
    inline bool operator < (const Line &nex) const { return y < nex.y; }
} l[Maxn];

struct Point
{
    int x, y;
    long long p;
    bool operator < (const Point &b) const { return p == b.p ? x < b.x : p < b.p; }
} s[Maxn*Maxn];

struct Query
{
    int id;
    long long x;
    bool operator < (const Query &b) const { return x < b.x; }
} q[Maxm];

template <typename T> inline void read(T &);
template <typename T> void put(T);
inline long long calc(Line a, long long x) { return a.k*x+a.b; }
inline long long jd(Line a, Line b) { return (b.b-a.b)/(a.k-b.k)+1; }

int main()
{
    read(n); read(m); read(k);
    for(int i = 1; i <= n; ++i)
    {
        read(l[i].k);
        read(l[i].b);
    }
    for(int i = 1; i <= m; ++i)
    {
        read(q[i].x);
        q[i].id = i;
    }
    sort(q+1, q+m+1);
    for(int i = 1; i <= n; ++i) l[i].y = calc(l[i], q[1].x);
    sort(l+1, l+n+1);
    for(int i = 1; i <= n; ++i)
    {
        num[i] = rk[i] = i;
        for(int j = i+1; j <= n; ++j)
            if(l[i].k != l[j].k && calc(l[i], q[m].x) >= calc(l[j], q[m].x))
            {
                long long d = jd(l[i], l[j]);
                if(d >= q[1].x)
                {
                    s[++tot].x = i;
                    s[tot].y = j;
                    s[tot].p = d;
                }
            }
    }
    sort(s+1, s+tot+1);
    for(int i = 1, id = 1; i <= m; ++i)
    {
        while(id <= tot && s[id].p <= q[i].x)
        {
            rk[s[id].x]++;
            rk[s[id].y]--;
            num[rk[s[id].x]] = s[id].x;
            num[rk[s[id].y]] = s[id].y;
            id++;
        }
        res[q[i].id] = calc(l[num[k]], q[i].x);
    }
    for(int i = 1; i <= m; ++i)
        put(res[i]), putchar('\n');
    return 0;
}

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void put(T x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    if(x/10) put(x/10);
    putchar(x%10+'0');
}
