/*
 * @Author: Kaizyn
 * @Date: 2020-08-14 22:33:19
 * @LastEditTime: 2020-08-14 22:58:12
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e2+7;

int n[3];
int a[3][N];
multiset<pii> s[8];

bool empty() {
  return s[1|2].empty() || s[1|4].empty() || s[2|4].empty();
}

void erase(const pii &p) {
  for (int i = 1; i < 8; ++i) {
    if ((i>>p.second)&1) s[i].erase(s[i].find(p));
  }
}

inline void solve() {
  for (int i = 0; i < 3; ++i) cin >> n[i];
  for (int i = 0; i < 3; ++i) {
    for (int j = 1; j <= n[i]; ++j) {
      cin >> a[i][j];
      for (int k = 0; k < 8; ++k) if ((k>>i)&1) {
        s[k].insert({a[i][j], i});
      }
    }
  }
  int res = 0;
  while (!empty()) {
    pii t1 = *s[7].rbegin();
    erase(t1);
    int ver = 7^(1<<t1.second);
    assert(s[ver].size());
    pii t2 = *s[ver].rbegin();
    erase(t2);
    res += t1.first*t2.first;
  }
  cout << res << endl;
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