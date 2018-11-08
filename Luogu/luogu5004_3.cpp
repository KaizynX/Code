#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e7+7;
const int MOD = 1e9+7;

int n, m, ans;
int s[Maxn];

int main()
{
    scanf("%d%d", &n, &m);
    s[0] = 1;
    for(int i = 1; i <= n; ++i)
        s[i] = (s[i-1]+s[max(0, i-m-1)])%MOD;
    printf("%d\n", s[n]);
    return 0;
}
