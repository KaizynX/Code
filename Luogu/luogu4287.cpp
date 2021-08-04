/*
 * @Author: Kaizyn
 * @Date: 2021-08-04 15:00:44
 * @LastEditTime: 2021-08-04 16:19:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

struct PAM {
  static const int A = 26;
  static const char C = 'a';
  int sz, tot, last;
  int ch[N][A], len[N], fail[N];
  int diff[N], slink[N];
  char s[N];
  int node(int l) {
    ++sz;
    memset(ch[sz], 0, sizeof ch[sz]);
    len[sz] = l;
    fail[sz] = 0;
    return sz;
  }
  void init() {
    sz = -1;
    last = 0;
    s[tot = 0] = '$';
    fail[node(0)] = node(-1);
  }
  int getfail(int x) {
    while (s[tot-len[x]-1] != s[tot]) x = fail[x];
    return x;
  }
  void insert(char c) {
    s[++tot] = c;
    int now = getfail(last);
    if (!ch[now][c-C]) {
      int x = node(len[now]+2);
      fail[x] = ch[getfail(fail[now])][c-C];
      diff[x] = len[x]-len[fail[x]];
      slink[x] = diff[x] == diff[fail[x]] ? slink[fail[x]] : fail[x];
      ch[now][c-C] = x;
    }
    last = ch[now][c-C];
  }
  ll solve() {
    int res = 0;
    for (int i = 2; i <= sz; ++i) {
      if (len[i]%4) continue;
      for (int j = i, k = slink[i]; j; j = fail[k], k = slink[j]) {
        if (len[k] > len[i]/2) continue;
        if (len[j] < len[i]/2) break;
        if ((len[i]/2-len[k])%diff[j] == 0) res = max(res, len[i]);
      }
    }
    return res;
  }
};

int n;
string s;
PAM pam;

inline void solve() {
  cin >> n >> s;
  pam.init();
  for (char ch : s) pam.insert(ch);
  cout << pam.solve() << '\n';
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