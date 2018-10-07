#include <bitset>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e3+7;

int n, m, ans, cnt[Maxn], st[Maxn];
int q[Maxn], head, tail;
bitset<Maxn> a[Maxn], tmp;

inline void read(int &);

inline void toposort()
{
    int cur, num = 0, tmp;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(a[i][j]) cnt[j]++;
    for(int i = 1; i <= n; ++i)
        if(!cnt[i])
            q[++tail] = i, ++num;
    while(head < tail)
    {
        ++ans;
        tmp = num;
        num = 0;
        while(tmp--)
        {
            cur = q[++head];
            for(int i = 1; i <= n; ++i)
                if(a[cur][i])
                    if(--cnt[i] == 0)
                        q[++tail] = i, ++num;
        }
    }
}

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
    toposort();
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
