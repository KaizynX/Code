/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 13:38:26
 * @LastEditTime: 2020-05-30 14:05:15
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
pii p;

inline void solve1() {
  for (int i = 8; i >= 0; i -= 4) {
    if (c[i]) {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
}

inline void update(const int &x, const int &y) {
  if (p == make_pair(-1, -1)) return p = {x, y}, void();
  int l = max(p.first, p.second)*1000+min(p.first, p.second)*100+x*10+y;
  int r = max(x, y)*1000+min(x, y)*100+p.first*10+p.second;
  if (l > r) p = {x, y};
}

inline void solve() {
  int k = 0;
  for (int i = 0; i <= 9; ++i) {
    cin >> c[i];
    if (c[i]) ++k;
  }
  if (k == 1 && c[0]) return cout << 0 << endl, void();
  p = {-1, -1};
  for (int i = 0; i < 100; i += 4) {
    if ((i/10 == i%10 && c[i/10] >= 2) ||
        (i/10 != i%10 && c[i/10] && c[i%10])) {
      update(i/10, i%10);
    }
  }
  if (p != make_pair(-1, -1)) {
    if ((p.second*10+p.first)%4 == 0) swap(p.first, p.second);
    --c[p.first]; --c[p.second];
    for (int i = 9; i >= 0; --i) {
      for (int j = 1; j <= c[i]; ++j) cout << i;
    }
    cout << p.first << p.second << endl;
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