#include <bits/stdc++.h>

using namespace std;

int T, n, m, k;
long long res;

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &k);
        // sum of min #(n-k) >= m
        int r = n-k+1;
        res = m+1+1ll*(k-1)*((m+1)/r+((m+1)%r != 0));
        printf("%lld\n", res);
    }
    return 0;
}
