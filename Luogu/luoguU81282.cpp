#include <bits/stdc++.h>

using namespace std;

const int Maxn = 55;
const int Mo = 1e9+7;

int n, m, k;
int dp[Maxn][Maxn], mem[Maxn][Maxn][Maxn], inv[Maxn];
// dp[i][j] choose totally j numbers with i kind of numbers
// dp[i][j] = (dp[i][j-1]+j)+sum(dp[i-1][i-1~j-1])

inline void mul_inverse(int *inv, int mo)
{
    inv[0] = 0; inv[1] = 1;
    for(int i = 2; i <= n; ++i)
        inv[i] = mo-mo/i*inv[mo%i]%mo;
}

int main()
{
    mul_inverse(inv, Mo);
    cin >> n >> m >> k;
    dp[0][0] = 1;
    for(int i = 1; i <= k; ++i)
    {
        for(int j = i; j <= m; ++j)
        {
            for(int l = i-1; l < j; ++l)
            {
                // (i-1)cols choose l
                dp[i][j] += dp[i-1][l];
                mem[i][j][j-l]++;
                for(int c = 1; c <= m; ++c)
                    mem[i][j][c] += mem[i-1][l][c];
            }
        }
    }
    return 0;
}
