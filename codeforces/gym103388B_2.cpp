/*
 * @Author: Kaizyn
 * @Date: 2021-11-06 15:32:22
 * @LastEditTime: 2021-11-06 16:43:20
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
const int N = 2e5+7;

int n, m;
int base[3], ans[N];
string s, t;
set<pii> st[3];
// 0 ++, 1 --, 2 equal
vector<pii> add[3][N];

void giao(int i, int j) {
  // assert(j <= i+1);
  #ifdef DEBUG
  cout << pii{i,j} << '\n';
  #endif
  if (!j) return;
  if (j > n) j = n;
  add[2][max(0, i-n+1)].emplace_back(j, i-j+1);
  add[1][i-j+1].emplace_back(j, i);
  add[0][i-j+1].emplace_back(0, i);
  #ifdef DEBUG
  printf("add[%d][%d](%d,%d)\n", 2, max(0, i-n+1), j, i-j+1);
  printf("add[%d][%d](%d,%d)\n", 1, i-j+1, j, i);
  printf("add[%d][%d](%d,%d)\n", 0, i-j+1, 0, i);
  #endif
  /*
  if (j >= n) {
    add[2][i-j+1].emplace_back(n, i-n+1);
    add[2][i-j+n].emplace_back(n, i);
    add[1][i-n+1].emplace_back(n, i);
    add[0][i-j+1].emplace_back(1, i-j+n);
  } else {
    add[2][max(0, i-n+1)].emplace_back(j, i-j+1);
    add[1][i-j+1].emplace_back(j, i);
    add[0][i-j+1].emplace_back(1, i);
  }
  */
}

struct generalSAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, len[M], link[M], nex[M][A];
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
  void insert(const string &s) {
    int last = 0; for (char ch : s) last = extend(last, ch-C);
  }
  void fuck(const string &s) {
    for (int i = 0, u = 0, l = 0, c; i < (int)s.size(); ++i) {
      c = s[i]-C;
      while (u && !nex[u][c]) l = len[u = link[u]];
      if (nex[u][c]) u = nex[u][c], ++l;
      giao(i, l);
    }
  }
} gsam;

inline void solve() {
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    cin >> t;
    gsam.insert(t);
  }
  gsam.fuck(s+s);
  for (int i : {0, 1, 2}) {
    base[i] = 0;
    st[i].clear();
    st[i].insert({-INF, 2*n});
  }
  for (int i = 0; i < 2*n; ++i, ++base[0], --base[1]) {
    #ifdef DEBUG
    cout << i << "--------------\n";
    #endif
    for (int j : {0, 1, 2}) {
      for (pii p : add[j][i]) {
        st[j].insert({p.first-base[j], p.second});
        #ifdef DEBUG
        cout << p << ' ';
        #endif
      }
      while (st[j].rbegin()->second < i) st[j].erase(--st[j].end());
      ans[i%n] = max(ans[i%n], st[j].rbegin()->first+base[j]);
      #ifdef DEBUG
      orz(base[j]);
      cout << *st[j].rbegin() << ' ';
      orz(ans[i%n]);
      #endif
    }
  }
  #ifdef DEBUG
  orzarr(ans, n);
  #endif
  cout << *min_element(ans, ans+n) << '\n';
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