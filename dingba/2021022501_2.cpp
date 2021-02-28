/*
 * @Author: Kaizyn
 * @Date: 2021-02-25 19:54:46
 * @LastEditTime: 2021-02-25 20:08:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e3+7;

const int shit[] = {
0b1110111,
0b0100100,
0b1011101,
0b1011011,
0b0111010,
0b1101011,
0b1101111,
0b1010010,
0b1111111,
0b1111011,
0b0010010
};

int magic[N][N]; // magic[i][j] turn i to j
int cnt2[5][N];

int cnt(int x) {
  if (x < 10) return 1;
  if (x < 100) return 2;
  return 3;
}

int init2(int x, int y) {
  int res = 0;
  for (int _ = cnt(x), t = 1; _; --_, t *= 10) {
    res += magic[x/t%10][y/t%10];
  }
  return res;
}

void init() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < i; ++j) {
      magic[j][i] = magic[i][j] = __builtin_popcount(shit[i]^shit[j]);
    }
  }
  for (int i = 0; i < 10; ++i) {
    magic[1][i] = magic[i][1] = min(magic[1][i], __builtin_popcount(shit[10]^shit[i]));
  }
  for (int i = 10; i < 1000; ++i) {
    for (int j = 0; j < i; ++j) {
      magic[i][j] = magic[j][i] = init2(i, j);
    }
  }
  for (int i = 0; i < 1000; ++i) {
    for (int _ = cnt(i), t = 1; _; --_, t *= 10) {
      cnt2[cnt(i)][i] += __builtin_popcount(shit[i/t%10]);
    }
    for (int j = cnt(i)+1; j <= 3; ++j) {
      cnt2[j][i] = cnt2[j-1][i]+cnt2[1][0];
    }
  }
}

inline void solve() {
  init();
  int a, b, c;
  cin >> a >> b >> c;
  // assert(a >= 0 && a < 1000);
  // assert(b >= 0 && b < 1000);
  // assert(c >= 0 && c < 1000);
  int sum = cnt2[cnt(a)][a]+cnt2[cnt(b)][b]+cnt2[cnt(c)][c];
  int res = sum*2;
  for (int i = 0; i < 1000; ++i) if (cnt(i) <= cnt(a))
  for (int j = 0; j < 1000-i; ++j) if (cnt(j) <= cnt(b)) {
    int k = i+j;
    if (cnt(k) > cnt(c)) continue;
    if (cnt2[cnt(a)][i]+cnt2[cnt(b)][j]+cnt2[cnt(c)][k] != sum) continue;
    #ifdef DEBUG
    cout << i << " " << j << " " << k << " " << magic[a][i]+magic[b][j]+magic[c][k] << '\n';
    #endif
    /*
    assert(a >= 0 && a < 1000);
    assert(b >= 0 && b < 1000);
    assert(c >= 0 && c < 1000);
    assert(i >= 0 && i < 1000);
    assert(j >= 0 && j < 1000);
    assert(k >= 0 && k < 1000); // RE here
    */
    res = min(res, magic[a][i]+magic[b][j]+magic[c][k]);
  }
  cout << res/2 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
881 7 3
*/