/*
 * @Author: Kaizyn
 * @Date: 2020-08-09 21:19:21
 * @LastEditTime: 2020-08-09 22:14:45
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, l, k;
int a[N], b[N], c[N];
multiset<int> s1, s2;

inline void insert(const int &x) {
  if (x >= *s2.begin()) s2.insert(x);
  else s1.insert(x);
  while ((int)s2.size() > k) {
    s1.insert(*s2.begin());
    s2.erase(s2.begin());
  }
  while ((int)s2.size() < k) {
    s2.insert(*s1.rbegin());
    s1.erase(--s1.end());
  }
}

inline void erase(const int &x) {
  auto it = s1.find(x);
  if (it != s1.end()) s1.erase(it);
  else s2.erase(s2.find(x));
}

inline long long calc() {
  s1.clear(); s2.clear();
  for (int i = 1; i < l; ++i) s2.insert(b[i]);
  insert(b[l]);
  long long res = *s2.begin();
  for (int i = l+1; i <= n; ++i) {
    erase(b[i-l]);
    insert(b[i]);
    res += *s2.begin();
  }
  return res;
}

inline void build() {
  for (int i = 1, lp = 0, rp = n+1; i <= n; ) {
    for (int _ = 1; _ <= l-k && i <= n; ++_)
      b[i++] = a[++lp];
    for (int _ = 1, j = min(n, i+k-1); _ <= k && i <= j; ++_)
      b[j--] = a[--rp];
    i += k;
  }
  /*
  int lp = 0, rp = n+1;
  int i = 1, j = n;
  */
  /*
  for (i = 1, j = n; i < l && i <= j; ++i, --j) {
    b[i] = a[++lp];
    if (i != j) b[j] = a[++lp];
  }
  */
  /*
  for ( ; i <= j; ) {
    for (int o = 1; o <= l-k && i <= j; ++o) {
      b[i++] = a[++lp];
    }
    for (int o = 1; o <= k && i <= j; ++o) {
      b[i++] = a[--rp];
    }
  }
  */
  /*
  while (i <= j) {
    b[i++] = a[--rp];
    if (i > j) break;
    b[j--] = a[--rp];
    if (i > j) break;
    b[i++] = a[++lp];
    if (i > j) break;
    b[j--] = a[++lp];
  }
  */
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << b[i] << " \n"[i==n];
  }
  cout.flush();
#endif
}

inline void solve() {
  cin >> n >> l >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  build();
  cout << calc() << " ";
  reverse(a+1, a+n+1);
  build();
  cout << calc() << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}