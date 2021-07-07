/*
 * @Author: Kaizyn
 * @Date: 2021-07-06 12:58:37
 * @LastEditTime: 2021-07-06 13:22:00
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 4e5+7;

int n, m;
int a[N], dis[N], h[N];
vector<int> sand[N];
set<int> st;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    static string str;
    cin >> str;
    for (int j = 1; j <= m; ++j) if (str[j-1] == '#') {
      sand[i].emplace_back(j);
    }
  }
  for (int i = 1; i <= m; ++i) cin >> a[i];

  int res = 0;
  memset(h, 0x3f, sizeof h);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dis[j] = n;
      auto it = st.lower_bound(j);
      if (it != st.end()) dis[j] = min(dis[j], *it-j);
      it = st.upper_bound(j);
      if (it != st.begin()) dis[j] = min(dis[j], j-*(--it));
    }
    sort(sand[i].begin(), sand[i].end(), [&](int x, int y) {
      return dis[x] < dis[y];
    });
#ifdef DEBUG
    cout << "res:" << res << '\n';
    cout << "sand:";
    for (auto &j : sand[i]) cout << ' ' << j;
    cout << '\n';
    for (int i = 1; i <= m; ++i) cout << h[i] << " \n"[i==m];
#endif
    for (auto &j : sand[i]) {
      res += h[j] > i && h[j-1] > i && h[j+1] > i;
      st.insert(j);
      h[j] = min(h[j], i);
    }
  }
  cout << res << '\n';
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