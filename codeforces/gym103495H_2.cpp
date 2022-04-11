/*
 * @Author: Kaizyn
 * @Date: 2022-04-11 15:38:38
 * @LastEditTime: 2022-04-11 16:05:31
 */
#include <bits/stdc++.h>

// #define DEBUG

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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

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

char s[N];
ST<int, less<int>> st;

int LCP(int i, int j) {
  // lcp(sa[i],sa[j])=min{height[i+1...j]}
  i = rk[i];
  j = rk[j];
  if (i > j) swap(i, j);
  return st.query(i + 1, j);
}

inline void solve() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  s[n + 1] = '$';
  for (int i = n, j = n + 2; i; --i, ++j) s[j] = s[i];
  SA(s, 2 * n + 1);
  st.build(height, 2 * n + 1);
  int l = n, r = 0, ri;
  // find l
  vector<int> mx(26, 0);
  for (int i = n; i; --i) {
    int c = s[i] - 'a';
    for (int j = 0; j < c; ++j) {
      if (mx[j]) {
        l = i;
        break;
      }
    }
    mx[c] = 1;
  }
  // find r
  for (int i = 1; i <= 2 * n + 1; ++i) {
    if (sa[i] <= n + 1) continue;
    int ki = sa[i];
    int k = n - (ki - n - 1) + 1;
    if (k <= l) continue;
    if (!r) {
      r = k;
      ri = ki;
      continue;
    }
    // compare (l, r), (l, k)
    int kl = k, kr = r;
    int kil = ki, kir = ri;
    int len = kl - l + 1;
    int lcp = LCP(kil, kir);
    if (lcp < len) continue; // rk[ri] < rk[ki]
    if (kl > kr) {
      swap(kl, kr);
      swap(kil, kir);
    }
    if (rk[kl + 1] < rk[n - (kr - len) + 1 + n + 1]) {
      r = kl;
      ri = kil;
    } else {
      r = kr;
      ri = kir;
    }
    // lcp = LCP(kl + 1, n - (kr - len) + 1 + n + 1);
    // if (lcp < kr - l + 1 - len)
    // r = rk[kl + 1] < rk[n - (kr - len) + 1 + n + 1] ? kl : kr;
    // else r = r;
  }
  #ifdef DEBUG
  orz(l);
  orz(r);
  orzarr(sa + 1, 2 * n + 1);
  orzarr(rk + 1, 2 * n + 1);
  orzarr(height + 1, 2 * n + 1);
  #endif
  if (l < r) reverse(s + l, s + r + 1);
  s[n + 1] = '\0';
  printf("%s\n", s + 1);
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
/*
bbabbbabbb
abbbabbbbb
*/