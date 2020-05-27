/*
 * @Author: Kaizyn
 * @Date: 2020-05-26 13:23:07
 * @LastEditTime: 2020-05-26 20:28:09
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
const int M = 1234;

int n, m;
int h[N];
int dp[55][M];
string str[55][M];
string s;

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
    int p = 0;
    for (int i = 0, c; i < (int)s.size(); ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt, ch[cnt] = c;
      p = nex[p][c];
    }
    num[p] = id;
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
} ac;

inline bool cmp(const string &s1, const string &s2) {
  if (s1.size() != s2.size()) return s1.size() < s2.size();
  return s1 < s2;
}

inline void solve() {
  ac.clear();
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> s;
    ac.insert(i);
  }
  for (int i = 1; i <= m; ++i) cin >> h[i];
  m = ac.cnt+1;
  ac.build();
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] = -INF;
      str[i][j] = "";
    }
  }
  dp[0][0] = 0;
  int resv = 0;
  string ress = "";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) if (dp[i][j] >= 0) {
      s = str[i][j];
      for (int k = 0; k < 26; ++k) {
        int np = ac.nex[j][k],
            val = dp[i][j]+h[ac.num[np]];
        s.push_back('a'+k);
        if (dp[i+1][np] < val || (dp[i+1][np] == val && cmp(s, str[i+1][np]))) {
          dp[i+1][np] = val;
          str[i+1][np] = s;
          if (val > resv || (val == resv && cmp(s, ress))) {
            resv = val;
            ress = s;
          }
        }
        s.pop_back();
      }
    }
  }
  cout << ress << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}