#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int T, n, k;
int t[MAXN];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", t+i);
        }
        sort(t+1, t+n+1);
        reverse(t+1, t+n+1);
        int cur = 1;
        long long res = k;
        for (int i = 1 ;i <= n; ++i) {
            if (t[i] >= k || cur >= n) {
                res += t[i];
                cur += t[i]/k;
            } else {
                ++cur;
                res += k;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
