/*
 * @Author: Kaizyn
 * @Date: 2022-04-03 12:54:38
 * @LastEditTime: 2022-04-03 12:57:44
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
const int N = 1e4 + 7;

set<pii> ban;
int n;
int a[N];
ll sum[N];

ll query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  ll x;
  cin >> x >> l >> r;
  ban.insert({l, r});
  return x;
}

inline void solve() {
  ban.clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j; --j) {
      if (ban.count({j, i})) continue;
      ll val = query(j, i);
      a[i] = val - (sum[i - 1] - sum[j - 1]);
      break;
    }
    sum[i] = sum[i - 1] + a[i];
  }
  cout << "!\n";
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " \n"[i == n];
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