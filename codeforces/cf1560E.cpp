/*
 * @Author: Kaizyn
 * @Date: 2021-08-18 23:13:25
 * @LastEditTime: 2021-08-18 23:36:04
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
const int N = 5e5+7;

string s, t;
int cnt[26], vis[26], tmp[26];

#define GG {return cout<<"-1\n",void();}

bool check(const string &sub) {
  string ss = sub;
  memset(vis, 0, sizeof vis);
  for (char c : t) {
    vis[c-'a'] = 1;
    for (char ch : sub) {
      if (!vis[ch-'a']) ss += ch;
    }
  }
  return ss == s;
}

inline void solve() {
  cin >> s;
  t = "";
  memset(cnt, 0, sizeof cnt);
  memset(vis, 0, sizeof vis);
  int turn = 0, sum = 0;
  for (int c : s) {
    if (++vis[c-'a'] == 1) ++turn;
  }
  for (int p = s.size()-1, q; turn; --turn) {
    q = p;
    while (p > 0 && !vis[s[p]-'a']) --p;
    if (p < 0) GG;
    t += s[p];
    if (vis[s[p]-'a']%turn) GG;
    cnt[s[p]-'a'] = vis[s[p]-'a']/turn;
    vis[s[p]-'a'] = 0;
    sum += cnt[s[p]-'a'];
    memcpy(tmp, cnt, sizeof tmp);
    p = q;
    if (p+1 < sum) GG;
    for (int i = sum; i; --i) {
      if (--tmp[s[p--]-'a'] < 0) GG;
    }
  }
  reverse(t.begin(), t.end());
  if (!check(s.substr(0, sum))) GG;
  cout << s.substr(0, sum) << ' ' << t << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}