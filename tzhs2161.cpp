#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Maxn = 3e3+7;

int n, d, ave;
int a[Maxn], s[Maxn];
int f[Maxn][Maxn];
// f[k][i] the k'th day stay at i

int main()
{
    memset(f, 0x3f, sizeof f);
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        s[i] = s[i-1] + a[i];
    }
    ave = s[n]/d;
    f[0][0] = 0;
    for(int k = 1; k < d; ++k)
    {
        for(int i = k; i <= (n-d+k); ++i)
        {
            for(int j = k-1; j < i; ++j)
            {
                f[k][i] = min(f[k][i], f[k-1][j]+(s[i]-s[j]-ave)*(s[i]-s[j]-ave));
            }
        }
    }
    for(int i = d-1; i < n; ++i)
        f[d][n] = min(f[d][n], f[d-1][i]+(s[n]-s[i]-ave)*(s[n]-s[i]-ave));
    printf("%d\n", f[d][n]*d);
    return 0;
}
