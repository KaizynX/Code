/*
 * @Author: Kaizyn
 * @Date: 2020-09-02 18:57:04
 * @LastEditTime: 2020-09-02 19:01:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

int n, m;
string s, t = "zsbd";

inline void solve() {
  cin >> n >> s;
  m = s.size();
  cout << s;
  while (m < n) cout << t, m += 4;
  cout << endl;
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