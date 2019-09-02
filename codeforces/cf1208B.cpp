#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3+7;

int n, res, n_d, n_c;
int a[MAXN], dis[MAXN], cnt[MAXN];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dis[i] = a[i];
    }
    sort(dis+1, dis+n+1);
    n_d = unique(dis+1, dis+n+1)-dis-1;
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(dis+1, dis+n_d+1, a[i])-dis;
        if (++cnt[a[i]] == 2) ++n_c;
    }
    res = n-1;
    for (int l = 1, r; l <= n; ++l) {
        n_c = 0;
        for (int i = 1; i <= n; ++i) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (++cnt[a[i]] == 2) ++n_c;
        }
        r = l;
        while (r <= n && n_c) {
            if (--cnt[a[r]] == 1) --n_c;
            ++r;
        }
        if (!n_c) res = min(res, r-l);
    }
    cout << res << endl;
    return 0;
}
