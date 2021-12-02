/*
 * @Author: Kaizyn
 * @Date: 2021-11-28 23:20:15
 * @LastEditTime: 2021-11-28 23:29:26
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
const int N = 1e3+7;

template <typename T = int> struct DSU {
  vector<int> fa;
  vector<T> w;
  void init(int n, T v = 1) {
    fa = vector<int>(n+1);
    iota(fa.begin(), fa.end(), 0);
    w = vector<T>(n+1, v);
  }
  void init(int n, T a[]) {
    fa = vector<int>(n+1);
    iota(fa.begin(), fa.end(), 0);
    w = vector<T>(a, a+n+1);
  }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (w[y] += w[x], fa[x] = y, true);
  }
};

int n, d, m;
int x[N], y[N];
DSU<int> dsu;
vector<int> vec;

inline void solve() {
  m = 0;
  cin >> n >> d;
  dsu.init(n);
  for (int i = 1; i <= d; ++i) {
    cin >> x[i] >> y[i];
    m += !dsu.merge(x[i], y[i]);
    vec.clear();
    for (int j = 1; j <= n; ++j) {
      if (dsu[j] == j) vec.emplace_back(dsu.w[j]);
    }
    sort(vec.rbegin(), vec.rend());
    int ans = -1;
    for (int j = 0; j <= m; ++j) ans += vec[j];
    cout << ans << '\n';
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