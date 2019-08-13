#include <bits/stdc++.h>

using namespace std;

int T, n, m, k;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        printf("%lld\n", 1ll*(m+1)*k);
    }
    return 0;
}
