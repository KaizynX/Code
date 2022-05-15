/*
 * @Author: Kaizyn
 * @Date: 2022-05-15 20:51:53
 * @LastEditTime: 2022-05-15 21:21:36
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
const int N = 2e5 + 7;

int n, x;
int vis[N];

inline void solve() {
  cin >> n >> x;
  if (abs((x - 1) - (n - x)) <= 1) {
    for (int i = 1, k = x - 1 >= n - x ? -1 : 1; i <= n; ++i) {
      cout << x << " \n"[i == n];
      x += k;
      k = -k - k / abs(k);
    }
    return;
  }
  int y = 0;
  for (int i = n; i; --i) {
    if (x == i) continue;
    if (i - 1 - (x < i) >= n - i - (x > i)) y = i;
  }
  assert(y);
  #ifdef DEBUG
  orz(y);
  #endif
  vis[x] = 1;
  cout << x;
  for (int i = 2, k = -1; i <= n; ++i) {
    assert(y >= 1 && y <= n);
    vis[y] = 1;
    cout << ' ' << y;
    if (i == n) break;
    y += k;
    while (vis[y]) y += k / abs(k), k += k / abs(k);
    k = -k - k / abs(k);
  }
  cout << '\n';
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