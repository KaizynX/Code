/*
 * @Author: Kaizyn
 * @Date: 2022-02-13 20:06:29
 * @LastEditTime: 2022-02-13 20:13:25
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
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 3e5 + 7;

int n;
ll s[N], a[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  ll mn[3] = {0, 0, 0};
  for (int i = 2; i <= n; ++i) {
    a[i + 2] = a[i - 1] + s[i] - s[i - 1];
    mn[(i + 2) % 3] = max(mn[(i + 2) % 3], -a[i + 2]);
  }
  #ifdef DEBUG
  orzarr(a + 1, n + 2);
  #endif
  for (int i = 1; i <= 3; ++i) a[i] = mn[i % 3];
  if (a[1] + a[2] + a[3] > s[1]) return cout << "No\n", void();
  a[1] = s[1] - a[2] - a[3];
  for (int i = 2; i <= n; ++i) {
    a[i + 2] = a[i - 1] + s[i] - s[i - 1];
  }
  cout << "Yes\n";
  for (int i = 1; i <= n + 2; ++i) {
    #ifdef DEBUG
    assert(a[i] >= 0);
    if (i <= n) assert(s[i] = a[i] + a[i + 1] + a[i + 2]);
    #endif
    cout << a[i] << " \n"[i == n + 2];
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