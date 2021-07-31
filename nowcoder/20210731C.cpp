/*
 * @Author: Kaizyn
 * @Date: 2021-07-31 14:05:46
 * @LastEditTime: 2021-07-31 14:38:08
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
const int N = 1e6+7;

int n;
string str;
// first_pos[i] 第一个 >= i 的在 pos 中的下标
// dis[i] 两者差距的前缀和 W-L
// nex[i][j] 第一次出现 dis[i]+(j-3)的位置
int first_pos[2][N], dis[N], nex[N][7], arr[N<<1], *last = arr+N;
// pos[i] 第 i 个字符的位置
vector<int> pos[2];

inline void solve() {
  cin >> n >> str;
  for (int i = 1, ch; i <= n; ++i) {
    ch = str[i-1] == 'W';
    dis[i] = dis[i-1]+(ch ? 1 : -1);
    first_pos[ch][i] = pos[ch].size();
    first_pos[ch^1][i] = -1;
    pos[ch].emplace_back(i);
  }
  first_pos[0][n+1] = first_pos[1][n+1] = n+1;
  for (int i = n; i; --i) {
    for (int id : {0, 1}) {
      if (~first_pos[id][i]) continue;
      first_pos[id][i] = first_pos[id][i+1];
    }
    last[dis[i]] = i;
    for (int j = 0; j < 7; ++j) {
      nex[i][j] = last[dis[i]+j-3];
      if (!nex[i][j]) nex[i][j] = n+1;
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << first_pos[0][i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << first_pos[1][i] << " \n"[i==n];
  #endif
  ll res = 0, base = 1;
  for (int gap = 1, cur; gap <= n; ++gap, base = base*(n+1)%MOD) {
    cur = 0;
    #ifdef DEBUG
    printf("********gap=%d*******", gap);
    #endif
    for (int head = 1, tail, i0, i1; head <= n; head = tail+1) {
      i0 = first_pos[0][head];
      i1 = first_pos[1][head];
      int j0 = i0+gap-1 >= (int)pos[0].size() ? n+1 : pos[0][i0+gap-1];
      int j1 = i1+gap-1 >= (int)pos[1].size() ? n+1 : pos[1][i1+gap-1];
      tail = min(j0, j1);
      if (tail > n) break;
      int nowd = dis[tail]-dis[head-1];
      if (abs(nowd) < 2) {
        tail = min(nex[tail][(2-nowd)+3], nex[tail][(-2-nowd)+3]);
      }
      if (tail > n) break;
      nowd = dis[tail]-dis[head-1];
      if (nowd > 0) ++cur;
      #ifdef DEBUG
      printf("(%d, %d, %d)", head, tail, nowd);
      #endif
    }
    #ifdef DEBUG
    printf("%d\n", cur);
    #endif
    res = (res+cur*base)%MOD;
  }
  cout << res << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}