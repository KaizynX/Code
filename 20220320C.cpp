/*
 * @Author: Kaizyn
 * @Date: 2022-03-20 12:03:23
 * @LastEditTime: 2022-03-20 12:20:51
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

#ifdef DEBUG

struct Euler {
  vector<int> prime, check;
  int& operator [](const int &i) { return check[i]; }
  void init(int n) {
    prime.clear();
    check = vector<int>(n+1);
    for (int i = 2; i <= n; ++i) {
      if (!check[i]) prime.emplace_back(i), check[i] = i;
      for (const int &j : prime) {
        if (i*j > n) break;
        check[i*j] = j;
        if (i%j == 0) break;
      }
    }
  }
} E;

using u128 = __uint128_t;
int n, m;
map<ll, int> ans;
constexpr ll INF = 1e18;

bool check(ll mul, ll p) {
  ++mul;
  if (mul % p) return false;
  mul /= p;
  if (mul <= 1) return false;
  return __builtin_popcountll(mul) == 1;
}
#endif

inline void solve() {
  ll n;
  cin >> n;
  cout << (n >= 2431 ? 1 : 0) << '\n';
  return;
  #ifdef DEBUG
  E.init(2e6);
  m = E.prime.size() - 1;
  for (int i = 0; i < m; ++i) {
    u128 mul = 1;
    for (int j = i; j < m; ++j) {
      mul *= E.prime[j];
      if (mul > INF) break;
      if (check(mul, E.prime[j + 1])) {
        ++ans[mul];
        cout << i << ' ' << j << ' ' << (ll)mul << ' ' << E.prime[j + 1] << '\n';
      }
    }
  }
  orzeach(ans);
  #endif
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