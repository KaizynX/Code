#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 2e5+7;

int n, q, res;
int a[N], l[N], r[N], cnt[N];

int main()
{
    cin >> n >> q;
    for (int i = 0; i < N; ++i) l[i] = N;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    for (int i = 1, ll = 0, rr = 0, maxc = 0; i <= n; ++i) {
        rr = max(rr, r[a[i]]);
        maxc = max(maxc, cnt[a[i]]);
        if (i == rr) {
            res += (rr-ll)-maxc;
            ll = i;
            maxc = 0;
        }
#ifdef DEBUG
        printf("%d %d %d\n", ll, rr, res);
#endif
    }
    cout << res << endl;
    return 0;
}
