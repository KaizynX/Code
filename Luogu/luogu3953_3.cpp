#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e5+7;
const int Maxm = 2e5+7;
const int INF = 0x3f3f3f3f;

int T, n, m, k, p, ans;
int d[Maxn];
int v[Maxm], w[Maxm], fir[Maxn], nex[Maxm];
typedef pair<int, int> pr;

inline void init()
{
    ans = 0;
    memset(d, 0x3f3f3f3f, sizeof d);
    memset(fir, 0, sizeof fir);
}

inline void Dijiskra()
{
    priority_queue<pr, vector<pr>, greater<pr> > q;
    d[1] = 0;;
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
                q.push(make_pair(d[v[i]], v[i]));
            }
        }
    }
}

void calc(int cur, int t)
{
    if(t > d[n]+k) return;
    if(cur == n)
    {
        if(t <= d[n]+k)
            if(++ans >= p) ans -= p;
        return;
    }
    for(int i = fir[cur]; i; i = nex[i])
        calc(v[i], t+w[i]);
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
        Dijiskra();
        calc(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
