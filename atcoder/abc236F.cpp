/*
 * @Author: Kaizyn
 * @Date: 2022-01-23 20:49:13
 * @LastEditTime: 2022-01-23 21:47:02
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
const int N = (1 << 16) + 7;

template <typename T>
struct LinearBase {
  int sz = sizeof(T)*8, zero;
  T tot;
  vector<T> b; // , rb, p;
  LinearBase(){ init(); }
  void init() {
    tot = zero = 0;
    vector<T>(sz, 0).swap(b);
    // vector<T>().swap(rb);
    // vector<T>().swap(p);
  }
  bool insert(T x) {
    for (int i = sz-1; i >= 0; --i) if ((x>>i)&1) {
      if (!b[i]) { b[i] = x; return 1; }
      x ^= b[i];
    }
    return 0;
  }
  bool find(T x) {
    for (int i = sz-1; i >= 0; --i) if ((x>>i)&1) {
      if (!b[i]) { return false; }
      x ^= b[i];
    }
    return true;
  }
};

int n;
pii p[N];
LinearBase<int> lb;

inline void solve() {
  cin >> n;
  n = 1 << n;
  for (int i = 1; i < n; ++i) {
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(p + 1, p + n);
  lb.init();
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    if (lb.insert(p[i].second)) ans += p[i].first;
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