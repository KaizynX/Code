/*
 * @Author: Kaizyn
 * @Date: 2021-07-22 23:16:25
 * @LastEditTime: 2021-07-23 13:13:08
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
const int N = 3e5+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n, m;
int a[N], cnt[N];
vector<int> res;
DSU dsu;

bool check(int k) {
  dsu.init(n);
  for (int i = 0; i < n; ++i) {
    dsu.merge((i-k+n)%n, a[i]);
  }
  int c = 0;
  for (int i = 0; i < n; ++i) {
    c += dsu[i] == i;
  }
  return n-c <= m;
}

inline void solve() {
  res.clear();
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    // (i-k)%n == a[i]
    ++cnt[(i-a[i]+n)%n];
  }
  for (int i = 0; i < n; ++i) if (cnt[i] >= n-2*m) {
    if (check(i)) res.emplace_back(i);
  }

  cout << res.size();
  for (int i : res) cout << ' ' << i;
  cout << '\n';
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