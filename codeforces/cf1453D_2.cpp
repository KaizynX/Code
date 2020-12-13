/*
 * @Author: Kaizyn
 * @Date: 2020-12-04 22:54:28
 * @LastEditTime: 2020-12-04 22:56:06
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
#define log(x) (31-__builtin_clz(x))
// const int N = ;

long long k;
vector<int> res;

inline void solve() {
  cin >> k;
  if (k&1) return cout << -1 << endl, void();
  res.clear();
  while (k) {
    res.emplace_back(1);
    k -= 2;
    for (long long b = 4; b <= k; b *= 2) {
      res.emplace_back(0);
      k -= b;
    }
  }
  cout << res.size() << endl;
  for (int &i : res) cout << i << " ";
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}