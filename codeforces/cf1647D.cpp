/*
 * @Author: Kaizyn
 * @Date: 2022-03-11 22:47:23
 * @LastEditTime: 2022-03-11 23:22:17
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
// const int N = 1e;

inline bool is_prime(long long x) {
  if(x == 1) return false;
  if(x == 2 || x == 3) return true;
  if(x%6 != 1 && x%6 != 5) return false;
  for(long long i = 5; i*i <= x; i += 6)
    if(x%i == 0 || x%(i+2) == 0) return false;
  return true;
}

/*
for(int i = 2; i*i <= x; ++i)
  if(x%i == 0) {
    p[++tot] = i;
    for(; x%i == 0; x /= i) k[tot]++;
  }
if(x > 1) p[++tot] = x, k[tot] = 1;
*/

vector<pair<int, int>> get_fac(int x) {
  vector<pair<int, int>> ans;
  for (int i = 2, k; i * i <= x; ++i) {
    if (x % i) continue;
    for (k = 0; x % i == 0; x /= i) ++k;
    ans.emplace_back(i, k);
  }
  if (x > 1) ans.emplace_back(x, 1);
  return ans;
}

int x, d;

inline bool solve() {
  cin >> x >> d;
  int k = 0;
  int y = x;
  while (y % d == 0) y /= d, ++k;
  if (k == 1) return false;
  if (y > 1 && !is_prime(y)) return true;
  y *= d;
  --k;
  auto fd = get_fac(d);
  for (auto &pr : fd) {
    int p = pr.first;
    int t = 0;
    while (y % p == 0) y /= p, ++t;
    #ifdef DEBUG
    printf("fd{%d,%d},t=%d\n", p, pr.second, t);
    #endif
    if (fd.size() == 1) {
      if (k * (pr.second - 1) >= t) return true;
    } else {
      if (k * pr.second > t) return true;
    }
  }
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "yes" : "no") << '\n';
  }
  return 0;
}