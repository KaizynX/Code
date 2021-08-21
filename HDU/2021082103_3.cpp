/*
 * @Author: Kaizyn
 * @Date: 2021-08-21 14:05:17
 * @LastEditTime: 2021-08-21 14:22:14
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
const int N = 1e2+7;

struct Node {
  int curt, step, curv, id;
  bool operator <(const Node &b) const {
    return step > b.step;
  }
};

int n, m;
int a[N], t[N];

Node get_nex(Node x) {
  x.curt += x.step;
  x.step = x.curt;
  if (--x.curv < 0) return x.id = -1, x;
  while (x.step <= t[x.id] && (a[x.id]+x.step-1)/x.step > x.curv) ++x.step;
  if (x.step > t[x.id]) x.id = -1;
  x.step -= x.curt;
  return x;
}

inline void solve() {
  priority_queue<Node> q;
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ans += a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    Node x = get_nex(Node{1, 0, a[i], i});
    if (~x.id) q.push(x);
  }
  while (q.size()) {
    Node x = q.top();
    q.pop();
    if (m < x.step) break;
    m -= x.step;
    --ans;
    x = get_nex(x);
    if (~x.id) q.push(x);
  }
  cout << ans << '\n';
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