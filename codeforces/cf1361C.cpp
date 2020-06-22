/*
 * @Author: Kaizyn
 * @Date: 2020-06-11 17:52:31
 * @LastEditTime: 2020-06-11 21:58:20
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

struct Node {
  int a, b;
  friend istream& operator >>(istream &is, Node &nd) {
    return is >> nd.a >> nd.b;
  }
};

int n;
int a[N], b[N];
Node c[N];

bool check(const int &x) {
  for (int i = 1, indeg, otdeg; i <= n; ++i) {
    // a^b >= 1<<x
    // a >= (1<<x)^b, b >= (1<<x)^a
    indeg = upper_bound(b+1, b+n+1, c[i].a)-lower_bound(b+1, b+n+1, c[i].a);
    indeg += n+1-(lower_bound(b+1, b+n+1, (1<<x)^c[i].b)-b);
    // indeg -= (c[i].a^c[i].b) >= (1<<x) || c[i].a == c[i].b;
    otdeg = upper_bound(a+1, a+n+1, c[i].a)-lower_bound(a+1, a+n+1, c[i].b);
    otdeg += n+1-(lower_bound(a+1, a+n+1, (1<<x)^c[i].a)-a);
    // otdeg -= (c[i].a^c[i].b) >= (1<<x) || c[i].a == c[i].b;
    if (indeg != otdeg) return false;
  }
  return true;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    c[i] = {a[i], b[i]};
  }
  sort(a+1, a+n+1);
  sort(b+1, b+n+1);
  int l = 1, r = 20;
  while (l < r) {
    int mid = (l+r+1)>>1;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}