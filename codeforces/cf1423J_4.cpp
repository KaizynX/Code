/*
 * @Author: Kaizyn
 * @Date: 2020-12-26 20:20:01
 * @LastEditTime: 2020-12-26 20:25:28
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e2+7;

template <typename T> inline void read(T &x) {
  int c;
  while(!isdigit((c=getchar()))) {}
  x = c-'0';
  while(isdigit((c=getchar()))) x = (x<<1)+(x<<3)+c-'0';
}

template <typename T> void write(T x) {
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

ll m;
int cnt[2][8][8], l[2][8], r[2][8];
int sum[2][10];

inline void init() {
  for (int i = 0; i < 7; ++i) { // last is i
    for (int j = 0; j < 8; ++j) { // now choose j
      assert((i+1)>>1 < 7);
      ++cnt[(i+j)&1][(i+j)>>1][i];
    }
  }
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < 7; ++i) {
      l[k][i] = 8; r[k][i] = -1;
      for (int j = 0; j < 7; ++j) if (cnt[k][i][j]) {
        l[k][i] = min(l[k][i], j);
        r[k][i] = max(r[k][i], j);
      }
    }
  }
}

inline void solve() {
  read(m);
  fill(sum[0]+1, sum[0]+8, 1);
  int i;
  for (i = 0; 1ll<<i <= m; ++i) {
    int *pre = sum[i&1], *nex = sum[~i&1], b = (m>>i)&1;
    for (int j = 0; j < 7; ++j) {
      nex[j+1] = nex[j]+pre[r[b][j]+1]-pre[l[b][j]];
      if (nex[j+1] >= MOD) nex[j+1] -= MOD;
      else if (nex[j+1] < 0) nex[j+1] += MOD;
    }
  }
  write(sum[i&1][1]);
  putchar('\n');
}

signed main() {
  init();
  int T;
  read(T);
  while (T--) solve();
  return 0;
}