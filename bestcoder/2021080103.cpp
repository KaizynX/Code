/*
 * @Author: Kaizyn
 * @Date: 2021-08-01 14:15:40
 * @LastEditTime: 2021-08-01 14:50:47
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
const int N = 1e3+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : fa[x] = y, true;
  }
};

int n, s;
int deg[N], flag[N];
vector<int> v[N];
char a[N][N];
DSU dsu;

inline int solve() {
  cin >> n >> s;
  dsu.init(n);
  for (int i = 1; i <= n; ++i) {
    deg[i] = flag[i] = 0;
    v[i].clear();
  }
  int sum = 0;
  for (int i = 2; i <= n; ++i) {
    cin >> (a[i]+1);
    for (int j = 1; j < i; ++j) {
      if (a[i][j] == '1') continue;
      ++sum;
      dsu.merge(i, j);
      ++deg[i];
      ++deg[j];
    }
  }
  if (sum == 0) return 0;
  for (int i = 1; i <= n; ++i) {
    v[dsu[i]].emplace_back(i);
  }
  int cnt = 0, ce2 = 0;
  for (int i = 1; i <= n; ++i) if (v[i].size() > 1) {
    ++cnt;
    int ce = 0;
    for (int j : v[i]) ce += deg[j]&1;
    if (ce == 0) {
      ;
    } else if (ce == 2) {
      ++ce2;
      flag[i] = 1;
    } else {
      return -1;
    }
  }
  if (ce2 > 1) return -1;
  if (ce2 && !flag[dsu[s]]) return -1;
  if (flag[dsu[s]] && deg[s]%2 == 0) return -1;
  if (v[dsu[s]].size() == 1u) ++cnt;
  return sum+(cnt-1)*2;
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
/*
4 1
0
10
101

3 1
0
10

3 2
0
10

3 1
1
11

4 4
0
00
111
*/