/*
 * @Author: Kaizyn
 * @Date: 2020-05-25 21:59:17
 * @LastEditTime: 2020-05-25 23:13:18
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

struct Aho_Corasick_Automaton {
  static const int NN = 2e3+7;
  static const int SZ = 4;
  char beg;
  int nex[NN][SZ], num[NN], fail[NN], cnt;
  Aho_Corasick_Automaton(const char &_beg = 1) : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(const char *s) {
    int p = 0;
    for (int i = 0, c; s[i] != '\0'; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    num[p] = 1;
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

int n, m;
char s[N];
int dp[N][N];
Aho_Corasick_Automaton ac;

inline void str_magic(char *s) {
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == 'A') s[i] = 1;
    if (s[i] == 'G') s[i] = 2;
    if (s[i] == 'C') s[i] = 3;
    if (s[i] == 'T') s[i] = 4;
  }
}

inline void update(int &x, const int &y) {
  if (x == -1 || x > y) x = y;
}

inline void solve(const int &T) {
  ac.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    str_magic(s);
    ac.insert(s);
  }
  ac.build();
  scanf("%s", s);
  n = strlen(s);
  str_magic(s);
  m = ac.cnt+1;
  for (int i = 0; i <= n; ++i) {
    memset(dp[i], -1, sizeof(int)*(m));
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (dp[i][j] == -1) continue;
      for (int k = 0, to; k < 4; ++k) {
        to = ac.nex[j][k];
        if (ac.num[to]) continue;
        update(dp[i+1][to], dp[i][j]+(k != s[i]-1));
      }
    }
  }
  int res = -1;
  for (int i = 0; i < m; ++i) {
    if (dp[n][i] != -1) update(res, dp[n][i]);
  }
  printf("Case %d: %d\n", T, res);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 0;
  while (scanf("%d", &n) && n) solve(++T);
  return 0;
}