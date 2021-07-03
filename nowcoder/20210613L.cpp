/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 15:04:26
 * @LastEditTime: 2021-06-13 15:15:20
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e3+7;

int a[2], w, h, res;
vector<int> v;

bool check(int x) {
  int last = 0, cnt = 0;
  for (int i = 0; i < w; ++i) {
    if (last == ((x>>i)&1)) ++cnt;
    else {
      if (cnt%a[last]) return false;
      last ^= 1;
      cnt = 1;
    }
  }
  return cnt%a[last] == 0;
}

bool check(int x, int y) {
  for (int i = 1; i < w; ++i) {
    int lbx = (x>>(i-1))&1, lby = (y>>(i-1))&1;
    int rbx = (x>>i)&1, rby = (y>>i)&1;
    if (lbx == lby && rbx == rby && lbx != rbx) return false;
  }
  return true;
}

inline void solve() {
  // cin >> a[0] >> a[1] >> w >> h;
  v.clear();
  for (int i = 0; i < 1<<w; ++i) {
    if (check(i)) v.emplace_back(i);
  }
  cout << w << ' ' << a[0] << ' ' << a[1] << ' ' << v.size() << '\n';
  res = max(res, (int)v.size());
  /*
  for (int i = 0; i < (int)v.size(); ++i) {
    for (int j = 0; j < (int)v.size(); ++j) {
      if (check(v[i], v[j])) ;
    }
  }
  */
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    // solve();
  }
  for (w = 2; w <= 20; ++w)
  for (a[0] = 2; a[0] <= 10; ++a[0])
  for (a[1] = 2; a[1] <= 10; ++a[1]) if (a[0] != a[1]) {
    solve();
  }
  cout << res << '\n';
  return 0;
}