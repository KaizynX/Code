/*
 * @Author: Kaizyn
 * @Date: 2020-05-12 17:10:44
 * @LastEditTime: 2020-05-12 20:06:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 1e9+7;
const int N = 5e4+7;
const int NN = sqrt(N)+7;

int n, q, t, m;
int a[N], cnt[N], dis[N];
int sum[NN][N]; // sum[i][j] the num of j in [0, i*t)
int f[NN][N]; // f[i][j] the res of [i*t, j]

inline void discrete() {
  memcpy(dis, a, sizeof(int)*n);
  sort(dis, dis+n);
  m = unique(dis, dis+n)-dis;
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(dis, dis+m, a[i])-dis;
  }
}

inline int qpow(long long a, int p) {
  long long res = 1;
  while (p) {
    if (p&1) (res *= a) %= MOD;
    (a *= a) %= MOD;
    p >>= 1;
  }
  return static_cast<int>(res);
}

inline int get_num(const int &i, const int &r, const int &v) {
  // return the number of v in [i*t, r]
  if (i*t > r) return 0;
  int res = sum[r/t][v]-sum[i][v];
  for (int x = r/t*t; x <= r; ++x) res += a[x] == v;
  return res;
}

inline int query(const int &l, const int &r) {
  int x = (l+t-1)/t;
  int res = f[x][r];
  for (int i = l; i <= r && i%t; ++i) cnt[a[i]] = get_num(x, r, a[i]);
  for (int i = l; i <= r && i%t; ++i) {
    if (cnt[a[i]]) (res -= qpow(dis[a[i]], cnt[a[i]])) %= MOD;
    (res += qpow(dis[a[i]], ++cnt[a[i]])) %= MOD;
  }
  for (int i = l; i <= r && i%t; ++i) cnt[a[i]] = 0;
  return (res+MOD)%MOD;
}

inline void solve() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  discrete();
  t = static_cast<int>(sqrt(n)+.5);
  for (int i = 0; i < (n+t-1)/t; ++i) {
    memcpy(sum[i+1], sum[i], sizeof(int)*m);
    for (int j = i*t; j < i*t+t; ++j) ++sum[i+1][a[j]];
    memset(f[i], 0, sizeof(int)*i*t);
    for (int j = i*t; j < n; ++j) {
      f[i][j] = f[i][j-1];
      if (cnt[a[j]]) (f[i][j] -= qpow(dis[a[j]], cnt[a[j]])) %= MOD;
      (f[i][j] += qpow(dis[a[j]], ++cnt[a[j]])) %= MOD;
    }
    for (int j = i*t; j < n; ++j) --cnt[a[j]];
  }
  for (int i = 1, l, r, res = 0; i <= q; ++i) {
    scanf("%d %d", &l, &r);
    l = (l^res)%n;
    r = (r^res)%n;
    #ifdef DEBUG
    cout << "(" << l << ", " << r << ")" << endl;
    #endif
    if (l > r) swap(l, r);
    printf("%d\n", res = query(l, r));
  }
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}