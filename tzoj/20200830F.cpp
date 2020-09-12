/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 13:22:00
 * @LastEditTime: 2020-08-30 13:28:59
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
const int M = 10;

int n, m;
int a[M];

inline void solve() {
  for (int i = 0; i < m; ++i) cin >> a[i];
  if (n == 0) return cout << 0 << endl, void();
  sort(a, a+m);
  int res = 0;
  for (int b = 0; b < 1<<m; ++b) {
    // int k = __builtin_popcount(b);
    vector<int> aa;
    for (int i = 0; i < m; ++i) if ((b>>i)&1) {
      aa.emplace_back(a[i]);
    }
    do {
      int val = 0;
      for (auto &i : aa) val = val*10+i;
      if (val == 0) continue;
      if (val%n == 0) res = res ? min(val, res) : val;
    } while (next_permutation(aa.begin(), aa.end()));
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) solve();
  return 0;
}