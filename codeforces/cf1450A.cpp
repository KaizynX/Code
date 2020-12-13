/*
 * @Author: Kaizyn
 * @Date: 2020-12-06 22:31:29
 * @LastEditTime: 2020-12-06 22:40:25
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e2+7;

int n;
string s, t = "trygub";
int cnt[256];

inline void solve() {
  cin >> n >> s;
  memset(cnt, 0, sizeof cnt);
  for (char &c : s) ++cnt[c];
  string res;
  for (int i = t.size()-1; i >= 0; --i) {
    res += string(cnt[t[i]], t[i]);
    // for (int _ = 0; _ < cnt[t[i]]; ++_) res += t[i];
  }
  for (char c = 'a'; c <= 'z'; ++c) if (t.find(c) == t.npos) {
    res += string(cnt[c], c);
    // for (int _ = 0; _ < cnt[c]; ++_) res += t[i];
    // while (cnt[c]--) res += c;
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}