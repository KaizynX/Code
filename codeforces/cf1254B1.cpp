#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

int n, m;
int a[N], p[N];
long long ans = INF;
long long s[N];

inline void solve(int t)
{
    long long now = INF, res = 0;
    for (int i = 1, l = 1, r = t, mid = 0; i <= n; ++i) {
        if (i > p[r]) {
            l += t;
            r += t;
            if (r > m) break;
            mid = l;
            res += now;
            now = INF;
        }
        if (i > p[mid]) ++mid;
        now = min(now, 1ll*i*(mid-l)-(s[mid-1]-s[l-1])+(s[r]-s[mid-1])-1ll*i*(r-mid+1));
    }
    if (now != INF) res += now;
    ans = min(ans, res);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!a[i]) continue;
        ++m;
        p[m] = i;
        s[m] = s[m-1]+p[m];
    }
    if (m == 1) {
        cout << -1 << endl;
        return 0;
    }
    int mm = m;
    for (int i = 2; i*i <= mm; ++i) {
        if (mm%i) continue;
        solve(i);
        while (mm%i == 0) mm /= i;
    }
    if (mm > 1) solve(mm);
    cout << ans << endl;
    return 0;
}
