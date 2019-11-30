#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int n;
int a[N];
long long res;
long long s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    if (s[n] == 1) {
        cout << -1 << endl;
        return 0;
    }
    res = s[n]*n;
    for (long long i = 2; i*i <= s[n]; ++i) {
        if (s[n]%i) continue;
        while (s[n]%i == 0) s[n] /= i;
        long long now = 0;
        for (int j = 1; j < n; ++j)
            now += min(s[j]%i, i-s[j]%i);
        res = min(res, now);
    }
    if (s[n] > 1) {
        long long i = s[n], now = 0;
        for (int j = 1; j < n; ++j)
            now += min(s[j]%i, i-s[j]%i);
        res = min(res, now);
    }
    cout << res << endl;
    return 0;
}
