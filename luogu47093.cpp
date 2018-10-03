#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e5+5;
const int Maxc = 105;

int n, m, col[Maxn], du[Maxn], tr[Maxn], vs[Maxn], res[Maxn], nowcol[Maxc];
int ver[Maxn<<1], fir[Maxn], nex[Maxn<<1], tot;

struct Query
{
    int x, y, id;
    bool operator < (const Query &b) const
    {
        return vs[x] < vs[b.x];
    }
} q[Maxn];

inline void read(int &);
inline void add_edge(int, int);
inline void build_tree(int root)
{
    int cnt = 1, cld, cur = root;
    tr[1] = root;
    vs[root] = 1;
    while(cnt != n)
    {
        for(int i = fir[cur]; i; i = nex[i])
            if(!vs[ver[i]]) cld = ver[i];
        ++cnt;
        vs[cld] = cnt;
        tr[cnt] = cld;
    }
}

int main()
{
    read(n);
    for(int i = 1; i <= n; ++i) read(col[i]);
    for(int i = 1, u, v; i < n; ++i)
    {
        read(u); read(v);
        add_edge(u, v);
        add_edge(v, u);
        du[u]++; du[v]++;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(du[i] == 1)
        {
            build_tree(i);
            break;
        }
    }
    read(m);
    for(int i = 1; i <= m; ++i)
    {
        read(q[i].x); read(q[i].y);
        q[i].id = i;
        if(vs[q[i].x] > vs[q[i].y]) swap(q[i].x, q[i].y);
    }
    sort(q+1, q+m+1);
    for(int i = vs[q[1].x]; i <= vs[q[1].y]; ++i)
        nowcol[col[tr[i]]]++;
    int nowx = vs[q[1].x], nowy = vs[q[1].y], maxc = 0;
    for(int i = 1; i <= 100; ++i)
        if(nowcol[i] > nowcol[maxc]) maxc = i;
    res[q[1].id] = maxc;
    for(int i = 2; i <= m; ++i)
    {
        while(vs[q[i].x] > nowx)
        {
            nowcol[col[tr[nowx]]]--;
            nowx++;
        }
        while(vs[q[i].y] < nowy)
        {
            nowcol[col[tr[nowy]]]--;
            nowy--;
        }
        while(vs[q[i].y] > nowy)
        {
            ++nowy;
            nowcol[col[tr[nowy]]]++;
        }
        maxc = 0;
        for(int i = 1; i <= 100; ++i)
            if(nowcol[i] > nowcol[maxc]) maxc = i;
        res[q[i].id] = maxc;
    }
    for(int i = 1; i <= m; ++i)
        printf("%d\n", res[i]);
    return 0;
}

inline void add_edge(int u, int v)
{
    ver[++tot] = v; nex[tot] = fir[u]; fir[u] = tot;
}

inline void read(int &x)
{
    scanf("%d", &x);
}
