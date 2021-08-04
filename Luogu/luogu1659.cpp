/*
 * @Author: Kaizyn
 * @Date: 2021-08-04 14:14:31
 * @LastEditTime: 2021-08-04 14:26:26
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
const int MOD = 19930726;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

struct PAM {
  static const int A = 26;
  static const char C = 'a';
  int sz, tot, last;
  int ch[N][A], len[N], fail[N];
  int cnt[N];
  ll sum[N];
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
  void insert(char c) {
    s[++tot] = c;
    int now = getfail(last);
    if (!ch[now][c-C]) {
      int x = node(len[now]+2);
      fail[x] = ch[getfail(fail[now])][c-C];
      ch[now][c-C] = x;
    }
    last = ch[now][c-C];
    ++cnt[last];
  }
  ll solve(ll k) {
    ll res = 1;
    for (int i = sz; i >= 0; --i) {
      cnt[fail[i]] += cnt[i];
      sum[len[i]] += cnt[i];
    }
    for (int i = tot; i; --i) if (i&1) {
      ll t = min(k, sum[i]);
      k -= t;
      res = res*qpow(i, t)%MOD;
    }
    return k ? -1 : res;
  }
};

int n;
ll k;
string s;
PAM pam;

inline void solve() {
  cin >> n >> k >> s;
  pam.init();
  for (char ch : s) pam.insert(ch);
  cout << pam.solve(k) << '\n';
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