/*
 * @Author: Kaizyn
 * @Date: 2021-08-03 13:22:41
 * @LastEditTime: 2021-08-03 15:57:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MOD = 998244353; // 1e9+7;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1e5+7;

int n;
int p[N];
ll res;
multiset<ll> st[N];
multiset<pll> stmx[N];
vector<pii> e[N];
vector<pll> dp[N], mx1[N];

void update(int u) {
  if (st[u].size() == 1u) {
    res = min(res, *st[u].begin());
    return;
  }
  ll cur = *st[u].rbegin();
  st[u].erase(--st[u].end());
  res = min(res, cur+*st[u].rbegin());
  st[u].insert(cur);
}

pll dfs(int u, int fa) {
  dp[u].resize(e[u].size());
  mx1[u].resize(e[u].size());
  st[u].clear();
  if (e[u].size() <= 1u) return pll{0, 0};
  for (int i = 0; i < (int)e[u].size(); ++i) {
    int v = e[u][i].first;
    int w = e[u][i].second;
    if (v == fa) continue;
    pll son = dfs(v, u);
    dp[u][i] = pll{
        max(son.first+w, son.second+max(0, w-p[v])),
        max(son.first+max(0, w-p[u]), son.second+max(0, w-p[u]-p[v]))
    };
    st[u].insert(dp[u][i].first);
  }
  pll ret = pll{INF, *st[u].rbegin()};
  for (int i = 0; i < (int)e[u].size(); ++i) {
    int v = e[u][i].first;
    if (v == fa) continue;
    st[u].erase(st[u].find(dp[u][i].first));
    st[u].insert(dp[u][i].second);
    ret.first = min(ret.first, *st[u].rbegin());
    st[u].erase(st[u].find(dp[u][i].second));
    st[u].insert(dp[u][i].first);
  }
  return ret;
}

void dfs2(int u, int fa, pll last) {
  st[u].clear();
  stmx[u].clear();
  for (int i = 0; i < (int)e[u].size(); ++i) {
    int v = e[u][i].first;
    if (v == fa) dp[u][i] = last;
    st[u].insert(dp[u][i].first);
    stmx[u].insert(pll{dp[u][i].second, -dp[u][i].first});
  }
  for (int i = 0; i < (int)e[u].size(); ++i) {
    st[u].erase(st[u].find(dp[u][i].first));
    st[u].insert(dp[u][i].second);
    update(u);
    st[u].erase(st[u].find(dp[u][i].second));
    st[u].insert(dp[u][i].first);
  }
  for (int i = 0; i < (int)e[u].size(); ++i) {
    int v = e[u][i].first;
    if (v == fa) continue;
    stmx[u].erase(stmx[u].find(pll{dp[u][i].second, -dp[u][i].first}));
    if (stmx[u].empty()) {
      dfs2(v, u, pll{*st[u].rbegin(), 0});
    } else {
      pll tmp = *stmx[u].rbegin();
      stmx[u].erase(--stmx[u].end());
      stmx[u].insert(pll{-tmp.second, 0});
      dfs2(v, u, pll{*st[u].rbegin(), stmx[u].rbegin()->first});
      stmx[u].erase(stmx[u].find(pll{-tmp.second, 0}));
      stmx[u].insert(tmp);
    }
    stmx[u].insert(pll{dp[u][i].second, -dp[u][i].first});
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  res = INF;
  dfs(1, 0);
  dfs2(1, 0, pll{0, 0});
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) e[i].clear();
  }
  return 0;
}