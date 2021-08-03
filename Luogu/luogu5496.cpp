/*
 * @Author: Kaizyn
 * @Date: 2021-08-03 18:00:31
 * @LastEditTime: 2021-08-03 18:21:07
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
  int ch[N][A], len[N], fail[N], cnt[N];
  char s[N];
  int node(int l) {
    sz++;
    memset(ch[sz], 0, sizeof ch[sz]);
    len[sz] = l;
    fail[sz] = cnt[sz] = 0;
    return sz;
  }
  void init() {
    sz = -1;
    last = 0;
    s[tot = 0] = '$';
    node(0);
    node(-1);
    fail[0] = 1;
  }
  int getfail(int x) {
    while (s[tot-len[x]-1] != s[tot]) x = fail[x];
    return x;
  }
  int insert(char c) {
    s[++tot] = c;
    int now = getfail(last);
    if (!ch[now][c-C]) {
      int x = node(len[now]+2);
      fail[x] = ch[getfail(fail[now])][c-C];
      cnt[x] = cnt[fail[x]]+1;
      ch[now][c-C] = x;
    }
    last = ch[now][c-C];
    return cnt[last];
  }
};

string s;
PAM pam;

inline void solve() {
  cin >> s;
  pam.init();
  int k = 0;
  for (char ch : s) {
    k = pam.insert((ch-97+k)%26+97);
    cout << k << ' ';
  }
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