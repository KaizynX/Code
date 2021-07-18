/*
 * @Author: Kaizyn
 * @Date: 2021-07-18 12:01:46
 * @LastEditTime: 2021-07-18 13:11:49
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
const int N = 4e5+7;

int n, k;
string s;
int cnt[26], tot;

void add(int x) {
  if (++cnt[x] > k) ++tot;
}

void del(int x) {
  if (--cnt[x] == k) --tot;
}

bool check(int l) {
  memset(cnt, 0, sizeof cnt);
  tot = 0;
  int res = 0;
  for (int i = 0; i < l; ++i) add(s[i]-'a');
  res |= tot == 0;
  for (int i = l; i < n; ++i) {
    add(s[i]-'a');
    del(s[i-l]-'a');
    res |= tot == 0;
  }
  return res;
}

inline void solve() {
  // cin >> k >> s;
  n = s.size();
  int l = 1, r = n, mid;
  while (l < r) {
    mid = (l+r+1)>>1;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  // int T = 1;
  // cin >> T; // scanf("%d", &T);
  // for (int t = 1; t <= T; ++t) {
    // solve();
  // }
  while (cin >> k >> s) solve();
  return 0;
}