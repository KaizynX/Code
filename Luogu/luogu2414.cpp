/*
 * @Author: Kaizyn
 * @Date: 2021-09-22 18:54:51
 * @LastEditTime: 2021-09-26 16:26:33
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
const int N = 1e5+7;
const int A = 26;

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

int m;
string s;
int res[N], pos[N];
vector<pii> q[N];
vector<int> stk, e[N];
int nex[N][A], fail[N], cnt;
int L[N], R[N], dfn;
BinaryIndexedTree<int> tree;

void build() {
  static queue<int> q;
  for (int i = 0; i < A; ++i) if (nex[0][i]) q.push(nex[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    e[fail[u]].emplace_back(u);
    for (int i = 0; i < A; ++i) {
      if (nex[u][i]) {
        fail[nex[u][i]] = nex[fail[u]][i];
        q.push(nex[u][i]);
      } else {
        nex[u][i] = nex[fail[u]][i];
      }
    }
  }
}

void dfs(int u = 0) {
  L[u] = ++dfn;
  for (int v : e[u]) dfs(v);
  R[u] = dfn;
}

inline void solve() {
  cin >> s >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    q[y].emplace_back(i, x);
  }
  int id = 0;
  stk = vector<int>(1, 0);
  for (char ch : s) {
    if (ch == 'B') {
      if (stk.size() > 1u) stk.pop_back();
    } else if (ch == 'P') {
      pos[++id] = stk.back();
    } else {
      int c = ch-'a', p = stk.back();
      if (!nex[p][c]) nex[p][c] = ++cnt;
      stk.emplace_back(nex[p][c]);
    }
  }
  build();
  dfs();
  id = 0;
  tree.init(dfn);
  stk = vector<int>(1, 0);
  for (char ch : s) {
    if (ch == 'B') {
      if (stk.size() <= 1u) continue;
      tree.add(L[stk.back()], -1);
      stk.pop_back();
    } else if (ch == 'P') {
      ++id;
      for (auto pr : q[id]) {
        int th = pr.first, x = pr.second;
        res[th] = tree.query(L[pos[x]], R[pos[x]]);
      }
    } else {
      int c = ch-'a', p = stk.back();
      stk.emplace_back(p = nex[p][c]);
      tree.add(L[p], 1);
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << res[i] << '\n';
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