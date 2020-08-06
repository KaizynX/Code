/*
 * @Author: Kaizyn
 * @Date: 2020-07-31 19:59:02
 * @LastEditTime: 2020-07-31 23:07:50
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 1e9+7;
const int N = 4e2+7;
const int M = 160000+7;
const int NN = 2*M*(log2(M)+5);
typedef unsigned int U;
typedef unsigned long long ull;

inline ull xorshift128(){
  static U SX=335634763,SY=873658265,SZ=192849106,SW=746126501;
  U t=SX^(SX<<11);
  SX=SY;
  SY=SZ;
  SZ=SW;
  return SW=SW^(SW>>19)^t^(t>>8);
}
inline ull myrand(){return (xorshift128()<<32)^xorshift128();}

int n, m, q;
int a[N][N], f[N][N], g[N][N], h[N][N], lv[N][N], rv[N][N];
int cnt[NN], ls[NN], rs[NN], tot;
ull pw[M], w[M], val[NN], hval[NN];

int insert(const int &pre, const int &l, const int &r, const int &k) {
  int cur = ++tot;
  ls[cur] = ls[pre]; rs[cur] = rs[pre];
  cnt[cur] = cnt[pre]+1;
  val[cur] = (val[pre]+pw[k])%MOD;
  hval[cur] = hval[pre]+w[k];
  if (l == r) return cur;
  int mid = (l+r)>>1;
  if (k <= mid) ls[cur] = insert(ls[pre], l, mid, k);
  else rs[cur] = insert(rs[pre], mid+1, r, k);
  return cur;
}

bool bigger(int u0, int u1, int v0, int v1) {
  if (hval[u0]+hval[u1] == hval[v0]+hval[v1]) return false;
  int l = 1, r = m, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (hval[rs[u0]]+hval[rs[u1]] == hval[rs[v0]]+hval[rs[v1]]) {
      u0 = ls[u0];
      u1 = ls[u1];
      v0 = ls[v0];
      v1 = ls[v1];
      r = mid;
    } else {
      u0 = rs[u0];
      u1 = rs[u1];
      v0 = rs[v0];
      v1 = rs[v1];
      l = mid+1;
    }
  }
  return cnt[u0]+cnt[u1] > cnt[v0]+cnt[v1];
}

// [x, y] ==> x<<9 + y
inline int get_max(const int &x, const int &y) {
  if (!x || !y) return x+y;
  return bigger(f[x>>9][x&511], h[x>>9][x&511], f[y>>9][y&511], h[y>>9][y&511]) ? x : y;
}

signed main() {
  // freopen("1004.in", "r", stdin);
  // freopen("my.out", "w", stdout);
  int T;
  scanf("%d", &T);
  pw[0] = 1;
  while (T--) {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
      }
    }

    tot = 0;
    m = n*n;
    for (int i = 1; i <= m; ++i) w[i] = myrand();
    for (int i = 1; i <= m; ++i) pw[i] = pw[i-1]*m%MOD;
    for (int i = 0; i <= n+1; ++i) {
      for (int j = 0; j <= n+1; ++j) {
        f[i][j] = g[i][j] = h[i][j] = lv[i][j] = rv[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        f[i][j] = bigger(f[i-1][j], 0, f[i][j-1], 0) ? f[i-1][j] : f[i][j-1];
        f[i][j] = insert(f[i][j], 1, m, a[i][j]);
      }
    }
    for (int i = n; i; --i) {
      for (int j = n; j; --j) {
        h[i][j] = bigger(g[i+1][j], 0, g[i][j+1], 0) ? g[i+1][j] : g[i][j+1];
        g[i][j] = insert(h[i][j], 1, m, a[i][j]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        lv[i][j] = get_max(lv[i][j-1], i<<9|j);
      }
      for (int j = n; j; --j) {
        rv[i][j] = get_max(rv[i][j+1], i<<9|j);
      }
    }
    for (int _ = 1, xl, xr, yl, yr, res; _ <= q; ++_) {
      scanf("%d %d %d %d", &xl, &xr, &yl, &yr);
      res = get_max(lv[xr+1][yl-1], rv[xl-1][yr+1]);
      printf("%lld\n", (val[f[res>>9][res&511]]+val[h[res>>9][res&511]])%MOD);
    }
  }
  return 0;
}