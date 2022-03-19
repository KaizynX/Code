/*
 * @Author: Kaizyn
 * @Date: 2022-03-19 20:51:51
 * @LastEditTime: 2022-03-19 21:29:10
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
const int N = 1e6 + 7;

int n, m;
int a[N];
int ans[N << 1];

int single(int m) {
  // int cnt[30];
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    // C(n,k) 当 `n&k == k` 为奇数反之偶数
    // int cof = C(n - i + m - 1, m - 1) & 1;
    int cof = ((n - i + m - 1) & (m - 1)) == (m - 1);
    if (cof) ans ^= a[i];
    /*
    if (cof) for (int b = 0; b < 30; ++b) {
      int v = (a[i] >> b) & 1;
      cnt[b] += v;
    }
    */
  }
  /*
  for (int b = 0; b < 30; ++b) {
    if (cnt[b] & 1) ans |= 1 << b;
  }
  */
  return ans;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) {
    int ans = a[n];
    int ri = (1 << 20) - 1 - i;
    // i <= i | j < n + i
    for (int s = ri; s; s = (s - 1) & ri) {
      if (s > 0 && s < n) ans ^= a[n - s];
    }
    // if (ri < n) ans ^= a[n]; // s == 0
    cout << ans << " \n"[i + 1 == m];
  }
  #ifdef DEBUG
  for (int i = 1; i <= m; ++i) {
    cout << single(i) << " \n"[i == m];
  }
  #endif
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