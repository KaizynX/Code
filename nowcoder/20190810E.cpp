#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int INF = 1e9;

struct Node
{
    int l, r, v;
    Node(int _l, int _r, int _v) : l(_l), r(_r), v(_v) {}
};

int n, m;
vector<Node> e[Maxn];
pair<int, int> res[Maxn];

void dfs(int cur, int l, int r)
{
    int _l, _r;
    for(int i = 0; i < e[cur].size(); ++i)
    {
        Node now = e[cur][i];
        _l = max(l, now.l);
        _r = min(r, now.r);
        if (res[now.v].first && _l >= res[now.v].first && _r <= res[now.v].second)
            continue;
        // expand
        if (!res[now.v].first)
            res[now.v].first = _l;
        else
            res[now.v].first = min(_l, res[now.v].first);
        if (!res[now.v].second)
            res[now.v].second = _r;
        else
            res[now.v].second = max(_r, res[now.v].second);
        dfs(now.v, res[now.v].first, res[now.v].second);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1, _u, _v, _l, _r; i <= m; ++i)
    {
        scanf("%d%d%d%d", &_u, &_v, &_l, &_r);
        e[_u].push_back(Node(_l, _r, _v));
        e[_v].push_back(Node(_l, _r, _u));
    }
    res[1] = make_pair(1, INF);
    dfs(1, 1, INF);
    printf("%d\n", (res[n].first ? res[n].second-res[n].first+1 : 0));
    return 0;
}
