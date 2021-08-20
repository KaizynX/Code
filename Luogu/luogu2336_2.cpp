/*
 * @Author: Kaizyn
 * @Date: 2021-08-20 17:43:17
 * @LastEditTime: 2021-08-20 17:47:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

struct generalSAM {
  static const int M = N<<1;
  int sz, len[M], link[M], vis[M], cnt[M], cnt2[M];
  int t[M], rk[M];
  map<int, int> nex[M];
  generalSAM() { init(); }
  void init() {
    for (int i = 0; i < sz; ++i) nex[i].clear();
    link[0] = -1; sz = 1;
  }
  int extend(int last, int c) {
    if (nex[last].count(c)) {
      int p = last, cur = nex[p][c];
      if (len[p]+1 == len[cur]) return cur;
      int q = sz++;
      len[q] = len[p]+1;
      nex[q] = nex[cur];
      for ( ; ~p && nex[p].count(c) && nex[p][c] == cur; p = link[p]) nex[p][c] = q;
      link[q] = link[cur];
      link[cur] = q;
      return q;
    }
    int cur = sz++, p = last;
    len[cur] = len[p]+1;
    for ( ; ~p && !nex[p].count(c); p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    len[clone] = len[p]+1;
    nex[clone] = nex[q];
    for (; ~p && nex[p].count(c) && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[clone] = link[q];
    link[q] = link[cur] = clone;
    return cur;
  }
  void insert(vector<int> &a, int id) {
    int last = 0;
    for (int x : a) {
      last = extend(last, x);
      for (int i = last; i && vis[i] != id; i = link[i]) {
        vis[i] = id;
        ++cnt[i];
      }
    }
  }
  void build() { // topo on parent tree
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      cnt[j] += cnt[i];
    }
    memset(vis, 0, sizeof(int)*sz);
  }
  int query(vector<int> &a) {
    int u = 0;
    for (int c : a) {
      if (!nex[u].count(c)) return 0;
      u = nex[u][c];
    }
    ++cnt2[u];
    return cnt[u];
  }
  int query2(vector<int> a[], int id) {
    int ans = 0, last;
    for (int t : {0, 1}) {
      last = 0;
      for (int x : a[t]) {
        last = extend(last, x);
        for (int i = last; i && vis[i] != id; i = link[i]) {
          vis[i] = id;
          ans += cnt2[i];
        }
      }
    }
    return ans;
  }
};

int n, m;
vector<int> a[N][2], b[N];
generalSAM gsam;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> m;
  for (int i = 1, l; i <= n; ++i) for (int t : {0, 1}) {
    cin >> l;
    a[i][t].resize(l);
    for (int j = 0; j < l; ++j) cin >> a[i][t][j];
    gsam.insert(a[i][t], i);
  }
  gsam.build();
  for (int i = 1, l; i <= m; ++i) {
    cin >> l;
    b[i].resize(l);
    for (int j = 0; j < l; ++j) cin >> b[i][j];
    cout << gsam.query(b[i]) << '\n';
  }
  for (int i = 1; i <= n; ++i) {
    cout << gsam.query2(a[i], i) << " \n"[i==n];
  }
  return 0;
}