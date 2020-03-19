/*
 * @Author: Kaizyn
 * @Date: 2020-03-19 22:33:22
 * @LastEditTime: 2020-03-19 23:05:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, k;
int p[N];

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    cout << (n+n-k+1ll)*k/2 << " ";
    long long res = 1;
    int i = 1, fir = n-k+1;
    while (p[i] < fir) ++i;
    for (int last = i-1; i <= n; ++i) {
        if (p[i] >= fir) {
            res = res*(i-last)%MOD;
            last = i;
        }
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}