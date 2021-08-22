/*
 * @Author: Kaizyn
 * @Date: 2021-08-22 17:18:10
 * @LastEditTime: 2021-08-22 19:07:27
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e4+7;

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = (int)log2(N)+3;
  static const T INF = 1e9;
  int lg2[N];
  U cmp = U();
  T rmq[N][NN];
  ST() {
    fill(rmq[0], rmq[0]+N*NN, cmp(-INF, +INF) ? INF : -INF);
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
  }
  T& operator [] (const int &i) { return rmq[i][0]; }
  void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
  // rmq[i][j] ==> [i, i+2^j-1]
  void build(T a[], const int &n) {
    for (int i = n; i; --i) {
      rmq[i][0] = a[i];
      for (int j = 1; j <= lg2[n-i+1]; ++j)
        rmq[i][j] =  mv(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  T query(const int &l, const int &r) {
    if (l > r) return query(r, l);
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

int n;
char s[N];
int f[N], g[N];
int sa[N], rk[2][N<<1], height[N];
ST<int, less<int>> st[2];


template <typename T> // s start from 1
inline void SA(const T *s, const int &n, int *rk) {
#define cmp(x, y, w) oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]
  static int oldrk[N<<1], id[N], px[N], cnt[N], m;
  memset(cnt, 0, sizeof(int) * (m = 128));
  for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
  for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
  for (int i = n; i; --i) sa[cnt[rk[i]]--] = i;
  for (int w = 1, p, i; w <= n; w <<= 1, m = p) {
    for (p = 0, i = n; i > n - w; --i) id[++p] = i;
    for (i = 1; i <= n; ++i) if (sa[i] > w) id[++p] = sa[i] - w;
    memset(cnt + 1, 0, sizeof(int) * m);
    for (i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i; --i) sa[cnt[px[i]]--] = id[i];
    // swap(oldrk, rk);
    memcpy(oldrk+1, rk+1, sizeof(int)*n*2);
    for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
  }
  for (int i = 1, k = 0; i <= n; ++i) {
    if (k) --k;
    while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
    height[rk[i]] = k;
  }
#undef cmp
}

int query(int i, int j, int id) {
  i = rk[id][i];
  j = rk[id][j];
  if (i > j) swap(i, j);
  return st[id].query(i+1, j);
}

inline void solve() {
  scanf("%s", s+1);
  n = strlen(s+1);
  SA(s, n, rk[0]);
  st[0].build(height, n);
  reverse(s+1, s+n+1);
  SA(s, n, rk[1]);
  st[1].build(height, n);
  memset(f, 0, sizeof(int)*(n+2));
  memset(g, 0, sizeof(int)*(n+2));
  for (int len = 1; len <= n/2; ++len) {
    for (int i = 1, j; (j = i+len) <= n; i += len) {
      int lcp = query(i, j, 0);
      int lcs = query(n-i+1, n-j+1, 1);
      int d = (lcp+lcs-1)*2-len*2+1;
      if (d <= 0) continue;
      #ifdef DEBUG
      printf("len=%d,lcp=%d,lcs=%d,i=%d\n", len, lcp, lcs, i);
      #endif
      ++f[i-lcs+1]; --f[i-lcs+1+d];
      ++g[j+lcp-d]; --g[j+lcp];
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    f[i] += f[i-1];
    g[i] += g[i-1];
    #ifdef DEBUG
    cout << i << ':' << f[i] << ' ' << g[i] << '\n';
    #endif
  }
  for (int i = 1; i < n; ++i) {
    ans += 1ll*g[i]*f[i+1];
  }
  printf("%lld\n", ans);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}