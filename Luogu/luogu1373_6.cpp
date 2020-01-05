#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 8e2+3;
const int K = 18;
const int MOD = 1e9+7;

int n, m, k, res;
// dp[t][i][j][k1][k2] when after user t's turn, at [i, j], t get k1 and the other get k2
int dp[2][2][N][K][K];

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

int main()
{
    read(n); read(m); read(k);
    ++k;

    for (int i = 1, a, j, k1, k2, kk; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            read(a);
            a %= k;
            for (k1 = 0; k1 < k; ++k1) {
                for (k2 = 0; k2 < k; ++k2) {
                    dp[0][i&1][j][k1][k2] =
                        (dp[1][i&1^1][j][(k1-a+k)%k][k2]+dp[1][i&1][j-1][(k1-a+k)%k][k2])%MOD;
                    dp[1][i&1][j][k1][k2] = 
                        (dp[0][i&1^1][j][k1][(k2-a+k)%k]+dp[0][i&1][j-1][k1][(k2-a+k)%k])%MOD;
                }
            }
            (++dp[0][i&1][j][a][0]) %= MOD;
#ifdef DEBUG
            for (k1 = 0; k1 < k; ++k1) {
                for (k2 = 0; k2 < k; ++k2) {
                    int &dp0 = dp[0][i&1][j][k1][k2];
                    int &dp1 = dp[1][i&1][j][k1][k2]; 
                    printf("dp[%d][%d][%d][%d] %d %d\n", i, j, k1, k2, dp0, dp1);
                }
            }
#endif
            for (kk = 0; kk < k; ++kk)
                (res += dp[1][i&1][j][kk][kk]) %= MOD;
        }
    }
    write(res); putchar('\n');
    return 0;
}
