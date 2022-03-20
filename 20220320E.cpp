/*
 * @Author: Kaizyn
 * @Date: 2022-03-20 12:27:33
 * @LastEditTime: 2022-03-20 12:31:33
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
const int N = 4;

int c[N], rk[N], r[N];
int a[N][N];

inline bool solve() {
  iota(rk, rk + N, 0);
  for (int i = 0; i < N; ++i) cin >> c[i];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> a[i][j];
    }
  }
  do {
    memcpy(r, c, sizeof r);
    int flag = 1;
    for (int _ = 0, i; _ < 3 * N; ++_) {
      i = rk[_ % N];
      if (r[i] < c[i]) {
        flag = 0;
        break;
      }
      r[i] = 0;
      for (int j = 0; j < N; ++j) r[j] += a[i][j];
    }
    if (flag) return true;
  } while (next_permutation(rk, rk + N));
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}