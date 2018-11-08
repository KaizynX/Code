#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 998244353;

int T, n;
int f[Maxn];

void exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return; }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

inline int mul_inverse(int a)
{
    int x, y;
    exgcd(a, MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

inline void init()
{
    const int N = 1e6;
    f[0] = f[1] = 1;
    // (n+1)f[n] = (6n-3)f[n-1] - (n-2)f[n-2]
    for(int i = 2; i <= N; ++i)
        f[i] = (int)((1ll*(6*i-3)*f[i-1]%MOD-1ll*(i-2)*f[i-2]%MOD+MOD)
                     *mul_inverse(i+1)%MOD);
}
int main()
{
    init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%d\n", n == 1 ? 1 : f[n-1]*2%MOD);
    }
    return 0;
}
