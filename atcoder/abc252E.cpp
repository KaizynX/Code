/*
 * @Author: Kaizyn
 * @Date: 2022-05-21 20:18:35
 * @LastEditTime: 2022-05-21 20:30:51
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

#define int ll
using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

int n, m;
int a[N], b[N], w[N];
vector<int> e[N];
pii dis[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i] >> w[i];
    e[a[i]].emplace_back(i);
    e[b[i]].emplace_back(i);
  }
  priority_queue<pii, vector<pii>, greater<pii>> q;
  for (int i = 1; i <= n; ++i) dis[i] = pii{inf<int>, 0};
  q.push({0, 1});
  dis[1] = pii{0, 0};
  while (q.size()) {
    int u = q.top().second;
    int ud = q.top().first;
    q.pop();
    if (ud > dis[u].first) continue;
    #ifdef DEBUG
    cerr << u << ':' << dis[u] << '\n';
    #endif
    if (dis[u].second) cout << dis[u].second << ' ';
    for (int i : e[u]) {
      int v = a[i] == u ? b[i] : a[i];
      int vd = w[i] + ud;
      if (vd < dis[v].first) {
        dis[v] = pii{vd, i};
        q.push({vd, v});
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