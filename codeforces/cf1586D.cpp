/*
 * @Author: Kaizyn
 * @Date: 2021-11-13 10:56:05
 * @LastEditTime: 2021-11-13 11:04:11
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
const int N = 1e2+7;

int n;
int a[N];
int ans[N];

int query() {
  cout << '?';
  for (int i = 1; i <= n; ++i) cout << ' ' << a[i];
  cout << endl;
  int k;
  cin >> k;
  return k;
}

inline void solve() {
  cin >> n;
  fill(a+1, a+n+1, 1);
  ans[n] = 1;
  for (int i = 1; i < n; ++i) {
    ++a[n];
    int k = query();
    if (!k) {
      ans[n] = n-i+1;
      break;
    }
    ans[k] = i;
  }
  fill(a+1, a+n+1, n);
  for (int i = 1; i < n; ++i) {
    --a[n];
    int k = query();
    if (!k) {
      break;
    }
    ans[k] = -i;
  }
  for (int i = 1; i < n; ++i) {
    ans[i] += ans[n];
  }
  cout << '!';
  for (int i = 1; i <= n; ++i) cout << ' ' << ans[i];
  cout << endl;
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