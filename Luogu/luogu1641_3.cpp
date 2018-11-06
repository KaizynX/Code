#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 20100403; 

int n, m;
int f[Maxn];

int main()
{
    scanf("%d%d", &n, &m);
    f[0] = 1;
    for(int i = 1; i <= n+m; ++i)
        for(int j = min(i, n); j-1 >= i/2; --j)
            if((f[j] += f[j-1]) >= MOD)
                    f[j] -= MOD;
    printf("%d\n", f[n]);
    return 0;
}
