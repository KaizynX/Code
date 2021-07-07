/*
 * @Author: Kaizyn
 * @Date: 2021-07-07 23:24:57
 * @LastEditTime: 2021-07-07 23:38:50
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
const int N = 2e5+7;

int n, k;

struct Node {
  vector<int> v;
  Node() {}
  Node(int x) {
    v.clear();
    while (x) {
      v.emplace_back(x%k);
      x /= k;
    }
  }
  Node& operator +=(const Node &b) {
    for (int i = 0; i < (int)min(v.size(), b.v.size()); ++i)
      v[i] = (v[i]+b.v[i])%k;
    if (v.size() < b.v.size())
      v.insert(v.end(), b.v.begin()+v.size(), b.v.end());
    return *this;
  }
  Node operator +(const Node &b) const { Node x = *this; return x += b; }
  Node &operator -=(const Node &b) {
    for (int i = 0; i < (int)min(v.size(), b.v.size()); ++i)
      v[i] = (v[i]-b.v[i]+k)%k;
    for (int i = v.size(); i < (int)b.v.size(); ++i) {
      v.emplace_back(b.v[i] == 0 ? 0 : k-b.v[i]);
    }
    return *this;
  }
  Node operator -(const Node &b) const { Node x = *this; return x -= b; }
  friend ostream& operator <<(ostream &os, const Node &nd) {
    int x = 0;
    for (auto it = nd.v.rbegin(); it != nd.v.rend(); ++it) {
      x = x*k+*it;
    }
    return os << x;
  }
};

inline void solve() {
  cin >> n >> k;
  Node s = 0, y;
  for (int i = 0, r; i < n; ++i) {
    if (i&1) y = s-Node(i);
    else y = s+Node(i);
    cout << y << endl;
    cin >> r;
    if (r) return;
    s = y-s;
  }
}
/*
x
y0-x
y1-y0+x
y2-y1+y0-x
*/

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