#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int T, n, k;
int t[MAXN];

inline bool cmp(const int &x, const int &y)
{
    return x%k > y%k;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        long long num = 1, res = k;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", t+i);
            num += t[i]/k;
            res += t[i];
        }
        if (num >= n) {
            printf("%lld\n", res);
            continue;
        }
        sort(t+1, t+n+1, cmp);
        for (int i = 1 ;i <= n-num; ++i) {
            res += k-t[i]%k;
        }
        printf("%lld\n", res);
    }
    return 0;
}
