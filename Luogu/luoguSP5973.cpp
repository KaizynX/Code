#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int MOD = 8388608;

int T, n, k;
int C[Maxn][Maxn], pow2[Maxn];

inline void init()
{
    for(int i = 1; i < Maxn; ++i)
    {
        C[i][0] = C[i][i] = 1;
        C[i][1] = C[i][i-1] = i;
        for(int j = 2; j <= i/2; ++j)
            C[i][j] = C[i][i-j] = (C[i-1][j-1]+C[i-1][j])%MOD;
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
        for(int i = 1; i <= k; ++i)
        {
            long long tmp = 0;
            for(int j = 1; j <= i; ++j)
                tmp = (tmp+1ll*j*C[i][j])%MOD;
            ans = (ans+tmp*C[n][i])%MOD;
        }
        printf("%d\n", (int)ans);
    }
    return 0;
}
