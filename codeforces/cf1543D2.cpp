/*
 * @Author: Kaizyn
 * @Date: 2021-07-07 22:46:05
 * @LastEditTime: 2021-07-07 23:24:50
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
  Node& operator ^=(Node b) {
    for (int i = 0; i < (int)min(v.size(), b.v.size()); ++i) {
      v[i] = (v[i]+b.v[i])%k;
    }
    if (v.size() < b.v.size()) v.insert(v.end(), b.v.begin()+v.size(), b.v.end());
    return *this;
  }
  Node operator ^(Node b) const { Node x = *this; return x ^= b; }
  /*
  Node operator ^(Node &b) const {
    Node x;
    for (int i = 0; i < (int)min(v.size(), b.v.size()); ++i) {
      x.v.emplace_back((v[i]+b.v[i])%k);
    }
    if (v.size() < b.v.size()) x.v.insert(b.v.begin()+v.size(), b.v.end());
    if (v.size() > b.v.size()) x.v.insert(v.begin()+b.v.size(), v.end());
    return x;
  }
  */
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
  Node x = 0;
  for (int i = 0, y; i < n; ++i) {
    cout << (x^Node(i)) << endl;
    cin >> y;
    if (y) return;
    x ^= x^Node(i);
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