/*
 * @Author: Kaizyn
 * @Date: 2022-04-11 13:06:56
 * @LastEditTime: 2022-04-11 13:27:05
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

#define log(x) (31-__builtin_clz(x))

vector<pii> ans;

/*
void init() {
  ans.emplace_back(1, 0);
  // int mx;
  for (int i = 1, bl = 1, bv = 2, len = 1; len < 1000'000'000; ++i) {
    if (i == bv) bv *= 2, ++bl; 
    len += bl;
    if (i & 1) continue;
    int tmp = __builtin_ctz(~(i - 1)) + __builtin_clz(~i);
    if (tmp > ans.back().second) ans.emplace_back(len, tmp);
    // mx = i;
  }
  // orz(mx);
  // orz(ans.size());
}
*/

int calc(ll x) {
  int ans = 0, cur = 0;
  while (x) {
    if (x & 1) {
      ++cur;
      ans = max(ans, cur);
    } else {
      cur = 0;
    }
    x >>= 1;
  }
  return ans;
}

void brute() {
  int len = 1;
  ans.emplace_back(1, 0);
  for (int i = 1, bl = 1, bv = 2; len < 1000'000'000; ++i) {
    if (i == bv) bv *= 2, ++bl;
    len += bl;
    int tmp = calc((i & 1) ? i : (((i - 1ll) << bl) | i));
    if (tmp > ans.back().second) {
      ans.emplace_back(len, tmp);
      cout << "{" << len << ", " << tmp << "},\n";
    }
  }
}

inline void solve() {
  int k;
  cin >> k;
  auto it = --upper_bound(ans.begin(), ans.end(), pii{k, 233});
  cout << it->second << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  // init();
  brute();
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}