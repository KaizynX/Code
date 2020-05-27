/*
 * @Author: Kaizyn
 * @Date: 2020-05-24 17:07:50
 * @LastEditTime: 2020-05-25 08:35:33
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int N = 1e5+7;

int n, q;
char s[N];
int nt[N][26], res[2][N];
int head[N], len[N], id[N];
int qx[N], qy[N];
map<pii, int> mp;

struct Aho_Corasick_Automaton {
  static const int NN = 1e5+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], fail[NN], num[NN], cnt;
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(const int &x) {
    char *str = s+head[x];
    int p = 0;
    for (int i = 0, c; i < len[x]; ++i) {
      c = str[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    if (!num[p]) num[p] = x;
    id[x] = num[p];
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
  void query(const int &x) {
    char *str = s+head[x];
    for (int i = 0, p = 0; i < len[x]; ++i) {
      p = nex[p][str[i]-beg];
      for (int t = p; t; t = fail[t]) {
        mp[{num[t], id[x]}] = 1;
      }
    }
  }
} ac;

inline void solve_ac() {
  mp.clear();
  ac.clear();
  for (int i = 1; i <= n; ++i) ac.insert(i);
  ac.build();
  for (int i = 1; i <= n; ++i) ac.query(i);
  for (int i = 1; i <= q; ++i) {
    res[1][i] = mp.count({id[qx[i]], id[qy[i]]});
  }
}

inline int check_sub(const int &x, const int &y) {
  if (len[x] > len[y]) return 0;
  for (int i = head[x], j = head[y]; i < head[x]+len[x]; ++i, ++j) {
    if (j >= head[y]+len[y]) return 0;
    j = nt[j][s[i]-'a'];
    if (j == -1) return 0;
  }
  return 1;
}

inline void solve_nt() {
  for (int i = 1, j; i <= n; ++i) {
    j = head[i]+len[i]-1;
    memset(nt[j], -1, sizeof nt[j]);
    nt[j][s[j]-'a'] = j;
    for (--j; j >= head[i]; --j) {
      memcpy(nt[j], nt[j+1], sizeof nt[j]);
      nt[j][s[j]-'a'] = j;
    }
  }
  mp.clear();
  for (int i = 1; i <= q; ++i) {
    if (mp.count({qx[i], qy[i]})) res[0][i] = mp[{qx[i], qy[i]}];
    else mp[{qx[i], qy[i]}] = res[0][i] = check_sub(qx[i], qy[i]);
  }
}

inline void solve() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    head[i] = head[i-1]+len[i-1];
    scanf("%s", s+head[i]);
    len[i] = strlen(s+head[i]);
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d %d", &qx[i], &qy[i]);
  }
  memset(res[0]+1, 0, sizeof(int)*n);
  memset(res[1]+1, 0, sizeof(int)*n);
  solve_nt();
  solve_ac();
  for (int i = 1; i <= q; ++i) {
    printf("%d%d", res[0][i], res[1][i]);
  }
  putchar('\n');
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}