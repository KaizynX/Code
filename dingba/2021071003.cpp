/*
 * @Author: Kaizyn
 * @Date: 2021-07-10 13:41:40
 * @LastEditTime: 2021-07-10 14:07:30
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

struct Node {
  int xl, xr, yl, yr;
  Node(){}
  Node(int _xl, int _xr, int _yl, int _yr) : xl(_xl), xr(_xr), yl(_yl), yr(_yr) {}
  bool check() {
    return xl <= xr && yl <= yr;
  }
  bool is_point() {
    return xl == xr && yl == yr;
  }
  bool is_int() {
    return (xl+xr)%2 == 0;
  }
  bool operator <(const Node &b) const {
    return vector<int>{xl, xr, yl, yr} < vector<int>{b.xl, b.xr, b.yl, b.yr};
  }
  bool operator ==(const Node &b) const {
    return vector<int>{xl, xr, yl, yr} == vector<int>{b.xl, b.xr, b.yl, b.yr};
  }
  Node operator &(const Node &b) const {
    return Node(
        max(xl, b.xl),
        min(xr, b.xr),
        max(yl, b.yl),
        min(yr, b.yr)
    );
  }
  #ifdef DEBUG
  friend ostream& operator <<(ostream &os, const Node &nd) {
    return os << '(' << nd.xl << ',' << nd.xr
        << ") (" << nd.yl << ',' << nd.yr << ")\n";
  }
  #endif
};

int n;
int x[N], y[N], d[N];
vector<Node> a[N];

void my_unique(vector<Node> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

vector<Node> cross(vector<Node> &v1, vector<Node> &v2) {
  vector<Node> v;
  Node tmp;
  for (auto &n1 : v1) for (auto &n2 : v2) {
    tmp = n1&n2;
    if (!tmp.check()) continue;
    if (tmp.is_point() && !tmp.is_int()) continue;
    v.emplace_back(tmp);
  }
  my_unique(v);
  return v;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i] >> d[i];
    x[i] = x[i]+y[i];
    y[i] = x[i]-2*y[i];
    a[i].emplace_back(Node(x[i]-d[i], x[i]-d[i], y[i]-d[i], y[i]+d[i]));
    a[i].emplace_back(Node(x[i]+d[i], x[i]+d[i], y[i]-d[i], y[i]+d[i]));
    a[i].emplace_back(Node(x[i]-d[i], x[i]+d[i], y[i]-d[i], y[i]-d[i]));
    a[i].emplace_back(Node(x[i]-d[i], x[i]+d[i], y[i]+d[i], y[i]+d[i]));
    my_unique(a[i]);
  }
  vector<Node> res = a[1];
  for (int i = 2; i <= n; ++i) {
    res = cross(res, a[i]);
    #ifdef DEBUG
    cout << i << ":\n";
    for (auto &j : res) cout << j;
    #endif
    if (res.empty()) break;
  }
  if (res.empty()) cout << "impossible\n";
  else if (res.size() > 1 || !res.back().is_point()) cout << "uncertain\n";
  else {
    int xx = res.back().xl, yy = res.back().yl;
    cout << (xx+yy)/2 << ' ' << (xx-yy)/2 << '\n';
  }
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