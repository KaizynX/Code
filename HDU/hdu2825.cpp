/*
 * @Author: Kaizyn
 * @Date: 2020-05-26 10:41:58
 * @LastEditTime: 2020-05-26 11:27:35
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 20090717;
const int INF = 0x3f3f3f3f;

struct Aho_Corasick_Automaton {
  static const int NN = 1e2+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], num[NN], fail[NN], cnt;
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(const char *s, const int &id) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    num[p] |= 1<<id;
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
    for (int i = 0; i <= cnt; ++i) {
      for (int j = i; j; j = fail[j]) {
        num[i] |= num[j];
      }
    }
  }
};

int n, m, k, t;
char s[20];
int dp[30][110][1<<10];
Aho_Corasick_Automaton ac;

inline void init_dp() {
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < t; ++j) {
      memset(dp[i][j], 0, sizeof(int)*(1<<m));
    }
  }
  dp[0][0][0] = 1;
}

inline void solve() {
  ac.clear();
  for (int i = 0; i < m; ++i) {
    scanf("%s", s);
    ac.insert(s, i);
  }
  ac.build();
  t = ac.cnt+1;
  init_dp();
  for (int i = 0; i < n; ++i) { // length of target string
    for (int j = 0; j < t; ++j) { // at ac.pos[j]
      for (int l = 0; l < 1<<m; ++l) if (dp[i][j][l]) { // include the magic set
        for (int ch = 0; ch < 26; ++ch) { // next char
          int np = ac.nex[j][ch], nt = l|ac.num[np];
          (dp[i+1][np][nt] += dp[i][j][l]) %= MOD;
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < 1<<m; ++i) {
    if (__builtin_popcount(i) < k) continue;
    for (int j = 0; j < t; ++j) {
      (res += dp[n][j][i]) %= MOD;
    }
  }
  printf("%d\n", res);
}

signed main() {
  while (scanf("%d %d %d", &n, &m, &k) == 3 && n|m|k) solve();
  return 0;
}