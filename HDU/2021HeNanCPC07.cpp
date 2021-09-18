/*
 * @Author: Kaizyn
 * @Date: 2021-09-17 11:38:13
 * @LastEditTime: 2021-09-18 14:15:40
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
const int N = 1e3+7;
const int M = 1e6+7;

int n, m;
int a[N][N], f[N][N];
int b[N<<1], g[N<<1], cnt[M];

void extend(int &r) {
  while (r < m && !cnt[b[r+1]]) ++cnt[b[++r]];
}

void shrink(int &l) {
  while (--cnt[b[l++]] != 1) {}
}

int calc(int k, int l, int r) {
  if (k < l || k > r) return 0;
  return min(k-l, r-k)+1;
}

void giao() {
  #ifdef DEBUG
  orzarr(b+1, m);
  #endif
  int l1, r1, l2 = 1, r2 = 0, k = 1;
  extend(r2);
  while (r2 < m) {
    l1 = l2; r1 = r2;
    ++cnt[b[++r2]];
    shrink(l2);
    extend(r2);
    while (k <= n && calc(k, l1, r1) >= calc(k, l2, r2)) {
      g[k] = calc(k, l1, r1);
      ++k;
    }
  }
  while (k <= n) g[k] = calc(k, l2, r2), ++k;
  for (int i = 1; i <= m; ++i) cnt[b[i]] = 0;
  #ifdef DEBUG
  orzarr(g+1, m);
  #endif
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      f[i][j] = n;
    }
  }
  for (int s = 2; s <= n+n; ++s) {
    #ifdef DEBUG
    orz(s);
    #endif
    m = 0;
    for (int i = 1, j; i <= n; ++i) {
      j = s-i;
      if (j < 1 || j > n) continue;
      b[++m] = a[i][j];
    }
    giao();
    m = 0;
    for (int i = 1, j; i <= n; ++i) {
      j = s-i;
      if (j < 1 || j > n) continue;
      f[i][j] = min(f[i][j], g[++m]);
    }
  }
  for (int d = 1-n; d <= n-1; ++d) {
    #ifdef DEBUG
    orz(d);
    #endif
    m = 0;
    for (int i = 1, j; i <= n; ++i) {
      j = i+d;
      if (j < 1 || j > n) continue;
      b[++m] = a[i][j];
    }
    giao();
    m = 0;
    for (int i = 1, j; i <= n; ++i) {
      j = i+d;
      if (j < 1 || j > n) continue;
      f[i][j] = min(f[i][j], g[++m]);
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << f[i][j] << " \n"[j==n];
    }
  }
  #endif
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans += f[i][j];
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