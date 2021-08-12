/*
 * @Author: Kaizyn
 * @Date: 2021-08-12 13:43:18
 * @LastEditTime: 2021-08-12 13:55:25
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
const int N = 1e5+7;
const int L = 33;

struct Aho_Corasick_Automaton {
  static const int NN = 2e6+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], num[NN], fail[NN], cnt, last[NN];
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    memset(last, 0, sizeof(int)*(cnt+1));
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
  void query(const char *s, int k) {
    int len = strlen(s), p = 0;
    for (int i = 0; i < len; ++i) {
      p = nex[p][s[i]-beg];
      #ifdef DEBUG
      printf("%d, %d, %d, %d\n", i, p, num[p], last[p]);
      #endif
      if (!last[p] || last[p]+k-1 <= i) {
        ++num[p];
        last[p] = i+1;
      }
      // num[p] += last[p] ? last[p]+k-1 <= i : 1;
      // last[p] = i+1;
      /*
      for (int t = p; t && ~num[t]; t = fail[t]) {
        res += num[t];
        num[t] = -1;
      }
      */
    }
    // return res;
  }
};

int n;
int b[N], res[N];
vector<int> l[L];
char s[N], a[N][L];
Aho_Corasick_Automaton ac;

inline void solve() {
  scanf("%s%d", s, &n);
  for (int i = 1; i <= 30; ++i) l[i].clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]);
    l[strlen(a[i])].emplace_back(i);
  }
  for (int i = 1; i <= 30; ++i) if (l[i].size()) {
    ac.clear();
    for (int j : l[i]) {
      b[j] = ac.insert(a[j]);
    }
    ac.build();
    ac.query(s, i);
    for (int j : l[i]) {
      res[j] = ac.num[b[j]];
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", res[i]);
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