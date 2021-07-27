/*
 * @Author: Kaizyn
 * @Date: 2021-07-27 12:28:07
 * @LastEditTime: 2021-07-27 13:13:12
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
const int N = 1e5+7;

int f(char c) {
  if (c >= '0' && c <= '9') return c-'0';
  return c-'A'+10;
}

char f(int x) {
  if (x <= 9) return '0'+x;
  return x-10+'A';
}

struct Node {
  int c[3];
  Node operator +(const Node &b) const {
    Node res;
    for (int i = 0; i < 3; ++i) {
      res.c[i] = c[i]+b.c[i];
    }
    return res;
  }
  Node operator -(const Node &b) const {
    Node res;
    for (int i = 0; i < 3; ++i) {
      res.c[i] = c[i]-b.c[i];
    }
    return res;
  }
  void print() {
    for (int i = 0; i < 3; ++i) {
      c[i] = min(c[i], 255);
      putchar(f(c[i]/16));
      putchar(f(c[i]%16));
    }
    putchar('\n');
  }
};

int n, q;
Node a[N], s[N];
char str[N];
set<int> st;

inline void solve() {
  // cin >> n >> q;
  scanf("%d%d", &n, &q);
  // string str;
  st.clear();
  st.insert(0);
  st.insert(n+1);
  for (int i = 1, m; i <= n; ++i) {
    // cin >> m >> str;
    scanf("%d%s", &m, str);
    for (int j = 0; j < 3; ++j) {
      a[i].c[j] = f(str[j*2])*16+f(str[j*2+1]);
    }
    if (m == 1) st.insert(i);
    s[i] = s[i-1]+a[i];
  }
  for (int i = 1, l, r; i <= q; ++i) {
    // cin >> l >> r;
    scanf("%d%d", &l, &r);
    auto it = st.upper_bound(r);
    l = max(l, *(--it));
    Node res = s[r]-s[l-1];
    res.print();
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}