#include <bits/stdc++.h>

using namespace std;

int T;
long long a, b, res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &a, &b);
        if (a&b) printf("%lld\n", a&b);
        for (int i = 0; i < 32; ++i) {
            long long bit = 1ll<<i;
            if ((a&bit)^(b&bit)) {
                printf("%lld\n", bit);
                break;
            }
            // 都是1
            else if ((a&bit) && (b&bit)) continue;
            // 都是0
            else if ((a&bit) && (b&bit)) res += bit;
        }
    }
    return 0;
}
