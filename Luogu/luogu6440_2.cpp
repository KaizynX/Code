/*
 * @Author: Kaizyn
 * @Date: 2021-07-30 17:43:07
 * @LastEditTime: 2021-07-31 20:10:14
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 4e5+7;

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = (int)log2(N)+3;
  static const T INF = 1e9;
  int lg2[N];
  U cmp = U();
  T rmq[N][NN];
  ST() {
    fill(rmq[0], rmq[0]+N*NN, cmp(-INF, +INF) ? INF : -INF);
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
  }
  T& operator [] (const int &i) { return rmq[i][0]; }
  void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
  // rmq[i][j] ==> [i, i+2^j-1]
  void build(T a[], const int &n) {
    for (int i = n; i; --i) {
      rmq[i][0] = a[i];
      for (int j = 1; j <= lg2[n-i+1]; ++j)
        rmq[i][j] =  mv(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  T query(const int &l, const int &r) {
    if (l > r) return query(r, l);
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

struct generalSAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, len[M], link[M], nex[M][A];
  int k[M], t[M], rk[M], mp[M], mpp[M], f[M];
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
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
  void insert(const string &s, int id) {
    int root = 0;
    for (char ch : s) k[root = insertTrie(root, ch-C)] |= 1<<id;
    for (int i = 0; i < (int)s.size(); ++i) {
      k[root = insertTrie(root, s[i]-C)] |= 1<<id;
      if (!id) {
        mp[i+1] = root;
        // mpp[root] = i+1;
      }
    }
  }
  void sort() {
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i <= sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
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
  void solve() {
    for (int _ = sz-1, i, j; _ >= 0; --_) {
      i = rk[_];
      j = link[i];
      if (j == -1) continue;
      k[j] |= k[i];
    }
    for (int _ = 0, i, j; _ < sz; ++_) {
      i = rk[_];
      j = link[i];
      if (j == -1) continue;
      if (k[i] == 3) f[i] = len[i];
      else f[i] = f[j];
    }
  }
  #ifdef DEBUG
  void debug() {
    for (int i = 0; i < sz; ++i) cout << link[i] << " \n"[i==sz-1];
    for (int i = 0; i < sz; ++i) cout << f[i] << " \n"[i==sz-1];
  }
  #endif
};

int n, q;
int g[N];
string s, t;
generalSAM gsam;
ST<int, greater<int>> st;

inline void solve() {
  cin >> s >> t;
  n = s.size();
  gsam.init();
  gsam.insert(s, 0);
  gsam.insert(t, 1);
  gsam.build();
  gsam.sort();
  gsam.solve();
  for (int i = 1; i <= n; ++i) {
    g[i] = min(i, gsam.f[gsam.mp[i]]);
  }
  st.build(g, n);
  #ifdef DEBUG
  gsam.debug();
  for (int i = 1; i <= n; ++i) cout << g[i] << " \n"[i==n];
  #endif
  cin >> q;
  for (int _ = q, l, r; _; --_) {
    cin >> l >> r;
    cout << min(r-l+1, st.query(l, r)) << '\n';
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