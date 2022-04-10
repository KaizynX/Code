/*
 * @Author: Kaizyn
 * @Date: 2022-04-04 13:44:34
 * @LastEditTime: 2022-04-04 13:48:36
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
const int N = 2e5 + 7;

int n;
int a[N], b[N];

void func(int &x, int &y) {
  int t = min(x, y);
  x -= t;
  y -= t;
}

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  int mx = max_element(b + 1, b + n + 1) - b;
  rotate(a + 1, a + mx + 1, a + n + 1);
  rotate(b + 1, b + mx + 1, b + n + 1);
  int ta = a[1], tb = 0;
  for (int i = 2; i <= n; ++i) {
    func(ta, b[i]);
    func(tb, a[i]);
    ta += a[i];
    tb += b[i];
  }
  func(ta, b[1]);
  if (b[1] && tb) return false;
  return true;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}