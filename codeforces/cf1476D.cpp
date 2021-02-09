/*
 * @Author: Kaizyn
 * @Date: 2021-02-04 15:34:56
 * @LastEditTime: 2021-02-04 16:09:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 6e5+7;

struct DSU {
  int fa[N], num[N];
  void init(int n) { for (int i = 0; i <= n; ++i) fa[i] = i, num[i] = 1; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) {
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    if (num[fx] >= num[fy]) num[fx] += num[fy], fa[fy] = fx;
    else num[fy] += num[fx], fa[fx] = fy;
    return true;
  }
};

int n;
string s;
DSU dsu;

inline void solve() {
  cin >> n >> s;
  dsu.init(n*2+1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      dsu.merge((i+1)<<1, i<<1|1);
    } else if (s[i] == 'R') {
      dsu.merge(i<<1, (i+1)<<1|1);
    }
  }
  for (int i = 0; i <= n; ++i) {
    cout << dsu.num[dsu[i<<1]] << " \n"[i==n];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}