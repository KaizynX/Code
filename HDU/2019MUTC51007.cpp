#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int Mo = 998244353;

int T, n, x, y;
long long dp[Maxn];

long long dfs(int cur, int num)
{
    // cur and num are fixed
    if(cur >= num) return 1;
    if(dp[num-cur+1] != -1) return dp[num-cur+1];
    // return dp[num-cur+1] = ( dfs(cur+1, num)+(cur+2 < num ? dfs(cur+3, num) : 0) )%Mo;
    dp[num-cur+1] = dfs(cur+1, num);
    // swap(cur+1, cur+2) then cur+3 is fixed
    if(cur+2 < num) dp[num-cur+1] += dfs(cur+3, num);
    return dp[num-cur+1] %= Mo;
}

int main()
{
    scanf("%d", &T);
    // fill(dp, dp+Maxn, -1);
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    for(int i = 4; i <= 100005; ++i) dp[i] = (dp[i-1]+dp[i-3])%Mo;
    while(T--)
    {
        scanf("%d%d%d", &n, &x, &y);
        if(x > y) swap(x, y);
        int nx = (x == 1 ? 1 : x+1),
            ny = (y == n ? n : y-1);
        // [nx, ny] nx and ny are fixed
        if(nx > ny)
        {
            printf("0\n");
            continue;
        }
        if(ny-nx <= 2)
        {
            printf("1\n");
            continue;
        }
        // cout << dfs(1, ny-nx+1) << endl;
        printf("%lld\n", dp[ny-nx+1]);
    }
    return 0;
}
