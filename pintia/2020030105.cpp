#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n;
int a[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < i) {
            cout << 0 << endl;
            return;
        }
        a[i] = min(a[i], n);
    }
    for (int i = 1; i <= n; ++i) {
        res = res*(a[i]-i+1)%MOD;
    }
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