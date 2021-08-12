/*
 * @Author: Kaizyn
 * @Date: 2021-08-12 12:31:26
 * @LastEditTime: 2021-08-12 12:59:17
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

struct Aho_Corasick_Automaton {
  static const int NN = 4e5+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], /*num[NN],*/ fail[NN], cnt;
  int vis[NN], res[NN][31];
  vector<int> pt[NN], dp[NN][31];
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    // memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    for (int i = 0; i <= cnt; ++i) pt[i].clear();
    for (int i = 0; i <= cnt; ++i) if (vis[i]) {
      for (int j = 1; j <= 30; ++j) dp[i][j].clear();
      vis[i] = 0;
    }
    // memset(vis, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  int insert(const char *s) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    // ++num[p];
    return p;
  }
  void build() {
    static queue<int> q;
    for (int i = 0; i < SZ; ++i) if (nex[0][i]) q.push(nex[0][i]);
    while (q.size()) {
      int u = q.front();
      q.pop();
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
  void fuck(const char *s) {
    int len = strlen(s), p = 0;
    for (int i = 0; i < len; ++i) {
      p = nex[p][s[i]-beg];
      pt[p].emplace_back(i);
      /*
      for (int t = p; t && ~num[t]; t = fail[t]) {
        res += num[t];
        num[t] = -1;
      }
      */
    }
  }
  void shit(int id) {
    #ifdef DEBUG
    printf("%d:", id);
    for (int i : pt[id]) printf("%d ", i);
    puts("");
    #endif
    if (vis[id]) return;
    vis[id] = 1;
    memset(res[id], 0, sizeof res[id]);
    vector<int> *dpp = dp[id];
    for (int i = 1; i <= 30; ++i) {
      dpp[i].assign(pt[id].size(), 1);
    }
    for (int i = 1; i < (int)pt[id].size(); ++i) {
      for (int j = 1, k = i-1; j <= 30; ++j) {
        while (~k && pt[id][k] > pt[id][i]-j) --k;
        if (~k) dpp[j][i] = max(dpp[j][i], dpp[j][k]);
        res[id][j] = max(res[id][j], dpp[j][i]);
        #ifdef DEBUG
        printf("dpp[%d][%d]=%d,", j, i, dpp[j][i]);
        #endif
      }
      #ifdef DEBUG
      puts("");
      #endif
    }
  }
  int query(int id, int len) {
    shit(id);
    return res[id][len];
  }
};

int n;
int a[N], l[N];
char s[N], t[N];
Aho_Corasick_Automaton ac;

inline void solve() {
  scanf("%s%d", s, &n);
  ac.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", t);
    l[i] = strlen(t);
    a[i] = ac.insert(t);
  }
  ac.build();
  ac.fuck(s);
  for (int i = 1; i <= n; ++i) {
    #ifdef DEBUG
    printf("%d:query(%d,%d)\n", i, a[i], l[i]);
    #endif
    printf("%d\n", ac.query(a[i], l[i]));
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}