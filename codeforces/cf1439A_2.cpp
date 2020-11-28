/*
 * @Author: Kaizyn
 * @Date: 2020-11-17 23:31:28
 * @LastEditTime: 2020-11-18 00:39:38
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n, m;
int a[N][N], f[1<<4], rf[1<<4];
vector<vector<pii>> res;

void init() {
  for (int i = 0; i < 1<<4; ++i) {
    f[i] = 0;
    for (int j = 0; j < 4; ++j) if ((i>>j)&1) {
      for (int k = 0; k < 4; ++k) if (j != k) {
        f[i] ^= 1<<k;
      }
    }
    rf[f[i]] = i;
  }
}

int code(int x, int y) {
  int res = 0;
  if (a[x][y]) res |= 1;
  if (a[x+1][y]) res |= 2;
  if (a[x][y+1]) res |= 4;
  if (a[x+1][y+1]) res |= 8;
  return res;
}

void fuck(int x, int y, int ope) {
  static vector<pii> cur;
  for (int k = 0; k < 4; ++k) if (ope>>k&1) {
    cur.clear();
    for (int i = x; i <= x+1; ++i) {
      for (int j = y; j <= y+1; ++j) {
        if (k == 0 && i == x && j == y) continue;
        if (k == 1 && i == x+1 && j == y) continue;
        if (k == 2 && i == x && j == y+1) continue;
        if (k == 3 && i == x+1 && j == y+1) continue;
        cur.emplace_back(i, j);
        a[i][j] ^= 1;
      }
    }
    res.emplace_back(cur);
  }
}


void ope(int x, int y, int xx, int yy) {
  static vector<pii> cur;
  cur.clear();
  for (int i = x; i <= x+1; ++i) {
    for (int j = y; j <= y+1; ++j) {
      if (i == xx && j == yy) continue;
      cur.emplace_back(i, j);
      a[i][j] ^= 1;
    }
  }
  res.emplace_back(cur);
}

inline void solve() {
  res.clear();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    static string s;
    cin >> s;
    for (int j = 1; j <= m; ++j) {
      a[i][j] = s[j-1]-'0';
    }
  }
  for (int i = 1; i < n-1; ++i) {
    if (a[i][1]) ope(i, 1, i, 2);
    for (int j = 2; j <= m; ++j) {
      if (a[i][j]) ope(i, j-1, i, j-1);
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
  #endif
  if (m&1) {
    // cout << bitset<4>(code(n-1, m-2)) << " "
        // << bitset<4>(code(n-1, m-1)) << endl;
    for (int f1 = 0, flag = 1; flag && f1 < 1<<4; ++f1) {
      for (int f2 = 0; flag && f2 < 1<<4; ++f2) {
        int r = f[f1]^(f[f2]<<2);
        int t = __builtin_popcount(f1)+__builtin_popcount(f2);
        if (t > 6) continue;
        int c = code(n-1, m-2)|(code(n-1, m-1)<<2);
        if (c == r) {
          flag = 0;
          fuck(n-1, m-2, f1);
          fuck(n-1, m-1, f2);
          #ifdef DEBUG
          cout << bitset<4>(f1) << " " << bitset<4>(f2) << " "
              << bitset<6>(r) << " " << bitset<6>(c) << endl;
          #endif
        }
      } 
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
  #endif
  for (int i = 1; i+1 <= m; i += 2) {
    fuck(n-1, i, rf[code(n-1, i)]);
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
  #endif
  assert((int)res.size() <= n*m);
  cout << res.size() << endl;
  for (auto &cur : res) {
    for (auto &p : cur) {
      cout << p.first << " " << p.second << " ";
    }
    cout << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  init();
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}