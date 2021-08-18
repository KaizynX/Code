/*
 * @Author: Kaizyn
 * @Date: 2021-08-18 15:17:25
 * @LastEditTime: 2021-08-18 15:42:03
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e4+7;

struct TireTree {
  static const int NN = 5e5+7;
  static const int SZ = 2;
  char beg;
  int nex[NN][SZ], num[NN], cnt, exist[NN];
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(exist, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(int s[], int len) {
    int p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i];
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
      ++num[p];
    }
    ++exist[p];
  }
  int query(int s[], int len) {
    int p = 0, res = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i];
      if (!nex[p][c]) return exist[p]+res;
      res += exist[p];
      p = nex[p][c];
    }
    return num[p]+res;
  }
};

int n, m;
int a[N];
TireTree tire;

inline void solve() {
  cin >> m >> n;
  for (int i = 1, len; i <= m; ++i) {
    cin >> len;
    for (int j = 0; j < len; ++j) cin >> a[j];
    tire.insert(a, len);
  }
  for (int i = 1, len; i <= n; ++i) {
    cin >> len;
    for (int j = 0; j < len; ++j) cin >> a[j];
    cout << tire.query(a, len) << '\n';
  }
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