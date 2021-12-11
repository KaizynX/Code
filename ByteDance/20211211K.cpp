/*
 * @Author: Kaizyn
 * @Date: 2021-12-11 15:15:35
 * @LastEditTime: 2021-12-11 15:34:26
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
const int N = 1e5+7;

int n, k;
int a[N], vis[N];
queue<int> q;

void dfs(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  dfs(a[x]);
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = 0; // 环数
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    dfs(i);
    ++ans;
  }
  // 环最多
  int tmp = ans + k;
  if (tmp <= n) {
    cout << n - tmp << ' ';
  } else {
    cout << (tmp - n) % 2 << ' ';
  }
  // 环最少
  tmp = ans - k;
  if (tmp >= 1) {
    cout << n - tmp << '\n';
  } else {
    cout << n - 1 - (1 - tmp) % 2 << '\n';
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