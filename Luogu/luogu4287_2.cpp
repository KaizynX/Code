/*
 * @Author: Kaizyn
 * @Date: 2021-08-04 15:47:22
 * @LastEditTime: 2021-08-04 16:09:58
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
  int trans[N];
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
    node(0);
    fail[0] = node(-1);
    // fail[node(0)] = node(-1);
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
      ch[now][c-C] = x;
      if (len[x] <= 2) {
        trans[x] = fail[x];
      } else {
        int tmp = trans[now];
        while (s[tot-len[tmp]-1] != s[tot] || (len[tmp]+2)*2 > len[x]) tmp = fail[tmp];
        trans[x] = ch[tmp][c-C];
      }
    }
    last = ch[now][c-C];
  }
  int solve() {
    int res = 0;
    for (int i = 2, j; i <= sz; ++i) {
      j = trans[i];
      if (len[j]*2 == len[i] && len[j]%2 == 0) {
        res = max(res, len[i]);
      }
      // if (len[i]%4) continue;
      // if (len[trans[i]] == len[i]/2) res = max(res, len[i]);
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