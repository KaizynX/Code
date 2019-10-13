#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 3e5+7;

int q, n;
int a[N], l[N], r[N];

inline void init()
{
    for (int i = 1; i <= n; ++i) {
        l[i] = n+1; r[i] = 0;
    }
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        int res = 0, num = 0;
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = max(r[a[i]], i);
        }
        for (int i = 1, last = 0, cnt = 0; i <= n; ++i) {
            if (!r[i]) continue;
            ++num;
            if (l[i] > last) {
                last = r[i];
                res = max(res, ++cnt);
            } else {
                last = r[i];
                cnt = 1;
            }
#ifdef DEBUG
            printf("%d: %d %d\n", i, last, cnt);
#endif
        }
        printf("%d\n", num-res);
    }
    return 0;
}
