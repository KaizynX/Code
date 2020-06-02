/*
 * @Author: Kaizyn
 * @Date: 2020-05-28 15:56:34
 * @LastEditTime: 2020-05-28 19:19:15
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 52;
const int M = 42;
const int H = 11*11*11*11+7;

struct Aho_Corasick_Automaton {
  static const int NN = 5e2+7;
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
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    ++num[p];
  }
  void build(int *w) {
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
      w[i] = 0;
      for (int j = i; j; j = fail[j]) {
        w[i] += num[j];
      }
    }
  }
};

int n;
int num[4], state[4], w[507];
char s[M];
int dp[507][H];
Aho_Corasick_Automaton ac;

inline void str_magic(char *s) {
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == 'A') s[i] = 1;
    if (s[i] == 'C') s[i] = 2;
    if (s[i] == 'G') s[i] = 3;
    if (s[i] == 'T') s[i] = 4;
  }
}

inline int my_hash() {
  int res = 0, base = 1;
  for (int i = 0; i < 4; ++i) {
    res += state[i]*base;
    base *= num[i]+1;
  }
  return res;
}

inline void solve(const int &T) {
  ac.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    str_magic(s);
    ac.insert(s);
  }
  ac.build(w);
  scanf("%s", s);
  str_magic(s);
  memset(num, 0, sizeof num);
  for (int i = 0; s[i] != '\0'; ++i) ++num[s[i]-1];
  n = ac.cnt+1;
  int res = 0;
  memset(state, 0, sizeof state);
  for (int i = 0, sz = (num[0]+1)*(num[1]+1)*(num[2]+1)*(num[3]+1); i < n; ++i) {
    memset(dp[i], 0x8f, sizeof(int)*(sz));
  }
  dp[0][my_hash()] = 0;
  for (state[0] = 0; state[0] <= num[0]; ++state[0])
  for (state[1] = 0; state[1] <= num[1]; ++state[1])
  for (state[2] = 0; state[2] <= num[2]; ++state[2])
  for (state[3] = 0; state[3] <= num[3]; ++state[3]) {
    int s1 = my_hash(), s2;
    for (int i = 0; i < n; ++i) if (dp[i][s1] >= 0) {
      for (int j = 0; j < 4; ++j) if (state[j]+1 <= num[j]) {
        int np = ac.nex[i][j], val = dp[i][s1]+w[np];
        ++state[j];
        s2 = my_hash();
        dp[np][s2] = max(dp[np][s2], val);
        res = max(res, val);
        --state[j];
      }
    }
  }
  printf("Case %d: %d\n", T, res);
  // malloc_trim(0);
}

signed main() {
  int T = 0;
  while (scanf("%d", &n) == 1 && n) {
    solve(++T);
  }
  return 0;
}