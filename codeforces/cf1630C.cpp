/*
 * @Author: Kaizyn
 * @Date: 2022-01-27 23:21:25
 * @LastEditTime: 2022-01-27 23:39:08
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
const int N = 2e5 + 7;

int n;
int a[N];
int L[N], R[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    L[i] = n + 1;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    L[a[i]] = min(L[a[i]], i);
    R[a[i]] = max(R[a[i]], i);
  }
  int ans = n;
  for (int l = 1, r, mx; l <= n; ) {
    r = R[a[l]];
    --ans;
    if (l == r) {
      ++l;
      continue;
    }
    while (l <= r) {
    #ifdef DEBUG
    cout << l << ' ' << r << '\n';
    #endif
      mx = r;
      for (int i = l; i <= r; ++i) {
        mx = max(mx, R[a[i]]);
      }
      --ans;
      l = r + 1;
      r = mx;
    }
    /*
    mx = r = max(r, R[a[l]]);
    #ifdef DEBUG
    cout << l << ' ' << r << '\n';
    #endif
    for (int i = l; i <= r; ++i) {
      mx = max(mx, R[a[i]]);
    }
    l = r + 1;
    r = mx;
    --ans;
    */
  }
  cout << ans << '\n';
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
/*
20
1 2 3 1 2 3 9 4 4 8 8 8 5 6 5 7 6 7 7 7
0 1 0 1 1 0 0 0 0 0 1 0 0 0 1 0 1 1 1 0
8
*/