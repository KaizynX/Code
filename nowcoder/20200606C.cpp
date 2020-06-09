/*
 * @Author: Kaizyn
 * @Date: 2020-06-06 14:00:53
 * @LastEditTime: 2020-06-06 14:07:10
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+27;

int x, m, n;
int a[N];

inline void solve() {
  cin >> x >> m >> n;
  memset(a+1, 0, sizeof(int)*n);
  a[8] = 1; a[14] = -1;
  --m;
  int cur = 0;
  for (int i = 1, t; i <= n; ++i) {
    cur += a[i];
    t = (int)min(1ll*m, 1ll*x*cur);
    m -= t;
    a[i+7] += t;
    a[i+13] -= t;
  }
  cout << cur << endl;
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