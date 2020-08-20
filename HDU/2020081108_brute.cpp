/*
 * @Author: Kaizyn
 * @Date: 2020-08-11 12:54:26
 * @LastEditTime: 2020-08-11 13:51:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;
const int B = 21;

template <typename T> inline void read(T &x) {
  int c;
  while(!isdigit((c=getchar()))) {}
  x = c-'0';
  while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
}

template <typename T> void write(T x) {
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

int n, m;
int p[N], b[N], a[1<<B], dp[1<<B];

signed main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", p+i, b+i);
  }
  scanf("%d", &m);
  for (int i = 0, x; i < m; ++i) {
    scanf("%d", &x);
    long long res = 0;
    for (int j = 0; j < 1<<n; ++j) {
      int s = 0, flag = 1;
      long long mul = 1;
      for (int k = 0; k < n; ++k) if ((j>>k)&1) {
        if (s&b[k]) { flag = 0; break; }
        s |= b[k];
        mul = mul*p[k]%MOD;
      }
      if (flag && s == x) res = (res+mul)%MOD;
    }
    printf("%lld\n", res);
  }
  return 0;
}