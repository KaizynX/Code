/*
 * @Author: Kaizyn
 * @Date: 2022-05-14 22:15:42
 * @LastEditTime: 2022-05-14 23:00:39
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e4 + 7;

int n, k;
vector<int> v;

inline void solve() {
  cin >> n >> k;
  int d = n * n - 1 - k;
  v.clear();
  for (int i = n * 4 - 6; i > 0; i -= 2) {
    if (d >= i) {
      d -= i;
      v.emplace_back(i);
      i -= 6;
    }
  }
  if (d) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << v.size() << '\n';
  reverse(v.begin(), v.end());
  for (int cen = 1, base = 0, i = n * 4 - 6; cen <= n / 2; ++cen) {
    for (int j = 1; j <= 4; ++j, i -= 2, base += n - cen) {
      if (v.size() && i == v.back()) {
        v.pop_back();
        cout << base + 2 << ' ' << base + 3 + i << '\n';
      }
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}