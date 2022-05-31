/*
 * @Author: Kaizyn
 * @Date: 2022-05-31 22:42:22
 * @LastEditTime: 2022-05-31 22:45:41
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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e5 + 7;

int n, k;
string s;

void f(int p) {
  if (s[p - 1] == '1' || k == 0) return;
  for (int i = 2; i < n; ++i) {
    if (s[i - 1] == '1') {
      swap(s[p - 1], s[i - 1]);
      --k;
      return;
    }
  }
}

inline void solve() {
  cin >> n >> k >> s;
  int t1 = 0;
  for (char c : s) t1 += c - '0';
  f(1);
  f(n);
  int ans = 0;
  if (s[0] == '1') ans += 10;
  if (s[n - 1] == '1') ans += 1;
  for (int i = 2; i < n; ++i) {
    if (s[i - 1] == '1') ans += 11;
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