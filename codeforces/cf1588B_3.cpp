/*
 * @Author: Kaizyn
 * @Date: 2021-11-22 23:31:58
 * @LastEditTime: 2021-11-23 09:45:50
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
// const int N = ;

// 二分找到一个有值的地方
// 向左向右试探得到其中一个边界
// 继续二分得到中间分界
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
  ll all = query(1, n), x, y;
  int l = 1, r = n, mid, i = -1, j = -1, k = -1;
  while (l < r) {
    mid = (l+r+1)/2;
    x = query(mid, n);
    if (x == 0) {
      r = mid-1;
      continue;
    } else if (x == all) {
      l = mid;
      continue;
    }
    y = check(x);
    if (~y && query(mid+y-1, n) == 0) {
      k = mid+y-1;
      if (query(k-1, n) == 0) --k;
      r = mid;
    } else { // wrong
      y = check(all-x);
      i = mid-y+1;
      l = mid+1;
    }
    break;
  }
  if (~i) while (l < r) {
    mid = (l+r+1)/2;
    x = query(mid, n);
    if (x == (mid-i)*(mid-i-1ll)/2) l = mid;
    else r = mid-1;
  }
  else while (l < r) {
    mid = (l+r)/2;
    x = query(mid, n);
    if (x == (k-mid+1ll)*(k-mid)/2) r = mid;
    else l = mid+1;
  }
  j = l;
  if (i == -1) i = j-check(query(1, j));
  if (k == -1) k = j+check(query(j, n))-1;
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
/*
4637829 3424 3426 3427

1000000000 1 3 1000000000

1000000000 1 999999999 1000000000
*/