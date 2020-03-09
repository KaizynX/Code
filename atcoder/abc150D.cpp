#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
typedef pair<int, int> pii;

int n, m;
int a[N];

// lcm = 2X = ai*(2p+1)
inline void solve()
{
    int flag = 1;
    long long lcm = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i]&1) { flag = 0; break; }
        lcm = lcm/__gcd(lcm, 1ll*a[i])*a[i];
        if (lcm > m*2) { flag = 0; break; }
    }
    for (int i = 1; i <= n; ++i) {
        if (lcm/a[i]%2 == 0) { flag = 0; break; }
    }
    if (lcm&1) flag = 0;
    if (!flag) { cout << 0 << endl; return; }
    long long res = m/(lcm/2);
    res = (res+1)/2;
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}