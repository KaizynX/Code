/*
 * @Author: Kaizyn
 * @Date: 2021-07-15 13:22:05
 * @LastEditTime: 2021-07-15 13:59:06
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
const int N = 50+7;
const int M = 15000+7;
const int T = 5e2+7;

int n, m, t, p, res;
// cost y day gain x
int id[N], x[N], y[N], del[N];
// dp[i][j] cost i day the most mark can gain
int dp[N][T], f[2][T];
int pos[N]; // the min day i get 60
string str;
map<string, int> mp;

void dfs(int u, int last = 0) {
  if (u > p) {
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; ++i) {
      memset(f[i&1], 0, sizeof(int)*(t+1));
      for (int j = del[i] ? 0 : pos[i]; j <= t; ++j) {
        for (int k = j; k <= t; ++k) {
          f[i&1][k] = max(f[i&1][k], f[~i&1][k-j]+dp[i][j]);
        }
        if (dp[i][j] == 100) break;
      }
    }
    res = max(res, f[n&1][t]);
    return;
  }
  for (int i = last+1; i <= n; ++i) {
    del[i] = 1;
    dfs(u+1, i);
    del[i] = 0;
  }
}

inline void solve() {
  res = 0;
  mp.clear();
  memset(dp, 0, sizeof dp);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    mp[str] = i;
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> str;
    id[i] = mp[str];
    cin >> x[i] >> y[i];
  }
  cin >> t >> p;
  for (int i = 1; i <= m; ++i) {
    for (int j = t; j >= y[i]; --j) {
      dp[id[i]][j] = max(dp[id[i]][j], dp[id[i]][j-y[i]]+x[i]);
      dp[id[i]][j] = min(dp[id[i]][j], 100);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= t; ++j) {
      if (dp[i][j] >= 60) {
        pos[i] = j;
        break;
      }
    }
  }
  dfs(1);
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int Test = 1;
  cin >> Test; // scanf("%d", &T);
  for (int t = 1; t <= Test; ++t) {
    solve();
  }
  return 0;
}