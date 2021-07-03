/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 13:04:32
 * @LastEditTime: 2021-06-13 13:07:41
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
const int N = 20;

int n;
vector<int> e[N];
int a[N], co[N], vis[N];

bool check(int u) {
  for (int v : e[u]) {
    if (vis[v]) continue;
    vis[v] = 1;
    if (!co[v] || check(co[v])) {
      co[v] = u;
      return true;
    }
  }
  return false;
}

inline int solve() {
  int res = 0;
  memset(co, 0, sizeof co);
  for (int i = 1; i <= n; ++i) {
    memset(vis, 0, sizeof(int)*(n+3));
    res += check(i);
  }
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 1; i <= 2*n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = n+1; j <= 2*n; ++j) {
      if (__gcd(a[i], a[j]) > 1) {
        e[i].emplace_back(j);
        e[j].emplace_back(i);
      }
    }
  }
  cout << solve() << '\n';
  return 0;
}