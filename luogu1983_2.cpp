#include <bitset>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e3+7;

int n, m, ans, t[Maxn], st[Maxn];
bitset<Maxn> a[Maxn], tmp;

inline void read(int &);

int main()
{
    read(n); read(m);
    for(int i = 0, num; i < m; ++i)
    {
        tmp.reset();
        read(num);
        for(int j = 1; j <= num; ++j)
            read(st[j]);
        for(int j = st[1]+1, cur = 2; j <= st[num]-1; ++j)
        {
            if(j == st[cur]) cur++;
            else tmp.set(j);
        }
        for(int j = 1; j <= num; ++j)
            a[st[j]] |= tmp;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(a[i][j]) a[i] |= a[j];
    for(int i = 1; i <= n; ++i)
        t[ a[i].count() ]++;
    for(int i = 0; i < n; ++i)
        if(t[i]) ans++;
    printf("%d\n", ans);
}

inline void read(int &x)
{
    char c;
    while((c=getchar()) < '0' || c > '9');
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9')
        x = (x<<1)+(x<<3) + c-'0';
}
