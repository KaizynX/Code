/*
 * @Author: Kaizyn
 * @Date: 2020-09-28 00:19:55
 * @LastEditTime: 2020-09-28 00:34:32
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n;
BinaryIndexedTree<int> BIT;
int a[N], b[N], c[N];

long long inversion(int *arr) {
  static int d[N], rk[N];
  memcpy(d+1, arr+1, sizeof(int)*n);
  sort(d+1, d+n+1);
  int m = unique(d+1, d+n+1)-d;
  for (int i = 1; i <= n; ++i) rk[i] = i;
  sort(rk+1, rk+n+1, [&](int x, int y) {
    return arr[x] < arr[y];
  });
  for (int _ = 1, i, j = 1; _ <= n; ++_) {
    i = rk[_];
    while (d[j] < arr[i]) ++j;
    arr[i] = j;
  }
  BIT.init(m);
  long long res = 0;
  for (int i = n; i; --i) {
    res += BIT.query(arr[i]-1);
    BIT.add(arr[i], 1);
  }
  return res;
}

inline void solve() {
  scanf("%d", &n);
  int x = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int bit = 30; bit >= 0; --bit) {
    for (int i = 1; i <= n; ++i) c[i] = b[i]*2+((a[i]>>bit)&1);
    long long c0 = inversion(c);
    for (int i = 1; i <= n; ++i) c[i] = b[i]*2+(((a[i]>>bit)&1)^1);
    long long c1 = inversion(c);
    if (c0 <= c1) {
      for (int i = 1; i <= n; ++i) b[i] = b[i]*2+((a[i]>>bit)&1);
    } else {
      x += 1<<bit;
      for (int i = 1; i <= n; ++i) b[i] = b[i]*2+(((a[i]>>bit)&1)^1);
    }
  }
  cout << inversion(b) << " " << x << endl;
}

signed main() {
  solve();
  return 0;
}