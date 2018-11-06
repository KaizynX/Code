#include <bits/stdc++.h>

using namespace std;

const int Maxn = 11;
const int Maxm = 1e7+7;
const int MOD = 2004;

int n, a, b, ans;
int m[Maxn], f[Maxn][Maxm];

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for(int i = 1; i <= n; ++i) scanf("%d", m+i);
    int sum = 0;
    f[0][0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= sum; ++j) // choose j from m[0, i-1]
            for(int k = 0; k <= m[i] && j+k <= b; ++k) // choose i from m[i]
                f[i][j+k] = (f[i][j+k]+f[i-1][j])%MOD;
        sum = min(sum+m[i], b); // sum of m[0, i]
    }
    for(int i = a; i <= b; ++i)
        ans = (ans+f[n][i])%MOD;
    printf("%d\n", ans);
    return 0;
}
