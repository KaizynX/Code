/*
 * @Author: Kaizyn
 * @Date: 2021-02-07 16:14:22
 * @LastEditTime: 2021-02-07 16:28:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

int n;
int x[N], y[N], vis[N];

ll dis(int i, int j) {
  return 1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
  }
  cout << "1 ";
  vis[1] = 1;
  for (int i = 2, last = 1; i <= n; ++i) {
    int cur = last;
    for (int j = 1; j <= n; ++j) if (!vis[j]) {
      if (dis(cur, last) < dis(last, j)) cur = j;
    }
    vis[cur] = 1;
    cout << cur << " \n"[i==n];
    last = cur;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}