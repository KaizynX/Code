/*
 * @Author: Kaizyn
 * @Date: 2020-08-17 00:12:05
 * @LastEditTime: 2020-08-17 00:30:48
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 25+5;

int n;
long long a[N][N];

void build() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i&1) a[i][j] = 1ll<<(i+j);
      // int s = (i+j);
      // a[i][j] = 1ll<<(s+i%2);
      cout << a[i][j] << " \n"[j==n-1];
    }
  }
  cout.flush();
}

void answer(long long k) {
  cout << "1 1\n";
  int x = 0, y = 0;
  for (int i = 1; i < 2*n-1; ++i) {
    // k >>= 2;
    // int r = k%4; // r == 1 || 2
    // if (r%2 == x%2) ++x;
    k >>= 1;
    if (k%2 != x%2) ++x;
    else ++y;
    cout << x+1 << " " << y+1 << "\n";
  }
  cout.flush();
}

inline void solve() {
  cin >> n;
  build();
  int q;
  long long k;
  cin >> q;
  while (q--) {
    cin >> k;
    answer(k);
  }
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