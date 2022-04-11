/*
 * @Author: Kaizyn
 * @Date: 2022-04-11 13:29:12
 * @LastEditTime: 2022-04-11 13:37:40
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

vector<int> seq = {1,2,3,7,19,51,131,323,771,1795,4099,9219,20483,45059,98307,212995,458755,983043,2097155,4456451,9437187,19922947,41943043,88080387,184549379,385875971,805306371,1000000007};

vector<int> to_binary(int x) {
  vector<int> ans;
  do {
    ans.emplace_back(x & 1);
    x >>= 1;
  } while (x);
  reverse(ans.begin(), ans.end());
  return ans;
}

inline void brute() {
  vector<int> x;
  auto it = x.end();
  seq.assign({1});
  int cur = 0;
  for (int i = 1, j = 0; i <= 1000'000'000; ++i) {
    if (it == x.end()) {
      x = to_binary(j++);
      it = x.begin();
    }
    if (*it == 0) {
      cur = 0;
    } else {
      ++cur;
      if (cur >= (int)seq.size()) {
        seq.emplace_back(i);
        cout << i << ",";
      }
    }
    ++it;
  }
}

void solve() {
  int k;
  cin >> k;
  cout << upper_bound(seq.begin(), seq.end(), k) - seq.begin() - 1 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // brute();
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}