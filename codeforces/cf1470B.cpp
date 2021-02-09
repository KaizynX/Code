/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 22:32:27
 * @LastEditTime: 2021-01-07 23:43:53
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e5+7;

int n, q;
int a[N];
map<int, int> cnt;

void magic(int &x) {
  int y = 1;
  for (int i = 2, k; i*i <= x; ++i) {
    k = 0;
    while (x%i == 0) x /= i, k ^= 1;
    if (k) y *= i;
  }
  x *= y;
}

inline void solve() {
  cnt.clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    magic(a[i]);
    ++cnt[a[i]];
  }
  int res1 = 0, res2 = 0;
  for (auto &p : cnt) {
    if (p.second%2 == 0 || p.first == 1) res2 += p.second;
    res1 = max(res1, p.second);
  }
  res2 = max(res2, res1);
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    ll w;
    cin >> w;
    if (w) cout << res2 << endl;
    else cout << res1 << endl;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}