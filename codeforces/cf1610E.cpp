/*
 * @Author: Kaizyn
 * @Date: 2021-11-24 00:37:54
 * @LastEditTime: 2021-11-24 01:03:16
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
ll a[N], s[N];

bool check(int m) {
  int l = (m-1)/2, r = m-l;
  for (int i = l; i+r <= n; ++i) {
    ll sum = s[i+r]-s[i]+s[l];
    int ln = upper_bound(a+1, a+l+1, sum/m-(sum%m==0))-a-1;
    int rn = a+i+r+1-upper_bound(a+i+1, a+i+r+1, sum/m);
    if (rn > ln) return true;
  }
  return false;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) s[i] = s[i-1]+a[i];
  int l = 1, r = n, mid;
  while (l < r) {
    mid = (l+r+1)/2;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << n-l << '\n';
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