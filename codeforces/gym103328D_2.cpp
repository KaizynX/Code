/*
 * @Author: Kaizyn
 * @Date: 2021-11-03 14:16:53
 * @LastEditTime: 2021-11-03 14:22:49
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
const int N = 6e5+7;
const int SZ = 26;

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

int n, m;
string s, t;
int ans[N], pid[N], qid[N], L[N], R[N], dfn;
vector<int> e[N], q[N], fe[N];
int nex[N][SZ], fail[N], cnt;
BinaryIndexedTree<int> tree;

int ac_insert(const string &s) {
  int p = 0, c;
  for (char ch : s) {
    c = ch-'a';
    if (!nex[p][c]) nex[p][c] = ++cnt;
    p = nex[p][c];
  }
  return p;
}

void ac_build() {
  static queue<int> q;
  for (int i = 0; i < SZ; ++i) if (nex[0][i]) q.push(nex[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    fe[fail[u]].emplace_back(u);
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

void get_dfn(int u = 0) {
  L[u] = ++dfn;
  for (int v : fe[u]) get_dfn(v);
  R[u] = dfn;
}

void dfs(int u = 1, int fa = 0, int p = 0) {
  p = nex[p][s[u-1]-'a'];
  tree.add(L[p], 1);
  for (int i : q[u]) {
    ans[i] = tree.query(L[qid[i]], R[qid[i]]);
  }
  for (int v : e[u]) if (v != fa) {
    dfs(v, u, p);
  }
  tree.add(L[p], -1);
}

inline void solve() {
  cin >> n >> s;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  cin >> m;
  for (int i = 1, u; i <= m; ++i) {
    cin >> u >> t;
    qid[i] = ac_insert(t);
    q[u].emplace_back(i);
  }
  ac_build();
  get_dfn();
  tree.init(dfn);
  dfs();
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << '\n';
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
  }
  return 0;
}