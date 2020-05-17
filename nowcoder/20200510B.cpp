/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 13:17:37
 * @LastEditTime: 2020-05-10 13:29:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e3+7;

string s, subs;
stringstream ss;

inline void solve() {
  cin >> s;
  int len = s.size();
  long long res = 0;
  for (int i = 0, j = 0, n, x; j <= len; ++j) {
    if (s[j] == '+' || j == len) {
      subs = s.substr(i, j-i);
      int p = subs.find('d');
      if (p == subs.npos) {
        ss.clear();
        ss << subs;
        ss >> x;
        res += x*2ll;
        continue;
      }
      ss.clear();
      ss << subs.substr(0, p);
      ss >> n;
      ss.clear();
      ss << subs.substr(p+1);
      ss >> x;
      res += n*(1ll+x);
      i = j+1;
    }
  }
  if (res&1) cout << res/2 << ".5" << endl;
  else cout << res/2 << endl;
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