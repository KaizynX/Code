/*
 * @Author: Kaizyn
 * @Date: 2021-05-08 20:13:08
 * @LastEditTime: 2021-05-08 20:23:50
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

int n, m, l;
int a[N], b[N], c[N];
int la[N], ra[N], lb[N], rb[N];
vector<int> pa[N], pb[N];
vector<int> addl[N], addr[N], dell[N], delr[N];
multiset<int> stl, str;

inline bool solve() {
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pa[a[i]].emplace_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    pb[b[i]].emplace_back(b[i]);
  }
  for (int i = 1; i <= l; ++i) cin >> c[i];

  for (int i = 1, j = 1, k = 1; i <= l; ++i) {
    while (j <= n && a[j] != c[i]) ++j;
    while (k <= m && b[k] != c[i]) ++k;
    la[i] = j;
    lb[i] = k;
  }
  for (int i = l, j = n, k = m; i; --i) {
    while (j && a[j] != c[i]) --j;
    while (k && b[k] != c[i]) --k;
    ra[i] = j;
    rb[i] = k;
  }
  if (la[l] > n || lb[l] > m) return false;

  // init
  la[0] = lb[0] = 0;
  ra[l+1] = n+1; rb[l+1] = m+1;
  stl.clear();
  str.clear();
  for (int i = 1; i <= n; ++i) {
    addl[i].clear();
    addr[i].clear();
    dell[i].clear();
    delr[i].clear();
  }

  for (int i = 0; i <= n; ++i) {
    // between c[i] & c[i+1]
    int al = la[i]+1, ar = ra[i+1]-1;
    int bl = lb[i]+1, br = rb[i+1]-1;
    addl[al].emplace_back(bl);
    addr[al].emplace_back(br);
    dell[ar].emplace_back(bl);
    delr[ar].emplace_back(br);
  }
  for (int i = 1; i <= n; ++i) {
    for (auto &v : addl) stl.insert(v);
    for (auto &v : addr) str.insert(v);
    if (stl.size() && str.size()) {
    }
    for (auto &v : dell) stl.erase(stl.find(v));
    for (auto &v : delr) str.erase(str.find(v));
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  while (cin >> n >> m >> l) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}