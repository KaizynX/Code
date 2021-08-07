/*
 * @Author: Kaizyn
 * @Date: 2021-08-07 14:17:01
 * @LastEditTime: 2021-08-07 15:47:16
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
const int N = 2e5+7;
const int S = 300;
const int M = N/S+1;

int n, m, q;
int a[N], b[N];
int stk[M][S+7], sz[M], add_b[M], Jmp[M];
int jmp[N], val[N];

inline int lb(int id, int cur) {
  static int l, r, mid;
  l = 1, r = sz[id];
  while (l < r) {
    mid = (l+r)>>1;
    if (a[stk[id][mid]] >= a[cur]) r = mid;
    else l = mid+1;
  }
  return stk[id][l];
}

inline int calc_b(int i, int j) {
  return add_b[i/S]^b[i]^add_b[j/S]^b[j];
}

inline void modify_b(int x, int y) { // O(n/S+S)
  for ( ; x <= y && x%S; ++x) b[x] ^= 1;
  for ( ; x+S-1 <= y; x += S) add_b[x/S] ^= 1;
  for ( ; x <= y; ++x) b[x] ^= 1;
}

inline void get_Jmp(int id) {
  if (id < 0 || id == m) return;
  int x = stk[id][sz[id]], y = stk[id+1][sz[id+1]];
  if (a[x] > a[y]) Jmp[id] = 0;
  else Jmp[id] = lb(id+1, x);
}

inline void get_jmp(int id) { // O(S)
  static int stk[S+7], sz;
  sz = 0;
  int l = id*S, r = min(n, l+S);
  for (int i = r-1; i >= l; --i) {
    // 找到i之后第一个a[j]>=a[i]
    while (sz && a[stk[sz]] < a[i]) --sz;
    jmp[i] = sz ? jmp[stk[sz]] : i;
    val[i] = sz ? val[stk[sz]]+calc_b(i, stk[sz]) : 0;
    stk[++sz] = i;
  }
  get_Jmp(id);
  get_Jmp(id-1);
}

inline void get_stk(int id) { // O(S)
  int l = id*S, r = min(n, l+S);
  // 维护l开始的不下降序列
  stk[id][sz[id] = 1] = l;
  for (int i = l+1; i < r; ++i) {
    if (a[i] >= a[stk[id][sz[id]]]) {
      stk[id][++sz[id]] = i;
    }
  }
}

inline void rebuild(int id) {
  get_stk(id);
  get_jmp(id);
}

inline int query(int x, int y) {
  int cur = x++, sum = 0;
  for ( ; x <= y && x%S; ++x) { // O(S)
    if (a[x] >= a[cur]) {
      sum += calc_b(cur, x);
      cur = x;
    }
  }
  for (int id, to; x+S-1 <= y; x += S) { // O(n/S+log(S))
    id = x/S;
    if (a[cur] > a[stk[id][sz[id]]]) continue;
    if (id && a[cur] == a[stk[id-1][sz[id-1]]]) to = Jmp[id-1];
    else to = lb(id, cur);
    sum += calc_b(cur, to)+val[to];
    cur = jmp[to];
  }
  for ( ; x <= y; ++x) { // O(S)
    if (a[x] >= a[cur]) {
      sum += calc_b(cur, x);
      cur = x;
    }
  }
  return sum;
}

inline void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);
  for (int i = 0; i < n; ++i) scanf("%d", b+i);
  m = (n-1)/S;
  for (int i = m; i >= 0; --i) rebuild(i);
  // for (int i = 0; i <= m; ++i) rebuild(i);
  scanf("%d", &q);
  // for (int i = 0; i <= m; ++i) cout << Jmp[i] << " \n"[i==m];
  for (int _ = q, opt, x, y; _; --_) {
    scanf("%d%d%d", &opt, &x, &y);
    if (opt == 1) {
      a[--x] = y;
      rebuild(x/S);
    } else if (opt == 2) {
      modify_b(--x, --y);
      get_jmp(x/S);
      if (x/S != y/S) get_jmp(y/S);
    } else {
      printf("%d\n", query(x-1, y-1));
    }
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