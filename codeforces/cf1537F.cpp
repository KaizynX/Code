/*
 * @Author: Kaizyn
 * @Date: 2021-07-05 23:31:51
 * @LastEditTime: 2021-07-05 23:48:00
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
const int N = 2e5+7;

int n, m, bip;
int v[N], col[N];
vector<int> e[N];

bool dfs(int x, int c = 0) {
  if (~col[x]) return c == col[x];
  col[x] = c;
  for (int &y : e[x]) {
    if (!dfs(y, c^1)) return false;
  }
  return true;
}

inline bool solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    e[i].clear();
    col[i] = -1;
  }
  int flag = 0;
  for (int i = 1, t; i <= n; ++i) {
    cin >> t;
    v[i] = t-v[i];
    flag ^= abs(v[i])&1;
  }
  if (flag) return false;
  for (int i = 1, a, b; i <= m; ++i) {
    cin >> a >> b;
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }
  flag = 1;
  for (int i = 1; i <= n; ++i) if (~col[i]) {
    flag &= dfs(i);
  }
  if (!flag) return true;
  ll sum[2] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    sum[col[i]] += v[i];
  }
  return sum[0] == sum[1];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}