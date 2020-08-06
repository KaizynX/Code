/*
 * @Author: Kaizyn
 * @Date: 2020-07-11 15:52:20
 * @LastEditTime: 2020-07-11 16:35:35
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e4+7;

int n, q;
int a[N], son[N], mn[N][N], mx[N][N];
vector<int> e[N];

void dfs(const int &u) {
  son[u] = 1;
  mn[u][0] = mx[u][0] = 0;
  mn[u][1] = mx[u][1] = a[u];
  for (const int &v : e[u]) {
    dfs(v);
    for (int i = 1; i <= son[v]; ++i) {
      mn[u][son[u]+i] = INF;
      mx[u][son[u]+i] = 0;
    }
    /*
    for (int i = son[u]+son[v]; i > 1; --i) {
      for (int j = max(0, i-son[u]); j <= min(i-1, son[v]); ++j) {
        mn[u][i] = min(mn[u][i], mn[v][i-j]+mn[v][j]);
        mx[u][i] = max(mx[u][i], mx[v][i-j]+mx[v][j]);
      }
    }
    */
    for (int i = son[u]; i; --i) for (int j = son[v]; j; --j) {
      mn[u][i+j] = min(mn[u][i+j], mn[u][i]+mn[v][j]);
      mx[u][i+j] = max(mx[u][i+j], mx[u][i]+mx[v][j]);
    }
    son[u] += son[v];
  }
}

inline void solve() {
  // memset(mn, 0x3f, sizeof mn);
  // memset(mx, 0, sizeof mx);
  static string str;

  cin >> n >> q;
  for (int i = 1, fa; i <= n; ++i) {
    cin >> fa;
    e[fa].emplace_back(i);
  }
  cin >> str;
  for (int i = 1; i <= n; ++i) a[i] = str[i-1] == 'C';
  dfs(e[0][0]);
  for (int i = 1, x, c, s; i <= q; ++i) {
    cin >> x >> c >> s;
    // cout << mn[x][c+s] << " " << mx[x][c+s] << endl;
    cout << (c+s <= son[x] && c >= mn[x][c+s] && c <= mx[x][c+s] \
        ? "COMPROMISED\n" : "NOT COMPROMISED\n");
  }
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