/*
 * @Author: Kaizyn
 * @Date: 2021-11-23 13:05:37
 * @LastEditTime: 2021-11-23 13:13:17
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
// const int N = 1e9;

int n;
map<pii, ll> mp;

ll query(int l, int r) {
  if (l == r) return 0;
  if (mp.count({l, r})) return mp[{l, r}];
  cout << "? " << l << " " << r << endl;
  ll x;
  cin >> x;
  return mp[{l, r}] = x;
}

ll check(ll x) {
  for (ll y = sqrt(2*x), i = max(1ll, y-3); i <= y+3; ++i) {
    if (i*(i-1) == 2*x) return i;
  }
  return -1;
}

inline void solve() {
  mp.clear();
  cin >> n;
  ll A = query(1, n);
  int l = 1, r = n, mid, i, j, k;
  while (l < r) {
    mid = (l+r)/2;
    if (query(1, mid) < A) l = mid+1;
    else r = mid;
  }
  k = l;
  ll B = query(1, k-1);
  j = k-A+B;
  i = j-check(A-(k-j+1ll)*(k-j)/2);
  cout << "! " << i << ' ' << j << ' ' << k << endl;
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