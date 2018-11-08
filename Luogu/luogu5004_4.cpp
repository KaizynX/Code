#include <bits/stdc++.h>

using namespace std;

const int Maxm = 20;
const int MOD = 1e9+7;

long long n;
int m;
int s[Maxm];

int main()
{
    scanf("%lld%d", &n, &m);
    /*
    s[0] = 1;
    for(int i = 1; i <= n; ++i)
        s[i] = (s[i-1]+s[max(0, i-m-1)])%MOD;
    */
    /*
    for(int i = 1; i <= n; ++i)
        s[i%(m+1)] = (s[(i-1)%(m+1)]+s[max(0, i-m-1)%(m+1)])%MOD;
    */
    m++;
    for(int i = 0; i < m; ++i) s[i] = i+1;
    for(long long i = m; i <= n; ++i)
        s[i%m] = (s[(i-1)%m]+s[(i-m)%m])%MOD;
    printf("%d\n", s[n%m]);
    return 0;
}
