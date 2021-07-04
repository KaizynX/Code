/*
 * @Author: Kaizyn
 * @Date: 2021-07-04 14:52:23
 * @LastEditTime: 2021-07-04 14:55:17
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
const int N = 1e3+7;

int n, k, t;
int a[N];
set<pii> s;
vector<pii> v;

bool check() {
  int r = (t*k-n)/2;
  for (int i = 1; i <= n; ++i) {
    a[i] = 1+r/n*2+(i <= r%n)*2;
  }
  s.clear();
  for (int i = 1; i <= n; ++i) s.insert(pii{a[i], i});
  for (int i = 1; i <= t; ++i) {
    if ((int)s.size() < k) return false;
    v.clear();
    for (int j = 1; j <= k; ++j) {
      pii x = *s.rbegin();
      s.erase(--s.end());
      if (--x.first) v.emplace_back(x);
    }
    s.insert(v.begin(), v.end());
  }
  return true;
}

int query() {
  v.clear();
  cout << "?";
  // assert(s.size() >= k);
  for (int i = 1; i <= k; ++i) {
    pii x = *s.rbegin();
    s.erase(--s.end());
    cout << ' ' << x.second;
    if (--x.first) v.emplace_back(x);
  }
  s.insert(v.begin(), v.end());
  cout << endl;
  int x;
  cin >> x;
  return x;
}

inline void solve() {
  cin >> n >> k;
  if (k%2 == 0 && n%2 == 1) return cout << "-1\n", void();
  t = 500;
  for (int i = 0; i < 5; ++i, --t) {
    if ((t*k-n)%2 == 1) continue;
    if (check()) break;
  }
  int res = 0;
  #ifdef DEBUG
  cout << t << endl;
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  #endif
  for (int i = 1; i <= n; ++i) s.insert(pii{a[i], i});
  while (t--) res ^= query();
  cout << "! " << res << endl;
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