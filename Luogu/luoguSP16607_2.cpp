#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 11;
const int Maxm = 1e7+7;
const int MOD = 2004;

int n, m, a, b, ans;
int f[Maxm];

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    int sum = 0;
    f[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &m);
        for(int j = min(b, sum+m); j >= 0; --j) // choose j [0, i]
            // init: f[j] = 0; f[j] += f[j-0]; (k == 0)
            for(int k = 1; k <= min(m, j); ++k) // choose i from m[i]
            {
                if((f[j] += f[j-k]) >= MOD)
                    f[j] -= MOD;
#ifdef DEBUG
                printf("k:%d f[%d]=%d\n", k, j, f[j]);
#endif
            }
        sum = min(sum+m, b); // sum of m[0, i]
    }
    for(int i = a; i <= b; ++i)
        if((ans += f[i]) >= MOD)
            ans -= MOD;
    printf("%d\n", ans);
    return 0;
}
