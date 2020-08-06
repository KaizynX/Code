/*
 * @Author: Kaizyn
 * @Date: 2020-08-03 15:58:53
 * @LastEditTime: 2020-08-03 23:36:35
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
const int N = 1e5+7;

ll f[N], sum[N];

ll calc(int n, int m) {
  if (n < m+3 || n > m*3-3) return 0;
  n -= 6; m -= 3;
  n -= m;
  // m [0, 1, 2] sum n
  if (n <= m) return n/2+1;
  else return (2*m-n)/2+1;
}

inline void init(const int &n) {
  for (int l = 50, m, r; l <= n; ++l) {
    m = l+1; r = l+2;
    for (int nl = 1; nl*l <= n; ++nl) {
      for (int nm = 3; nm*m+nl*l <= n; ++nm) {
        f[nm*m+nl*l] += (nm-1)/2;
      }
    }
    for (int nr = 0; nr*r <= n; ++nr) {
      for (int nm = 3; nm*m+nr*r <= n; ++nm) {
        f[nm*m+nr*r] += (nm-1)/2;
      }
    }
  }
  for (int i = 6; i <= 10000; ++i) {
    f[i] = 0;
    for (int j = 3; j <= i-3; ++j) {
      // i-j*k
      int t = i%j;
      if (t+j <= i) f[i] += calc(t+j, j);
      if (t+j*2 <= i) f[i] += calc(t+j*2, j);
    }
  }
  for (int i = 1; i <= n; ++i) sum[i] = sum[i-1]+f[i];
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  init(100000);
  int T = 1;
  scanf("%d", &T);
  for (int t = 1, l, r; t <= T; ++t) {
    scanf("%d %d", &l, &r);
    printf("Case #%d: %lld\n", t, sum[r]-sum[l-1]);
  }
  return 0;
}