/*
 * @Author: Kaizyn
 * @Date: 2020-08-04 11:58:50
 * @LastEditTime: 2020-08-04 13:50:32
 */

#pragma comment (linker, "/STACK:102400000,102400000")///手动扩栈

#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, k;
ll res;
vector<pii> e[N];
vector<ll> dp[N];
vector<int> rk[N];

ll dfs1(const int &u, const int &fa) {
  for (int i = 0, v, w; i < (int)e[u].size(); ++i) {
    v = e[u][i].first;
    w = e[u][i].second;
    if (v == fa) continue;
    dp[u][i] = dfs1(v, u)+w;
    rk[u][i] = i;
  }
  sort(rk[u].begin(), rk[u].end(), [&](int x, int y) {
    return dp[u][x] > dp[u][y];
  });
  ll res = 0;
  for (int i = 0; i < (int)e[u].size() && i < k; ++i) {
    res += dp[u][rk[u][i]];
  }
  return res;
}

void dfs2(const int &u, const int &fa, const ll &fa_val) {
  ll sum = 0;
  int sz = e[u].size();
  for (int i = 0, v; i < sz; ++i) {
    v = e[u][i].first;
    if (v == fa) dp[u][i] = fa_val;
    sum += dp[u][i];
    rk[u][i] = i;
  }
  res = max(res, sum);
  sum = 0;
  sort(rk[u].begin(), rk[u].end(), [&](int x, int y) {
    return dp[u][x] > dp[u][y];
  });
  for (int i = 0; i < sz && i < k; ++i) sum += dp[u][rk[u][i]];
  for (int j = 0, i, v, w; j < sz && j < k; ++j) {
    i = rk[u][j];
    v = e[u][i].first;
    w = e[u][i].second;
    if (v == fa) continue;
    dfs2(v, u, sum+w-dp[u][i]+(k < sz ? dp[u][rk[u][k]] : 0));
  }
  for (int j = k, i, v, w; j < sz; ++j) {
    i = rk[u][j];
    v = e[u][i].first;
    w = e[u][i].second;
    if (v == fa) continue;
    dfs2(v, u, sum+w);
  }
}

inline ll solve() {
  cin >> n >> k;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  if (k == 0) return 0;
  for (int i = 1; i <= n; ++i) {
    dp[i].resize(e[i].size(), 0);
    rk[i].resize(e[i].size());
  }
  res = 0;
  dfs1(1, 0);
  dfs2(1, 0, 0);
  for (int i = 1; i <= n; ++i) {
    vector<pii>().swap(e[i]);
    vector<ll>().swap(dp[i]);
    vector<int>().swap(rk[i]);
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}