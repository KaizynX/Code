/*
 * @Author: Kaizyn
 * @Date: 2021-07-10 23:23:02
 * @LastEditTime: 2021-07-10 23:33:41
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
const int N = 3e5+7;

int n, k;
int a[N], t[N];
vector<int> v[N];
multiset<int> sl, sr;

inline void solve() {
  sl.clear();
  sr.clear();
  sl.insert(INF);
  sr.insert(INF);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) v[i].clear();
  for (int i = 1; i <= k; ++i) cin >> a[i];
  for (int i = 1; i <= k; ++i) {
    cin >> t[i];
    v[a[i]].emplace_back(t[i]);
    sr.insert(t[i]+a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    // cout << *sl.begin() << ' ' << *sr.begin() << '\n';
    int nt = min(*sl.begin()+i, *sr.begin()-i);
    cout << nt << " \n"[i==n];
    for (int &j : v[i]) {
      sr.erase(sr.find(j+i));
      sl.insert(j-i);
    }
  }
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