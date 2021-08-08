/*
 * @Author: Kaizyn
 * @Date: 2021-08-08 19:11:08
 * @LastEditTime: 2021-08-08 21:00:57
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;

struct generalSAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, len[M], link[M], nex[M][A];
  int cnt[M];
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
    int last = 0; for (char ch : s) ++cnt[last = extend(last, ch-C)];
  }
  void build() { // topo on parent tree
    static int t[M], rk[M];
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      cnt[j] += cnt[i];
    }
  }
  ll cyclic_query(const string &s) { // 循环同构
    static int id = 0, vis[M];
    ++id;
    ll res = 0;
    for (int i = 0, c, m = s.size(), u = 0, l = 0; i < m*2-1; ++i) {
      c = s[i%m]-C;
      while (u && !nex[u][c]) l = len[u = link[u]];
      if (nex[u][c]) u = nex[u][c], ++l;
      if (l > m && --l == len[link[u]]) u = link[u];
      if (l == m && vis[u] != id) res += cnt[u], vis[u] = id; 
    }
    return res;
  }
};

int n;
string s;
generalSAM gsam;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> s >> n;
  gsam.insert(s);
  gsam.build();
  for (int _ = n; _; --_) {
    cin >> s;
    cout << gsam.cyclic_query(s) << '\n';
  }
  return 0;
}