/*
 * @Author: Kaizyn
 * @Date: 2021-09-18 15:51:09
 * @LastEditTime: 2021-09-18 15:55:52
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
const int N = 5e2+7;

int n, m, k;
int a[N][N];
vector<int> v;

inline void solve() {
  priority_queue<int, vector<int>, greater<int>> q;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  ll cur = 0, ans = 0;
  v.clear();
  for (int i = 1, l, r; i <= n; ++i) {
    cin >> l >> r;
    sort(a[i]+1, a[i]+m+1);
    reverse(a[i]+1, a[i]+m+1);
    for (int j = 1; j <= l; ++j) {
      cur += 2*a[i][j];
      q.push(a[i][j]);
      if ((int)q.size() > k) cur -= q.top(), q.pop();
    }
    for (int j = l+1; j <= r; ++j) v.emplace_back(a[i][j]);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ans = cur;
  for (int x : v) {
    cur += 2*x;
    q.push(x);
    if ((int)q.size() > k) cur -= q.top(), q.pop();
    ans ^= cur;
  }
  cout << ans << '\n';
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