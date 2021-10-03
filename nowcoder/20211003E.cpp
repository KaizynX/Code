/*
 * @Author: Kaizyn
 * @Date: 2021-10-03 12:40:04
 * @LastEditTime: 2021-10-03 13:38:25
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
#define log(x) (31-__builtin_clz(x))
const int N = 1e6+7;

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = 31-__builtin_clz(N)+3;
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
int sa[N], rk[N<<1], height[N];
ST<int, less<int>> st;

template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
#define cmp(x, y, w) oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]
  static int oldrk[N<<1], id[N], px[N], cnt[N], m;
  // memset(oldrk+n+1, 0, sizeof(int)*n); // multi testcase
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

bool cmp(int i, int j) {
  int lcp, leni, lenj;
  leni = n-i+1;
  lenj = n-j+1;
  lcp = st.query(min(rk[i], rk[j])+1, max(rk[i], rk[j]));
  if (lcp < min(leni, lenj)) return false;
  i += lcp;
  j += lcp;
  if (i > n) i -= n;
  if (j > n) j -= n;
  leni = n-i+1;
  lenj = n-j+1;
  lcp = st.query(min(rk[i], rk[j])+1, max(rk[i], rk[j]));
  if (lcp < min(leni, lenj)) return false;
  i += lcp;
  j += lcp;
  if (i > n) i -= n;
  if (j > n) j -= n;
  leni = n-i+1;
  lenj = n-j+1;
  lcp = st.query(min(rk[i], rk[j])+1, max(rk[i], rk[j]));
  if (lcp < min(leni, lenj)) return false;
  return true;
}

inline void solve() {
  scanf("%s", s+1);
  n = strlen(s+1);
  SA(s, n);
  st.build(height, n);
  #ifdef DEBUG
  orzarr(sa+1, n);
  orzarr(rk+1, n);
  orzarr(height+1, n);
  #endif
  vector<int> v;
  vector<vector<int>> ans;
  for (int i = 1, j; i <= n; i = j) {
    v.clear();
    v.emplace_back(sa[i]);
    for (j = i+1; j <= n; ++j) {
      if (!cmp(sa[i], sa[j])) break;
      v.emplace_back(sa[j]);
    }
    sort(v.begin(), v.end());
    ans.emplace_back(v);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (auto v : ans) {
    printf("%d", (int)v.size());
    for (int i : v) printf(" %d", i-1);
    puts("");
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}