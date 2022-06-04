/*
 * @Author: Kaizyn
 * @Date: 2022-06-04 22:51:47
 * @LastEditTime: 2022-06-04 23:05:04
 */
#include <bits/stdc++.h>

// #define DEBUG

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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e5 + 7;

int n, c;
int a[N], b[N], p[N], t[N];

bool check(int col) {
  return t[col] == 0 || (t[col] >= a[col] && t[col] <= b[col]);
}

inline ll solve() {
  cin >> n >> c;
  for (int i = 1; i <= c; ++i) cin >> a[i] >> b[i];
  for (int i = 0; i < n; ++i) cin >> p[i];
  ll ans = 0;
  for (int l = 0; l < n; ++l) {
    memset(t + 1, 0, sizeof(int) * c);
    int ok = c;
    for (int r = l; r < l + n - (l != 0); ++r) {
      int cur = p[r % n];
      int before = check(cur);
      ++t[cur];
      int after = check(cur);
      ok += after - before;
      #ifdef DEBUG
      cout << "(" << l << "," << r << ")" << ok << '\n';
      #endif
      if (l < r && ok == c) {
        ++ans;
      }
    }
  }
  return ans;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << '\n';
  }
  return 0;
}