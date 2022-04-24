/*
 * @Author: Kaizyn
 * @Date: 2022-04-24 19:59:14
 * @LastEditTime: 2022-04-24 20:28:53
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
// const int N = ;

ll n, a, b, x, y, z;

ll f(int na) {
  int nb = (n - na * a) / b;
  return na * y + nb * z + (n - na * a - nb * b) * x;
}

inline ll solve() {
  // na * Y + nb * Z + (n - na * A - nb * B) * X
  // (Y - AX) * na + (Z - BX) * nb + n * X
  // nb = (n - na * a) / b
  
  cin >> n >> a >> b >> x >> y >> z;
  if (y >= a * x && z >= b * x) {
    return n * x;
  } else if (y >= a * x) {
    return n / b * z + n % b * x;
  } else if (z >= b * x) {
    return n / a * y + n % a * x;
  } else {
    if (a < b) {
      swap(a, b);
      swap(y, z);
    }
    #ifdef DEBUG
    int l = 0, r = n / a, mid;
    for (int i = 0; i <= r; ++i) {
      cout << f(i) << " \n"[i == r];
    }
    #endif
    while (l < r) {
      mid = (l + r) / 2;
      if (f(mid) < f(mid + 1)) r = mid;
      else l = mid + 1;
    }
    #ifdef DEBUG
    orz(l);
    orz(f(l));
    #endif
    return f(l);
  }
}
/*
while (l < r) {
  int mid = (l+r)>>1;
  if (f(mid) < f(mid+1)) r = mid;
  else l = mid+1;
}
*/

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