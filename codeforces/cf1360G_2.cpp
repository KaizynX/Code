/*
 * @Author: Kaizyn
 * @Date: 2020-05-24 22:03:57
 * @LastEditTime: 2020-05-24 23:08:51
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 55;

int n, m, x, y;
int a[N][N];

inline void solve() {
  cin >> n >> m >> x >> y;
  if (n*x%m || m*y%n || m*y != n*x)
    return cout << "NO" << endl, void(); 
  cout << "YES" << endl;
  int g = __gcd(m, x);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = i*g; k < i*g+x; ++k) {
        a[i][k%m] = 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
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