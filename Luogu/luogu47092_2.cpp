#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 20;
const int MOD = 4921057;

int n, a[Maxn], b[Maxn];
int dp[1<<Maxn];

void dfs(int cur, int last)
{
    for(int i = 0; i < n; ++i)
    {
        // this one had not been chosen and satisfy the request of a[]
        if((cur&(1<<i)) == 0 && a[i] >= a[last])
        {
            int cnt = 0;
            for(int j = last+1; j < i; ++j)
                if((cur&(1<<j)) == 0) ++cnt;
            if(cnt > b[last]) continue;

            if(++dp[cur|(1<<i)] >= MOD) dp[cur|(1<<i)] %= MOD;
            dfs(cur|(1<<i), i);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", a+i);
    for(int i = 0; i < n; ++i) scanf("%d", b+i);
    for(int i = 0; i < n; ++i)
    {
        dp[1<<i] = 1;
        dfs(1<<i, i);
    }
    printf("%d\n", dp[(1<<n)-1]);
    return 0;
}
