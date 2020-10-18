/*
 * @Author: Kaizyn
 * @Date: 2020-10-01 00:30:12
 * @LastEditTime: 2020-10-01 00:47:47
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n, h, t;
vector<pii> res;
vector<int> vec;

inline void solve() {
  cin >> n;
  for (int b = 2; b <= n; b *= 2) {
    for (int i = 1; i+b-1 <= n; i += b) {
      for (int j = 0; j < b/2; ++j) {
        res.emplace_back(i+j, i+b/2+j);
      }
    }
  }
  for (int i = 0; i < (n&-n); ++i) vec.emplace_back(n-i);
  n -= n&-n;
  h = 0; t = n;
  while (__builtin_popcount(n) > 1) {
    int b = n&-n;
    n -= b;
    while (b > (int)vec.size()) {
      for (int i = 0, sz = vec.size(); i < sz; ++i) {
        ++h;
        res.emplace_back(vec[i], h);
        vec.emplace_back(h);
      }
    }
    for (int i = 0, sz = vec.size(); i < sz; ++i) {
      res.emplace_back(vec[i], t);
      vec.emplace_back(t);
      --t;
    }
  }
  cout << res.size() << endl;
  for (auto &p : res) cout << p.first << " " << p.second << endl;
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