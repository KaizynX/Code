/*
 * @Author: Kaizyn
 * @Date: 2021-11-29 13:43:21
 * @LastEditTime: 2021-11-29 13:46:14
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
  for (int i = 1; i <= n; ++i) {
    cin >> deg[i];
    if (deg[i] == 0) q.insert(i);
    for (int j = 0, a; j < deg[i]; ++j) {
      cin >> a;
      e[a].emplace_back(i);
    }
  }
  int ans = 1, cnt = 0;
  for (int last = 0; q.size(); ) {
    auto it = q.lower_bound(last);
    if (it == q.end()) {
      last = 0;
      ++ans;
      continue;
    }
    int u = *it;
    last = u;
    q.erase(it);
    ++cnt;
    for (int v : e[u]) {
      if (--deg[v] == 0) {
        q.insert(v);
      }
    }
  }
  if (cnt != n) return -1;
  else return ans;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
    for (int i = 1; i <= n; ++i) e[i].clear();
  }
  return 0;
}