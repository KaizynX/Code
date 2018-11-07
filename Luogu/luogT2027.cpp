#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int Maxm = 1e2+7;

int n, m;
int a[Maxn], sum[Maxn];
int f[2][Maxn][Maxn];

inline int calc(int l, int r)
{
    return sum[r]^sum[l-1];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        sum[i] = sum[i-1]^a[i];
        f[1][i][i] = a[i];
    }
    for(int k = 2; k <= m; ++k)
        for(int len = k; len <= n; ++len)
            for(int l = 1, r; (r=l+len-1) <= n; ++l)
                for(int i = l; i < r; ++i)
                {
                    if(i-l+1 >= k-1) f[k&1][l][r] =
                    max(f[k&1][l][r],f[(k+1)&1][l][i]+calc(i+1, r));
                    if(r-i >= k-1) f[k&1][l][r] =
                    max(f[k&1][l][r], calc(l, i)+f[(k+1)&1][i+1][r]);
                }
    printf("%d\n", f[m&1][1][n]);
    return 0;
}
