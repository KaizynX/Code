/*
 * @Author: Kaizyn
 * @Date: 2020-10-05 23:03:24
 * @LastEditTime: 2020-10-06 10:09:45
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

long long T;
int P, Q, n, m;
int arr1[N], arr2[N], pos[N], sum[N], *a = arr1, *b = arr2;

inline bool solve() {
  if (!(cin >> P >> Q >> n >> m >> T)) return false;
  memset(a, 0, sizeof(int)*P);
  memset(b, 0, sizeof(int)*Q);
  for (int i = 1, x; i <= n; ++i) cin >> x, a[x] = 1;
  for (int i = 1, x; i <= m; ++i) cin >> x, b[x] = 1;
  if (P > Q) swap(P, Q), swap(n, m), swap(a, b);
  int g = __gcd(P, Q), len = Q/g;
  long long time = 1ll*P*Q/g;
  for (int c = 0, s; c < g; ++c) {
    s = c*len;
    for (int i = 0, j = c; i < len; ++i) {
      pos[j] = s+i;
      sum[s+i] = (i ? sum[s+i-1] : 0)+b[j];
      j = (j+P)%Q;
    }
  }
  long long res = 0;
  for (int i = 0, c, s, l, r; i < P; ++i) if (a[i]) {
    c = pos[i]/len;
    s = c*len;
    res += T/time*sum[s+len-1];
    if (T%time <= i) continue;
    l = pos[i];
    r = s+(l-s+(T%time-i-1)/P)%len;
    if (l <= r) res += sum[r]-(l == s ? 0 : sum[l-1]);
    else res += sum[c*len+len-1]-(sum[l-1]-sum[r]);
  }
  cout << res << endl;
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (solve()) {}
  return 0;
}