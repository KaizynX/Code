/*
 * @Author: Kaizyn
 * @Date: 2021-08-28 13:05:51
 * @LastEditTime: 2021-08-28 13:43:51
 */
#include <bits/stdc++.h>

// #define DEBUG

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
const int N = 2e6+7;
typedef unsigned long long ull;

int n, m;
int p[N], vis[N];
ull f[N];
int q[N], head, tail;

void print() {
  #ifdef DEBUG
  orzarr(f+1, n);
  #endif
  ull ans = 0, base = 1;
  for (int i = n; i; --i, base *= 23333) {
    ans += f[i]*base;
  }
  cout << ans << '\n';
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> p[i];
  ll lim = 1;
  memset(f+1, 0, sizeof(ull)*n);
  memset(vis+1, 0, sizeof(int)*n);
  vis[0] = *max_element(p+1, p+m+1);
  for (int i = 1; i <= m; ++i) {
    if (lim <= n) lim *= p[i];
    for (int j = p[i]; j <= n; j += p[i]) {
      vis[j] = max(vis[j], p[i]);
    }
  }
  lim = min(n*1ll, lim-1);
  head = tail = 0;
  q[tail++] = 0;
  for (int i = 1; i <= lim; ++i) {
    while (head < tail && q[head]+vis[q[head]] <= i) ++head;
    f[i] = f[q[head]]+1;
    if (!vis[i]) continue;
    while (head < tail && f[q[tail-1]] > f[i]) --tail;
    q[tail++] = i;
  }
  print();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}