/*
 * @Author: Kaizyn
 * @Date: 2020-05-17 18:41:34
 * @LastEditTime: 2020-05-17 19:13:45
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e3+7;

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
};

int n, m, t;
int n1, n2, n3;
DSU dsu;
int col[N], cnt[N][2];
int dp[N][N];
int mp[N], pt[N], paint[N];
int res[N];
vector<int> e[N];
queue<int> q;
vector<int> odd;

void bfs(const int &s) {
  q.push(s);
  col[s] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (const int &v : e[u]) {
      if (col[v] == -1) {
        col[v] = col[u]^1;
        q.push(v);
        dsu.merge(u, v);
      } else {
        if (col[u] == col[v]) {
          cout << "NO" << endl;
          exit(0);
        }
      }
    }
  }
}

inline void solve() {
  memset(col, -1, sizeof col);
  cin >> n >> m;
  cin >> n1 >> n2 >> n3;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  dsu.init(n);
  for (int i = 1; i <= n; ++i) {
    if (col[i] == -1) bfs(i);
  }
  for (int i = 1; i <= n; ++i) {
    ++cnt[dsu[i]][col[i]];
    if (dsu[i] == i) {
      pt[++t] = i;
      mp[i] = t;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= t; ++i) {
    for (int j = cnt[pt[i]][0]; j <= n; ++j) {
      dp[i][j] |= dp[i-1][j-cnt[pt[i]][0]];
    }
    for (int j = cnt[pt[i]][1]; j <= n; ++j) {
      dp[i][j] |= dp[i-1][j-cnt[pt[i]][1]];
    }
  }
  if (!dp[t][n2]) return void(cout << "NO" << endl);
  for (int i = t, rest = n2; i; --i) {
    if (rest-cnt[pt[i]][0] >= 0 && dp[i-1][rest-cnt[pt[i]][0]]) {
      rest -= cnt[pt[i]][0];
      paint[pt[i]] = 0;
    } else {
      rest -= cnt[pt[i]][1];
      paint[pt[i]] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (col[i] == paint[dsu[i]]) res[i] = 2;
    else odd.emplace_back(i);
  }
  for (int i = 0; i < (int)odd.size(); ++i) {
    res[odd[i]] = (i < n1 ? 1 : 3);
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) cout << res[i];
  cout << endl;
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