/*
 * @Author: Kaizyn
 * @Date: 2020-05-24 22:22:41
 * @LastEditTime: 2020-05-24 22:50:18
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 20;

int n, m;
string s[N];

inline int dif(const string &a, const string &b) {
  int cnt = 0;
  for (int i = 0; i < m; ++i) cnt += a[i] != b[i];
  return cnt;
}

inline bool check(const string &str) {
  for (int i = 2; i <= n; ++i) {
    if (dif(str, s[i]) > 1) return false;
  }
  return true;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  int p = 0;
  for (int i = 2, d; i <= n; ++i) {
    d = dif(s[1], s[i]);
    if (d >= 3) return cout << -1 << endl, void();
    if (d == 2) p = i;
  }
  if (!p) return cout << s[1] << endl, void();
  string res = s[1];
  for (int i = 0; i < m; ++i) {
    if (s[1][i] != s[p][i]) {
      res[i] = s[p][i];
      if (check(res)) return cout << res << endl, void();
      res[i] = s[1][i];
    }
  }
  cout << -1 << endl;
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