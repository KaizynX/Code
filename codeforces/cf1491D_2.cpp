/*
 * @Author: Kaizyn
 * @Date: 2021-02-28 23:02:53
 * @LastEditTime: 2021-02-28 23:09:20
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
// const int N = ;

vector<int> vu, vv;

inline bool solve(int u, int v) {
  if (u > v) return false;
  vu.clear();
  vv.clear();
  for (int i = 0; i < 30; ++i) {
    if ((u>>i)&1) vu.emplace_back(i);
    if ((v>>i)&1) vv.emplace_back(i);
  }
  while (vv.size()) {
    while (vu.size() && vu.back() > vv.back()) vu.pop_back();
    if (vu.size()) vu.pop_back(), vv.pop_back();
    else return false;
  }
  return true;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1, u, v; t <= T; ++t) {
    cin >> u >> v;
    cout << (solve(u, v) ? "YES" : "NO") << '\n';
  }
  return 0;
  return 0;
}