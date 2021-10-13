/*
 * @Author: Kaizyn
 * @Date: 2021-10-13 16:06:56
 * @LastEditTime: 2021-10-13 16:28:07
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int sa[N], rk[N<<1], height[N];
template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
#define cmp(x, y, w) oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]
  static int oldrk[N<<1], id[N], px[N], cnt[N], m;
  memset(oldrk+n+1, 0, sizeof(int)*n); // multi testcase
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
    swap(oldrk, rk); // memcpy(oldrk+1, rk+1, sizeof(int)*n);
    for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
  }
  for (int i = 1, k = 0; i <= n; ++i) {
    if (k) --k;
    while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
    height[rk[i]] = k;
  }
#undef cmp
}

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n;
int h[6][N], a[6][N], st[6][N], th[6];
char f[3];
char s[N];
DSU dsu;

inline void solve() {
  dsu.init(n);
  s[n+1] = '$';
  f[0] = 'a'; f[1] = 'b'; f[2] = 'c';
  int idx = 0;
  do {
    for (int i = n+2; i <= n+n+1; ++i) s[i] = f[s[i-n-1]-'a'];
    SA(s, n*2+1);
    th[idx] = 0;
    memcpy(h[idx], height, sizeof(int)*(n*2+2));
    memcpy(a[idx], sa, sizeof(int)*(n*2+2));
    iota(st[idx], st[idx]+n*2+2, 0);
    sort(st[idx], st[idx]+n*2+2, [&](int x, int y) {
      return height[x] > height[y];
    });
    idx++;
  } while (next_permutation(f, f+3));
  ll ans = 0, cnt = 0;
  for (int len = n; len; --len) {
    for (int i = 0, j; i < 6; ++i) {
      while (h[i][j = st[i][th[i]]] >= len) {
        int i1 = a[i][j], i2 = a[i][j-1];
        if (i1 > i2) swap(i1, i2);
        if (i1 <= n && i2 > n+1) cnt += dsu.merge(i1, i2-n-1);
        ++th[i];
      }
    }
    ans += (n-len+1)-cnt;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  while (scanf("%d%s", &n, s+1) != -1) solve();
  return 0;
}