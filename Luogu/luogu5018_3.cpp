/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 14:53:12
 * @LastEditTime: 2020-09-06 16:07:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, res = 1;
int a[N], l[N], r[N], num[N];

bool check(int u, int v) {
  if (u == -1 && v == -1) return true;
  if (u == -1 || v == -1 ||
      num[u] != num[v] || a[u] != a[v]) return false;
  return check(l[u], r[v]) && check(r[u], l[v]);
}

void dfs(int u) {
  num[u] = 1;
  if (~l[u]) {
    dfs(l[u]);
    num[u] += num[l[u]];
  }
  if (~r[u]) {
    dfs(r[u]);
    num[u] += num[r[u]];
  }
  if (check(l[u], r[u])) res = max(res, num[u]);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
  dfs(1);
  cout << res << endl;
  return 0;
}