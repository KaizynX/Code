/*
 * @Author: Kaizyn
 * @Date: 2020-08-11 12:54:26
 * @LastEditTime: 2020-08-11 17:04:49
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int p[N], b[N], a[1<<B];
long long dp[1<<B];

signed main() {
  // scanf("%d", &n);
  read(n);
  for (int i = 1; i <= n; ++i) {
    // scanf("%d %d", p+i, b+i);
    read(p[i]); read(b[i]);
    (a[b[i]] += p[i]) %= MOD;
  }
  dp[0] = a[0];
  int all = (1<<B)-1;
  for (int i = 1, k; i < 1<<B; ++i) if (a[i]) {
    k = all^i;
    (dp[i] += a[i]*(a[0]+1ll)) %= MOD;
    for (int j = k; j; j = (j-1)&k) if (dp[j]) {
      (dp[i|j] += a[i]*dp[j]) %= MOD;
    }
  }
  // scanf("%d", &m);
  read(m);
  for (int i = 1, x; i <= m; ++i) {
    // scanf("%d", &x);
    read(x);
    // printf("%d\n", dp[x]);
    write(dp[x]); putchar('\n');
  }
  return 0;
}