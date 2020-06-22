/*
 * @Author: Kaizyn
 * @Date: 2020-06-11 22:32:07
 * @LastEditTime: 2020-06-11 23:45:25
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
const int M = 1e7+7;

struct Euler {
  int tot = 0;
  int prime[M];
  bool check[M];
  bool& operator [] (const int i) { return check[i]; }
  void init(int sz) {
    tot = 0;
    for (int i = 1; i <= sz; ++i) check[i] = true;
    check[1] = false;
    for (register int i = 2, j; i <= sz; ++i) {
      if (check[i]) prime[++tot] = i;
      for (j = 1; j <= tot && i*prime[j] <= sz; ++j) {
        check[i*prime[j]] = false;
        if (i%prime[j] == 0) break;
      }
    }
  }
} E;

int n;
int a[N];
int d[2][N];

inline bool is_prime(long long x) {
  if(x == 1) return false;
  if(x == 2 || x == 3) return true;
  if(x%6 != 1 && x%6 != 5) return false;
  for(long long i = 5; i*i <= x; i += 6)
    if(x%i == 0 || x%(i+2) == 0) return false;
  return true;
}

inline int get_fac(const int &x) {
  if (is_prime(x)) return x;
  for (int i = 1; i <= E.tot && E.prime[i]*E.prime[i] <= x; ++i) {
    if (x%E.prime[i] == 0) return E.prime[i];
  }
  return x;
}

inline void solve() {
  cin >> n;
  for (int i = 1, x, y, f; i <= n; ++i) {
    cin >> a[i];
    x = a[i]; y = 1;
    f = get_fac(x); // 找最小一个
    while (x%f == 0) x /= f, y *= f;
    if (x == 1 || y == 1) d[0][i] = d[1][i] = -1;
    else d[0][i] = x, d[1][i] = y;
  }
  for (int i = 1; i <= n; ++i) cout << d[0][i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << d[1][i] << " \n"[i==n];
  /*
  for (int i = 2, x, y, f; i <= 100000; ++i) {
    x = i; y = 1;
    f = get_fac(x);
    while (x%f == 0) x /= f, y *= f;
    if (y == 1 || x == 1) continue;
    if (__gcd(x+y, i) != 1) {
      cout << i << " " << x << " " << y << endl;
    }
  }
  cout << "OK" << endl;
  */
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  E.init(10000000);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}