/*
 * @Author: Kaizyn
 * @Date: 2022-05-14 23:25:46
 * @LastEditTime: 2022-05-14 23:43:47
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
const int N = 1e5 + 7;
const int R = 200;

ll ans[N], pw[N];
int a[R + 7][R + 7];

void init() {
  for (int i = 1; i < N; ++i) pw[i] = 1ll * i * i;
  for (int r = 1; r <= R; ++r)
  for (int x = 0; x <= r; ++x) {
    int y = round(sqrt(pw[r] - pw[x]));
    a[x][y] = a[y][x] = 1;
  }
  for (int r = 1; r <= R; ++r)
  for (int x = 1; x <= r; ++x)
  for (int y = 1; y <= r; ++y) {
    if (!a[x][y] && round(sqrt(pw[x] + pw[y])) <= r) ++ans[r];
  }
  /*
  for (int x = 1; x <= R; ++x)
  for (int y = 1; y <= R; ++y) {
    cout << a[x][y] << " \n"[y == R];
  }
  */
}

inline void solve() {
  int r;
  cin >> r;
  cout << ans[r] * 4 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  init();
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}