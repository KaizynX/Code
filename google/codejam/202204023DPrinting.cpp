/*
 * @Author: Kaizyn
 * @Date: 2022-04-02 21:22:21
 * @LastEditTime: 2022-04-02 21:25:17
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

int a[4][3], b[4];

inline void solve() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> a[j][i];
    }
  }
  int sum = 0;
  for (int i = 0; i < 4; ++i) {
    b[i] = *min_element(a[i], a[i] + 3);
    sum += b[i];
  }
  sum -= 1000000;
  if (sum < 0) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (int i = 0; i < 4; ++i) {
    int val = min(sum, b[i]);
    b[i] -= val;
    sum -= val;
  }
  for (int i = 0; i < 4; ++i) {
    cout << b[i] << " \n"[i == 3];
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