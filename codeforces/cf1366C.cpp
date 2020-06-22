/*
 * @Author: Kaizyn
 * @Date: 2020-06-11 22:31:58
 * @LastEditTime: 2020-06-11 22:42:46
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 40;

int n, m;
int a[N][N];
int cnt[N<<1][2];

inline void solve() {
  cin >> n >> m;
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, k; j <= m; ++j) {
      cin >> a[i][j];
      k = min(i+j, n+m+2-(i+j));
      ++cnt[k][a[i][j]];
    }
  }
  int res = 0;
  for (int i = 2; i <= n+m+2; ++i) {
    if (i == n+m+2-i) continue;
    res += min(cnt[i][0], cnt[i][1]);
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