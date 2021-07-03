/*
 * @Author: Kaizyn
 * @Date: 2021-06-09 13:08:29
 * @LastEditTime: 2021-06-09 13:13:33
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
const int N = 1e5+7;
const int X = 2e4+7;

int n, m;
int s[N];
vector<pii> a[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1, l, r, x; i <= m; ++i) {
    cin >> l >> r >> x;
    a[x].emplace_back(l, r);
  }
  for (int i = 1, l, r; i <= X; ++i) if (a[i].size()) {
    sort(a[i].begin(), a[i].end());
    l = 1; r = 0;
    for (auto &p : a[i]) {
      if (p.first > r) {
        s[l] += i;
        s[r+1] -= i;
        l = p.first;
        r = p.second;
      } else {
        r = max(r, p.second);
      }
    }
    s[l] += i;
    s[r+1] -= i;
  }
  for (int i = 1; i <= n; ++i) {
    s[i] += s[i-1];
    cout << s[i] << " \n"[i==n];
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