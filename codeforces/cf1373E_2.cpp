/*
 * @Author: Kaizyn
 * @Date: 2020-06-26 00:12:59
 * @LastEditTime: 2020-06-26 20:28:21
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 9e18;

int n, k;
long long pw10[20];

inline int f(long long x) {
  int res = 0;
  while (x) {
    res += x%10;
    x /= 10;
  }
  return res;
}

inline long long calc(int rest, int cnt) {
  if (rest%cnt) return -1;
  long long res = 0;
  for (int i = 1, dig; rest > 0; ++i) {
    dig = min(9, rest/cnt);
    rest -= dig*cnt;
    res += dig*pw10[i];
  }
  return res;
}

inline void solve() {
  cin >> n >> k;
  long long res = INF, cur;
  for (int fir = 0, rest; fir < 10; ++fir) {
    rest = n;
    for (int i = fir; i <= fir+k; ++i) rest -= i%10;
    if (rest < 0) continue;
    if (fir+k < 10) {
      cur = calc(rest, k+1);
      if (cur != -1) res = min(res, cur+fir);
    } else {
      for (int s = 0; s <= rest; ++s) {
        cur = calc(s, 10-fir);
        if (cur == -1) continue;
        if ((k+1-(10-fir))*f(cur+10) == rest-s) res = min(res, cur+fir);
        cur = calc(rest-s, k+1-(10-fir));
        if (cur == -1 || cur < 10) continue;
        if ((10-fir)*f(cur-10) == s) res = min(res, cur-10+fir);
      }
    }
  }
  cout << (res >= INF ? -1 : res) << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  pw10[0] = 1;
  for (int i = 1; i <= 18; ++i) pw10[i] = pw10[i-1]*10;
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}