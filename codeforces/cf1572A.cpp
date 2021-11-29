/*
 * @Author: Kaizyn
 * @Date: 2021-11-29 13:30:19
 * @LastEditTime: 2021-11-29 13:39:35
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
vector<int> a[N], e[N], seq, lds;

inline int solve() {
  priority_queue<int, vector<int>, greater<int>> q;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> deg[i];
    a[i].resize(deg[i]);
    if (deg[i] == 0) q.push(i);
    for (int j = 0; j < deg[i]; ++j) {
      cin >> a[i][j];
      e[a[i][j]].emplace_back(i);
    }
  }
  seq.clear();
  while (q.size()) {
    int u = q.top();
    q.pop();
    seq.emplace_back(u);
    for (int v : e[u]) {
      if (--deg[v] == 0) {
        q.push(v);
      }
    }
  }
  if ((int)seq.size() != n) return -1;
  lds.clear();
  for (int x : seq) {
    auto it = lower_bound(lds.begin(), lds.end(), x, greater<int>());
    if (it == lds.end()) lds.emplace_back(x);
    else *it = x;
  }
  return lds.size();
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