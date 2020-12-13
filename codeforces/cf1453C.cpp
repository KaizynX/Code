/*
 * @Author: Kaizyn
 * @Date: 2020-12-04 22:22:20
 * @LastEditTime: 2020-12-04 22:35:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

int n;
int a[N][N], rowl[10], rowr[10], coll[10], colr[10];

inline void solve() {
  cin >> n;
  memset(rowl, 1, sizeof(int)*10);
  memset(rowr, 0, sizeof(int)*10);
  memset(coll, 1, sizeof(int)*10);
  memset(colr, 0, sizeof(int)*10);
  for (int i = 1; i <= n; ++i) {
    static string str;
    cin >> str;
    for (int j = 1; j <= n; ++j) {
      a[i][j] = str[j-1]-'0';
      rowl[a[i][j]] = min(rowl[a[i][j]], i);
      rowr[a[i][j]] = max(rowr[a[i][j]], i);
      coll[a[i][j]] = min(coll[a[i][j]], j);
      colr[a[i][j]] = max(colr[a[i][j]], j);
    }
  }
  for (int d = 0; d <= 9; ++d) {
    int s = 0;
    for (int i = 1; i <= n; ++i) {
      int l = n, r = 1;
      for (int j = 1; j <= n; ++j) if (a[i][j] == d) {
        l = min(l, j);
        r = max(r, j);
      }
      if (l > r) continue;
      s = max(s, (r-l)*max(i-1, n-i));
      s = max(s, max(n-l, r-1)*max(i-rowl[d], rowr[d]-i));
    }
    for (int i = 1; i <= n; ++i) {
      int l = n, r = 1;
      for (int j = 1; j <= n; ++j) if (a[j][i] == d) {
        l = min(l, j);
        r = max(r, j);
      }
      if (l > r) continue;
      s = max(s, (r-l)*max(i-1, n-i));
      s = max(s, max(n-l, r-1)*max(i-coll[d], colr[d]-i));
    }
    cout << s << " \n"[d==9];
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