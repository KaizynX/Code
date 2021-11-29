/*
 * @Author: Kaizyn
 * @Date: 2021-11-27 20:26:09
 * @LastEditTime: 2021-11-27 20:59:31
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

int n, sum[N];
ll k;
string s;
vector<int> p;

inline void solve() {
  cin >> s >> k;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'Y') p.emplace_back(i+1);
    sum[i+1] = sum[i]+(s[i]=='.');
  }
  n = p.size();
  int ans = 0;
  ll cur = 0;
  for (int l = 0, r = 0, mid = 0; l < n; ++l) {
    if (l > r) r = mid = l;
    // [p[l], p[mid]], (p[mid], p[r]]
    while (r+1 < n) {
      ll tmp = cur+sum[p[r+1]]-sum[p[mid]];
      if (r-mid > mid-l) tmp -= sum[p[mid+1]]-sum[p[mid]];
      if (tmp > k) break;
      if (r-mid > mid-l) ++mid;
      cur = tmp;
      ++r;
    }
    ans = max(ans, r-l+1);
    #ifdef DEBUG
    cout << l << ' ' << r << ' ' << cur << '\n';
    #endif
    if ((r-l)&1) ++mid;
    cur -= sum[p[mid]]-sum[p[l]];
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