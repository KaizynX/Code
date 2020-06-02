/*
 * @Author: Kaizyn
 * @Date: 2020-05-29 18:34:52
 * @LastEditTime: 2020-05-29 23:44:17
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e1+3;
const int L = 1e3+7;
const int M = 6e4+7;

struct Aho_Corasick_Automaton {
  static const int NN = M;
  static const int SZ = 2;
  char beg;
  int nex[NN][SZ], num[NN], fail[NN], cnt;
  Aho_Corasick_Automaton(const char &_beg = '0') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  int insert(const char *s, const int &k) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    num[p] = k;
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
};

int n, m;
int p[N], dis[M];
int d[N][N], dp[N][1<<10];
char s[M];
Aho_Corasick_Automaton ac;

inline void bfs(const int &st) {
  static queue<int> q;
  memset(dis, 0x3f, sizeof(int)*(ac.cnt+1));
  q.push(p[st]);
  dis[p[st]] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0, v; i < 2; ++i) {
      v = ac.nex[u][i];
      if (ac.num[v] || dis[v] <= dis[u]+1) continue;
      dis[v] = dis[u]+1;
      q.push(v);
    }
  }
  for (int i = 0; i < n; ++i) d[st][i] = dis[p[i]];
}

inline void solve() {
  ac.clear();
  memset(d, 0x3f, sizeof d);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    p[i] = ac.insert(s, 0);
    memset(dp[i], 0x3f, sizeof(int)*(1<<n));
    dp[i][1<<i] = strlen(s);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%s", s);
    ac.insert(s, 1);
  }
  ac.build();
  for (int i = 0; i < n; ++i) bfs(i);
  #ifdef DEBUG
  puts("****");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d%c", d[i][j], " \n"[j==n-1]);
    }
  }
  puts("****");
  #endif

  for (int i = 1; i < 1<<n; ++i) if (__builtin_popcount(i) > 1) {
    for (int j = 0, l; j < n; ++j) if ((i>>j)&1) {
      l = i^(1<<j);
      for (int k = 0; k < n; ++k) if ((l>>k)&1) {
        dp[j][i] = min(dp[j][i], dp[k][l]+d[k][j]);
      }
    }
  }
  int res = INF;
  for (int i = 0, j = (1<<n)-1; i < n; ++i) {
    res = min(res, dp[i][j]);
  }
  printf("%d\n", res);
}

signed main() {
  while (scanf("%d %d", &n, &m) == 2 && n|m) solve();
  return 0;
}