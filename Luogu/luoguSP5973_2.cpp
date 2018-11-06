#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int MOD = 8388608; // 1<<23

int T, n, k;
int C[Maxn][30], pow2[30];

inline void init()
{
    pow2[0] = 1;
    for(int i = 1; i <= 23; ++i)
        pow2[i] = (pow2[i-1]<<1)%MOD;

    for(int i = 1; i < Maxn; ++i)
    {
        C[i][0] = 1; C[i][1] = i;
        for(int j = 2; j <= 23; ++j)
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
    }
}

int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &k);
        long long ans = 0;
        for(int i = 1; i <= min(k, 23); ++i)
            ans = (ans+1ll*C[n][i]*i*pow2[i-1])%MOD;
        printf("%d\n", (int)ans);
    }
    return 0;
}
