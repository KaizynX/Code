/*
 * @Author: Kaizyn
 * @Date: 2021-11-12 20:46:49
 * @LastEditTime: 2021-11-12 21:03:53
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
const int N = 1e6+7;
const int dir[] = {0,-1,0,1,0};

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, m, q;
int ans[N], sum[N], suf[N];
string a[N];
vector<pii> qq[N];
vector<int> dp[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    dp[i] = vector<int>(m, 0);
    for (int j = 1; j <= m; ++j) {
      sum[j] += a[i][j] == '.';
    }
  }
  for (int i = 1; i <= m; ++i) sum[i] += sum[i-1];
  cin >> q;
  for (int i = 1, l, r; i <= q; ++i) {
    cin >> l >> r;
    qq[l].emplace_back(r, i);
  }
  suf[m] = 0;
  for (int i = m, last = m; i; --i) {
    if (a[0][i-1] == 'X') last = i-1;
    int col = 0;
    for (int j = n, cnt; j; --j) {
      if (a[j-1][i-1] == 'X') {
        cnt = 0;
        continue;
      }
      dp[j-1][i-1] = ++cnt;
      if (i+1 <= m) dp[j-1][i-1] += dp[j-1][i];
      if (j == 1 || a[j-2][i-1] == 'X') col += dp[j-1][i-1];
    }
    #ifdef DEBUG
    for (int j = 0; j < n; ++j) cout << dp[j][i-1] << ' ';
    orz(i);
    #endif
    suf[i-1] = suf[i]+dp[0][i];
    for (auto p : qq[i]) {
      int l = i, r = p.first, id = p.second;
      int cur = col+max(0, suf[r-1]-suf[last]);
      #ifdef DEBUG
      orz(p);
      orz(cur);
      #endif
      ans[id] = sum[r]-sum[l-1] == cur;
    }
  }
  for (int i = 1; i <= q; ++i) {
    cout << (ans[i] ? "YES" : "NO") << '\n';
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
    for (int i = 1; i <= m; ++i) qq[i].clear();
  }
  return 0;
}