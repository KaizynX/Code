/*
 * @Author: Kaizyn
 * @Date: 2021-07-14 12:46:32
 * @LastEditTime: 2021-07-14 14:33:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
const int K = 41;

int n, m;
int d[N<<1], op[N], del[N<<1];
// f[i][j] 以i为端点长度为j的路径数
// s[i][j] 经过i且不以i为端点的长度为j的路径数
ll s[N<<1][K], f[N<<1][K], all[K], res[N];

void build() {
  for (int i = n; i; --i) {
    d[i] = max(d[i<<1], d[i<<1|1])+1;
    f[i][0] = 1;
    for (int j = 0; j < d[i]; ++j) {
      f[i][j+1] = (!del[i<<1])*f[i<<1][j]+(!del[i<<1|1])*f[i<<1|1][j];
      all[j+1] += f[i][j+1];
    }
    if (!del[i<<1] && !del[i<<1|1])
    for (int j = 0; j < d[i<<1]; ++j) {
      for (int k = 0; k < d[i<<1|1]; ++k) {
        s[i][j+k+2] += f[i<<1][j]*f[i<<1|1][k];
        all[j+k+2] += f[i<<1][j]*f[i<<1|1][k];
      }
    }
    // for (int j = 2; j < d[i<<1]+d[i<<1|1]+2; ++j) s[i][j+k+2] /= 2;
    // for (int j = 1; j < d[i<<1]; ++j) s[i][j] += s[i<<1][j];
    // for (int j = 1; j < d[i<<1|1]; ++j) s[i][j] += s[i<<1|1][j];
    // for (int j = 1; j < d[i]; ++j) s[i][j] += f[i][j];
  }
}

void add(int x) {
  static ll g[K];
  memcpy(g, f[x], sizeof g);
  del[x] = 0;
  for (int i = x; i/2 && !del[i]; i /= 2) {
    for (int j = 0; j < d[i/2]; ++j) {
      f[i/2][j+1] += g[j];
      all[j+1] += g[j];
    }
    if (!del[i^1])
    for (int j = 0; j < d[i]; ++j)
    for (int k = 0; k < d[i^1]; ++k) {
      s[i/2][j+k+2] += g[j]*f[i^1][k];
      all[j+k+2] += g[j]*f[i^1][k];
    }
    for (int k = K-1; k; --k) g[k] = g[k-1];
    g[0] = 0;
  }
}

inline void solve() {
  cin >> n >> m;
  del[1] = 1;
  for (int i = 1; i <= m; ++i) {
    static char ch;
    cin >> ch >> op[i];
    if (ch == '-') {
      del[op[i]] = 1;
      op[i] = -op[i];
    }
  }
  build();
  for (int i = m; i; --i) {
    if (op[i] > 0) {
      for (int j = 1; j <= op[i]; ++j) res[i] += all[j];
    } else {
      add(-op[i]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (op[i] < 0) continue;
    cout << res[i] << '\n';
  }
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