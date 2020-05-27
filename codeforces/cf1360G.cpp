/*
 * @Author: Kaizyn
 * @Date: 2020-05-24 22:03:57
 * @LastEditTime: 2020-05-24 22:17:13
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
int col[N], row[N];

inline void solve() {
  cin >> n >> m >> x >> y;
  if (n*x%m || m*y%n || m*y != n*x)
    return cout << "NO" << endl, void(); 
  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) row[i] = 0;
  for (int i = 1; i <= m; ++i) col[i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (row[i] < x && col[j] < y) {
        cout << "1";
        ++row[i];
        ++col[j];
      } else {
        cout << "0";
      }
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