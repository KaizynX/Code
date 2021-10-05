/*
 * @Author: Kaizyn
 * @Date: 2021-10-05 12:13:33
 * @LastEditTime: 2021-10-05 12:15:38
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
const int N = 1e5+7;

int n, k;
int s[N], c[N];
double v[N];

bool check(double mid) {
  double sum = 0;
  for (int i = 1; i <= n; ++i) {
    v[i] = s[i]*(c[i]-mid);
  }
  nth_element(v+1, v+k+1, v+n+1);
  for (int i = k+1; i <= n; ++i) sum += v[i];
  return sum > -eps;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];
  double l = 0, r = 1e8, mid;
  while (r-l > eps) {
    mid = (l+r)/2;
    if (check(mid)) l = mid;
    else r = mid;
  }
  printf("%.11f\n", (l+r)/2);
  // cout << (l+r)/2 << '\n';
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