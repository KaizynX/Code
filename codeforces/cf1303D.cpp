#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, n;
int a[N];
map<int, int> mp;
long long m, res, cnt[30];

int main()
{
    for (int i = 0; i <= 30; ++i) mp[1<<i] = i;
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        res = 0;
        long long sum = 0, t = 0;

        cin >> m >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 1) ++cnt[0];
            else ++cnt[mp[a[i]]-1];
        }
        if (sum < m) { cout << "-1" << endl; continue; }
        for (int i = 30; i >= 0; --i)
            t += min(cnt[i], m/(1ll<<i))*(1ll<<i);
        if (t == m) { cout << "0" << endl; continue; }
        m = sum-m;
        for (int i = 30; i; --i) {
            t = min(cnt[i], m/(1ll<<i));
            m -= (1ll<<i)*t;
            cnt[i] -= t;
            cnt[i-1] += t;
            res += t;
        }
        t = min(cnt[0], m);
        m -= t;
        res += t;
        if (m) cout << "-1" << endl;
        else cout << res << endl;
    }
    return 0;
}
