/*
 * @Author: Kaizyn
 * @Date: 2021-07-14 14:40:14
 * @LastEditTime: 2021-07-14 14:56:19
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
const int N = 5e5+7;

struct Node {
  int x, y;
};

int n;
Node a[N];

inline ll dis(int i, int j) {
  return ll(a[i].x-a[j].x)*(a[i].x-a[j].x)+ll(a[i].y-a[j].y)*(a[i].y-a[j].y);
}

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  int k = 1;
  for (int j = 2; j < n; ++j) {
    if (dis(0, j) > dis(0, k)) k = j;
  }
  const int t = 10;
  for (int i = 0, j = k; i < n; ++i) {
    k = i;
    for (int l = j-t, p; l <= j+t; ++l) {
      p = (l%n+n)%n;
      if (dis(i, p) > dis(i, k) || (dis(i, p) == dis(i, k) && p < k)) {
        k = p;
      }
    }
    cout << (j=k)+1 << '\n';
  }
  /*
  int k = 0;
  ll d = 0, tmp;
  for (int j = 1; j < n; ++j) {
    tmp = dis(0, j);
    if (tmp > d) {
      d = tmp;
      k = j;
    }
  }
  const int t = 10;
  for (int i = 0, j = k; i < n; ++i) {
    d = 0; k = n;
    for (int l = j-t, p; l <= j+t; ++l) {
      p = (l%n+n)%n;
      tmp = dis(i, p);
      if (tmp > d || (tmp == d && p < k)) {
        d = tmp;
        k = p;
      }
    }
    cout << (j=k)+1 << '\n';
  }
  */
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