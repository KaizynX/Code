/*
 * @Author: Kaizyn
 * @Date: 2022-03-06 17:48:01
 * @LastEditTime: 2022-03-06 18:16:06
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
const int N = 1e6 + 7;

int n, c;
int a[N], vis[N], sum[N];

inline bool solve() {
  cin >> n >> c;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    vis[a[i]] = 1;
  }
  for (int i = 1; i <= c; ++i) {
    sum[i] = sum[i - 1] + vis[i];
  }
  for (int i = 1; i <= c; ++i) if (vis[i]) {
    // x / i = j
    for (int j = 1; j * i <= c; ++j) {
      // x [ i*j, i*(j+1) )
      if (sum[min(c, i*(j+1)-1)] - sum[i*j-1] == 0) continue;
      if (!vis[j]) return false;
    }
  }
  return true;
  // sort(a + 1, a + n + 1);
  // n = unique(a + 1, a + n + 1) - a - 1;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << '\n';
    for (int i = 1; i <= c; ++i) {
      vis[i] = sum[i] = 0;
    }
  }
  return 0;
}