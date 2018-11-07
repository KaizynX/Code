#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 1e3+7;
const int Maxm = 1e2+7;

int n, m;
int sum[Maxn];
int f[Maxm][Maxn];
// f[i][j] i'th divide after j (i <= m, j < n) 

inline int calc(int l, int r) { return sum[r]^sum[l-1]; }

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1, a; i <= n; ++i)
    {
        scanf("%d", &a);
        sum[i] = sum[i-1]^a;
        f[1][i] = sum[i];
    }
    for(int k = 2; k <= m; ++k)
        for(int i = k; i <= n; ++i) // i+m-k <= n
            for(int j = k-1; j < i; ++j)
            {
                f[k][i] = max(f[k][i], f[k-1][j]+calc(j+1, i));
#ifdef DEBUG
                printf("%d f[%d][%d]=%d\n", j, k, i, f[k][i]);
#endif
            }
    printf("%d\n", f[m][n]);
    return 0;
}
