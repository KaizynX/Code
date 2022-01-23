/*
 * @Author: Kaizyn
 * @Date: 2022-01-23 20:35:47
 * @LastEditTime: 2022-01-23 20:42:46
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
const int N = 16;

int n, ans;
int a[N][N];

void dfs(int vis, int val = 0) {
  if (vis == 0) {
    ans = max(ans, val);
    return;
  }
  int i = 0;
  while ((vis >> i) % 2 == 0) ++i;
  for (int j = i + 1; j < 2 * n; ++j) if ((vis >> j) & 1) {
    dfs(vis ^ (1 << i) ^ (1 << j), val ^ a[i][j]);
  }
}

inline void solve() {
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = i + 1; j < 2 * n; ++j) {
      cin >> a[i][j];
    }
  }
  dfs((1 << (2 * n)) - 1, 0);
  cout << ans << '\n';
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