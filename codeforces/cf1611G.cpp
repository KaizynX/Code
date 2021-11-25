/*
 * @Author: Kaizyn
 * @Date: 2021-11-25 22:51:23
 * @LastEditTime: 2021-11-26 00:26:35
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
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;

int n, m;
string s;
vector<int> X[2], Y[2];
set<pii> st[2];

inline void solve() {
  for (int id : {0, 1}) {
    X[id].clear();
    Y[id].clear();
  }
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) if (s[j] == '1') {
      X[(i+j)&1].emplace_back(i);
      Y[(i+j)&1].emplace_back(j);
    }
  }
  int ans = 0;
  for (int id : {0, 1}) {
    st[0].clear();
    st[1].clear();
    st[0].insert({INF, -1});
    st[1].insert({INF, -1});
    auto &x = X[id], &y = Y[id];
    auto cmp = [&](int li, int ri, int i) {
      if (li == -1) return ri;
      if (ri == -1) return li;
      int dl = x[i]-x[li]-y[i]+y[li];
      int dr = x[ri]-x[i]-y[i]+y[ri];
      return dl <= dr ? li : ri;
    };
    for (int i = 0; i < (int)x.size(); ++i) {
      int li = st[0].lower_bound({y[i]-x[i], 0})->second;
      int ri = st[1].lower_bound({y[i]+x[i], 0})->second;
      int j = cmp(li, ri, i);
      #ifdef DEBUG
      printf("i=%d,y-x=%d,y+x=%d,li=%d,ri=%d,j=%d\n",
          i, y[i]-x[i], y[i]+x[i], li, ri, j);
      #endif
      if (j == -1) {
        ++ans;
      } else {
        st[0].erase({y[j]-x[j], j});
        st[1].erase({y[j]+x[j], j});
      }
      st[0].insert({y[i]-x[i], i});
      st[1].insert({y[i]+x[i], i});
    }
  }
  cout << ans << '\n';
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