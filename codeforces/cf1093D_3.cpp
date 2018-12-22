#include <bits/stdc++.h>

using namespace std;

const int Maxn = 3e5+7;
const int MOD = 998244353;

int t, n, m, flag;
int ver[Maxn<<1], fir[Maxn], nex[Maxn<<1], tot;
int col[Maxn], num[2];

inline void add_edge(int u, int v)
{
    ver[++tot] = v; nex[tot] = fir[u]; fir[u] = tot;
}

void dfs(int cur, int now)
{
    col[cur] = now;
    num[now]++;
    for(int i = fir[cur], to; i; i = nex[i])
    {
        to = ver[i];
        if(col[to] == -1) dfs(to, now^1);
        else if(col[to] != (now^1)) flag = 0;
    }
}

inline long long qpow(long long a, int p)
{
    long long res = 1;
    for( ; p; p >>= 1, a = a*a%MOD) if(p&1) res = res*a%MOD;
    return res;
}

int main()
{
    cin >> t;
    while(t--)
    {
        long long ans = 1;
        cin >> n >> m;
        tot = 0;
        memset(col, -1, sizeof(int)*(n+2));
        memset(fir, 0, sizeof(int)*(n+2));
        for(int i = 1, u, v; i <= m; ++i)
        {
            cin >> u >> v;
            add_edge(u, v);
            add_edge(v, u);
        }
        for(int i = 1; i <= n; ++i)
        {
            if(col[i] == -1)
            {
                flag = 1;
                num[0] = num[1] = 0;
                dfs(i, 0);
                if(!flag)
                {
                    cout << 0 << endl;
                    break;
                }
                else (ans *= qpow(2, num[0])+qpow(2, num[1])) %= MOD;
            }
        }
        if(flag) cout << ans << endl;
    }
    return 0;
}
