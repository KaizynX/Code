/*
 * @Author: Kaizyn
 * @Date: 2020-07-13 12:23:24
 * @LastEditTime: 2020-07-13 13:06:09
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, k, m;
int a[N], b[N], c1[N], c2[N], p[N];
int vis[N];

inline void solve() {
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    b[a[i]] = i;
    vis[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    m = 1;
    c1[0] = i;
    for (int j = b[i]; j != i; j = b[j]) {
      c1[m++] = j;
      vis[j] = 1;
    }
    for (int j = c1[0], cp = 0, t = 0; t < m; ++t) {
      c2[cp] = j;
      j = b[j];
      cp = (cp+k)%m;
    }
    for (int j = 0; j < m; ++j) p[c2[(j+1)%m]] = c2[j];
  }
  for (int i = 0; i < n; ++i) cout << p[i]+1 << " \n"[i==n-1];
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> k) solve();
  return 0;
}