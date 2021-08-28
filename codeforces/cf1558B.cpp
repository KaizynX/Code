/*
 * @Author: Kaizyn
 * @Date: 2021-08-24 22:14:08
 * @LastEditTime: 2021-08-24 23:15:18
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
// const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 4e6+7;

int n, P;
int f[N], g[N], s[N];

int brute(int n) {
  memset(f+1, 0, sizeof(int)*n);
  f[n] = 1;
  for (int i = n; i; --i) {
    for (int j = 1; j < i; ++j) (f[j] += f[i]) %= P;
    for (int j = 2; j <= i; ++j) (f[i/j] += f[i]) %= P;
  }
  return f[1];
}

void guess() {
  s[1] = g[1] = 1;
  for (int i = 2, j; i <= n; ++i) {
    g[i] = 0;
    // for (int j = 2; j <= i; ++j) (g[i] += g[i/j]) %= MOD;
    for (j = 1; j*j <= i; ++j) {
      (g[i] += g[i/j]) %= P;
      if (i/j != j) (g[i] += 1ll*(i/j-i/(j+1))*g[j]) %= P;
    }
    // for (j = 1; j < i; ++j) (g[i] += g[j]) %= MOD;
    (g[i] += s[i-1]) %= P;
    s[i] = (s[i-1]+g[i])%P;
    // cout << g[i] << " \n"[i==n];
  }
}

inline void solve() {
  cin >> n >> P;
  // for (int i = 2; i <= n; ++i) cout << brute(i) << " \n"[i==n];
  guess();
  cout << g[n] << '\n';
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