/*
 * @Author: Kaizyn
 * @Date: 2021-09-18 22:39:55
 * @LastEditTime: 2021-09-18 22:44:59
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
const int N = 2e5+7;

int n;
int deg[N];
vector<int> e[N];
set<int> q;

inline int solve() {
  q.clear();
  cin >> n;
  for (int i = 1, k; i <= n; ++i) {
    cin >> k;
    deg[i] = k;
    if (!k) q.insert(i);
    for (int j = 1, a; j <= k; ++j) {
      cin >> a;
      e[a].emplace_back(i);
    }
  }
  int cnt = 0, ans = 0;
  for (int u = 1; q.size(); ++u) {
    auto it = q.lower_bound(u);
    if (it == q.end()) it = q.begin(), ++ans;
    u = *it;
    q.erase(it);
    ++cnt;
    for (int v : e[u]) {
      if (--deg[v] == 0) q.insert(v);
    }
  }
  return cnt < n ? -1 : ans+1;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
      deg[i] = 0;
    }
  }
  return 0;
}