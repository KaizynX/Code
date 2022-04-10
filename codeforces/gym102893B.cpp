/*
 * @Author: Kaizyn
 * @Date: 2022-04-04 13:16:57
 * @LastEditTime: 2022-04-04 13:28:08
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

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
using uint = uint32_t;
// const int N = ;

int n;

inline void solve() {
  cin >> n;
  vector<string> pre, cur = {"0", "1"};
  for (int i = 1; i <= n; ++i) {
    swap(cur, pre);
    cur.clear();
    for (uint j = 0; j < pre.size(); j += 2) {
      cur.emplace_back(pre[j] + pre[j + 1]);
    }
    uint need_size = 1u << (n - i);
    for (uint j = 0; j < pre.size() && cur.size() < need_size; ++j) {
      for (uint k = 0; k < pre.size() && cur.size() < need_size; ++k) {
        if (j % 2 == 0 && k == j + 1) continue;
        cur.emplace_back(pre[j] + pre[k]);
      }
    }
    #ifdef DEBUG
    // assert(cur.size() % 2 == 0);
    orzeach(cur);
    #endif
  }
  cout << cur[0] << '\n';
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