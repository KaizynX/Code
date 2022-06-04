/*
 * @Author: Kaizyn
 * @Date: 2022-06-04 21:24:20
 * @LastEditTime: 2022-06-04 21:25:47
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

int n, Q;
int A[N], B[N];

template <typename T>
struct ST {
  static const int NN = (int)log2(N)+3;
  static const T INF = 1e9;
  U cmp = U();
  T rmq[N][N][NN][NN]; // rmq[i][j][k][l] [i, j] [i+2^k-1, j+2^l-1]
  ST() { init(); }
  ST(const T &val) { init(val); }
  T& operator [] (const int &i) { return rmq[i][0]; }
  void init(){ fill(rmq[0][0][0], rmq[0][0][0]+N*N*NN*NN, cmp(-INF, +INF) ? INF : -INF); }
  void init(const T &val) { fill(rmq[0][0][0], rmq[0][0][0]+N*N*NN*NN, val); }
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
  void build(T a[N][N], const int &n, const int &m) {
    for (int k = 0; k <= log_2[n]; ++k)
    for (int l = 0; l <= log_2[m]; ++l)
    for (int i = 1; i+(1<<k)-1 <= n; ++i)
    for (int j = 1; j+(1<<l)-1 <= m; ++j) {
      T &cur = rmq[i][j][k][l];
      if (!k && !l) cur = a[i][j];
      else if (!l) cur = mv(rmq[i][j][k-1][l], rmq[i+(1<<(k-1))][j][k-1][l]);
      else cur = mv(rmq[i][j][k][l-1], rmq[i][j+(1<<(l-1))][k][l-1]);
    }
  }
  T query(const int &r1, const int &c1, const int &r2, const int &c2) {
    int k = log_2[r2-r1+1], l = log_2[c2-c1+1];
    return mv(mv(rmq[r1][c1][k][l], rmq[r2-(1<<k)+1][c2-(1<<l)+1][k][l]),
          mv(rmq[r2-(1<<k)+1][c1][k][l], rmq[r1][c2-(1<<l)+1][k][l]));
  }
};

ST<int> st;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  for (int i = 1; i <= n; ++i) cin >> B[i];
  st.build();
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