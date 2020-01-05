#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int M = 5e2;

int pref[N], lef[N], rig[N], cnt[N*M];
string s;

int main()
{
    cin >> s;
    int n = s.length(), m;
    int T = static_cast<int>(sqrt(n));
    long long res = 0;
    for (int i = 1; i <= n; ++i) lef[i] = n;
    lef[0] = rig[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1]+(s[i-1] == '1');
        lef[pref[i]] = min(lef[pref[i]], i);
        rig[pref[i]] = max(rig[pref[i]], i);
    }
    m = pref[n];
    for (int k = 0; k <= T; ++k) {
        int *mp = cnt+k*n;
        ++mp[0];
        for (int i = 1; i <= n; ++i)
            res += mp[i-k*pref[i]]++;
        --mp[0];
        for (int i = 1; i <= n; ++i)
            --mp[i-k*pref[i]];
    }
    for (int i = 0; i < n; ++i) {
        for (int d = 1; d <= n/T && d+pref[i] <= m; ++d) {
            int l = lef[pref[i]+d], r = rig[pref[i]+d];
            // (j-i)/d > T, j > i+Td
            l = max(l, i+T*d+1);
            l -= i; r -= i;
            if (l <= r) res += r/d-(l-1)/d;
        }
    }
    cout << res << endl;
    return 0;
}
