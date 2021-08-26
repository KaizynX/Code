/*
 * @Author: Kaizyn
 * @Date: 2021-08-25 17:04:27
 * @LastEditTime: 2021-08-26 14:44:11
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
const double eps = 1e-6;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 15e2+7;

int n, m;
int ed[N];
char S[N], T[N];
pii path[N][N];
double v[N], dp[N][N];

struct Aho_Corasick_Automaton {
  static const int NN = N;
  static const int SZ = 10;
  static const char beg = '0';
  int nex[NN][SZ], fail[NN], cnt;
  double val[NN];
  vector<int> topo;
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    // memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  int insert(const char *s) {
    int p = 0;
    for (int i = 0, c; s[i]; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    return p;
  }
  void build() {
    static queue<int> q;
    for (int i = 0; i < SZ; ++i) if (nex[0][i]) q.push(nex[0][i]);
    while (q.size()) {
      int u = q.front();
      topo.emplace_back(u);
      q.pop();
      for (int i = 0; i < SZ; ++i) {
        if (nex[u][i]) {
          fail[nex[u][i]] = nex[fail[u]][i];
          q.push(nex[u][i]);
        } else {
          nex[u][i] = nex[fail[u]][i];
        }
      }
    }
  }
  void update(int i, int j, int k) {
    int nj = nex[j][k];
    double nv = dp[i][j]+val[nj];
    if (nv > dp[i+1][nj]) {
      dp[i+1][nj] = nv;
      // path[i+1][nj] = pii{j, k};
      path[i+1][nj].first = j;
      path[i+1][nj].second = k;
    }
  }
  bool check(double mid) {
    memset(val, 0, sizeof(double)*(cnt+1));
    for (int i = 1; i <= m; ++i) val[ed[i]] = v[i]-mid;
    for (int i : topo) val[i] += val[fail[i]];
    for (int i = 0; i <= n; ++i) fill(dp[i], dp[i]+cnt+1, -1e9);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= cnt; ++j) if (dp[i][j] > -1e9) {
        if (T[i] == '.') for (int k = 0; k < SZ; ++k) {
          update(i, j, k);
        } else {
          update(i, j, T[i]-beg);
        }
      }
    }
    return *max_element(dp[n], dp[n]+cnt+1) > 0;
  }
  string print() {
    #ifdef DEBUG
    orzarr(val, cnt+1);
    for (int i = 0; i <= cnt; ++i) orzarr(nex[i], SZ);
    for (int i = 1; i <= n; ++i) orzarr(dp[i], cnt+1);
    orz(*max_element(dp[n], dp[n]+cnt+1));
    #endif
    string ans;
    for (int i = n, j = max_element(dp[n], dp[n]+cnt+1)-dp[n]; i; --i) {
      ans += path[i][j].second+beg;
      j = path[i][j].first;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
} ac;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  scanf("%d%d%s", &n, &m, T);
  double l = 0, r = 0, mid;
  for (int i = 1, val; i <= m; ++i) {
    scanf("%s%d", S, &val);
    v[i] = log(val);
    r = max(r, v[i]);
    ed[i] = ac.insert(S);
  }
  ac.build();
  while (r-l > eps) {
    mid = (l+r)/2;
    if (ac.check(mid)) l = mid;
    else r = mid;
  }
  ac.check(l);
  cout << ac.print() << '\n';
  return 0;
}
/*
ln(2) = 0.6931718
(ln(2)+ln(3)+ln(4))/3 = 1.05935127678
*/