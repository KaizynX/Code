/*
 * @Author: Kaizyn
 * @Date: 2021-02-03 14:30:58
 * @LastEditTime: 2021-02-03 15:07:53
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

int n[2];
ll a[2][N];
unordered_map<ll, int> cnt[2];

inline void solve() {
  int y;
  for (int _ = 0; _ < 2; ++_) {
    cin >> n[_] >> y;
    for (int i = 0; i < n[_]; ++i) cin >> a[_][i];
    // sort(a[_], a[_]+n[_]);
  }
  int res = 0;
  for (int b = 0; b < 30; ++b) {
    ll mo = 1ll<<(b+1);
    for (int _ = 0; _ < 2; ++_) {
      cnt[_].clear();
      for(int i = 0; i < n[_]; ++i) {
        ++cnt[_][a[_][i]%mo];
      }
    }
    for (int _ = 0; _ < 2; ++_) {
      for (auto &p : cnt[_]) {
        ll val = (p.first+(1ll<<b))%mo;
        res = max(res, p.second+(cnt[_^1].count(val) ? cnt[_^1][val] : 0));
      }
    }
  }
  cout << res << endl;
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