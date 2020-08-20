/*
 * @Author: Kaizyn
 * @Date: 2020-08-09 20:05:10
 * @LastEditTime: 2020-08-09 20:28:07
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

int n;
int dif[N];
string s, t;

inline void solve() {
  cin >> n >> s >> t;
  dif[n] = dif[n+1] = 0;
  for (int i = n-1; i >= 0; --i) {
    dif[i] = dif[i+1]+(s[i] != t[i]);
  }
  s += '0';
  t += '0';
  int res = dif[0];
  for (int i = 0, s0 = 0, t1 = 0; i < n; ++i) {
    // turn[0, i] to 0 use +1
    s0 += s[i] == '0';
    t1 += t[i] == '1';
    int cnt = s0+1+t1;
    cnt += (s[i+1] == '1');
    cnt += (t[i+1] != '1');
    cnt += dif[i+2];
    res = min(res, cnt);
  }
  cout << res << endl;
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