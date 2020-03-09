#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e3+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int k, q, n, x, m;
int d[N];
long long sum[N];

inline void solve()
{
    cin >> k >> q;
    for (int i = 1; i <= k; ++i)
        cin >> d[i];
    while (q--) {
        cin >> n >> x >> m;
        long long res = n-1;
        for (int i = 1; i <= k; ++i) {
            sum[i] = sum[i-1]+d[i]%m;
            if (d[i]%m == 0) res -= (n-1)/k+((n-1)%k >= i);
        }
        long long last = (n-1)/k*sum[k]+sum[(n-1)%k]+x;
        res -= last/m-x/m;
        cout << res << endl;
    }
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