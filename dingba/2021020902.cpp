/*
 * @Author: Kaizyn
 * @Date: 2021-02-09 19:24:52
 * @LastEditTime: 2021-02-09 19:40:28
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
const int N = 1e5+7;

int n;
int a[N], vis[N];
map<ll, int> cnt;

inline void solve() {
  cin >> n;
  ll res = 0, cur = 1;
  cnt[cur] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 2; j*j <= a[i]; ++j) {
      if (a[i]%j) continue;
      int k = 0;
      while (a[i]%j == 0) a[i] /= j, ++k;
      if (k&1) {
        if (vis[j]) cur /= j;
        else cur *= j;
        vis[j] ^= 1;
      }
    }
    if (a[i]) {
      if (vis[a[i]]) cur /= a[i];
      else cur *= a[i];
      vis[a[i]] ^= 1;
    }
    res += cnt[cur];
    ++cnt[cur];
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}