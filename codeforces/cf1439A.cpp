/*
 * @Author: Kaizyn
 * @Date: 2020-11-17 22:32:04
 * @LastEditTime: 2020-11-17 23:53:56
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
int a[N][N], f[1<<4];
vector<vector<pii>> res;

void init() {
  #ifdef DEBUG
  static int vis[1<<4];
  memset(vis, 0, sizeof vis);
  #endif
  for (int i = 0; i < 1<<4; ++i) {
    f[i] = 0;
    for (int j = 0; j < 4; ++j) if ((i>>j)&1) {
      for (int k = 0; k < 4; ++k) if (j != k) {
        f[i] ^= 1<<k;
      }
    }
    #ifdef DEBUG
    if (vis[f[i]]) cout << "shit" << endl;
    else vis[f[i]] = 1;
    cout << bitset<4>(i) << " " << bitset<4>(f[i]) << endl;
    #endif
  }
}

int code(int x, int y) {
  int res = 0;
  if (a[x][y]) res |= 1;
  if (a[x+1][y]) res |= 2;
  if (a[x][y+1]) res |= 4;
  if (a[x+1][y+1]) res |= 8;
  return f[res];
}

/*
void add(int x, int y, int xx, int yy) {
  static vector<pii> cur;
  cur.clear();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (x+i == xx && y+j == yy) continue;
      cur.emplace_back(x+i, y+j);
      a[x+i][y+j] ^= 1;
    }
  }
  res.emplace_back(cur);
}
*/

void fuck(int x, int y) {
  static vector<pii> cur;
  int ope = code(x, y);
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
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= m; j += 2) {
      fuck(i-(i+1 > n), j-(j+1 > m));
      /*
      int ope = code();
      if (ope&1) add(i, j, i, j);
      if (ope&2) add(i, j, i+1, j);
      if (ope&4) add(i, j, i, j+1);
      if (ope&8) add(i, j, i+1, j+1);
      */
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