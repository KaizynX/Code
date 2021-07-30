/*
 * @Author: Kaizyn
 * @Date: 2021-07-30 20:30:00
 * @LastEditTime: 2021-07-30 20:34:58
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
const int N = 1e5+7;

int K;

struct generalSAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, len[M], link[M], nex[M][A];
  int t[M], rk[M], k[M], las[M];
  void init() {
    // memset(nex, 0, sizeof(int)*A*sz);
    link[0] = -1;
    sz = 1;
  }
  int insertSAM(int last, int c) {
    int cur = nex[last][c];
    if (len[cur]) return cur;
    len[cur] = len[last]+1;
    int p = link[last];
    for (; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    for (int i = 0; i < A; ++i)
      nex[clone][i] = len[nex[q][i]] ? nex[q][i] : 0;
    len[clone] = len[p]+1;
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[clone] = link[q];
    link[q] = link[cur] = clone;
    return cur;
  }
  int insertTrie(int cur, int c) {
    return nex[cur][c] ? nex[cur][c] : nex[cur][c] = sz++;
  }
  void insert(const string &s) {
    int root = 0;
    for (char ch : s) root = insertTrie(root, ch-C);
  }
  void sort() {
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i <= sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = sz-1, i, j; _ >= 0; --_) {
      i = rk[_];
      j = link[i];
      if (j == -1) continue;
      k[j] |= k[i];
    }
  }
  void build() {
    queue<pair<int, int>> q;
    for (int i = 0; i < A; ++i)
      if (nex[0][i]) q.push({0, i});
    while (!q.empty()) {
      auto item = q.front();
      q.pop();
      int last = insertSAM(item.first, item.second);
      for (int i = 0; i < A; ++i)
        if (nex[last][i]) q.push({last, i});
    }
  }
  void update(const string &s, int id) {
    int x = 0;
    for (char ch : s) {
      x = nex[x][ch-C];
      for (int y = x; y && las[y] != id; y = link[y]) {
        las[y] = id;
        ++k[y];
      }
    }
  }
  ll query(const string &s) {
    ll cnt = 0;
    int x = 0, y;
    for (char ch : s) {
      x = nex[x][ch-C];
      for (y = x; y && k[y] < K; y = link[y]) {}
      cnt += len[y];
    }
    return cnt;
  }
};

int n;
string s[N];
generalSAM gsam;

inline void solve() {
  cin >> n >> K;
  gsam.init();
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    gsam.insert(s[i]);
  }
  gsam.build();
  for (int i = 1; i <= n; ++i) {
    gsam.update(s[i], i);
  }
  for (int i = 1; i <= n; ++i) {
    cout << gsam.query(s[i]) << " \n"[i==n];
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