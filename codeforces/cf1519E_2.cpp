/*
 * @Author: Kaizyn
 * @Date: 2021-04-29 23:56:54
 * @LastEditTime: 2021-04-30 00:14:05
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
typedef pair<ll, ll> pll;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
int use[N], rk[N<<1];
Node p[N];
vector<pll> dis;
vector<int> pset[N<<1], res[N<<1];

inline pll magic(ll a, ll b, ll c, ll d) {
  a *= d;
  b *= c;
  ll g = __gcd(a, b);
  return pll{a/g, b/g};
}

inline int lb(pll v) {
  return lower_bound(dis.begin(), dis.end(), v)-dis.begin()+1;
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

void shuffle(int a[], int n) {
  for (int i = 1; i <= n; ++i) {
    swap(a[i], a[rnd()%i+1]);
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1, a, b, c, d; i <= n; ++i) {
    cin >> a >> b >> c >> d;
    p[i] = Node{a, b, c, d};
    dis.emplace_back(magic(a+b, b, c, d));
    dis.emplace_back(magic(a, b, c+d, d));
  }
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  for (int i = 1, a, b, c, d; i <= n; ++i) {
    tie(a, b, c, d) = p[i];
    pset[lb(magic(a+b, b, c, d))].emplace_back(i);
    pset[lb(magic(a, b, c+d, d))].emplace_back(i);
  }
  memset(use, -1, sizeof use);
  iota(rk+1, rk+(int)dis.size()+1, 1);
  shuffle(rk, dis.size());
  int tot = 0;
  for (int _ = 1, i, cnt; _ <= (int)dis.size(); ++_) {
    i = rk[_];
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