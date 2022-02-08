/*
 * @Author: Kaizyn
 * @Date: 2022-02-07 17:58:12
 * @LastEditTime: 2022-02-07 18:06:06
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
const int N = (1 << 20) + 7;

int n;
int a[N];
ll sum[N][2], tmp[N][2];

void f(int l, int r) {
  if (r - l == 1) {
    int v = __builtin_popcount(l) & 1;
    sum[l][v] = a[l];
    sum[l][v ^ 1] = 0;
    return;
  }
  int mid = (l + r) / 2;
  f(l, mid); f(mid, r);
  for (int i = l, j = mid; i < mid; ++i, ++j) {
    for (int k : {0, 1}) {
      tmp[i][k] = sum[i][k] + sum[j][k ^ 1];
      tmp[j][k] = sum[j][k] + sum[i][k];
    }
  }
  memcpy(sum + l, tmp + l, sizeof(ll) * 2 * (r - l));
}

inline void solve() {
  cin >> n;
  n = 1 << n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  f(0, n);
  for (int i = 0; i < n; ++i) {
    cout << sum[i][1] << " \n"[i + 1 == n];
  }
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