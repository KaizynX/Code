/*
 * @Author: Kaizyn
 * @Date: 2021-07-18 13:13:21
 * @LastEditTime: 2021-07-18 13:14:53
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
// const int N = ;

int k, n;
string s;
int cnt[26], tot;

void add(int x) {
  if (++cnt[x] > k) ++tot;
}

void del(int x) {
  if (--cnt[x] == k) --tot;
}

inline void solve() {
  n = s.size();
  int res = 0;
  memset(cnt, 0, sizeof cnt);
  tot = 0;
  for (int r = 0, l = 0; r < n; ++r) {
    add(s[r]-'a');
    while (tot) del(s[l++]-'a');
    res = max(res, r-l+1);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  while (cin >> k >> s) solve();
  return 0;
}