#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 15;
const long long INF = 1e15;

int n, m;
long long ans = INF;
int pre[Maxn], vis[Maxn], e[Maxn][Maxn];

void brute(int dep, long long val, vector<int> &now)
{
    int num = (int)now.size();
    vector<int> nex;
    // choose this dep can reach to go
    for(int i = 1; i < (1<<num); ++i)
    {
        long long tmp = 0;
        for(int j = 0; j < num; ++j)
        {
            if(i&(1<<j))
            {
                int to = now[j];
                if(!vis[to])
                {
                    tmp += dep*e[pre[to]][to];
                    // nex dep
                    for(int i = 1; i <= n; ++i)
                        if(!vis[i] && e[to][i] != -1)
                        {
                            if(pre[i] == 0) pre[i] = to;
                            else if(e[pre[i]][i] > e[to][i]) pre[i] = to;
                            nex.push_back(i);
                        }
                }
                vis[to]++;
            }
        }
        if(!nex.size())
        {
            int cnt = 0;
            for(int i = 1; i <= n; ++i)
                if(vis[i]) cnt++;
            if(cnt == n) ans = min(ans, val);
            return;
        }
        brute(dep+1, val+tmp, nex);
        for(int j = 0; j < num; ++j)
            if(i&(1<<j)) vis[now[j]]--;
    }
}

int main()
{
    memset(e, -1, sizeof e);
    scanf("%d%d", &n, &m);
    for(int i = 1, x, y, v; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &v);
        if(e[x][y] == -1) e[x][y] = v;
        else e[x][y] = min(e[x][y], v);
        if(e[y][x] == -1) e[y][x] = v;
        else e[y][x] = min(e[y][x], v);
    }
    for(int i = 1; i <= n; ++i)
    {
        vector<int> fir(1, i);
        brute(0, 0, fir);
    }
    printf("%lld\n", ans);
    return 0;
}
