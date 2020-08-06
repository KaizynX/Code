/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 23:18:11
 * @LastEditTime: 2020-07-24 14:45:13
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 2e5+7;
const int K = 22;

int n, k;
int a[N], b[N];
long long D;
vector<pii> e[N];
vector<vector<ll>> dp[N];

template <typename T>
inline void update(T &x, const T &y) {
  if (x == -1 || y < x) x = y;
}

vector<ll> dfs1(const int &u, const int fa) {
  vector<ll> res(k+1, -1); res[0] = 0;
  for (int i = 0, v, w; i < (int)e[u].size(); ++i) {
    v = e[u][i].first;
    w = e[u][i].second;
    if (v == fa) continue;
    vector<ll> vec = dfs1(v, u);
    for (int j = 0; j <= k; ++j) if (~vec[j]) {
      update(dp[u][i][j], vec[j]+b[w]);
      if (j+1 <= k) update(dp[u][i][j+1], vec[j]+a[w]);
      update(res[j], dp[u][i][j]);
    }
  }
  return res;
}

void dfs2(const int &u, const int &fa, const vector<ll> &vec) {
  vector<multiset<ll>> st(k+1);
  vector<ll> nex(k+1);
  st[0].insert(0);
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i].first;
    if (v == fa) dp[u][i] = vec;
    for (int j = 0; j <= k; ++j) {
      st[j].insert(dp[u][i][j]);
    }
    D = max(D, dp[u][i][k]);
  }
  for (int i = 0, v, w; i < (int)e[u].size(); ++i) {
    v = e[u][i].first;
    w = e[u][i].second;
    if (v == fa) continue;
    for (int j = 0; j <= k; ++j) nex[j] = -1;
    nex[0] = 0;
    for (int j = 0; j <= k; ++j) {
      st[j].erase(st[j].find(dp[u][i][j]));
      if (st[j].size()) {
        nex[j] = max(nex[j], *st[j].rbegin()+b[w]);
        if (j+1 <= k) nex[j+1] = max(nex[j+1], *st[j].rbegin()+a[w]);
      }
      st[j].insert(dp[u][i][j]);
    }
    dfs2(v, u, nex);
  }
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v >> a[i] >> b[i];
    e[u].emplace_back(v, i);
    e[v].emplace_back(u, i);
  }
  for (int i = 1; i <= n; ++i) {
    vector<vector<ll>>(e[i].size(), vector<ll>(k+1, -1)).swap(dp[i]);
  }
  D = 0;
  dfs1(1, 0);
  dfs2(1, 0, vector<ll>(k+1, -1));
  #ifdef DEBUG
  for (int u = 1; u <= n; ++u) {
    for (int i = 0, v; i < (int)e[u].size(); ++i) {
      v = e[u][i].first;
      printf("(%d %d):", u, v);
      for (int j = 0; j <= k; ++j) printf("%lld%c", dp[u][i][j], " \n"[j==k]);
    }
  }
  #endif
  cout << D << endl;
  for (int i = 1; i <= n; ++i) {
    vector<pii>().swap(e[i]);
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