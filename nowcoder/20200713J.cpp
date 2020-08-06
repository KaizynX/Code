/*
 * @Author: Kaizyn
 * @Date: 2020-07-13 12:23:24
 * @LastEditTime: 2020-07-13 12:50:43
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
int a[N], b[N], c[N], p[N];

inline void solve() {
  m = n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    b[a[i]] = i;
    if (a[i] == i) --m;
  }
  if (!m) {
    for (int i = 1; i <= n; ++i) cout << i << " \n";
    cout.flush();
    return;
  }
  k %= m;
  int s;
  for (int i = 0; i < n; ++i) {
    if (b[i] != i) {
      s = i;
      break;
    }
  }
  for (int i = s, cp = 0, t = 0; t < m; ++t) {
    c[cp] = i;
    i = b[i];
    cp = (cp+k)%m;
  }
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < m; ++i) p[c[(i+1)%m]] = c[i];
  for (int i = 0; i < n; ++i) cout << p[i]+1 << " \n"[i==n-1];
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> k) solve();
  return 0;
}