/*
 * @Author: Kaizyn
 * @Date: 2021-08-25 16:40:53
 * @LastEditTime: 2021-08-25 17:06:13
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
const int N = 15e2+7;
const int M = N<<1;

int n, m;
int ed[N];
pii path[N][M];
double v[N], dp[N][M];
string T, S;

inline bool cmp(const double &x, const double &y) {
  return abs(x-y) < eps;
}

struct generalSAM {
  static const int A = 10;
  // static const int M = N<<1;
  static const char C = '0';
  int sz, len[M], link[M], nex[M][A];
  int t[M], rk[M];
  double val[M];
  generalSAM() { init(); }
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    link[0] = -1; sz = 1;
  }
  int extend(int last, int c) {
    if (nex[last][c]) {
      int p = last, cur = nex[p][c];
      if (len[p]+1 == len[cur]) return cur;
      int q = sz++;
      len[q] = len[p]+1;
      memcpy(nex[q], nex[cur], sizeof nex[q]);
      for ( ; ~p && nex[p][c] == cur; p = link[p]) nex[p][c] = q;
      link[q] = link[cur];
      link[cur] = q;
      return q;
    }
    int cur = sz++, p = last;
    len[cur] = len[p]+1;
    for ( ; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    len[clone] = len[p]+1;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[clone] = link[q];
    link[q] = link[cur] = clone;
    return cur;
  }
  int insert(const string &s) {
    int last = 0; for (char ch : s) last = extend(last, ch-C);
    return last;
  }
  void build() { // topo on parent tree
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = 1, i, j; _ < sz; ++_) {
      i = rk[_];
      j = link[i];
      for (int k = 0; k < A; ++k) {
        if (nex[i][k]) continue;
        nex[i][k] = nex[j][k];
      }
    }
  }
  void update(int i, int j, int k) {
    int nj = nex[j][k];
    double nv = dp[i][j]+val[nj];
    if (nv > dp[i+1][nj]) {
      dp[i+1][nj] = nv;
      path[i+1][nj] = pii{j, k};
    }
  }
  bool check(double mid) {
    memset(val, 0, sizeof(double)*sz);
    for (int i = 1; i <= m; ++i) val[ed[i]] = v[i]-mid;
    for (int _ = 1, i, j; _ < sz; ++_) {
      i = rk[_];
      j = link[i];
      val[i] += val[j];
    }
    fill(dp[0], dp[0]+N*M, -1e9);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < sz; ++j) if (dp[i][j] > -1e9) {
        if (T[i] == '.') for (int k = 0; k < A; ++k) {
          update(i, j, k);
        } else {
          update(i, j, T[i]-C);
        }
      }
    }
    return *max_element(dp[n], dp[n]+sz) > 0;
  }
  string print() {
    #ifdef DEBUG
    orzarr(val, sz);
    for (int i = 0; i < sz; ++i) orzarr(nex[i], A);
    for (int i = 1; i <= n; ++i) orzarr(dp[i], sz);
    #endif
    string ans;
    for (int i = n, j = max_element(dp[n], dp[n]+sz)-dp[n]; i; --i) {
      ans += path[i][j].second+C;
      j = path[i][j].first;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
} gsam;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> m >> T;
  double l = 0, r = 0, mid;
  for (int i = 1, val; i <= m; ++i) {
    cin >> S >> val;
    v[i] = log(val);
    r = max(r, v[i]);
    ed[i] = gsam.insert(S);
  }
  gsam.build();
  while (r-l > eps) {
    mid = (l+r)/2;
    if (gsam.check(mid)) l = mid;
    else r = mid;
  }
  gsam.check(l);
  cout << gsam.print() << '\n';
  return 0;
}
/*
ln(2) = 0.6931718
(ln(2)+ln(3)+ln(4))/3 = 1.05935127678
*/