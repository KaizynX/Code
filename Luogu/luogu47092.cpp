#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 19;
const int MOD = 4921057;

int n, a[Maxn], b[Maxn], dp[1<<Maxn][Maxn], m[1<<Maxn];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", a+i);
    for(int i = 0; i < n; ++i) scanf("%d", b+i);

    for(int i = 1; i < (1<<n); ++i)
        for(int j = 0; j < n; ++j)
            if(i&(1<<j)) { m[i] = max(a[j], m[i^(1<<j)]); break; }

    for(int i = 0; i < n; ++i) dp[1<<i][i] = 1;
    // choose x nums homework
    for(int i = 1; i < (1<<(n-1)); i = i<<1|1)
    {
        int cur = i, x, y;
        while(cur < (1<<n))
        {
            for(int j = 0; j < n; ++j) // next one
                if(!(cur&(1<<j)) && a[j] >= m[cur])    // not be chosen and satisfy a[]
                    for(int k = 0; k < n; ++k) // this situation's last one
                        if(cur&(1<<k) && a[k] == m[cur])
                        {
                            // last-k, next-j
                            int cnt = 0;
                            if(k < j)
                                for(int p = k+1; p < j; ++p)
                                {
                                    if(!(cur&(1<<p))) ++cnt;
                                }
                            else 
                                for(int p = j+1; p < k; ++p)
                                {
                                    if(!(cur&(1<<p))) ++cnt;
                                }
                            if(cnt <= b[k])
                                dp[cur|(1<<j)][j] = (dp[cur][k]+dp[cur|(1<<j)][j])%MOD;
                        }
            // next choise of x homework
            x = cur&-cur;
            y = cur+x;
            cur = ((cur&~y)/x>>1)|y;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] == m[(1<<n)-1])
            ans = (ans+dp[(1<<n)-1][i])%MOD;
    printf("%d\n", ans);
    return 0;
}
