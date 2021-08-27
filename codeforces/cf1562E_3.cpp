/*
 * @Author: Kaizyn
 * @Date: 2021-08-27 00:34:48
 * @LastEditTime: 2021-08-27 08:59:46
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
const int N = 5e3+7;

int n;
char s[N];
int dp[N][N];

template <typename T>
void update(T &x, T y) {
  if (x < y) x = y;
}

struct TireTree {
  static const int NN = 125e5+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], val[NN], mxv[NN], cnt;
  TireTree(char _beg = 'a') : beg(_beg) { clear(); }
  void clear() {
    memset(nex, 0, sizeof(int)*(cnt+1)*SZ);
    memset(val, 0, sizeof(int)*(cnt+1));
    memset(mxv, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(int st) {
    int p = 0, i, mx = 0, c;
    for (i = st; i <= n; ++i) {
      c = s[i]-beg;
      for (int j = 0; j < c; ++j) if (nex[p][j]) {
        update(mx, mxv[nex[p][j]]);
      }
      if (!nex[p][c]) break;
      p = nex[p][c];
      dp[st][i] = max(val[p], ++mx);
    }
    for (; i <= n; ++i) dp[st][i] = ++mx;
    p = 0;
    mx = *max_element(dp[st]+st, dp[st]+n+1);
    for (i = st; i <= n; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
      update(val[p], dp[st][i]);
      update(mxv[p], mx);
    }
  }
} tree;

inline void solve() {
  tree.clear();
  cin >> n >> (s+1);
  for (int i = 1; i <= n; ++i) {
    tree.insert(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    #ifdef DEBUG
    orzarr(dp[i]+1, n);
    #endif
    update(ans, *max_element(dp[i]+i, dp[i]+n+1));
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