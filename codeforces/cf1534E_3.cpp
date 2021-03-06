/*
 * @Author: Kaizyn
 * @Date: 2021-07-04 14:59:44
 * @LastEditTime: 2021-07-04 15:26:26
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
  int p = 0, sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= t) p = max(p, i);
    else sum += a[i];
  }
  if (p >= k) return true;
  if (sum/(k-p) == t) return true;
  return false;
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
  for (t = (n+k-1)/k; t <= 500; ++t) {
  // for (t = 168; t <= 500; ++t) {
    if ((t*k-n)&1) continue;
    if (check()) break;
  }
  // if (t > 500) cout << "-1\n", void();
  #ifdef DEBUG
  cout << t << endl;
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  #endif
  int res = 0;
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