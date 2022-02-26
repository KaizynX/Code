/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 12:22:44
 * @LastEditTime: 2022-02-26 12:27:25
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
const int N = 1e6 + 7;

int n, m;
int rk[N];
string s[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    rk[i] = i;
  }
  int id = 0;
  auto cmp = [&id](int x, int y) -> bool {
    if (id & 1) return s[x][id] > s[y][id];
    else return s[x][id] < s[y][id];
  };
  // for (id = 0; id < m; ++id) sort(rk + 1, rk + n + 1, cmp);
  for (id = m - 1; id >= 0; --id) sort(rk + 1, rk + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    cout << rk[i] << " \n"[i == n];
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