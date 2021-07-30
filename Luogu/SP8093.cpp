/*
 * @Author: Kaizyn
 * @Date: 2021-07-30 16:11:35
 * @LastEditTime: 2021-07-30 16:18:36
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
const int B = 1e4;

struct generalSAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, len[M], link[M], nex[M][A];
  int t[M], rk[M];
  bitset<B> k[M];
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
  void insert(const char *s, int id) {
    int root = 0;
    for (int i = 0; s[i]; ++i) {
      root = insertTrie(root, s[i]-C);
      k[root][id] = 1;
    }
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
  int solve(const char *s) {
    int p = 0;
    for (int i = 0; s[i]; ++i) {
      p = nex[p][s[i]-C];
      if (!p) return 0;
    }
    return k[p].count();
  }
};

int n, m;
char s[N];
generalSAM gsam;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  scanf("%d%d", &n, &m);
  gsam.init();
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    gsam.insert(s, i);
  }
  gsam.build();
  gsam.sort();
  for (int _ = m; _; --_) {
    scanf("%s", s);
    printf("%d\n", gsam.solve(s));
  }
  return 0;
}