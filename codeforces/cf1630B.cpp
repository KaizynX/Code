/*
 * @Author: Kaizyn
 * @Date: 2022-01-27 22:33:29
 * @LastEditTime: 2022-01-28 00:00:13
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
const int N = 2e5 + 7;

int n, k, m;
int a[N], t[N];

bool check(int x) {
  for (int i = 0; i + x <= n; ++i) {
    if (t[i + x] - t[i] >= m) return true;
  }
  return false;
}

inline void solve() {
  cin >> n >> k;
  m = k + (n - k + 1) / 2;
  memset(t + 1, 0, sizeof(int) * n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++t[a[i]];
  }
  for (int i = 1; i <= n; ++i) t[i] += t[i - 1];
  int l = 1, r = n, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  for (int i = 0; i < n; ++i) {
    if (t[i + l] - t[i] >= m) {
      r = i + l;
      l = i + 1;
      break;
    }
  }
  cout << l << ' ' << r << '\n';
  for (int i = 1, j = 0, cur = 0, last = 1; i <= n; ++i) {
    if (a[i] >= l && a[i] <= r) ++cur;
    else --cur;
    if (cur > 0) {
      if (++j == k) i = n;
      cout << last << ' ' << i << '\n';
      last = i + 1;
      cur = 0;
    }
  }
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