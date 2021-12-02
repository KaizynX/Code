/*
 * @Author: Kaizyn
 * @Date: 2021-11-29 00:01:00
 * @LastEditTime: 2021-11-29 00:15:00
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
const int N = 1e6+7;
const int B = 60;

#define __pcnt(x) __builtin_popcountll(x)

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
ll a[N];
vector<int> v[B];
ST<ll, greater<ll>> maxv;
ST<ll, less<ll>> minv;

bool check(int l, int r, int b) {
  return __pcnt(minv.query(l, r)) == b
      && __pcnt(maxv.query(l, r)) == b;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i<= n; ++i) {
    cin >> a[i];
    v[__pcnt(a[i])].emplace_back(i);
  }
  maxv.build(a, n);
  minv.build(a, n);
  ll ans = 0;
  for (int b = 0; b < B; ++b) {
    int m = v[b].size(), l, r, mid;
    for (int i = 0, j = 0; i < m; ++i) {
      // [i, j]
      j = max(j, i);
      while (j+1 < m && check(v[b][i], v[b][j+1], b)) ++j;

      l = i ? v[b][i-1]+1 : 1;
      r = v[b][i];
      while (l < r) {
        mid = (l+r)>>1;
        if (check(mid, v[b][i], b)) r = mid;
        else l = mid+1;
      }
      int lp = l;

      l = v[b][j];
      r = j+1 < m ? v[b][j+1]-1 : n;
      while (l < r) {
        mid = (l+r+1)>>1;
        if (check(v[b][j], mid, b)) l = mid;
        else r = mid-1;
      }
      int rp = l;
      #ifdef DEBUG
      printf("(l=%d,r=%d)(lp=%d,rp=%d)\n", i, j, lp, rp);
      #endif
      ans += (rp-lp+1ll)*(rp-lp)/2-(rp-v[b][i])*(rp-v[b][i]-1ll)/2;
    }
  }
  cout << ans << '\n';
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