/*
 * @Author: Kaizyn
 * @Date: 2020-08-22 19:58:44
 * @LastEditTime: 2020-08-22 21:35:18
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
int a[N*3];
int dp[N][N], mv[N], curmv[N], curdp[N];

inline void update(int x, int y, int z) {
  if (x > y) swap(x, y);
  if (z <= dp[x][y]) return;
  dp[x][y] = z;
  mv[x] = max(mv[x], z);
  mv[y] = max(mv[y], z);
  #ifdef DEBUG
  // cout << x << " " << y << " " << z << endl;
  #endif
}

#ifdef DEBUG
void print() {
  cout << "***********\n";
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cout << dp[i][j] << " \n"[j==n];
  for (int i = 1; i <= n; ++i) cout << mv[i] << " \n"[i==n];
  cout << "***********" << endl;
}
#endif

inline void solve() {
  cin >> n;
  for (int i = 1; i <= 3*n; ++i) cin >> a[i];
  memset(dp, 0x9f, sizeof dp);
  memset(mv, 0x9f, sizeof mv);
  update(a[1], a[2], 0);
  int base = 0;
  for (int i = 3; i+2 <= 3*n; i += 3) {
    if (a[i] == a[i+1] && a[i] == a[i+2]) {
      ++base;
      continue;
    }
    int b[3], maxv = 0;
    sort(a+i, a+i+3);
    if (a[i+1] == a[i+2]) swap(a[i], a[i+2]); // fuck there
    for (int j = 1; j <= n; ++j) {
      curdp[j] = dp[min(a[i], j)][max(a[i], j)];
      curmv[j] = mv[j];
      maxv = max(maxv, mv[j]);
    }
    for (int j = 0; j < 3; ++j) b[j] = dp[a[i+j]][a[i+j]];
    // spj
    if (a[i] == a[i+1]) for (int j = 1; j <= n; ++j) { // fuck here
      update(a[i+2], j, curdp[j]+1); // dp[a[i]][j] -> dp[a[i+2]][j]
    }
    update(a[i+1], a[i+2], b[0]+1); // get three a[i]
    update(a[i], a[i+2], b[1]+1); // get three a[i+1]
    update(a[i], a[i+1], b[2]+1); // get three a[i+2]
    // two of three rest
    update(a[i+1], a[i+2], maxv);
    update(a[i], a[i+2], maxv);
    update(a[i], a[i+1], maxv);
    // one of three rest
    for (int j = 1; j <= n; ++j) {
      update(a[i], j, curmv[j]);
      update(a[i+1], j, curmv[j]);
      update(a[i+2], j, curmv[j]);
    }
#ifdef DEBUG
    cout << i << ":\n"; print();
#endif
  }
  int res = dp[a[3*n]][a[3*n]]+1;
  for (int i = 1; i <= n; ++i) res = max(res, mv[i]);
  cout << res+base << endl;
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