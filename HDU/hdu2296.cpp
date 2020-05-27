/*
 * @Author: Kaizyn
 * @Date: 2020-05-26 13:23:07
 * @LastEditTime: 2020-05-26 19:03:28
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n, m;
int h[N], w[1100];
int dp[55][1100], pre[55][1100];
char str[N][15];

struct Aho_Corasick_Automaton {
  static const int NN = 2e3+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], num[NN], fail[NN], ch[NN], cnt;
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    memset(ch, 0, sizeof(int)*(cnt+1));
    cnt = 0;
    ch[0] = 233;
  }
  void insert(const int &id) {
    char *s = str[id];
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt, ch[cnt] = c;
      p = nex[p][c];
    }
    num[p] += h[id];
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
      // w[i] = num[i];
      w[i] = 0;
      for (int j = i; j; j = fail[j]) {
        w[i] += num[j];
      }
    }
  }
} ac;

inline void init() {
  for (int i = 0; i <= n; ++i) {
    memset(dp[i], 0x8f, sizeof(int)*m);
    memset(pre[i], 0, sizeof(int)*m);
  }
  dp[0][0] = 0;
}

inline void solve() {
  ac.clear();
  scanf("%d %d", &n, &m);
  for (int i = 1, len; i <= m; ++i) {
    scanf("%s", str[i]);
    len = strlen(str[i]);
    reverse(str[i], str[i]+len);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", h+i);
    ac.insert(i);
  }
  m = ac.cnt+1;
  init();
  ac.build();
#ifdef DEBUG
  for (int i = 0; i < m; ++i) {
    printf("%d %c %d\n", i, 'a'+ac.ch[i], w[i]);
  }
#endif
  int resi = 0, resj = 0;
  for (int i = 1; i <= n; ++i) { // length
    for (int j = 0; j < m; ++j) { // pos at ac
      for (int k = 0; k < 26; ++k) {
        // (i-1)'th at j --> i'th chhose char(k) at np
        int np = ac.nex[j][k],
            val = dp[i-1][j]+w[np];
        if (val > dp[i][np] ||
            (val == dp[i][np] && ac.ch[j] < ac.ch[pre[i][np]])) {
          dp[i][np] = val;
          pre[i][np] = j;
          if (dp[i][np] > dp[resi][resj] ||
              (dp[i][np] == dp[resi][resj] && i <= resi && k < ac.ch[resj])) {
            resi = i;
            resj = np;
          }
        }
      }
    }
#ifdef DEBUG
    printf("dp[%d][%d]=%d\n", resi, resj, dp[resi][resj]);
#endif
  }
  for ( ; resi; --resi) {
    putchar('a'+ac.ch[resj]);
    resj = pre[resi][resj];
  }
  putchar('\n');
}

signed main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}