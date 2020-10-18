/*
 * @Author: Kaizyn
 * @Date: 2020-10-11 17:03:54
 * @LastEditTime: 2020-10-11 17:52:03
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
char s[N];
vector<int> t;

inline void solve() {
  t.clear();
  cin >> n >> (s+1);
  int cnt = 1;
  for (int i = 2; i <= n; ++i) {
    if (s[i] == s[i-1]) ++cnt;
    else t.emplace_back(cnt), cnt = 1;
  }
  t.emplace_back(cnt);
  #ifdef DEBUG
  for (auto &i : t) cout << i << " ";
  cout << endl;
  #endif
  int p = 0, res = 0, l = 0, r = t.size()-1;
  while (l <= r) {
    p = max(p, l);
    while (p <= r && t[p] <= 1) ++p;
    p = min(p, r);
    --t[p];
    while (l <= r && t[r] == 0) --r;
    while (l <= r && t[l] == 0) ++l;
    ++l;
    ++res;
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