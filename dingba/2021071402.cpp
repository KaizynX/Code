/*
 * @Author: Kaizyn
 * @Date: 2021-07-14 15:34:25
 * @LastEditTime: 2021-07-14 16:21:31
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
const int dir[] = {0,-1,0,1,0};

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n, m, k, res;
int vis[N], dfn;
DSU dsu;
map<int, map<int, int>> mp;
set<pii> pt;
vector<int> e[N];

void dfs1(int x, int y) {
  for (int dx : {-1, 1}) {
    for (int dy : {-1, 1}) {
      if (pt.count(pii{x+dx, y}) && pt.count(pii{x, y+dy})) {
        if (pt.count(pii{x+dx, y+dy})) {
          dsu.merge(mp[x][y], mp[x+dx][y+dy]);
          dsu.merge(mp[x][y], mp[x+dx][y]);
          dsu.merge(mp[x][y], mp[x][y+dy]);
          // res += x == 1 || x == n;
          // res += y == 1 || y == m;
        } else {
          --res;
        }
      }
    }
  }
}

void dfs2(int x, int y) {
  if (x == 1 || y == 1 || x == n || y == m) {
    e[0].emplace_back(mp[x][y]);
    e[mp[x][y]].emplace_back(0);
  }
  for (int dx : {-1, 0, 1}) {
    for (int dy : {-1, 0, 1}) {
      if (dx == 0 && dy == 0) continue;
      if (pt.count(pii{x+dx, y+dy}) == 0) continue;
      int u = dsu[mp[x][y]], v = dsu[mp[x+dx][y+dy]];
      if (u == v) continue;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
  }
}

void dfs(int u, int fa) {
  if (vis[u]) return res += vis[u] < vis[fa], void();
  vis[u] = ++dfn;
  for (const int &v : e[u]) if (v != fa) {
    dfs(v, u);
  }
}

inline void solve() {
  cin >> n >> m >> k;
  dsu.init(k);
  int x, y;
  for (int i = 1; i <= k; ++i) {
    cin >> x >> y;
    mp[x][y] = i;
    pt.insert(pii{x, y});
  }
  for (const auto &it : pt) {
    x = it.first;
    y = it.second;
    dfs1(x, y);
  }
  for (const auto &it : pt) {
    x = it.first;
    y = it.second;
    dfs2(x, y);
  }
  for (int i = 0; i <= k; ++i) {
    if (dsu[i] != i) continue;
    if (vis[i]) continue;
    dfs(i, k+1);
  }
  for (const auto &it : pt) {
    x = it.first;
    y = it.second;
    res -= (x == 1 || x == n) && pt.count(pii{x, y-1});
    res -= (y == 1 || y == m) && pt.count(pii{x-1, y});
  }
  cout << res+1 << '\n';
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