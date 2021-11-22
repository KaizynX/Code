/*
 * @Author: Kaizyn
 * @Date: 2021-11-22 14:00:17
 * @LastEditTime: 2021-11-22 14:21:01
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
map<pii, int> mp;

ll query(int l, int r) {
  if (l == r) return 0;
  if (mp.count({l, r})) return mp[{l, r}];
  cout << "? " << l << " " << r << endl;
  ll x;
  cin >> x;
  return mp[{l, r}] = x;
}

int check(ll x) {
  for (ll y = sqrt(2*x), i = max(1ll, y-3); i <= y+3; ++i) {
    if (i*(i-1) == 2*x) return i;
  }
  return -1;
}

inline void solve() {
  mp.clear();
  cin >> n;
  ll all = query(1, n);
  int l = 1, r = n, mid, i, j, k;
  if (~check(all)) {
    while (l < r) {
      mid = (l+r+1)/2;
      if (query(1, mid) == 0) l = mid;
      else r = mid-1;
    }
    j = l;
    i = j-1;
    k = j+check(all)-1;
  } else {
    while (l < r) {
      mid = (l+r+1)/2;
      if (~check(query(1, mid))) l = mid;
      else r = mid-1;
    }
    ll rev = query(1, l);
    j = l;
    i = j-check(rev);
    k = j+check(all-rev)-1;
  }
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