/*
 * @Author: Kaizyn
 * @Date: 2021-09-29 17:23:50
 * @LastEditTime: 2021-09-29 17:39:16
 */
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>

using namespace std;
const int N = 15;
const int M = 1e3+7;

int n, m;
int a[N][N], rk[N], vis[M], *h[N], ans[M];

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    rk[i] = i;
    h[i] = a[i];
    for (int j = 0; j < n; ++j) {
      cin >> a[i][min(m, j)];
    }
  }
  do {
    for (int i = 0; i < m; ++i) vis[*h[i]] = 0, h[i] = a[i];
    for (int _ = 0, i; _ < m; ++_) {
      i = rk[_];
      while (vis[*h[i]]) ++h[i];
      vis[*h[i]] = ans[*h[i]] = 1;
    }
  } while (next_permutation(rk, rk+m));
  int cnt = 0;
  for (int i = 1; i <= 1000; ++i) cnt += ans[i];
  cout << cnt << '\n';
  for (int i = 1; i <= 1000; ++i) if (ans[i]) cout << i << ' ';
  cout << '\n';
  return 0;
}