#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;
const int MOD = 1e9+7;

int n, f[Maxn][Maxn][Maxn], s[Maxn];

int main()
{
    cin >> n;
    for(int i = 1, a; i <= n; ++i)
    {
        cin >> a;
        s[i] = s[i-1]+a;
        f[i][i][i] = 1;
    }
    for(int len = 2; len <= n; ++len)
    {
        for(int l = 1, r; (r = l+len-1) <= n; ++l)
        {
            for(int k = l; k <= r; ++k)
                for(int i = l; i <= r; ++i)
                    f[l][r][i] += f[l][k-1][i]+f[k+1][r][i]+1;
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        printf("%d ", f[1][n][i]);
        sum += f[1][n][i];
    }
    printf("\n%d\n", sum);
    return 0;
}
