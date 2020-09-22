/*
 * @Author: Kaizyn
 * @Date: 2020-09-14 22:32:32
 * @LastEditTime: 2020-09-14 22:58:47
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, q;
int a[N];
set<int> num;
multiset<int> gap;

int query() {
  if (num.size() <= 2) return 0;
  return *num.rbegin()-*num.begin()-*gap.rbegin();
}

inline void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    num.insert(a[i]);
  }
  sort(a+1, a+n+1);
  for (int i = 1; i < n; ++i) {
    gap.insert(a[i+1]-a[i]);
  }
  cout << query() << endl;
  for (int i = 1, t, x, l, r; i <= q; ++i) {
    cin >> t >> x;
    if (t) {
      auto it = num.upper_bound(x);
      r = it == num.end() ? 0 : *it;
      l = it == num.begin() ? 0 : *(--it);
      if (l && r) gap.erase(gap.find(r-l));
      if (l) gap.insert(x-l);
      if (r) gap.insert(r-x);
      num.insert(x);
    } else {
      auto it = num.upper_bound(x);
      r = it == num.end() ? 0 : *it;
      it = num.lower_bound(x);
      l = it == num.begin() ? 0 : *(--it);
      if (l && r) gap.insert(r-l);
      if (l) gap.erase(gap.find(x-l));
      if (r) gap.erase(gap.find(r-x));
      num.erase(x);
    }
    cout << query() << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}