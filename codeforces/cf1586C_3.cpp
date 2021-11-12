/*
 * @Author: Kaizyn
 * @Date: 2021-11-12 23:12:22
 * @LastEditTime: 2021-11-12 23:20:12
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
const int N = 1e6+7;

int n, m, q;
int sum[N];
string a[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) sum[i] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i > 1) for (int j = 1; j < m; ++j) {
      sum[j+1] += a[i][j-1] == 'X' && a[i-1][j] == 'X';
    }
  }
  for (int i = 1; i <= m; ++i) sum[i] += sum[i-1];
  cin >> q;
  for (int i = 1, l, r; i <= q; ++i) {
    cin >> l >> r;
    cout << (sum[l] == sum[r] ? "YES" : "NO") << '\n';
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