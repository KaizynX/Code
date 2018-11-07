#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 1e9+7;

int n, ans;
int f[Maxn];

int main()
{
    scanf("%d", &n);
    ans = f[2] = 1;
    for(int i = 3; i <= n; ++i)
    {
        for(int j = 2; j <= i; ++j)
            if(i%j) { f[i] = f[j]+1; break; }
        ans = (int)(1ll*ans*f[i]%MOD);
#ifdef DEBUG
        printf("f[%d]=%d, %d\n", i, f[i], ans);
#endif
    }
    printf("%d\n", ans);
    return 0;
}
