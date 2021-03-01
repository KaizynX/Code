/*
 * @Author: Kaizyn
 * @Date: 2021-02-28 23:35:00
 * @LastEditTime: 2021-02-28 23:40:18
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n;
int fib[26];

inline void solve() {
  ;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  fib[0] = 1; fib[1] = 2;
  for (int i = 2; i <= 25; ++i) {
    fib[i] = fib[i-1]+fib[i-2];
  }
  map<int, int> vis;
  for (int i = 0; i <= 25; ++i) {
    for (int j = 0; j <= i; ++j) {
      ++vis[fib[i]+fib[j]];
    }
  }
  for (auto &p : vis) {
    if (p.second > 1) {
      cout << p.first << " " << p.second << '\n';
    }
  }
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}