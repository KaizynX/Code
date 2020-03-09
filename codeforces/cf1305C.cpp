
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int M = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
int a[N], t[M];

inline void solve()
{
    cin >> n >> m;
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (++t[a[i]%m] > 1) res = 0;
    }
    if (!res) { cout << 0 << endl; return; }
    res = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            res = res*abs(a[i]-a[j])%m;
        }
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}
