/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 13:38:26
 * @LastEditTime: 2020-05-30 14:15:55
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int c[10];
int resx, resy;

inline void solve1() {
  for (int i = 8; i >= 0; i -= 4) {
    if (c[i]) {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
}

inline bool cmp(const int &x, const int &y) {
  if (resx == -1 && resy == -1) return true;
  for (int i = 9, l, r; i >= 0; --i) {
    l = c[i]-(resx == i)-(resy == i);
    r = c[i]-(x == i)-(y == i);
    if (l != r) return l < r;
  }
  return resx*10+resy < x*10+y;
}

inline void solve() {
  int k = 0;
  for (int i = 0; i <= 9; ++i) {
    cin >> c[i];
    if (c[i]) ++k;
  }
  if (k == 1 && c[0]) return cout << 0 << endl, void();
  resx = resy = -1;
  for (int i = 0; i < 100; i += 4) {
    if ((i/10 == i%10 && c[i/10] >= 2) ||
        (i/10 != i%10 && c[i/10] && c[i%10])) {
      if (cmp(i/10, i%10)) resx = i/10, resy = i%10;
    }
  }
  if (resx != -1 && resy != -1) {
    --c[resx]; --c[resy];
    for (int i = 9; i >= 0; --i) {
      for (int j = 1; j <= c[i]; ++j) cout << i;
    }
    cout << resx << resy << endl;
    return;
  }
  solve1();
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