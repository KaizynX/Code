/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 14:53:12
 * @LastEditTime: 2020-09-06 15:39:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const ull PL[] = {1572869, 75161927681};
const ull PR[] = {3145739, 206158430209};
const ull MOD = 3221225473;
const int N = 1e6+7;

int n, rt, res = 1;
int a[N], l[N], r[N], deg[N], num[N];
ull hv[2][N], rv[2][N];

void dfs(int u) {
  num[u] = 1;
  hv[0][u] = hv[1][u] = a[u];
  rv[0][u] = rv[1][u] = a[u];
  if (~l[u]) {
    dfs(l[u]);
    num[u] += num[l[u]];
    (hv[0][u] += hv[0][l[u]]*PL[0]) %= MOD;
    (rv[0][u] += rv[0][l[u]]*PR[0]) %= MOD;
    hv[1][u] += hv[1][l[u]]*PL[1];
    rv[1][u] += rv[1][l[u]]*PR[1];
  }
  if (~r[u]) {
    dfs(r[u]);
    num[u] += num[r[u]];
    (hv[0][u] += hv[0][r[u]]*PR[0]) %= MOD;
    (rv[0][u] += rv[0][r[u]]*PL[0]) %= MOD;
    hv[1][u] += hv[1][r[u]]*PR[1];
    rv[1][u] += rv[1][r[u]]*PL[1];
  }
  if (~l[u] && ~r[u] && num[l[u]] == num[r[u]] &&
      hv[0][u] == rv[0][u] && hv[1][u] == rv[1][u]) {
    res = max(res, num[u]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];

  for (int i = 1; i <= n; ++i) {
    if (~l[i]) ++deg[l[i]];
    if (~r[i]) ++deg[r[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) rt = i;
  }
  dfs(rt);
  cout << res << endl;
  return 0;
}