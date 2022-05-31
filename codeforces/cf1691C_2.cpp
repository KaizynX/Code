/*
 * @Author: Kaizyn
 * @Date: 2022-05-31 22:42:22
 * @LastEditTime: 2022-05-31 22:57:02
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
string s, t;

void f(int x, int y) {
  if (x == -1 || y == -1) return;
  if (k >= abs(x - y)) {
    k -= abs(x - y);
    swap(s[x], s[y]);
  }
  #ifdef DEBUG
  cerr << "done f\n";
  #endif
}

int calc() {
  int ans = 0;
  if (s[1] == '1') ans += 10;
  if (s[n] == '1') ans += 1;
  for (int i = 2; i < n; ++i) {
    if (s[i] == '1') ans += 11;
  }
  return ans;
}

inline void solve() {
  cin >> n >> k >> s;
  s = '#' + s;
  t = s;
  int kk = k;
  int l1 = -1, r1 = -1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') {
      if (l1 == -1) l1 = i; 
      r1 = i;
    }
  }
  #ifdef DEBUG
  orz(l1);
  orz(r1);
  #endif
  f(1, l1);
  if (l1 != r1) f(n, r1);
  #ifdef DEBUG
  orz(calc());
  #endif
  int ans = calc();
  s = t;
  k = kk;
  f(n, r1);
  if (l1 != r1) f(1, l1);
  ans = min(ans, calc());
  #ifdef DEBUG
  orz(calc());
  #endif
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