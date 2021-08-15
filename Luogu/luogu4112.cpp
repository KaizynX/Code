/*
 * @Author: Kaizyn
 * @Date: 2021-08-15 14:41:53
 * @LastEditTime: 2021-08-15 16:14:02
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
const int N = 2e3+7;

struct SAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, last, len[M], link[M], nex[M][A];
  SAM() { init(); }
  void init() {
    // memset(nex, 0, sizeof nex);
    link[0] = -1; sz = 1; last = 0;
  }
  int extend(int c) {
    int cur = sz++, p = last;
    len[cur] = len[last]+1;
    for (; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    link[clone] = link[q];
    len[clone] = len[p]+1;
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[q] = link[cur] = clone;
    return cur;
  }
  void build(const string &s) {
    for (char ch : s) last = extend(ch-C);
  }
  int get_nex(int i, int c) const {
    while (~i && !nex[i][c]) i = link[i];
    return ~i ? nex[i][c] : 0;
  }
};

struct SeqAutomaton { // suppose string [1, n]
  static const int A = 26;
  static const char C = 'a';
  int nex[N][A], ch[A];
  void build(const string &s) {
    memset(ch, 0, sizeof ch);
    memset(nex[s.size()], 0, sizeof ch);
    for (int i = s.size(); i; --i) {
      ch[s[i-1]-C] = i;
      memcpy(nex[i-1], ch, sizeof ch);
    }
  }
  int get_nex(int i, int c) const {
    return nex[i][c];
  }
};

int dp[N<<1][N<<1];
string A, B;
SAM sam_a, sam_b;
SeqAutomaton sqm_a, sqm_b;

void update(int &x, int y) {
  if (y == -1) return;
  if (x == -1 || y < x) x = y;
}

template <typename T, typename U>
int bfs(const T &ma, const U &mb, int ia = 0, int ib = 0, int check = 1) {
  // cout << ia << ' ' << ib << ' ' << len << '\n';
  if (~dp[ia][ib]) return dp[ia][ib];
  if (check && !ia) return -1;
  if (check && !ib) return 0;
  int res = -1;
  for (int i = 0; i < 26; ++i) {
    update(res, bfs(ma, mb, ma.nex[ia][i], mb.nex[ib][i]));
  }
  if (~res) ++res;
  return dp[ia][ib] = res;
}

inline void solve() {
  cin >> A >> B;
  sam_a.build(A);
  sam_b.build(B);
  sqm_a.build(A);
  sqm_b.build(B);
  memset(dp, -1, sizeof dp);
  cout << bfs(sam_a, sam_b, 0, 0, 0) << '\n';
  memset(dp, -1, sizeof dp);
  cout << bfs(sam_a, sqm_b, 0, 0, 0) << '\n';
  memset(dp, -1, sizeof dp);
  cout << bfs(sqm_a, sam_b, 0, 0, 0) << '\n';
  memset(dp, -1, sizeof dp);
  cout << bfs(sqm_a, sqm_b, 0, 0, 0) << '\n';
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