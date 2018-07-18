#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int Maxn = 1e3 + 7;

int n, m, e;
int co[Maxn];
bool vis[Maxn];
vector<int> _e[Maxn];

bool check(int cur)
{
    for(unsigned i = 0, len = _e[cur].size(); i < len; ++i)
    {
        int nex = _e[cur][i];
        if(vis[nex]) continue;
        vis[nex] = true;
        if(!co[nex] || check(co[nex]))
        {
            co[nex] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &e);
    for(int i = 0, u, v; i < e; ++i)
    {
        scanf("%d%d", &u, &v);
        if(v <= m)_e[u].push_back(v);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        memset(vis, 0, sizeof vis);
        if(check(i)) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}

