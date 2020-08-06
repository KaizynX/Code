/*
 * @Author: Kaizyn
 * @Date: 2020-07-30 22:34:30
 * @LastEditTime: 2020-07-30 22:45:39
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

int n;
long long a[N];
int b[N], id[N], deg[N], rk[N];
queue<int> q;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    if (~b[i]) ++deg[b[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) q.push(i);
  }
  int tot = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    id[u] = ++tot;
    if (~b[u] && --deg[b[u]] == 0) q.push(b[u]);
  }
  for (int i = 1; i <= n; ++i) rk[id[i]] = i;
  long long res = 0;
  for (int j = 1, i; j <= n; ++j) {
    i = rk[j];
    if (a[i] >= 0) {
      q.push(i);
      res += a[i];
      deg[i] = 1;
      if (~b[i]) a[b[i]] += a[i];
    }
  }
  for (int j = n, i; j; --j) {
    i = rk[j];
    if (deg[i]) continue;
    q.push(i);
    res += a[i];
    if (~b[i]) a[b[i]] += a[i];
  }
  cout << res << endl;
  while (q.size()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
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