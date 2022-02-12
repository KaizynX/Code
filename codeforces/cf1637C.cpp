/*
 * @Author: Kaizyn
 * @Date: 2022-02-12 22:58:39
 * @LastEditTime: 2022-02-12 23:12:51
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
const int N = 1e5 + 7;

int n;
ll a[N];

inline ll solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (n == 3 && a[2] % 2) return -1;
  ll sum = 0, chk = 0, cnt = 0;
  for (int i = 2; i < n; ++i) {
    sum += a[i];
    chk += a[i] >= 2;
    cnt += a[i] % 2;
  }
  if (cnt == 0) return sum / 2;
  if (chk == 0) return -1;
  return sum / 2 + (cnt + 1) / 2;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}
/*
5
0 1 1 1 0
4
0 3 1 0
5
0 1 1 3 0
6
0 1 1 1 3 0

0 1 1 2 1 1
0 1 2 0 2 1
0 2 0 0 2 2
.
.
*/