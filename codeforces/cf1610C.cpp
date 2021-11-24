/*
 * @Author: Kaizyn
 * @Date: 2021-11-23 23:12:30
 * @LastEditTime: 2021-11-24 00:04:52
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
int a[N], b[N], dp[N];
set<int> st; // dp[i-1]-1 > dp[i]

void update(int p, int v) {
  if (dp[p] >= v) return;
  st.erase(p);
  st.erase(p-1);
  dp[p] = v;
  if (dp[p-1]-1 > dp[p]) st.insert(p-1);
  if (dp[p]-1 > dp[p+1]) st.insert(p);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    dp[i] = -1;
  }
  dp[0] = n; dp[n+1] = INF;
  st.insert(0);
  vector<int> vec;
  for (int i =  1; i <= n; ++i) {
    int p = upper_bound(dp, dp+n+1, b[i], greater<int>())-dp;
    // dp[p] the left p that dp[p] < b[i]
    vec.end();
    update(p, b[i]);
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (dp[i] >= 0) ans = i;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}