/*
 * @Author: Kaizyn
 * @Date: 2022-05-14 21:00:18
 * @LastEditTime: 2022-05-14 21:03:29
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

int n, m;
int vis[N];
vector<int> e[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v : e[u]) {
    if (vis[v]) continue;
    cout << u << ' ' << v << '\n';
    dfs(v);
  }
}

void bfs(int s) {
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : e[u]) {
      if (vis[v]) continue;
      vis[v] = 1;
      cout << u << ' ' << v << '\n';
      q.push(v);
    }
  }
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  memset(vis, 0, sizeof vis);
  dfs(1);
  memset(vis, 0, sizeof vis);
  bfs(1);
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