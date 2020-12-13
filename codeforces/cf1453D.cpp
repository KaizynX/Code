/*
 * @Author: Kaizyn
 * @Date: 2020-12-04 20:58:40
 * @LastEditTime: 2020-12-04 22:49:10
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
  if (k <= 4e3) {
    cout << k/2 << endl;
    for (int i = 1; i <= k/2; ++i) cout << 1 << " \n"[i==k/2];
    return;
  }
  int cnt = 1000;
  k -= 2*cnt;
  if (k&2) ++cnt, k -= 2;
  res = vector<int>(1, 1);
  --cnt;
  for (long long b; k; k -= b) {
    b = k&-k;
    for (int i = 1; i < log(b); ++i) res.emplace_back(0);
    res.emplace_back(1);
    --cnt;
  }
  while (cnt--) res.emplace_back(1);
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