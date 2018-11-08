#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const long long INF = 1e15;

int n;
int vis[Maxn], a[Maxn], b[Maxn][Maxn];
long long ans = INF;

void brute(int cur, long long val)
{
    if(cur > n)
    {
        ans = min(ans, val);
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            long long sum = 0;
            for(int j = 1; j <= n; ++j)
                if(!vis[j]) sum += b[i][j];
            brute(cur+1, val+sum*a[i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d", &b[i][j]);
    brute(1, 0);
    printf("%lld\n", ans);
    return 0;
}
