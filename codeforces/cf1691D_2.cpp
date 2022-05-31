/*
 * @Author: Kaizyn
 * @Date: 2022-05-31 23:17:14
 * @LastEditTime: 2022-05-31 23:34:28
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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

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
    if (l > r) return inf<int>;
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

int n;
int a[N], L[N], R[N];
ll ls[N], rs[N];
ST<ll, less<ll>> st;
vector<int> stk;

inline void solve() {
  cin >> n;
  int flag = 1;

  a[0] = a[n + 1] = inf<int>;
  ls[1] = 0;
  stk.clear();
  stk.emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    // ls[i] = ls[i - 1] + a[i];
    ls[i + 1] = ls[i] + a[i];
    while (a[stk.back()] <= a[i]) {
      stk.pop_back();
    }
    L[i] = stk.back();
    stk.emplace_back(i);
  }
  st.build(ls, n + 1);
  for (int i = 1; i <= n; ++i) {
    // check sum{j, i-1} > 0 (L < j < i)
    // ls[i - 1] - min{ls[L, i - 1]}
    if (st.query(L[i] + 1, i) < ls[i]) {
      flag = 0;
      #ifdef DEBUG
      cerr << "ls find " << i << '\n';
      #endif
    }
  }

  rs[n + 1] = 0;
  stk.clear();
  stk.emplace_back(n + 1);
  for (int i = n; i; --i) {
    rs[i] = rs[i + 1] + a[i];
    while (a[stk.back()] <= a[i]) {
      stk.pop_back();
    }
    R[i] = stk.back();
    stk.emplace_back(i);
  }
  st.build(rs, n + 1);
  for (int i = 1; i <= n; ++i) {
    // check sum{i+1, j} > 0 (i < j < R)
    // rs[i + 1] - min{rs[i + 1, R]}
    if (st.query(i + 1, R[i]) < rs[i + 1]) {
      flag = 0;
      #ifdef DEBUG
      cerr << "rs find " << i << '\n';
      #endif
    }
  }
#ifdef DEBUG
  orzarr(L + 1, n);
  orzarr(R + 1, n);
#endif

  cout << (flag ? "YES" : "NO") << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}