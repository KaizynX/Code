/*
 * @Author: Kaizyn
 * @Date: 2022-01-03 22:33:45
 * @LastEditTime: 2022-01-03 22:52:28
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

int n;
map<pii, int> vis;
set<int> lval, rval;

inline void solve() {
  cin >> n;
  int ml = 1e9+7, mr = 0, ans;
  vis.clear();
  lval.clear();
  rval.clear();
  for (int i = 1, l, r, c; i <= n; ++i) {
    cin >> l >> r >> c;
    if (vis.count({l, r})) vis[{l, r}] = min(vis[{l, r}], c);
    else vis[{l, r}] = c;
    if (l == ml) {
      lval.insert(c);
    } else if (l < ml) {
      ml = l;
      lval.clear();
      lval.insert(c);
    }
    if (r == mr) {
      rval.insert(c);
    } else if (r > mr) {
      mr = r;
      rval.clear();
      rval.insert(c);
    }
    ans = *lval.begin() + *rval.begin();
    if (vis.count({ml, mr})) {
      ans = min(ans, vis[{ml, mr}]);
    }
    cout << ans << '\n';
  }
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