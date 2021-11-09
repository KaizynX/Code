/*
 * @Author: Kaizyn
 * @Date: 2021-11-07 13:18:34
 * @LastEditTime: 2021-11-07 13:30:58
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
const int N = 5e5+7;

int n, k, m;
vector<int> deg[N], e[N];
set<int> ids[N];

inline void solve() {
  cin >> n >> k >> m;
  deg[1].resize(n+1);
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    ++deg[1][v];
  }
  for (int i = 1; i <= k; ++i) ids[0].insert(i);
  for (int i = 1; i <= n; ++i) {
    if (deg[1][i] == 0) ids[i] = ids[0];
  }
  for (int i = 2; i <= k; ++i) deg[i] = deg[1];
  for (int i = 1, c, r; i <= n*k; ++i) {
    cin >> c;
    r = *ids[c].begin();
    cout << r << ' ';
    ids[c].erase(r);
    for (int v : e[c]) {
      if (--deg[r][v] == 0) {
        ids[v].insert(r);
      }
    }
  }
  cout << '\n';
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