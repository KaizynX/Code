/*
 * @Author: Kaizyn
 * @Date: 2021-08-22 15:53:38
 * @LastEditTime: 2021-08-22 15:59:18
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
  int sz, len[M], link[M], vis[M], cnt[M];
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
  void insert(vector<int> &a) {
    int last = 0; for (int x : a) last = extend(last, x);
  }
  void insert(vector<int> &a, int id) {
    int last = 0;
    for (int x : a) {
      last = nex[last][x];
      for (int i = last; i && vis[i] != id; i = link[i]) {
        vis[i] = id;
        ++cnt[i];
      }
    }
  }
  int query(int n) {
    int ans = 0;
    for (int i = 0; i < sz; ++i) {
      if (cnt[i] == n) ans = max(ans, len[i]);
    }
    return ans+1;
  }
};

int n;
vector<int> a[N];
generalSAM gsam;

inline void solve() {
  cin >> n;
  for (int i = 1, m; i <= n; ++i) {
    cin >> m;
    a[i].resize(m);
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (j) a[i][j-1] -= a[i][j];
    }
    a[i].pop_back();
    gsam.insert(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    gsam.insert(a[i], i);
  }
  cout << gsam.query(n) << '\n';
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