/*
 * @Author: Kaizyn
 * @Date: 2021-09-30 18:01:41
 * @LastEditTime: 2021-09-30 18:54:30
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
const int N = 4e2+7;

int n, m;
char a[N][N];
int s[N][N], v0[N], v1[N], vs[N], vb[N];
int q[N], head, tail;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i]+1);
    for (int j = 1; j <= m; ++j) {
      s[i][j] = s[i][j-1]+(a[i][j]=='1');
    }
  }
  int ans = n*m;
  for (int l = 1; l <= m; ++l) {
    for (int r = l+3; r <= m; ++r) {
      head = tail = 0;
      int len = r-l-1;
      for (int i = 1; i <= n; ++i) {
        v1[i] = s[i][r-1]-s[i][l];
        v0[i] = len-v1[i];
        vb[i] = vb[i-1]+v1[i]+(a[i][l] == '0')+(a[i][r] == '0');
        vs[i] = vb[i-1]+v0[i];
        // vs[i] = vs[i-1]-v0[i-1]+v1[i-1]+(a[i-1][l] == '0')+(a[i-1][r] == '0')+v0[i];
        while (head < tail && vs[q[tail-1]] >= vs[i]) --tail; 
        q[tail++] = i;
      }
      #ifdef DEBUG
      orzarr(vs+1, n);
      #endif
      for (int i = 1; i <= n; ++i) {
        while (head < tail && q[head] < i+4) ++head;
        if (head < tail) ans = min(ans,
            vs[q[head]]-vb[i]+v0[i]);
      }
    }
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