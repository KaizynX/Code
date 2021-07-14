/*
 * @Author: Kaizyn
 * @Date: 2021-07-14 16:05:27
 * @LastEditTime: 2021-07-14 16:15:34
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
const int A = 3e3+7;
const int dir[] = {0, 1, 0, -1, 0};

int n, m, k;
int vis[A][A], x[N], y[N];
vector<int> vx, vy;

void discrete(int *arr, vector<int> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= k; ++i) {
    arr[i] = lower_bound(v.begin(), v.end(), arr[i])-v.begin()+1;
  }
}

void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || vis[x][y]) return;
  vis[x][y] = 1;
  for (int d = 0; d < 4; ++d) {
    dfs(x+dir[d], y+dir[d+1]);
  }
}

inline void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> x[i] >> y[i];
    vx.emplace_back(x[i]);
    if (x[i]-1 >= 1) vx.emplace_back(x[i]-1);
    if (x[i]+1 <= n) vx.emplace_back(x[i]+1);
    vy.emplace_back(y[i]);
    if (y[i]-1 >= 1) vy.emplace_back(y[i]-1);
    if (y[i]+1 <= m) vy.emplace_back(y[i]+1);
  }
  if (k <= 1000) {
    discrete(x, vx);
    discrete(y, vy);
    n = vx.size();
    m = vy.size();
  }
  for (int i = 1; i <= k; ++i) {
    vis[x[i]][y[i]] = 1;
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!vis[i][j]) {
        dfs(i, j);
        ++res;
      }
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