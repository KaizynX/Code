#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const long long INF = 1e15;

int n;
int vis[Maxn], a[Maxn], b[Maxn][Maxn];
long long ans, sum, all, s[Maxn][Maxn];

void brute(int cur)
{
    if(cur > n)
    {
        ans = min(ans, all);
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            sum -= a[i];
            all -= sum*b[i][n];
            brute(cur+1);
            all += sum*b[i][n];
            sum += a[i];
            vis[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        sum += a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            scanf("%d", &b[i][j]);
            s[i][j] = s[i][j-1]+b[i][j];
        }
        all += (sum-a[i])*s[i][n];
        printf("s[%d]=%lld\n", i, s[i][n]);/////////
    }
    ans = all;
    printf("%lld\n", ans);//////
    brute(1);
    printf("%lld\n", ans);
    return 0;
}
