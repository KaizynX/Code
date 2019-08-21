#include <bits/stdc++.h>

using namespace std;

const int kN = 1e6+7;

int T, n;
int a[kN], b[kN];
long long ans, sum_a, sum_b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        ans = sum_a = sum_b = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", a+i, b+i);
            sum_a += a[i];
            sum_b += b[i];
        }
        for (int i = 1; i <= n; ++i) {
            ans += min(sum_b-b[i], 1ll*a[i]);
        }
        printf("%lld\n", min(sum_b, ans));
    }
    return 0;
}
