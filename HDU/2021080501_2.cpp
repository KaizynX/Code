/*
 * @Author: Kaizyn
 * @Date: 2021-08-05 12:47:34
 * @LastEditTime: 2021-08-05 13:31:32
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
const int N = 2e7+40;
// const int N = 10000019+10;

int x;
int L[N], R[N];

struct Euler {
  int tot;
  int prime[N];
  bool check[N];
  bool operator [](const int &i) { return check[i]; }
  void init(int n) {
    tot = 0;
    fill(check+2, check+n+1, 1);
    for (int i = 2; i <= n; ++i) {
      if (check[i]) prime[++tot] = i;
      for (int j = 1; j <= tot && i*prime[j] <= n; ++j) {
        check[i*prime[j]] = false;
        if (i%prime[j] == 0) break;
      }
    }
  }
} E;

void init() {
  E.init(N-1);
  int last = 0;
  for (int i = 10000019; i; ++i) {
    if (E[i]) {
      last = i;
      L[i] = R[i] = i;
      break;
    } else if (E[i+i-1]) {
      L[i] = i-1;
      R[i] = i+1;
      last = i;
      break;
    } else if (E[i+i+1]) {
      L[i] = i;
      R[i] = i+1;
      last = i;
      break;
    }
  }
  for (int i = 1e7+18; i; --i) {
    if (E[i]) {
      last = i;
      L[i] = R[i] = i;
    } else if (E[i+i-1]) {
      L[i] = i-1;
      R[i] = i;
      last = i;
    } else if (E[i+i+1]) {
      L[i] = i;
      R[i] = i+1;
      last = i;
    } else {
      L[i] = -L[last]+1;
      R[i] = R[last];
    }
  }
}

void print(int x) {
  printf("%d(%d,%d)\n", x, L[x], R[x]);
}

inline void solve() {
  scanf("%d", &x);
  if (x == 0) return puts("3"), void();
  if (x > 0) return printf("%d\n", R[x]-L[x]+1), void();
  int l, r;
  for (int i = 1; i; ++i) {
    if (L[-x+i] == -x) continue;
    l = L[-x+i]; r = R[-x+i];
    break;
  }
  // int l = L[-x+1], r = R[-x+1];
  // if (l == -x) l = L[-x+2], r = R[-x+2];
  if (l >= 0) l = -l+1;
  printf("%d\n", r-l+1);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  init();
  int T = 1;
  // print(97);
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}