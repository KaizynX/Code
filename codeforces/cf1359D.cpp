/*
 * @Author: Kaizyn
 * @Date: 2020-05-28 22:21:18
 * @LastEditTime: 2020-05-28 23:03:26
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
int a[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int v = 1; v <= 30; ++v) {
    int cur = 0, tmp = 0;
    for (int i = 1; i <= n; ++i) {
      tmp += a[i];
      if (tmp < 0 || a[i] > v) {
        tmp = 0;
      }
      cur = max(cur, tmp);
    }
    res = max(res, cur-v);
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