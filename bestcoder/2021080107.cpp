/*
 * @Author: Kaizyn
 * @Date: 2021-08-01 15:53:49
 * @LastEditTime: 2021-08-01 15:59:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, k, res;
int a[N];
vector<int> e[N];

void update(int &x, int y) {
  if (y == -1) return;
  if (x == -1 || y < x) x = y;
}

int dfs(int u) {
  int r = a[u] ? k : -1;
  for (int v : e[u]) {
    update(r, dfs(v));
  }
  if (r == 0) ++res, r = -1;
  return ~r ? r-1 : r;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 2, p; i <= n; ++i) {
    cin >> p;
    e[p].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) cin >> a[i];
  res = 0;
  if (~dfs(1)) ++res;
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