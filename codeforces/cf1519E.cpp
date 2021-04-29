/*
 * @Author: Kaizyn
 * @Date: 2021-04-29 23:01:08
 * @LastEditTime: 2021-04-29 23:54:51
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;
typedef tuple<int, int, int, int> Node;

int n;
int use[N];
Node p[N];
vector<Node> dis;
vector<int> pset[N<<1], res[N<<1];

inline int lb(int a, int b, int c, int d) {
  return lower_bound(dis.begin(), dis.end(), Node{a, b, c, d})-dis.begin()+1;
}

inline void reuse(int i) {
  int j = use[i];
  for (int &k : pset[j]) {
    if (k == i) {
      use[k] = -1;
    } else if (use[k] == j) {
      use[k] = 0;
      res[j].emplace_back(k);
    }
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1, a, b, c, d, g; i <= n; ++i) {
    cin >> a >> b >> c >> d;
    p[i] = Node{a, b, c, d};
    g = __gcd(a, b);
    a /= g; b /= g;
    g = __gcd(c, d);
    c /= g; d /= g;
    dis.emplace_back(Node{a+b, b, c, d});
    dis.emplace_back(Node{a, b, c+d, d});
  }
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  for (int i = 1, a, b, c, d; i <= n; ++i) {
    tie(a, b, c, d) = p[i];
    pset[lb(a+b, b, c, d)].emplace_back(i);
    pset[lb(a, b, c+d, d)].emplace_back(i);
  }
  memset(use, -1, sizeof use);
  int tot = 0;
  for (int i = 1, cnt; i <= (int)dis.size(); ++i) {
    #ifdef DEBUG
    cout << i << ":";
    for (auto &j : pset[i]) {
      printf("(%d,%d)", j, use[j]);
    }
    cout << '\n';
    #endif
    cnt = 0;
    for (int &j : pset[i]) {
      if (use[j] > 0) reuse(j);
      if (use[j] == -1) ++cnt;
    }
    tot += cnt/2;
    if (cnt&1) {
      for (int &j : pset[i]) {
        if (use[j] == -1) use[j] = i;
      }
    } else {
      for (int &j : pset[i]) {
        if (use[j] == -1) {
          use[j] = 0;
          res[i].emplace_back(j);
        }
      }
    }
  }
  cout << tot << endl;
  for (int i = 1; i <= (int)dis.size(); ++i) {
    for (int j = 0; j < (int)res[i].size(); j += 2) {
      cout << res[i][j] << ' ' << res[i][j+1] << '\n';
    }
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