/*
 * @Author: Kaizyn
 * @Date: 2020-05-23 18:16:29
 * @LastEditTime: 2020-05-23 19:14:42
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
int a[N];
vector<int> e[N], dp[N];

int dfs1(const int &u, const int &fa) {
  int val = 0;
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    if (v == fa) continue;
    dp[u][i] = dfs1(v, u);
    val = max(val ,dp[u][i]);
  }
  return a[u] == 1 ? val+1 : 0;
}

void dfs2(const int &u, const int &fa, const int &val) {
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    if (v == fa) dp[u][i] = val;
    else dfs2(v, u, a[u] == 1 ? val+1 : 0);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  int mina = INF;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mina = min(mina, a[i]);
    dp[i].resize(e[i].size());
  }
  if (mina != 1) return cout << mina << "/1\n", 0;
  dfs1(1, 0);
  dfs2(1, 0, 0);
  int resa = 1, resb = 1;
  for (int i = 1; i <= n; ++i) if (a[i] == 1) {
    for (const int &v : dp[i]) resb = max(resb, v+1);
  }
  resa *= 2; resb *= 2;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 2 && dp[i].size() >= 2) {
      sort(dp[i].begin(), dp[i].end());
      reverse(dp[i].begin(), dp[i].end());
      resb = max(resb, dp[i][0]+dp[i][1]+1);
      /*
      if (2*resb < resa*(dp[i][0]+dp[i][1]+1)) {
        resa = 2;
        resb = dp[i][0]+dp[i][1]+1;
      }
      */
    }
  }
  int g = __gcd(resa, resb);
  resa /= g; resb /= g;
  cout << resa << "/" << resb << endl;
  return 0;
}