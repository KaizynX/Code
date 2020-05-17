/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 20:49:43
 * @LastEditTime: 2020-05-10 20:56:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, m;
long long k;
int a[N], b[N], vis[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int s;
  for (s = 1; !vis[s]; s = a[s]) vis[s] = m, b[m++] = s;
  if (k < vis[s]) cout << b[k] << endl;
  else cout << b[vis[s]+(k-vis[s])%(m-vis[s])] << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}