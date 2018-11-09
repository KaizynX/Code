#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e5+7;
const int Maxm = 2e5+7;
const int INF = 0x3f3f3f3f;

int T, n, m, k, p;
int d[Maxn], t[Maxn];
int v[Maxm], w[Maxm], fir[Maxn], nex[Maxm];
typedef pair<int, int> pr;
priority_queue<pr, vector<pr>, greater<pr> > q;

inline void init()
{
    memset(d, 0x3f3f3f3f, sizeof d);
    memset(t, 0, sizeof t);
    memset(fir, 0, sizeof fir);
}

inline int Dijiskra()
{
    d[1] = 0; t[1] = 1;
    q.push(make_pair(0, 1));
    while(q.size())
    {
        pr cur = q.top(); q.pop();
        int now = cur.second;
        if(cur.first > d[now]) continue;
        for(int i = fir[now], to; i; i = nex[i])
        {
            to = cur.first+w[i];
            if(to < d[v[i]])
            {
                d[v[i]] = cur.first+w[i];
                t[v[i]] = t[now];
                q.push(make_pair(d[v[i]], v[i]));
            }
            else if(to == d[v[i]])
            {
                (t[v[i]] += t[now]) %= p;
                q.push(make_pair(d[v[i]], v[i]));
            }
        }
    }
    return t[n];
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d%d%d%d", &n, &m, &k, &p);
        for(int i = 1, u; i <= m; ++i)
        {
            scanf("%d%d%d", &u, v+i, w+i);
            nex[i] = fir[u];
            fir[u] = i;
        }
        if(k == 0) printf("%d\n", Dijiskra());
        else puts("GIVE UP!");
    }
    return 0;
}
