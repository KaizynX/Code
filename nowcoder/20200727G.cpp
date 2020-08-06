/*
 * @Author: Kaizyn
 * @Date: 2020-07-27 13:10:32
 * @LastEditTime: 2020-07-27 14:16:12
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

int n, k;
int a[N<<1][N];

inline void solve() {
  cin >> n >> k;
  int sum = (n+1)*n*2;
  if (n == 1 || k == 1 || sum%k) return cout << -1 << endl, void();
  for (int i = 0, u = 0; i <= n*2; ++i) {
    for (int j = ~i&1; j <= n; ++j) {
      a[i][j] = u+1;
      u = (u+1)%k;
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i*2][j] << " \n"[j==n];
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[j*2-1][i] << " \n"[j==n];
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  /*
  for (int n = 1; n <= 200; ++n) {
    int sum = 2*n*(n+1);
    for (int k = 2; k*k <= 2*n+1; ++k) {
      if ((2*n+1)%k) continue;
      if (sum%k == 0) cout << n << " " << k << endl;
      int kk = (2*n+1)/k;
      if (kk == k) continue;
      if (sum%kk == 0) cout << n << " " << kk << endl;
    }
  }
  */
  return 0;
}