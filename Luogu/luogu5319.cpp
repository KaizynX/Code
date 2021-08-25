/*
 * @Author: Kaizyn
 * @Date: 2021-08-25 15:15:38
 * @LastEditTime: 2021-08-25 16:34:08
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
const int N = 15e2+7;
const int M = N<<1;

int n, m;
int ed[N];
double v[N], dp[N][M];
string T, S;

template <typename T>
void update(T &x, T y) {
  if (y > x) x = y;
}

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
  bool check(double mid) {
    memset(val, 0, sizeof(double)*sz);
    for (int i = 1; i <= m; ++i) val[ed[i]] = v[i]-mid;
    for (int _ = 1, i, j; _ < sz; ++_) {
      i = rk[_];
      j = link[i];
      val[i] += val[j];
    }
    fill(dp[0], dp[0]+N*M, -100.0);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < sz; ++j) if (dp[i][j] > -100.0) {
        if (T[i] == '.') for (int k = 0; k < A; ++k) {
          update(dp[i+1][nex[j][k]], dp[i][j]+val[nex[j][k]]);
        } else {
          update(dp[i+1][nex[j][T[i]-C]], dp[i][j]+val[nex[j][T[i]-C]]);
        }
      }
    }
    #ifdef DEBUG
    // orz(mid);
    // orzarr(val, sz);
    // for (int i = 1; i <= n; ++i) orzarr(dp[i], sz);
    // orz(*max_element(dp[n], dp[n]+sz));
    #endif
    return *max_element(dp[n], dp[n]+sz) > 0;
  }
  string print() {
    #ifdef DEBUG
    orzarr(val, sz);
    for (int i = 0; i < sz; ++i) orzarr(nex[i], A);
    for (int i = 1; i <= n; ++i) orzarr(dp[i], sz);
    #endif
    int u = max_element(dp[n], dp[n]+sz)-dp[n];
    string ans;
    for (int i = n-1, from; i >= 0; --i, u = from) {
      #ifdef DEBUG
      printf("dp[%d][%d]=%g\n", i+1, u, dp[i+1][u]);
      #endif
      from = -1;
      for (int j = 0; j < sz && from == -1; ++j) if (dp[i][j] > -100.0) {
        if (T[i] == '.') for (int k = 0; k < A; ++k) {
          if (nex[j][k] != u) continue;
          if (cmp(dp[i+1][u], dp[i][j]+val[u])) {
            from = j;
            ans += C+k;
            break;
          }
        } else if (nex[j][T[i]-C]) {
          if (cmp(dp[i+1][u], dp[i][j]+val[u])) {
            from = j;
            ans += T[i];
          }
        }
      }
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
  for (int i = 1, val; i <= m; ++i) {
    cin >> S >> val;
    v[i] = log(val);
    ed[i] = gsam.insert(S);
  }
  gsam.build();
  double l = 0, r = log(1e9)+eps, mid;
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