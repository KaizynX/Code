/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 14:53:12
 * @LastEditTime: 2020-09-06 15:35:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int PL[] = {1572869, 6291469};
const int PR[] = {3145739, 12582917};
const int MO[] = {25165843, 50331653};
const int N = 1e6+7;

int n, rt, res = 1;
int a[N], l[N], r[N], deg[N], num[N];
ull hv[2][N], rv[2][N];

void dfs(int u) {
  num[u] = 1;
  for (int i = 0; i < 2; ++i) {
    hv[i][u] = a[u];
    rv[i][u] = a[u];
  }
  if (~l[u]) {
    dfs(l[u]);
    num[u] += num[l[u]];
    for (int i = 0; i < 2; ++i) {
      (hv[i][u] += hv[i][l[u]]*PL[i]) %= MO[i];
      (rv[i][u] += rv[i][l[u]]*PR[i]) %= MO[i];
    }
  }
  if (~r[u]) {
    dfs(r[u]);
    num[u] += num[r[u]];
    for (int i = 0; i < 2; ++i) {
      (hv[i][u] += hv[i][r[u]]*PR[i]) %= MO[i];
      (rv[i][u] += rv[i][r[u]]*PL[i]) %= MO[i];
    }
  }
  if (hv[0][u] == rv[0][u] && hv[1][u] == rv[1][u]) {
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