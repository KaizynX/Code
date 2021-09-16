/*
 * @Author: Kaizyn
 * @Date: 2021-09-04 13:53:16
 * @LastEditTime: 2021-09-04 14:49:19
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
const int K = 1e7+7;

int n, q;
pii ans[K];

struct generalSAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, len[M], link[M], nex[M][A], cnt[M], vis[M], th;
  generalSAM() { init(); }
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    memset(cnt, 0, sizeof(int)*sz);
    memset(vis, 0, sizeof(int)*sz);
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
  void insert2(const string &s) {
    memset(vis, 0, sizeof(int)*sz);
    for (int i = 0, last = 0; i < (int)s.size(); ++i) {
      last = nex[last][s[i]-C];
      // vis[last] = i+1;
      for (int j = last; j && !vis[j]; j = link[j]) {
        vis[j] = i+1;
      }
    }
  }
  void insert(const string &s, int id) {
    int last = 0;
    for (char ch : s) {
      last = nex[last][ch-C];
      for (int i = last; i && vis[i] != id; i = link[i]) {
        vis[i] = id;
        ++cnt[i];
      }
    }
  }
  void dfs(int u, int len) {
    if (++th > 10000000) return;
    ans[th] = pii{vis[u]-len, vis[u]};
    for (int i = 0; i < A; ++i) if (cnt[nex[u][i]] == n) {
      dfs(nex[u][i], len+1);
    }
  }
  void build() { // topo on parent tree
    /*
    static int t[M], rk[M];
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      // if (cnt[i] < n) continue;
      // assert(vis[i]);
      if (vis[i]) vis[j] = vis[j] ? min(vis[j], vis[i]) : vis[i];
    }
    */
    th = 0;
    vis[0] = 0;
    cnt[0] = 0;
    for (int i = 0; i < A; ++i) if (cnt[nex[0][i]] == n) dfs(nex[0][i], 1);
  }
};

string s[N];
generalSAM gsam;

inline void solve() {
  gsam.init();
  cin >> n;
  for (int i = 1; i<= n; ++i) {
    cin >> s[i];
    gsam.insert(s[i]);
  }
  for (int i = 1; i <= n; ++i) {
    gsam.insert(s[i], i);
  }
  gsam.insert2(s[1]);
  gsam.build();
  cin >> q;
  for (int i = 1, k; i <= q; ++i) {
    cin >> k;
    if (k > gsam.th) {
      cout << "-1\n";
    } else {
      cout << ans[k].first << ' ' << ans[k].second << '\n';
    }
  }
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