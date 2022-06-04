/*
 * @Author: Kaizyn
 * @Date: 2022-06-04 20:16:45
 * @LastEditTime: 2022-06-04 20:25:52
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
const int N = 15e4 + 7;

int n, m, Q;
int vis[N];
ll ans;
vector<int> e[N], all;
queue<int> q;

/*
void dfs(int u, int d = 0) {
  ans += u;
  vis.insert(u);
  if (d < k) for (int v : e[u]) {
    if (vis.count(v)) continue;
    dfs(v, d + 1);
  }
}
*/

ll bfs(int x, int k) {
  ll ans = 0;
  q.push(x);
  vis[x] = 0;
  all.emplace_back(x);
  while (q.size()) {
    int u = q.front();
    q.pop();
    ans += u;
    if (vis[u] >= k) continue;
    for (int v : e[u]) {
      if (~vis[v]) continue;
      vis[v] = vis[u] + 1;
      q.push(v);
      all.emplace_back(v);
    }
  }
  for (int i : all) vis[i] = -1;
  all.clear();
  return ans;
}

inline void solve() {
  cin >> n >> m;
  memset(vis + 1, -1, sizeof(int) * n);
  for (int i = 1, a, b; i <= m; ++i) {
    cin >> a >> b;
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }
  cin >> Q;
  for (int i = 1, x, k; i <= Q; ++i) {
    cin >> x >> k;
    cout << bfs(x, k) << '\n';
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