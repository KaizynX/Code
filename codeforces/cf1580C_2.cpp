/*
 * @Author: Kaizyn
 * @Date: 2021-09-30 19:41:22
 * @LastEditTime: 2021-09-30 19:44:33
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
const int B = 501;

int n, m;
int x[N], y[N], z[N], k[N], badd[N], vis[N];
int sadd[B][B];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    z[i] = x[i]+y[i];
  }
  int cur = 0;
  for (int i = 1, op, k, val; i <= m; ++i) {
    cin >> op >> k;
    cur += badd[i];
    val = op == 1 ? 1 : -1;
    if (op == 1) vis[k] = i;
    if (z[k] >= B) {
      for (int j = vis[k]; j <= m; j += z[k]) {
        if (j+x[k] <= m) badd[j+x[k]] += val;
        if (j+z[k] <= m) badd[j+z[k]] -= val;
        if (i >= j+x[k] && i < j+z[k]) cur += val;
      }
    } else {
      for (int j = vis[k]+x[k]; j < vis[k]+z[k]; ++j) {
        sadd[z[k]][j%z[k]] += val;
      }
    }
    int ans = cur;
    for (int j = 2; j < B; ++j) {
      ans += sadd[j][i%j];
    }
    cout << ans << '\n';
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