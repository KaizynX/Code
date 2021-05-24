/*
 * @Author: Kaizyn
 * @Date: 2021-05-15 22:37:23
 * @LastEditTime: 2021-05-15 23:16:47
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 13+7;

int n, res;
int a[N], vis[N];

struct Node {
  int a[N], aa, b[N], bb;
  void init() {
    aa = bb = 0;
  }
  int size() const { return aa; }
  void insert(int x) {
    while (aa && a[aa] < x) {
      b[++bb] = a[aa--];
    }
    a[++aa] = x;
  }
  void undo(int t) {
    --aa;
    while (t--) a[++aa] = b[bb--];
  }
} stk;

void dfs(int x) {
  if (x > n) return ++res, void();
  for (int i = 1, t1, t2; i <= n; ++i) if (!vis[i]) {
    t1 = stk.size();
    stk.insert(i);
    t2 = stk.size();
    if (t2 == a[x]) {
      vis[i] = 1;
      dfs(x+1);
      vis[i] = 0;
    }
    stk.undo(t1+1-t2);
  }
}

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  memset(vis, 0, sizeof vis);
  stk.init();
  res = 0;
  dfs(1);
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    auto res = solve();
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}