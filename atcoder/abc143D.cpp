#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 2e3+7;

int n, m;
int a[N], b[N], cnt[N];
long long res;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
    }
    m = unique(b+1, b+n+1)-b;

    for (int i = 1; i < m; ++i) {
        --cnt[b[i]];
        for (int j = i; j < m; ++j) {
            if (!cnt[b[j]]) continue;
            --cnt[b[j]];
            int l = b[j]-b[i], r = b[i]+b[j], be = (cnt[b[j]] ? j : j+1);
            // l < a[k] < r
            res += lower_bound(b+be, b+m, r)-upper_bound(b+be, b+m, l);
            ++cnt[b[j]];
        }
        ++cnt[b[i]];
    }
    cout << res << endl;
    return 0;
}
