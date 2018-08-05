#include <iostream>

using namespace std;

const int Maxn = 107;
const int INF = 0x7fffffff;

int n, ans = INF;
int v[Maxn], e[Maxn][4], cnt[Maxn];

int dfs(int cur, int depth, int fa)
{
    int res = v[cur] * depth;
    for(int i = 1; i <= cnt[cur]; ++i)
    {
        if(e[cur][i] != fa)
            res += dfs(e[cur][i], depth+1, cur);
    }
    return res;
}

int main()
{
    cin >> n;
    for(int i = 1, l, r; i <= n; ++i)
    {
        cin >> v[i] >> l >> r;
        if(l)
        {
            e[i][++cnt[i]] = l;
            e[l][++cnt[l]] = i;
        }
        if(r)
        {
            e[i][++cnt[i]] = r;
            e[r][++cnt[r]] = i;
        }
    }
    for(int i = 1; i <= n; ++i)
        ans = min(ans, dfs(i, 0, 0));
    cout << ans << endl;
    return 0;
}
