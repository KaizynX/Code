/*
 * @Author: Kaizyn
 * @Date: 2022-01-30 20:29:59
 * @LastEditTime: 2022-01-30 20:36:05
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
const int N = 2e5 + 7;

// priority_queue<pii, vector<int>, less<pii>> q;
priority_queue<pii> q;
int n, m;
int h[N], d[N];
vector<int> e[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    d[i] = -INF;
  }
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  d[1] = 0;
  q.push({0, 1});
  while (q.size()) {
    int u = q.top().second;
    int ud = q.top().first;
    q.pop();
    if (ud < d[u]) continue;
    for (int v : e[u]) {
      int uv = ud;
      if (h[u] > h[v]) uv += h[u] - h[v];
      else uv -= 2 * (h[v] - h[u]);
      if (uv > d[v]) {
        d[v] = uv;
        q.push({uv, v});
      }
    }
    #ifdef DEBUG
    orzarr(d + 1, n);
    #endif
  }
  cout << *max_element(d + 1, d + n + 1) << '\n';
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