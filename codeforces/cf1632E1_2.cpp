/*
 * @Author: Kaizyn
 * @Date: 2022-01-31 00:08:11
 * @LastEditTime: 2022-01-31 00:24:06
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
const int N = 3e3 + 7;

int n, ans, pd1;
vector<int> e[N];
pii dis[N][N];
int ptr[N], cnt[N];

void dfs(int u, int fa, int dep, pii *dis) {
  dis[u] = {dep, u};
  for (int v : e[u]) {
    if (v == fa) continue;
    dfs(v, u, dep + 1, dis);
  }
}

bool check() {
  return *max_element(cnt[i]) < pts.size();
}

void my_modify(int x) {
  for (int i = pd1; i <= n; ++i) {
    while (ptr[i] && dis[i][ptr[i]].first + x > ans) {
      --cnt[dis[i][ptr[i]--].second];
    }
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    dfs(i, 0, 0, dis[i]);
    sort(dis[i] + 1, dis[i] + n + 1);
  }
  ans = 0;
  pd1 = 0;
  for (int i = 1; i <= n; ++i) {
    while (ptr[i] < n && dis[i][ptr[i] + 1].first + 1 <= ans) {
      ++cnt[dis[i][++ptr[i]].second];
    }
  }
  for (int x = 1; x <= n; ++x) {
    my_modify(x);
    while (*max_element(cnt + 1, cnt + n + 1) < (int)pts.size()) {
      ++ans;
      while (pd1 && dis[1][pd1].first <= ans) {
        int i = dis[1][pd1].second;
        while (ptr[i] < n && dis[i][ptr[i] + 1].first + x <= ans) {
          ++cnt[dis[i][++ptr[i]].second];
        }
      }
      my_modify(x);
    }
    cout << ans << " \n"[x == n];
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