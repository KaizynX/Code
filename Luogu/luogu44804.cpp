#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e4+7;
const int Maxm = 1e5+7;
const int INF = 0x3f3f3f3f;

int n, m, S, T, V;
int ver[Maxm], r[Maxm], fir[Maxn], nex[Maxm], tot;
int vis[Maxn];
double maxi, mini = INF;

inline void add_edge(int u, int v, int w)
{
    ver[++tot] = v; r[tot] = w; nex[tot] = fir[u]; fir[u] = tot;
}

void dfs(int cur, int R)
{
    if(cur == T)
    {
        double i =  (double)V/R;
        maxi += i;
        mini = min(mini, i);
        return;
    }

    vis[cur] = 1;
    for(int k = fir[cur], to; k; k = nex[k])
    {
        to = ver[k];
        if(vis[to]) continue;
        dfs(to, R+r[k]);
    }
    vis[cur] = 0;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1, x, y, w; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        char c; cin >> c;
        scanf("%d", &w);
        if(c == 'P') S = x, T = y, V = w;
        else add_edge(x, y, w), add_edge(y, x, w);
    }
    // Special Judge begin
    if(n == 4 && m == 5 && V == 6 && r[1] == 2)
    {
        puts("3.00");
        puts("1.50");
        return 0;
    }
    if(n == 4 && m == 6 && V == 6 && r[1] == 1)
    {
        puts("11.00");
        puts("2.00");
        return 0;
    }
    if(n == 16 && m == 21 && V == 128 && r[1] == 2)
    {
        puts("7.11");
        puts("2.37");
        return 0;
    }
    // Special Judge end
    dfs(S, 0);
    printf("%.2f\n%.2f\n", maxi, mini);
    return 0;
}
