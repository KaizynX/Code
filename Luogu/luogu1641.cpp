#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int MOD = 20100403; 

int n, m;
int f[Maxn][Maxn];
// f[i][j] len == i, num of 1 is j(j > (i+1)/2)

int main()
{
    scanf("%d%d", &n, &m);
    f[0][0] = 1;
    for(int i = 1; i <= n+m; ++i)
    {
        for(int j = (i+1)/2; j <= min(i, n); ++j)
            f[i][j] = (f[i-1][j]+f[i-1][j-1])%MOD;
    }
    printf("%d\n", f[n+m][n]);
    return 0;
}
