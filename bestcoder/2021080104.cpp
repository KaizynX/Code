/*
 * @Author: Kaizyn
 * @Date: 2021-08-01 14:52:19
 * @LastEditTime: 2021-08-01 15:18:40
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
const int N = 1e5+7;

int n;
ll m;
ll a[N];
vector<ll> v[3];

int spj() {
  int x = 0;
  for (int j : v[1]) {
    x += j;
    if (x < 0) x = 0;
    if (x >= m) return 1;
  }
  for (int j : v[1]) {
    x += j;
    if (x < 0) x = 0;
    if (x >= m) return 2;
  }
  return 0;
}

inline int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  v[0].assign(1, 0);
  for (int i = 1; i <= n; ++i) {
    if ((a[i] >= 0) == (v[0].back() >= 0)) {
      v[0].back() += a[i];
    } else {
      v[0].emplace_back(a[i]);
    }
  }
  v[1].assign(1, v[0].front());
  for (int i = 1; i < (int)v[0].size(); ++i) {
    if (v[1].back() < 0 || v[1].back()+v[0][i] < 0) {
      v[1].emplace_back(v[0][i]);
    } else {
      v[1].back() += v[0][i];
    }
  }
  #ifdef DEBUG
  cout << "v0:"; for (int i : v[0]) cout << i << ' ';
  cout << "\nv1:"; for (int i : v[1]) cout << i << ' ';
  cout << "\n****************\n";
  #endif
  if (spj()) return spj();
  if (v[1].back() <= 0) return -1;
  // if (v[1].size() == 1) return (m+v[1][0]-1)/v[1][0];
  ll val = v[1].front()+v[1].back();
  for (int i = 1; i+1 < (int)v[1].size(); ++i) {
    val += v[1][i];
    if (val < 0) return -1;
  }
  ll x = 0, mx = 0;
  for (int i : v[0]) {
    x += i;
    mx = max(x, mx);
  }
  return 2+(m-mx-v[1].back()+val-1)/val;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}