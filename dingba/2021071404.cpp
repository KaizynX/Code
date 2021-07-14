/*
 * @Author: Kaizyn
 * @Date: 2021-07-14 13:22:31
 * @LastEditTime: 2021-07-14 13:41:14
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e3+7;

int n, w, h;
ll A, B, P;
int a[N][N];
int qcv[N][N], qci[N][N], hc[N], tc[N];
int qrv[N], qri[N], hr, tr;

void insert(int *qv, int *qi, int &h, int &t, int v, int l, int r) {
  while (h < t && qi[h] < l) ++h;
  while (h < t && qv[t-1] <= v) --t;
  qv[t] = v; qi[t] = r; ++t;
}

inline void solve() {
  cin >> n >> w >> h >> A >> B >> P;
  for (int i = 1; i <= n; ++i) cin >> a[1][i];
  for (int i = 2; i <= n; ++i) cin >> a[i][1];
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= n; ++j) {
      a[i][j] = (A*a[i-1][j]+B*a[i][j-1])%P;
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j] << " \n"[j==n];
    }
  }
  #endif
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i < w; ++i) {
      insert(qcv[j], qci[j], hc[j], tc[j], a[i][j], i-w+1, i);
    }
  }
  ll res = 0;
  for (int i = w; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      insert(qcv[j], qci[j], hc[j], tc[j], a[i][j], i-w+1, i);
    }
    hr = tr = 0;
    for (int j = 1; j < h; ++j) {
      insert(qrv, qri, hr, tr, qcv[j][hc[j]], j-h+1, j);
    }
    for (int j = h; j <= n; ++j) {
      insert(qrv, qri, hr, tr, qcv[j][hc[j]], j-h+1, j);
      res += qrv[hr];
      #ifdef DEBUG
      cout << i-h+1 << "," << j-w+1 << ":" << qrv[hr] << '\n';
      #endif
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}