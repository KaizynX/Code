/*
 * @Author: Kaizyn
 * @Date: 2022-05-14 19:59:10
 * @LastEditTime: 2022-05-14 20:47:48
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

inline void solve() {
  int w;
  cin >> w;
  vector<int> v;
  for (int i = 1; i < 1<<7; ++i) {
    v.emplace_back(i);
    v.emplace_back(i << 7);
  }
  for (int i = 1; i < 1<<6; ++i) {
    if ((i << 14) > w) break;
    v.emplace_back(i << 14);
  }
  cout << v.size() << '\n';
  for (int i : v) cout << i << ' ';
  cout << '\n';

  for (int i = 1; i < 20; ++i) {
    int t = (1000000 >> i) + (1 << (i / 2)) + (1 << ((i + 1) / 2));
    cout << i << ' ' << t << '\n';
  }
  cout << bitset<20>(1000000) << '\n';
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