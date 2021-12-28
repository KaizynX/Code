/*
 * @Author: Kaizyn
 * @Date: 2021-12-28 22:03:43
 * @LastEditTime: 2021-12-28 22:56:36
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
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n;
int a[N], b[N];

void magic(int i, int y) {
  if (y < 0) return;
  y = min(y, b[i] / 3);
  b[i] -= 3 * y;
  b[i - 1] += y;
  b[i - 2] += 2 * y;
}

bool check(int x) {
  memcpy(b + 1, a + 1, sizeof(int) * n);
  magic(3, (x - b[1] + 1) / 2);
  magic(3, min((b[3] - x) / 3, x - b[2]));
  for (int i = 4; i <= n; ++i) {
    int tmp = b[i - 1] / 3;
    magic(i, min((x - b[i - 2] + 1) / 2, x - b[i - 1]));
    if (b[i - 2] < x) {
      int t = min({b[i] / 3, tmp, (x - b[i - 2] + 2) / 3});
      b[i] -= 3 * t;
      b[i - 2] += 3 * t;
    }
    magic(i, (x - b[i - 2] + 1) / 2);
    magic(i, min((b[i] - x) / 3, x - b[i - 1]));
  }
  for (int i = 1; i <= n; ++i) {
    if (b[i] < x) return false;
  }
  return true;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  #ifdef DEBUG
  // cout << check(7) << '\n';
  #endif
  int l = *min_element(a + 1, a + n + 1),
      r = *max_element(a + 1, a + n + 1), mid;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
4
100 2 4 12
*/